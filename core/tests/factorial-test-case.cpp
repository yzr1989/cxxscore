#include <core/tests/factorial-test-case.h>

using namespace Test;

uint64_t FactorialTest::factorial(uint64_t n) {
	if (n < 2) return 1;

	return n * FactorialTest::factorial(n - 1);
}

Enum::TestType FactorialTest::id() const {
	return Enum::TestType::Factorial;
}

QString FactorialTest::name() const {
	return "Factorial";
}

uint64_t FactorialTest::execute() {
	return factorial(256);
}

uint64_t FactorialTest::count() const {
	return 100000000;
}


