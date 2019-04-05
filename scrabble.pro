#-------------------------------------------------
#
# Project created by QtCreator 2019-03-25T00:05:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = scrabble
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        Lista.cpp \
        Nodo.cpp \
        dibujar.cpp \
        ficha.cpp \
        funcionescliente.cpp \
        listaPieza.cpp \
        listaficha.cpp \
        main.cpp \
        pieza.cpp \
        scrabble.cpp \
        tablero.cpp

HEADERS += \
        Lista.h \
        Nodo.h \
        dibujar.h \
        ficha.h \
        funcionescliente.h \
        json.hpp \
        listaPieza.h \
        listaficha.h \
        pieza.h \
        scrabble.h \
        tablero.h

FORMS += \
        scrabble.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
