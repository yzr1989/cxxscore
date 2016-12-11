#pragma once

#include <string>
#include "core/types.h"

namespace Enum {

enum class CompilerType : u8 {
	Gcc,
	Clang
};

std::string name(const CompilerType &type);
std::string filename(const CompilerType &type);
}
