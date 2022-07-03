SRC = $$system( git rev-parse --show-toplevel )

TEMPLATE = app
TARGET = invert_selected_bit

SOURCES = test.cpp

include( $$SRC/include.pro )
