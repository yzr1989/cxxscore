#pragma once

#include <core/abstracts/abstract-container.h>
#include <memory>

namespace Factory {

class ContainerFactory {
public:
	explicit ContainerFactory() = delete;
	virtual ~ContainerFactory() = delete;

	static std::unique_ptr<Abstract::AbstractContainer> create(const Enum::ContainerType &type);
};
}
