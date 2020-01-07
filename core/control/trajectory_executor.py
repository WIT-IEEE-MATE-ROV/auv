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
from auv.msg import trajectory
from auv.msg import mode
from auv.msg import position
from auv.msg import ninedof
from auv.msg import multistep_trajectory

pub = rospy.Publisher('trajectory_execution', trajectory, queue_size=3)


def ninedof_current_callback(data):
    rospy.loginfo("%s", data)


def ninedof_position_callback(data):
    rospy.loginfo("%s", data)


def trajectory_callback(data):
    rospy.loginfo("%s", data)


def trajectory_callback(data):
    rospy.loginfo("%s", data)


def listener():
    rospy.init_node('trajectory_executor', anonymous=True)
    rospy.Subscriber('ninedof_current', ninedof, ninedof_current_callback)
    rospy.Subscriber('ninedof_integrated', position, ninedof_position_callback)
    rospy.Subscriber('planned_path', multistep_trajectory, trajectory_callback)

    rate = rospy.Rate(5)
    # TODO
    sendtraj = trajectory()
    while not rospy.is_shutdown():
        pub.publish(sendtraj)
        rate.sleep()


if __name__ == '__main__':
    listener()
