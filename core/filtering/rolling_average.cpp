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

void rolling_avg_filter(translation *input);
void rolling_avg_filter(orientation *input);

ros::Publisher ninedof_filtered_pub;

std::vector<orientation> * gyro_history = new std::vector<orientation>;
std::vector<translation> * accel_history = new std::vector<translation>;

const int history_max_length = 10;

int main(int argc, char **argv) {
    // Initialize ROS publisher
    ros::init(argc, argv, "ninedof_filter_rolling_avg");
    ros::NodeHandle n;
    ros::Subscriber ninedof_current_sub = n.subscribe("ninedof_values", 1000, &ninedofCallback);
    
    ninedof_filtered_pub = n.advertise<auv::ninedof>("ninedof_filtered", 3);

    ros::spin();

    delete gyro_history;
    delete accel_history;

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

    rolling_avg_filter(gyro);
    rolling_avg_filter(accel);

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

void rolling_avg_filter(orientation *input) {
    gyro_history->push_back(*input);

    if (gyro_history->size() > history_max_length) {
        gyro_history->erase(gyro_history->begin());
    }

    for (orientation point : *gyro_history) {
        input->roll    += point.roll;
        input->pitch   += point.pitch;
        input->yaw     += point.yaw;
    }

    input->roll    /= accel_history->size();
    input->pitch   /= accel_history->size();
    input->yaw     /= accel_history->size();
}

void rolling_avg_filter(translation *input) {
    accel_history->push_back(*input);

    if (accel_history->size() > history_max_length) {
        accel_history->erase(accel_history->begin());
    }

    for (translation point : *accel_history) {
        input->x += point.x;
        input->y += point.y;
        input->z += point.z;
    }

    input->x /= accel_history->size();
    input->y /= accel_history->size();
    input->z /= accel_history->size();

    accel_history->push_back(*input);
}
