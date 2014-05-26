#-------------------------------------------------
#
# Project created by QtCreator 2014-05-04T20:50:35
#
#-------------------------------------------------

QT       += core gui sql
TARGET = ErpSystem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    materialdialog.cpp \
    newcustomerdialog.cpp \
    orderdialog.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    materialdialog.h \
    newcustomerdialog.h \
    orderdialog.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    materialdialog.ui \
    newcustomerdialog.ui \
    orderdialog.ui

RESOURCES += \
    erp.qrc
