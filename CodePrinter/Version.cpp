// Version.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "Version.h"


// CVersion 对话框

IMPLEMENT_DYNAMIC(CVersion, CDialog)

CVersion::CVersion(CWnd* pParent /*=NULL*/)
	: CDialog(CVersion::IDD, pParent)
{

}

CVersion::~CVersion()
{
}

void CVersion::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CVersion, CDialog)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CVersion 消息处理程序

BOOL CVersion::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

HBRUSH CVersion::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if(nCtlColor == CTLCOLOR_STATIC)
	{		 
		pDC->SelectObject(theApp.m_StaticFont);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));	
	}
	// TODO:  在此更改 DC 的任何属性
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return theApp.m_DlgBrush;
}