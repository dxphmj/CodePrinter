// InkSetupDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "InkSetupDlg.h"


// CInkSetupDlg 对话框

IMPLEMENT_DYNAMIC(CInkSetupDlg, CDialog)

CInkSetupDlg::CInkSetupDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInkSetupDlg::IDD, pParent)
{

}

CInkSetupDlg::~CInkSetupDlg()
{
}

void CInkSetupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInkSetupDlg, CDialog)
END_MESSAGE_MAP()


// CInkSetupDlg 消息处理程序
