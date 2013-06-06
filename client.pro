#-------------------------------------------------
#
# Project created by QtCreator 2013-06-06T15:39:07
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = client
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Client.cpp

OTHER_FILES += \
    README.md

HEADERS += \
    MyIO.h \
    Client.h
