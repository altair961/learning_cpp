#include "FilesFilter.h"

namespace fs = std::experimental::filesystem;

std::vector<std::string> getAllImagesFromFilepath(std::string path) {
	std::string allodwedExt[] = {
		"jpeg",
		"jpg",
	};

	std::vector<std::string> images;

	for (const auto & entry : fs::directory_iterator(path))
	{
		std::string p = entry.path().string();

		std::string ext = p.substr(p.rfind('.') + 1);
		std::transform(ext.begin(), ext.end(), ext.begin(),
			[](unsigned char c) { return std::tolower(c); });

		if (std::find(std::begin(allodwedExt), std::end(allodwedExt), ext) != std::end(allodwedExt)) {
			images.push_back(p);
		}
	}

	return images;
}