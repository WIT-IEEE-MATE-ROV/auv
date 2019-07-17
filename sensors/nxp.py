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

ninedof_current_pub = rospy.Publisher('ninedof_current', ninedof, queue_size=3)
ninedof_integrated_pub = rospy.Publisher('ninedof_integrated', position, queue_size=3)

def listener():
    rospy.init_node('ninedof', anonymous=True)

    rate = rospy.Rate(5)
    # TODO
    sendval_ninedof = ninedof()
    sendval_integrated = position()
    while not rospy.is_shutdown():
        sendval_ninedof.orientation.roll = 0
        sendval_ninedof.orientation.pitch = 0
        sendval_ninedof.orientation.yaw = 0
        sendval_ninedof.translation.x = 0
        sendval_ninedof.translation.y = 0
        sendval_ninedof.translation.z = 0
        sendval_integrated.x = 10.32
        sendval_integrated.y = 1.4
        sendval_integrated.z = 30.9
        ninedof_current_pub.publish(sendval_ninedof)
        ninedof_integrated_pub.publish(sendval_integrated)
        rate.sleep()


if __name__ == '__main__':
    listener()
