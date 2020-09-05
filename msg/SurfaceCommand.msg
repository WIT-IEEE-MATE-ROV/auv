# Message for sending a command down from the surface.
std_msgs/Header header

Trajectory   desired_trajectory    # The orientation and translation we'd like to be at in this moment
IoRequest[] io_requests           # Any additional io requests to take place here
