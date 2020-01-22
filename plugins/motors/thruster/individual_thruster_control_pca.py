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
from auv.msg import io_request, arbitrary_pca_commands

publisher = rospy.Publisher('arbitrary_pca_commands', arbitrary_pca_commands, queue_size=3)


def callback(data):
    """
    If there's a request for an individual thruster to be moved (handy for debug), we receive it and
    handle it.
    """
    if data.executor.lower() == "individual_thruster_control":
        msg = arbitrary_pca_commands()

        msg.set_thruster = True
        msg.set_channel_pwm = False
        msg.set_channel_pwm_send_count = False

        msg.thruster = data.string
        msg.pwm = data.float
        publisher.publish(msg)

    if data.executor.lower() == "kill_thruster":
        msg = arbitrary_pca_commands()

        msg.kill_thruster = True
        msg.thruster = data.string
        publisher.publish(msg)

    if data.executor.lower() == "unkill_thruster":
        msg = arbitrary_pca_commands()

        msg.unkill_thruster = True
        msg.thruster = data.string
        publisher.publish(msg)


if __name__ == '__main__':
    rospy.init_node('individual_thruster_control', anonymous=True)
    rospy.Subscriber('io_request', io_request, callback)
    rospy.spin()
