#include <core/tests/empty-call-test.h>

using namespace Test;

Enum::TestType EmptyCallTest::type() const {
	return Enum::TestType::EmptyCall;
}

u64 EmptyCallTest::execute(u64 in) {
	return in;
}
