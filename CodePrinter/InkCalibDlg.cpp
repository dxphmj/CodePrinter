// InkCalibDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "InkCalibDlg.h"
#include "CodePrinterDlg.h"


// CInkCalibDlg 对话框

IMPLEMENT_DYNAMIC(CInkCalibDlg, CDialog)

CInkCalibDlg::CInkCalibDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInkCalibDlg::IDD, pParent)
{

}

CInkCalibDlg::~CInkCalibDlg()
{
}

void CInkCalibDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CALIB_NEXT1_BTN, m_CalibNext1IB);
	DDX_Control(pDX, IDC_CALIB_NEXT2_BTN, m_CalibNext2IB);
	DDX_Control(pDX, IDC_CALIB_RETURN_BTN, m_CalibReturnIB);
}


BEGIN_MESSAGE_MAP(CInkCalibDlg, CDialog)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_CALIB_NEXT1_BTN, &CInkCalibDlg::OnBnClickedCalibNext1Btn)
	ON_BN_CLICKED(IDC_CALIB_NEXT2_BTN, &CInkCalibDlg::OnBnClickedCalibNext2Btn)
	ON_BN_CLICKED(IDC_CALIB_RETURN_BTN, &CInkCalibDlg::OnBnClickedCalibReturnBtn)
END_MESSAGE_MAP()


// CInkCalibDlg 消息处理程序

BOOL CInkCalibDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	GetDlgItem(IDC_CALIB_RETURN_BTN)->SetWindowPos(NULL,30,420,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_CALIB_NEXT1_BTN)->SetWindowPos(NULL,350,420,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_CALIB_NEXT2_BTN)->SetWindowPos(NULL,550,420,80,55,SWP_SHOWWINDOW);

	////彩色按钮
	m_CalibReturnIB.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RETURN1_BITMAP);
	m_CalibReturnIB.SizeToContent();
	m_CalibNext1IB.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_80_55_BITMAP,true);
	m_CalibNext1IB.SizeToContent();
	m_CalibNext2IB.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_80_55_BITMAP,true);
	m_CalibNext2IB.SizeToContent();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

HBRUSH CInkCalibDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

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
	// TODO:  在此更改 DC 的任何属性
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return theApp.m_DlgBrush;
}


void CInkCalibDlg::OnBnClickedCalibNext1Btn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->GetDlgItem(IDC_CALIB_NEXT1_BTN)->ShowWindow(SW_HIDE);
	this->GetDlgItem(IDC_CALIB_NEXT2_BTN)->ShowWindow(SW_SHOW);
	wstring tempstr;
	if ( LevCal_type.CompareNoCase(_T("Ink")) == 0 )//墨水液位校准
	{
		tempstr=theApp.myLanguage.LanguageMap["Installsensorandplugininkcartridgetoaddoinknolongerautomatically"];
		this->GetDlgItem(IDC_INK_SOL_CALIB_STATIC)->SetWindowText(tempstr.c_str());
	} 
	else//溶剂液位校准
	{
		tempstr=theApp.myLanguage.LanguageMap["Installsensorandpluginsolventcartridgetoaddtosolventnolongerautomatically"];
		this->GetDlgItem(IDC_INK_SOL_CALIB_STATIC)->SetWindowText(tempstr.c_str());
	}

}

void CInkCalibDlg::OnBnClickedCalibNext2Btn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
	((CCodePrinterDlg*)GetParent()->GetParent()->GetParent())->m_PicHead.SetSecondLineOpeString(_T(""));
}

void CInkCalibDlg::OnBnClickedCalibReturnBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
	((CCodePrinterDlg*)GetParent()->GetParent()->GetParent())->m_PicHead.SetSecondLineOpeString(_T(""));
}


