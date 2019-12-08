// EditTextDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "EditTextDlg.h"


// CEditTextDlg 对话框

IMPLEMENT_DYNAMIC(CEditTextDlg, CDialog)

CEditTextDlg::CEditTextDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditTextDlg::IDD, pParent)
{

}

CEditTextDlg::~CEditTextDlg()
{
}

void CEditTextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEditTextDlg, CDialog)
	ON_BN_CLICKED(IDC_EDITTEXT_CLOSE_BTN, &CEditTextDlg::OnBnClickedEdittextCloseBtn)
END_MESSAGE_MAP()


// CEditTextDlg 消息处理程序

BOOL CEditTextDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CEditTextDlg::OnBnClickedEdittextCloseBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
}
