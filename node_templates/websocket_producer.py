from src.auv.networking.BroadcastServerProtocol import BroadcastServerProtocol
import rospy

class WebsocketProducerNode(BroadcastServerProtocol):

    def onMessage(self, payload, isBinary):
        print b"Got message: " + payload



def main():
    rospy.init_node('websocket_producer', anonymous=True)
    factory = None
    simmode = True  # TODO: Allow command line switch of this
    if simmode is True:
        factory = BroadcastServerFactory(u"ws://127.0.0.1:9000")
    if simmode is False:
        factory = BroadcastServerFactory(u"ws://enbarr.local:9000")
