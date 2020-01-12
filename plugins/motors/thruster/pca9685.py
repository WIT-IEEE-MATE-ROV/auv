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
from auv.msg import thruster_sensor, thrustermove, arbitrary_pca_commands

# TODO: Use a config file instead of hardcoding anything
thruster_dictionary = {
    'topfront': 5,
    'topback': 6,
    'topleft': -1,
    'topright': -1,
    'frontleft': 4,
    'frontright': 1,
    'backleft': 3,
    'backright': 2
}

try:
    import Adafruit_PCA9685 as PCA
except:
    rospy.logerr("Failed to import Adafruit PCA library.")

pca = None
try:
    pca = PCA.PCA9685()
    pca.set_pwm_freq(390)
except:
    rospy.logerr("Failed to initialize PCA.")

MAX_ATTEMPT_COUNT = 5
MIN_PCA_INT_VAL = 1850
MAX_PCA_INT_VAL = 3050


def scale(value):
    return int((value * (MAX_PCA_INT_VAL - MIN_PCA_INT_VAL)) + MIN_PCA_INT_VAL)


def stop_thrusters():
    if pca is None:
        rospy.loginfo("[simulating PCA]: Stopping thrusters.")
        return

    for thruster in thruster_dictionary.keys():
        try:
            if thruster_dictionary[thruster] == -1:  # Flag value: there is no -1 pca channel, skip this thruster
                rospy.logdebug("Did not move due to no channel specification: " + thruster)
            else:
                rospy.logdebug(thruster + " " + str(thruster_dictionary[thruster]))
                pca.set_pwm(thruster_dictionary[thruster], 0, scale(.5))  # Stop moving
                time.sleep(.5)  # If you go too fast between IO requests it can throw an error.
                pca.set_pwm(thruster_dictionary[thruster], 0, 0)  # Kill the channel
                time.sleep(.5)
        except Exception as e:
            rospy.logerr(
                "Thruster stopping failed: Attempting " + thruster + " on " + str(thruster_dictionary[thruster]))
            rospy.logerr("Error cause: " + str(e))

    rospy.loginfo("Stopped thrusters.")


def init_thrusters():
    if pca is None:
        rospy.loginfo("[simulating PCA]: Initializing thrusters.")
        return

    for thruster in thruster_dictionary.keys():
        try:
            if thruster_dictionary[thruster] == -1:  # Flag value: there is no -1 pca channel, skip this thruster
                rospy.logdebug("Did not move due to no channel specification: " + thruster)
            else:
                rospy.logdebug(thruster + " " + str(thruster_dictionary[thruster]))
                pca.set_pwm(thruster_dictionary[thruster], 0, scale(.5))
                time.sleep(1)
                pca.set_pwm(thruster_dictionary[thruster], 0, scale(.75))
                time.sleep(1)
                pca.set_pwm(thruster_dictionary[thruster], 0, scale(.5))
                time.sleep(.25)
        except Exception as e:
            rospy.logerr(
                "Thruster movement failed: Attempting " + thruster + " on " + str(thruster_dictionary[thruster]))
            rospy.logerr("Error cause: " + str(e))

    rospy.loginfo("Initialized thrusters!")


def move_callback(data):
    """ This is what runs when a new message comes in """
    if pca is None:
        rospy.loginfo("[simulating PCA]: Move callback entered. msg:\n"+str(data))
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
                rospy.logdebug("Did not move due to no channel specification: " + thruster)
            else:
                rospy.logdebug(
                    thruster + " " + str(thruster_dictionary[thruster]) + " " + str(thruster_values[thruster]))
                pca.set_pwm(thruster_dictionary[thruster], 0, scale(thruster_values[thruster]))
        except Exception as e:
            # It's possible for the rate of IO requests to be such that the PCA freaks out
            # because we're a bit too quick. We'll catch them and move on, it'll be OK.
            rospy.logdebug("Thruster movement failed: Attempting " + thruster + " at " +
                           str(scale(thruster_values[thruster])) + " (" +
                           str(thruster_values[thruster]) + ") on " +
                           str(thruster_dictionary[thruster]))
            rospy.logdebug("Error cause: " + str(e))


def sensor_callback(data):
    """ If there are sensors on your thrusters, here's where you can deal with that. """
    if data.estop:
        print("estop triggered!")
        # Do something with that, I guess
        # rospy.signal_shutdown("Got an e-stop command!") or whatever


