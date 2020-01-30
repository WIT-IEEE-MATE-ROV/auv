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


    Chaos joystick sender: Like the regular joystick sender, but now with
    the ability to add 'chaos': fiddle with the deadzone, make certain 
    trajectories go slower than they need too, and so on.
    
    Useful for making drivers suffer, reminding the mechanicals that this
    machine is OURS NOT THEIRS, or for making arbitrary adjustments to
    different inputs.
"""

import os
import rospy
import rospkg
import pygame
import sys
import argparse
import socket
from auv.msg import surface_command, io_request, joystick_chaos


try:
    publisher = rospy.Publisher('surface_command', surface_command, queue_size=3)
    corrective_subscriber = rospy.Subscriber('joystick_chaos', joystick_chaos, corrective_callback)
    rospy.init_node('joystick_sender_'+socket.gethostname(), anonymous=False)  # Be effectively anonymous by naming the node after the hostname
except rospy.exceptions.ROSInitException as e:
    print("You've cancelled initialization of this node. Shutting down.")
    sys.exit(0)

shift_horizontal_correction = 0
shift_vertical_correction = 0
shift_twist_correction = 0
shift_lever_correction = 0
magnitude_horizontal_correction = 1
magnitude_vertical_correction = 1
magnitude_twist_correction = 1
magnitude_lever_correction = 1
lag_seconds = 0
thruster_to_kill = []
thruster_to_unkill = []


def corrective_joystick_chaos(data):
    global shift_horizontal_correction
    global shift_vertical_correction
    global shift_twist_correction
    global shift_lever_correction
    global magnitude_horizontal_correction
    global magnitude_vertical_correction
    global magnitude_twist_correction
    global magnitude_lever_correction
    global lag_seconds

    shift_horizontal_correction = data.shift_horizontal_correction
    shift_vertical_correction = data.shift_vertical_correction
    shift_twist_correction = data.shift_twist_correction
    shift_lever_correction = data.shift_lever_correction
    magnitude_horizontal_correction = data.magnitude_horizontal_correction
    magnitude_vertical_correction = data.magnitude_vertical_correction
    magnitude_twist_correction = data.magnitude_twist_correction
    magnitude_lever_correction = data.magnitude_lever_correction
    lag_seconds = data.lag_seconds

    if data.unkill_thruster:
        thruster_to_unkill.append(data.thruster)
    elif data.kill_thruster:
        thruster_to_kill.append(data.thruster)


def different_msg(msg1, msg2):
    if msg1 is None or msg2 is None:
        return True

    return msg1.desired_trajectory.orientation != msg2.desired_trajectory.orientation or \
           msg1.desired_trajectory.translation != msg2.desired_trajectory.translation or \
           msg1.io_requests != msg2.io_requests


if __name__ == '__main__':
    joystick = None

    # Set up Pygame to run headlesslu
    os.environ["SDL_VIDEODRIVER"] = "dummy"
    pygame.display.set_mode((1, 1))

    # We'll use this to try not to connect to the joystick too quickly.
    rate = rospy.Rate(1)

    os.environ["SDL_VIDEODRIVER"] = "dummy"
    pygame.display.set_mode((1, 1))

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

    # roslaunch/rosrun executes this from the wrong directory, preventing us from calling the config import.
    # By updating our python path via sys, we're able to tell it where to find this stuff.
    # TODO: Make this conditional on a command line parameter.
    rospkg = rospkg.RosPack()
    sys.path.append(rospkg.get_path('auv'))
    import config

    # Now that we're not using the rate to slow down our joystick connection, let's bring it to something we'll use.
    rate = rospy.Rate(10)
    lastmsg = surface_command()
    while not rospy.is_shutdown():
        try:
            pygame.event.get()
            horizontal_axis = joystick.get_axis(0) + shift_horizontal_correction   # Horizontal: -1 is full left, 1 is right
            vertical_axis = joystick.get_axis(1) + shift_vertical_correction  # Vertical: -1 is full forward, 1 is back
            twist_axis = joystick.get_axis(2) + shift_twist_correction  # Twist: -1 is full counter-clockwise, 1 is clockwise
            lever_axis = joystick.get_axis(3) + shift_lever_correction  # Lever: 1 is full down, -1 is full up

            msg = surface_command()
            msg.desired_trajectory.translation.x = -1 * horizontal_axis * magnitude_horizontal_correction
            msg.desired_trajectory.translation.y = vertical_axis  * magnitude_vertical_correction
            msg.desired_trajectory.translation.z = -1 * lever_axis * magnitude_lever_correction
            msg.desired_trajectory.orientation.yaw = -1 * twist_axis * magnitude_twist_correction

            msg = config.simulate_peripherals.handle_peripherals(joystick, msg)
            if different_msg(lastmsg, msg):
                publisher.publish(msg)
                time.sleep(lag_seconds)
                lastmsg = msg

            rate.sleep()

        except KeyboardInterrupt:
            rospy.loginfo("Got keyboard interrupt. Bye!")
            sys.exit(0)
