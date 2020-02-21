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

#include <cstdlib>

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
//  Matrix class
// ===============================================

template <typename T>
class Matrix : public std::vector<T> {

};

// ===============================================
//  Kalman-Bucy filter class
// ===============================================

class _KalmanBucy {
    private: 
        static const unsigned short int state_dim = 2; // Dimension of state
        Matrix<Matrix<int>> id_operator = eye(state_dim); // Identity operator
        float gamma = 1; // Observational noise variance is gamma^2*id_operator
        float sigma = 1; // Dynamics noise variance is sigma^2*id_operator
        Matrix<Matrix<int>> c_0 = eye(2); // Prior initial condition variance
        Matrix<int> m_0 = {{0, 0}}; // Prior initial condition mean
        int seed = 10; // Random number seed
        std::vector<std::vector<int>> A = {{{-1, 1}, {-1, -1}}}; // Dynamics determined by A
        float tau = 0.01;


        Matrix<Matrix<int>> eye(unsigned int size);

    public:
        _KalmanBucy();
        void filter(float *input);
};

_KalmanBucy::_KalmanBucy() {
    std::srand(seed);
}

void _KalmanBucy::filter(float *input) {
    
}

class KalmanBucy {
    private:
        static _KalmanBucy gyro_roll;
        static _KalmanBucy gyro_pitch;
        static _KalmanBucy gyro_yaw;
        static _KalmanBucy accel_x;
        static _KalmanBucy accel_y;
        static _KalmanBucy accel_z;

    public:
        static void filter(ninedof *input);
};

_KalmanBucy KalmanBucy::gyro_roll;
_KalmanBucy KalmanBucy::gyro_pitch;
_KalmanBucy KalmanBucy::gyro_yaw;
_KalmanBucy KalmanBucy::accel_x;
_KalmanBucy KalmanBucy::accel_y;
_KalmanBucy KalmanBucy::accel_z;

void KalmanBucy::filter(ninedof *input) {
    KalmanBucy::gyro_roll.filter(&input->gyro.roll);
    KalmanBucy::gyro_pitch.filter(&input->gyro.pitch);
    KalmanBucy::gyro_yaw.filter(&input->gyro.yaw);
    KalmanBucy::accel_x.filter(&input->accel.x);
    KalmanBucy::accel_y.filter(&input->accel.y);
    KalmanBucy::accel_z.filter(&input->accel.z);
}

// ===============================================


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

    KalmanBucy::filter(msg);

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
