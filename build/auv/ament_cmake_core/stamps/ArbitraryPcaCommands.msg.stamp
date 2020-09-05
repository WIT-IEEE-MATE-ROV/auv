# Represents an arbitrary command that can be sent to the PCA, in addition to its standard usage of receiving
# thruster commands.
std_msgs/Header header

# Here's the operations you can use. Set one to true to indicate what you're trying to do here.
bool set_thruster
bool set_channel_pwm
bool set_channel_pwm_send_count
bool kill_thruster
bool unkill_thruster

# These get used in the operations set above.
string thruster
uint8 channel
uint16 count
float32 pwm