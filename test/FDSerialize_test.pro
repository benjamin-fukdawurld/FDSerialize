TARGET = FDSerialize_test

TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

DESTDIR = ../../build/bin
MAKEFILE = ../../build/makefiles/$${TARGET}
OBJECTS_DIR = ../../build/obj/$${TARGET}

LIBS += \
    -pthread \
    -L../../build/lib -lFDXml -lFDJson -lFDCore \
    -L../../thirdparty/googletest/build/lib -lgtest

INCLUDEPATH += \
    ../../FDCore/include \
    ../include \
    ../../ \
    ../../FDXml/include \
    ../../FDJson/include \
    ../../thirdparty/rapidjson/include \
    ../../thirdparty \
    ../../thirdparty/googletest/googletest/include \

SOURCES += \
    main.cpp

HEADERS += \
    FDSerialize_test.h
