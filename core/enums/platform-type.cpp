#include <core/enums/platform-type.h>

using namespace Enum;

QString Enum::name(const PlatformType &type) {
	switch (type) {
		case PlatformType::Linux: return "Linux";
	}

	return {};
}

QString filename(const PlatformType &type) {
	return name(type).toLower();
}
