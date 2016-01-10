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
	m_logger = std::move(object);
}

void AbstractPlatform::initTestCase(Interface::ITestCase *test) {
	if (m_logger)
		m_logger->init(test);

	m_elapsed.start();
	std::cout << "Running '" << test->name().toStdString()
						<< "' test " << test->count() << " times... " << std::flush;
}

void AbstractPlatform::executeTest(Interface::ITestCase *test) {
	auto count = test->count();

	for (volatile decltype(count) i = 0; i < count; ++i)
		test->execute();
}

void AbstractPlatform::doneTestCase(Interface::ITestCase *test) {
	const auto duration = m_elapsed.stop();

	if (m_logger)
		m_logger->done(test, duration);

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

