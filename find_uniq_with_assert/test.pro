SRC = $$system( git rev-parse --show-toplevel )

TEMPLATE = app
TARGET = find_uniq_with_assert

SOURCES = test.cpp

include( $$SRC/include.pro )
