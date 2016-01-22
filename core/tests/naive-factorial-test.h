#pragma once

#include <core/abstracts/abstract-test-case.h>
#include <cstdint>

namespace Test {

	class NaiveFactorialTest final : public Abstract::AbstractTestCase {
	public:
		explicit NaiveFactorialTest() = default;
		virtual ~NaiveFactorialTest() = default;

		virtual Enum::TestType type() const override;
		virtual uint64_t execute() override;

		static uint64_t factorial(uint64_t n);
	};

}
