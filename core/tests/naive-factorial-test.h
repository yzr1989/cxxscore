#pragma once

#include <core/abstracts/abstract-test-case.h>

namespace Test {

class NaiveFactorialTest final : public Abstract::AbstractTestCase {
public:
	explicit NaiveFactorialTest() = default;
	virtual ~NaiveFactorialTest() = default;

	virtual Enum::TestType type() const override;
	virtual u64 execute(u64 in) override;

	static u64 factorial(u64 n);
};
}
