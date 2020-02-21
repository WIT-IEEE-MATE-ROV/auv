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

import rospy
import auv.msg as auv

"""
TODO: This is totally untested, and I really doubt it works as-is. Feel free to add/modify/delete/replace as necessary
to get this functionality.
"""

Publisher = rospy.Publisher('ninedof_filtered', auv.ninedof, queue_size=3)
history = []


def callback_ninedof(data):
    msg = auv.ninedof()

    global Publisher
    Publisher.publish(msg)


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
    L = sp.linalg.expm(A*tau)  # forward semigroup operator
    Sigma = (sigma**2) * (np.linalg.lstsq(A + A.transpose(), (L * L.transpose() - I)))  # dynamics noise variance integrated
    sqrtS = sp.linalg.sqrtm(Sigma)

    def __init__(self):
        random.seed(self.sd)

        self.m = np.array([[]])
        self.v = np.array([[]])
        self.z = np.array([])
        self.c = np.array([[[]]])
        self.v[:, 0] = self.m0 + sp.linalg.sqrtm(self.C0) * np.random.randn(self.N, 1)  # initial truth
        self.m[:, 0] = 10 * np.random.randn(self.N, 1)  # initial mean/estimate
        self.c[:, :, 0] = 100 * self.C0  # initial covariance
        self.z[0] = 0  # initial ghost observation
        self.H = [1, 0]  # observation operator
        
        self.v_1 = np.array([[]])
        self.z_1 = np.array([])        
        self.m_1 = np.array([[]])        
        self.c_1 = np.array([[[]]])

    def filter(self):
        self.v_1[:, 0] = self.L * self.v[:, 1] + self.sqrtS * np.random.randn(self.N, 1)  # truth
        self.z_1[0] = self.z[0] + self.tau * self.H * self.v_1[:, 0] + self.gamma * np.sqrt(self.tau) * np.random.randn  # observation
        
        mhat = self.L * self.m[:, 1]  # estimator intermediate "predict"
        chat = self.L * self.c[:, :, 1] * self.L.transpose() + self.Sigma  # covariance intermediate "predict"
        
        d = (self.z_1[0] - self.z[0]) / self.tau - self.H * mhat  # "innovation"
        K = (self.tau * chat * self.H.transpose()) / (self.H * chat * self.H.transpose() * self.tau + self.gamma**2)  # "Kalman gain"
        self.m_1[:, 0] = mhat + K * d  # estimator "update"
        self.c_1[:, :, 0] = (self.I - K * self.H) * chat  # covariance "update"


if __name__ == '__main__':
    rospy.init_node('ninedof_filter_kalman', anonymous=True, log_level=rospy.DEBUG)
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
