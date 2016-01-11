#pragma once

#include <core/interfaces/itestcase.h>

namespace Test {

	class Base64Test final : public Interface::ITestCase {
	public:
		explicit Base64Test() = default;
		virtual ~Base64Test() = default;

		virtual Enum::TestType id() const override;
		virtual QString name() const override;
		virtual uint64_t execute() override;
		virtual uint64_t count() const override;


	};

}
