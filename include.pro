CONFIG += debug
QMAKE_CXXFLAGS += -Werror
QMAKE_CXXFLAGS += -D_REENTRANT
QMAKE_CXXFLAGS += -std=c++17
QMAKE_CFLAGS += -Werror

contains( TEMPLATE, autotest ){
  TEMPLATE = app
  isEmpty( DESTDIR ):DESTDIR = ./
}

SRC = $$system( git rev-parse --show-toplevel )
isEmpty( DESTDIR ) {
  contains( TEMPLATE, app ):DESTDIR = $$SRC/bin
  contains( TEMPLATE, lib ):DESTDIR = $$SRC/lib
}
contains( TEMPLATE, subdirs ):DESTDIR = ./

isEmpty( DESTDIR ):error( "TEMPLATE must be defined" )

CONFIG += warn_on
QMAKE_CXXFLAGS += -pthread

contains( CONFIG, qt ) {
    MOC_DIR = ./.moc
    UI_DIR  = ./.ui
    RCC_DIR = ./.rcc
    INCLUDEPATH += ./.ui
}
OBJECTS_DIR = ./.o

