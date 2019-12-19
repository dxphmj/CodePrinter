#pragma once

#include "stdafx.h "
#include "xml\tinyxml.h"
#include "xml\tinystr.h"

class CDealXml
{
public:
	CDealXml(void);
	~CDealXml(void);
public:
	CString ReadXml(CString FileName,CString Name,CString FaultStr,CString Path);
	bool WriteXml(CString FileName,CString Name,CString Value,CString Path);
	CString ConstCharToCStirng( const char* ch);
	const char* CStringToConstChar( CString cstr );

};
