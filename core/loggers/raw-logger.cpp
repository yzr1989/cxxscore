#include <core/containers/test-case-info-container.h>
#include <core/functionals/compiler-info.h>
#include <core/functionals/platform-info.h>
#include <core/interfaces/itestcase.h>
#include <core/loggers/raw-logger.h>
#include <QDir>

using namespace Functional;
using namespace Logger;

RawLogger::RawLogger(const QString &name)
	: m_file(QDir::homePath() + "/" + name) {
}

Enum::LoggerType RawLogger::type() const {
	return Enum::LoggerType::RawLogger;
}

void RawLogger::init(Interface::ITestCase *) {
}

void RawLogger::done(Interface::ITestCase *test, double duration) {
	Container::TestCaseContainer container;
	container.compiler() = CompilerInfo::info();
	container.platform() = PlatformInfo::info();
	container.testcase().setCount(test->count());
	container.testcase().setDuration(duration);
	container.testcase().setName(QString::fromStdString(name(test->type())));
	m_file.write(container);
}
