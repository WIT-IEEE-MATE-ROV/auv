This directory contains launch files. To run a launch file, run `roslaunch auv <launch_file.launch>`. For example,
to run the entire system in a simulation, run `roslaunch auv simulate.launch`. 

- camera_nodes runs the camera publisher and subscriber nodes.
- core runs the core enbarr stuff. It's not useful on its own, but is useful when called from other launch files.
- enbarr2019 is the launch file for the original enbarr AUV.
- ieee2020 is the launch file for the 2020 WIT IEEE Underwater ROV.
- simulate is the launch file for running a simple simulated example.