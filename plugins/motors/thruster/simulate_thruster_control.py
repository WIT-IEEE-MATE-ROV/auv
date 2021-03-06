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
from auv.msg import thruster_sensor, thrustermove


def move_callback(data):
    """
    This is what runs when a new message comes in.
    This is in simulation, so nothing will happen here.
    """
    rospy.loginfo(data)


def sensor_callback(data):
    """
    If there are sensors on your thrusters, here's where you can deal with that.
    In simulation, so again nothing's happening here.
    """
    pass


def listener():
    """
    Listen to thruster commands ad run them.
    """
    # Run listeners, with the option of happening simultaneously.
    rospy.init_node('thrusters', anonymous=True)

    rospy.Subscriber('thruster_commands', thrustermove, move_callback)
    rospy.Subscriber('thruster_sensors', thruster_sensor, sensor_callback)

    # Run forever
    rospy.spin()


if __name__ == '__main__':
    listener()
