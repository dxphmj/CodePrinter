// CodePrinter.h : PROJECT_NAME 应用程序的主头文件
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

// 重写
public:
	virtual BOOL InitInstance();
//
	BYTE bytSlaveStatus[37];
	queue<vector<BYTE>> queCtr;//命令队列
	queue<vector<BYTE>> ForPreQue;//序列号队列
	queue<vector<BYTE>> boDotForPreQue;//动态显示队列
	queue<vector<int>> intCounNumForPreQue ; //'主界面及计数器显示动态字符池
	int readCount;
	BYTE bytStatus[37];
// 实现
	//bool boMythreadDynamic;
	//bool boMythreadDynamicdis;
	int mainPicPixel;//主界面显示行数
	bool boTTL;
	bool boDrawMainPic;//主界面动态绘制开关
	bool mythreadDynamicBoo;//动态线程开关
	CWinThread* TTLcom;//ttl线程句柄
	CWinThread* mythreadDynamic;
	CWinThread* mythreadDynamicdis;
	TimClass myTimClass;
	PcfClass myPcfClass;
	StatusClass myStatusClass;
	DWORD TTLcomID;
	Language myLanguage;
	ClassMessage myclassMessage;
	CCriticalSection bytSlaveStatusLock;//读取状态
	CCriticalSection boPrintNowLock;//打印
	CCriticalSection boQueCtrLock;//命令
	CCriticalSection boETimetextLock;//时间
	CIOVsd myCIOVsd;
	ModuleMain myModuleMain;
	UserPower myUserPower;
	bool bochange;//用于判断是否为更改；
	DECLARE_MESSAGE_MAP()
};

extern CCodePrinterApp theApp;
