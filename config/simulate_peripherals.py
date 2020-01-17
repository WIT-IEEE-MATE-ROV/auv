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

from auv.msg import io_request

already_sent_zero = True  # Set to true so that we aren't trying to set anything to zero on startup
last_sent = ""


def hat_to_val(a, b):
    if a == 0:
        if b == 0:
            return None
        if b == 1:
            return "top_front"
        if b == -1:
            return "top_back"
    if a == 1:
        if b == 0:
            return "top_right"
        if b == 1:
            return "front_right"
        if b == -1:
            return "back_right"
    if a == -1:
        if b == 0:
            return "top_left"
        if b == 1:
            return "front_left"
        if b == -1:
            return "back_left"


def handle_peripherals(joystick, msg):
    global already_sent_zero
    global last_sent

    hat = joystick.get_hat(0)
    hat = hat_to_val(hat[0], hat[1])
    io_request_ = io_request()

    if hat is None:
        if not already_sent_zero:
            io_request_.executor = "individual_thruster_control"
            io_request_.string = last_sent
            already_sent_zero = True
    else:
        io_request_.executor = "individual_thruster_control"
        io_request_.string = hat
        io_request_.float = 0.75
        last_sent = hat
        already_sent_zero = False
    msg.io_requests += (io_request_,)

    io_request_ = io_request()  # New message to play with
    if joystick.get_button(0):
        io_request_.executor = "trigger"
        io_request_.boolean = True
        msg.io_requests += (io_request_,)

    return msg  # If we wanted to do something with button presses, we could mess around with that sort of thing here.
