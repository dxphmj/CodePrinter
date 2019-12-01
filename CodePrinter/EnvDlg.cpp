// EnvDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "EnvDlg.h"


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
END_MESSAGE_MAP()


// CEnvDlg 消息处理程序

BOOL CEnvDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetWindowPos(NULL,0,0,800,450,SWP_SHOWWINDOW );	
	CRect rect;
	GetWindowRect(&rect);

	m_LanguageComboBox.AddString(_T("中文"));
	m_LanguageComboBox.AddString(_T("英文"));


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
