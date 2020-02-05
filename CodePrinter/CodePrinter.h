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
	CBrush m_StaticBrush;
	CBrush m_ListBoxBrush;
    COLORREF m_BKcolor;
	CFont *m_HeadMachineStaFont;
	CFont *m_HeadOperationStaFont;
	CFont *m_StaticFont;
	CFont *m_EditFont;
	CFont *m_ListBoxFont;

// ��д
public:
	virtual BOOL InitInstance();
//
	BYTE bytSlaveStatus[37];
	queue<vector<BYTE>> queCtr;//�������
	queue<vector<BYTE>> ForPreQue;//���кŶ���
	queue<vector<BYTE>> boDotForPreQue;//��̬��ʾ����
	queue<vector<int>> intCounNumForPreQue ; //'�����漰��������ʾ��̬�ַ���
	int readCount;
	BYTE bytStatus[37];
// ʵ��
	//bool boMythreadDynamic;
	//bool boMythreadDynamicdis;
	int mainPicPixel;//��������ʾ����
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
	bool bochange;//�����ж��Ƿ�Ϊ���ģ�
	DECLARE_MESSAGE_MAP()
};

extern CCodePrinterApp theApp;
