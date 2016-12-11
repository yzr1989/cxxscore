#pragma once

#include <core/abstracts/abstract-test-case.h>
#include <cstdint>

namespace Test {

class TailCallFactorialTest final : public Abstract::AbstractTestCase {
public:
	explicit TailCallFactorialTest() = default;
	virtual ~TailCallFactorialTest() = default;

	virtual Enum::TestType type() const override;
	virtual u64 execute(u64 in) override;

	static u64 factorial(u64 n);
};
}
