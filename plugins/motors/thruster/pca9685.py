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
import time
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
    return int((value*(1600-1200))+1200)


def stop_thrusters():
    for thruster in thruster_dictionary.keys():
        try:
            if thruster_dictionary[thruster] == -1:  # Flag value: there is no -1 pca channel, skip this thruster
                rospy.logdebug("Did not move due to no channel specification: "+thruster)
            else:
                rospy.logdebug(thruster+" "+str(thruster_dictionary[thruster]))
                pca.set_pwm(thruster_dictionary[thruster], 0, scale(.5)) # Stop moving
                time.sleep(.5) #  If you go too fast between IO requests it can throw an error.
                pca.set_pwm(thruster_dictionary[thruster], 0, 0) # Kill the channel
                time.sleep(.5)
        except Exception as e:
            rospy.logerr("Thruster stopping failed: Attempting "+thruster+" on "+str(thruster_dictionary[thruster]))
            rospy.logerr("Error cause: "+str(e))
 
    rospy.loginfo("Stopped thrusters.")


def init_thrusters():
    for thruster in thruster_dictionary.keys():
        try:
            if thruster_dictionary[thruster] == -1:  # Flag value: there is no -1 pca channel, skip this thruster
                rospy.logdebug("Did not move due to no channel specification: "+thruster)
            else:
                rospy.logdebug(thruster+" "+str(thruster_dictionary[thruster]))
                pca.set_pwm(thruster_dictionary[thruster], 0, scale(.5))
                time.sleep(.5)
        except Exception as e:
            rospy.logerr("Thruster movement failed: Attempting "+thruster+" on "+str(thruster_dictionary[thruster]))
            rospy.logerr("Error cause: "+str(e))
 
    rospy.loginfo("Initialized thrusters!")



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
        try:
            if thruster_dictionary[thruster] == -1:  # Flag value: there is no -1 pca channel, skip this thruster
                rospy.logdebug("Did not move due to no channel specification: "+thruster)
            else:
                rospy.logdebug(thruster+" "+str(thruster_dictionary[thruster])+" "+str(thruster_values[thruster]))
                pca.set_pwm(thruster_dictionary[thruster], 0, scale(thruster_values[thruster]))
        except Exception as e:
            # It's possible for the rate of IO requests to be such that the PCA freaks out
            # because we're a bit too quick. We'll catch them and move on, it'll be OK.
            rospy.logdebug("Thruster movement failed: Attempting "+thruster+" at "+str(scale(thruster_values[thruster]))+" ("+str(thruster_values[thruster])+") on "+str(thruster_dictionary[thruster]))
            rospy.logdebug("Error cause: "+str(e))


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

    # If we're here, the process has been killed
    rospy.loginfo("Told to shut down. Stopping movement and setting channels to 0...")
    stop_thrusters()    


if __name__ == '__main__':
    listener()
