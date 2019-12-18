// CodePrinter.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once
#include <queue>
#include "IOVsd.h"
#include "Language.h"
#include "ClassMessage.h"
#include "ModuleMain.h"
#include "..\KEYBOARD\KEYBOARD\ExportDlg.h"
#include "afxmt.h"
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
//
	BYTE bytSlaveStatus[37];
	queue<vector<BYTE>> queCtr;//�������
	int readCount;
	BYTE bytStatus[37];
// ʵ��
	bool boTTL;
	CWinThread* TTLcom;//ttl�߳̾��
	StatusClass myStatusClass;
	DWORD TTLcomID;
	Language myLanguage;
	ClassMessage myclassMessage;
	CCriticalSection bytSlaveStatusLock;//��ȡ״̬
	CCriticalSection boPrintNowLock;//��ӡ
	CCriticalSection boQueCtrLock;//����
	CIOVsd myCIOVsd;
	ModuleMain myModuleMain;
	DECLARE_MESSAGE_MAP()
};

extern CCodePrinterApp theApp;
