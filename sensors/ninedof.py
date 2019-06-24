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
from auv.msg import ninedof

pub = rospy.Publisher('ninedof_vals', ninedof, queue_size=3)

def listener():
    rospy.init_node('ninedof', anonymous=True)

    rate = rospy.Rate(5)
    # TODO
    sendval = ninedof()
    while not rospy.is_shutdown():
        pub.publish(sendval)
        rate.sleep()


if __name__ == '__main__':
    listener()
