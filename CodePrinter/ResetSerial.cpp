// ResetSerial.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "ResetSerial.h"
#include "CodePrinterDlg.h"

// CResetSerial 对话框

IMPLEMENT_DYNAMIC(CResetSerial, CDialog)

CResetSerial::CResetSerial(CWnd* pParent /*=NULL*/)
	: CDialog(CResetSerial::IDD, pParent)
{
	boDlgOpen=false;
}

CResetSerial::~CResetSerial()
{
}

void CResetSerial::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RESET_SERIAL1_BTN, ResetBtn1);
	DDX_Control(pDX, IDC_RESET_SERIAL2_BTN, ResetBtn2);
	DDX_Control(pDX, IDC_RESET_SERIAL3_BTN, ResetBtn3);
	DDX_Control(pDX, IDC_RESET_SERIAL4_BTN, ResetBtn4);
	DDX_Control(pDX, IDC_ALL_RESET_BTN, allResetBtn);
	DDX_Control(pDX, IDC_RESET_SERIAL_RETURN_BTN, resetSerialReturnBtn);
	DDX_Control(pDX, IDC_SERIAL1_STATIC, m_serialStatic1);
	DDX_Control(pDX, IDC_SERIAL2_STATIC, m_serialStatic2);
	DDX_Control(pDX, IDC_SERIAL3_STATIC, m_serialStatic3);
	DDX_Control(pDX, IDC_SERIAL4_STATIC, m_serialStatic4);
	DDX_Control(pDX, IDC_SERIAL1_QUAD1_STATIC, m_serial1_quad1_static);
	DDX_Control(pDX, IDC_SERIAL1_QUAD2_STATIC, m_serial1_quad2_static);
	DDX_Control(pDX, IDC_SERIAL2_QUAD1_STATIC, m_serial2_quad1_static);
	DDX_Control(pDX, IDC_SERIAL2_QUAD2_STATIC, m_serial2_quad2_static);
	DDX_Control(pDX, IDC_SERIAL3_QUAD1_STATIC, m_serial3_quad1_static);
	DDX_Control(pDX, IDC_SERIAL3_QUAD2_STATIC, m_serial3_quad2_static);
	DDX_Control(pDX, IDC_SERIAL4_QUAD1_STATIC, m_serial4_quad1_static);
	DDX_Control(pDX, IDC_SERIAL4_QUAD2_STATIC, m_serial4_quad2_static);
	DDX_Control(pDX, IDC_SERIAL1_CUR_STATIC, m_serial1_cur_static);
	DDX_Control(pDX, IDC_SERIAL2_CUR_STATIC, m_serial2_cur_static);
	DDX_Control(pDX, IDC_SERIAL3_CUR_STATIC, m_serial3_cur_static);
	DDX_Control(pDX, IDC_SERIAL4_CUR_STATIC, m_serial4_cur_static);

}

BEGIN_MESSAGE_MAP(CResetSerial, CDialog)
	ON_BN_CLICKED(IDC_RESET_SERIAL_RETURN_BTN, &CResetSerial::OnBnClickedResetSerialReturnBtn)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_RESET_SERIAL1_BTN, &CResetSerial::OnBnClickedResetSerial1Btn)
	ON_BN_CLICKED(IDC_RESET_SERIAL2_BTN, &CResetSerial::OnBnClickedResetSerial2Btn)
	ON_BN_CLICKED(IDC_RESET_SERIAL3_BTN, &CResetSerial::OnBnClickedResetSerial3Btn)
	ON_BN_CLICKED(IDC_RESET_SERIAL4_BTN, &CResetSerial::OnBnClickedResetSerial4Btn)
	ON_BN_CLICKED(IDC_ALL_RESET_BTN, &CResetSerial::OnBnClickedAllResetBtn)
END_MESSAGE_MAP()

// CResetSerial 消息处理程序

BOOL CResetSerial::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	ResetBtn1.LoadBitmaps(IDB_70_45_1_BITMAP,IDB_70_45_BITMAP,0,0,IDB_70_45_BITMAP,true);
	ResetBtn1.SizeToContent(); 
	ResetBtn2.LoadBitmaps(IDB_70_45_1_BITMAP,IDB_70_45_BITMAP,0,0,IDB_70_45_BITMAP,true);
	ResetBtn2.SizeToContent(); 
	ResetBtn3.LoadBitmaps(IDB_70_45_1_BITMAP,IDB_70_45_BITMAP,0,0,IDB_70_45_BITMAP,true);
	ResetBtn3.SizeToContent(); 
	ResetBtn4.LoadBitmaps(IDB_70_45_1_BITMAP,IDB_70_45_BITMAP,0,0,IDB_70_45_BITMAP,true);
	ResetBtn4.SizeToContent(); 
	resetSerialReturnBtn.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_80_55_BITMAP);
	resetSerialReturnBtn.SizeToContent(); 
	allResetBtn.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_80_55_BITMAP,true);
	allResetBtn.SizeToContent(); 

	GetDlgItem(IDC_RESET_SERIAL_NAME_STATIC)->SetFont(theApp.m_StaticFont);
	GetDlgItem(IDC_QUADRANT1_STATIC)->SetFont(theApp.m_StaticFont);
	GetDlgItem(IDC_QUADRANT2_STATIC)->SetFont(theApp.m_StaticFont);
	GetDlgItem(IDC_CUR_VALUE_STATIC)->SetFont(theApp.m_StaticFont);
	GetDlgItem(IDC_SET_VALUE_STATIC)->SetFont(theApp.m_StaticFont);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CResetSerial::OnBnClickedResetSerialReturnBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	boDlgOpen=false;
	this->ShowWindow(SW_HIDE);
}

