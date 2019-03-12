#-------------------------------------------------
#
# Project created by QtCreator 2019-02-26T15:42:01
#
#-------------------------------------------------

QT       -= gui

TARGET = WWC
TEMPLATE = lib
CONFIG += staticlib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES +=


HEADERS += \
    WWC/WWC.h \
    WWC/src/Component/setupable.h \
    WWC/src/Component/setconf.h
 
unix {
    target.path = /usr/lib
    INSTALLS += target
}
