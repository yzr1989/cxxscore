#include <core/tests/lambda-test.h>

using namespace Test;

Enum::TestType LambdaTest::type() const { return Enum::TestType::Lambda; }

uint64_t LambdaTest::execute(uint64_t in) {
	auto add = [](uint64_t value) { return value + 1; };
	auto dec = [](uint64_t value) { return value - 1; };
	auto mul = [](uint64_t x, uint64_t y) { return x * y; };

	return mul(add(in), dec(in));
}
