project(cxxbench)
cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -Werror -Wpedantic -Wfloat-equal")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -save-temps -fverbose-asm")

configure_file(config.h.in config.h)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 9)
set(VERSION_MINOR 0)

include_directories(
	${CMAKE_CURRENT_BINARY_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}
)

set(sources
	core/abstracts/abstract-container.cpp
	core/abstracts/abstract-container.h
	core/abstracts/abstract-platform.cpp
	core/abstracts/abstract-platform.h
	core/abstracts/abstract-test-case.cpp
	core/abstracts/abstract-test-case.h
	core/containers/compiler-info-container.cpp
	core/containers/compiler-info-container.h
	core/containers/platform-info-container.cpp
	core/containers/platform-info-container.h
	core/containers/test-case-info-container.cpp
	core/containers/test-case-info-container.h
	core/containers/test-result-container.cpp
	core/containers/test-result-container.h
	core/containers/version-info-container.cpp
	core/containers/version-info-container.h
	core/core/data-stream.cpp
	core/core/data-stream.h
	core/enums/architecture-type.cpp
	core/enums/architecture-type.h
	core/enums/compiler-type.cpp
	core/enums/compiler-type.h
	core/enums/container-type.cpp
	core/enums/container-type.h
	core/enums/folder.cpp
	core/enums/folder.h
	core/enums/logger-type.cpp
	core/enums/logger-type.h
	core/enums/platform-type.cpp
	core/enums/platform-type.h
	core/enums/test-type.cpp
	core/enums/test-type.h
	core/factories/container-factory.cpp
	core/factories/container-factory.h
	core/factories/logger-factory.cpp
	core/factories/logger-factory.h
	core/factories/platform-factory.cpp
	core/factories/platform-factory.h
	core/factories/test-factory.cpp
	core/factories/test-factory.h
	core/functionals/container-reader.cpp
	core/functionals/container-reader.h
	core/functionals/container-writer.cpp
	core/functionals/container-writer.h
	core/functionals/elapsed-time.cpp
	core/functionals/elapsed-time.h
	core/functionals/info-center.cpp
	core/functionals/info-center.h
	core/interfaces/ilogger.cpp
	core/interfaces/ilogger.h
	core/interfaces/iplatform.cpp
	core/interfaces/iplatform.h
	core/interfaces/itestcase.cpp
	core/interfaces/itestcase.h
	core/interfaces/templates/itemplate-attach.cpp
	core/interfaces/templates/itemplate-attach.h
	core/loggers/raw-logger.cpp
	core/loggers/raw-logger.h
	core/platforms/linux-platform.cpp
	core/platforms/linux-platform.h
	main/platform/main.cpp
)

set(tests
	core/tests/base64-test.cpp
	core/tests/base64-test.h
	core/tests/color-brightness-correction-test.cpp
	core/tests/color-brightness-correction-test.h
	core/tests/color-rgb-correction-test.cpp
	core/tests/color-rgb-correction-test.h
	core/tests/empty-call-test.cpp
	core/tests/empty-call-test.h
	core/tests/lambda-test.cpp
	core/tests/lambda-test.h
	core/tests/merge-sort-test.cpp
	core/tests/merge-sort-test.h
	core/tests/naive-factorial-test.cpp
	core/tests/naive-factorial-test.h
	core/tests/naive-fibonacci-test.cpp
	core/tests/naive-fibonacci-test.h
	core/tests/naive-nwd-test.cpp
	core/tests/naive-nwd-test.h
	core/tests/sieve-of-eratosthenes-test.cpp
	core/tests/sieve-of-eratosthenes-test.h
	core/tests/string-concate-test.cpp
	core/tests/string-concate-test.h
	core/tests/tail-call-factorial-test.cpp
	core/tests/tail-call-factorial-test.h
	core/tests/tail-call-fibonacci-test.cpp
	core/tests/tail-call-fibonacci-test.h
)

add_executable(cxxbench ${sources} ${tests})

install(TARGETS cxxbench DESTINATION ${CMAKE_INSTALL_PREFIX}/bin/)
