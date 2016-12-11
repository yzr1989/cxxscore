#pragma once

#include <string>

namespace Enum {

enum class PlatformType : uint8_t {
	Linux
};

std::string name(const PlatformType &type);
std::string filename(const PlatformType &type);
}
