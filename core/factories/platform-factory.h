#pragma once

#include <core/interfaces/iplatform.h>
#include <memory>

namespace Factory {

class PlatformFactory {
public:
	explicit PlatformFactory() = delete;
	virtual ~PlatformFactory() = delete;

	static std::unique_ptr<Interface::IPlatform> create(const Enum::PlatformType &type);
};
}
