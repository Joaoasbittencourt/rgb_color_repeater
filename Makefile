ARDUINO_DIR = /usr/share/arduino
ARDUINO_PORT = /dev/ttyACM*

USER_LIB_PATH+= /home/jp/Arduino/libraries

ARDUINO_LIBS += Wire

BOARD_TAG = uno


include /home/jp/projects/Arduino-Makefile/Arduino.mk