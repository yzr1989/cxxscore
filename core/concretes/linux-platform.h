#pragma once

#include <core/abstracts/abstract-platform.h>

namespace Concrete {

	class LinuxPlatform final : public Abstract::AbstractPlatform {
	public:
		explicit LinuxPlatform() = default;
		virtual ~LinuxPlatform() = default;
	};

}
