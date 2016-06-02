#pragma once

#include <core/abstracts/abstract-test-case.h>
#include <cstdint>

namespace Test {

class TailCallFactorialTest final : public Abstract::AbstractTestCase {
public:
	explicit TailCallFactorialTest() = default;
	virtual ~TailCallFactorialTest() = default;

	virtual Enum::TestType type() const override;
	virtual uint64_t execute(uint64_t in) override;

	static uint64_t factorial(uint64_t n);
};
}
