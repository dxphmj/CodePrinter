// UserOpenDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "UserOpenDlg.h"


// CUserOpenDlg �Ի���

IMPLEMENT_DYNAMIC(CUserOpenDlg, CDialog)

CUserOpenDlg::CUserOpenDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserOpenDlg::IDD, pParent)
{

}

CUserOpenDlg::~CUserOpenDlg()
{
}

void CUserOpenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NOT_GRANTED_LIST, m_notGranted);
	DDX_Control(pDX, IDC_GRANTED_LIST, m_granted);
}


BEGIN_MESSAGE_MAP(CUserOpenDlg, CDialog)
END_MESSAGE_MAP()


// CUserOpenDlg ��Ϣ�������

BOOL CUserOpenDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_notGranted.AddString(L"Set Productcounter");

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
