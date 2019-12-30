// ConfigOutSet.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "ConfigOutSetDlg.h"


// CConfigOutSet �Ի���

IMPLEMENT_DYNAMIC(CConfigOutSetDlg, CDialog)

CConfigOutSetDlg::CConfigOutSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConfigOutSetDlg::IDD, pParent)
	,m_currentLevelStr("High")
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
	DDX_Control(pDX,IDC_FREQ_MULTI_COMBO,m_FreqMulti);
	DDX_Control(pDX,IDC_PRODUCT_DETE_LIST,m_productDete);
	DDX_Control(pDX,IDC_ACTIVE_LEV_LIST,m_activeLev);
	DDX_Control(pDX,IDC_IMPULSE_EDIT,m_impulse);
	DDX_Control(pDX,IDC_LENGTH_EDIT,m_length);
	DDX_Control(pDX,IDC_CURRENT_LEV_EDIT,m_currentLevel);
	DDX_Control(pDX,IDC_TRIGGER_LEN_EDIT,m_triggerLen);
	DDX_Text(pDX, IDC_CURRENT_LEV_EDIT, m_currentLevelStr);

	DDX_Control(pDX, IDC_CONFIG_OSRETURN_BTN, m_outSetReturn);
	DDX_Control(pDX, IDC_OUTSET_OK_BTN, m_outSetOk);
}


BEGIN_MESSAGE_MAP(CConfigOutSetDlg, CDialog)
	ON_BN_CLICKED(IDC_CONFIG_OSRETURN_BTN, &CConfigOutSetDlg::OnBnClickedConfigOsreturnBtn)
	ON_WM_CTLCOLOR()
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
	m_FreqMulti.AddString(_T("ON"));
	m_FreqMulti.AddString(_T("OFF"));
	m_FreqMulti.SetCurSel(1);	
	m_impulse.SetWindowText(_T("2500"));	
	m_length.SetWindowText(_T("200"));		
	m_currentLevel.SetWindowText(_T("High"));	 
	m_triggerLen.SetWindowText(_T("300"));	

	GetDlgItem(IDC_CONFIG_OSRETURN_BTN)->SetWindowPos(NULL,20,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_OUTSET_OK_BTN)->SetWindowPos(NULL,700,390,70,45,SWP_SHOWWINDOW);

	m_outSetReturn.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_outSetReturn.SizeToContent(); 
	m_outSetOk.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_outSetOk.SizeToContent(); 
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CConfigOutSetDlg::OnBnClickedConfigOsreturnBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->ShowWindow(SW_HIDE);
}

HBRUSH CConfigOutSetDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return theApp.m_DlgBrush;
}
