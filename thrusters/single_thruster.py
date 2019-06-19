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
import argparse
from auv.msg import thruster_sensor, thrustermove
ESC_IS_INIT = False
CHANNEL = -1

def init_esc():
    """ Initialize the ESC's here TODO """
    global ESC_IS_INIT  # FIXME: Messy
    ESC_IS_INIT = True

def move(data):
    """ Move the thrusters TODO """
    print("Told to move: ")
    print(data)

def callback(data):
    """ This is what runs when a new message comes in """
    if not ESC_IS_INIT:
        init_esc()
    move(data)

def listener(thruster):
    """ Listen to thruster commands ad run them, assuming it's ours. """
    # Run listener nodes, with the option of happeneing simultaneously.
    rospy.init_node('single_thruster', anonymous=True)

    rospy.Subscriber('thruster_commands', thrustermove, callback)
    rospy.Subscriber('thruster_sensor_'+thruster, thruster_sensor, callback)

    # Run forever
    rospy.spin()

if __name__ == '__main__':
    myargv = rospy.myargv()
    parser = argparse.ArgumentParser("Handles running a single thruster as directed by the command line argument")
    parser.add_argument('-c', '--channel', help="The channel this node should send PWM to", required=True)
    parser.add_argument('-t', '--thruster', help="The name of the thruster this node is responsible for", required=True)
    args = vars(parser.parse_args(myargv[1:]))
    CHANNEL = args['channel']
    listener(args['thruster'])
