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


def hat_to_val(a, b):
    if a == 0:
        if b == 0:
            return None
        if b == 1:
            return "topfront"
        if b == -1:
            return "topleft"
    if a == 1:
        if b == 0:
            return "topright"
        if b == 1:
            return "frontright"
        if b == -1:
            return "frontleft"
    if a == -1:
        if b == 0:
            return "topback"
        if b == 1:
            return "backleft"
        if b == -1:
            return "backright"


def handle_peripherals(joystick, msg):
    hat = joystick.get_hat(0)
    hat = hat_to_val(hat[0], hat[1])

    if hat is not None:
        msg.io_request.executor = "individual_thruster_control"
        msg.io_request.string = hat

    return msg  # If we wanted to do something with button presses, we could mess around with that sort of thing here.
