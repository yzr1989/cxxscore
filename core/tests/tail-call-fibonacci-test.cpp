#include <core/tests/tail-call-fibonacci-test.h>

using namespace Test;

uint64_t TailCallFibonacciTest::fibonacci(int n, int f, int fPop) {
	if (n < 3)
		return f;

	return fibonacci(n - 1, f + fPop, f);
}

Enum::TestType TailCallFibonacciTest::type() const {
	return Enum::TestType::TailCallFibonacci;
}

uint64_t TailCallFibonacciTest::execute() {
	return fibonacci(41, 0 , 1);
}
