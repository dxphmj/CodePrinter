// ConfigPrintModeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "ConfigPrintModeDlg.h"
#include "ConfigurationDlg.h"
#include "CodePrinterDlg.h"


// CConfigPrintModeDlg 对话框

IMPLEMENT_DYNAMIC(CConfigPrintModeDlg, CDialog)

CConfigPrintModeDlg::CConfigPrintModeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConfigPrintModeDlg::IDD, pParent)
	, m_repeatCount(0)
{

}

CConfigPrintModeDlg::~CConfigPrintModeDlg()
{
}

void CConfigPrintModeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PRINT_MODE_LIST, m_printMode);
	DDX_Control(pDX, IDC_WORK_LIST_LIST, m_workList);
	DDX_Text(pDX, IDC_REAPEAT_COUNT_EDIT, m_repeatCount);
	DDX_Control(pDX, IDC_VIRTUAL_PRINT_LIST, m_virtualPrint);

	DDX_Control(pDX, IDC_CONFIG_CLOSE_BTN, m_returnIB);
	DDX_Control(pDX, IDC_CONFIG_OK_BTN, m_okIB);
	DDX_Control(pDX, IDC_REAPEAT_COUNT_EDIT, m_edit_repeatCount);
	DDX_Control(pDX, IDC_PRINT_MODE_STATIC, m_printModeStatic);
	DDX_Control(pDX, IDC_WORK_LIST_STATIC, m_workListStatic);
	DDX_Control(pDX, IDC_REAPEAT_COUNT_STATIC, m_reapeatCountStatic);
	DDX_Control(pDX, IDC_VIRTUAL_PRINT_STATIC, m_virtualPrintStatic);
}


BEGIN_MESSAGE_MAP(CConfigPrintModeDlg, CDialog)
	ON_BN_CLICKED(IDC_CONFIG_CLOSE_BTN, &CConfigPrintModeDlg::OnBnClickedConfigCloseBtn)
	ON_WM_CTLCOLOR()

	ON_EN_SETFOCUS(IDC_REAPEAT_COUNT_EDIT, &CConfigPrintModeDlg::OnEnSetfocusReapeatCountEdit)

	ON_LBN_SELCHANGE(IDC_PRINT_MODE_LIST, &CConfigPrintModeDlg::OnLbnSelchangePrintModeList)

	ON_BN_CLICKED(IDC_CONFIG_OK_BTN, &CConfigPrintModeDlg::OnBnClickedConfigOkBtn)
END_MESSAGE_MAP()


// CConfigPrintModeDlg 消息处理程序

void CConfigPrintModeDlg::OnLbnSelchangePrintModeList()
{
	// TODO: 在此添加控件通知处理程序代码

	CConfigurationDlg *pParent = (CConfigurationDlg *)GetParent();
	pParent->pcf_diagram_select();
}


void CConfigPrintModeDlg::OnBnClickedConfigCloseBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
	wstring tempstr;
	CString cstr;
	CCodePrinterDlg *pCodeDlg = (CCodePrinterDlg*)this->GetParent()->GetParent();//获取主对话框指针
	tempstr=theApp.myLanguage.LanguageMap["ID_CONFIGURATION_MANAGEMENT"];
	cstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(tempstr.c_str());
	((CCodePrinterDlg*)GetParent()->GetParent())->m_PicHead.SetOperationString(cstr);//User Manage 
}

BOOL CConfigPrintModeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_printMode.AddString(L"Single");
	m_printMode.AddString(L"Continuous");
	m_printMode.AddString(L"Repetition");

	m_printMode.SetCurSel(0);
	m_printMode.SetItemHeight(0,20);

	m_workList.AddString(L"OFF");
	m_workList.AddString(L"ON");
	m_workList.SetCurSel(0);
	m_workList.SetItemHeight(0,20);

	m_virtualPrint.AddString(L"OFF");
	m_virtualPrint.AddString(L"ON");
	m_virtualPrint.SetCurSel(0);
	m_virtualPrint.SetItemHeight(0,20);

	GetDlgItem(IDC_CONFIG_CLOSE_BTN)->SetWindowPos(NULL,20,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_CONFIG_OK_BTN)->SetWindowPos(NULL,700,390,70,45,SWP_SHOWWINDOW);

	m_returnIB.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_returnIB.SizeToContent(); 
	m_okIB.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_okIB.SizeToContent(); 

	m_edit_repeatCount.SetFont(theApp.m_EditFont);
	 
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

HBRUSH CConfigPrintModeDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
void CConfigPrintModeDlg::OnEnSetfocusReapeatCountEdit()
{
	// TODO: 在此添加控件通知处理程序代码

	CEdit *pEdit = &m_edit_repeatCount;

	CCodePrinterDlg* dlg;
	dlg = (CCodePrinterDlg*)(GetParent()->GetParent());
	dlg->OpenNumKeyBoard(pEdit,4);
}

void CConfigPrintModeDlg::OnBnClickedConfigOkBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	CConfigurationDlg* dlg;
	dlg = (CConfigurationDlg*)(GetParent());

	dlg->OnBnClickedSavePcf();
	this->ShowWindow(SW_HIDE);

}
