#pragma once

#include <QString>

namespace Enum {

enum class CompilerType : quint8 {
	Gcc,
	Clang
};

QString name(const CompilerType &type);
QString filename(const CompilerType &type);
}
