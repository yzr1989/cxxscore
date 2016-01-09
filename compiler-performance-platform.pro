QT += core
CONFIG += c++14

TARGET = compiler-performance-platform

TEMPLATE = app

SOURCES += main.cpp \
    core/interfaces/templates/itemplate-attach.cpp \
    core/abstracts/abstract-platform.cpp \
    core/interfaces/iplatform.cpp \
    core/interfaces/itestcase.cpp \
    core/interfaces/ilogger.cpp \
    core/enums/test-case-id-enum.cpp

HEADERS += \
    core/interfaces/templates/itemplate-attach.h \
    core/abstracts/abstract-platform.h \
    core/interfaces/iplatform.h \
    core/interfaces/itestcase.h \
    core/interfaces/ilogger.h \
    core/enums/test-case-id-enum.h
