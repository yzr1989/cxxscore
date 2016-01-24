#include <core/tests/naive-nwd-test.h>

using namespace Test;

Enum::TestType NaiveNWDTest::type() const {
	return Enum::TestType::NaiveNWD;
}

uint64_t NaiveNWDTest::execute(uint64_t in) {
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
