#pragma once

#include <core/interfaces/itestcase.h>

namespace Test {

	class MergeSortTest final : public Interface::ITestCase {
	public:
		explicit MergeSortTest() = default;
		virtual ~MergeSortTest() = default;

		virtual Enum::TestType id() const override;
		virtual QString name() const override;
		virtual uint64_t execute() override;
		virtual uint64_t count() const override;
	};

}
