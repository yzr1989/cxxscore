#include <core/tests/tail-call-factorial-test.h>

using namespace Test;

uint64_t TailCallFactorialTest::factorial(uint64_t n) {
	if (n < 2) return 1;

	return n * TailCallFactorialTest::factorial(n - 1);
}

Enum::TestType TailCallFactorialTest::type() const {
	return Enum::TestType::TailCallFactorial;
}

uint64_t TailCallFactorialTest::execute(uint64_t in) {
	return factorial(in % 256);
}
