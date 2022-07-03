SRC = $$system( git rev-parse --show-toplevel )

TEMPLATE = app
TARGET = virtual_nightmare

SOURCES = test.cpp

LIBS += -lfmt

include( $$SRC/include.pro )

QMAKE_CXXFLAGS += -Wno-error=delete-non-virtual-dtor
