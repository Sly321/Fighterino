#-------------------------------------------------
#
# Project created by QtCreator 2014-10-20T13:33:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 025_WidgetKey
TEMPLATE = app


SOURCES += main.cpp\
    draw.cpp \
    startmenu.cpp \
    chat.cpp \
    choosemenu.cpp \
    sprite.cpp \
    character.cpp \
    fighterino.cpp

HEADERS  += \
    draw.h \
    startmenu.h \
    chat.h \
    choosemenu.h \
    definitions.h \
    sprite.h \
    character.h \
    fighterino.h

FORMS    += \
    startmenu.ui

RESOURCES += \
    res.qrc
