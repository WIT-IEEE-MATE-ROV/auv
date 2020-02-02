import board
import busio
import time
import os
import sys
import logging

import adafruit_fxas21002c
import adafruit_fxos8700

from enum import Enum
from math import sqrt

logging.basicConfig(format='[Send][%(levelname)s]: %(message)s', level=logging.DEBUG)


def calc_magnitude(x, y, z):
    return sqrt((x ** 2) + (y ** 2) + (z ** 2))


class Sensor:
    # TODO: Set these values according to a user-specified transform that takes rotation of the sensor into account
    _X = 0
    _Y = 1
    _Z = 2
    _Roll = 0
    _Pitch = 1
    _Yaw = 2

    def __init__(self, i2c):
        self._i2c = i2c
        self._sensor_gyro = adafruit_fxas21002c.FXAS21002C(self._i2c)
        self._sensor = adafruit_fxos8700.FXOS8700(self._i2c)

    # getAcc reads sensor data from accelerometer
    @property
    def accel_x(self):
        return self._sensor.accelerometer[_X]

    @property
    def accel_y(self):
        return self._sensor.accelerometer[_Y]

    @property
    def accel_z(self):
        return self._sensor.accelerometer[_Z]

    @property
    def accel_mag(self):
        return calc_magnitude(self.accel_x, self.accel_y, self.accel_z)

    # getGyro reads gyroscope values
    @property
    def gyro_roll(self):
        return self._sensor_gyro.gyroscope[_Roll]

    @property
    def gyro_pitch(self):
        return self._sensor_gyro.gyroscope[_Pitch]

    @property
    def gyro_yaw(self):
        return self._sensor_gyro.gyroscope[_Yaw]

    @property
    def gyro_mag(self):
        return calc_magnitude(self.gyro_x, self.gyro_y, self.gyro_z)

    # getMag reads magnetometer values
    @property
    def mag_x(self):
        return self._sensor.magnetometer[_X]

    @property
    def mag_y(self):
        return self._sensor.magnetometer[_Y]

    @property
    def mag_z(self):
        return self._sensor.magnetometer[_Z]

    @property
    def mag_mag(self):
        return calc_magnitude(self.mag_x, self.mag_y, self.mag_z)


def send_data():
    i2c = busio.I2C(board.SCL, board.SDA)
    sensor = Sensor(i2c)
    
    while os.path.exists('/tmp/run.lck'):
        print('{0:.3f};{1:.3f};{2:.3f};{3:.3f};{4:.3f};{5:.3f};'.format(
            sensor.gyro_roll,
            sensor.gyro_pitch,
            sensor.gyro_yaw,
            sensor.accel_x,
            sensor.accel_y,
            sensor.accel_z
        ))
        print("Python script", end='\n\0', flush=True)
        time.sleep(0.1)
        


def test_output():
    while True:
        # os.system('clear')
        i2c = busio.I2C(board.SCL, board.SDA)
        sensor = Sensor(i2c)
        print(' Accelerometer:\tmagnitude: {0:.2f} \tx: {1:.2f} \ty: {2:.2f} \tz: {3:.2f}'.format(
                sensor.accel_mag,
                sensor.accel_x,
                sensor.accel_y,
                sensor.accel_z))
        print(' Magnetometer:\tmagnitude: {0:.2f} \tx: {1:.2f} \ty: {2:.2f} \tz: {3:.2f}'.format(
                sensor.mag_mag,
                sensor.mag_x,
                sensor.mag_y,
                sensor.mag_z))
        print(' Gyroscope:\tmagnitude: {0:.2f} \troll: {1:.2f} \tpitch: {2:.2f} \tyaw: {3:.2f}\n'.format(
                sensor.gyro_mag,
                sensor.gyro_roll,
                sensor.gyro_pitch,
                sensor.gyro_yaw))
        time.sleep(5)


if __name__ == "__main__":
    test_output()
