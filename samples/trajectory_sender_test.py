#!/usr/bin/env python

import rospy
from auv.msg import trajectory


def publisher():
    pub = rospy.Publisher('trajectory_commands', trajectory, queue_size=3)
    rospy.init_node('trajectory_talker', anonymous=True)
    rate = rospy.Rate(10)  # 10hz

    while not rospy.is_shutdown():
        msg = trajectory()
        msg.orientation.roll = .1
        msg.orientation.pitch = -.2
        msg.orientation.yaw = .3
        msg.translation.x = -.4
        msg.translation.y = .5
        msg.translation.z = -.6

        pub.publish(msg)
        rate.sleep()


if __name__ == '__main__':
    try:
        publisher()
    except rospy.ROSInterruptException:
        pass
