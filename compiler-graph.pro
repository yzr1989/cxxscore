QT += core gui widgets printsupport

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
    core/enums/container-type-enum.h \
    core/factories/container-factory.h \
    gui/widgets/plot-tab.h \
    gui/widgets/plot.h \
    core/factories/color-factory.h \
    core/functionals/container-reader.h \
    core/containers/test-case-info-container.h

SOURCES += \
    gui/window/main-window.cpp \
    main/graph/main.cpp \
    core/abstracts/abstract-container.cpp \
    core/containers/compiler-info-container.cpp \
    core/containers/platform-info-container.cpp \
    core/containers/test-result-container.cpp \
    core/core/data-stream.cpp \
    core/enums/container-type-enum.cpp \
    core/factories/container-factory.cpp \
    gui/widgets/plot-tab.cpp \
    gui/widgets/plot.cpp \
    core/factories/color-factory.cpp \
    core/functionals/container-reader.cpp \
    core/containers/test-case-info-container.cpp

FORMS += \
    gui/window/main-window.ui

