#pragma once

#include <QString>

namespace Enum {

	enum class ArchitectureType : quint8 {
		ARM,
		x86,
		x86_64
	};

	QString name(const ArchitectureType &type);

}
