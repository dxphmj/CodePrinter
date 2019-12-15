// ConfigurationDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "ConfigurationDlg.h"


// CConfigurationDlg �Ի���

IMPLEMENT_DYNAMIC(CConfigurationDlg, CDialog)

CConfigurationDlg::CConfigurationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConfigurationDlg::IDD, pParent)
{

}

CConfigurationDlg::~CConfigurationDlg()
{
}

void CConfigurationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CConfigurationDlg, CDialog)
	ON_BN_CLICKED(IDC_CONFI_CLOSE_BTN, &CConfigurationDlg::OnBnClickedConfiCloseBtn)
	ON_BN_CLICKED(IDC_PRINT_SET_BTN, &CConfigurationDlg::OnBnClickedPrintSetBtn)
END_MESSAGE_MAP()


// CConfigurationDlg ��Ϣ�������

BOOL CConfigurationDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_ConfigPM= new CConfigPrintModeDlg;
	int nX = 0;
	int nY = 0;
	int nWidth = 800;
	int nHeight = 600;
	m_ConfigPM->Create(IDD_CONFIG_PRINT_MODE_DIALOG,this);
	m_ConfigPM->MoveWindow(nX,nY,nWidth,nHeight);
	m_ConfigPM->ShowWindow(SW_HIDE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CConfigurationDlg::OnBnClickedConfiCloseBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->ShowWindow(SW_HIDE);
	showConfigDlg(0);
}

void CConfigurationDlg::showConfigDlg(int ID)
{
	m_ConfigPM->ShowWindow(SW_HIDE);
	if (ID == IDD_CONFIG_PRINT_MODE_DIALOG)
	{
		m_ConfigPM->ShowWindow(SW_SHOW);
	}
	else if (0)
	{
		return;
	}

}

void CConfigurationDlg::OnBnClickedPrintSetBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	showConfigDlg(IDD_CONFIG_PRINT_MODE_DIALOG);
}
