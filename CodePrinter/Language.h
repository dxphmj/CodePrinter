#pragma once
#include <map>
#include <string>
class Language
{
public:
	Language(void);
	~Language(void);

public:
	std::map<std::string,std::string> LanguageMap;
	bool readLanguageXml(std::string xmlName);
};
