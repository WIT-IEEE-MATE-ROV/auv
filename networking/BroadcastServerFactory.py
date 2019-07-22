#!/usr/bin/env python2
from autobahn.twisted.websocket import WebSocketServerFactory


class BroadcastServerFactory(WebSocketServerFactory):
    """
    Simple broadcast server broadcasting any message it receives to all
    currently connected clients.
    """
    protocol = None

    def __init__(self, url, custom_protocol):
        global protocol
        protocol = custom_protocol
        WebSocketServerFactory.__init__(self, url)
        self.clients = []

    def register(self, client):
        if client not in self.clients:
            self.clients.append(client)
            print "registered client {}".format(client.peer)

    def unregister(self, client):
        if client in self.clients:
            self.clients.remove(client)
            print "unregistered client {}".format(client.peer)

    def broadcast(self, payload, isBinary):
        for c in self.clients:
            c.sendMessage(payload, isBinary)
        print "broadcasted message to {} clients".format(len(self.clients))
