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
from auv.msg import ninedof, trajectory

def callback_trajectory(data):
    rospy.loginfo(data)

def listener():
    rospy.init_node('control_loop_orientation')
    
    # Run listener nodes, with the option of happeneing simultaneously.
    rospy.Subscriber('trajectory_raw', trajectory, callback_trajectory)
    rospy.Subscriber('ninedof_vals', ninedof, callback_trajectory)

    global Publisher
    Publisher = rospy.Publisher('trajectory_cl_o', trajectory, queue_size=3)

    # Run forever
    rospy.spin()

if __name__ == '__main__':
    listener()
