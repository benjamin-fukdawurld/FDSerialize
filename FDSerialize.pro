#-------------------------------------------------
#
# Project created by QtCreator 2019-07-11T10:08:23
#
#-------------------------------------------------

TARGET = FDSerialize
TEMPLATE = lib
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = ../build/lib
MAKEFILE = ../build/makefiles/$${TARGET}
OBJECTS_DIR = ../build/obj/$${TARGET}

INCLUDEPATH += include

SOURCES +=

HEADERS += \
    include/FDSerialize/FDSerialize.h \
    include/FDSerialize/SerializerBase.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
