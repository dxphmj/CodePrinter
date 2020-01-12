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
	tempstr=theApp.myLanguage.LanguageMap["ID_CONFIGURATION_MANAGEMENT"];
	cstr = tempstr.c_str();
	((CCodePrinterDlg*)GetParent()->GetParent())->m_PicHead.SetOperationString(cstr);//User Manage 
}

BOOL CConfigPrintModeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_printMode.AddString(L"OFF");
	m_printMode.AddString(L"Continuous");
	m_printMode.SetCurSel(0);

	m_workList.AddString(L"OFF");
	m_workList.AddString(L"ON");
	m_workList.SetCurSel(0);

	m_virtualPrint.AddString(L"OFF");
	m_virtualPrint.AddString(L"ON");
	m_virtualPrint.SetCurSel(0);

	GetDlgItem(IDC_CONFIG_CLOSE_BTN)->SetWindowPos(NULL,20,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_CONFIG_OK_BTN)->SetWindowPos(NULL,700,390,70,45,SWP_SHOWWINDOW);

	m_returnIB.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_returnIB.SizeToContent(); 
	m_okIB.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_okIB.SizeToContent(); 


	//////////////////////////////////////////////////////////////////////////
	pNumKey = new CNumKey();
	pNumKey->Create( IDD_DIALOG_NUMKEY,this);  
	pNumKey->ShowWindow(SW_HIDE);
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
	dlg->OpenNumKeyBoard(pEdit);
}

void CConfigPrintModeDlg::OnBnClickedConfigOkBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	CConfigurationDlg* dlg;
	dlg = (CConfigurationDlg*)(GetParent());

	dlg->OnBnClickedSavePcf();

}
