// FileManaDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "FileManaDlg.h"


// CFileManaDlg 对话框

IMPLEMENT_DYNAMIC(CFileManaDlg, CDialog)

CFileManaDlg::CFileManaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileManaDlg::IDD, pParent)
{

}

CFileManaDlg::~CFileManaDlg()
{
}

void CFileManaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFileManaDlg, CDialog)
	ON_BN_CLICKED(IDC_FILEMANA_CLOSE_BTN, &CFileManaDlg::OnBnClickedFilemanaCloseBtn)
END_MESSAGE_MAP()


// CFileManaDlg 消息处理程序

BOOL CFileManaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CFileManaDlg::OnBnClickedFilemanaCloseBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
}
