#pragma once

#include <core/enums/folder.h>
#include <QDir>

namespace Manager {

	class FileManager final {
	public:
		explicit FileManager(const QString &workdir = QDir::homePath());
		virtual ~FileManager() = default;

		QString path(const Enum::Folder &folder, const QString &fileName);
		QFileInfoList list(const Enum::Folder &folder);

	private:
		QString m_workdir;
		QDir m_dir;
	};

}
