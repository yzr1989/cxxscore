QMAKE_CFLAGS += -Werror -std=c++14
QMAKE_CXXFLAGS += -Werror -std=c++14
QMAKE_CFLAGS_RELEASE += -march=native -O3 -pipe -fomit-frame-pointer
QMAKE_CXXFLAGS_RELEASE += -march=native -O3 -pipe -fomit-frame-pointer
QMAKE_CFLAGS_DEBUG += -O1 -ggdb3 -g3 -fno-omit-frame-pointer
QMAKE_CXXFLAGS_DEBUG += -O1 -ggdb3 -g3 -fno-omit-frame-pointer
QMAKE_RESOURCE_FLAGS += -threshold 0 -compress 9
