#pragma once

#include <core/abstracts/abstract-platform.h>
#include <memory>

namespace Factory {

	class PlatformFactory {
	public:
		explicit PlatformFactory() = delete;
		virtual ~PlatformFactory() = delete;

		static std::unique_ptr<Abstract::AbstractPlatform> create(const Enum::PlatformType &type);
	};

}
