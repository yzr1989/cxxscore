#include <core/tests/naive-factorial-test.h>

using namespace Test;

uint64_t NaiveFactorialTest::factorial(uint64_t n) {
	if (n < 2) return 1;

	return n * NaiveFactorialTest::factorial(n - 1);
}

Enum::TestType NaiveFactorialTest::type() const {
	return Enum::TestType::NaiveFactorial;
}

uint64_t NaiveFactorialTest::execute(uint64_t in) {
	return factorial(in % 256);
}
