#pragma once

#include <core/interfaces/itestcase.h>

namespace Test {

	class FibonacciTest final : public Interface::ITestCase {
	public:
		explicit FibonacciTest() = default;
		virtual ~FibonacciTest() = default;

		virtual Enum::TestType id() const override;
		virtual QString name() const override;
		virtual int execute() override;
		virtual unsigned long long count() const override;

		static long fibonacci(unsigned n);
	};

}
