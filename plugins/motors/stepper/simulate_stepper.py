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

import argparse
import rospy
from auv.msg import trajectory, io_request

Name = None


def callback(data):
    global Name
    if data.executor.lower() == Name.lower():
        rospy.loginfo('Moving the stepper motor' + Name + " " + data.int32 + " steps!")
        # Here's where we would do that, if we were real.


if __name__ == '__main__':
    parser = argparse.ArgumentParser('Runs a stepper of a specified name.')
    parser.add_argument('id_name', type=str, help='Set the name for this instance of the node to respond to.')
    args = parser.parse_args(rospy.myargv()[1:])

    Name = args.id_name

    if not Name:
        rospy.logwarn("Name is not valid, has it been provided?")
        Name = "default"

    rospy.init_node('stepper_' + Name, anonymous=True)
    rospy.Subscriber('io_request', io_request, callback)
    rospy.spin()
