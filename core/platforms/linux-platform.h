#pragma once

#include <core/abstracts/abstract-platform.h>

namespace Platform {

	class LinuxPlatform final : public Abstract::AbstractPlatform {
	public:
		explicit LinuxPlatform();
		virtual ~LinuxPlatform() = default;

		virtual Enum::PlatformType type() const override;
	};

}
