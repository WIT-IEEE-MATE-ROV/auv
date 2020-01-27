#!python3

import logging
import os

try:
    import adafruit_fxas21002c
    import adafruit_fxos8700
    import board
    import busio

    fxas = adafruit_fxas21002c.FXAS21002C(busio.I2C(board.SCL, board.SDA))
    fxos = adafruit_fxos8700.FXOS8700(busio.I2C(board.SCL, board.SDA))

    fxas_fxos_is_up = True
    logging.info("NineDoF sensor is up!")
except Exception as e:
    logging.error("Failed to set up the sensor! We'll assume it's because you aren't running on the right hardware, "
                  "and we'll provide junk testing values instead.")
    logging.error(e)

pipe_name = 'pipe'

try:
    os.mkfifo(pipe_name)
except OSError as oe:
    logging.debug('Pipe exists')

with open(pipe_name, 'w', 1) as fifo:
    logging.info('FIFO opened')
    data = fifo.write('test')
