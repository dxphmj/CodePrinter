// SystemDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "SystemDlg.h"
#include "EnvDlg.h"
#include "ComDlg.h"
#include "Version.h"
#include "CodePrinterDlg.h"

// CSystemDlg 对话框

IMPLEMENT_DYNAMIC(CSystemDlg, CDialog)

CSystemDlg::CSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSystemDlg::IDD, pParent)
{

}

CSystemDlg::~CSystemDlg()
{
}

void CSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SYS_FRESH1_BTN, m_freshUp);
	DDX_Control(pDX, IDC_SYS_FRESH2_BTN, m_freshDown);
	DDX_Control(pDX, IDC_SYSTEM_CLOSE_BTN, m_sysReturn);
	DDX_Control(pDX, IDC_SYS_OK_BTN, m_sysOk);
	DDX_Control(pDX, IDC_DHCP_BTN, m_dhcp);
}


BEGIN_MESSAGE_MAP(CSystemDlg, CDialog)
	ON_BN_CLICKED(IDC_EVN_BTN, &CSystemDlg::OnBnClickedEvnBtn)
	ON_BN_CLICKED(IDC_COM_BTN, &CSystemDlg::OnBnClickedComBtn)
	ON_BN_CLICKED(IDC_VERSION_BTN, &CSystemDlg::OnBnClickedVersionBtn)
	ON_BN_CLICKED(IDC_NET_BTN, &CSystemDlg::OnBnClickedNetBtn)
	ON_BN_CLICKED(IDC_SYSTEM_CLOSE_BTN, &CSystemDlg::OnBnClickedSystemCloseBtn)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CSystemDlg 消息处理程序

BOOL CSystemDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	pEvn = new CEnvDlg;
	pCom = new CComDlg;
	pVersion = new CVersion;

	pEvn->Create(IDD_ENV_DIALOG,this);
	pCom->Create(IDD_COM_DIALOG,this);
	pVersion->Create(IDD_VERSION_DIALOG,this);

	int nX = 0;
	int nY = 100;
	int nWidth = 800;
	int nHeight = 350;
	pEvn->MoveWindow(nX,nY,nWidth,nHeight);
	pCom->MoveWindow(nX,nY,nWidth,nHeight);
	pVersion->MoveWindow(nX,nY,nWidth,nHeight);
	
	//设置按钮的位置及大小

	GetDlgItem(IDC_SYSTEM_CLOSE_BTN)->SetWindowPos(NULL,10,400,70,45,SWP_SHOWWINDOW);//IDC_SYSTEM_CANCEL_BTN
	GetDlgItem(IDC_SYS_FRESH1_BTN)->SetWindowPos(NULL,320,55,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_SYS_FRESH2_BTN)->SetWindowPos(NULL,320,210,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_SYSTEM_CLOSE_BTN)->SetWindowPos(NULL,11,404,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_SYS_OK_BTN)->SetWindowPos(NULL,695,404,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_DHCP_BTN)->SetWindowPos(NULL,562,319,45,45,SWP_SHOWWINDOW);

	m_freshUp.LoadBitmaps(IDB_FRESH1_BITMAP,IDB_FRESH2_BITMAP,0,0,IDB_FRESH1_BITMAP);
	m_freshUp.SizeToContent(); 
	m_freshDown.LoadBitmaps(IDB_FRESH1_BITMAP,IDB_FRESH2_BITMAP,0,0,IDB_FRESH1_BITMAP);
	m_freshDown.SizeToContent(); 
	m_sysReturn.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RETURN1_BITMAP);
	m_sysReturn.SizeToContent(); 
	m_sysOk.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_OK1_BITMAP);
	m_sysOk.SizeToContent(); 
	m_dhcp.LoadBitmaps(IDB_DHCP1_BITMAP,IDB_DHCP2_BITMAP,0,0,IDB_DHCP1_BITMAP);
	m_dhcp.SizeToContent(); 

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CSystemDlg::OnBnClickedEvnBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	showSystemDlg(IDD_ENV_DIALOG);
}

void CSystemDlg::OnBnClickedComBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	showSystemDlg(IDD_COM_DIALOG);	
}

void CSystemDlg::OnBnClickedVersionBtn()
{
	// TODO: 在此添加控件通知处理程序代码

	//////////////////////////////////临时要删除////////////////////////////////////////
	//CExportDlg myCExportDlg;
	//CString ts;
	//ts.Format(L"%s",_T("sdfsa"));
	//myCExportDlg.GetInputText(ts);
	/////
	showSystemDlg(IDD_VERSION_DIALOG);	
}

void CSystemDlg::OnBnClickedNetBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	showSystemDlg(0);	
}

void CSystemDlg::OnBnClickedSystemCloseBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
	pEvn->ShowWindow(SW_HIDE);
	pCom->ShowWindow(SW_HIDE);
	pVersion->ShowWindow(SW_HIDE);
}


void CSystemDlg::showSystemDlg(int ID)
{
	pEvn->ShowWindow(SW_HIDE);
	pCom->ShowWindow(SW_HIDE);
	pVersion->ShowWindow(SW_HIDE);

	if (ID == IDD_ENV_DIALOG)
	{
		pEvn->ShowWindow(SW_SHOW);
	}
	else if(ID == IDD_COM_DIALOG)
	{
		pCom->ShowWindow(SW_SHOW);
	}
	else if(ID == IDD_VERSION_DIALOG)
	{
		pVersion->ShowWindow(SW_SHOW);
	}
}

HBRUSH CSystemDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return theApp.m_DlgBrush;
}
