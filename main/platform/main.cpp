#include <core/factories/logger-factory.h>
#include <core/factories/platform-factory.h>
#include <core/factories/test-factory.h>
#include <core/functionals/info-center.h>
#include <core/interfaces/iplatform.h>

#include <iostream>

using namespace Container;
using namespace Enum;
using namespace Factory;
using namespace Functional;

void run(const std::string &fileName, int count) {
	auto platform = PlatformFactory::create(PlatformType::Linux);
	platform->attach(LoggerFactory::create(LoggerType::RawLogger, fileName));

	for (const auto test : testsToRun())
		platform->attach(TestFactory::create(test));

	platform->run(count);
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
