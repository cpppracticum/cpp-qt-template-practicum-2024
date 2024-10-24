QT += testlib
QT += gui
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += qt warn_on depend_includepath testcase

CONFIG += c++17

DEFINES += PRAC_TESTS

SUBMISSION_PATH = ../submission

INCLUDEPATH += $$SUBMISSION_PATH

INCLUDEPATH += ../prac_mocks

TEMPLATE = app

SOURCES += \
    tests.cpp \
    $$SUBMISSION_PATH/winterwindow.cpp

HEADERS +=  \
    $$SUBMISSION_PATH/winterwindow.h \
    ../prac_mocks/prac/QPainter

FORMS += \
    $$SUBMISSION_PATH/winterwindow.ui

