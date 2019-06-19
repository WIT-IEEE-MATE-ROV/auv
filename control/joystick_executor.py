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

pub = rospy.Publisher('joystick_execution', trajectory, queue_size=100)
modepub = rospy.Publisher('mode_request', mode, queue_size=10)

def mode_callback(data):
    AUVMODE = data.auvmode

def listener():
    rospy.init_node('joystick_executor', anonymous=True)
    rospy.Subscriber('current_mode', mode, mode_callback)

    # TODO
    sendtraj = trajectory()
    while not rospy.is_shutdown():
        pub.publish(sendtraj)


if __name__ == '__main__':
    listener()