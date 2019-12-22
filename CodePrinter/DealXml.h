#pragma once

#include "stdafx.h "
#include "xml\tinyxml.h"
#include "xml\tinystr.h"
#include <string>

using namespace std;

class CDealXml
{
public:
	CDealXml(void);
	~CDealXml(void);
public:
	CString ReadXml(CString FileName,CString Name,CString FaultStr,CString Path);//读XML某行
	bool WriteXml(CString FileName,CString Name,CString Value,CString Path);//保存XML某行

	//用途：将十六进制转化为十进制byte型
	//输入：Hex(十六进制数)
	//输入数据类型：String
	//输出：HEX_to_DECbyte(十进制数)
	//输出数据类型：Long
	//输入的最大数为FF,输出的最大数为255
	BYTE HEX_to_DECbyte(CString strHex);//

};
