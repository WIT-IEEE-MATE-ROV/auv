# Enbarr AUV 2.0
Code for the Autonomous Underwater Vehicle produced as a part of the Enbarr project.

## What is this?
This is code to control an underwater AUV from a surface station. It's designed to be platform-ambivalent (meaning that you configure it to your needs and hardware, and go from there). As of version 2.0, the plugin/core structure is no longer implied and is instead the forced standard. Doing it this way makes it reasonably trivial to build up a repository of different sensors and motor control systems for future teams to build onto.

## File structure
This repository uses the de-facto standard found in ROS workspaces.

- `config` contains configuration files. See the README in that directory for more information.
- `core` contains the core Enbarr code. See the 'core and plugins' section for more.
- `docs` contains more documentation.
- `launch` contains launch files. The files here allow you to run existing configurations in simulation, real life, etc.
- `msg` contains ROS message templates. These are used to pass information from one process to another.
- `plugins` contains Enbarr plugins. See the 'core and plugins' section for more.
- `scripts` contains helper scripts.

## Core and Plugins
The code run here falls into two categories: core code, and plugin code. Some things will be universal: we're going to want to be able to communicate with a surface station, we're going to want to get sensor data, we're going to want to put that through a control loop, etc. Thanks to the way the architecture is set up with our universal messages, this is common core code. 

What makes different ROV's and AUV's different from build to build is in the hardware itself, and this is where plugins come in. For example, the core code doesn't care about how the thrusters end up at 80% power, it just needs them there. It's up to the appropriate plugin to deal with how to make the hardware do the right thing, and it's up to you (the user/engineer) to make sure that the right plugin is being used on the right hardware. By creating new plugins for new hardware, we can easily swap in new thrusters/sensors with minimal effort, allowing for greater adaptability and focus on improving core code or challenge-specific code.

## Setup

To use this code, you will need the standard ROS Kinetic utilities (catkin, etc) described by the ROS tutorials. Create your catkin workspace wherever you wish, and then run 'catkin_make' as described [here](https://wiki.ros.org/catkin/Tutorials/create_a_workspace). `cd` on over to the `src` directory (which you should have made within your catkin workspace), and `git clone` this repository. You will now be able to run `catkin_make` from the root of the catkin workspace to make the package.
The goal of this project is to create a low-cost, entry level AUV (both software platform and hardware) capable of being adapted for a wide array of research or hobbyist applications. It's not as capable as some of the larger or more expensive counterparts, but it's low-cost, can be replicated at pretty much any university (or even by an individual, depending on what tools you have around), and it's still capable of collecting data.


It's designed to be pretty easy to use and adapt for your needs. If something is difficult to use, adapt, or understand, that's because we've failed to properly document it: please let us know how we can take care of it by creating an issue for us to review. If you've made an interesting addition we might be interested in, we're open to pull requests! Check out contributing.md.

We've chosen to use Python for our core codebase. However, keep in mind that thanks to ROS, you can use any language ROS supports to interact with our system (C++, Python, Java, Lisp...). 

The hardware is Free and Open Source too, and developed using only Free and Open Source tools. The pressure tolerant design allows for impressive depths at low cost. Check out the 'hardware' repo for more, but you don't actually need it: we're running ROS, so you can run your code in simulation before pushing it on to an actual machine.

To get that to happen, you'll need to follow our [setup steps](), and then check out the [default usage]() steps. Once you've got that, you can start to play with our [api documentation]() to learn how to read values from sensors or instruct the machine to send PWM values, follow a trajectory, and more.

