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
	ColorRGBCorrection
};

constexpr auto testsToRun() -> std::initializer_list<const TestType> {
	return {
		TestType::Base64,
		TestType::EmptyCall,
		TestType::MergeSort,
		TestType::NaiveFactorial,
		TestType::NaiveFibonacci,
		TestType::NaiveNWD,
		TestType::TailCallFibonacci,
		TestType::TailCallFactorial,
		TestType::Lambda,
		TestType::StringConcate,
		TestType::SieveOfEratosthenes,
		TestType::ColorBrightnessCorrection,
		TestType::ColorRGBCorrection,
	};
}

std::string title(const TestType &type);
std::string name(const TestType &type);
}
