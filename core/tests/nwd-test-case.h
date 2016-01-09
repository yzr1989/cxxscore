#pragma once

#include <core/interfaces/itestcase.h>

namespace TestCase {

	class NWDTestCase final : public Interface::ITestCase {
	public:
		explicit NWDTestCase() = default;
		virtual ~NWDTestCase() = default;

		virtual Enum::TestCaseId id() const override;
		virtual std::string name() const override;
		virtual int execute() override;
		virtual int count() const override;
	};

}
