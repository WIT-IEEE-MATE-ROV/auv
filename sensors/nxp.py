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
from auv.msg import ninedof
from auv.msg import position
from auv.msg import gyroscope

import csv
import subprocess

ninedof_current_pub = rospy.Publisher('ninedof_current', ninedof, queue_size=3)
ninedof_integrated_pub = rospy.Publisher('ninedof_integrated' , position , queue_size=3)
ninedof_gyro_pub = rospy.Publisher('ninedof_gyroscope' , gyroscope , queue_size=3)

def listener():
    rospy.init_node('ninedof', anonymous=True)

    rate = rospy.Rate(5)

    proc = subprocess.Popen('python3 /home/robot/enbarr/src/auv/scripts/read_nxpval.py' , shell=True)
    
    sendval_ninedof = ninedof()
    sendval_integrated = position()
    sendval_gyro = gyroscope()
    while not rospy.is_shutdown():

        with open("output/nxpval.csv" , "r") as f:
            reader = csv.DictReader(f)

            sendval_ninedof.orientation.roll = reader['roll']
            sendval_ninedof.orientation.pitch = reader['pitch']
            sendval_ninedof.orientation.yaw = reader['yaw']
            sendval_ninedof.translation.x = reader['accl_x']
            sendval_ninedof.translation.y = reader['accl_y']
            sendval_ninedof.translation.z = reader['accl_z']

            sendval_integrated.x = reader['pos_x']
            sendval_integrated.y = reader['pos_y']
            sendval_integrated.z = reader['pos_z']

            sendval_gyro.x = reader['gyro_x']
            sendval_gyro.y = reader['gyro_y']
            sendval_gyro.z = reader['gyro_z']

        ninedof_current_pub.publish(sendval_ninedof)
        ninedof_integrated_pub.publish(sendval_integrated)
        ninedof_gyro_pub.publish(sendval_gyro)

        rate.sleep()

    proc.terminate()

if __name__ == '__main__':
    listener()
