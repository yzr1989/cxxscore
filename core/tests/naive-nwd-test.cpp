#include <core/tests/naive-nwd-test.h>

using namespace Test;

Enum::TestType NaiveNWDTest::type() const {
	return Enum::TestType::NaiveNWD;
}

u64 NaiveNWDTest::execute(u64 in) {
	auto a = 5324;
	auto b = 31;
	auto c = 0;

	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return a + in;
}
