#pragma once

#include <core/containers/platform-info-container.h>

namespace Functional {

	class PlatformInfo final {
	public:
		explicit PlatformInfo() = delete;
		virtual ~PlatformInfo() = delete;

		static Container::PlatformInfoContainer info();

		static void printInfo();
	};

}
