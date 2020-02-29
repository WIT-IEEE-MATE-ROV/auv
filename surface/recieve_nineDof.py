#!/usr/bin/env python

import rospy
from auv.msg import ninedof

def callback(data):
    rospy.loginfo("I heard %s",data.orientation.roll)

def listener():
    rospy.init_node('ninedof_reciever',anonymous=True)
    rospy.Subscriber("ninedof_values", ninedof, callback)

    rospy.spin()

if __name__ == '__main__':
    listener()