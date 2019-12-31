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

import rospy
from auv.msg import ninedof, gyroscope
# from auv.msg import gyroscope

import csv
import subprocess
import os

nineDof_current_pub = rospy.Publisher('ninedof_current', ninedof, queue_size=3)
nineDof_integrated_pub = rospy.Publisher('ninedof_integrated', gyroscope, queue_size=3)
nineDof_gyro_pub = rospy.Publisher('ninedof_gyroscope', gyroscope, queue_size=3)


def listener():
    rospy.init_node('nxp-by-file_nineDof', anonymous=True)
    rate = rospy.Rate(5)
    proc = subprocess.Popen('rosrun auv read_nxpval.py', shell=True)

    sendval_ninedof = ninedof()
    sendval_integrated = gyroscope()
    sendval_gyro = gyroscope()
    current_directory = os.path.dirname(__file__)
    csv_filename = os.path.join(current_directory, '../scripts/output/nxpval.csv')
    while not rospy.is_shutdown():

        with open(csv_filename, "r") as f:
            reader = csv.DictReader(f)

            for row in reader:
                sendval_ninedof.orientation.roll = row['roll']
                sendval_ninedof.orientation.pitch = row['pitch']
                sendval_ninedof.orientation.yaw = row['yaw']
                sendval_ninedof.translation.x = row['accl_x']
                sendval_ninedof.translation.y = row['accl_y']
                sendval_ninedof.translation.z = row['accl_z']

                sendval_integrated.x = row['pos_x']
                sendval_integrated.y = row['pos_y']
                sendval_integrated.z = row['pos_z']

                sendval_gyro.x = row['gyro_x']
                sendval_gyro.y = row['gyro_y']
                sendval_gyro.z = row['gyro_z']

        nineDof_current_pub.publish(sendval_ninedof)
        nineDof_integrated_pub.publish(sendval_integrated)
        nineDof_gyro_pub.publish(sendval_gyro)

        rate.sleep()

    proc.kill()


if __name__ == '__main__':
    listener()
