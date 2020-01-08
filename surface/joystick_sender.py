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
import pygame
import sys
import argparse
from auv.msg import surface_command

publisher = rospy.Publisher('surface_command', surface_command, queue_size=3)
rospy.init_node('joystick_sender', anonymous=False)

joystick = None
rate = rospy.Rate(1)

try:
    pygame.joystick.init()
    while pygame.joystick.get_count() == 0:
        rospy.logerr("No joystick connected!")
        pygame.joystick.quit()
        pygame.joystick.init()
        rate.sleep()
    rospy.loginfo("Found a joystick to use.")
    pygame.init()
    joystick = pygame.joystick.Joystick(0)
    joystick.init()
except pygame.error:
    rospy.logerr("Failed to initialize joystick!")
    sys.exit(1)

parser = argparse.ArgumentParser("Find a plugged in joystick and send it over /surface_command.")
parser.add_argument('config_name', type=str, help='Set the name of the file we should use as a config (from within '
                                                  'the config directory)')
args = parser.parse_args(rospy.myargv()[1:])

rate = rospy.Rate(5)
while not rospy.is_shutdown():
    try:
        pygame.event.get()

        horizontal_axis = joystick.get_axis(0)  # Horizontal: -1 is full left, 1 is full right
        vertical_axis = joystick.get_axis(1)  # Vertical: -1 is full forward, 1 is full back
        twist_axis = joystick.get_axis(2)  # Twist: -1 is full counter-clockwise, 1 is clockwise
        lever_axis = joystick.get_axis(3)  # Lever: 1 is full down, -1 is full up

        msg = surface_command()
        msg.desired_trajectory.translation.x = horizontal_axis
        msg.desired_trajectory.translation.y = -1 * vertical_axis  # Flipped as forward is negative, and that's dumb
        msg.desired_trajectory.translation.z = lever_axis
        msg.desired_trajectory.orientation.yaw = twist_axis

        publisher.publish(msg)
        rate.sleep()

    except KeyboardInterrupt:
        rospy.loginfo("Got keyboard interrupt. Bye!")
        sys.exit(0)
