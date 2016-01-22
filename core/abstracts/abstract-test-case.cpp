#include <core/abstracts/abstract-test-case.h>

using namespace Abstract;

uint64_t AbstractTestCase::count() const {
	return Enum::count(type());
}
