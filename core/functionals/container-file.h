#pragma once

#include <core/abstracts/abstract-container.h>
#include <core/core/data-stream.h>
#include <QString>
#include <QFile>

#include <memory>

namespace Functional {

	class ContainerFile {
	public:
		explicit ContainerFile(const QString &filePath);
		virtual ~ContainerFile() = default;

		std::unique_ptr<Abstract::AbstractContainer> read();
		void write(const Abstract::AbstractContainer &container);

	private:
		QFile m_file;
		Core::DataStream m_stream;
	};

}
