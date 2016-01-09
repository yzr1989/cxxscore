#include <core/abstracts/abstract-platform.h>
#include <core/interfaces/itestcase.h>
#include <core/interfaces/ilogger.h>

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
}

void AbstractPlatform::executeTest(Interface::ITestCase *test) {
	const int count = test->count();

	for (volatile int i = 0; i < count; ++i)
		test->execute();
}

void AbstractPlatform::doneTestCase(Interface::ITestCase *test) {
	if (m_logger)
		m_logger->done(test);
}

void AbstractPlatform::run() {
	for (auto &testCase : m_testCaseList) {
		ITestCase *pointer = testCase.get();
		initTestCase(pointer);
		executeTest(pointer);
		doneTestCase(pointer);
	}
}

