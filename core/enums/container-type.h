#pragma once

#include <qglobal.h>

namespace Enum {

	enum class ContainerType : quint8 {
		CompilerInfo,
		PlatformInfo,
		TestCaseInfo,
		TestCase,
		VersionInfo
	};

}
