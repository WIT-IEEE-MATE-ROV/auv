#!/usr/bin/env python

# This file recieves input from the surface and uses that input to command thrusters and other devices.
# It also sets up the main config stuff.

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


def callback_request(command):
    print("TODO!")


if __name__ == '__main__':
    print("Started core!")
    rospy.init_node('command_receiver', anonymous=False)  # We just want one receiver.

    rospy.Subscriber('surface_command', surface_command, callback_request)

    rospy.spin()
