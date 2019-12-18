// ConfigurationDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "ConfigurationDlg.h"


// CConfigurationDlg 对话框

IMPLEMENT_DYNAMIC(CConfigurationDlg, CDialog)

CConfigurationDlg::CConfigurationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConfigurationDlg::IDD, pParent)
{

}

CConfigurationDlg::~CConfigurationDlg()
{
}

void CConfigurationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CConfigurationDlg, CDialog)
	ON_BN_CLICKED(IDC_CONFI_CLOSE_BTN, &CConfigurationDlg::OnBnClickedConfiCloseBtn)
	ON_BN_CLICKED(IDC_PRINT_SET_BTN, &CConfigurationDlg::OnBnClickedPrintSetBtn)
	ON_BN_CLICKED(IDC_OUT_SET_BTN, &CConfigurationDlg::OnBnClickedOutSetBtn)
END_MESSAGE_MAP()


// CConfigurationDlg 消息处理程序

BOOL CConfigurationDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_ConfigPM= new CConfigPrintModeDlg;
	m_ConfigOS = new CConfigOutSetDlg;
	int nX = 0;
	int nY = 0;
	int nWidth = 800;
	int nHeight = 600;
	m_ConfigPM->Create(IDD_CONFIG_PRINT_MODE_DIALOG,this);
	m_ConfigPM->MoveWindow(nX,nY,nWidth,nHeight);
	m_ConfigPM->ShowWindow(SW_HIDE);
	m_ConfigOS->Create(IDD_CONFIG_OUTSET_DIALOG,this);
	m_ConfigOS->MoveWindow(nX,nY,nWidth,nHeight);
	m_ConfigOS->ShowWindow(SW_HIDE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CConfigurationDlg::OnBnClickedConfiCloseBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
	showConfigDlg(0);
}

void CConfigurationDlg::showConfigDlg(int ID)
{
	m_ConfigPM->ShowWindow(SW_HIDE);
	m_ConfigOS->ShowWindow(SW_HIDE);
	if (ID == IDD_CONFIG_PRINT_MODE_DIALOG)
	{
		m_ConfigPM->ShowWindow(SW_SHOW);
	}
	if (ID == IDD_CONFIG_OUTSET_DIALOG)
	{
		m_ConfigOS->ShowWindow(SW_SHOW);
	}
	else if (0)
	{
		return;
	}

}

void CConfigurationDlg::OnBnClickedPrintSetBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	showConfigDlg(IDD_CONFIG_PRINT_MODE_DIALOG);
}

void CConfigurationDlg::OnBnClickedOutSetBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	showConfigDlg(IDD_CONFIG_OUTSET_DIALOG);
}
