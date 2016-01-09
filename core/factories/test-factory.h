#pragma once

#include <core/enums/test-type-enum.h>
#include <core/interfaces/itestcase.h>
#include <memory>

namespace Factory {

	class TestFactory {
	public:
		explicit TestFactory() = delete;
		virtual ~TestFactory() = delete;

		static std::unique_ptr<Interface::ITestCase> create(const Enum::TestType &type);
	};

}
