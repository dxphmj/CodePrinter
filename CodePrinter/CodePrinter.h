// CodePrinter.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once
#include "Language.h"
#include "ClassMessage.h"
#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif
using namespace MyNameSpace;
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
	ClassMessage myclassMessage;
	DECLARE_MESSAGE_MAP()
};

extern CCodePrinterApp theApp;
