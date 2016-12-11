#pragma once

#include <core/enums/folder.h>

namespace Manager {

class FileManager final {
public:
	explicit FileManager(const std::string &workdir);
	virtual ~FileManager() = default;

	std::string path(const Enum::Folder &folder, const std::string &fileName);
	//QFileInfoList list(const Enum::Folder &folder);

private:
	std::string m_workdir;
};
}
