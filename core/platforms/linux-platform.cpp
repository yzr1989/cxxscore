#include <core/platforms/linux-platform.h>

using namespace Platform;

Enum::PlatformType LinuxPlatform::type() const {
	return Enum::PlatformType::Linux;
}
