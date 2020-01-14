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
from auv.msg import surface_command, io_request

publisher = rospy.Publisher('surface_command', surface_command, queue_size=3)
rospy.init_node('joystick_sender', anonymous=False)


def hat_to_val(a, b):
    if a == 0:
        if b == 0:
            return None
        if b == 1:
            return "top_front"
        if b == -1:
            return "top_left"
    if a == 1:
        if b == 0:
            return "top_right"
        if b == 1:
            return "front_right"
        if b == -1:
            return "front_left"
    if a == -1:
        if b == 0:
            return "top_back"
        if b == 1:
            return "back_left"
        if b == -1:
            return "back_right"


def handle_peripherals(joystick_, msg_):
    hat = joystick_.get_hat(0)
    hat = hat_to_val(hat[0], hat[1])

    io_request_ = io_request()
    io_request_.executor = "individual_thruster_control"

    if hat is not None:
        io_request_.float = 0.75
        io_request_.string = hat
    else:
        io_request_.float = 0.5
        io_request_.string = "all"
    msg.io_request.append(io_request_)

    return msg_  # If we wanted to do something with button presses, we could mess around with that sort of thing here.


def different_msg(msg1, msg2):
    if msg1 is None or msg2 is None:
        return True

    return msg1.desired_trajectory.orientation != msg2.desired_trajectory.orientation or \
           msg1.desired_trajectory.translation != msg2.desired_trajectory.translation or \
           msg1.io_request != msg2.io_request


if __name__ == '__main__':
    joystick = None

    # We'll use this to try not to connect to the joystick too quickly.
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
    parser.add_argument('--config_name', type=str, help='Set the name of the file we should use as a config (from '
                                                        'within the config directory)')
    args = parser.parse_args(rospy.myargv()[1:])

    # Now that we're not using the rate to slow down our joystick connection, let's bring it to something we'll use.
    rate = rospy.Rate(20)
    while not rospy.is_shutdown():
        try:
            pygame.event.get()
            horizontal_axis = joystick.get_axis(0)  # Horizontal: -1 is full left, 1 is full right
            vertical_axis = joystick.get_axis(1)  # Vertical: -1 is full forward, 1 is full back
            twist_axis = joystick.get_axis(2)  # Twist: -1 is full counter-clockwise, 1 is clockwise
            lever_axis = joystick.get_axis(3)  # Lever: 1 is full down, -1 is full up

            msg = surface_command()
            msg.desired_trajectory.translation.x = horizontal_axis
            msg.desired_trajectory.translation.y = -1 * vertical_axis  # Flipped: forward is negative, that's dumb
            msg.desired_trajectory.translation.z = lever_axis
            msg.desired_trajectory.orientation.yaw = twist_axis

            msg = handle_peripherals(joystick, msg)
            publisher.publish(msg)
            rate.sleep()

        except KeyboardInterrupt:
            rospy.loginfo("Got keyboard interrupt. Bye!")
            sys.exit(0)
