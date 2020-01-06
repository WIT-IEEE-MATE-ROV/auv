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
    """ This is what runs when a new message comes in """
    print("Not yet implented!")
    """ TODO: 
     Take the values from data (i.e., data.thruster_topfront) and move
     the corresponding PCA channel to the right PWM. Ideally the values of 
     PCA channel to thruster will be quickly adjustable, perhaps by a command
     line input or a config file?
    """


def sensor_callback(data):
    """ If there are sensors on your thrusters, here's where you can deal with that. """
    if data.estop:
        print("estop triggered!")
        # Do something with that, I guess
        # rospy.signal_shutdown("Got an e-stop command!") or whatever


def listener():
    """ Listen to thruster commands ad run them, assuming it's ours. """
    # Run listener nodes, with the option of happening simultaneously.
    rospy.init_node('thrusters', anonymous=True)

    rospy.Subscriber('thruster_commands', thrustermove, move_callback)
    rospy.Subscriber('thruster_sensors', thruster_sensor, sensor_callback)

    # Run forever
    rospy.spin()


if __name__ == '__main__':
    listener()
