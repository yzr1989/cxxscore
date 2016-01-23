#pragma once

#include <core/enums/container-type.h>
#include <core/core/data-stream.h>

#include <memory>

namespace Abstract {

	class AbstractContainer {
	public:
		explicit AbstractContainer() = default;
		virtual ~AbstractContainer() = default;

		virtual Enum::ContainerType type() const = 0;

		virtual Core::DataStream &operator << (Core::DataStream &in) = 0;
		virtual Core::DataStream &operator >> (Core::DataStream &out) const = 0;

	};

}
