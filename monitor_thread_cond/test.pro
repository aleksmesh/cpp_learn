SRC = $$system( git rev-parse --show-toplevel )

TEMPLATE = app
TARGET = monitor

SOURCES = test.cpp

include( $$SRC/include.pro )
