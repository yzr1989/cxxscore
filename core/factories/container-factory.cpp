#include <core/factories/container-factory.h>
#include <core/containers/compiler-info-container.h>
#include <core/containers/platform-info-container.h>
#include <core/containers/test-result-container.h>

using namespace Enum;
using namespace Factory;

std::unique_ptr<Abstract::AbstractContainer> ContainerFactory::create(const ContainerType &type) {
	switch (type) {
		case ContainerType::CompilerInfo:
			return std::make_unique<Container::CompilerInfoContainer>();

		case ContainerType::PlatformInfo:
			return std::make_unique<Container::PlatformInfoContainer>();

		case ContainerType::TestResult:
			return std::make_unique<Container::TestResultContainer>();
	};

	return nullptr;
}

