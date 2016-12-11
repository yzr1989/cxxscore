#include <core/tests/naive-factorial-test.h>

using namespace Test;

u64 NaiveFactorialTest::factorial(u64 n) {
	if (n < 2) return 1;

	return n * NaiveFactorialTest::factorial(n - 1);
}

Enum::TestType NaiveFactorialTest::type() const {
	return Enum::TestType::NaiveFactorial;
}

u64 NaiveFactorialTest::execute(u64 in) {
	return factorial(in % 256);
}
