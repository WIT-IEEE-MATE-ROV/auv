# Overview
You may find yourself in a situtation where you have an area that needs to be scanned over. You could do the trajectories yourself, but to save you some time and effort Enbarr has a built-in path planner. By specifiying a start and end point and some other parameters, the path planner will plan and execute the appropriate trajectory.

Alternatively, you can specify a set of points, where the AUV will attempt to go from point to point in order.

# Parameters
## Trajectory by scan area
**Start Position**: The start position, relative to the current position. 
**End position**: The end position, relative to the start position. 
**Speed**: The speed at which the path will be followed, as a percentage of the maximum speed.
**Distance**: The distance between each line when planning a search area.

## Trajectory by points
**Point**: A point to move to, relative to the current position. The next point will not be relative to the AUV's initial position: it will be relative to the position it is at when it begins to move to the point.
**Speed**: The speed at which the current point will be traveled to, as a percentageage of the maximum speed. 

# Usage
For you to interact with a ROS node, you'll need to make your own node in whatever language you like. The path_planner node listens on two topics: `/scanarea_requests` and `scanpoints_requests`. Therefore, to send an instruction, simply write a publisher that sends your desired content to either of those topics (but not both). An example for each is provided.

## Scan area

## Points
