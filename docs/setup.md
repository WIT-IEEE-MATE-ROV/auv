# Dependencies
First off, you'll need ROS. This was developed using Kinetic, but Melodic should work just fine. The ROS wiki has the best documentation on this, so just go [here]() to see what they need you to do to install ROS and set up a workspace. 

You should now have a workspace called `catkin_ws` or `enbarr` or whatever. The `src` folder is where we'll be dealing with our source directories, so `cd` on over to there and `git clone` this directory. If this is your development machine, you'll also want to clone the surface-station repo. If this is your devoted surface machine (you don't need one, but sometimes it's nice), just clone the surface station and get on out of here.

With that cloned, `cd` into there and you should see a `requirements.txt` file. We're using `virtualenv` to manage our packages, but unfortunately ROS only handles Python2 while our hardware only has libraries in Python3. So this part gets a bit messy... `pip -r requirements.txt` and `pip3 -r requirements.txt` should get you sorted out. If all that went well, your python dependencies are all handled.

# Installing

From the root of your workspace, run a `catkin_make install`. You should now have all the messages ready to go. Recall that messages are what allows ROS nodes to talkt o each other, so this part is pretty non-optional. Make sure you correct any error you get here, or re-run this step if you ever modify a message.

# Verifying Install
`roslaunch auv enbarr.launch` should 'just work' out of the box, assuming you have those python dependencies and everything else installed. You may want to run `roslaunch auv enbarr-sim.launch` if you're doing this on your development machine. Future versions will support a launchfile of gazebo.

