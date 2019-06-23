#!/usr/bin/env python

import rospy
from auv.msg import thrustermove

def publisher():
    pub = rospy.Publisher('thruster_commands', thrustermove, queue_size=3)
    rospy.init_node('pca_talker', anonymous=True)
    rate = rospy.Rate(10) # 10hz

    while not rospy.is_shutdown():
        msg = thrustermove()
        msg.thruster_front = 0
        msg.thruster_back = 0
        msg.thruster_topleft = 0
        msg.thruster_topright = 0
        msg.thruster_backleft = 0
        msg.thruster_backright = 0

        pub.publish(msg)
        rate.sleep()

if __name__ == '__main__':
    try:
        publisher()
    except rospy.ROSInterruptException:
        pass
