#pragma once

#include <string>
#include "core/types.h"

namespace Enum {

enum class Folder : u8 {
	Data,
	Plot
};

std::string name(const Folder &folder);
}
