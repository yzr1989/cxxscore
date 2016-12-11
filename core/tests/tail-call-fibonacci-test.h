#pragma once

#include <core/abstracts/abstract-test-case.h>

namespace Test {

class TailCallFibonacciTest final : public Abstract::AbstractTestCase {
public:
	explicit TailCallFibonacciTest() = default;
	virtual ~TailCallFibonacciTest() = default;

	virtual Enum::TestType type() const override;
	virtual u64 execute(u64 in) override;

	static u64 fibonacci(u64 n, u64 f = 0, u64 fPop = 1);
};
}
