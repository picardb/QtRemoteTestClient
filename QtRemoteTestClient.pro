#-------------------------------------------------
#
# Project created by QtCreator 2016-08-02T17:37:06
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtRemoteTestClient
TEMPLATE = app

LIBS += -L$$PWD\lib -ldnssd -lws2_32 -liphlpapi

INCLUDEPATH += src/

SOURCES += \
    src/main.cpp \
    src/widgets/MainWindow.cpp \
    src/widgets/MainWidget.cpp \
    src/widgets/DeviceWidget.cpp \
    src/widgets/AudioWidget.cpp \
    src/model/Model.cpp \
    src/model/network/Network.cpp \
    src/model/network/DnsServiceBrowser.cpp \
    src/model/network/DnsServiceRecord.cpp \
    src/model/network/DnsServiceRecordList.cpp \
    src/model/network/DnsServiceResolver.cpp \
    src/model/control/Control.cpp \
    src/model/control/AudioControl.cpp

HEADERS  += \
    src/constants.h \
    src/widgets/MainWindow.h \
    src/widgets/MainWidget.h \
    src/widgets/DeviceWidget.h \
    src/widgets/AudioWidget.h \
    src/model/Model.h \
    src/model/network/Network.h \
    src/model/network/Request.h \
    src/model/network/DnsServiceBrowser.h \
    src/model/network/DnsServiceRecord.h \
    src/model/network/DnsServiceRecordList.h \
    src/model/network/DnsServiceResolver.h \
    src/model/control/Control.h \
    src/model/control/AudioControl.h
