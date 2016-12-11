#include <core/tests/naive-fibonacci-test.h>

using namespace Test;

u64 NaiveFibonacciTest::fibonacci(u64 n) {
	if (n < 2) return n;

	return NaiveFibonacciTest::fibonacci(n - 1) + NaiveFibonacciTest::fibonacci(n - 2);
}

Enum::TestType NaiveFibonacciTest::type() const {
	return Enum::TestType::NaiveFibonacci;
}

u64 NaiveFibonacciTest::execute(u64 in) {
	return fibonacci(in % 40);
}
