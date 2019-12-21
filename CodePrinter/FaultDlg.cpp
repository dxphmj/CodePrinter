// FaultDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "FaultDlg.h"


// CFaultDlg 对话框

IMPLEMENT_DYNAMIC(CFaultDlg, CDialog)

CFaultDlg::CFaultDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFaultDlg::IDD, pParent)
{

}

CFaultDlg::~CFaultDlg()
{
}

void CFaultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX,IDC_FAULT_LIST,m_faultList);
}


BEGIN_MESSAGE_MAP(CFaultDlg, CDialog)
	ON_BN_CLICKED(IDC_FAULT_CLOSE_BTN, &CFaultDlg::OnBnClickedFaultCloseBtn)
END_MESSAGE_MAP()


// CFaultDlg 消息处理程序

BOOL CFaultDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	GetDlgItem(IDC_FAULT_CLOSE_BTN)->SetWindowPos(NULL,10,520,80,50,SWP_SHOWWINDOW);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CFaultDlg::OnBnClickedFaultCloseBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
}
