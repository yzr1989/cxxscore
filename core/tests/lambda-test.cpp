#include <core/tests/lambda-test.h>

using namespace Test;

Enum::TestType LambdaTest::type() const { return Enum::TestType::Lambda; }

u64 LambdaTest::execute(u64 in) {
	auto add = [](u64 value) { return value + 1; };
	auto dec = [](u64 value) { return value - 1; };
	auto mul = [](u64 x, u64 y) { return x * y; };

	return mul(add(in), dec(in));
}
