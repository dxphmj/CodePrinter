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
END_MESSAGE_MAP()


// CFileManaDlg 消息处理程序

BOOL CFileManaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetWindowPos(NULL,0,0,800,600,SWP_SHOWWINDOW );	
	CRect rect;
	GetWindowRect(&rect);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
