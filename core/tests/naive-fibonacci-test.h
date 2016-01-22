#pragma once

#include <core/abstracts/abstract-test-case.h>

namespace Test {

	class NaiveFibonacciTest final : public Abstract::AbstractTestCase {
	public:
		explicit NaiveFibonacciTest() = default;
		virtual ~NaiveFibonacciTest() = default;

		virtual Enum::TestType type() const override;
		virtual uint64_t execute() override;

		static uint64_t fibonacci(uint64_t n);
	};

}
