#include <core/abstracts/abstract-platform.h>
#include <core/interfaces/itestcase.h>
#include <core/interfaces/ilogger.h>

#include <iostream>
#include <limits>
#include <time.h>

using namespace Abstract;
using namespace Interface;

AbstractPlatform::AbstractPlatform() {
}

AbstractPlatform::~AbstractPlatform() {
}

void AbstractPlatform::attach(std::unique_ptr<ITestCase> &&object) {
	m_testCaseList.push_back(std::move(object));
}

void AbstractPlatform::attach(std::unique_ptr<ILogger> &&object) {
	m_loggerList.push_back(std::move(object));
}

void AbstractPlatform::init(Interface::ITestCase *test) {
	for (auto &logger : m_loggerList)
		logger->init(test);

	std::cout
		<< "Running '"
		<< name(test->type()).toStdString()
		<< "' test "
		<< test->count()
		<< " iterations... "
		<< std::endl
		<< std::flush;
}

uint64_t AbstractPlatform::exec(Interface::ITestCase *test) {
	volatile uint64_t ir = 0;

	struct timespec time_b;
	struct timespec time_e;

	clock_gettime(CLOCK_MONOTONIC, &time_b);

	do {
		test->execute(++ir);
		clock_gettime(CLOCK_MONOTONIC, &time_e);

	} while((time_e.tv_sec - time_b.tv_sec) < 1);

	return ir;
}

void AbstractPlatform::done(Interface::ITestCase *test, const double duration, const uint64_t ir) {
	for (auto &logger : m_loggerList)
		logger->done(test, duration, ir);

	std::cout << "done. [" << duration << "sec]" << "[" << ir << "]" << std::endl;
}

void AbstractPlatform::run(volatile int count) {
	m_count = count;

	for (auto &testCase : m_testCaseList) {
		ITestCase *pointer = testCase.get();
		init(pointer);
		auto min_ir = std::numeric_limits<uint64_t>::max();

		for (int i = 0; i < count; ++i) {
			m_elapsed.start();
			uint64_t ir = exec(pointer);
			const double last = m_elapsed.stop();
			std::cout
				<< std::to_string(i + 1)
				<< "/"
				<< std::to_string(count)
				<< ", "
				<< last
				<< "s" << std::endl;

			min_ir = std::min(min_ir, ir);
		}

		done(pointer, 5, min_ir);
	}
}
