#include <core/factories/logger-factory.h>
#include <core/factories/platform-factory.h>
#include <core/factories/test-factory.h>
#include <core/functionals/info-center.h>
#include <core/interfaces/iplatform.h>
#include <core/managers/file-manager.h>

#include <iostream>
#include <QCoreApplication>

using namespace Container;
using namespace Enum;
using namespace Factory;
using namespace Functional;
using namespace Manager;

void run(const QString &fileName) {
	FileManager manager(QDir::homePath());
	auto core = PlatformFactory::create(PlatformType::Linux);
	core->attach(LoggerFactory::create(LoggerType::RawLogger, manager.path(Folder::Data, fileName)));

	for (std::underlying_type<TestType>::type i = 0;
	     i < static_cast<std::underlying_type<TestType>::type>(TestType::Last); ++i)
		core->attach(TestFactory::create(static_cast<TestType>(i)));

	core->run(10);
}

int main(int argc, char *argv[]) {
	QCoreApplication application(argc, argv);
	application.setApplicationName("cpp");
	CompilerInfoContainer compiler;
	PlatformInfoContainer platform;
	InfoCenter::populate(compiler);
	InfoCenter::populate(platform);
	InfoCenter::print(compiler);
	InfoCenter::print(platform);
	run(name(platform.platform()) + "-" +
	    name(platform.arch()) + "-" +
	    name(compiler.id()).toLower() + "-" +
	    compiler.constVersion().toString() + "-" +
	    compiler.checksum() + ".raw");
}
