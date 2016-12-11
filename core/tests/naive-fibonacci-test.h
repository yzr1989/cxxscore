#pragma once

#include <core/abstracts/abstract-test-case.h>

namespace Test {

class NaiveFibonacciTest final : public Abstract::AbstractTestCase {
public:
	explicit NaiveFibonacciTest() = default;
	virtual ~NaiveFibonacciTest() = default;

	virtual Enum::TestType type() const override;
	virtual u64 execute(u64 in) override;

	static u64 fibonacci(u64 n);
};
}
