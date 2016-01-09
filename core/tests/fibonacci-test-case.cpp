#include <core/tests/fibonacci-test-case.h>

using namespace TestCase;


long FibonacciTestCase::fibonacci(unsigned n) {
	if (n < 2) return n;

	return FibonacciTestCase::fibonacci(n - 1) + FibonacciTestCase::fibonacci(n - 2);
}

Enum::TestCaseId FibonacciTestCase::id() const {
	return Enum::TestCaseId::Fibonacci;
}

std::string FibonacciTestCase::name() const {
	return "Fibonacci";
}

int FibonacciTestCase::execute() {
	return fibonacci(41);
}

int FibonacciTestCase::count() const {
	return 5;
}


