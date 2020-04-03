#-------------------------------------------------
#
# Project created by QtCreator 2019-07-09T17:14:36
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dbpoker
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
    hand.cpp \
    hand_view.cpp \
    lecteur.cpp \
        main.cpp \
        mainwindow.cpp \
    range.cpp \
    range_view.cpp \
    read_history.cpp \
    reader.cpp \
    sql.cpp \
    util.cpp

HEADERS += \
    SQL.h \
    hand.h \
    hand_view.h \
    lecteur.h \
    mainwindow.h \
    range.h \
    range_view.h \
    read_history.h \
    reader.h \
    util.h

FORMS += \
        lecteur.ui \
        mainwindow.ui \
        range_view.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    hand_hystory_example_pokerstars.txt \
    hand_hystory_example_winamax \
    script_sql \
    testpoker.db

RESOURCES += \
    image.qrc
