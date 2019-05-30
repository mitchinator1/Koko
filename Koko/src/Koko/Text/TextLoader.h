#ifndef TEXT_LOADER_H
#define TEXT_LOADER_H
#include "kkpch.h"
#include "Koko/Text.h"

namespace Koko
{
	//TextData LoadTextData(const std::string& fileName, const std::string& id);
	std::string LoadString(const std::string& key, const std::string& lang = "EN");
}

#endif