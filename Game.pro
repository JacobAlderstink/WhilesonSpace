#-------------------------------------------------
#
# Project created by QtCreator 2018-04-16T11:22:37
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game
TEMPLATE = app

INCLUDEPATH = . Character Map Objects Interface

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        game.cpp \
    Map/planetsuperclass.cpp \
    Character/charactersuperclass.cpp \
    Interface/button.cpp \
    Interface/mainmenu.cpp \
    Interface/minterface.cpp \
    Character/Youler/youler.cpp \
    Map/chuncklist.cpp \
    Map/planetexample.cpp \
    Map/chunckblock.cpp

HEADERS += \
        game.h \
    Map/planetsuperclass.h \
    Character/charactersuperclass.h \
    Interface/button.h \
    Interface/mainmenu.h \
    Interface/minterface.h \
    Character/Youler/youler.h \
    Map/chuncklist.h \
    Map/planetexample.h \
    Map/chunckblock.h

