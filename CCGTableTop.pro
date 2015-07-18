
QT += core
QT += network
QT -= gui
QT += core websockets

TARGET = CCGTableTop
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    server.cpp \
    serverthread.cpp \
    websocketserver.cpp \
    protocolhandler.cpp

HEADERS += \
    server.h \
    serverthread.h \
    websocketserver.h \
    protocolhandler.h

