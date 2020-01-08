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
import argparse
from auv.msg import thruster_sensor, thrustermove

# TODO: Use a config file instead of hardcoding anything
thruster_dictionary = {
    'topfront': 1,
    'topback': 2,
    'topleft': -1,
    'topright': -1,
    'frontleft': 3,
    'frontright': 4,
    'backleft': 5,
    'backright': 6
}

successful_start = True
try:
    import Adafruit_PCA9685 as PCA
except:
    rospy.logerr("Failed to import Adafruit PCA library.")
    successful_start = False

try:
    pca = PCA.PCA9685()
    pca.frequency = 400
except:
    rospy.logerr("Failed to initialize PCA.")
    successful_start = False


def scale(value):
    return (value - 1200) * (1300 - 1200) / (1300 - 1200) + 1200


def init_thrusters():
    msg = thrustermove()
    msg.thruster_topfront = .5
    msg.thruster_topback = .5
    msg.thruster_topleft = .5
    msg.thruster_topback = .5
    msg.thruster_frontleft = .5
    msg.thruster_frontback = .5
    msg.thruster_frontright = .5
    msg.thruster_frontfront = .5
    move_callback(msg)


def move_callback(data):
    """ This is what runs when a new message comes in """

    if not successful_start:
        rospy.logerr("Failed to safely start PCA! No movement will occur.")
        return

    # Convert data into a nicer dictionary
    thruster_values = {
        'topfront': data.thruster_topfront,
        'topback': data.thruster_topback,
        'topleft': data.thruster_topleft,
        'topright': data.thruster_topright,
        'frontleft': data.thruster_frontleft,
        'frontright': data.thruster_frontright,
        'backleft': data.thruster_backleft,
        'backright': data.thruster_backright
    }

    for thruster in thruster_dictionary.keys():
        if thruster_dictionary[thruster] == -1:  # Flag value: there is no -1 pca channel, skip this thruster
            pass
        else:
            pca.set_pwm(thruster_dictionary[thruster], 0, scale(thruster_values[thruster]))


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

    init_thrusters()
    # Run forever
    rospy.spin()


if __name__ == '__main__':
    listener()
