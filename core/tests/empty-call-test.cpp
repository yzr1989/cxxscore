#include <core/tests/empty-call-test.h>

using namespace Test;

Enum::TestType EmptyCallTest::type() const {
	return Enum::TestType::EmptyCall;
}

uint64_t EmptyCallTest::execute(uint64_t in) {
	return in;
}
