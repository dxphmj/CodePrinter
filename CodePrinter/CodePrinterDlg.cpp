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
	DDX_Control(pDX, IDC_SYSTEM_BUTTON, m_ButSystem);
	DDX_Control(pDX, IDC_USER_BUTTON, m_ButUser);
	DDX_Control(pDX, IDC_LABEL_BUTTON, m_ButLabel);
	DDX_Control(pDX, IDC_CONFIGURATION_BUTTON, m_ButConfig);
	DDX_Control(pDX, IDC_FILEMANA_BUTTON, m_ButFileMana);
	DDX_Control(pDX, IDC_INK_BUTTON, m_ButInk);
	DDX_Control(pDX, IDC_ONOROFF_BUTTON, m_OnOrOff);
	DDX_Control(pDX, IDC_STARTPRINT_BUTTON, m_StartPrint);
	DDX_Control(pDX, IDC_PAUSEPRINT_BUTTON, m_PausePrint);
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

	m_Fault = new CFaultDlg;
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
	m_Fault->Create(IDD_FAULT_DIALOG,this);
	m_Fault->MoveWindow(nX,nY,nWidth,nHeight);

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
	GetDlgItem(IDC_FAULT_BUTTON)->SetWindowPos(NULL,700,10,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_SYSTEM_BUTTON)->SetWindowPos(NULL,670,100,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_USER_BUTTON)->SetWindowPos(NULL,670,170,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_LABEL_BUTTON)->SetWindowPos(NULL,670,240,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_CONFIGURATION_BUTTON)->SetWindowPos(NULL,670,310,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_FILEMANA_BUTTON)->SetWindowPos(NULL,670,380,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_INK_BUTTON)->SetWindowPos(NULL,670,450,80,55,SWP_SHOWWINDOW);
	//下面两个按钮
	GetDlgItem(IDC_RESET_COUNT_BTN)->SetWindowPos(NULL,40,330,80,50,SWP_SHOWWINDOW);
	GetDlgItem(IDC_RESET_SERIAL_BTN)->SetWindowPos(NULL,360,330,80,50,SWP_SHOWWINDOW);
	
	//彩色按钮
	m_ButFault.LoadBitmaps(IDB_FAULT_BITMAP,IDB_FAULT_BITMAP,0,0,IDB_FAULT_BITMAP);
	m_ButFault.SizeToContent(); 
	m_ButSystem.LoadBitmaps(IDB_SYSTEM_BITMAP,IDB_SYSTEM_BITMAP,0,0,IDB_SYSTEM_BITMAP);
	m_ButSystem.SizeToContent(); 
	m_ButUser.LoadBitmaps(IDB_USER_BITMAP,IDB_USER_BITMAP,0,0,IDB_USER_BITMAP);
	m_ButUser.SizeToContent(); 
	m_ButLabel.LoadBitmaps(IDB_LABEL_BITMAP,IDB_LABEL_BITMAP,0,0,IDB_LABEL_BITMAP);
	m_ButLabel.SizeToContent(); 
	m_ButConfig.LoadBitmaps(IDB_CONFIG_BITMAP,IDB_CONFIG_BITMAP,0,0,IDB_CONFIG_BITMAP);
	m_ButConfig.SizeToContent(); 
	m_ButFileMana.LoadBitmaps(IDB_FILEMANA_BITMAP,IDB_FILEMANA_BITMAP,0,0,IDB_FILEMANA_BITMAP);
	m_ButFileMana.SizeToContent(); 
	m_ButInk.LoadBitmaps(IDB_INKSYSTEM_BITMAP,IDB_INKSYSTEM_BITMAP,0,0,IDB_INKSYSTEM_BITMAP);
	m_ButInk.SizeToContent(); 
	m_OnOrOff.LoadBitmaps(IDB_ON_OR_OFF_BITMAP,IDB_ON_OR_OFF_BITMAP,0,0,IDB_ON_OR_OFF_BITMAP);
	m_OnOrOff.SizeToContent(); 
	m_StartPrint.LoadBitmaps(IDB_START_PRINT_BITMAP,IDB_START_PRINT_BITMAP,0,0,IDB_START_PRINT_BITMAP);
	m_StartPrint.SizeToContent(); 
	m_PausePrint.LoadBitmaps(IDB_PAUSE_PRINT_BITMAP,IDB_PAUSE_PRINT_BITMAP,0,0,IDB_PAUSE_PRINT_BITMAP);
	m_PausePrint.SizeToContent(); 


///////////////////////
	LPTSTR strTempCmd;
	BYTE readArr[8]={0x1,0x80,0x3,0x8f,0x0,0x25,0xaa,0x55};
	strTempCmd=(LPTSTR)readArr;
	bool bRet = theApp.myCIOVsd.Send(strTempCmd,8);

	Sleep(10);
	theApp.readCount=theApp.myCIOVsd.Read();
    theApp.TTLcom=AfxBeginThread(TTLcomLoop,NULL,THREAD_PRIORITY_HIGHEST);



	//theApp.TTLcom=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)TTLcomLoop,NULL,CREATE_SUSPENDED,&theApp.TTLcomID);
	

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
	showDlg(IDD_FAULT_DIALOG);
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
	m_Fault->ShowWindow(SW_HIDE);
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
	else if (ID == IDD_FAULT_DIALOG)
	{
		m_Fault->ShowWindow(SW_SHOW);
	}
}
