#include <core/tests/nwd-test-case.h>

using namespace Test;

Enum::TestType NWDTest::id() const {
	return Enum::TestType::NWD;
}

QString NWDTest::name() const {
	return "NWD";
}

uint64_t NWDTest::execute() {
	auto a = 5324;
	auto b = 31;
	auto c = 0;

	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

uint64_t NWDTest::count() const {
	return 500000000;
}