def persistent_pca(channel, pwm):
    """
    The usual way we set the PCA does not care if it succeeds or fails, because we know another command is just
    around the corner. However, this is used for things like setting PWM for a servo, which ideally we're only
    sending once. If it fails the same way, that would be bad, so we need a more persistent alternative.
    """
    keep_trying = True
    attempt_count = 0
    while keep_trying:
        try:
            pca.set_pwm(channel, 0, pwm)

            # If we got here, the PCA didn't freak out. It'll do that sometimes if we request things too back-to-back.
            keep_trying = False
        except Exception as e:
            attempt_count += 1
            if attempt_count > MAX_ATTEMPT_COUNT:
                rospy.logwarn("After " +
                              str(attempt_count) + "attempts, we failed to set the PCA to " +
                              str(pwm) + " (channel " +
                              str(channel) + ")")
                rospy.logerr(e)  # We're assuming that it failed for the same reason each time.
                keep_trying = False


def arbitrary_pca_callback(data):
    if pca is None:
        rospy.loginfo("[simulating PCA]: arbitrary pca callback entered. msg:\n"+str(data))
        return

    runcount = 0  # We'll use this to check that the message gave precisely one command.
    if data.set_thruster:
        if data.thruster == "all":
            for thruster in thruster_dictionary.keys():
                persistent_pca(thruster_dictionary[thruster], scale(data.pwm))
        if thruster_dictionary[data.thruster] is not None and thruster_dictionary[data.thruster] != -1:
            persistent_pca(thruster_dictionary[data.thruster], scale(data.pwm))
        else:
            rospy.logwarn("You've tried to specify a thruster with no channel association!")
        runcount += 1

    if data.set_channel_pwm:
        rospy.logwarn("This function is untested!")
        persistent_pca(data.channel, int(data.pwm * 4096))
        runcount += 1

    if data.set_channel_pwm_send_count:
        rospy.logwarn("This function is untested!")
        pca.set_pwm(data.channel, 0, int(0.5 * 4096))  # 50% pulsewidth
        # This time.sleep is the part of the function that bothers me. I think it's being computed correctly to give the
        # desired count of pulses, but I don't know if this will end up blocking. We should be OK given that it's in a
        # callback, but its worth verifying that.
        # TODO!
        time.sleep(data.count * pca.frequency)
        pca.set_pwm(data.channel, 0, 0)
        runcount += 1

    if runcount != 1:
        rospy.logwarn(
            "Your arbitrary PCA command specified " + str(runcount) + "operations. You are using this message" +
            "incorrectly, set precisely one!")


def listener():
    """ Listen to thruster commands ad run them, assuming it's ours. """
    # Run listener nodes, with the option of happening simultaneously.
    rospy.init_node('thrusters', anonymous=True)

    rospy.Subscriber('thruster_commands', thrustermove, move_callback)
    rospy.Subscriber('thruster_sensors', thruster_sensor, sensor_callback)
    rospy.Subscriber('arbitrary_pca_commands', arbitrary_pca_commands, arbitrary_pca_callback)

    if pca is None:
        rospy.logerr("PCA failed to initialize. We're going to assume that's because you're not running on the"
                     " right hardware, and we'll run in simulation instead.")

    init_thrusters()
    # Run forever
    rospy.spin()

    # If we're here, the process has been killed
    rospy.loginfo("Told to shut down. Stopping movement and setting channels to 0...")
    stop_thrusters()


if __name__ == '__main__':
    '''
    parser = argparse.ArgumentParser("Create a ROS interface for the PCA9685 hardware to control thrusters and other "
                                     "motors.")
    parser.add_argument('min_pca_int_value', type=int, help='Integer value that represents the lowest value to be '
                                                            'passed to the PCA.')
    parser.add_argument('max_pca_int_value', type=int, help='Integer value that represents the highest value to be '
                                                            'passed to the PCA.')
    args = parser.parse_args(rospy.myargv()[1:])

    MAX_PCA_INT_VAL = args.max_pca_int_value
    MIN_PCA_INT_VAL = args.min_pca_int_value
    if MIN_PCA_INT_VAL <= MAX_PCA_INT_VAL:
        rospy.logerr("Your max PCA value <= your min PCA value. Swapping, but you've configured stuff wrong so it'll "
                     "probably break elsewhere, too.")
        tmp = MAX_PCA_INT_VAL
        MAX_PCA_INT_VAL = MIN_PCA_INT_VAL
        MIN_PCA_INT_VAL = tmp
    '''
    listener()
