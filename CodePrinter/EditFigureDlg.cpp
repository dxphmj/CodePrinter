// EditFigureDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "EditFigureDlg.h"


// CEditFigureDlg 对话框

IMPLEMENT_DYNAMIC(CEditFigureDlg, CDialog)

CEditFigureDlg::CEditFigureDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditFigureDlg::IDD, pParent)
{

}

CEditFigureDlg::~CEditFigureDlg()
{
}

void CEditFigureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEditFigureDlg, CDialog)
END_MESSAGE_MAP()


// CEditFigureDlg 消息处理程序

BOOL CEditFigureDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetWindowPos(NULL,0,0,800,600,SWP_SHOWWINDOW );	
	CRect rect;
	GetWindowRect(&rect);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
