#pragma once

#include <core/containers/compiler-info-container.h>

namespace Functional {

	class CompilerInfo final {
	public:
		explicit CompilerInfo() = delete;
		virtual ~CompilerInfo() = delete;

		static Container::CompilerInfoContainer info();

		static void printInfo();
	};

}
