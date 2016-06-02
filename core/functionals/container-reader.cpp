#include <core/functionals/container-reader.h>
#include <core/factories/container-factory.h>

using namespace Functional;
using namespace Factory;

ContainerReader::ContainerReader(const QString &filePath)
		: m_file(filePath) {
	m_file.open(QIODevice::ReadOnly);
	m_stream.setDevice(&m_file);
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
