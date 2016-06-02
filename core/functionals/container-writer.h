#pragma once

#include <core/abstracts/abstract-container.h>
#include <core/core/data-stream.h>

#include <QFile>
#include <memory>

namespace Functional {

class ContainerWritter {
public:
	explicit ContainerWritter(const QString &filePath);
	virtual ~ContainerWritter() = default;

	void write(const Abstract::AbstractContainer &container);

private:
	QFile m_file;
	Core::DataStream m_stream;
};
}
