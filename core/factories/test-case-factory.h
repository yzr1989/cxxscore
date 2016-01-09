#pragma once

#include <core/enums/test-case-id-enum.h>
#include <core/interfaces/itestcase.h>
#include <memory>

namespace Factory {

	class TestCaseFactory {
	public:
		explicit TestCaseFactory() = delete;
		virtual ~TestCaseFactory() = delete;

		static std::unique_ptr<Interface::ITestCase> create(const Enum::TestCaseId &id);
	};

}
