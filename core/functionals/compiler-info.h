#pragma once

#include <string>

namespace Functional {

	class CompilerInfo {
	public:
		explicit CompilerInfo() = default;
		virtual ~CompilerInfo() = default;

		static std::string compiler();
		static std::string arch();
		static std::string ident();
	};

}
