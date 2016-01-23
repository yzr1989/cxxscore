#pragma once

#include <core/containers/compiler-info-container.h>
#include <core/containers/platform-info-container.h>
#include <core/containers/test-result-container.h>
#include <core/enums/test-type.h>

namespace Container {

	class TestCaseContainer final : public Abstract::AbstractContainer {
	public:
		explicit TestCaseContainer() = default;
		virtual ~TestCaseContainer() = default;

		virtual Enum::ContainerType type() const override;
		virtual Core::DataStream &operator << (Core::DataStream &in) override;
		virtual Core::DataStream &operator >> (Core::DataStream &out) const override;

		CompilerInfoContainer &compiler();
		PlatformInfoContainer &platform();
		TestCaseInfoContainer &testcase();

		const CompilerInfoContainer &constCompiler() const;
		const PlatformInfoContainer &constPlatform() const;
		const TestCaseInfoContainer &constTestcase() const;

	private:
		CompilerInfoContainer m_compiler;
		PlatformInfoContainer m_platform;
		TestCaseInfoContainer m_testcase;
	};

}
