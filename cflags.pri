QMAKE_CFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CFLAGS_RELEASE += -std=c++14 -march=native -O3 -pipe -fomit-frame-pointer -g3 -ggdb3 -fverbose-asm
QMAKE_CXXFLAGS_RELEASE += -std=c++14 -march=native -O3 -pipe -fomit-frame-pointer -g3 -ggdb3 -fverbose-asm
QMAKE_CFLAGS_DEBUG += -Werror -std=c++14 -O3 -march=native -fno-omit-frame-pointer -g3 -ggdb3 -fverbose-asm
QMAKE_CXXFLAGS_DEBUG += -Werror -std=c++14 -O3 -march=native -fno-omit-frame-pointer -g3 -ggdb3 -fverbose-asm
QMAKE_RESOURCE_FLAGS += -threshold 0 -compress 9

DEFINES += "CXXFLAGS='$$QMAKE_CXXFLAGS_RELEASE'"

QMAKE_CFLAGS_RELEASE += -Werror
QMAKE_CXXFLAGS_RELEASE += -Werror
