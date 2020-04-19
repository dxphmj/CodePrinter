// CodePrinterDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "ImageButton.h"
#include "CodePrinterDlg.h"
#include "LabelDlg.h"
#include "FaultDlg.h"
#include "SystemDlg.h"
#include "UserDlg.h"
#include "ConfigurationDlg.h"
#include "FileManaDlg.h"
#include "InkSystemDlg.h"
#include "PictureStatic.h"
#include "MainPicture.h"
#include "Resource.h"
#include "OnOffDlg.h"
#include "NumKey.h"
#include "ResetSerial.h"
#include "DealXml.h"

#include "Arabicconjunction.h"

#include "ClientSocket.h"

#define TIMER1 1

// CCodePrinterDlg 对话框
class CCodePrinterDlg : public CDialog
{
// 构造
public:
	CCodePrinterDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CODEPRINTER_DIALOG };


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


public:
    CPictureStatic m_PicHead;
	MainPicture m_PictureMain;
	string m_currentDate; //当前日期
	string m_currentTime; //当前时间
public:
    void UpdateValve(); //更新各种阀的信息
    void GetFaultInfo(); //获得各种故障信息
    void UpdatePhase();

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	afx_msg void OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/);
#endif

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedLabelButton();
	afx_msg void OnBnClickedFaultButton();
	afx_msg void OnBnClickedSystemButton();
	afx_msg void OnBnClickedUserButton();
	afx_msg void OnBnClickedConfigurationButton();
	afx_msg void OnBnClickedFilemanaButton();
	afx_msg void OnBnClickedInkButton();
	afx_msg void OnBnClickedOnoroffButton();
	afx_msg void OnBnClickedStartprintButton();
	afx_msg void OnBnClickedPauseprintButton();
	afx_msg void OnBnClickedResetCountBtn();
	afx_msg void OnBnClickedResetSerialBtn();
	CImageButton m_ButFault;
	CImageButton m_ButSystem;
	CImageButton m_ButUser;
	CImageButton m_ButLabel;
	CImageButton m_ButConfig;
	CImageButton m_ButFileMana;
	CImageButton m_ButInk;
	CImageButton m_ButOnOrOff;
	CImageButton m_StartPrint;
	CImageButton m_PausePrint;
	CImageButton m_ButResetCounter;
	CImageButton m_ButResetSerial;

	CSystemDlg *m_System;
	CUserDlg *m_User;
	CLabelDlg *m_Label;
	CConfigurationDlg *m_Confi;
	CFileManaDlg *m_FileMan;
	CInkSystemDlg *m_Ink;
	CFaultDlg *m_Fault;
	CResetSerial *m_resetSerial;

	COnOffDlg *m_OnOff;
	CNumKey *m_pNumKey;


	structMP mainPicStruct;
	
public:
	void showDlg(int ID);
	void OpenNumKeyBoard(CEdit * pWnd,int dlgNum);

public:

	afx_msg void OnTimer(UINT_PTR nIDEvent); //定时器
 
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	void ChangeBottonEnable();
public:
	CArabicconjunction *m_cAbrabicconj;
public://网络
	afx_msg LRESULT OnSocketAccept(WPARAM wParam, LPARAM lParam);	//FD_ACCEPT网络事件自定义消息
	afx_msg LRESULT OnSocketRead(WPARAM wParam, LPARAM lParam);		//FD_READ网络事件自定义消息
	afx_msg LRESULT OnSocketClose(WPARAM wParam, LPARAM lParam);	//FD_CLOSE网络事件自定义消息

	BOOL	InitSocket(void);								//初始化套结字
	BOOL	BeginListen(void);								//服务器开始监听
	BOOL    StartSocket(void);								//开始通讯
	static DWORD WINAPI ServiceThread(void *pParam);		//服务器线程函数

	void	ClearSocketAndEventFromArr(const int nIndex);	//删除客户端套接字
	void	DeleteClientNode(SOCKET s);						//从管理客户端链表删除节点
	CClientSocket* FindClientNode(const SOCKET s);			//从管理客户端链表中查找对应的CClientSocket指针


public:

	SOCKET			m_sListen;						//监听套接字
	WSAEVENT		m_arrEvent[MAX_NUM_EVENTS];		//套接字事件对象数组
	SOCKET			m_arrSocket[MAX_NUM_EVENTS];	//套接字数组
	WORD			m_nTotalEvent;					//网络事件数量
	CImageList		*m_pImageList;					//图像列表对象
	BOOL			m_bRuning;						//服务器运行状态
	HANDLE			m_hEventExit;					//服务器退出事件

private:
	//CObList				m_UserList;					//用户链表
	//CCriticalSection	m_csList;					//临界区对象
};
