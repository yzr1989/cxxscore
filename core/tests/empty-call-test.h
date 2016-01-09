#pragma once

#include <core/interfaces/itestcase.h>

namespace Test {

	class EmptyCallTest final : public Interface::ITestCase {
	public:
		explicit EmptyCallTest() = default;
		virtual ~EmptyCallTest() = default;

		virtual Enum::TestType id() const override;
		virtual std::string name() const override;
		virtual int execute() override;
		virtual unsigned long long count() const override;
	};

}
