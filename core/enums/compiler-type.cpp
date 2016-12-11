#include <core/enums/compiler-type.h>

using namespace Enum;

std::string Enum::name(const CompilerType &type) {
	switch (type) {
		case CompilerType::Clang: return "Clang";
		case CompilerType::Gcc: return "GCC";
	}

	return {};
}

std::string Enum::filename(const CompilerType &type) {
	switch (type) {
		case CompilerType::Clang:
			return "clang";

		case CompilerType::Gcc:
			return "gcc";
	}

	return {};
}
