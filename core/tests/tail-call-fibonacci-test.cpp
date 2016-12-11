#include <core/tests/tail-call-fibonacci-test.h>

using namespace Test;

u64 TailCallFibonacciTest::fibonacci(u64 n, u64 f, u64 fPop) {
	if (n < 3)
		return f;

	return fibonacci(n - 1, f + fPop, f);
}

Enum::TestType TailCallFibonacciTest::type() const {
	return Enum::TestType::TailCallFibonacci;
}

u64 TailCallFibonacciTest::execute(u64 in) {
	return fibonacci(in % 100, 0, 1);
}
