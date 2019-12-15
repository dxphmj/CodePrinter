// ComDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "ComDlg.h"


// CComDlg 对话框

IMPLEMENT_DYNAMIC(CComDlg, CDialog)

CComDlg::CComDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CComDlg::IDD, pParent)
{

}

CComDlg::~CComDlg()
{
}

void CComDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CComDlg, CDialog)
END_MESSAGE_MAP()


// CComDlg 消息处理程序

BOOL CComDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//SetWindowPos(NULL,0,0,800,450,SWP_SHOWWINDOW );	
	//CRect rect;
	//GetWindowRect(&rect);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
