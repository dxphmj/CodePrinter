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
#include "UserPower.h"
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

public:

	CBrush m_DlgBrush;
    COLORREF m_BKcolor;
	CFont *m_HeadMachineStaFont;
	CFont *m_HeadOperationStaFont;
	CFont *m_StaticFont;

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
	bool boDrawMainPic;//�����涯̬���ƿ���
	bool mythreadDynamicBoo;//��̬�߳̿���
	CWinThread* TTLcom;//ttl�߳̾��
	CWinThread* mythreadDynamic;
	CWinThread* mythreadDynamicdis;
	TimClass myTimClass;
	PcfClass myPcfClass;
	StatusClass myStatusClass;
	DWORD TTLcomID;
	Language myLanguage;
	ClassMessage myclassMessage;
	CCriticalSection bytSlaveStatusLock;//��ȡ״̬
	CCriticalSection boPrintNowLock;//��ӡ
	CCriticalSection boQueCtrLock;//����
	CCriticalSection boETimetextLock;//ʱ��
	CIOVsd myCIOVsd;
	ModuleMain myModuleMain;
	UserPower myUserPower;
	DECLARE_MESSAGE_MAP()
};

extern CCodePrinterApp theApp;
