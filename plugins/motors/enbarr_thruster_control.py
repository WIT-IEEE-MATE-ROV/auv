#!/usr/bin/env python3

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
from subprocess import call

def init_esc(args):
    setall(args, 0)
    setall(args, .5)
    setall(args, 0)

def setall(args, x):
    sendstr = [
                str(x)+',',
                str(x)+',',
                str(x)+',',
                str(x)+',',
                str(x)+',',
                str(x)+',',
                str(x)+',',
                str(x)+',',
                str(x)+',',
                str(x)+',',
                str(x)+',',
                str(x)+',',
                str(x)+',',
                str(x)+',',
                str(x)+',',
                str(x)+','
            ]
    call("rosrun auv set_pcaval.py "+''.join(sendstr), shell=True)


def callback(data):
    """ This is what runs when a new message comes in """
    move(data)


def listener(thrusters):
    """ Listen to thruster commands ad run them, assuming it's ours. """
    # Run listener nodes, with the option of happeneing simultaneously.
    rospy.init_node('thrusters', anonymous=True)

    rospy.Subscriber('thruster_commands', thrustermove, callback)
    rospy.Subscriber('thruster_sensors', thruster_sensor, callback)

    # Run forever
    rospy.spin()


if __name__ == '__main__':
    myargv = rospy.myargv()
    parser = argparse.ArgumentParser("Handles running a single thruster as directed by the command line argument")
    parser.add_argument('-tf', '--topfront', help="Set the PCA channel number for the top front thruster")
    parser.add_argument('-tb', '--topback', help="Set the PCA channel number for the top back thruster")
    parser.add_argument('-tl', '--topleft', help="Set the PCA channel number for the top left thruster")
    parser.add_argument('-tr', '--topright', help="Set the PCA channel number for the top right thruster")
    parser.add_argument('-fl', '--frontleft', help="Set the PCA channel number for the front left thruster")
    parser.add_argument('-fr', '--frontright', help="Set the PCA channel number for the front right thruster")
    parser.add_argument('-bl', '--backleft', help="Set the PCA channel number for the back left thruster")
    parser.add_argument('-br', '--backright', help="Set the PCA channel number for the back right thruster")
    args = vars(parser.parse_args(myargv[1:]))
    init_esc(args)
    listener(args)
