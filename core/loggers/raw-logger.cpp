#include <core/containers/test-result-container.h>
#include <core/functionals/compiler-info.h>
#include <core/functionals/platform-info.h>
#include <core/interfaces/itestcase.h>
#include <core/loggers/raw-logger.h>
#include <QDir>

using namespace Logger;

RawLogger::RawLogger(const QString &name)
	: m_file(QDir::homePath() + "/" + name) {
	m_file.write(Functional::CompilerInfo::info());
	m_file.write(Functional::PlatformInfo::info());
}

Enum::LoggerType RawLogger::type() const {
	return Enum::LoggerType::RawLogger;
}

void RawLogger::init(Interface::ITestCase *) {
}

void RawLogger::done(Interface::ITestCase *test, double duration) {
	Container::TestResultContainer container;
	container.setName(test->name());
	container.setCount(test->count());
	container.setDuration(duration);
	m_file.write(container);
}
