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
import numpy as np
from auv.msg import surface_command

command_publisher = rospy.Publisher('surface_command', surface_command, queue_size=3)

if __name__ == '__main__':
    rospy.loginfo("Started command receiver!")
    rospy.init_node('command_receiver', anonymous=False)  # We just want one receiver.

    surface_command_msg = surface_command()
    rate = rospy.Rate(2)
    while not rospy.is_shutdown():
        surface_command_msg.desired_trajectory.translation.x = np.random.normal()
        surface_command_msg.desired_trajectory.translation.y = np.random.normal()
        surface_command_msg.desired_trajectory.translation.z = np.random.normal()

        surface_command_msg.desired_trajectory.orientation.roll = np.random.normal()
        surface_command_msg.desired_trajectory.orientation.pitch = np.random.normal()
        surface_command_msg.desired_trajectory.orientation.yaw = np.random.normal()

        command_publisher.publish(surface_command_msg)

        rate.sleep()
