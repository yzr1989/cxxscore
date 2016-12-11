#include <core/managers/file-manager.h>

using namespace Enum;
using namespace Manager;

FileManager::FileManager(const std::string &workdir)
		: m_workdir(workdir)

{
//	const auto list = {
//		Folder::Data,
//		Folder::Plot};

//	for (auto &type : list)
//		m_dir.mkdir(name(type));
}

std::string FileManager::path(const Enum::Folder &folder, const std::string &fileName) {
	return m_workdir + '/' + name(folder) + '/' + fileName;
}

//QFileInfoList FileManager::list(const Enum::Folder &folder) {
//	QDir dir(m_workdir + QDir::separator() + name(folder));
//	return dir.entryInfoList({"*.*"}, QDir::Files, QDir::Reversed | QDir::Name);
//}
