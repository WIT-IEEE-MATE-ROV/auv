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
from auv.msg import arbitrary_pca_commands

publisher = rospy.Publisher('arbitrary_pca_commands', arbitrary_pca_commands, queue_size=3)
rospy.init_node('pca_servo', anonymous=True)

parser = argparse.ArgumentParser("Set the thruster speed on a PCA channel over the /arbitrary_pca_commands topic.")
parser.add_argument('thruster', help='The name of the thruster to be used here.')
parser.add_argument('speed', type=float, help='The speed to be used which will then be scaled. [0, 1]')
args = parser.parse_args(rospy.myargv()[1:])

command = arbitrary_pca_commands()
command.set_thruster = True
command.thruster = args.thruster
command.pwm = args.speed

publisher.publish(command)

rospy.spin()

command.pwm = 0
publisher.publish(command)
