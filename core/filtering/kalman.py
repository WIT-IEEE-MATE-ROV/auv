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
import pykalman
import numpy as np
from auv.msg import ninedof

"""
TODO: This is totally untested, and I really doubt it works as-is. Feel free to add/modify/delete/replace as necessary
to get this functionality.
"""

Publisher = rospy.Publisher('ninedof_filtered', ninedof, queue_size=3)
history = []


def callback_ninedof(data):
    history.append(data)
    if history.__len__() > 5:
        del history[0]
        kalman(history)


def kalman(measurements):
    translation = []
    orientation = []
    magnetometer = []
    for measurement in measurements:
        translation.append([measurement.translation.x, measurement.translation.y, measurement.translation.z])
        orientation.append([measurement.orientation.roll, measurement.orientation.pitch, measurement.orientation.yaw])
        magnetometer.append([measurement.orientation.roll, measurement.orientation.pitch, measurement.orientation.yaw])

    k_filter = pykalman.KalmanFilter(transition_matrices=[[1, 1, 1], [0, 1, 1], [1, 1, 1]],
                                     observation_matrices=[[0.1, 0.5, 0.0], [-0.3, 0.0, 0.0], [1, 1, 1]])
    filtered_translation = k_filter.em(translation, n_iter=5)
    filtered_orientation = k_filter.em(np.asarray(orientation), n_iter=5)
    filtered_magnetometer = k_filter.em(np.asarray(magnetometer), n_iter=5)
    (smoothed_translation_means, smoothed_translation_covariance) = filtered_translation.smooth(translation)
    (smoothed_orientation_means, smoothed_orientation_covariance) = filtered_orientation.smooth(orientation)
    (smoothed_magnetometer_means, smoothed_magnetometer_covariance) = filtered_magnetometer.smooth(magnetometer)

    msg = ninedof()
    msg.translation.x = smoothed_translation_means[4][0]
    msg.translation.y = smoothed_translation_means[4][1]
    msg.translation.z = smoothed_translation_means[4][2]

    msg.orientation.roll = smoothed_orientation_means[4][0]
    msg.orientation.pitch = smoothed_orientation_means[4][1]
    msg.orientation.yaw = smoothed_orientation_means[4][2]

    msg.magnetometer.roll = smoothed_magnetometer_means[4][0]
    msg.magnetometer.pitch = smoothed_magnetometer_means[4][1]
    msg.magnetometer.yaw = smoothed_magnetometer_means[4][2]

    global Publisher
    Publisher.publish(msg)


if __name__ == '__main__':
    rospy.init_node('filter', anonymous=True)
    rospy.Subscriber('ninedof_values', ninedof, callback_ninedof)

    rospy.logwarn("The kalman filter being used has not been thoroughly tested, and has not been tuned.")
    rospy.spin()
