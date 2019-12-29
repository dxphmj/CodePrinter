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
	DDX_Control(pDX, IDC_EDITFIG_CLOSE_BTN, m_returnIB);
	DDX_Control(pDX, IDC_EDITFIGURE_OK_BTN, m_okIB);
}


BEGIN_MESSAGE_MAP(CEditFigureDlg, CDialog)
	ON_BN_CLICKED(IDC_EDITFIG_CLOSE_BTN, &CEditFigureDlg::OnBnClickedEditfigCloseBtn)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CEditFigureDlg 消息处理程序

BOOL CEditFigureDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetWindowPos(NULL,0,0,800,600,SWP_SHOWWINDOW );	
	CRect rect;
	GetWindowRect(&rect);

	GetDlgItem(IDC_EDITFIG_CLOSE_BTN)->SetWindowPos(NULL,20,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_EDITFIGURE_OK_BTN)->SetWindowPos(NULL,700,390,70,45,SWP_SHOWWINDOW);

	m_returnIB.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_returnIB.SizeToContent(); 
	m_okIB.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_okIB.SizeToContent(); 

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CEditFigureDlg::OnBnClickedEditfigCloseBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
}

HBRUSH CEditFigureDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return theApp.m_DlgBrush;
}
