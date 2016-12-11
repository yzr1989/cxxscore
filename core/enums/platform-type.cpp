#include <core/enums/platform-type.h>

using namespace Enum;

std::string Enum::name(const PlatformType &type) {
	switch (type) {
		case PlatformType::Linux: return "Linux";
	}

	return {};
}

std::string filename(const PlatformType &type) {
	return name(type);
}
