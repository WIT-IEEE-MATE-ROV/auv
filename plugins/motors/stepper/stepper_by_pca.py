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
from auv.msg import io_request, arbitrary_pca_commands

publisher = rospy.Publisher('arbitrary_pca_commands', arbitrary_pca_commands, queue_size=3)
Name = None
Channel = None


def callback(data):
    """
    Is this the stepper we've been told to deal with? If so, deal with it here.
    """
    if data.executor.lower() == Name.lower():
        msg = arbitrary_pca_commands()

        msg.set_thruster = False
        msg.set_channel_pwm = False
        msg.set_channel_pwm_send_count = True

        msg.channel = Channel
        msg.count = data.int32
        publisher.publish(msg)


if __name__ == '__main__':
    rospy.Subscriber('io_request', io_request, callback)

    parser = argparse.ArgumentParser('Runs a stepper of a specified name.')
    parser.add_argument('executor_name', type=str, help='Set the name for this instance of the node to respond to.')
    parser.add_argument('channel', type=int, help='Set the PCA channel to send stepper pulses on.')
    args = parser.parse_args(rospy.myargv()[1:])

    Name = args.executor_name
    Channel = args.channel

    # Creates a node name like "stepper_manipulator_ch10"
    rospy.init_node('stepper_' + Name + '_ch'+str(Channel), anonymous=False)
    rospy.spin()
