#include <core/interfaces/itestcase.h>
#include <core/loggers/ini-logger.h>
#include <core/functionals/compiler-info.h>

#include <QDir>

using namespace Logger;

IniLogger::IniLogger(const QString &name)
	: m_file(QDir::homePath() + "/" + name, QSettings::IniFormat)


{
}

Enum::LoggerType IniLogger::type() const {
	return Enum::LoggerType::IniLogger;
}

void IniLogger::init(Interface::ITestCase *test) {
	m_file.beginGroup(test->name());
}

void IniLogger::done(Interface::ITestCase *test, double duration) {
	m_file.setValue("count", static_cast<quint64>(test->count()));
	m_file.setValue("duration", duration);
	m_file.endGroup();
	m_file.sync();
}
