#pragma once

#include <core/interfaces/itestcase.h>

namespace TestCase {

	class FibonacciTestCase final : public Interface::ITestCase {
	public:
		explicit FibonacciTestCase() = default;
		virtual ~FibonacciTestCase() = default;

		virtual Enum::TestCaseId id() const override;
		virtual std::string name() const override;
		virtual int execute() override;
		virtual int count() const override;

		static long fibonacci(unsigned n);
	};

}
