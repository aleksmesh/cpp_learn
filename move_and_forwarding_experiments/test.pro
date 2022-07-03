SRC = $$system( git rev-parse --show-toplevel )

TEMPLATE = app
TARGET = move_experiment

SOURCES = test.cpp

include( $$SRC/include.pro )
