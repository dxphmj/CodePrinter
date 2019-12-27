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
}


BEGIN_MESSAGE_MAP(CSystemDlg, CDialog)
	ON_BN_CLICKED(IDC_EVN_BTN, &CSystemDlg::OnBnClickedEvnBtn)
	ON_BN_CLICKED(IDC_COM_BTN, &CSystemDlg::OnBnClickedComBtn)
	ON_BN_CLICKED(IDC_VERSION_BTN, &CSystemDlg::OnBnClickedVersionBtn)
	ON_BN_CLICKED(IDC_NET_BTN, &CSystemDlg::OnBnClickedNetBtn)
	ON_BN_CLICKED(IDC_SYSTEM_CLOSE_BTN, &CSystemDlg::OnBnClickedSystemCloseBtn)
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
	
	//设置按钮的位置及大小IDC_SYSTEM_CLOSE_BTN
	GetDlgItem(IDC_SYSTEM_CLOSE_BTN)->SetWindowPos(NULL,10,400,70,45,SWP_SHOWWINDOW);//IDC_SYSTEM_CANCEL_BTN

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
