QT       += sql
QT       -= gui

TARGET = JapKatsuyouCLI
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += static

#QTPLUGIN += qsqlite
#QTPLUGIN.platforms = qminimal

TEMPLATE = app
DESTDIR = ../japkat-bin

DEFINES += dataFolder=\\\"./\\\"

SOURCES += \
            main.cpp \
            edict2.cpp \
            japkat.cpp

HEADERS += \
            msg.h \
            edict2.h \
            japkat.h

LIBS += -L../libjpconj-bin/ -ljpconj
#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libjpconj-bin/ -llibjpconj
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libjpconj-bin/debug/ -llibjpconj
#else:symbian: LIBS += -llibjpconj
#else:unix: LIBS += -L$$PWD/../libjpconj-bin/ -ljpconj

INCLUDEPATH += ../libjpconj
DEPENDPATH += . ../libjpconj
