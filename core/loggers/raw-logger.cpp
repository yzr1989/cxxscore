#include <core/containers/test-case-info-container.h>
#include <core/functionals/info-center.h>
#include <core/interfaces/itestcase.h>
#include <core/loggers/raw-logger.h>

using namespace Functional;
using namespace Logger;

RawLogger::RawLogger(const std::string &name)
		: m_file(name) {
}

Enum::LoggerType RawLogger::type() const {
	return Enum::LoggerType::RawLogger;
}

void RawLogger::init(Interface::ITestCase *) {
}

void RawLogger::done(Interface::ITestCase *test, double duration, const u64 ips) {
	Container::TestCaseContainer container;
	InfoCenter::populate(container.compiler());
	InfoCenter::populate(container.platform());
	container.testcase().setCount(ips);
	container.testcase().setDuration(duration);
	container.testcase().setId(test->type());
	container.testcase().setIps(ips);
	m_file.write(container);
}
