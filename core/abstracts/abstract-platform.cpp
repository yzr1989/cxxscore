#include <core/abstracts/abstract-platform.h>
#include <core/interfaces/itestcase.h>
#include <core/interfaces/ilogger.h>

#include <iostream>
#include <limits>
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

void AbstractPlatform::exec(Interface::ITestCase *test) {
	auto count = test->count();

	for (decltype(count) i = 0; i < count; ++i)
		test->execute(count);
}

void AbstractPlatform::done(Interface::ITestCase *test, const double duration) {
	for (auto &logger : m_loggerList)
		logger->done(test, duration);

	std::cout << "done. [" << duration << "sec]" << std::endl;
}

void AbstractPlatform::run(volatile int count) {
	m_count = count;

	for (auto &testCase : m_testCaseList) {
		ITestCase *pointer = testCase.get();
		init(pointer);
		auto duration = std::numeric_limits<double>::max();

		for (int i = 0; i < count; ++i) {
			m_elapsed.start();
			exec(pointer);
			const double last = m_elapsed.stop();
			std::cout
			    << std::to_string(i + 1)
			    << "/"
			    << std::to_string(count)
			    << ", "
			    << last
			    << "s" << std::endl;

			if (last < duration)
				duration = last;
		}

		done(pointer, duration);
	}
}

