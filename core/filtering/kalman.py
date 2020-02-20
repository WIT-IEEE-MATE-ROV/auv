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
import auv.msg as auv

"""
TODO: This is totally untested, and I really doubt it works as-is. Feel free to add/modify/delete/replace as necessary
to get this functionality.
"""

Publisher = rospy.Publisher('ninedof_filtered', auv.ninedof, queue_size=3)
history = []


def callback_ninedof(data):
    history.append(data)
    if history.__len__() > 5:
        del history[0]
        kalman(history)


def kalman(measurements):
    gyro_history = []
    accel_history = []

    for measurement in measurements:
        gyro_history.append([measurement.orientation.roll, measurement.orientation.pitch, measurement.orientation.yaw])
        accel_history.append([measurement.translation.x, measurement.translation.y, measurement.translation.z])

    k_filter = pykalman.KalmanFilter(transition_matrices=[[1, 1, 1], [0, 1, 1], [1, 1, 1]],
                                     observation_matrices=[[0.1, 0.5, 0.0], [-0.3, 0.0, 0.0], [1, 1, 1]])
    filtered_orientation = k_filter.em(np.asarray(gyro_history), n_iter=5)
    filtered_translation = k_filter.em(np.asarray(accel_history), n_iter=5)
    (smoothed_orientation_means, smoothed_orientation_covariance) = filtered_orientation.smooth(gyro_history)
    (smoothed_translation_means, smoothed_translation_covariance) = filtered_translation.smooth(accel_history)

    msg = auv.ninedof()

    msg.orientation.roll = smoothed_orientation_means[4][0]
    msg.orientation.pitch = smoothed_orientation_means[4][1]
    msg.orientation.yaw = smoothed_orientation_means[4][2]
    
    msg.translation.x = smoothed_translation_means[4][0]
    msg.translation.y = smoothed_translation_means[4][1]
    msg.translation.z = smoothed_translation_means[4][2]


    global Publisher
    Publisher.publish(msg)


if __name__ == '__main__':
    rospy.init_node('ninedof_filter_kalman', anonymous=True)
    rospy.Subscriber('ninedof_values', auv.ninedof, callback_ninedof)

    rospy.logwarn("The kalman filter being used has not been thoroughly tested, and has not been tuned.")
    rospy.spin()


class Orientation:
    def __init__(self, roll, pitch, yaw):
        self.roll = roll if roll else 0.0
        self.pitch = pitch if pitch else 0.0
        self.yaw = yaw if yaw else 0.0


class Translation:
    def __init__(self, x, y, z):
        self.x = x if x else 0.0
        self.y = y if y else 0.0
        self.z = z if z else 0.0


class Ninedof:
    def __init__(self, orientation, translation):
        self.translation = translation if translation else None
        self.orientation = orientation if orientation else None
