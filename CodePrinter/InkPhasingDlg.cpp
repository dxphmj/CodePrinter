// InkPhasingDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "InkPhasingDlg.h"


// CInkPhasingDlg 对话框

IMPLEMENT_DYNAMIC(CInkPhasingDlg, CDialog)

CInkPhasingDlg::CInkPhasingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInkPhasingDlg::IDD, pParent)
	, m_fixed(0)
{
}

CInkPhasingDlg::~CInkPhasingDlg()
{
}

void CInkPhasingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FIXED_EDIT, m_fixed);
}


BEGIN_MESSAGE_MAP(CInkPhasingDlg, CDialog)

		ON_WM_CTLCOLOR()

END_MESSAGE_MAP()


// CInkPhasingDlg 消息处理程序
HBRUSH CInkPhasingDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return theApp.m_DlgBrush;
}