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
	Lambda,
	StringConcate,
	SieveOfEratosthenes,
	ColorBrightnessCorrection,
	ColorRGBCorrection,
	Last
};

QString title(const TestType &type);
QString name(const TestType &type);
}
