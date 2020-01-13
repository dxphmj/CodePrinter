// DateDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "DateDlg.h"


// CDateDlg 对话框

IMPLEMENT_DYNAMIC(CDateDlg, CDialog)

CDateDlg::CDateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDateDlg::IDD, pParent)
{

}

CDateDlg::~CDateDlg()
{
}

void CDateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATE_CLOSE_BTN, m_returnIB);
	DDX_Control(pDX, IDC_DATE_OK_BTN, m_okIB);
	DDX_Control(pDX, IDC_DATE_REFRESH_BTN, m_freshIB);
	DDX_Control(pDX, IDC_DATE_SKEW_VALUE_EDIT, m_skewValue);
}


BEGIN_MESSAGE_MAP(CDateDlg, CDialog)
	ON_BN_CLICKED(IDC_DATE_CLOSE_BTN, &CDateDlg::OnBnClickedDateCloseBtn)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CDateDlg 消息处理程序

BOOL CDateDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CRect rect;
	GetWindowRect(&rect);

	GetDlgItem(IDC_DATE_CLOSE_BTN)->SetWindowPos(NULL,20,420,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_DATE_OK_BTN)->SetWindowPos(NULL,700,420,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_DATE_REFRESH_BTN)->SetWindowPos(NULL,500,420,70,45,SWP_SHOWWINDOW);

	m_returnIB.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_returnIB.SizeToContent(); 
	m_okIB.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_okIB.SizeToContent(); 
	m_freshIB.LoadBitmaps(IDB_FRESH1_BITMAP,IDB_FRESH2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_freshIB.SizeToContent(); 

	m_skewValue.SetFont(theApp.m_EditFont);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CDateDlg::OnBnClickedDateCloseBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
}

HBRUSH CDateDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	if(nCtlColor == CTLCOLOR_STATIC)
	{		 
		pDC->SelectObject(theApp.m_StaticFont);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));	
		return theApp.m_StaticBrush;
	}
	if(nCtlColor == CTLCOLOR_EDIT)
	{ 
	// 	pDC->SelectObject(theApp.m_EditFont);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));	
		return theApp.m_StaticBrush;
	}
	if(nCtlColor == CTLCOLOR_LISTBOX)
	{
		pDC->SelectObject(theApp.m_ListBoxFont);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));	
		return theApp.m_ListBoxBrush;
	}
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return theApp.m_DlgBrush;
}