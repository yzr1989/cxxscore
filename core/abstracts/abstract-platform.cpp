#include <core/abstracts/abstract-platform.h>
#include <core/interfaces/itestcase.h>
#include <core/interfaces/ilogger.h>

#include <iostream>

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

	m_elapsed.start();
	std::cout << "Running '" << name(test->type()).toStdString()
	          << "' test " << test->count() << " iterations... " << std::flush;
}

void AbstractPlatform::exec(Interface::ITestCase *test) {
	volatile auto count = test->count();

	for (volatile decltype(count) i = 0; i < count; ++i)
		test->execute();
}

void AbstractPlatform::done(Interface::ITestCase *test) {
	const auto duration = m_elapsed.stop() / static_cast<double>(m_count);

	for (auto &logger : m_loggerList)
		logger->done(test, duration);

	std::cout << "done. [" << duration << "sec]" << std::endl;
}

void AbstractPlatform::run(volatile int count) {
	m_count = count;

	for (auto &testCase : m_testCaseList) {
		ITestCase *pointer = testCase.get();
		init(pointer);

		for (int i = 0; i < count; ++i)
			exec(pointer);

		done(pointer);
	}
}

