#pragma once

#include <core/interfaces/itestcase.h>
#include <cstdint>

namespace Test {

	class FactorialTest final : public Interface::ITestCase {
	public:
		explicit FactorialTest() = default;
		virtual ~FactorialTest() = default;

		virtual Enum::TestType id() const override;
		virtual QString name() const override;
		virtual uint64_t execute() override;
		virtual uint64_t count() const override;

		static uint64_t factorial(uint64_t n);
	};

}
