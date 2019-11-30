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
	CLabelDlg Label;
	Label.DoModal();
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
	CSystemDlg System;
	System.DoModal();
}

void CCodePrinterDlg::OnBnClickedUserButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CUserDlg User;
	User.DoModal();
}

void CCodePrinterDlg::OnBnClickedConfigurationButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CConfigurationDlg Configuration;
	Configuration.DoModal();
}

void CCodePrinterDlg::OnBnClickedFilemanaButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileManaDlg FileMana;
	FileMana.DoModal();
}

void CCodePrinterDlg::OnBnClickedInkButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CInkSystemDlg InkSystem;
	InkSystem.DoModal();
}
