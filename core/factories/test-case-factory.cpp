#include <core/factories/test-case-factory.h>
#include <core/tests/nwd-test-case.h>
#include <core/tests/fibonacci-test-case.h>

using namespace Factory;
using namespace Enum;

std::unique_ptr<Interface::ITestCase> TestCaseFactory::create(const TestCaseId &id) {
	switch (id) {
		case TestCaseId::NWD:
			return std::make_unique<TestCase::NWDTestCase>();

		case TestCaseId::Fibonacci:
			return std::make_unique<TestCase::FibonacciTestCase>();

		case TestCaseId::Last:
			return nullptr;
	}

	return nullptr;
}
