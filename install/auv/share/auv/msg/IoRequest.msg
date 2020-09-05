# A super general IO request format. Devices can implement responses to this by subscribing to topics
# that publish this message, and then if the device matches the 'executor' string, executing it.
# The specifics of implementing will vary from device to device, which is why this is kept 
# vague and general.

std_msgs/Header header

string  executor # Who we want to execute this request
float32 number # A float value for the request to use, if they want
bool    boolean  # A boolean value for the request to use, if they want
int32   int32    # You get the picture by now
string  string   # fill-in-the-blank if you really need to
