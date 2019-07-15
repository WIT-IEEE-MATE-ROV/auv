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
from autobahn.twisted.websocket import WebSocketServerFactory, WebSocketServerProtocol
from twisted.internet import reactor
from auv.msg import trajectory
from auv.msg import mode

trajpub = rospy.Publisher('joystick_execution', trajectory, queue_size=3)
modepub = rospy.Publisher('mode_request', mode, queue_size=3)

# Yoinked from surface_station/server/server.py 
class BroadcastServerProtocol(WebSocketServerProtocol):

    def onOpen(self):
        self.factory.register(self)
                                                                                                                    
    def onMessage(self, payload, isBinary):
        payload = b"Server response: " + payload
        self.factory.broadcast(payload, isBinary)

    def onClose(self, wasClean, code, reason):
        self.factory.unregister(self)


class BroadcastServerFactory(WebSocketServerFactory):

    """ 
    Simple broadcast server broadcasting any message it receives to all
    currently connected clients.
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
    simmode = True # TODO: Allow command line switch of this 
    if simmode is True:
        factory = BroadcastServerFactory(u"ws://127.0.0.1:9000")
    if simmode is False:
        factory = BroadcastServerFactory(u"ws://enbarr.local:9000")

    reactor.listenTCP(9000, factory)
    reactor.run()

    try:
        rate = rospy.Rate(5)
        # TODO
        sendtraj = trajectory()
        sendmode = mode()
        sendmode.auvmode = True; sendmode.rovmode = False
        modepub.publish(sendmode)
        while not rospy.is_shutdown():
            trajpub.publish(sendtraj)
            rate.sleep()

    except Exception as e:
        # If anything messes up, make sure the thrusters aren't spinning anymore
        print(e)
        sendtraj = trajectory()
        trajectory.orientation.roll = 0
        trajectory.orientation.pitch = 0
        trajectory.orientation.yaw = 0
        trajectory.translation.x = 0
        trajectory.translation.y = 0
        trajectory.translation.z = 0
        sendmode.auvmode = True
        sendmode.rovmode = False
        sendmode = mode()

        trajpub.publish(sendtraj)
        modepub.publish(sendmode)

if __name__ == '__main__':
    listener()
