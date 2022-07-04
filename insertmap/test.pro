SRC = $$system( git rev-parse --show-toplevel )

TEMPLATE = app
TARGET = insert_map

SOURCES = test.cpp

include( $$SRC/include.pro )
