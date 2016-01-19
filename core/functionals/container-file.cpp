#include <core/functionals/container-file.h>
#include <core/factories/container-factory.h>

using namespace Functional;
using namespace Factory;

ContainerFile::ContainerFile(const QString &filePath)
	: m_file(filePath) {
	m_file.open(QIODevice::ReadWrite | QIODevice::Truncate);
	m_stream.setDevice(&m_file);
}

std::unique_ptr<Abstract::AbstractContainer> ContainerFile::read() {
	if (m_stream.atEnd())
		return nullptr;

	std::underlying_type<Enum::ContainerType>::type type;
	m_stream >> type;
	auto container = ContainerFactory::create(static_cast<Enum::ContainerType>(type));
	*container << m_stream;
	return container;
}

void ContainerFile::write(const Abstract::AbstractContainer &container) {
	auto type = static_cast<std::underlying_type<Enum::ContainerType>::type>(container.type());
	m_stream << type;
	container >> m_stream;
}
