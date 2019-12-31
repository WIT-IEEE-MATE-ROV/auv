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

Publisher = rospy.Publisher('ninedof_filtered', ninedof, queue_size=3)


def callback_ninedof(data):
    pubmsg = ninedof()
    # TODO: Actually filter these values through Kalman's method
    global Publisher
    Publisher.publish(pubmsg)


if __name__ == '__main__':
    rospy.init_node('filter', anonymous=True)
    rospy.Subscriber('ninedof_values', ninedof, callback_ninedof)

    rospy.spin()
