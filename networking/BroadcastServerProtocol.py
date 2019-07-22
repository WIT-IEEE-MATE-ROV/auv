#!/usr/bin/env python2

from autobahn.twisted import WebSocketServerProtocol


class BroadcastServerProtocol(WebSocketServerProtocol):

    def onOpen(self):
        self.factory.register(self)

    def onMessage(self, payload, isBinary):
        """Define behavior for receiving message"""

    def onClose(self, wasClean, code, reason):
        self.factory.unregister(self)