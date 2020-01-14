This directory contains message definitions. ROS will later convert them into objects that we can interact with and
send wherever we need them.

To add a message, create a message in the proper format in this folder. Then, go to the CMakeLists.txt file and add
it to the list of messages found in 'add_message_files' (at the time of writing, found on line 52). When you next
run catkin_make, you will generate this message and it will be available for use.