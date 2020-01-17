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
from auv.msg import trajectory, io_request, surface_command

trajectory_requester = rospy.Publisher('trajectory_request', trajectory, queue_size=3)
io_requester = rospy.Publisher('io_request', io_request, queue_size=3)
last_trajectory = trajectory()
last_io_requests = surface_command().io_requests


def trajectory_content_match(msg1, msg2):
    return msg1.orientation == msg2.orientation and msg1.translation == msg2.translation


def io_content_match(msg1, msg_list):
    for msg in msg_list:
        if msg1.executor == msg.executor and \
                msg1.float == msg.float and \
                msg1.boolean == msg.boolean and \
                msg1.int32 == msg.int32 and \
                msg1.string == msg.string:
            return True
    return False


def callback_request(command):
    global last_trajectory
    global last_io_requests

    # It's possible that the only thing that's changed is the io stuff. If that's the case, there's
    # no need to send another IO request.
    if not trajectory_content_match(last_trajectory, command.desired_trajectory):
        trajectory_requester.publish(command.desired_trajectory)
        last_trajectory = command.desired_trajectory
    for io_request in command.io_requests:
        if not io_content_match(io_request, last_io_requests):
            io_requester.publish(io_request)
            last_io_requests = command.io_requests


if __name__ == '__main__':
    rospy.loginfo("Started command receiver!")
    rospy.init_node('command_receiver', anonymous=False)  # We just want one receiver.

    rospy.Subscriber('surface_command', surface_command, callback_request)

    rospy.spin()
