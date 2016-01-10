QT += core gui widgets

include(cflags.pri)

TARGET = compiler-platform-graph
TEMPLATE = app

HEADERS += \
    gui/window/main-window.h

SOURCES += \
    gui/window/main-window.cpp \
    main/graph/main.cpp

FORMS += \
    gui/window/main-window.ui

