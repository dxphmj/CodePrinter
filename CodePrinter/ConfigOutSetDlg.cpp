// ConfigOutSet.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "ConfigOutSetDlg.h"


// CConfigOutSet �Ի���

IMPLEMENT_DYNAMIC(CConfigOutSetDlg, CDialog)

CConfigOutSetDlg::CConfigOutSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConfigOutSetDlg::IDD, pParent)
	
{

}

CConfigOutSetDlg::~CConfigOutSetDlg()
{
}

void CConfigOutSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX,IDC_PRINT_DIRE_LIST,m_printDire);
	DDX_Control(pDX,IDC_ENCODE_SIGN_LIST,m_encodeSign);
	DDX_Control(pDX,IDC_FREQ_MULTI_COMBO,FreqMulti);
	DDX_Control(pDX,IDC_PRODUCT_DETE_LIST,m_productDete);
	DDX_Control(pDX,IDC_ACTIVE_LEV_LIST,m_activeLev);
	DDX_Control(pDX,IDC_IMPULSE_EDIT,m_impulse);
	DDX_Control(pDX,IDC_LENGTH_EDIT,m_length);
	DDX_Control(pDX,IDC_CURRENT_LEV_EDIT,m_currentLev);
	DDX_Control(pDX,IDC_TRIGGER_LEN_EDIT,m_triggerLen);
}


BEGIN_MESSAGE_MAP(CConfigOutSetDlg, CDialog)
	ON_BN_CLICKED(IDC_CONFIG_OSRETURN_BTN, &CConfigOutSetDlg::OnBnClickedConfigOsreturnBtn)
END_MESSAGE_MAP()


// CConfigOutSet ��Ϣ�������
BOOL CConfigOutSetDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_printDire.AddString(_T("forward"));
	m_printDire.AddString(_T("Backward"));
	m_encodeSign.AddString(_T("1 Phase"));	
	m_encodeSign.AddString(_T("2 Phase"));	
	m_productDete.AddString(_T("OFF"));	
	m_productDete.AddString(_T("ON"));
	m_activeLev.AddString(_T("Low"));	
	m_activeLev.AddString(_T("High"));
	FreqMulti.AddString(_T("ON"));
	FreqMulti.AddString(_T("OFF"));
	FreqMulti.SetCurSel(1);	
	m_impulse.SetWindowText(_T(""));	
	m_length.SetWindowText(_T(""));		
	m_currentLev.SetWindowText(_T(""));		
	m_triggerLen.SetWindowText(_T(""));	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CConfigOutSetDlg::OnBnClickedConfigOsreturnBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->ShowWindow(SW_HIDE);
}