HBRUSH CResetSerial::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return theApp.m_DlgBrush; 
}

void CResetSerial::OnBnClickedResetSerial1Btn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_MessagePrint.SerialCountSet[0] = true;
	theApp.m_MessagePrint.SerialCountNew = false;
	//CString tempNum;
	CCodePrinterDlg* mainDlg=(CCodePrinterDlg*)GetParent();
	mainDlg->m_Label->CreatePrintData();
}

void CResetSerial::OnBnClickedResetSerial2Btn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_MessagePrint.SerialCountSet[1] = true;
	theApp.m_MessagePrint.SerialCountNew = false;
	//CString tempNum;
	CCodePrinterDlg* mainDlg=(CCodePrinterDlg*)GetParent();
	mainDlg->m_Label->CreatePrintData();
}

void CResetSerial::OnBnClickedResetSerial3Btn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_MessagePrint.SerialCountSet[2] = true;
	theApp.m_MessagePrint.SerialCountNew = false;
	//CString tempNum;
	CCodePrinterDlg* mainDlg=(CCodePrinterDlg*)GetParent();
	mainDlg->m_Label->CreatePrintData();
}

void CResetSerial::OnBnClickedResetSerial4Btn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_MessagePrint.SerialCountSet[3] = true;
	theApp.m_MessagePrint.SerialCountNew = false;
	//CString tempNum;
	CCodePrinterDlg* mainDlg=(CCodePrinterDlg*)GetParent();
	mainDlg->m_Label->CreatePrintData();
}

void CResetSerial::OnBnClickedAllResetBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	memset(theApp.m_MessagePrint.SerialCountSet,true,4*sizeof(bool));
	theApp.m_MessagePrint.SerialCountNew = false;
	//CString tempNum;
	CCodePrinterDlg* mainDlg=(CCodePrinterDlg*)GetParent();
	mainDlg->m_Label->CreatePrintData();
}

BOOL CResetSerial::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	CEdit* pEdit1 = (CEdit*)GetDlgItem(IDC_SET_VALUE1_EDIT);
	CEdit* pEdit2 = (CEdit*)GetDlgItem(IDC_SET_VALUE2_EDIT);
	CEdit* pEdit3 = (CEdit*)GetDlgItem(IDC_SET_VALUE3_EDIT);
	CEdit* pEdit4 = (CEdit*)GetDlgItem(IDC_SET_VALUE4_EDIT);
	//CEdit* kEdit = (CEdit*)GetDlgItem(IDC_PASSWARD_EDIT);
	ASSERT(pEdit1 && pEdit1->GetSafeHwnd());
	ASSERT(pEdit2 && pEdit2->GetSafeHwnd());
	ASSERT(pEdit3 && pEdit3->GetSafeHwnd());
	ASSERT(pEdit4 && pEdit4->GetSafeHwnd());
	if(WM_LBUTTONDOWN == pMsg->message && pEdit1->GetSafeHwnd() == pMsg->hwnd)
	{
		CString str;
		pEdit1-> GetWindowText(str);

		CExportDlg myCExportDlg;
		str=myCExportDlg.GetInputText(str);
		pEdit1-> SetWindowText(str);
		return TRUE;
	}
	else if(WM_LBUTTONDOWN == pMsg->message && pEdit2->GetSafeHwnd() == pMsg->hwnd)
	{
		CString str;
		pEdit2-> GetWindowText(str);

		CExportDlg myCExportDlg;
		str=myCExportDlg.GetInputText(str);
		pEdit2-> SetWindowText(str);
		return TRUE;
	}
	else if(WM_LBUTTONDOWN == pMsg->message && pEdit3->GetSafeHwnd() == pMsg->hwnd)
	{
		CString str;
		pEdit3-> GetWindowText(str);

		CExportDlg myCExportDlg;
		str=myCExportDlg.GetInputText(str);
		pEdit3-> SetWindowText(str);
		return TRUE;
	}
	else if(WM_LBUTTONDOWN == pMsg->message && pEdit4->GetSafeHwnd() == pMsg->hwnd)
	{
		CString str;
		pEdit4-> GetWindowText(str);

		CExportDlg myCExportDlg;
		str=myCExportDlg.GetInputText(str);
		pEdit4-> SetWindowText(str);
		return TRUE;
	}


	return CDialog::PreTranslateMessage(pMsg);
}
