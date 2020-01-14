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
rospy.init_node('kill_thruster', anonymous=True)

parser = argparse.ArgumentParser("Send a thruster kill command over the /surface_command topic.")
parser.add_argument('thruster', help='The name of the thruster to be used here.')
args = parser.parse_args(rospy.myargv()[1:])

command = arbitrary_pca_commands()
command.kill_thruster = True
command.thruster = args.thruster

publisher.publish(command)
