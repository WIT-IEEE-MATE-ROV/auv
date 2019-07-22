#!/usr/bin/env python

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

import json

import rospy
from autobahn.twisted.websocket import WebSocketClientFactory
from auv.msg import mode
from auv.msg import trajectory
from twisted.internet import reactor

trajpub = rospy.Publisher('joystick_execution', trajectory, queue_size=3)
modepub = rospy.Publisher('mode_request', mode, queue_size=3)
RATE = None


# Yoinked from surface_station/server/server.py, modified for us
class JoystickWebsocketClientProtocol:

    def onOpen(self):
        self.factory._proto = self
        self.sendMessage(u"Joystick Executor online and connected.".encode('utf8'))

    def onMessage(self, payload, isBinary):
        payload_str = b"Got Message: " + payload
        sendtraj = trajectory()
        sendmode = mode()

        try:
            datadict = json.loads(payload.decode('utf-8'))

            sendtraj.orientation.roll = float(datadict['r'])
            sendtraj.orientation.pitch = float(datadict['p'])
            sendtraj.orientation.yaw = float(datadict['c'])
            sendtraj.translation.x = float(datadict['x'])
            sendtraj.translation.y = float(datadict['y'])
            sendtraj.translation.z = float(datadict['z'])
            # TODO: Modify message for button press info

            #            while not rospy.is_shutdown():
            trajpub.publish(sendtraj)
        #                RATE.sleep()

        except Exception as e:
            # If anything messes up, make sure the thrusters aren't spinning anymore
            print("Exception in joystick_executor")
            print(e)
            sendtraj.orientation.roll = 0
            sendtraj.orientation.pitch = 0
            sendtraj.orientation.yaw = 0
            sendtraj.translation.x = 0
            sendtraj.translation.y = 0
            sendtraj.translation.z = 0
            sendmode.auvmode = True
            sendmode.rovmode = False

            trajpub.publish(sendtraj)
            modepub.publish(sendmode)
        self.sendMessage(payload_str, isBinary)

    def onClose(self, wasClean, code, reason):
        print "WebSocket connection closed: %s" % reason
        self.factory._proto = None


class MyClientFactory(WebSocketClientFactory):
    """
    Our factory for WebSocket client connections.
    """
    protocol = JoystickWebsocketClientProtocol()

    def __init__(self, url):
        WebSocketClientFactory.__init__(self, url)


# Also yoinked, modified for us
# class BroadcastServerFactory(WebSocketServerFactory):
#
#     """
#     Simple broadcast server which broadcasts out the instructions from the surface
#     """
#     # protocol = BroadcastServerProtocol
#
#     def __init__(self, url):
#         WebSocketServerFactory.__init__(self, url)
#         self.clients = []
#
#     def register(self, client):
#         if client not in self.clients:
#             self.clients.append(client)
#             print("registered client {}".format(client.peer))
#
#     def unregister(self, client):
#         if client in self.clients:
#             self.clients.remove(client)
#             print("unregistered client {}".format(client.peer))
#
#     def broadcast(self, payload, isBinary):
#         for c in self.clients:
#             c.sendMessage(payload, isBinary)
#         print("broadcasted message to {} clients".format(len(self.clients)))

# class MyClientProtocol(WebSocketClientProtocol):
#     """
#     Our protocol for WebSocket client connections.
#     """
#
#     def onOpen(self):
#         print("WebSocket connection open.")
#
#         # the WebSocket connection is open. we store ourselves on the
#         # factory object, so that we can access this protocol instance
#         # from wxPython, e.g. to use sendMessage() for sending WS msgs
#         ##
#         self.factory._proto = self
#         self._received = 0
#
#     def onMessage(self, payload, isBinary):
#         # a WebSocket message was received. now interpret it, possibly
#         # accessing the wxPython app `self.factory._app` or our
#         # single UI frame `self.factory._app._frame`
#         ##
#         if isBinary:
#             print("Binary message received: {0} bytes".format(len(payload)))
#         else:
#             print("Text message received: {0}".format(payload.decode('utf8')))
#
#         self._received += 1
#         frame = self.factory._app._frame
#         # frame.rov_panel.messages.AppendText("{}\n".format(self._received))
#         frame.rov_panel.messages.AppendText("{}\n".format(payload))
#
#     def onClose(self, wasClean, code, reason):
#         print("WebSocket connection closed: {0}".format(reason))
#
#         # the WebSocket connection is gone. clear the reference to ourselves
#         # on the factory object. when accessing this protocol instance from
#         # wxPython, always check if the ref is None. only use it when it's
#         # not None (which means, we are actually connected)
#         ##
#         self.factory._proto = None


def mode_callback(data):
    AUVMODE = data.auvmode


def listener():
    rospy.init_node('joystick_executor', anonymous=True)
    rospy.Subscriber('current_mode', mode, mode_callback)

    factory = None
    simmode = True  # TODO: Allow command line switch of this
    host = None
    if simmode is True:
        host = u"ws://127.0.0.1:9000"
    if simmode is False:
        host = u"ws://enbarr.local:9000"

    factory = MyClientFactory(host)
    reactor.connectTCP(host, 9000, factory)
    reactor.run()
    sendmode = mode()
    sendmode.auvmode = True;
    sendmode.rovmode = False
    modepub.publish(sendmode)

    #    global RATE
    #    RATE = rospy.Rate(5)


if __name__ == '__main__':
    listener()
