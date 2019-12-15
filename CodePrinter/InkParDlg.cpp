// InkParDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "InkParDlg.h"


// CInkParDlg 对话框

IMPLEMENT_DYNAMIC(CInkParDlg, CDialog)

CInkParDlg::CInkParDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInkParDlg::IDD, pParent)
{

}

CInkParDlg::~CInkParDlg()
{
}

void CInkParDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInkParDlg, CDialog)
END_MESSAGE_MAP()


// CInkParDlg 消息处理程序
