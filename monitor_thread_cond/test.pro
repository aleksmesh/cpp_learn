SRC = $$system( git rev-parse --show-toplevel )

TEMPLATE = app
TARGET = monitor

SOURCES = test.cpp

LIBS += -lfmt

include( $$SRC/include.pro )
