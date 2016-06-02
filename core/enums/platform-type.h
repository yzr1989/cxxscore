#pragma once

#include <QString>

namespace Enum {

enum class PlatformType : quint8 {
	Linux
};

QString name(const PlatformType &type);
}
