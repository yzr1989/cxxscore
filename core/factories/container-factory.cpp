#include <core/containers/compiler-info-container.h>
#include <core/containers/platform-info-container.h>
#include <core/containers/test-case-info-container.h>
#include <core/containers/test-result-container.h>
#include <core/containers/version-info-container.h>
#include <core/factories/container-factory.h>

using namespace Enum;
using namespace Factory;

std::unique_ptr<Abstract::AbstractContainer> ContainerFactory::create(const ContainerType &type) {
	switch (type) {
		case ContainerType::CompilerInfo:
			return std::make_unique<Container::CompilerInfoContainer>();

		case ContainerType::PlatformInfo:
			return std::make_unique<Container::PlatformInfoContainer>();

		case ContainerType::TestCaseInfo:
			return std::make_unique<Container::TestCaseInfoContainer>();

		case ContainerType::TestCase:
			return std::make_unique<Container::TestCaseContainer>();

		case ContainerType::VersionInfo:
			return std::make_unique<Container::VersionInfoContainer>();
	};

	return nullptr;
}
