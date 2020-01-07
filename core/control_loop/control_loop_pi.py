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
from auv.msg import ninedof, trajectory

Publisher = rospy.Publisher('trajectory_corrected', trajectory, queue_size=3)
history = []

# Setting the P and I values for use in the PI controller
# Setting P to 1 and I to 0 means that only the goal value is used without modification
value_p = 1
value_i = 0


# This callback handles interpreting the trajectory request and using it in tandem with the sensor values.
def callback_trajectory(data):
    pubmsg = trajectory()

    # Get the roll/pitch/yaw, x/y/z values scaled up by P
    p_times_proportional_orientation = [value_p * data.orientation.roll,
                                        value_p * data.orientation.pitch,
                                        value_p * data.orientation.yaw]
    p_times_proportional_translation = [value_p * data.translation.x,
                                        value_p * data.translation.y,
                                        value_p * data.translation.z]

    # Integrate orientation and translation values
    integrated_orientation = [0, 0, 0]
    integrated_translation = [0, 0, 0]
    for point in history:
        integrated_orientation = [integrated_orientation[0] + point.orientation.roll,
                                  integrated_orientation[1] + point.orientation.pitch,
                                  integrated_orientation[2] + point.orientation.yaw]
        integrated_translation = [integrated_translation[0] + point.translation.x,
                                  integrated_translation[1] + point.translation.y,
                                  integrated_translation[2] + point.translation.z]

    integrated_orientation = [integrated_orientation[0] // integrated_orientation.__len__(),
                              integrated_orientation[1] // integrated_orientation.__len__(),
                              integrated_orientation[2] // integrated_orientation.__len__()]
    integrated_translation = [integrated_translation[0] // integrated_translation.__len__(),
                              integrated_translation[1] // integrated_translation.__len__(),
                              integrated_translation[2] // integrated_translation.__len__()]

    # Now that things are integrated, scale by I
    i_times_integrated_orientation = [value_i * integrated_orientation[0],
                                      value_i * integrated_orientation[1],
                                      value_i * integrated_orientation[2]]
    i_times_integrated_translation = [value_i * integrated_translation[0],
                                      value_i * integrated_translation[1],
                                      value_i * integrated_translation[2]]

    # Sum up the scaled P and I values and assign to a message
    pubmsg.orientation.roll = p_times_proportional_orientation[0] + i_times_integrated_orientation[0]
    pubmsg.orientation.pitch = p_times_proportional_orientation[1] + i_times_integrated_orientation[1]
    pubmsg.orientation.yaw = p_times_proportional_orientation[2] + i_times_integrated_orientation[2]

    pubmsg.translation.x = p_times_proportional_translation[0] + i_times_integrated_translation[0]
    pubmsg.translation.y = p_times_proportional_translation[1] + i_times_integrated_translation[1]
    pubmsg.translation.z = p_times_proportional_translation[2] + i_times_integrated_translation[2]

    global Publisher
    Publisher.publish(pubmsg)


# This callback just handles getting and saving sensor values.
def callback_ninedof(data):
    history.append(data)
    if history.__len__() > 5:  # Set history length
        del history[0]


def listener():
    rospy.init_node('control_loop')

    # Run listener nodes, with the option of happening simultaneously.
    rospy.Subscriber('trajectory_request', trajectory, callback_trajectory)
    rospy.Subscriber('ninedof_filtered', ninedof, callback_ninedof)

    global Publisher

    # Run forever
    rospy.spin()


if __name__ == '__main__':
    listener()
