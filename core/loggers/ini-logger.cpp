#include <core/interfaces/itestcase.h>
#include <core/loggers/ini-logger.h>

using namespace Logger;

IniLogger::IniLogger()
#ifdef __clang__
	: m_file("/home/dev/clang-output.ini", QSettings::IniFormat)
#else
	: m_file("/home/dev/gcc-output.ini", QSettings::IniFormat)
#endif

{
}

Enum::LoggerType IniLogger::type() const {
	return Enum::LoggerType::IniLogger;
}

void IniLogger::init(Interface::ITestCase *test) {
	m_file.beginGroup(QString::fromStdString(test->name()));
}

void IniLogger::done(Interface::ITestCase *test, double duration) {
	m_file.setValue("count", test->count());
	m_file.setValue("duration", duration);
	m_file.endGroup();
	m_file.sync();
}
