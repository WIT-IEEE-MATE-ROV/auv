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
import time
import sys
import re
import os
from auv.msg import joystick_chaos

publisher = rospy.Publisher('joystick_chaos', joystick_chaos, queue_size=3)
rospy.init_node('chaos_sender', anonymous=True)

current_msg = joystick_chaos()
current_msg.magnitude_horizontal_correction = 1
current_msg.magnitude_vertical_correction = 1
current_msg.magnitude_twist_correction = 1
current_msg.magnitude_lever_correction = 1

disabled_thrusters = []


def display_state():
    print(" Axis         | [S]hifts | [M]agnitude     \n"
          "==============|==========|===========    \n"
          " [H]orizontal |   {:2.2f}   |  {:2.2f}    \n"
          " [V]ertical   |   {:2.2f}   |  {:2.2f}    \n"
          " [T]wist      |   {:2.2f}   |  {:2.2f}    \n"
          " [L]ever      |   {:2.2f}   |  {:2.2f}    \n".format(
              current_msg.shift_horizontal_correction,
              current_msg.magnitude_horizontal_correction,
              current_msg.shift_vertical_correction,
              current_msg.magnitude_vertical_correction,
              current_msg.shift_twist_correction,
              current_msg.magnitude_twist_correction,
              current_msg.shift_lever_correction,
              current_msg.magnitude_lever_correction))

    print("Artificial Lag: {:3.2f} seconds.".format(current_msg.lag_seconds))
    if disabled_thrusters.__len__() is not 0:
        print("Disabled Thrusters: "+str(disabled_thrusters))


def get_state(current_message):
    print("\nTo modify axis adjustments: \n"
          "[axis] [type] [value] (i.e., h s -.1)")
    print("To modify artificial lag: 'lag [float]'")
    print("Or use [e]xit, [r]eset")

    input = raw_input("> ")
    input = input.lower()

    if input[0] is "e":
        sys.exit(0)

    elif input[0] is "r":
        current_msg.magnitude_horizontal_correction = 1
        current_msg.magnitude_vertical_correction = 1
        current_msg.magnitude_twist_correction = 1
        current_msg.magnitude_lever_correction = 1
        current_msg.shift_horizontal_correction = 0
        current_msg.shift_vertical_correction = 0
        current_msg.shift_twist_correction = 0
        current_msg.shift_lever_correction = 0
        current_msg.lag_seconds = 0

    elif input.startswith("lag "):
        current_msg.lag_seconds = float(input[3:])

    elif input[0] is 'h' or\
            input[0] is 'v' or\
            input[0] is 't' or\
            input[0] is 'l':
        shift_mode_not_magnitude_mode = None
        if input[1] is 's' or input[2] is 's':
            shift_mode_not_magnitude_mode = True
        if input[1] is 'm' or input[2] is 'm':
            shift_mode_not_magnitude_mode = False
        val = re.findall("[1234567890.-]", input)  # Filter out any non-numbers, convert
        val = "".join(val)

        if input[0] is 'h':
            if shift_mode_not_magnitude_mode:
                current_msg.shift_horizontal_correction = float(val)
            else:
                current_msg.magnitude_horizontal_correction = float(val)
        if input[0] is 'v':
            if shift_mode_not_magnitude_mode:
                current_msg.shift_vertical_correction = float(val)
            else:
                current_msg.magnitude_vertical_correction = float(val)
        if input[0] is 't':
            if shift_mode_not_magnitude_mode:
                current_msg.shift_twist_correction = float(val)
            else:
                current_msg.magnitude_twist_correction = float(val)
        if input[0] is 'l':
            if shift_mode_not_magnitude_mode:
                current_msg.shift_lever_correction = float(val)
            else:
                current_msg.magnitude_lever_correction = float(val)

    return current_message


while not rospy.is_shutdown():
    os.system('clear')
    display_state()
    current_msg = get_state(current_msg)

    publisher.publish(current_msg)

