#include <core/tests/empty-call-test.h>

using namespace Test;

Enum::TestType EmptyCallTest::id() const {
	return Enum::TestType::EmptyCall;
}

std::string EmptyCallTest::name() const {
	return "EmptyCall";
}

int EmptyCallTest::execute() {
	return 0;
}

unsigned long long EmptyCallTest::count() const {
	return 1000000000;
}
