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

    static _AlphaBeta gyro_roll;
    static _AlphaBeta gyro_pitch;
    static _AlphaBeta gyro_yaw;
    static _AlphaBeta accel_x;
    static _AlphaBeta accel_y;
    static _AlphaBeta accel_z;

    public:
        static void filter(ninedof *input);
};

void AlphaBeta::filter(ninedof *input) {
    gyro_roll.filter(&input->gyro.roll);
    gyro_pitch.filter(&input->gyro.pitch);
    gyro_yaw.filter(&input->gyro.yaw);
    accel_x.filter(&input->accel.x);
    accel_y.filter(&input->accel.y);
    accel_z.filter(&input->accel.z);
}

class _AlphaBeta {

    float delta_t = 0.5;
    float alpha = 0.85;
    float beta = 0.005;

    float xk_1 = 0.0;
    float vk_1 = 0.0;
    float xk;
    float vk;
    float rk;

    public:
        void filter(float *input);
};

void _AlphaBeta::filter(float *input) {
    xk = xk_1 + (vk_1 * delta_t);
    vk = vk_1;

    rk = *input - xk;

    xk += alpha * rk;
    vk += (beta * rk) / delta_t;

    xk_1 = xk;
    vk_1 = vk;

    *input = xk_1;
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
    ninedof * msg = new ninedof;
    msg->gyro.roll  = inMsg->orientation.roll;
    msg->gyro.pitch = inMsg->orientation.pitch;
    msg->gyro.yaw   = inMsg->orientation.yaw;
    msg->accel.x = inMsg->translation.x;
    msg->accel.y = inMsg->translation.y;
    msg->accel.z = inMsg->translation.z;

    AlphaBeta::filter(msg);

    auv::ninedof outMsg;

    outMsg.orientation.roll     = msg->gyro.roll;
    outMsg.orientation.pitch    = msg->gyro.pitch;
    outMsg.orientation.yaw      = msg->gyro.yaw;
    outMsg.translation.x        = msg->accel.x;
    outMsg.translation.y        = msg->accel.y;
    outMsg.translation.z        = msg->accel.z;

    ninedof_filtered_pub.publish(outMsg);

    delete msg;
}
