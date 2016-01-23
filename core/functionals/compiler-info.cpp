#include <core/functionals/compiler-info.h>
#include <iostream>

using namespace Functional;

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

Container::CompilerInfoContainer CompilerInfo::info() {
	Container::CompilerInfoContainer container;
#ifdef __clang__
	container.setId(Enum::CompilerType::Clang);
	container.version().setMajor(__clang_major__);
	container.version().setMinor(__clang_minor__);
	container.version().setPatch(__clang_patchlevel__);
#else
	container.setId(Enum::CompilerType::Gcc);
	container.version().setMajor(__GNUC__);
	container.version().setMinor(__GNUC_MINOR__);
	container.version().setPatch(__GNUC_PATCHLEVEL__);
#endif
	container.setFlags(TOSTRING(CXXFLAGS));
	return container;
}

void CompilerInfo::printInfo() {
	Container::CompilerInfoContainer info = CompilerInfo::info();
	std::cout << "Compiler info:" << std::endl;
	std::cout << "\tcompiler: " << name(info.id()).toStdString() << std::endl;
	std::cout << "\tversion: "
	          << static_cast<int>(info.version().major()) << "."
	          << static_cast<int>(info.version().minor()) << "."
	          << static_cast<int>(info.version().patch())
	          << std::endl;
	std::cout << "\tflags: " << info.flags().toStdString() << std::endl;
	std::cout << std::endl;
}

