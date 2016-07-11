QT += core gui widgets printsupport
CONFIG += c++14

include(cflags.pri)

LIBS += -lqcustomplot

TARGET = compiler-platform-graph
TEMPLATE = app

HEADERS += \
    gui/window/main-window.h \
    core/abstracts/abstract-container.h \
    core/containers/compiler-info-container.h \
    core/containers/platform-info-container.h \
    core/containers/test-result-container.h \
    core/core/data-stream.h \
    core/factories/container-factory.h \
    gui/widgets/plot-tab.h \
    gui/widgets/plot.h \
    core/factories/color-factory.h \
    core/functionals/container-reader.h \
    core/containers/test-case-info-container.h \
    core/enums/architecture-type.h \
    core/enums/compiler-type.h \
    core/enums/container-type.h \
    core/enums/logger-type.h \
    core/enums/platform-type.h \
    core/enums/test-type.h \
    core/containers/version-info-container.h \
    core/managers/file-manager.h \
    core/enums/folder.h \
    core/enums/font-type.h

SOURCES += \
    gui/window/main-window.cpp \
    main/graph/main.cpp \
    core/abstracts/abstract-container.cpp \
    core/containers/compiler-info-container.cpp \
    core/containers/platform-info-container.cpp \
    core/containers/test-result-container.cpp \
    core/core/data-stream.cpp \
    core/factories/container-factory.cpp \
    gui/widgets/plot-tab.cpp \
    gui/widgets/plot.cpp \
    core/factories/color-factory.cpp \
    core/functionals/container-reader.cpp \
    core/containers/test-case-info-container.cpp \
    core/enums/architecture-type.cpp \
    core/enums/compiler-type.cpp \
    core/enums/container-type.cpp \
    core/enums/logger-type.cpp \
    core/enums/platform-type.cpp \
    core/enums/test-type.cpp \
    core/containers/version-info-container.cpp \
    core/managers/file-manager.cpp \
    core/enums/folder.cpp \
    core/enums/font-type.cpp

FORMS += \
    gui/window/main-window.ui

