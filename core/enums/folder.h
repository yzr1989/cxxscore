#pragma once

#include <QString>

namespace Enum {

enum class Folder : quint8 {
	Data,
	Plot
};

QString name(const Folder &folder);
}
