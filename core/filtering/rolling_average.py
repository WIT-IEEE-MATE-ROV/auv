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
history = []
history_max_length = 10


# Filter out noise using a rolling average.
def callback(data):
    if history.__len__() > history_max_length:
        translation = data.translation
        orientation = data.orientation

        for point in history:
            translation.x += point.translation.x
            translation.y += point.translation.y
            translation.z += point.translation.z

            orientation.roll += point.orientation.roll
            orientation.pitch += point.orientation.pitch
            orientation.yaw += point.orientation.yaw

        translation.x /= history.__len__()
        translation.y /= history.__len__()
        translation.z /= history.__len__()
        orientation.roll /= history.__len__()
        orientation.pitch /= history.__len__()
        orientation.yaw /= history.__len__()

        msg = ninedof()
        msg.translation = translation
        msg.orientation = orientation
        Publisher.publish(msg)

        # The 'rolling' part of the average: get rid of the oldest data point before adding another data point
        del history[0]
    # This one's not in the if statement because we always want to add data,
    # we only want to remove data if there's enough to allow that
    history.append(data)


if __name__ == '__main__':
    rospy.init_node('filter', anonymous=True)
    rospy.Subscriber('ninedof_values', ninedof, callback)

    rospy.logwarn("The kalman filter being used has not been thoroughly tested, and has not been tuned.")
    rospy.spin()
