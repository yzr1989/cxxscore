#pragma once

#include <core/abstracts/abstract-test-case.h>

namespace Test {

	class TailCallFibonacciTest final : public Abstract::AbstractTestCase {
	public:
		explicit TailCallFibonacciTest() = default;
		virtual ~TailCallFibonacciTest() = default;

		virtual Enum::TestType type() const override;
		virtual uint64_t execute(uint64_t in) override;

		static uint64_t fibonacci(uint64_t n, uint64_t f = 0, uint64_t fPop = 1);
	};

}
