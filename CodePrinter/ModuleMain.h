#pragma once
#include <stdio.h>
#include "xml\tinyxml.h"
#include <iostream>
#include <string>
using namespace std;

class ModuleMain//Õ®”√À„∑®ø‚
{
public:
	ModuleMain(void);
	~ModuleMain(void);
	LPCWSTR stringToLPCWSTR(std::string orig);
    string WcharToChar(const wchar_t* wp, size_t m_encode = CP_ACP);
	string ReadXml(string xmlFileName,string nameStr,string faultValue,string path);
    bool writeXml(string xmlFileName,string valueStr,string textStr,string path);
	void string2tchar(std::string &src, TCHAR* buf);
	string TCHAR2STRING(TCHAR *STR);
};
