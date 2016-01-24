#include <core/tests/tail-call-fibonacci-test.h>

using namespace Test;

uint64_t TailCallFibonacciTest::fibonacci(uint64_t n, uint64_t f, uint64_t fPop) {
	if (n < 3)
		return f;

	return fibonacci(n - 1, f + fPop, f);
}

Enum::TestType TailCallFibonacciTest::type() const {
	return Enum::TestType::TailCallFibonacci;
}

uint64_t TailCallFibonacciTest::execute(uint64_t in) {
	return fibonacci(in % 100, 0 , 1);
}
