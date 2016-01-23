#include <core/managers/file-manager.h>
#include <QCoreApplication>

using namespace Enum;
using namespace Manager;

FileManager::FileManager(const QString &workdir)
	: m_workdir(workdir)
	, m_dir(workdir)

{
	const auto list = {
		Folder::Data,
		Folder::Plot
	};

	for (auto &type : list)
		m_dir.mkdir(name(type));
}

QString FileManager::path(const Enum::Folder &folder, const QString &fileName) {
	return m_workdir + QDir::separator() + name(folder) +
	       QDir::separator() + fileName;
}

QFileInfoList FileManager::list(const Enum::Folder &folder) {
	QDir dir(m_workdir + QDir::separator() + name(folder));
	return dir.entryInfoList({"*.*"}, QDir::Files, QDir::Reversed | QDir::Name);
}
