// SystemDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "SystemDlg.h"
#include "EnvDlg.h"


// CSystemDlg �Ի���

IMPLEMENT_DYNAMIC(CSystemDlg, CDialog)

CSystemDlg::CSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSystemDlg::IDD, pParent)
{

}

CSystemDlg::~CSystemDlg()
{
}

void CSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSystemDlg, CDialog)
	ON_BN_CLICKED(IDC_EVN_BTN, &CSystemDlg::OnBnClickedEvnButton)
END_MESSAGE_MAP()


// CSystemDlg ��Ϣ�������

BOOL CSystemDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetWindowPos(NULL,0,0,800,600,SWP_SHOWWINDOW );	
	CRect rect;
	GetWindowRect(&rect);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CSystemDlg::OnBnClickedEvnButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CEnvDlg m_Evn;
	m_Evn.DoModal();
}
