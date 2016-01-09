#include <core/factories/platform-factory.h>
#include <core/platforms/linux-platform.h>

using namespace Factory;
using namespace Enum;

std::unique_ptr<Abstract::AbstractPlatform> PlatformFactory::create(const PlatformType &type) {
	switch (type) {
		case PlatformType::Linux:
			return std::make_unique<Platform::LinuxPlatform>();
	}

	return nullptr;
}


