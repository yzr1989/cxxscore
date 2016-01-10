#include <core/tests/fibonacci-test-case.h>

using namespace Test;

uint64_t FibonacciTest::fibonacci(uint64_t n) {
	if (n < 2) return n;

	return FibonacciTest::fibonacci(n - 1) + FibonacciTest::fibonacci(n - 2);
}

Enum::TestType FibonacciTest::id() const {
	return Enum::TestType::Fibonacci;
}

QString FibonacciTest::name() const {
	return "Fibonacci";
}

uint64_t FibonacciTest::execute() {
	return fibonacci(41);
}

uint64_t FibonacciTest::count() const {
	return 5;
}


