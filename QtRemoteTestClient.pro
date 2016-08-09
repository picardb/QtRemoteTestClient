#-------------------------------------------------
#
# Project created by QtCreator 2016-08-02T17:37:06
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtRemoteTestClient
TEMPLATE = app

LIBS += -L$$PWD\lib -ldnssd

SOURCES += \
    src/main.cpp \
    src/widgets/MainWindow.cpp \
    src/model/Model.cpp \
    src/widgets/MainWidget.cpp \
    src/widgets/DeviceWidget.cpp \
    src/model/DnsServiceRecord.cpp \
    src/model/DnsServiceBrowser.cpp

HEADERS  += \
    src/widgets/MainWindow.h \
    src/model/Model.h \
    src/widgets/MainWidget.h \
    src/widgets/DeviceWidget.h \
    src/model/DnsServiceRecord.h \
    src/constants.h \
    src/model/DnsServiceBrowser.h
