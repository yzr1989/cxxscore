QT += core
QT -= gui

include(cflags.pri)

TARGET = compiler-top10
TEMPLATE = app

SOURCES += \
    main/top10/main.cpp \
    core/functionals/container-reader.cpp \
    core/core/data-stream.cpp \
    core/abstracts/abstract-container.cpp \
    core/containers/compiler-info-container.cpp \
    core/containers/platform-info-container.cpp \
    core/containers/test-case-info-container.cpp \
    core/containers/test-result-container.cpp \
    core/containers/version-info-container.cpp \
    core/enums/architecture-type.cpp \
    core/enums/compiler-type.cpp \
    core/enums/container-type.cpp \
    core/enums/platform-type.cpp \
    core/enums/test-type.cpp \
    core/factories/container-factory.cpp \
    core/managers/file-manager.cpp \
    core/enums/folder.cpp

HEADERS += \
    core/functionals/container-reader.h \
    core/core/data-stream.h \
    core/abstracts/abstract-container.h \
    core/containers/compiler-info-container.h \
    core/containers/platform-info-container.h \
    core/containers/test-case-info-container.h \
    core/containers/test-result-container.h \
    core/containers/version-info-container.h \
    core/enums/architecture-type.h \
    core/enums/compiler-type.h \
    core/enums/container-type.h \
    core/enums/platform-type.h \
    core/enums/test-type.h \
    core/factories/container-factory.h \
    core/managers/file-manager.h \
    core/enums/folder.h