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

import rospy
import json
from autobahn.twisted.websocket import WebSocketServerFactory, WebSocketServerProtocol
from twisted.internet import reactor
from auv.msg import trajectory
from auv.msg import mode

trajpub = rospy.Publisher('joystick_execution', trajectory, queue_size=3)
modepub = rospy.Publisher('mode_request', mode, queue_size=3)
RATE = None


# Yoinked from surface_station/server/server.py, modified for us
class BroadcastServerProtocol(WebSocketServerProtocol):

    def onOpen(self):
        self.factory.register(self)

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

        self.factory.broadcast(payload_str, isBinary)

    def onClose(self, wasClean, code, reason):
        self.factory.unregister(self)


# Also yoinked, modified for us
class BroadcastServerFactory(WebSocketServerFactory):
    """
    Simple broadcast server which broadcasts out the instructions from the surface
    """
    protocol = BroadcastServerProtocol

    def __init__(self, url):
        WebSocketServerFactory.__init__(self, url)
        self.clients = []

    def register(self, client):
        if client not in self.clients:
            self.clients.append(client)
            print("registered client {}".format(client.peer))

    def unregister(self, client):
        if client in self.clients:
            self.clients.remove(client)
            print("unregistered client {}".format(client.peer))

    def broadcast(self, payload, isBinary):
        for c in self.clients:
            c.sendMessage(payload, isBinary)
        print("broadcasted message to {} clients".format(len(self.clients)))


def mode_callback(data):
    AUVMODE = data.auvmode


def listener():
    rospy.init_node('joystick_executor', anonymous=True)
    rospy.Subscriber('current_mode', mode, mode_callback)

    factory = None
    simmode = True  # TODO: Allow command line switch of this
    if simmode is True:
        factory = BroadcastServerFactory(u"ws://127.0.0.1:9000")
    if simmode is False:
        factory = BroadcastServerFactory(u"ws://enbarr.local:9000")

    sendmode = mode()
    sendmode.auvmode = True;
    sendmode.rovmode = False
    modepub.publish(sendmode)

    #    global RATE
    #    RATE = rospy.Rate(5)
    reactor.listenTCP(9000, factory)
    reactor.run()


if __name__ == '__main__':
    listener()
