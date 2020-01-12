// EnvDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "EnvDlg.h"
using namespace std;
// CEnvDlg 对话框

IMPLEMENT_DYNAMIC(CEnvDlg, CDialog)



CEnvDlg::CEnvDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEnvDlg::IDD, pParent)
{

}

CEnvDlg::~CEnvDlg()
{
}

void CEnvDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LANGUAGE_LIST, m_langeageList);
}


BEGIN_MESSAGE_MAP(CEnvDlg, CDialog)
	ON_CBN_SELCHANGE(IDC_LANGUAGE_LIST, &CEnvDlg::OnCbnSelchangeLanguageCombo)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CEnvDlg 消息处理程序

BOOL CEnvDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_langeageList.AddString(L"Arabic");
	m_langeageList.AddString(L"Chinese Simplified");
	m_langeageList.AddString(L"Chinese Traditional");
	m_langeageList.AddString(L"Czech");
	m_langeageList.AddString(L"Dutch");
	m_langeageList.AddString(L"English");
	m_langeageList.AddString(L"Estonian");
	m_langeageList.AddString(L"Farsi");
	m_langeageList.AddString(L"Finnish");
	m_langeageList.AddString(L"French");
	m_langeageList.AddString(L"German");
	m_langeageList.AddString(L"Hindi");
	m_langeageList.AddString(L"Hungarian");
	m_langeageList.AddString(L"Italian");
	m_langeageList.AddString(L"Japanese");
	m_langeageList.AddString(L"Kannada");
	m_langeageList.AddString(L"Korean");
	m_langeageList.AddString(L"Polish");
	m_langeageList.AddString(L"Portuguese");
	m_langeageList.AddString(L"Romanian");
	m_langeageList.AddString(L"Russian");
	m_langeageList.AddString(L"Serbian");
	m_langeageList.AddString(L"Spanish");
	m_langeageList.AddString(L"Swedish");
	m_langeageList.AddString(L"Tamil");
	m_langeageList.AddString(L"Thai");
	m_langeageList.AddString(L"Turkish");
	m_langeageList.AddString(L"Vietnamese");

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CEnvDlg::OnCbnSelchangeLanguageCombo()
{
	// TODO: 在此添加控件通知处理程序代码
	int nIndex = m_langeageList.GetCurSel();  //当前选中的项
	 bool isRead=false;
	switch(nIndex)
	{
	case 0:
        isRead= theApp.myLanguage.readLanguageXml("ChineseSimplified.xml");
		if (isRead)
		{
            string lantest=theApp.myLanguage.LanguageMap["IDC_LANGUAGE_STATIC"];
			GetDlgItem(IDC_LANGUAGE_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(lantest));
		}
		break;
	case 1:
		isRead= theApp.myLanguage.readLanguageXml("English.xml");
		if (isRead)
		{
			string lantest=theApp.myLanguage.LanguageMap["IDC_LANGUAGE_STATIC"];
			GetDlgItem(IDC_LANGUAGE_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(lantest));
		}
		break;
	default:
		return;
	}
}

HBRUSH CEnvDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
