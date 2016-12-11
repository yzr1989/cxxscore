#pragma once

#include <core/abstracts/abstract-container.h>
#include <core/core/data-stream.h>

#include <memory>
#include <fstream>

namespace Functional {

class ContainerReader {
public:
	explicit ContainerReader(const std::string &filePath);
	virtual ~ContainerReader() = default;

	std::unique_ptr<Abstract::AbstractContainer> read();

private:
	const std::string m_filePath;
	std::fstream m_file;
	Core::DataStream m_stream;
};
}
