#pragma once

#include <cstdint>
#include <string>

namespace Enum {

	enum class TestType : uint8_t {
		Base64,
		EmptyCall,
		MergeSort,
		NaiveFactorial,
		NaiveFibonacci,
		NaiveNWD,
		TailCallFibonacci,
		TailCallFactorial,
		Last
	};

	std::string name(const TestType &type);

	uint64_t count(const TestType &type);

}
