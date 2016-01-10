#include <core/functionals/compiler-info.h>
#include <iostream>

using namespace Functional;

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

Container::CompilerInfoContainer CompilerInfo::info() {
	Container::CompilerInfoContainer container;
#ifdef __clang__
	container.setName("clang");
#else
	container.setName("gcc");
#endif
	container.setFlags(TOSTRING(CXXFLAGS));
	return container;
}

void CompilerInfo::printInfo() {
	Container::CompilerInfoContainer info = CompilerInfo::info();
	std::cout << "Compiler info:" << std::endl;
	std::cout << "\tcompiler: " << info.name().toStdString() << std::endl;
	std::cout << "\tflags: " << info.flags().toStdString() << std::endl;
	std::cout << std::endl;
}

