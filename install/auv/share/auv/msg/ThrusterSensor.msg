# Whatever sensors specific to the thrusters will get aggregated and spit out of this message.
std_msgs/Header header

string thruster  # The thruster this applies to.
uint16 rpm       # The rotations per minute, useful for control looping each thruster.
float32 current  # The value coming out of a current sensor, useful for detecting things being stuck.
bool estop       # If true, emergency stop this thruster.
