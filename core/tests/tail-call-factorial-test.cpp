#include <core/tests/tail-call-factorial-test.h>

using namespace Test;

u64 TailCallFactorialTest::factorial(u64 n) {
	if (n < 2) return 1;

	return n * TailCallFactorialTest::factorial(n - 1);
}

Enum::TestType TailCallFactorialTest::type() const {
	return Enum::TestType::TailCallFactorial;
}

u64 TailCallFactorialTest::execute(u64 in) {
	return factorial(in % 256);
}
