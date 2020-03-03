#!/usr/bin/env python
import ms5837
import rospy
import numpy as np
from auv.msg import bar30

sensor = ms5837.MS5837_30BA()
rospy.init_node('bar30_sender',anonymous = False)
pub = rospy.Publisher('bar30', bar30, queue_size = 10)
rate = rospy.Rate(10)

def read(msg):
    msg = msg()
    msg.depth = sensor.depth 
    msg.pressure = sensor.pressure(UNITS_psi)
    msg.temperature = sensor.temperature(UNITS_Centigrade)
    pub.publish(msg)

def test(msg):
    msg = msg()
    msg.depth = 10
    msg.pressure = 11
    msg.temperature = 12
    pub.publish(msg)

if __name__ == '__main__':
    while not rospy.is_shutdown():
        try:
            read(bar30)
        except Exception as e:
            print('Bar30 not detected\nor something else is fucked, go bother the electron diddlers\n Running test script')
            test(bar30)
            rate.sleep()
