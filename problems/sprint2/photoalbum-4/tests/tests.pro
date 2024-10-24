QT += testlib
QT += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += qt warn_on depend_includepath testcase

CONFIG += c++17

DEFINES += "PRAC_TESTS"

SUBMISSION_PATH = ../submission

INCLUDEPATH += $$SUBMISSION_PATH

INCLUDEPATH += ../prac_moc

TEMPLATE = app

SOURCES +=  tests.cpp \
    $$SUBMISSION_PATH/mainwindow.cpp

HEADERS +=  \
    $$SUBMISSION_PATH/mainwindow.h\
    ../prac_moc/prac/QTimer

FORMS += \
    $$SUBMISSION_PATH/mainwindow.ui

RESOURCES += \
    $$SUBMISSION_PATH/resources.qrc
