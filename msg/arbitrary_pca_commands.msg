# Represents an arbitrary command that can be sent to the PCA, in addition to its standard usage of receiving
# thruster commands.
Header header

bool set_thruster
bool set_channel_pwm
bool set_channel_pwm_send_count

string thruster
uint8 channel
uint16 count
float32 pwm