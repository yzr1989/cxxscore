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

void AbstractPlatform::initTestCase(Interface::ITestCase *test) {
	for (auto &logger : m_loggerList)
		logger->init(test);

	m_elapsed.start();
	std::cout << "Running '" << name(test->type())
	          << "' test " << test->count() << " times... " << std::flush;
}

void AbstractPlatform::executeTest(Interface::ITestCase *test) {
	volatile auto count = test->count();

	for (volatile decltype(count) i = 0; i < count; ++i)
		test->execute();
}

void AbstractPlatform::doneTestCase(Interface::ITestCase *test) {
	const auto duration = m_elapsed.stop();

	for (auto &logger : m_loggerList)
		logger->done(test, duration);

	std::cout << "done. [" << duration << "sec]" << std::endl;
}

void AbstractPlatform::run() {
	for (auto &testCase : m_testCaseList) {
		ITestCase *pointer = testCase.get();
		initTestCase(pointer);
		executeTest(pointer);
		doneTestCase(pointer);
	}
}

