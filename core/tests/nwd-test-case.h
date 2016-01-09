#pragma once

#include <core/interfaces/itestcase.h>

namespace Test {

	class NWDTest final : public Interface::ITestCase {
	public:
		explicit NWDTest() = default;
		virtual ~NWDTest() = default;

		virtual Enum::TestType id() const override;
		virtual std::string name() const override;
		virtual int execute() override;
		virtual unsigned long long count() const override;
	};

}
