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
from auv.msg import thrustermove, trajectory
ESC_IS_INIT = False
Publisher = None


arrx = [
        [0.0, 0.0, 0.0, 0.0], [1.0, -1.0, -1.0, 1.0]  # x
    ]

arry = [
        [0.0, 0.0, 0.0, 0.0], [1.0, 1.0, -1.0, -1.0]  # y
    ]

arrz = [
        [1.0, 1.0, 1.0, 1.0], [0.0, 0.0, 0.0, 0.0]    # z
    ]

arrr = [
        [0.0, 1.0, 0.0, 1.0], [0.0, 0.0, 0.0, 0.0]    # roll
    ]

arrp = [
        [1.0, 0.0, 1.0, 0.0], [0.0, 0.0, 0.0, 0.0]    # pitch
    ]

arrc = [
        [0.0, 0.0, 0.0, 0.0], [1.0, -1.0, 1.0, -1.0]  # c (cut, w/out reusing y)
    ]

arr_corrective = [
        [1, -1, 1, -1], [-1, -1, 1, -1]
    ]

def printarr(arra):
    print("{:.2f} {:.2f} {:.2f} {:.2f} {:.2f} {:.2f} {:.2f} {:.2f}".format(arra[0][0], arra[0][1], arra[0][2], arra[0][3], arra[1][0], arra[1][1], arra[1][2], arra[1][3]))


def arrmult(const, arra):
    return [
        [
            arra[0][0] * const,
            arra[0][1] * const,
            arra[0][2] * const,
            arra[0][3] * const
        ],
        [
            arra[1][0] * const,
            arra[1][1] * const,
            arra[1][2] * const,
            arra[1][3] * const
        ]
    ]


def arrdiv(arra, const):
    try:
        a = arra[0][0] / const
        b = arra[0][1] / const
        c = arra[0][2] / const
        d = arra[0][3] / const

        e = arra[1][0] / const
        f = arra[1][1] / const
        g = arra[1][2] / const
        h = arra[1][3] / const

        return [
            [
                a, b, c, d
            ],
            [
                e, f, g, h
            ]
        ]
    except ZeroDivisionError:
        print("0div")
        return [[0, 0, 0, 0], [0, 0, 0, 0]]

def arrmax(arra):
    rmax = -2
    for i in range(0, 3):
        rmax = max(arra[0][i], rmax)
    for i in range(0, 3):
        rmax = max(arra[1][i], rmax)
    return rmax


def arradd(arra, arrb):
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


def arrmultarr(arra, arrb):
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


def arraddint(arra, i):
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

def matrixToMsg(matrix):
    msg = thrustermove()
    msg.thruster_front = matrix[0][0]
    msg.thruster_back = matrix[0][3]
    msg.thruster_topleft = matrix[1][0]
    msg.thruster_topright = matrix[1][1]
    msg.thruster_backleft = matrix[1][2]
    msg.thruster_backright = matrix[1][3]
    return msg

def callback(data):
    """ This is what runs when a new message comes in """
    movematrix = [[0, 0, 0, 0], [0, 0, 0, 0]]
    movematrix = arradd(movematrix, arrmult(data.orientation.roll, arrr))
    movematrix = arradd(movematrix, arrmult(data.orientation.pitch, arrp))
    movematrix = arradd(movematrix, arrmult(data.orientation.yaw, arrc))
    movematrix = arradd(movematrix, arrmult(data.translation.x, arrx))
    movematrix = arradd(movematrix, arrmult(data.translation.y, arry))
    movematrix = arradd(movematrix, arrmult(data.translation.z, arrz))

    # Now that the matrix exists, it needs to be corrected for ESC/thruster
    # weirdness, normalized, and converted to 0-1 range that the thrusters need.
    movematrix = arrmultarr(arr_corrective, movematrix)
    amax = arrmax(movematrix)
    if amax >= 1:
        movematrix = arrdiv(movematrix, amax)
    movematrix = arraddint(movematrix, 1)
    movematrix = arrdiv(movematrix, 2)

    # Convert it to  thrustermove format and publish
    msg = matrixToMsg(movematrix)
    Publisher.publish(msg)

def listener():
    """ Listen to thruster commands and run them """
    rospy.init_node('trajectory_converter')
    
    # Run listener nodes, with the option of happeneing simultaneously.
    rospy.Subscriber('trajectory_commands', trajectory, callback)

    global Publisher
    Publisher = rospy.Publisher('thruster_commands', thrustermove, queue_size=10)

    # Run forever
    rospy.spin()

if __name__ == '__main__':
    listener()
