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
Publisher = rospy.Publisher('trajectory_cl', trajectory, queue_size=10)

def callback_trajectory(data):
    pubmsg = trajectory()
    pubmsg.orientation = data.orientation
    pubmsg.translation = data.translation
    global Publisher
    Publisher.publish(pubmsg)

def callback_ninedof(data):
    rospy.loginfo(data)

def listener():
    rospy.init_node('control_loop')
    
    # Run listener nodes, with the option of happeneing simultaneously.
    rospy.Subscriber('trajectory_raw', trajectory, callback_trajectory)
    rospy.Subscriber('ninedof_vals', ninedof, callback_ninedof)

    global Publisher

    # Run forever
    rospy.spin()

if __name__ == '__main__':
    listener()
