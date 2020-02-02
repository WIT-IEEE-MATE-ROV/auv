/*
 * Copyright (C) 2008, Morgan Quigley and Willow Garage, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the names of Stanford University or Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "auv/ninedof.h"

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string>


int main(int argc, char **argv)
{

    // Create lock file to show that node is running
    std::ifstream ifile;
    ifile.open("/tmp/run.lck");
    if(!ifile) {
        std::ofstream output("/tmp/run.lck");
    }

    int pfd[2];
    int pid;

    if (pipe(pfd) == -1) {
        perror("pipe failed");
        exit(-1);
    }
    if ((pid = fork()) < 0) {
        perror("fork failed");
        exit(-2);
    }

    if (pid == 0) {  // child process
        close(pfd[0]);
        dup2(pfd[1], 1);
        close(pfd[1]);

        execlp("python3", "python3", "fxas_fxos_sender.py", (char *) 0);
    }
    else {  // parent process
        close(pfd[1]);
        dup2(pfd[0], 0);
        close(pfd[0]);
    }

    /**
      * The ros::init() function needs to see argc and argv so that it can perform
      * any ROS arguments and name remapping that were provided at the command line.
      * For programmatic remappings you can use a different version of init() which takes
      * remappings directly, but for most command-line programs, passing argc and argv is
      * the easiest way to do it.  The third argument to init() is the name of the node.
      *
      * You must call one of the versions of ros::init() before using any other
      * part of the ROS system.
      */
    ros::init(argc, argv, "talker");

    /**
      * NodeHandle is the main access point to communications with the ROS system.
      * The first NodeHandle constructed will fully initialize this node, and the last
      * NodeHandle destructed will close down the node.
      */
    ros::NodeHandle n;

    /**
      * The advertise() function is how you tell ROS that you want to
      * publish on a given topic name. This invokes a call to the ROS
      * master node, which keeps a registry of who is publishing and who
      * is subscribing. After this advertise() call is made, the master
      * node will notify anyone who is trying to subscribe to this topic name,
      * and they will in turn negotiate a peer-to-peer connection with this
      * node.  advertise() returns a Publisher object which allows you to
      * publish messages on that topic through a call to publish().  Once
      * all copies of the returned Publisher object are destroyed, the topic
      * will be automatically unadvertised.
      *
      * The second parameter to advertise() is the size of the message queue
      * used for publishing messages.  If messages are published more quickly
      * than we can send them, the number here specifies how many messages to
      * buffer up before throwing some away.
      */
    ros::Publisher chatter_pub = n.advertise<auv::ninedof>("chatter", 1000);

    ros::Rate loop_rate(10);

    // Setup message structure
    // TODO: Set these values according to a user-specified transform that takes rotation of the sensor into account
    const int _X = 0;
    const int _Y = 1;
    const int _Z = 2;
    const int _Roll = 0;
    const int _Pitch = 1;
    const int _Yaw = 2;

    struct translation {
            float x;
            float y;
            float z;
        }
    struct orientation {
        float roll;
        float pitch;
        float yaw;
    }
    struct ninedof {
        struct translation fxas;
        struct orientation fxos;
    }

    /**
      * A count of how many messages we have sent. This is used to create
      * a unique string for each message.
      */
    int count = 0;

    // Setup input
    char buffer[128];
    int rr;

    while (ros::ok()) {

        // Get data from python script
        rr = read(pfd[0], buffer, 100);
        // buffer[rr] = '\0';
        std::string data(buffer);

        auv::ninedof msg;
        

        // ROS_INFO("%s", msg.data.c_str());  // TODO: setup console logging

        /**
        * The publish() function is how you send messages. The parameter
        * is the message object. The type of this object must agree with the type
        * given as a template parameter to the advertise<>() call, as was done
        * in the constructor above.
        */
        chatter_pub.publish(msg);

        ros::spinOnce();

        // loop_rate.sleep();  // loop rate will be limited by the python script
        ++count;
    }
    
    // Remove lockfile and wait to avoid crashing the python script
    std::remove("/tmp/run.lck");
    usleep(1000000);

    return 0;
}
