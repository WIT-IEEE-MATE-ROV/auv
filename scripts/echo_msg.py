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

parser = argparse.ArgumentParser('Echoes whatever you give it. Nice for launch files.')
parser.add_argument('msg', type=str, help='What will we print out?')
args = parser.parse_args(rospy.myargv()[1:])

rospy.init_node('msg_node', log_level=rospy.WARN)
rospy.logwarn(args.msg)
