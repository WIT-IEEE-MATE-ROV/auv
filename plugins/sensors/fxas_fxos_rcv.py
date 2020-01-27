#!/usr/bin/env python

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

import logging
import os

import rospy
import numpy as np
from auv.msg import ninedof

# Where we'll be publishing our results
nineDof_current_pub = rospy.Publisher('ninedof_values', ninedof, queue_size=3)

fxas_fxos_is_up = False

# TODO: Set these values according to a user-specified transform that takes rotation of the sensor into account
_X = 0
_Y = 1
_Z = 2
_Roll = 0
_Pitch = 1
_Yaw = 2


def get_data():
    script_path = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'send.py')

    os.system('python3 ' + script_path)

    pipe_name = 'pipe'

    with open(pipe_name, 'r', 1) as fifo:
        logging.info('FIFO opened')
        data = fifo.read()


def publisher():
    rospy.init_node('fxas_fxos_nineDof', anonymous=True)
    rate = rospy.Rate(10)

    sendval_ninedof = ninedof()
    while not rospy.is_shutdown():
        # While this node is still running, keep getting sensor values
        if fxas_fxos_is_up:
            sendval_ninedof.orientation.roll = fxas.gyroscope[_Roll]
            sendval_ninedof.orientation.pitch = fxas.gyroscope[_Pitch]
            sendval_ninedof.orientation.yaw = fxas.gyroscope[_Yaw]
            sendval_ninedof.translation.x = fxos.accelerometer[_X]
            sendval_ninedof.translation.y = fxos.accelerometer[_Y]
            sendval_ninedof.translation.z = fxos.accelerometer[_Z]

        else:
            # Just in case we're not running with the right hardware, assume we're running in
            # simulation and generate random values for the sake of testing.
            sendval_ninedof.orientation.roll = np.random.normal()
            sendval_ninedof.orientation.pitch = np.random.normal()
            sendval_ninedof.orientation.yaw = np.random.normal()
            sendval_ninedof.translation.x = np.random.normal()
            sendval_ninedof.translation.y = np.random.normal()
            sendval_ninedof.translation.z = np.random.normal()

        nineDof_current_pub.publish(sendval_ninedof)
        rate.sleep()


if __name__ == '__main__':
    # publisher()
    pass
