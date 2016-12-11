#include <core/functionals/container-writer.h>
#include <core/factories/container-factory.h>

using namespace Functional;
using namespace Factory;

ContainerWritter::ContainerWritter(const std::string &filePath)
		: m_filePath(filePath) {
	m_file.open(filePath.c_str(), std::fstream::in | std::fstream::out | std::ios::trunc | std::ios::binary);
}

ContainerWritter::~ContainerWritter() {
	m_file.write(m_stream.data(), m_stream.size());
	m_file.close();
}

void ContainerWritter::write(const Abstract::AbstractContainer &container) {
	auto type = static_cast<std::underlying_type<Enum::ContainerType>::type>(container.type());
	m_stream << type;
	container >> m_stream;
}
