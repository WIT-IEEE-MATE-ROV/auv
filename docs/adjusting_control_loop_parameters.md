# Overview
Adjusting control loop parameters can be time consuming, particularly if they are hard-coded, requiring the program to be shut down and re-launched every trial. Given that each machine and needs will be different, we've instead opted to make the tuning process as streamlined as possible by making them changeable on-the-fly.

# On startup
If you have values you like and would like to keep using, you can hard-code them into your launch file by adjusting the command line parameters. The parameters at the moment are tuned to a 'P' loop (no adjustment occurs, the same values piped in are the same values pipe out). This is also the default value if no parameters are provided.
