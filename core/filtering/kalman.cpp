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

ros::Publisher ninedof_filtered_pub;
void ninedofCallback(const auv::ninedof::ConstPtr& inMsg);

int main(int argc, char **argv) {
	// Initialize ROS publisher
	ros::init(argc, argv, "ninedof_filter_kalman");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("ninedof_values", 1000, ninedofCallback);

	ros::spin();

	return 0;
}

void ninedofCallback(const auv::ninedof::ConstPtr& inMsg) {
	auv::ninedof outMsg;

	outMsg.orientation.roll = 	inMsg->orientation.roll;
	outMsg.orientation.pitch = 	inMsg->orientation.pitch;
	outMsg.orientation.yaw =   	inMsg->orientation.yaw;
	outMsg.translation.x =     	inMsg->translation.x;
	outMsg.translation.y =     	inMsg->translation.y;
	outMsg.translation.z =     	inMsg->translation.z;

	ninedof_filtered_pub.publish(outMsg);
}