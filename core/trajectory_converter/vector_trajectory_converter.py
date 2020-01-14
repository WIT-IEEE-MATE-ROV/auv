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
from math import floor
from auv.msg import thrustermove, trajectory

ESC_IS_INIT = False
Publisher = rospy.Publisher('thruster_commands', thrustermove, queue_size=3)

# These arrays are in the format:
# [top front, top right, top back, top left], [front left, front right, back right, back left]
const_array_x = [
    [0.0, 0.0, 0.0, 0.0], [1.0, -1.0, -1.0, 1.0]  # x
]

const_array_y = [
    [0.0, 0.0, 0.0, 0.0], [1.0, 1.0, -1.0, -1.0]  # y
]

const_array_z = [
    [1.0, 1.0, 1.0, 1.0], [0.0, 0.0, 0.0, 0.0]  # z
]

const_array_roll = [
    [0.0, 1.0, 0.0, 1.0], [0.0, 0.0, 0.0, 0.0]  # roll
]

const_array_pitch = [
    [1.0, 0.0, -1.0, 0.0], [0.0, 0.0, 0.0, 0.0]  # pitch
]

const_array_cut = [
    [0.0, 0.0, 0.0, 0.0], [1.0, -1.0, 1.0, -1.0]  # cut
]

# In the event that a thruster is backwards, or running too fast, it can be corrected here.
# TODO: get these from a config file
arr_corrective = [
    [-1, 1, -1, 1], [1, 1, -1, -1]
]


def print_array(array):
    rospy.loginfo(
        "{:.2f} {:.2f} {:.2f} {:.2f} {:.2f} {:.2f} {:.2f} {:.2f}".format(array[0][0], array[0][1],
                                                                         array[0][2], array[0][3],
                                                                         array[1][0], array[1][1],
                                                                         array[1][2], array[1][3]))


def multiply_array_by_constant(const, array):
    return [
        [
            array[0][0] * const,
            array[0][1] * const,
            array[0][2] * const,
            array[0][3] * const
        ],
        [
            array[1][0] * const,
            array[1][1] * const,
            array[1][2] * const,
            array[1][3] * const
        ]
    ]


def divide_array_by_constant(array, const):
    try:
        a = array[0][0] / const
        b = array[0][1] / const
        c = array[0][2] / const
        d = array[0][3] / const

        e = array[1][0] / const
        f = array[1][1] / const
        g = array[1][2] / const
        h = array[1][3] / const

        return [
            [
                a, b, c, d
            ],
            [
                e, f, g, h
            ]
        ]
    except ZeroDivisionError:
        rospy.logwarn("Dividing by zero in trajectory converter. Assuming all zeros to allow safe continuing.")
        return [[0, 0, 0, 0], [0, 0, 0, 0]]


def find_max_array_val(arra):
    rmax = -2
    for i in range(0, 3):
        rmax = max(arra[0][i], rmax)
    for i in range(0, 3):
        rmax = max(arra[1][i], rmax)
    return rmax


def add_array_elements(arra, arrb):
    return [
        [
            arra[0][0] + arrb[0][0],
            arra[0][1] + arrb[0][1],
            arra[0][2] + arrb[0][2],
            arra[0][3] + arrb[0][3]
        ],
        [
            arra[1][0] + arrb[1][0],
            arra[1][1] + arrb[1][1],
            arra[1][2] + arrb[1][2],
            arra[1][3] + arrb[1][3]

        ]
    ]


def multiply_array_by_array(arra, arrb):
    return [
        [
            arra[0][0] * arrb[0][0],
            arra[0][1] * arrb[0][1],
            arra[0][2] * arrb[0][2],
            arra[0][3] * arrb[0][3]
        ],
        [
            arra[1][0] * arrb[1][0],
            arra[1][1] * arrb[1][1],
            arra[1][2] * arrb[1][2],
            arra[1][3] * arrb[1][3]

        ]
    ]


def add_constant_to_array(arra, i):
    return [
        [
            arra[0][0] + i,
            arra[0][1] + i,
            arra[0][2] + i,
            arra[0][3] + i
        ],
        [
            arra[1][0] + i,
            arra[1][1] + i,
            arra[1][2] + i,
            arra[1][3] + i

        ]
    ]


def matrix_to_msg(matrix):
    """
    Grab our matrix values and pass them to the corresponding msg values.
    """
    msg = thrustermove()
    msg.top_front = matrix[0][0]
    msg.top_right = matrix[0][1]
    msg.top_back = matrix[0][2]
    msg.top_left = matrix[0][3]
    msg.front_left = matrix[1][0]
    msg.front_right = matrix[1][1]
    msg.back_right = matrix[1][2]
    msg.back_left = matrix[1][3]
    return msg


def callback(data):
    """
    This is what runs when a new message comes in.
    We take the orientation/translation data and split it into individual components for each thruster.
    Each base direction (x, y, z, roll, pitch, yaw) is made of a combination of thruster directions. By
    multiplying the user-specified base directions with the thruster directions, we create a new matrix
    that represents the value for every thruster.

    The only catch is that this can lead to values that are greater than one, which doesn't make sense.
    We find the largest value, and divide everything by it to scale it down to values that do make sense.
    The only other catch is that if all the values are less than one, this division will make us go faster
    than desired. So, we only perform this division if any value is greater than one.
    """
    movematrix = [[0, 0, 0, 0], [0, 0, 0, 0]]

    # Take the roll, pitch, etc, data and turn it into corresponding matrix values
    movematrix = add_array_elements(movematrix, multiply_array_by_constant(data.orientation.roll, const_array_roll))
    movematrix = add_array_elements(movematrix, multiply_array_by_constant(data.orientation.pitch, const_array_pitch))
    movematrix = add_array_elements(movematrix, multiply_array_by_constant(data.orientation.yaw, const_array_cut))
    movematrix = add_array_elements(movematrix, multiply_array_by_constant(data.translation.x, const_array_x))
    movematrix = add_array_elements(movematrix, multiply_array_by_constant(data.translation.y, const_array_y))
    movematrix = add_array_elements(movematrix, multiply_array_by_constant(data.translation.z, const_array_z))

    # Now that the matrix exists, it needs to be corrected for ESC/thruster
    # weirdness, normalized, and converted to 0-1 range that the thrusters need.
    movematrix = multiply_array_by_array(arr_corrective, movematrix)
    amax = find_max_array_val(movematrix)

    # If the value is less than 1 we shouldn't mess with it, but we need to fix it otherwise so that 1 is the max.
    if amax >= 1:
        movematrix = divide_array_by_constant(movematrix, amax)
    movematrix = add_constant_to_array(movematrix, 1)
    movematrix = divide_array_by_constant(movematrix, 2)

    # Convert it to  thrustermove format and publish
    msg = matrix_to_msg(movematrix)
    Publisher.publish(msg)


def listener():
    """
    Set up our node, subscriber, and then spin.
    """
    rospy.init_node('trajectory_converter')

    # Run listener nodes, with the option of happening simultaneously.
    rospy.Subscriber('trajectory_corrected', trajectory, callback)

    # Run forever
    rospy.spin()


if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        'Creates a ROS node to convert translations and orientations into individual thruster instructions.')
    parser.add_argument('--correction',
                        help='Correct thrusters that are too fast or are spinning in reverse.')
    args = parser.parse_args(rospy.myargv()[1:])

    # If correction is in args, get it, parse it, and place it into the appropriate place in the corrective array
    if 'correction' in args:
        correction = [float(item) for item in args.correction.split(' ')]
        for i in range(0, 8, 1):
            arr_corrective[floor(i / 4)][i % 4] = correction[i]

    listener()
