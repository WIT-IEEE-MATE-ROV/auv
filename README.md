# auv
Code for the Autonomous Underwater Vehicle.

# Usage
To use this code, you will need the standard ROS utilities (catkin, etc) described by the ROS tutorials. Create your catkin workspace wherever you wish, and then run 'catkin_make' as described (https://wiki.ros.org/catkin/Tutorials/create_a_workspace)[here]. `cd` on over to the `src` directory (which you should have made within your catkin workspace), and `git clone` this repository. You will now be able to run `catkin_make` from the root of the catkin workspace to make the package.

To clarify a bit, I have a folder on my computer with all the Enbarr stuff in it. There's a folder for electronics, hardware, and the software (which is the folder we care about). I cd'd to `software` and ran `mkdir src`, `cd src`, then `git clone`'d this directory. I was then able to `cd` on back to `software` to run `catkin_make`.

```
enbarr
├── electronics
├── hardware
└── software
    ├── build
    │   ├── atomic_configure
    │   ├── auv
    │   ├── catkin
    │   ├── catkin_generated
    │   ├── CMakeFiles
    │   ├── gtest
    │   └── test_results
    ├── devel
    │   ├── lib
    │   └── share
    └── src
        └── auv

```
