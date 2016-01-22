#include <core/tests/naive-fibonacci-test.h>

using namespace Test;

uint64_t NaiveFibonacciTest::fibonacci(uint64_t n) {
	if (n < 2) return n;

	return NaiveFibonacciTest::fibonacci(n - 1) + NaiveFibonacciTest::fibonacci(n - 2);
}

Enum::TestType NaiveFibonacciTest::type() const {
	return Enum::TestType::NaiveFibonacci;
}

uint64_t NaiveFibonacciTest::execute() {
	return fibonacci(41);
}
