#-------------------------------------------------
#
# Project created by QtCreator 2014-06-17T17:54:59
#
#-------------------------------------------------

QT       += core gui network xlsx

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FabricGenerator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    datathread.cpp

HEADERS  += mainwindow.h \
    datathread.h

FORMS    += mainwindow.ui

ICON = Icon.icns
