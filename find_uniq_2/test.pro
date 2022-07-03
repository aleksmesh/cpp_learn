SRC = $$system( git rev-parse --show-toplevel )

TEMPLATE = app
TARGET = find_uniq2

SOURCES = test.cpp

include( $$SRC/include.pro )
