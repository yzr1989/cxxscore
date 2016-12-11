#include <core/factories/logger-factory.h>
#include <core/factories/platform-factory.h>
#include <core/factories/test-factory.h>
#include <core/functionals/info-center.h>
#include <core/interfaces/iplatform.h>
#include <core/managers/file-manager.h>

#include <iostream>

using namespace Container;
using namespace Enum;
using namespace Factory;
using namespace Functional;
using namespace Manager;

void run(const std::string &fileName, int count) {
	FileManager manager("/home/dev/");
	auto core = PlatformFactory::create(PlatformType::Linux);
	core->attach(LoggerFactory::create(LoggerType::RawLogger, manager.path(Folder::Data, fileName)));

	for (std::underlying_type<TestType>::type i = 0;
		 i < static_cast<std::underlying_type<TestType>::type>(TestType::Last); ++i)
		core->attach(TestFactory::create(static_cast<TestType>(i)));

	core->run(count);
}

int main(int argc, char *argv[]) {
	CompilerInfoContainer compiler;
	PlatformInfoContainer platform;
	InfoCenter::populate(compiler);
	InfoCenter::populate(platform);
	InfoCenter::print(compiler);
	InfoCenter::print(platform);
	int count = 5;

	if (argc > 1)
		count = std::atoi(argv[1]);

	run(name(platform.platform()) + "-" +
			name(platform.arch()) + "-" +
			name(compiler.id()) + "-" +
			compiler.constVersion().toString() + "-" +
			compiler.flags() + ".raw",
		count);
}
