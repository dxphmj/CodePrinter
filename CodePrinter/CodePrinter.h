// CodePrinter.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once
#include "Language.h"
#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#ifdef STANDARDSHELL_UI_MODEL
#include "resource.h"
#endif

// CCodePrinterApp:
// �йش����ʵ�֣������ CodePrinter.cpp
//

class CCodePrinterApp : public CWinApp
{
public:
	CCodePrinterApp();
	
// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	Language myLanguage;
	DECLARE_MESSAGE_MAP()
};

extern CCodePrinterApp theApp;
