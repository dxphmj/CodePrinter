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
	DDX_Control(pDX, IDC_LANGUAGE_COMBO, m_LanguageComboBox);
}


BEGIN_MESSAGE_MAP(CEnvDlg, CDialog)
	ON_CBN_SELCHANGE(IDC_LANGUAGE_COMBO, &CEnvDlg::OnCbnSelchangeLanguageCombo)
END_MESSAGE_MAP()


// CEnvDlg 消息处理程序

BOOL CEnvDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetWindowPos(NULL,0,0,800,450,SWP_SHOWWINDOW );	
	CRect rect;
	GetWindowRect(&rect);

	m_LanguageComboBox.AddString(_T("中文简体"));
	m_LanguageComboBox.AddString(_T("English"));


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CEnvDlg::OnCbnSelchangeLanguageCombo()
{
	// TODO: 在此添加控件通知处理程序代码
	int nIndex = m_LanguageComboBox.GetCurSel();  //当前选中的项
	 bool isRead=false;
	switch(nIndex)
	{
	case 0:
        isRead= theApp.myLanguage.readLanguageXml("ChineseSimplified.xml");
		if (isRead)
		{
            string lantest=theApp.myLanguage.LanguageMap["IDC_LANGUAGE_STATIC"];
			GetDlgItem(IDC_LANGUAGE_STATIC)->SetWindowText(envModule.stringToLPCWSTR(lantest));
		}
		break;
	case 1:
		isRead= theApp.myLanguage.readLanguageXml("English.xml");
		if (isRead)
		{
			string lantest=theApp.myLanguage.LanguageMap["IDC_LANGUAGE_STATIC"];
			GetDlgItem(IDC_LANGUAGE_STATIC)->SetWindowText(envModule.stringToLPCWSTR(lantest));
		}
		break;
	default:
		return;
	}
}
