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

#include <iostream>

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

ros::Publisher ninedof_filtered_pub;


// ===============================================
//  Alpha-Beta filter class
// ===============================================

class _AlphaBeta {
    private: 
        float delta_t = 0.25;
        float alpha = 0.5;
        float beta = 0.01;

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

class AlphaBeta {
    private:
        static _AlphaBeta gyro_roll;
        static _AlphaBeta gyro_pitch;
        static _AlphaBeta gyro_yaw;
        static _AlphaBeta accel_x;
        static _AlphaBeta accel_y;
        static _AlphaBeta accel_z;

    public:
        static void filter(ninedof *input);
};

_AlphaBeta AlphaBeta::gyro_roll;
_AlphaBeta AlphaBeta::gyro_pitch;
_AlphaBeta AlphaBeta::gyro_yaw;
_AlphaBeta AlphaBeta::accel_x;
_AlphaBeta AlphaBeta::accel_y;
_AlphaBeta AlphaBeta::accel_z;

void AlphaBeta::filter(ninedof *input) {
    AlphaBeta::gyro_roll.filter(&input->gyro.roll);
    AlphaBeta::gyro_pitch.filter(&input->gyro.pitch);
    AlphaBeta::gyro_yaw.filter(&input->gyro.yaw);
    AlphaBeta::accel_x.filter(&input->accel.x);
    AlphaBeta::accel_y.filter(&input->accel.y);
    AlphaBeta::accel_z.filter(&input->accel.z);
}

// ===============================================


int main(int argc, char **argv) {

    if( ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME, ros::console::levels::Debug) ) {
        ros::console::notifyLoggerLevelsChanged();
    }

    ROS_DEBUG("Alpha-Beta Filter started");

    // Initialize ROS publisher
    ros::init(argc, argv, "ninedof_filter_alpha_beta");
    ros::NodeHandle n;
    ros::Subscriber ninedof_current_sub = n.subscribe("ninedof_values", 1000, &ninedofCallback);
    
    ninedof_filtered_pub = n.advertise<auv::ninedof>("ninedof_filtered", 3);

    ros::spin();

    return 0;
}

void ninedofCallback(const auv::ninedof::ConstPtr& inMsg) {

    ROS_DEBUG("A-B Input: %f\t%f\t%f\t%f\t%f\t%f\t",
        inMsg->orientation.roll,
        inMsg->orientation.pitch,
        inMsg->orientation.yaw,
        inMsg->translation.x,
        inMsg->translation.y,
        inMsg->translation.z
    );

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

    ROS_DEBUG("A-B Output: %f\t%f\t%f\t%f\t%f\t%f\t",
        outMsg.orientation.roll,
        outMsg.orientation.pitch,
        outMsg.orientation.yaw,
        outMsg.translation.x,
        outMsg.translation.y,
        outMsg.translation.z
    );

    ninedof_filtered_pub.publish(outMsg);

    delete msg;
}
