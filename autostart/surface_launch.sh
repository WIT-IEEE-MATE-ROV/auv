#!/bin/bash

export ROS_MASTER_URI=http://chickensoup.local:11311
bash -c "source /home/ubuntu/catkin_ws/devel/setup.bash && rosrun auv joystick_sender.py"

