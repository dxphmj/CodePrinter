// CodePrinterDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "CodePrinterDlg.h"
#include "LabelDlg.h"
#include "FaultDlg.h"
#include "SystemDlg.h"
#include "UserDlg.h"
#include "ConfigurationDlg.h"
#include "FileManaDlg.h"
#include "InkSystemDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCodePrinterDlg 对话框

CCodePrinterDlg::CCodePrinterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCodePrinterDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCodePrinterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FAULT_BUTTON, m_ButFault);
	DDX_Control(pDX, IDC_RESET_COUNT_BTN, m_ButRestCount);
}

BEGIN_MESSAGE_MAP(CCodePrinterDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_LABEL_BUTTON, &CCodePrinterDlg::OnBnClickedLabelButton)
	ON_BN_CLICKED(IDC_FAULT_BUTTON, &CCodePrinterDlg::OnBnClickedFaultButton)
	ON_BN_CLICKED(IDC_SYSTEM_BUTTON, &CCodePrinterDlg::OnBnClickedSystemButton)
	ON_BN_CLICKED(IDC_USER_BUTTON, &CCodePrinterDlg::OnBnClickedUserButton)
	ON_BN_CLICKED(IDC_CONFIGURATION_BUTTON, &CCodePrinterDlg::OnBnClickedConfigurationButton)
	ON_BN_CLICKED(IDC_FILEMANA_BUTTON, &CCodePrinterDlg::OnBnClickedFilemanaButton)
	ON_BN_CLICKED(IDC_INK_BUTTON, &CCodePrinterDlg::OnBnClickedInkButton)
END_MESSAGE_MAP()


// CCodePrinterDlg 消息处理程序

BOOL CCodePrinterDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetWindowPos(NULL,0,0,800,600,SWP_SHOWWINDOW );	
	CRect rect;
	GetWindowRect(&rect);

	m_System = new CSystemDlg;
	m_User = new CUserDlg;
	m_Label = new CLabelDlg;
	m_Confi = new CConfigurationDlg;
	m_FileMan = new CFileManaDlg;
	m_Ink = new CInkSystemDlg;

	int nX = 0;
	int nY = 0;
	int nWidth = 800;
	int nHeight = 600;
	m_System->Create(IDD_SYSTEM_DIALOG,this);
	m_System->MoveWindow(nX,nY,nWidth,nHeight);

	m_User->Create(IDD_USER_DIALOG,this);
	m_User->MoveWindow(nX,nY,nWidth,nHeight);

	m_Label->Create(IDD_LABEL_DIALOG,this);
	m_Label->MoveWindow(nX,nY,nWidth,nHeight);

	m_Confi->Create(IDD_CONFIGURATION_DIALOG,this);
	m_Confi->MoveWindow(nX,nY,nWidth,nHeight);

	m_FileMan->Create(IDD_FILEMANA_DIALOG,this);
	m_FileMan->MoveWindow(nX,nY,nWidth,nHeight);

	m_Ink->Create(IDD_INKSYSTEM_DIALOG,this);
	m_Ink->MoveWindow(nX,nY,nWidth,nHeight);

	
	//右侧一列设置按钮的位置及大小
	GetDlgItem(IDC_FAULT_BUTTON)->SetWindowPos(NULL,700,50,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_SYSTEM_BUTTON)->SetWindowPos(NULL,670,130,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_USER_BUTTON)->SetWindowPos(NULL,670,200,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_LABEL_BUTTON)->SetWindowPos(NULL,670,270,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_CONFIGURATION_BUTTON)->SetWindowPos(NULL,670,340,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_FILEMANA_BUTTON)->SetWindowPos(NULL,670,410,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_INPUT_BUTTON)->SetWindowPos(NULL,670,480,80,55,SWP_SHOWWINDOW);
	//下面两个按钮
	GetDlgItem(IDC_RESET_COUNT_BTN)->SetWindowPos(NULL,40,400,80,50,SWP_SHOWWINDOW);
	GetDlgItem(IDC_RESET_SERIAL_BTN)->SetWindowPos(NULL,360,400,80,50,SWP_SHOWWINDOW);
	
	//彩色按钮
	m_ButFault.LoadBitmaps(IDB_BITMAP1,IDB_BITMAP2,0,0,IDB_BITMAP3);
	m_ButFault.SizeToContent(); 
	m_ButRestCount.LoadBitmaps(IDB_BITMAP1,IDB_BITMAP2,0,0,IDB_BITMAP3);
	m_ButRestCount.SizeToContent(); 

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CCodePrinterDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_CODEPRINTER_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_CODEPRINTER_DIALOG));
	}
}
#endif

void CCodePrinterDlg::OnBnClickedLabelButton()
{
	// TODO: 在此添加控件通知处理程序代码
	showDlg(IDD_LABEL_DIALOG);
}

void CCodePrinterDlg::OnBnClickedFaultButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CFaultDlg Fault;
	Fault.DoModal();
}

void CCodePrinterDlg::OnBnClickedSystemButton()
{
	// TODO: 在此添加控件通知处理程序代码
	showDlg(IDD_SYSTEM_DIALOG);
}

void CCodePrinterDlg::OnBnClickedUserButton()
{
	// TODO: 在此添加控件通知处理程序代码
	showDlg(IDD_USER_DIALOG);
}

void CCodePrinterDlg::OnBnClickedConfigurationButton()
{
	// TODO: 在此添加控件通知处理程序代码
	showDlg(IDD_CONFIGURATION_DIALOG);
}

void CCodePrinterDlg::OnBnClickedFilemanaButton()
{
	// TODO: 在此添加控件通知处理程序代码
	showDlg(IDD_FILEMANA_DIALOG);
}

void CCodePrinterDlg::OnBnClickedInkButton()
{
	// TODO: 在此添加控件通知处理程序代码
	showDlg(IDD_INKSYSTEM_DIALOG);
}

void CCodePrinterDlg::showDlg(int ID)
{
	m_System->ShowWindow(SW_HIDE);
	m_User->ShowWindow(SW_HIDE);

	m_Label->ShowWindow(SW_HIDE);
	m_Confi->ShowWindow(SW_HIDE);
	m_FileMan->ShowWindow(SW_HIDE);
	m_Ink->ShowWindow(SW_HIDE);
	
	if(ID == IDD_SYSTEM_DIALOG)
	{
		m_System->ShowWindow(SW_SHOW);
	}
	else if (ID == IDD_USER_DIALOG)
	{
		m_User->ShowWindow(SW_SHOW);
	}
	else if(ID == IDD_LABEL_DIALOG)
	{
		m_Label->ShowWindow(SW_SHOW);
	}
	else if(ID == IDD_CONFIGURATION_DIALOG)
	{
		m_Confi->ShowWindow(SW_SHOW);
	}
	else if(ID == IDD_FILEMANA_DIALOG)
	{
		m_FileMan->ShowWindow(SW_SHOW);
	}
	else if(ID == IDD_INKSYSTEM_DIALOG)
	{
		m_Ink->ShowWindow(SW_SHOW);
	}
}
