#pragma once

#include <core/abstracts/abstract-container.h>
#include <core/core/data-stream.h>

#include <memory>

namespace Functional {

class ContainerWritter {
public:
	explicit ContainerWritter(const std::string &filePath);
	virtual ~ContainerWritter() = default;

	void write(const Abstract::AbstractContainer &container);

private:
	const std::string m_filePath;
	Core::DataStream m_stream;
};
}
