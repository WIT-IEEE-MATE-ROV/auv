import numpy as np
import os
import sys
import time
import logging

import adafruit_fxas21002c
import adafruit_fxos8700

from math import sqrt

try:
    import board
    import busio

    import adafruit_fxas21002c
    import adafruit_fxos8700

    enableSensor = True
except NotImplementedError as e:
    print(e, file=sys.stderr)
    enableSensor = False
except Exception as e:
    print(e, file=sys.stderr)
    enableSensor = False

logging.basicConfig(format='[Send][%(levelname)s]: %(message)s', level=logging.DEBUG)


def calc_magnitude(x, y, z):
    return sqrt((x ** 2) + (y ** 2) + (z ** 2))


class Sensor:
    def __init__(self, i2c):
        # TODO: Set these values according to a user-specified transform that takes rotation of the sensor into account
        self._X = 0
        self._Y = 1
        self._Z = 2
        self._Roll = 0
        self._Pitch = 1
        self._Yaw = 2

        if enableSensor:
            self._i2c = i2c
            self._sensor_gyro = adafruit_fxas21002c.FXAS21002C(self._i2c)
            self._sensor = adafruit_fxos8700.FXOS8700(self._i2c)
        else:
            self._i2c = None
            self._sensor_gyro = None
            self._sensor = None

    # getAcc reads sensor data from accelerometer
    @property
    def accel_x(self):
        return self._sensor.accelerometer[self._X] if enableSensor else np.random.normal()

    @property
    def accel_y(self):
        return self._sensor.accelerometer[self._Y] if enableSensor else np.random.normal()

    @property
    def accel_z(self):
        return self._sensor.accelerometer[self._Z] if enableSensor else np.random.normal()

    @property
    def accel_mag(self):
        return calc_magnitude(self.accel_x, self.accel_y, self.accel_z)

    # getGyro reads gyroscope values
    @property
    def gyro_roll(self):
        return self._sensor_gyro.gyroscope[self._Roll] if enableSensor else np.random.normal()

    @property
    def gyro_pitch(self):
        return self._sensor_gyro.gyroscope[self._Pitch] if enableSensor else np.random.normal()

    @property
    def gyro_yaw(self):
        return self._sensor_gyro.gyroscope[self._Yaw] if enableSensor else np.random.normal()

    @property
    def gyro_mag(self):
        return calc_magnitude(self.gyro_roll, self.gyro_pitch, self.gyro_yaw)

    # getMag reads magnetometer values
    @property
    def mag_x(self):
        return self._sensor.magnetometer[self._X] if enableSensor else np.random.normal()

    @property
    def mag_y(self):
        return self._sensor.magnetometer[self._Y] if enableSensor else np.random.normal()

    @property
    def mag_z(self):
        return self._sensor.magnetometer[self._Z] if enableSensor else np.random.normal()

    @property
    def mag_mag(self):
        return calc_magnitude(self.mag_x, self.mag_y, self.mag_z)


def send_data():
    i2c = busio.I2C(board.SCL, board.SDA) if enableSensor else None
    sensor = Sensor(i2c)
    
    while os.path.exists('/tmp/run.lck'):
        gyro_roll = sensor.gyro_roll
        gyro_pitch = sensor.gyro_pitch
        gyro_yaw = sensor.gyro_yaw
        accel_x = sensor.accel_x
        accel_y = sensor.accel_y
        accel_z = sensor.accel_z
        try:
            print('{0:.6f};{1:.6f};{2:.6f};{3:.6f};{4:.6f};{5:.6f};{6:d}'.format(
                gyro_roll,
                gyro_pitch,
                gyro_yaw,
                accel_x,
                accel_y,
                accel_z,
                1 if enableSensor else 0
            ), end='\0', flush=True)
        except BrokenPipeError as e:
            print(e, file=sys.stderr)
            sys.exit(0)
        # print("Python script", end='\n\0', flush=True)
        time.sleep(0.25)


def save_data():
    i2c = busio.I2C(board.SCL, board.SDA) if enableSensor else None
    sensor = Sensor(i2c)
    
    while True:
        gyro_roll = sensor.gyro_roll
        gyro_pitch = sensor.gyro_pitch
        gyro_yaw = sensor.gyro_yaw
        accel_x = sensor.accel_x
        accel_y = sensor.accel_y
        accel_z = sensor.accel_z
        print('{0:.6f};{1:.6f};{2:.6f};{3:.6f};{4:.6f};{5:.6f};'.format(
            gyro_roll,
            gyro_pitch,
            gyro_yaw,
            accel_x,
            accel_y,
            accel_z
        ))
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
    send_data()
