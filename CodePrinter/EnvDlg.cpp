// EnvDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "EnvDlg.h"


// CEnvDlg �Ի���

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


// CEnvDlg ��Ϣ�������

BOOL CEnvDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetWindowPos(NULL,0,0,800,450,SWP_SHOWWINDOW );	
	CRect rect;
	GetWindowRect(&rect);

	m_LanguageComboBox.AddString(_T("����"));
	m_LanguageComboBox.AddString(_T("Ӣ��"));


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
