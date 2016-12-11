#include <core/functionals/container-reader.h>
#include <core/factories/container-factory.h>

using namespace Functional;
using namespace Factory;

ContainerReader::ContainerReader(const std::string &filePath)
		: m_filePath(filePath) {
	m_file.open(filePath.c_str(), std::fstream::in | std::ios::binary);
	m_file.seekg(0, std::ios::end);
	m_stream.setSize(m_file.tellg());
	m_file.seekg(0, std::ios::beg);
	m_file.read(m_stream.data(), m_stream.size());
}

std::unique_ptr<Abstract::AbstractContainer> ContainerReader::read() {
	if (m_stream.atEnd())
		return nullptr;

	std::underlying_type<Enum::ContainerType>::type type;
	m_stream >> type;
	auto container = ContainerFactory::create(static_cast<Enum::ContainerType>(type));
	*container << m_stream;
	return container;
}
