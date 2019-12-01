// CodePrinter.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once
#include "Language.h"
#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#ifdef STANDARDSHELL_UI_MODEL
#include "resource.h"
#endif

// CCodePrinterApp:
// 有关此类的实现，请参阅 CodePrinter.cpp
//

class CCodePrinterApp : public CWinApp
{
public:
	CCodePrinterApp();
	
// 重写
public:
	virtual BOOL InitInstance();
	LPCWSTR stringToLPCWSTR(std::string orig);
	std::string WcharToChar(const wchar_t* wp, size_t m_encode = CP_ACP);

// 实现
	Language myLanguage;
	DECLARE_MESSAGE_MAP()
};

extern CCodePrinterApp theApp;
