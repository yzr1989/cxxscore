TARGET = compiler-performance-platform
TEMPLATE = app
QT += core
QT -= gui

include(cflags.pri)

SOURCES += main/platform/main.cpp \
		core/abstracts/abstract-platform.cpp \
		core/factories/logger-factory.cpp \
		core/factories/platform-factory.cpp \
		core/factories/test-factory.cpp \
		core/interfaces/ilogger.cpp \
		core/interfaces/iplatform.cpp \
		core/interfaces/itestcase.cpp \
		core/interfaces/templates/itemplate-attach.cpp \
		core/tests/empty-call-test.cpp \
    core/platforms/linux-platform.cpp \
    core/functionals/elapsed-time.cpp \
    core/abstracts/abstract-container.cpp \
    core/containers/test-result-container.cpp \
    core/core/data-stream.cpp \
    core/containers/compiler-info-container.cpp \
    core/containers/platform-info-container.cpp \
    core/loggers/raw-logger.cpp \
    core/factories/container-factory.cpp \
    core/tests/base64-test.cpp \
    core/containers/test-case-info-container.cpp \
    core/functionals/container-reader.cpp \
    core/functionals/container-writer.cpp \
    core/tests/tail-call-fibonacci-test.cpp \
    core/tests/naive-nwd-test.cpp \
    core/tests/naive-factorial-test.cpp \
    core/tests/naive-fibonacci-test.cpp \
    core/tests/merge-sort-test.cpp \
    core/tests/tail-call-factorial-test.cpp \
    core/abstracts/abstract-test-case.cpp \
    core/enums/compiler-type.cpp \
    core/enums/container-type.cpp \
    core/enums/logger-type.cpp \
    core/enums/platform-type.cpp \
    core/enums/test-type.cpp \
    core/enums/architecture-type.cpp \
    core/containers/version-info-container.cpp \
    core/managers/file-manager.cpp \
    core/enums/folder.cpp \
    core/functionals/info-center.cpp

HEADERS += \
		core/abstracts/abstract-platform.h \
		core/factories/logger-factory.h \
		core/factories/platform-factory.h \
		core/factories/test-factory.h \
		core/interfaces/ilogger.h \
		core/interfaces/iplatform.h \
		core/interfaces/itestcase.h \
		core/interfaces/templates/itemplate-attach.h \
		core/tests/empty-call-test.h \
    core/platforms/linux-platform.h \
    core/functionals/elapsed-time.h \
    core/abstracts/abstract-container.h \
    core/containers/test-result-container.h \
    core/core/data-stream.h \
    core/containers/compiler-info-container.h \
    core/containers/platform-info-container.h \
    core/loggers/raw-logger.h \
    core/factories/container-factory.h \
    core/tests/base64-test.h \
    core/containers/test-case-info-container.h \
    core/functionals/container-reader.h \
    core/functionals/container-writer.h \
    core/tests/tail-call-fibonacci-test.h \
    core/tests/naive-nwd-test.h \
    core/tests/naive-factorial-test.h \
    core/tests/naive-fibonacci-test.h \
    core/tests/tail-call-factorial-test.h \
    core/tests/merge-sort-test.h \
    core/abstracts/abstract-test-case.h \
    core/enums/compiler-type.h \
    core/enums/container-type.h \
    core/enums/logger-type.h \
    core/enums/platform-type.h \
    core/enums/test-type.h \
    core/enums/architecture-type.h \
    core/containers/version-info-container.h \
    core/managers/file-manager.h \
    core/enums/folder.h \
    core/functionals/info-center.h
