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

from auv.msg import io_request, trajectory

already_sent_zero = True  # Set to true so that we aren't trying to set anything to zero on startup
last_sent = ""
servo_in_position = True
stepper_already_moving = True
thruster_already_killed = True
thruster_already_unkilled = True


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
    global servo_in_position
    global stepper_already_moving
    global thruster_already_killed
    global thruster_already_unkilled

    hat = joystick.get_hat(0)
    hat = hat_to_val(hat[0], hat[1])
    io_request_ = io_request()

    if hat is None:
        if not already_sent_zero:
            io_request_.executor = "individual_thruster_control"
            io_request_.string = last_sent
            already_sent_zero = True
            msg.io_requests += (io_request_,)
    else:
        io_request_.executor = "individual_thruster_control"
        io_request_.string = hat
        io_request_.float = 0.75
        last_sent = hat
        already_sent_zero = False
        msg.io_requests += (io_request_,)

    if joystick.get_button(0):  # Safety trigger: Do not Send trajectory data if this trigger is held.
        msg.desired_trajectory = trajectory()

    if not joystick.get_button(1):  # 'Boost mode': If this button is pressed, multiply trajectory by 2
        # We implement this by always cutting by 2, and then when the button is pressed, not cutting in half.
        msg.desired_trajectory.translation.x = msg.desired_trajectory.translation.x / 2
        msg.desired_trajectory.translation.y = msg.desired_trajectory.translation.y / 2
        msg.desired_trajectory.translation.z = msg.desired_trajectory.translation.z / 2
        msg.desired_trajectory.orientation.roll = msg.desired_trajectory.orientation.roll / 2
        msg.desired_trajectory.orientation.pitch = msg.desired_trajectory.orientation.pitch / 2
        msg.desired_trajectory.orientation.yaw = msg.desired_trajectory.orientation.yaw / 2

    if joystick.get_button(6):  # Kill thrusters button
        if not thruster_already_killed:
            io_request_ = io_request()
            io_request_.executor = "kill_thruster"
            io_request_.string = "front_left"
            msg.io_requests += (io_request_,)

            io_request_ = io_request()
            io_request_.executor = "kill_thruster"
            io_request_.string = "front_right"
            msg.io_requests += (io_request_,)

            io_request_ = io_request()
            io_request_.executor = "kill_thruster"
            io_request_.string = "top_front"
            msg.io_requests += (io_request_,)

            thruster_already_killed = True
    elif thruster_already_killed:  # Make sure the button is released before we send another stream of kill stuff
        thruster_already_killed = False

    if joystick.get_button(7):  # Un-kill thrusters button
        if not thruster_already_unkilled:
            io_request_ = io_request()
            io_request_.executor = "unkill_thruster"
            io_request_.string = "front_left"
            msg.io_requests += (io_request_,)

            io_request_ = io_request()
            io_request_.executor = "unkill_thruster"
            io_request_.string = "front_right"
            msg.io_requests += (io_request_,)

            io_request_ = io_request()
            io_request_.executor = "unkill_thruster"
            io_request_.string = "top_front"
            msg.io_requests += (io_request_,)

            thruster_already_unkilled = True
    elif thruster_already_unkilled:  # Make sure the button is released before we send another stream of un-kill stuff
        thruster_already_unkilled = False

    if joystick.get_button(10):  # Servo button
        io_request_ = io_request()  # Clean message
        io_request_.executor = "servo"
        io_request_.float = 0.5
        servo_in_position = True
        msg.io_requests += (io_request_,)
    elif servo_in_position:  # If the button is not pressed and the servo is currently in position:
        # This way, when the button is released, the servo channel should return to 0.
        io_request_ = io_request()  # Clean message
        io_request_.executor = "servo"
        io_request_.float = 0
        servo_in_position = False
        msg.io_requests += (io_request_,)

    if joystick.get_button(11):  # Stepper button
        if not stepper_already_moving:
            io_request_ = io_request()
            io_request_.executor = "stepper"
            io_request_.int32 = 800  # At 400 hz, this should be noticable on a oscilloscope
            msg.io_requests += (io_request_,)
            stepper_already_moving = True
    elif stepper_already_moving:  # Make sure the button is released before we send another stream of stepper stuff
        stepper_already_moving = False

    return msg  # If we wanted to do something with button presses, we could mess around with that sort of thing here.
