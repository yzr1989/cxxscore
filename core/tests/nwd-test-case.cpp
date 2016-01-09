#include <core/tests/nwd-test-case.h>

using namespace Test;

Enum::TestType NWDTest::id() const {
	return Enum::TestType::NWD;
}

std::string NWDTest::name() const {
	return "NWD";
}

int NWDTest::execute() {
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

unsigned long long NWDTest::count() const {
	return 500000000;
}
