#pragma once

#include <string>
#include "core/types.h"

namespace Enum {

enum class TestType : u8 {
	Base64,
	EmptyCall,
	MergeSort,
	NaiveFactorial,
	NaiveFibonacci,
	NaiveNWD,
	TailCallFibonacci,
	TailCallFactorial,
	Lambda,
	StringConcate,
	SieveOfEratosthenes,
	ColorBrightnessCorrection,
	ColorRGBCorrection,
	Last
};

std::string title(const TestType &type);
std::string name(const TestType &type);
}
