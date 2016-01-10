TARGET = compiler-performance-platform
TEMPLATE = app
QT += core

include(cflags.pri)

SOURCES += main/platform/main.cpp \
		core/abstracts/abstract-platform.cpp \
		core/enums/logger-type-enum.cpp \
		core/enums/platform-type-enum.cpp \
		core/enums/test-type-enum.cpp \
		core/factories/logger-factory.cpp \
		core/factories/platform-factory.cpp \
		core/factories/test-factory.cpp \
		core/interfaces/ilogger.cpp \
		core/interfaces/iplatform.cpp \
		core/interfaces/itestcase.cpp \
		core/interfaces/templates/itemplate-attach.cpp \
		core/tests/empty-call-test.cpp \
		core/tests/fibonacci-test-case.cpp \
		core/tests/nwd-test-case.cpp \
    core/loggers/ini-logger.cpp \
    core/platforms/linux-platform.cpp \
    core/functionals/elapsed-time.cpp \
    core/functionals/compiler-info.cpp

HEADERS += \
		core/abstracts/abstract-platform.h \
		core/enums/logger-type-enum.h \
		core/enums/platform-type-enum.h \
		core/enums/test-type-enum.h \
		core/factories/logger-factory.h \
		core/factories/platform-factory.h \
		core/factories/test-factory.h \
		core/interfaces/ilogger.h \
		core/interfaces/iplatform.h \
		core/interfaces/itestcase.h \
		core/interfaces/templates/itemplate-attach.h \
		core/tests/empty-call-test.h \
		core/tests/fibonacci-test-case.h \
		core/tests/nwd-test-case.h \
    core/loggers/ini-logger.h \
    core/platforms/linux-platform.h \
    core/functionals/elapsed-time.h \
    core/functionals/compiler-info.h
