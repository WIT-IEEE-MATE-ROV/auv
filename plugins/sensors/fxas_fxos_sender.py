import os
import sys
import pipes
import logging

logging.basicConfig(format='[Send][%(levelname)s]: %(message)s', level=logging.DEBUG)


def send_data():
    logging.debug('send_data')
    pipe_name = 'pipe'

    try:
        os.mkfifo(pipe_name)
    except OSError as oe:
        logging.error(oe)
        os.unlink(pipe_name)
        os.mkfifo(pipe_name)

    with open(pipe_name, 'w', 1) as fifo:
        logging.info('FIFO opened')
        fifo.write('test')
        fifo.write('test2')

    os.unlink(pipe_name)    

if __name__ == "__main__":
    # send_data()
    logging.debug("Send")
    os._exit(0)
