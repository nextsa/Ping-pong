#-------------------------------------------------
#
# Project created by QtCreator 2017-05-17T18:33:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pingpong
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    shape.cpp \
    ball.cpp \
    rocket.cpp \
    line.cpp

HEADERS  += dialog.h \
    shape.h \
    ball.h \
    rocket.h \
    line.h

FORMS    += dialog.ui
CONFIG+=C++11
