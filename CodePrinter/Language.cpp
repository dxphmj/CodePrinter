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
	// Ԥ��-�������ж��ֽڵĳ���    
	int ansiiLen = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, NULL, 0, NULL, NULL);  
	// ��ָ�򻺳�����ָ����������ڴ�    
	char *pAssii = (char*)malloc(sizeof(char)*ansiiLen);  
	// ��ʼ�򻺳���ת���ֽ�    
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), -1, pAssii, ansiiLen, NULL, NULL);  
	string ret_str = pAssii;  
	free(pAssii);  
	return ret_str;  
} 
wstring Language::Utf8ToUnicode(const string& str) 
{  
	// Ԥ��-�������п��ֽڵĳ���    
	int unicodeLen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);  
	// ��ָ�򻺳�����ָ����������ڴ�    
	wchar_t *pUnicode = (wchar_t*)malloc(sizeof(wchar_t)*unicodeLen);  
	// ��ʼ�򻺳���ת���ֽ�    
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, pUnicode, unicodeLen);  
	wstring ret_str = pUnicode;  
	free(pUnicode);  
	return ret_str;  
}  
string Language::Utf8ToAscii(const string& str) 
{  
	return UnicodeToAscii(Utf8ToUnicode(str));   
}  