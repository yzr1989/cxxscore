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
    core/platforms/linux-platform.cpp \
    core/functionals/elapsed-time.cpp \
    core/functionals/compiler-info.cpp \
    core/abstracts/abstract-container.cpp \
    core/enums/container-type-enum.cpp \
    core/containers/test-result-container.cpp \
    core/core/data-stream.cpp \
    core/containers/compiler-info-container.cpp \
    core/containers/platform-info-container.cpp \
    core/functionals/platform-info.cpp \
    core/loggers/raw-logger.cpp \
    core/functionals/container-file.cpp \
    core/factories/container-factory.cpp \
    core/tests/factorial-test-case.cpp \
    core/tests/base64-test.cpp \
    core/containers/test-case-info-container.cpp

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
    core/platforms/linux-platform.h \
    core/functionals/elapsed-time.h \
    core/functionals/compiler-info.h \
    core/abstracts/abstract-container.h \
    core/enums/container-type-enum.h \
    core/containers/test-result-container.h \
    core/core/data-stream.h \
    core/containers/compiler-info-container.h \
    core/containers/platform-info-container.h \
    core/functionals/platform-info.h \
    core/loggers/raw-logger.h \
    core/functionals/container-file.h \
    core/factories/container-factory.h \
    core/tests/factorial-test-case.h \
    core/tests/base64-test.h \
    core/containers/test-case-info-container.h
