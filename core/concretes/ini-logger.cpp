#include "ini-logger.h"
#include <core/interfaces/itestcase.h>

using namespace Concrete;



IniLogger::IniLogger()
#ifdef __clang__
	: m_file("/home/dev/clang-output.ini", QSettings::IniFormat)
#else
	: m_file("/home/dev/gcc-output.ini", QSettings::IniFormat)
#endif

{
}

void IniLogger::init(Interface::ITestCase *test) {
	m_file.beginGroup(QString::fromStdString(test->name()));
	m_begin = std::chrono::system_clock::now();
}

void IniLogger::done(Interface::ITestCase *test) {
	m_end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = m_end - m_begin;
	m_file.setValue("count", test->count());
	m_file.setValue("duration", elapsed_seconds.count());
	m_file.endGroup();
	m_file.sync();
}
