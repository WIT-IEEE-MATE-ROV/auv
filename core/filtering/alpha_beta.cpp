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

typedef struct {
    orientation gyro;
    translation accel;
} ninedof;

void ninedofCallback(const auv::ninedof::ConstPtr& inMsg);

std::vector<orientation> * gyro_history = new std::vector<orientation>;
std::vector<translation> * accel_history = new std::vector<translation>;

ros::Publisher ninedof_filtered_pub;

const int history_max_length = 10;

// ===============================================
//  Alpha-Beta filter class
// ===============================================

class AlphaBeta {
    static float estimate(float input);
    static ninedof estimate_ninedof(ninedof input);

    public:
        static void filter(orientation *input);
        static void filter(translation *input);
};

float AlphaBeta::estimate(float input) {

}

ninedof AlphaBeta::estimate_ninedof(ninedof input) {

}

void AlphaBeta::filter(orientation *input) {

}

void AlphaBeta::filter(translation *input) {
    
}

// ===============================================


int main(int argc, char **argv) {
    // Initialize ROS publisher
    ros::init(argc, argv, "ninedof_filter_alpha_beta");
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

    AlphaBeta::filter(gyro);
    AlphaBeta::filter(accel);

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
