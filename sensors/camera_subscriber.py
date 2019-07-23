#!/usr/bin/env python3
"""OpenCV feature detectors with ros CompressedImage Topics in python.

This example subscribes to a ros topic containing sensor_msgs
CompressedImage. It converts the CompressedImage into a numpy.ndarray,
then detects and marks features in that image. It finally displays
and publishes the new image - again as CompressedImage topic.
"""

import base64

import rospy
from autobahn.twisted.websocket import WebSocketServerProtocol, \
    WebSocketServerFactory, listenWS
from sensor_msgs.msg import CompressedImage
from twisted.internet import reactor


class BroadcastServerProtocol(WebSocketServerProtocol):

    def onOpen(self):
        self.factory.register(self)

    def onMessage(self, payload, isBinary):
        if not isBinary:
            payload = "{} from {}".format(payload.decode('utf8'), "camera_sub")
        print("{} from {}".format(payload, "camera_sub"))

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

    def register(self, client):
        if client not in self.clients:
            print("registered client {}".format(client.peer))
            self.clients.append(client)

    def unregister(self, client):
        if client in self.clients:
            print("unregistered client {}".format(client.peer))
            self.clients.remove(client)

    def broadcast(self, msg):
        print("Attempting to broadcast image from camera")
        if len(self.clients) == 0:
            print("No connected clients to broadcast too.")
            return
        for c in self.clients:
            c.sendMessage(msg)
            print("image sent to {}".format(c.peer))


def image_received_callback(data, args):
    rospy.loginfo("In subscriber callback")
    factory = args[0]
    b64string = base64.b64encode(data.data)
    # rospy.loginfo("Encoded size of the sent image: {0} bytes".format(len(b64string)))
    factory.broadcast(b64string)


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
