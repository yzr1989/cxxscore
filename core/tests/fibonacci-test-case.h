#pragma once

#include <core/interfaces/itestcase.h>

namespace Test {

	class FibonacciTest final : public Interface::ITestCase {
	public:
		explicit FibonacciTest() = default;
		virtual ~FibonacciTest() = default;

		virtual Enum::TestType id() const override;
		virtual QString name() const override;
		virtual uint64_t execute() override;
		virtual uint64_t count() const override;

		static uint64_t fibonacci(uint64_t n);
	};

}
