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
#include "ros/console.h"
#include "auv/ninedof.h"

#include <thread>

ros::Publisher ninedof_filtered_pub;

typedef struct {
    float roll;
    float pitch;
    float yaw;
} orientation;
 
typedef struct {
    float x;
    float y;
    float z;
} translation;

void ninedofCallback(const auv::ninedof::ConstPtr& inMsg);
void kalman_filter(translation *input);
void kalman_filter(orientation *input);

void kalman_thread(void *ptr);

int main(int argc, char **argv) {
    // Initialize ROS publisher
    ros::init(argc, argv, "ninedof_filter_kalman");
    ros::NodeHandle n;
    ros::Subscriber ninedof_current_sub = n.subscribe("ninedof_values", 1000, &ninedofCallback);
    
    ninedof_filtered_pub = n.advertise<auv::ninedof>("ninedof_filtered", 3);

    ros::spin();

    return 0;
}

void ninedofCallback(const auv::ninedof::ConstPtr& inMsg) {
    auv::ninedof outMsg;

    orientation * gyro = new orientation;
    gyro->roll  = inMsg->orientation.roll;
    gyro->pitch = inMsg->orientation.pitch;
    gyro->yaw   = inMsg->orientation.yaw;
    
    translation * accel = new translation;
    accel->x = inMsg->translation.x;
    accel->y = inMsg->translation.y;
    accel->z = inMsg->translation.z;

    kalman_filter(gyro);
    kalman_filter(accel);

    outMsg.orientation.roll     = gyro->roll;
    outMsg.orientation.pitch    = gyro->pitch;
    outMsg.orientation.yaw      = gyro->yaw;
    outMsg.translation.x        = accel->x;
    outMsg.translation.y        = accel->y;
    outMsg.translation.z        = accel->z;

    ninedof_filtered_pub.publish(outMsg);

    delete gyro;
    delete accel;
}

void kalman_filter(orientation *input) {
    std::vector<std::thread> threads;
    
    float * fields[] = {&input->roll, &input->pitch, &input->yaw};

    for (float * field : fields) {
        threads.push_back(std::thread(&kalman_thread, field));
    }

    for (std::thread& thread : threads) {
        thread.join();
    }
}

void kalman_filter(translation *input) {
    std::vector<std::thread> threads;

    float * fields[] = {&input->x, &input->y, &input->z};

    for (float * field : fields) {
        threads.push_back(std::thread(&kalman_thread, field));
    }

    for (std::thread& thread : threads) {
        thread.join();
    }
}

void kalman_thread(void *ptr) {

}