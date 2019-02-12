#-------------------------------------------------
#
# Project created by QtCreator 2018-09-04T15:09:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ManyTiles
TEMPLATE = app


SOURCES += main.cpp \
    dialog.cpp \
    blank_tile.cpp \
    filled_tile.cpp \
    game.cpp \
    gameboard.cpp \
    tile.cpp \
    view_tile.cpp \
    gameview.cpp

HEADERS  += \
    ../ProjektKlocki/blank_tile.h \
    ../ProjektKlocki/filled_tile.h \
    dialog.h \
    blank_tile.h \
    filled_tile.h \
    game.h \
    gameboard.h \
    tile.h \
    view_tile.h \
    gameview.h

FORMS    += \
    dialog.ui \
    mainwindow.ui

RESOURCES += \
    myresources.qrc
