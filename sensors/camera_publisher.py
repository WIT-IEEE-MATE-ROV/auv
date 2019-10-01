#!/usr/bin/env python2
# The ROS Node for pulling images from USB webcam
"""
 This file is part of Enbarr.

    Enbarr is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Enbarr is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Enbarr.  If not, see <https://www.gnu.org/licenses/>.
"""
import time

import cv2
import numpy as np
# ROS specific nodes
import rospy
# Message type
from sensor_msgs.msg import CompressedImage

if __name__ == '__main__':
    # add here the node name. In ROS, nodes are unique named.
    rospy.init_node('camera_publisher', anonymous=True, log_level=rospy.DEBUG)

    # publish messages to a topic using rospy.Publisher class
    pub = rospy.Publisher('/camera/image', CompressedImage, queue_size=5)

# set a publishing rate. Below is a publishing rate of 10 times/second
rate = rospy.Rate(30)

while not rospy.is_shutdown():
    # usb camera unix path
    resource_name = "/dev/video0"
    rospy.logdebug("Trying to open resource: " + resource_name)
    capture = cv2.VideoCapture(0)
    capture.set(3, 320)
    capture.set(4, 240)
    if not capture.isOpened():
        rospy.logdebug("Error opening resource: " + resource_name)
        rospy.logdebug("Maybe opencv VideoCapture can't open it")
        exit(0)

    print "Correctly opened resource, starting to show feed."
    while True:
        # Set custom sized image to capture
        ok, img = capture.read()
        if not ok:
            continue
        ok, img = cv2.imencode('.jpg', img, [cv2.IMWRITE_JPEG_QUALITY, 80])
        if not ok:
            continue
        jpg = img.tostring()
        np_arr = np.fromstring(jpg, np.uint8)
        # Deal with different versions of opencv having different
        # namespaces for the same thing
        if int(cv2.__version__.split('.')[0]) >= 3:
            image_np = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)
        else:
            image_np = cv2.imdecode(np_arr, cv2.CV_LOAD_IMAGE_COLOR)

        msg = CompressedImage()
        msg.header.stamp = rospy.Time.now()
        msg.format = "jpeg"
        msg.data = np.array(cv2.imencode('.jpg', image_np)[1]).tostring()
        # Publish new image
        rospy.logdebug('\n\nFrame shape:\n {}'.format(image_np.shape))
        pub.publish(msg)
        rate.sleep()
