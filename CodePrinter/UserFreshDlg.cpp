// UserFreshDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "UserFreshDlg.h"


// CUserFreshDlg 对话框

IMPLEMENT_DYNAMIC(CUserFreshDlg, CDialog)

CUserFreshDlg::CUserFreshDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserFreshDlg::IDD, pParent)
{

}

CUserFreshDlg::~CUserFreshDlg()
{
}

void CUserFreshDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUserFreshDlg, CDialog)
END_MESSAGE_MAP()


// CUserFreshDlg 消息处理程序
