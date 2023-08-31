# chinesetypewriter.pro

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chinesetypewriter
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++17

SOURCES += main.cpp \
    chinesetypewriter.cpp

HEADERS += chinesetypewriter.h

FORMS += chinesetypewriter.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
