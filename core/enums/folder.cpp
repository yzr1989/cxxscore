#include <core/enums/folder.h>

using namespace Enum;

std::string Enum::name(const Enum::Folder &folder) {
	switch (folder) {
		case Folder::Data:
			return "data";

		case Folder::Plot:
			return "plot";
	}

	return {};
}
