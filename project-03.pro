TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    UI.cpp \
    queue.cpp \
    commands.cpp

HEADERS += \
    UI.h \
    queue.h \
    commands.h
