#pragma once

#include <core/interfaces/itestcase.h>

namespace Test {

	class EmptyCallTest final : public Interface::ITestCase {
	public:
		explicit EmptyCallTest() = default;
		virtual ~EmptyCallTest() = default;

		virtual Enum::TestType id() const override;
		virtual QString name() const override;
		virtual uint64_t execute() override;
		virtual uint64_t count() const override;
	};

}
