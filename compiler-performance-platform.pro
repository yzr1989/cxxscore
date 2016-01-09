QT += core
CONFIG += c++14

include(cflags.pri)

TARGET = compiler-performance-platform

TEMPLATE = app

SOURCES += main.cpp \
    core/interfaces/templates/itemplate-attach.cpp \
    core/abstracts/abstract-platform.cpp \
    core/interfaces/iplatform.cpp \
    core/interfaces/itestcase.cpp \
    core/interfaces/ilogger.cpp \
    core/enums/test-case-id-enum.cpp \
    core/concretes/linux-platform.cpp \
    core/concretes/ini-logger.cpp \
    core/tests/nwd-test-case.cpp \
    core/factories/test-case-factory.cpp \
    core/tests/fibonacci-test-case.cpp

HEADERS += \
    core/interfaces/templates/itemplate-attach.h \
    core/abstracts/abstract-platform.h \
    core/interfaces/iplatform.h \
    core/interfaces/itestcase.h \
    core/interfaces/ilogger.h \
    core/enums/test-case-id-enum.h \
    core/concretes/linux-platform.h \
    core/concretes/ini-logger.h \
    core/tests/nwd-test-case.h \
    core/factories/test-case-factory.h \
    core/tests/fibonacci-test-case.h
