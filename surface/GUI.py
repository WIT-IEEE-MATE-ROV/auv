#!/usr/bin/env python

from PyQt5 import QtWidgets, QtGui
from PyQt5.QtCore import QTimer
from PyQt5.QtWidgets import QApplication, QWidget
import recieve_nineDof as ndof

# Configurations
fullscreenMode = False
# Enter Screen Resolution for surface station(Only if fullscreenMode is disabled)
height = 1080
width = 1920
# Fonts
Header = QtGui.QFont("Roboto", 12, QtGui.QFont.Bold)
Body = QtGui.QFont("Roboto", 10)


class WUROV(QWidget):
    def __init__(self):
        # Style settings for GUI
        super(WUROV, self).__init__()
        self.setGeometry(0, 0, width, height)
        self.setWindowTitle("WUROV Control")
        self.setStyleSheet('background-color: ' + '#2C2F33' + ';color: ' + 'white')

        # Grid layout for GUI
        self.nineDof()
        grid = QtWidgets.QGridLayout()
        grid.addWidget(self.accel_x, 2, 0)
        grid.addWidget(self.accel_y, 3, 0)
        grid.addWidget(self.accel_z, 4, 0)
        grid.addWidget(self.roll, 5, 0)
        grid.addWidget(self.pitch, 6, 0)
        grid.addWidget(self.yaw, 7, 0)

        # Refreshes Qlabel on a timer
        timer = QTimer(self)
        timer.start()
        self.setLayout(grid)
        timer = QTimer(self)
        timer.setInterval(10)
        timer.timeout.connect(self.sensor)
        timer.start()

    # NineDof labels to display sensor read outs
    def nineDof(self):
        self.accel_x = QtWidgets.QLabel(self)
        self.accel_x.setFont(QtGui.QFont(Body))
        self.accel_x.adjustSize()

        self.accel_y = QtWidgets.QLabel(self)
        self.accel_y.setFont(QtGui.QFont(Body))
        self.accel_y.adjustSize()

        self.accel_z = QtWidgets.QLabel(self)
        self.accel_z.setFont(QtGui.QFont(Body))
        self.accel_z.adjustSize()

        self.yaw = QtWidgets.QLabel(self)
        self.yaw.setFont(QtGui.QFont(Body))
        self.yaw.adjustSize()

        self.pitch = QtWidgets.QLabel(self)
        self.pitch.setFont(QtGui.QFont(Body))
        self.pitch.adjustSize()

        self.roll = QtWidgets.QLabel(self)
        self.roll.setFont(QtGui.QFont(Body))
        self.roll.adjustSize()

    # Sensor function updates labels from receive_nineDof.py
    def sensor(self):
        self.accel_x.setText("X: " + ndof.get_x())
        self.accel_y.setText("Y: " + ndof.get_y())
        self.accel_z.setText("Z: " + ndof.get_z())
        self.roll.setText("Roll: " + ndof.get_roll())
        self.pitch.setText("Pitch: " + ndof.get_pitch())
        self.yaw.setText("Yaw: " + ndof.get_yaw())


# Code to be executed
if __name__ == "__main__":
    import sys

    app = QApplication(sys.argv)
    win = WUROV()


    def window():
        if fullscreenMode:
            win.showFullScreen()
        else:
            win.show()
        sys.exit(app.exec_())


    window()
