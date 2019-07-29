# Overview of our API 
Our system is broken down into a bunch of straightforward parts that handle individual tasks, and publishes them for the next part of the toolchain. The nice thing about this is that you, the user, can also listen to those messages to get up-to-date sensor information, for example. In addition, we've put together nodes you can hook into to send commands to the rest of the system.

# Nodes of Interest
## ninedof
The nine degree of freedom node publishes content stemming from the nine degree of freedom sensor.

TODO @Ryley

## trajectory_executor
If you'd like the AUV to move to an arbitrary location, the trajectory_executor can take in trajectories and will attempt to execute them.

See [executing arbitrary trajectories]() for more information and an example of how to interact with this node.
## path_planner
If you know the trajectory you'd like the AUV to follow, you can use the trajectory_executor to execute it. However, if you have an area you'd like to cover but don't want to generate all the trajectories to make that happen, the path_planner can help out. Provide it with a position to start and a position to end, and it'll follow that trajectory.

See [planning and executing trajectories]() for more information and an example on how to interact with this node.

## camera_publisher
The camera publisher attempts to find a camera at /dev/video0 and publish it into the ROS ecosystem. If you'd like to do some sort of vision processing on the ROV, you should subscribe to this publisher to get that feed. If you'd like to do some sort of processing on the surface, you'll probably be more interested in the camera_subscriber node, which sends these values up to the surface station.

See [interacting with camera footage]() for more information and an example on how to interact with this node. See the surface station docs for more information on processing live on the surface.

## thruster_sensor
The thruster sensor isn't actually used in the default hardware for Enbarr. However, in the interest of being expandable to a wide array of adaptations, it's here. The thruster sensor publishes RPM's to help each thruster maintain the appropriate speed, and can send an emergency stop signal if something may have been tangled in the thruster. At this point in time, it is empty and does nothing; if you are interested in using this node you should fill it out for your purposes.

## loop_tuner
Each machine will be slightly different based off of how it was constructed or what subsystems have been mounted, so there's no 'one size fits all' control loop. It defaults to not altering your output, but having a control loop is pretty desireable for stability and reliability purposes. Tuning a loop is not always trivial: it's a lot of trial and error to move closer and closer to the ideal parameters.

Adjusting PID parameters and restarting the ROS node every time to test the new parameters is time consuming. To help speed up this process, you can use /loop_tuner to send the PID parameters manually. See [adjusting control loop parameters]() for more details.

# Interacting with Nodes
Each node is a tiny bit different in the message that they rely on, but the overall formula is the same: create a publisher that publishes to the topic the node is listening to, or subscribe to the topic a node is publishing to. Examples for each can be found in the links above.

Note that the language you use doesn't need to be python even though that's what we use: any language supported by ROS will work here.

# Nodes you should really just leave alone
It's your robot, you're welcome to mess with whatever node you please. However, you'll probably get the best results if you stick to messing with the nodes we've called out above, and if you in particular don't try to insert yourself into the main pipeline of the trajectory instructions.
