#pragma once

#include <core/abstracts/abstract-container.h>
#include <core/core/data-stream.h>

#include <fstream>

namespace Functional {

class ContainerWritter {
public:
	explicit ContainerWritter(const std::string &filePath);
	virtual ~ContainerWritter();

	void write(const Abstract::AbstractContainer &container);

private:
	const std::string m_filePath;
	std::fstream m_file;
	Core::DataStream m_stream;
};
}
