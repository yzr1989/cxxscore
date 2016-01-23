#include <core/enums/architecture-type.h>

using namespace Enum;

QString Enum::name(const ArchitectureType &type) {
	switch (type) {
		case ArchitectureType::ARM:
			return "ARM";

		case ArchitectureType::x86:
			return "x86";

		case ArchitectureType::x86_64:
			return "x86_64";
	}

	return {};
}
