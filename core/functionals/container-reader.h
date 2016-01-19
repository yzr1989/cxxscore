#pragma once

#include <core/abstracts/abstract-container.h>
#include <core/core/data-stream.h>

#include <QFile>
#include <memory>

namespace Functional {

	class ContainerReader {
	public:
		explicit ContainerReader(const QString &filePath);
		virtual ~ContainerReader() = default;

		std::unique_ptr<Abstract::AbstractContainer> read();

	private:
		QFile m_file;
		Core::DataStream m_stream;
	};


}
