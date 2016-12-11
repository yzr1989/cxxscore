#pragma once

#include "core/types.h"

namespace Enum {

enum class ArchitectureType : u8 {
	ARM,
	x86,
	x86_64
};

constexpr auto name(const ArchitectureType &type) {
	switch (type) {
		case ArchitectureType::ARM: return "ARM";
		case ArchitectureType::x86: return "x86";
		case ArchitectureType::x86_64: return "x86_64";
	}
	return "";
}
}
