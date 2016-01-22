#include <core/enums/test-type-enum.h>

using namespace Enum;

std::string Enum::name(const TestType &type) {
	switch (type) {
		case TestType::Base64:
			return "Base64";

		case TestType::EmptyCall:
			return "EmptyCall";

		case TestType::NaiveFactorial:
			return "NaiveFactorial";

		case TestType::TailCallFactorial:
			return "TailCallFactorial";

		case TestType::MergeSort:
			return "MergeSort";

		case TestType::NaiveFibonacci:
			return "NaiveFibonacci";

		case TestType::NaiveNWD:
			return "NaiveNWD";

		case TestType::TailCallFibonacci:
			return "TailCallFibonacci";

		case TestType::Last:
			return {};
	}

	return {};
}

uint64_t Enum::count(const TestType &type) {
	switch (type) {
		case TestType::Base64:
			return 10000000;

		case TestType::EmptyCall:
			return 1000000000;

		case TestType::MergeSort:
			return 1000000;

		case TestType::NaiveFactorial:
			return 10000000;

		case TestType::NaiveFibonacci:
			return 5;

		case TestType::NaiveNWD:
			return 100000000;

		case TestType::TailCallFactorial:
			return 10000000;

		case TestType::TailCallFibonacci:
			return 100000000;

		case TestType::Last:
			return 0;
	}

	return 0;
}
