#include <core/factories/test-factory.h>
#include <core/tests/base64-test.h>
#include <core/tests/empty-call-test.h>
#include <core/tests/factorial-test-case.h>
#include <core/tests/fibonacci-test-case.h>
#include <core/tests/nwd-test-case.h>

using namespace Test;
using namespace Enum;
using namespace Factory;

std::unique_ptr<Interface::ITestCase> TestFactory::create(const TestType &type) {
	switch (type) {
		case TestType::Base64:
			return std::make_unique<Base64Test>();

		case TestType::EmptyCall:
			return std::make_unique<EmptyCallTest>();

		case TestType::Factorial:
			return std::make_unique<FactorialTest>();

		case TestType::NWD:
			return std::make_unique<NWDTest>();

		case TestType::Fibonacci:
			return std::make_unique<FibonacciTest>();

		case TestType::Last:
			return nullptr;
	}

	return nullptr;
}
