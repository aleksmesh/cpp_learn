SRC = $$system( git rev-parse --show-toplevel )

TEMPLATE = app
TARGET = bands_from_int_sequence
INCLUDEPATH += .
SOURCES += test.cpp

LIBS += -lfmt

include( $$SRC/include.pro )
