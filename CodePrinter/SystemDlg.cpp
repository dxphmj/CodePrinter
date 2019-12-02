// SystemDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "SystemDlg.h"
#include "EnvDlg.h"
#include "ComDlg.h"


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
	ON_BN_CLICKED(IDC_EVN_BTN, &CSystemDlg::OnBnClickedEvnButton)
	ON_BN_CLICKED(IDC_BUTTON4, &CSystemDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CSystemDlg 消息处理程序

BOOL CSystemDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetWindowPos(NULL,0,0,800,600,SWP_SHOWWINDOW );	
	CRect rect;
	GetWindowRect(&rect);
	
	//设置按钮的位置及大小
	GetDlgItem(IDC_SYSTEM_CANCEL_BTN)->SetWindowPos(NULL,10,480,70,45,SWP_SHOWWINDOW);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CSystemDlg::OnBnClickedEvnButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CEnvDlg m_Evn;
	m_Evn.DoModal();
}

void CSystemDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CComDlg m_cd;
	m_cd.DoModal();
}
