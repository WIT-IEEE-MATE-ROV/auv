#!/usr/bin/env python3
"""OpenCV feature detectors with ros CompressedImage Topics in python.

This example subscribes to a ros topic containing sensor_msgs
CompressedImage. It converts the CompressedImage into a numpy.ndarray,
then detects and marks features in that image. It finally displays
and publishes the new image - again as CompressedImage topic.
"""
# Python libs

# OpenCV

# numpy and scipy
# Ros libraries
import base64

import rospy
from autobahn.twisted.websocket import WebSocketServerProtocol, \
    WebSocketServerFactory, listenWS
# Networking
# We do not use cv_bridge it does not support CompressedImage in python
# from cv_bridge import CvBridge, CvBridgeError
# Ros Messages
from sensor_msgs.msg import CompressedImage
from twisted.internet import reactor


class BroadcastServerProtocol(WebSocketServerProtocol):

    def onOpen(self):
        self.factory.register(self)

    def onMessage(self, payload, isBinary):
        if not isBinary:
            msg = "{} from {}".format(payload.decode('utf8'), "camera_sub")
            self.factory.broadcast(msg)

    def connectionLost(self, reason):
        WebSocketServerProtocol.connectionLost(self, reason)
        self.factory.unregister(self)


class BroadcastServerFactory(WebSocketServerFactory):
    """
    Simple broadcast server broadcasting any message it receives to all
    currently connected clients.
    """

    def __init__(self, url):
        WebSocketServerFactory.__init__(self, url)
        self.clients = []
        self.tickcount = 0

    def tick(self):
        self.tickcount += 1
        self.broadcast("tick %d from server" % self.tickcount)
        reactor.callLater(1, self.tick)

    def register(self, client):
        if client not in self.clients:
            print("registered client {}".format(client.peer))
            self.clients.append(client)

    def unregister(self, client):
        if client in self.clients:
            print("unregistered client {}".format(client.peer))
            self.clients.remove(client)

    def broadcast(self, msg):
        print("broadcasting message '{}' ..".format(msg))
        for c in self.clients:
            c.sendMessage(msg)
            print("message sent to {}".format(c.peer))


def image_received_callback(data, args):
    rospy.loginfo("In subscriber callback ")
    factory = args[0]
    b64string = base64.b64encode(data.data)
    rospy.loginfo("Encoded size of the sent image: {0} bytes".format(len(encoded_string)))
    factory.broadcast(b64string)


def callback(data, args):
    rospy.loginfo("cam sub Callback!")
    rospy.loginfo(str(args[0]))


def listener(_factory=None):
    rospy.loginfo("Started camera node ws server")
    ServerFactory = BroadcastServerFactory
    factory = ServerFactory(u"ws://127.0.0.1:9000")
    factory.protocol = BroadcastServerProtocol

    rospy.init_node('camera_subscriber', anonymous=True)
    rospy.loginfo("Started camera subscriber node")
    # callback_lambda = lambda x: image_received_callback(x, _factory)

    rospy.Subscriber(name="/camera/image", data_class=CompressedImage, callback=image_received_callback,
                     callback_args=(factory,))
    listenWS(factory)
    reactor.run()
    rospy.spin()


if __name__ == '__main__':
    listener()
