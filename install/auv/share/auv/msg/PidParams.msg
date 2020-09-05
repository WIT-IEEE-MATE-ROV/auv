# Allow for easy tuning of the control loop by passing a message
# instead of needing to shut everything down each time.
std_msgs/Header header

float32 p
float32 i
float32 d
