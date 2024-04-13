QT += testlib
QT += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += qt warn_on depend_includepath testcase

CONFIG += c++17
#CONFIG += qt console warn_on depend_includepath testcase
#CONFIG -= app_bundle

INCLUDEPATH += ../submission

TEMPLATE = app

SOURCES +=  tests.cpp \
    ../submission/mainwindow.cpp
    ../submission/main.cpp

HEADERS +=  \
    ../submission/mainwindow.h

FORMS += \
    ../submission/mainwindow.ui
