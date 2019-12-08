// UserDeleteDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "UserDeleteDlg.h"


// CUserDeleteDlg 对话框

IMPLEMENT_DYNAMIC(CUserDeleteDlg, CDialog)

CUserDeleteDlg::CUserDeleteDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserDeleteDlg::IDD, pParent)
{

}

CUserDeleteDlg::~CUserDeleteDlg()
{
}

void CUserDeleteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUserDeleteDlg, CDialog)
END_MESSAGE_MAP()


// CUserDeleteDlg 消息处理程序
