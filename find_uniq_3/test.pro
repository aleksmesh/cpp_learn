SRC = $$system( git rev-parse --show-toplevel )

TEMPLATE = app
TARGET = find_uniq_3

SOURCES = test.cpp

include( $$SRC/include.pro )
