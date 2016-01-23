#include <core/enums/test-type.h>

using namespace Enum;

QString Enum::name(const TestType &type) {
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

QString Enum::prettyname(const TestType &type) {
	switch (type) {
		case TestType::Base64:
			return "Base64 encoding & decoding";

		case TestType::EmptyCall:
			return "Empty function calls";

		case TestType::NaiveFactorial:
			return "Recursive factorial";

		case TestType::TailCallFactorial:
			return "Tail call factorial";

		case TestType::MergeSort:
			return "Merge sort";

		case TestType::NaiveFibonacci:
			return "Naive fibonacci";

		case TestType::NaiveNWD:
			return "Naive NWD";

		case TestType::TailCallFibonacci:
			return "Tail call fibonacci";

		case TestType::Last:
			return {};
	}

	return {};
}

uint64_t Enum::count(const TestType &type) {
	switch (type) {
		case TestType::Base64:
			return 1000000;

		case TestType::EmptyCall:
			return 100000000;

		case TestType::MergeSort:
			return 100000;

		case TestType::NaiveFactorial:
			return 1000000;

		case TestType::NaiveFibonacci:
			return 2;

		case TestType::NaiveNWD:
			return 10000000;

		case TestType::TailCallFactorial:
			return 1000000;

		case TestType::TailCallFibonacci:
			return 10000000;

		case TestType::Last:
			return 0;
	}

	return 0;
}

