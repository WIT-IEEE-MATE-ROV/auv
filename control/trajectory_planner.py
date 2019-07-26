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
from auv.msg import position
from auv.msg import multistep_trajectory
from auv.msg import scanarea

pub = rospy.Publisher('planned_path', multistep_trajectory, queue_size=3)

def callback(data):
    currentstep = data.startcorner
    path = multistep_trajectory
    path.trajectories = currentstep

    # TODO: compute a path, build it as below
    # This way, the message will be in order where [0] is the 0th step, [len] is last step, etc.
    # currentstep = generate_path_step_here
    # path.trajectories = path.trajectories + currentstep

    pub.publish(path)

def listener():
    rospy.init_node('trajectory_planner', anonymous=True)
    rospy.Subscriber('scanarea_requests', scanarea, callback)

    rate = rospy.Rate(2)
    rospy.spin()

if __name__ == '__main__':
    listener()
