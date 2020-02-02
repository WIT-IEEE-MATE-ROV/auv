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


def send_data():
    print('data')


def calc_magnitude(x, y, z):
    return sqrt((x ** 2) + (y ** 2) + (z ** 2))


class Sensor:
    def __init__(self, i2c):
        self._i2c = i2c
        self._sensor_gyro = adafruit_fxas21002c.FXAS21002C(self._i2c)
        self._sensor = adafruit_fxos8700.FXOS8700(self._i2c)

    # getAcc reads sensor data from accelerometer
    @property
    def accel_x(self):
        return self._sensor.accelerometer[SensorAxis.X.value]

    @property
    def accel_y(self):
        return self._sensor.accelerometer[SensorAxis.Y.value]

    @property
    def accel_z(self):
        return self._sensor.accelerometer[SensorAxis.Z.value]

    @property
    def accel_mag(self):
        return calc_magnitude(self.accel_x, self.accel_y, self.accel_z)

    # getGyro reads gyroscope values
    @property
    def gyro_x(self):
        return self._sensor_gyro.gyroscope[SensorAxis.X.value]

    @property
    def gyro_y(self):
        return self._sensor_gyro.gyroscope[SensorAxis.Y.value]

    @property
    def gyro_z(self):
        return self._sensor_gyro.gyroscope[SensorAxis.Z.value]

    @property
    def gyro_mag(self):
        return calc_magnitude(self.gyro_x, self.gyro_y, self.gyro_z)

    # getMag reads magnetometer values
    @property
    def mag_x(self):
        return self._sensor.magnetometer[SensorAxis.X.value]

    @property
    def mag_y(self):
        return self._sensor.magnetometer[SensorAxis.Y.value]

    @property
    def mag_z(self):
        return self._sensor.magnetometer[SensorAxis.Z.value]

    @property
    def mag_mag(self):
        return calc_magnitude(self.mag_x, self.mag_y, self.mag_z)


class SensorAxis(Enum):
    X = 0
    Y = 1
    Z = 2


def output():
    while os.path.exists('/tmp/run.lck'):
        print("Python script", end='\n\0', flush=True)
        time.sleep(0.1)
        


def test_output():
    while True:
        time.sleep(5)
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
        print(' Gyroscope:\tmagnitude: {0:.2f} \tx: {1:.2f} \ty: {2:.2f} \tz: {3:.2f}\n'.format(
                sensor.gyro_mag,
                sensor.gyro_x,
                sensor.gyro_y,
                sensor.gyro_z))


if __name__ == "__main__":
    test_output()
