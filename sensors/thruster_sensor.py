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
import sys
from auv.msg import thruster_sensor

pub = None

def listener(thruster):
    rospy.init_node('thruster_sensor', anonymous=True)
    global pub
    pub = rospy.Publisher('thruster_sensor_'+thruster, thruster_sensor, queue_size=3)

    rate = rospy.Rate(5)
    # TODO
    sendval = thruster_sensor()
    while not rospy.is_shutdown():
        pub.publish(sendval)
        rate.sleep()


if __name__ == '__main__':
    myargv = rospy.myargv()
    parser = argparse.ArgumentParser("Gathers all kinds of useful sensor values from stuff attached to the thrusters")
    parser.add_argument('-t', '--thruster', help="The name of the thruster this node is responsible for")
    args = vars(parser.parse_args(myargv[1:]))
    listener(args['thruster'])
