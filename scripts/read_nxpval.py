#!/usr/bin/env python3

"""

 This file is part of Enbarr.

    Enbarr is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Enbarr is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Enbarr.  If not, see <https://www.gnu.org/licenses/>.

"""

import time

import board
import busio

import adafruit_fxos8700
import adafruit_fxas21002c
from mpf.fusion import Fusion

i2c = busio.I2C(board.SCL, board.SDA)
sensor_am = adafruit_fxos8700.FXOS8700(i2c)
sensor_g = adafruit_fxas21002c.FXAS21002C(i2c)

last_accl = (0.0, 0.0, 0.0)
last_vel = [0.0, 0.0, 0.0]
last_pos = [0.0, 0.0, 0.0]

t0 = time.time()


def delta_t(time, t_i):
    return time - t_i


fuse = Fusion(delta_t)


def integrate(a_0, a_1, t_0, t_1):  # trapezoid
    vel = [0.0, 0.0, 0.0]
    for i in range(3):
        vel[i] = ((a_0[i] + a_1[i]) / 2.0) * (t_1 - t_0)
    return vel


def zero_pos():
    global last_pos
    last_pos = [0.0, 0.0, 0.0]


def get_mag():  # Return (x, y, z) tuple (blocking read)
    return sensor_am.magnetometer


def get_accl():
    return sensor_am.accelerometer


def get_gyro():
    return sensor_g.gyroscope


while True:
    accl = get_accl()
    mag = get_mag()
    gyro = get_gyro()

    t1 = time.time()
    vel = integrate(last_accl, accl, t0, t1)
    pos = integrate(last_vel, vel, t0, t1)

    for i in range(3):
        pos[i] += last_pos[i]

    fuse.update(accl, gyro, mag, t1)

    with open("/home/robot/enbarr/src/auv/scripts/output/nxpval.csv", "w") as f:
        f.write('gyro_x,gyro_y,gyro_z,accl_x,accl_y,accl_z,pos_x,pos_y,pos_z,roll,pitch,yaw\n')
        f.write('{0:f},{1:f},{2:f},'.format(gyro[0], gyro[1], gyro[2]))
        f.write('{0:f},{1:f},{2:f},'.format(accl[0], accl[1], accl[2]))
        f.write('{0:f},{1:f},{2:f},'.format(pos[0], pos[1], pos[2]))
        f.write('{0:f},{1:f},{2:f}'.format(fuse.roll, fuse.pitch, fuse.heading))

    t0 = t1

    time.sleep(0.20)
