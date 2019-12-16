// InkAdvanceDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "InkAdvanceDlg.h"


// CInkAdvanceDlg 对话框

IMPLEMENT_DYNAMIC(CInkAdvanceDlg, CDialog)

CInkAdvanceDlg::CInkAdvanceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInkAdvanceDlg::IDD, pParent)
{

}

CInkAdvanceDlg::~CInkAdvanceDlg()
{
}

void CInkAdvanceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInkAdvanceDlg, CDialog)
END_MESSAGE_MAP()


// CInkAdvanceDlg 消息处理程序
