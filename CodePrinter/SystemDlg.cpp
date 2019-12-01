// SystemDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "SystemDlg.h"
#include "EnvDlg.h"
#include "ComDlg.h"


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
	ON_BN_CLICKED(IDC_BUTTON4, &CSystemDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CSystemDlg ��Ϣ�������

BOOL CSystemDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetWindowPos(NULL,0,0,800,600,SWP_SHOWWINDOW );	
	CRect rect;
	GetWindowRect(&rect);
	
	//���ð�ť��λ�ü���С
	GetDlgItem(IDC_SYSTEM_CANCEL_BTN)->SetWindowPos(NULL,10,480,70,45,SWP_SHOWWINDOW);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CSystemDlg::OnBnClickedEvnButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CEnvDlg m_Evn;
	m_Evn.DoModal();
}

void CSystemDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CComDlg m_cd;
	m_cd.DoModal();
}
