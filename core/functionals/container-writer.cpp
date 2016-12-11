#include <core/functionals/container-writer.h>
#include <core/factories/container-factory.h>

using namespace Functional;
using namespace Factory;

ContainerWritter::ContainerWritter(const std::string &filePath)
		: m_filePath(filePath) {
//	m_file.open(QIODevice::WriteOnly | QIODevice::Truncate);
//	m_stream.setDevice(&m_file);
}

void ContainerWritter::write(const Abstract::AbstractContainer &container) {
	auto type = static_cast<std::underlying_type<Enum::ContainerType>::type>(container.type());
	m_stream << type;
	container >> m_stream;
}
