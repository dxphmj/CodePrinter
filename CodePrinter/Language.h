#pragma once
#include <map>
#include <string>
using namespace std;
class Language
{
public:
	Language(void);
	~Language(void);

public:
	std::map<std::string,std::wstring> LanguageMap;
	bool readLanguageXml(std::string xmlName);

	string  UnicodeToAscii(const wstring& wstr);
	wstring Utf8ToUnicode(const string& str);  
	string  Utf8ToAscii(const string& str);
};
