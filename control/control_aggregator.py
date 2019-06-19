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
from auv.msg import trajectory
from auv.msg import mode

pub = rospy.Publisher('trajectory_raw', trajectory, queue_size=100)
mmode = rospy.Publisher('current_mode', mode, queue_size=10)
ROVMODE = False
AUVMODE = False

def joystick_callback(data):
    if ROVMODE:
    	pub.publish(data)

def trajectory_callback(data):
    if AUVMODE:
    	pub.publish(data)

def mode_callback(data):
    global ROVMODE
    ROVMODE = data.rovmode
    global AUVMODE
    AUVMODE = data.auvmode

def listener():

    rospy.init_node('control_aggregator', anonymous=True)

    rospy.Subscriber('joystick_execution', trajectory, joystick_callback)
    rospy.Subscriber('trajectory_execution', trajectory, trajectory_callback)
    rospy.Subscriber('mode_request', mode, mode_callback)
    rospy.spin()


if __name__ == '__main__':
    listener()
