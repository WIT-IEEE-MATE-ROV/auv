#!/usr/bin/env python2
"""OpenCV feature detectors with ros CompressedImage Topics in python.

This example subscribes to a ros topic containing sensor_msgs
CompressedImage. It converts the CompressedImage into a numpy.ndarray,
then detects and marks features in that image. It finally displays
and publishes the new image - again as CompressedImage topic.
"""
# Python libs
import sys

# OpenCV
import cv2
# numpy and scipy
# Ros libraries
import rospy
# Networking
# We do not use cv_bridge it does not support CompressedImage in python
# from cv_bridge import CvBridge, CvBridgeError
# Ros Messages
from sensor_msgs.msg import CompressedImage
from twisted.internet import reactor

VERBOSE = True

# class ImageWebsocketNode:
#
#     def __init__(self):
#         '''Initialize ros publisher, ros subscriber'''
#         # subscribed Topic
#         self.subscriber = rospy.Subscriber("/camera/image",
#                                            CompressedImage, self.callback, queue_size=20)
#
#         rospy.logdebug("subscribed to /camera/image")
#         # Inherit websocketServerProtocol
#
#     def callback(self, ros_data):
#         '''Callback function of subscribed topic.
#         Here images get converted and features detected'''
#
#         rospy.logdebug('received image of type: "%s"' % ros_data.format)
#
#         # #### direct conversion to CV2 ####
#         # np_arr = np.fromstring(ros_data.data, np.uint8)
#         # image_np = cv2.imdecode(np_arr, cv2.CV_LOAD_IMAGE_COLOR)
#         # # image_np = cv2.imdecode(np_arr, cv2.IMREAD_COLOR) # OpenCV >= 3.0:
#         #
#         # #### Feature detectors using CV2 ####
#         # # "","Grid","Pyramid" +
#         # # "FAST","GFTT","HARRIS","MSER","ORB","SIFT","STAR","SURF"
#         # method = "GridFAST"
#         # feat_det = cv2.FeatureDetector_create(method)
#         # time1 = time.time()
#         #
#         # # convert np image to grayscale
#         # featPoints = feat_det.detect(
#         #     cv2.cvtColor(image_np, cv2.COLOR_BGR2GRAY))
#         # time2 = time.time()
#         # if VERBOSE:
#         #     print '%s detector found: %s points in: %s sec.' % (method,
#         #                                                         len(featPoints), time2 - time1)
#         # for featpoint in featPoints:
#         #     x, y = featpoint.pt
#         #     cv2.circle(image_np, (int(x), int(y)), 3, (0, 0, 255), -1)
#         #
#         # cv2.imshow('cv_img', image_np)
#         # cv2.waitKey(2)
#         global factory
#         factory._proto.sendMessage(ros_data.data, isBinary=False)


from autobahn.twisted.websocket import WebSocketClientFactory


class CameraSubscriberClientProtocol:

    # def __init__(self):
    #     self.subscriber = rospy.Subscriber("/camera/image",
    #                                        CompressedImage, self.callback, queue_size=20)

    def onOpen(self):
        self.factory._proto = self
        self.sendMessage(u"Joystick Executor online and connected.".encode('utf8'))
        self.sendMessage(u"Hello, from camera subscriber!".encode('utf8'))

    def callback(self, ros_data):
        '''Callback function of subscribed topic.
        Here images get converted and features detected'''

        rospy.logdebug('received image of type: "%s"' % ros_data.format)

        # #### direct conversion to CV2 ####
        # np_arr = np.fromstring(ros_data.data, np.uint8)
        # image_np = cv2.imdecode(np_arr, cv2.CV_LOAD_IMAGE_COLOR)
        # # image_np = cv2.imdecode(np_arr, cv2.IMREAD_COLOR) # OpenCV >= 3.0:
        #
        # #### Feature detectors using CV2 ####
        # # "","Grid","Pyramid" +
        # # "FAST","GFTT","HARRIS","MSER","ORB","SIFT","STAR","SURF"
        # method = "GridFAST"
        # feat_det = cv2.FeatureDetector_create(method)
        # time1 = time.time()
        #
        # # convert np image to grayscale
        # featPoints = feat_det.detect(
        #     cv2.cvtColor(image_np, cv2.COLOR_BGR2GRAY))
        # time2 = time.time()
        # if VERBOSE:
        #     print '%s detector found: %s points in: %s sec.' % (method,
        #                                                         len(featPoints), time2 - time1)
        # for featpoint in featPoints:
        #     x, y = featpoint.pt
        #     cv2.circle(image_np, (int(x), int(y)), 3, (0, 0, 255), -1)
        #
        # cv2.imshow('cv_img', image_np)
        # cv2.waitKey(2)
        self.sendMessage(ros_data.data, isBinary=False)

    def onConnect(self, response):
        pass

    def onMessage(self, payload, isBinary):
        if isBinary:
            print "Binary message received: %d bytes" % len(payload)
        else:
            print "Text message received: %d" % payload.decode('utf8')

    def onClose(self, wasClean, code, reason):
        print "WebSocket connection closed: %s" % reason
        self.factory._proto = None


class MyClientFactory(WebSocketClientFactory):
    """
    Our factory for WebSocket client connections.
    """
    protocol = CameraSubscriberClientProtocol()

    def __init__(self, url):
        WebSocketClientFactory.__init__(self, url)


def main():
    '''Initializes and cleanup ros node'''
    rospy.init_node('Image websocket broadcaster', anonymous=True)
    rospy.subscriber = rospy.Subscriber("/camera/image",
                                       CompressedImage, callback, queue_size=20)

    # ws_i = ImageWebsocketNode()
    factory = MyClientFactory(u"ws://127.0.0.1:9001")
    reactor.connectTCP("127.0.0.1", 9001, factory)
    reactor.run()

    try:
        rospy.spin()
    except KeyboardInterrupt:
        rospy.logdebug("Shutting down ROS Image feature detector module")
    cv2.destroyAllWindows()


if __name__ == '__main__':
    main(sys.argv)
