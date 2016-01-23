#include <QCoreApplication>
#include <core/factories/logger-factory.h>
#include <core/factories/platform-factory.h>
#include <core/factories/test-factory.h>
#include <core/functionals/compiler-info.h>
#include <core/functionals/platform-info.h>
#include <core/interfaces/iplatform.h>
#include <core/managers/file-manager.h>
#include <iostream>

using namespace Enum;
using namespace Factory;

int main(int argc, char *argv[]) {
	QCoreApplication application(argc, argv);
	application.setApplicationName("cpp");
	Functional::CompilerInfo::printInfo();
	Functional::PlatformInfo::printInfo();
	Manager::FileManager manager(QDir::homePath());
	QString outputFile =
	  manager.path(Enum::Folder::Data,
	               Functional::PlatformInfo::info().name() + "-" +
	               Functional::PlatformInfo::info().arch() + "-" +
	               filename(Functional::CompilerInfo::info().id()) + "-" +
	               Functional::CompilerInfo::info().version().toString() + "-" +
	               QCoreApplication::applicationName() + ".raw");
	auto platform = PlatformFactory::create(PlatformType::Linux);
	platform->attach(LoggerFactory::create(LoggerType::RawLogger, outputFile));

	for (std::underlying_type<Enum::TestType>::type i = 0;
	     i < static_cast<std::underlying_type<Enum::TestType>::type>(Enum::TestType::Last); ++i)
		platform->attach(TestFactory::create(static_cast<Enum::TestType>(i)));

	platform->run();
}
