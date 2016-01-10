QMAKE_CFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CFLAGS_RELEASE += -Werror -std=c++14 -march=native -O3 -pipe -fomit-frame-pointer
QMAKE_CXXFLAGS_RELEASE += -Werror -std=c++14 -march=native -O3 -pipe -fomit-frame-pointer
QMAKE_CFLAGS_DEBUG += -Werror -std=c++14 -O1 -ggdb3 -g3 -fno-omit-frame-pointer
QMAKE_CXXFLAGS_DEBUG += -Werror -std=c++14 -O1 -ggdb3 -g3 -fno-omit-frame-pointer
QMAKE_RESOURCE_FLAGS += -threshold 0 -compress 9

DEFINES += "CXXFLAGS='$$QMAKE_CXXFLAGS_RELEASE'"
