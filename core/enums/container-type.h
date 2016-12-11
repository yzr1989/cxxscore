#pragma once

#include <cstdint>

using u8 = uint8_t;

namespace Enum {

enum class ContainerType : u8 {
	CompilerInfo,
	PlatformInfo,
	TestCaseInfo,
	TestCase,
	VersionInfo
};
}
