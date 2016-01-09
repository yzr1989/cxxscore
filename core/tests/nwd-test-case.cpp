#include <core/tests/nwd-test-case.h>

using namespace TestCase;

Enum::TestCaseId NWDTestCase::id() const {
	return Enum::TestCaseId::NWD;
}

std::string NWDTestCase::name() const {
	return "NWD";
}

int NWDTestCase::execute() {
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

int NWDTestCase::count() const {
	return 500000000;
}
