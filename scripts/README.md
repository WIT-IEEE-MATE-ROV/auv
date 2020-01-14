This folder contains a collection of scripts. 

These scripts are meant to be useful for things like debug: they can send random or specific messages, for example.
This makes them effective for testing and debug, since on-demand you can create a new message that is exactly what
you're expecting. 

That said, keep in mind that these have been made with debug in mind. They really shouldn't be used for production
type tasks (i.e., keep them for debug and not running full time on the final product).

Here's the current listing of scripts and their applications:

- cli_controller.py: Allows for simple interactive sending of trajectories from the command line.
- echo_msg.py: Echos a message back to you. Handy for launchfiles when you want to warn the user about something.
- random_trajectory_requests.py: Generates and sends random trajectory requests. Useful only for simulation to show if messages are getting from one point to another.
- read_nxpval.py: Reads values from the NXP sensor and writes them to the ./output/nxpval.csv file as a CSV.
- set_pcaval_script.py: Sets PCA values according to a command line parameter.