#pragma once

#include <core/abstracts/abstract-test-case.h>

namespace Test {

	class TailCallFibonacciTest final : public Abstract::AbstractTestCase {
	public:
		explicit TailCallFibonacciTest() = default;
		virtual ~TailCallFibonacciTest() = default;

		virtual Enum::TestType type() const override;
		virtual uint64_t execute() override;

		static uint64_t fibonacci(int n, int f = 0, int fPop = 1);
	};

}
