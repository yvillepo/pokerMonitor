#-------------------------------------------------
#
# Project created by QtCreator 2019-07-09T17:14:36
#
#-------------------------------------------------

QT       += core gui sql testlib

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
    calcul/calcul.cpp \
    card.cpp \
    enregistreur.cpp \
    hand.cpp \
    hand_view.cpp \
    handviewitem.cpp \
    handviewwidget.cpp \
    imagereader.cpp \
    lecteur.cpp \
        main.cpp \
        mainwindow.cpp \
    mesranges.cpp \
    myopenrange.cpp \
    preflophelperwidget.cpp \
    range_view.cpp \
    rangeview.cpp \
    rangeviewwidget.cpp \
    read_history.cpp \
    reader.cpp \
    scan_hand.cpp \
    screen.cpp \
    sql.cpp \
    util.cpp \
    range.cpp

HEADERS += \
    SQL.h \
    calcul/calcul.h \
    card.h \
    enregistreur.h \
    hand.h \
    hand_view.h \
    handviewitem.h \
    handviewwidget.h \
    imagereader.h \
    lecteur.h \
    mainwindow.h \
    mesranges.h \
    myopenrange.h \
    preflophelperwidget.h \
    range.h \
    range_view.h \
    rangeview.h \
    rangeviewwidget.h \
    read_history.h \
    reader.h \
    scan_hand.h \
    screen.h \
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
    testpoker.db \
    img/* \
    open.txt \
    .gitignores

RESOURCES += \
    data_resources.qrc
