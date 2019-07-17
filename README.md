# auv
Code for the Autonomous Underwater Vehicle.

# Usage
To use this code, you will need the standard ROS Kinetic utilities (catkin, etc) described by the ROS tutorials. Create your catkin workspace wherever you wish, and then run 'catkin_make' as described [here](https://wiki.ros.org/catkin/Tutorials/create_a_workspace). `cd` on over to the `src` directory (which you should have made within your catkin workspace), and `git clone` this repository. You will now be able to run `catkin_make` from the root of the catkin workspace to make the package.

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

# Other Dependencies
Once the ROS requrirements have been met, you'll just need to install the python requirements. To help with this process, we have pipenv to help out. With pipenv installed, you can simply run 

```bash
pipenv install 
```

And you should now have all of the dependencies installed. If that fails for some reason, however, those dependencies are as follows:

- adafruit-circuitpython-busdevice
- adafruit-circuitpython-fxas21002c
- adafruit-circuitpython-fxos8700
- adafruit-circuitpython-motor
- adafruit-circuitpython-pca9685
- adafruit-circuitpython-register
- adafruit-circuitpython-servokit


