#pragma once

#include <QString>

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

QString title(const TestType &type);
QString name(const TestType &type);
uint64_t count(const TestType &type);
}
