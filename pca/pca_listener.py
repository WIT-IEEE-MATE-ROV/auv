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
from auv.msg import thrustermove
ESC_IS_INIT = False

def init_esc():
    """ Initialize the ESC's here TODO """

def move(data):
    """ Move the thrusters TODO """
    print(data)

def callback(data):
    """ This is what runs when a new message comes in """
    if not ESC_IS_INIT:
        init_esc()
    move(data)

def listener():
    """ Listen to thruster commands and run them """

    # Run listener nodes, with the option of happeneing simultaneously.
    rospy.init_node('listener', anonymous=True)
    rospy.Subscriber('thruster_commands', thrustermove, callback)

    # Run forever
    rospy.spin()

if __name__ == '__main__':
    listener()
