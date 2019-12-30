// UserNewDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "UserNewDlg.h"


// CUserNewDlg 对话框

IMPLEMENT_DYNAMIC(CUserNewDlg, CDialog)

CUserNewDlg::CUserNewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserNewDlg::IDD, pParent)
{

}

CUserNewDlg::~CUserNewDlg()
{
}

void CUserNewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUserNewDlg, CDialog)
END_MESSAGE_MAP()


// CUserNewDlg 消息处理程序
