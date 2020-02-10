/*
 *  This file is part of Enbarr.
 *
 *  Enbarr is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 * 
 *  Enbarr is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 * 
 *  You should have received a copy of the GNU General Public License
 *  along with Enbarr.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "auv/ninedof.h"

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <cstdlib>
#include <chrono>
#include <string>
#include <filesystem>


// Function prototypes
std::string getSrcPath();
bool checkSrc(const std::string& s);
std::vector<std::string> split(const std::string& s, char delimiter);

int main(int argc, char **argv) {

    // Create lock file to show that node is running
    std::ifstream ifile;
    ifile.open("/tmp/run.lck");
    if(!ifile) {
        std::ofstream output("/tmp/run.lck");
    }
    ifile.close();

    // Fork process to run sensor script
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

        std::string pythonPath = getSrcPath() + "/auv/plugins/sensors/fxas_fxos_sender.py";
        execlp("python3", "python3", pythonPath.c_str(), (char *) 0);
    }
    else {  // parent process
        close(pfd[1]);
        dup2(pfd[0], 0);
        close(pfd[0]);
    }

    // Initialize ROS publisher
    ros::init(argc, argv, "fxas_fxos_nineDof");
    ros::NodeHandle n;
    ros::Publisher nineDof_current_pub = n.advertise<auv::ninedof>("ninedof_values", 3);
    ros::Rate loop_rate(10); // Not used

    int count = 0;

    // Set up input
    char buffer[128];
    int rr;

    // Timing setup
    std::chrono::milliseconds time = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    );
    std::chrono::milliseconds new_time;
    int loop_time;
    int fast_loop = 0;
    int python_loop_delay = 1000;
    int loop_delay = 5;

    while (ros::ok()) {

        // Get data from python script
        rr = read(pfd[0], buffer, 100);
        if( rr > 0) {
            // buffer[rr] = '\0';
            std::string data = buffer;

            auv::ninedof msg;

            std::vector<std::string> dataVector = split(data, ';');
            msg.orientation.roll =  std::stof(dataVector[0]);
            msg.orientation.pitch = std::stof(dataVector[1]);
            msg.orientation.yaw =   std::stof(dataVector[2]);
            msg.translation.x =     std::stof(dataVector[3]);
            msg.translation.y =     std::stof(dataVector[4]);
            msg.translation.z =     std::stof(dataVector[5]);

            nineDof_current_pub.publish(msg);

            ros::spinOnce();

            // loop_rate.sleep();  // loop rate will be limited by the python script
            ++count;
        }

        // Calculate delay between loops
        new_time = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch()  // Absolute time
        );
        loop_time = (new_time - time).count();
        time = new_time;

        // Break if delay is significantly less than intended
        if(loop_time < (python_loop_delay / 2)) {
            fast_loop++;
            if(fast_loop >= 10) {
                break;
            }
        }
    }
    
    // Remove lockfile and wait to avoid crashing the python script
    std::remove("/tmp/run.lck");
    usleep(1000000);

    return 0;
}

std::string getSrcPath() {
    if (const char* ROS_PACKAGE_PATH = std::getenv("ROS_PACKAGE_PATH")) {
        std::string packagePath = ROS_PACKAGE_PATH;

        std::vector<std::string> paths = split(packagePath, ':');
        std::string srcPath = "";
        for (int i = 0; i < paths.size(); i++) {
            if (checkSrc(paths[i])) {
                srcPath = paths[i];
                return srcPath;
            }
        }
    }

    return "";
}

bool checkSrc(const std::string& s) {
    std::string src = "src";
    std::size_t found = s.find(src);

    return (found != std::string::npos);
}

std::vector<std::string> split(const std::string& s, char delimiter) {
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter)) {
      tokens.push_back(token);
   }
   return tokens;
}