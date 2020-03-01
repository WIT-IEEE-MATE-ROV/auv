#!/usr/bin/env python

import rospy
from PyQt5.QtCore import QTimer
from auv.msg import ninedof

CALLBACK_ROLL = "Initializing"
CALLBACK_PITCH = "Initializing"
CALLBACK_YAW = "Initializing"
CALLBACK_X = "Initializing"
CALLBACK_Y = "Initializing"
CALLBACK_Z = "Initializing"


def callback(data):
    global CALLBACK_ROLL
    global CALLBACK_YAW
    global CALLBACK_PITCH
    global CALLBACK_X
    global CALLBACK_Y
    global CALLBACK_Z

    roll = data.orientation.roll
    CALLBACK_ROLL = '{0:0.2f}'.format(roll)

    pitch = data.orientation.pitch
    CALLBACK_PITCH = '{0:0.2f}'.format(pitch)

    yaw = data.orientation.yaw
    CALLBACK_YAW = '{0:0.2f}'.format(yaw)

    x = data.translation.x
    CALLBACK_X = '{0:0.2f}'.format(x)

    y = data.translation.y
    CALLBACK_Y = '{0:0.2f}'.format(y)

    z = data.translation.z
    CALLBACK_Z = '{0:0.2f}'.format(z)




def get_x():
    rospy.init_node('ninedof_reciever', anonymous=True)
    rospy.Subscriber("ninedof_values", ninedof, callback)
    return CALLBACK_Z
    rospy.spin()

def get_y():
    rospy.init_node('ninedof_reciever', anonymous=True)
    rospy.Subscriber("ninedof_values", ninedof, callback)
    return CALLBACK_Y
    rospy.spin()


def get_z():
    rospy.init_node('ninedof_reciever', anonymous=True)
    rospy.Subscriber("ninedof_values", ninedof, callback)
    return CALLBACK_Z
    rospy.spin()


def get_roll():
    rospy.init_node('ninedof_reciever', anonymous=True)
    rospy.Subscriber("ninedof_values", ninedof, callback)
    return CALLBACK_ROLL
    rospy.spin()


def get_pitch():
    rospy.init_node('ninedof_reciever', anonymous=True)
    rospy.Subscriber("ninedof_values", ninedof, callback)
    return CALLBACK_PITCH
    rospy.spin()


def get_yaw():
    rospy.init_node('ninedof_reciever', anonymous=True)
    rospy.Subscriber("ninedof_values", ninedof, callback)
    return CALLBACK_YAW
    rospy.spin()
