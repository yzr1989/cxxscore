#pragma once

#include <core/containers/compiler-info-container.h>
#include <core/containers/platform-info-container.h>

namespace Functional {

class InfoCenter final {
public:
	explicit InfoCenter() = delete;
	virtual ~InfoCenter() = delete;

	static void populate(Container::CompilerInfoContainer &container);
	static void populate(Container::PlatformInfoContainer &container);

	static void print(Container::CompilerInfoContainer &container);
	static void print(Container::PlatformInfoContainer &container);
};
}
