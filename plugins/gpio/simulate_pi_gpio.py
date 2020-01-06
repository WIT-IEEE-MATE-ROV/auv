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

GPIO_pin = 0


def callback(data):
    global GPIO_pin
    if data.executor.lower() == "gpio_"+str(GPIO_pin):
        rospy.loginfo('Setting the pin ' + GPIO_pin + " to " + str(data.boolean))
        # Here's where we would do that, if we were real.


if __name__ == '__main__':
    print(rospy.myargv())
    parser = argparse.ArgumentParser('Controls a specified GPIO pin.')
    parser.add_argument('pin', type=int, help='Set the GPIO pin this node controls.')
    args = parser.parse_args(rospy.myargv()[1:])

    GPIO_pin = args.pin

    if not GPIO_pin:
        rospy.logwarn("Pin is not valid, has it been provided?")
        GPIO_pin = 0

    rospy.init_node('GPIO_' + str(GPIO_pin), anonymous=True)
    rospy.Subscriber('io_request', io_request, callback)
    rospy.spin()
