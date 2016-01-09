#include <QCoreApplication>
#include <core/concretes/linux-platform.h>
#include <core/concretes/ini-logger.h>
#include <core/factories/test-case-factory.h>

using namespace Concrete;
using namespace Factory;

int main(int argc, char *argv[]) {
	QCoreApplication application(argc, argv);
	std::unique_ptr<Interface::ILogger> logger(new IniLogger());
	LinuxPlatform platform;
	platform.attach(std::move(logger));

	for (size_t i = 0; i < static_cast<size_t>(Enum::TestCaseId::Last); ++i)
		platform.attach(TestCaseFactory::create(static_cast<Enum::TestCaseId>(i)));

	platform.run();
}
