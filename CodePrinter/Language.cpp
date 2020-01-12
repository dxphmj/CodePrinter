#include "StdAfx.h"
#include "Language.h"
#include "xml\tinyxml.h"
#include "CodePrinter.h"
using namespace std;
Language::Language(void)
{
}

Language::~Language(void)
{
}

bool Language::readLanguageXml(string xmlName)
{
	string path="\\Storage Card\\user\\LanguageXml\\";
	path+=xmlName;
	TiXmlDocument *pDocument = new TiXmlDocument(path.c_str());
	if (NULL == pDocument)
	{
		return false;
	}
	pDocument->LoadFile(path.c_str(),TIXML_ENCODING_UTF8);

	TiXmlElement *pRoot = pDocument->RootElement();
	if (NULL == pRoot)
	{
		return false;
	}

	TiXmlElement *pChildNode = pRoot->FirstChildElement();
	while (pChildNode != NULL)
	{
		string strValue = pChildNode->Value();
		string strText = pChildNode->GetText();
		wstring strText2 = Utf8ToUnicode(strText);
		theApp.myLanguage.LanguageMap[strValue]=strText2;
		pChildNode = pChildNode->NextSiblingElement();
	}

}

string Language::UnicodeToAscii(const wstring& wstr) 
{  
	// 预算-缓冲区中多字节的长度    
	int ansiiLen = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, NULL, 0, NULL, NULL);  
	// 给指向缓冲区的指针变量分配内存    
	char *pAssii = (char*)malloc(sizeof(char)*ansiiLen);  
	// 开始向缓冲区转换字节    
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, pAssii, ansiiLen, NULL, NULL);  
	string ret_str = pAssii;  
	free(pAssii);  
	return ret_str;  
} 
wstring Language::Utf8ToUnicode(const string& str) 
{  
	// 预算-缓冲区中宽字节的长度    
	int unicodeLen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);  
	// 给指向缓冲区的指针变量分配内存    
	wchar_t *pUnicode = (wchar_t*)malloc(sizeof(wchar_t)*unicodeLen);  
	// 开始向缓冲区转换字节    
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, pUnicode, unicodeLen);  
	wstring ret_str = pUnicode;  
	free(pUnicode);  
	return ret_str;  
}  
string Language::Utf8ToAscii(const string& str) 
{  
	return UnicodeToAscii(Utf8ToUnicode(str));   
}  