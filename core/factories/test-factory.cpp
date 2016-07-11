#include <core/factories/test-factory.h>
#include <core/tests/base64-test.h>
#include <core/tests/empty-call-test.h>
#include <core/tests/merge-sort-test.h>
#include <core/tests/naive-factorial-test.h>
#include <core/tests/naive-fibonacci-test.h>
#include <core/tests/naive-nwd-test.h>
#include <core/tests/tail-call-factorial-test.h>
#include <core/tests/tail-call-fibonacci-test.h>
#include <core/tests/lambda-test.h>
#include <core/tests/string-concate-test.h>
#include <core/tests/sieve-of-eratosthenes-test.h>
#include <core/tests/color-brightness-correction-test.h>
#include <core/tests/color-rgb-correction-test.h>

using namespace Test;
using namespace Enum;
using namespace Factory;

std::unique_ptr<Interface::ITestCase> TestFactory::create(const TestType &type) {
	switch (type) {
		case TestType::Base64:
			return std::make_unique<Base64Test>();

		case TestType::EmptyCall:
			return std::make_unique<EmptyCallTest>();

		case TestType::NaiveFactorial:
			return std::make_unique<NaiveFactorialTest>();

		case TestType::NaiveNWD:
			return std::make_unique<NaiveNWDTest>();

		case TestType::NaiveFibonacci:
			return std::make_unique<NaiveFibonacciTest>();

		case TestType::TailCallFactorial:
			return std::make_unique<TailCallFactorialTest>();

		case TestType::TailCallFibonacci:
			return std::make_unique<TailCallFibonacciTest>();

		case TestType::MergeSort:
			return std::make_unique<MergeSortTest>();

		case TestType::Lambda:
			return std::make_unique<LambdaTest>();

		case TestType::StringConcate:
			return std::make_unique<StringConcateTest>();

		case TestType::SieveOfEratosthenes:
			return std::make_unique<SieveOfEratosthenesTest>();

		case TestType::ColorBrightnessCorrection:
			return std::make_unique<ColorBrightnessCorrectionTest>();

		case TestType::ColorRGBCorrection:
			return std::make_unique<ColorRGBCorrectionTest>();

		case TestType::Last:
			return nullptr;
	}

	return nullptr;
}
