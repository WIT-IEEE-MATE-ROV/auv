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

import math
import numpy as np
import random
import scipy as sp
from scipy import linalg

import rospy
import auv.msg as auv

"""
TODO: This is totally untested, and I really doubt it works as-is. Feel free to add/modify/delete/replace as necessary
to get this functionality.
"""

Publisher = rospy.Publisher('ninedof_filtered', auv.ninedof, queue_size=3)
history = []


class _Kalman:
    N = 2  # dimension of state
    I = np.eye(N)  # identity operator
    gamma = 1  # observational noise variance is gammaˆ2*I
    sigma = 1  # dynamics noise variance is sigmaˆ2*I
    C0 = np.eye(2)  # prior initial condition variance
    m0 = np.array([0, 0])  # prior initial condition mean
    sd = 10  # choose random number seed
    A = np.array([[-1, 1], [-1, -1]])  # dynamics determined by A
    tau = 0.01  # time discretization is tau
    L = linalg.expm(A*tau)  # forward semigroup operator
    Sigma = (sigma**2) * (np.linalg.lstsq(A + A.transpose(), (L * L.transpose() - I)))  # dynamics noise variance integrated
    Sigma = Sigma[0]

    sqrtS = linalg.sqrtm(Sigma)

    def __init__(self):
        random.seed(self.sd)

        self.m = np.zeros((2,1), float)
        self.v = np.zeros((2,2), float)
        self.z = np.zeros((2,2), float)
        self.c = np.zeros((2,2), float)
        self.v = self.m0 + linalg.sqrtm(self.C0) * np.random.randn(self.N, 1)  # initial truth
        self.m = 10 * np.random.randn(self.N, 1)  # initial mean/estimate
        self.c = 100 * self.C0  # initial covariance
        self.z[0] = 0  # initial ghost observation
        self.H = np.array([1, 0])  # observation operator
        
        self.v_1 = np.zeros((2,2), float)
        self.z_1 = np.zeros((1), float)       
        self.m_1 = np.zeros((2,1), float)      
        self.c_1 = np.zeros((2,2), float)

    def filter(self, point):
        self.v_1 = self.L * self.v + self.sqrtS * np.random.randn(self.N, 1)  # truth
        self.z_1 = self.z[0] + self.tau * self.H * self.v_1 + self.gamma * np.sqrt(self.tau) * point  # observation
        
        mhat = self.L * self.m  # estimator intermediate "predict"
        chat = self.L * self.c * self.L.transpose() + self.Sigma  # covariance intermediate "predict"
        
        d = (self.z_1[0] - self.z[0]) / self.tau - self.H * mhat  # "innovation"
        K = (self.tau * chat * self.H.transpose()) / (self.H * chat * self.H.transpose() * self.tau + self.gamma**2)  # "Kalman gain"
        self.m_1 = mhat + K * d  # estimator "update"
        self.c_1 = (self.I - K * self.H) * chat  # covariance "update"
        self.m = self.m_1
        self.v = self.v_1
        self.z = self.z_1
        self.c = self.c_1

        return self.m[0][0]


class Kalman:
    gyro_roll = _Kalman()
    gyro_pitch = _Kalman()
    gyro_yaw = _Kalman()
    accel_x = _Kalman()
    accel_y = _Kalman()
    accel_z = _Kalman()

    @staticmethod
    def filter(point):
        out_msg = auv.ninedof()

        out_msg.orientation.roll = Kalman.gyro_roll.filter(point.orientation.roll)
        out_msg.orientation.pitch = Kalman.gyro_pitch.filter(point.orientation.pitch)
        out_msg.orientation.yaw = Kalman.gyro_yaw.filter(point.orientation.yaw)
        out_msg.translation.x = Kalman.accel_x.filter(point.translation.x)
        out_msg.translation.y = Kalman.accel_y.filter(point.translation.y)
        out_msg.translation.z = Kalman.accel_z.filter(point.translation.z)

        return out_msg


def callback_ninedof(data):

    rospy.logdebug('Input: {:.3f};{:.3f};{:.3f};{:.3f};{:.3f};{:.3f};'.format(
        data.orientation.roll,
        data.orientation.pitch,
        data.orientation.yaw,
        data.translation.x,
        data.translation.y,
        data.translation.z
        ))

    msg = Kalman.filter(data)

    rospy.logdebug('Output: {:.3f};{:.3f};{:.3f};{:.3f};{:.3f};{:.3f};'.format(
        msg.orientation.roll,
        msg.orientation.pitch,
        msg.orientation.yaw,
        msg.translation.x,
        msg.translation.y,
        msg.translation.z
        ))

    global Publisher
    Publisher.publish(msg)


if __name__ == '__main__':
    rospy.init_node('ninedof_filter_kalman', anonymous=True, log_level=rospy.DEBUG)
    rospy.Subscriber('ninedof_values', auv.ninedof, callback_ninedof)

    rospy.logwarn("The kalman filter being used has not been thoroughly tested, and has not been tuned.")
    rospy.spin()
