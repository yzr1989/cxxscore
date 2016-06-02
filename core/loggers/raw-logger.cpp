#include <core/containers/test-case-info-container.h>
#include <core/functionals/info-center.h>
#include <core/interfaces/itestcase.h>
#include <core/loggers/raw-logger.h>
#include <QDir>

using namespace Functional;
using namespace Logger;

RawLogger::RawLogger(const QString &name)
		: m_file(name) {
}

Enum::LoggerType RawLogger::type() const {
	return Enum::LoggerType::RawLogger;
}

void RawLogger::init(Interface::ITestCase *) {
}

void RawLogger::done(Interface::ITestCase *test, double duration) {
	Container::TestCaseContainer container;
	InfoCenter::populate(container.compiler());
	InfoCenter::populate(container.platform());
	container.testcase().setCount(test->count());
	container.testcase().setDuration(duration);
	container.testcase().setId(test->type());
	m_file.write(container);
}
