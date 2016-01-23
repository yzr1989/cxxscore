#include <core/enums/compiler-type.h>

using namespace Enum;

QString Enum::name(const CompilerType &type) {
	switch (type) {
		case CompilerType::Clang:
			return "Clang";

		case CompilerType::Gcc:
			return "GCC";
	}

	return {};
}

QString Enum::filename(const CompilerType &type) {
	switch (type) {
		case CompilerType::Clang:
			return "clang";

		case CompilerType::Gcc:
			return "gcc";
	}

	return {};
}
