#!/usr/bin/env python3

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
import numpy as np
from auv.msg import ninedof

# Where we'll be publishing our results
nineDof_current_pub = rospy.Publisher('ninedof', ninedof, queue_size=3)


def publisher():
    rospy.init_node('simulate_nineDof', anonymous=True)
    rate = rospy.Rate(5)

    sendval_ninedof = ninedof()
    while not rospy.is_shutdown():
        # While this node is still running, keep getting sensor values
        # In this case, it's simulated, so we're making up values
        # In your case, replace this block with however you're getting values
        sendval_ninedof.orientation.roll   = np.random.normal()
        sendval_ninedof.orientation.pitch  = np.random.normal()
        sendval_ninedof.orientation.yaw    = np.random.normal()
        sendval_ninedof.translation.x      = np.random.normal()
        sendval_ninedof.translation.y      = np.random.normal()
        sendval_ninedof.translation.z      = np.random.normal()
        sendval_ninedof.magnetometer.roll  = np.random.normal()
        sendval_ninedof.magnetometer.pitch = np.random.normal()
        sendval_ninedof.magnetometer.yaw   = np.random.normal()

        nineDof_current_pub.publish(sendval_ninedof)
        rate.sleep()


if __name__ == '__main__':
    publisher()
