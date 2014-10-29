#-------------------------------------------------
#
# Project created by QtCreator 2014-10-29T15:56:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Fighterino
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
