#include <core/tests/empty-call-test.h>

using namespace Test;

Enum::TestType EmptyCallTest::id() const {
	return Enum::TestType::EmptyCall;
}

QString EmptyCallTest::name() const {
	return "EmptyCall";
}

uint64_t EmptyCallTest::execute() {
	return 0;
}

uint64_t EmptyCallTest::count() const {
	return 1000000000;
}
