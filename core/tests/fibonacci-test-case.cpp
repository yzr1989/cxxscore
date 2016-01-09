#include <core/tests/fibonacci-test-case.h>

using namespace Test;

long FibonacciTest::fibonacci(unsigned n) {
	if (n < 2) return n;

	return FibonacciTest::fibonacci(n - 1) + FibonacciTest::fibonacci(n - 2);
}

Enum::TestType FibonacciTest::id() const {
	return Enum::TestType::Fibonacci;
}

std::string FibonacciTest::name() const {
	return "Fibonacci";
}

int FibonacciTest::execute() {
	return fibonacci(41);
}

unsigned long long FibonacciTest::count() const {
	return 5;
}


