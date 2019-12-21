// ConfigurationDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "ConfigurationDlg.h"


// CConfigurationDlg �Ի���

IMPLEMENT_DYNAMIC(CConfigurationDlg, CDialog)

CConfigurationDlg::CConfigurationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConfigurationDlg::IDD, pParent)
	, m_height(70)
	, m_dotPitch(0.423)
	, m_delay(100)
	, m_repeatDis(300)
	, m_speed(20)
{

}

CConfigurationDlg::~CConfigurationDlg()
{
}

void CConfigurationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_HEIGHT_EDIT, m_height);
	DDX_Control(pDX, IDC_REVERSE_COMBO, m_reverse);
	DDX_Control(pDX, IDC_INVERSE_COMBO, m_inverse);
	DDX_Text(pDX, IDC_DOT_PITCH_EDIT, m_dotPitch);
	DDX_Text(pDX, IDC_DELAY_EDIT, m_delay);
	DDX_Text(pDX, IDC_REPEAT_DIS_EDIT, m_repeatDis);
	DDX_Control(pDX, IDC_SPEED_WAY_COMBO, m_speedWay);
	DDX_Text(pDX, IDC_SPEED_EDIT, m_speed);
}


BEGIN_MESSAGE_MAP(CConfigurationDlg, CDialog)
	ON_BN_CLICKED(IDC_CONFI_CLOSE_BTN, &CConfigurationDlg::OnBnClickedConfiCloseBtn)
	ON_BN_CLICKED(IDC_PRINT_SET_BTN, &CConfigurationDlg::OnBnClickedPrintSetBtn)
	ON_BN_CLICKED(IDC_OUT_SET_BTN, &CConfigurationDlg::OnBnClickedOutSetBtn)
END_MESSAGE_MAP()


// CConfigurationDlg ��Ϣ�������

BOOL CConfigurationDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
    //��ť�����ʼ��
	m_ConfigPrintModeDlg = new CConfigPrintModeDlg;
	m_ConfigOutSetDlg = new CConfigOutSetDlg;


	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_ConfigPM= new CConfigPrintModeDlg;
	m_ConfigOS = new CConfigOutSetDlg;
	int nX = 0;
	int nY = 0;
	int nWidth = 800;
	int nHeight = 600;
	m_ConfigPM->Create(IDD_CONFIG_PRINT_MODE_DIALOG,this);
	m_ConfigPM->MoveWindow(nX,nY,nWidth,nHeight);
	m_ConfigPM->ShowWindow(SW_HIDE);
	m_ConfigOS->Create(IDD_CONFIG_OUTSET_DIALOG,this);
	m_ConfigOS->MoveWindow(nX,nY,nWidth,nHeight);
	m_ConfigOS->ShowWindow(SW_HIDE);

	m_reverse.AddString(L"OFF");
	m_reverse.AddString(L"ON");
	m_reverse.SetCurSel(0);

	m_inverse.AddString(L"OFF");
	m_inverse.AddString(L"ON");
	m_inverse.SetCurSel(0);

	m_speedWay.AddString(L"Fixed");
	m_speedWay.AddString(L"Variable");
	m_speedWay.SetCurSel(0);

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
	m_ConfigOS->ShowWindow(SW_HIDE);
	if (ID == IDD_CONFIG_PRINT_MODE_DIALOG)
	{
		m_ConfigPM->ShowWindow(SW_SHOW);
	}
	if (ID == IDD_CONFIG_OUTSET_DIALOG)
	{
		m_ConfigOS->ShowWindow(SW_SHOW);
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

void CConfigurationDlg::OnBnClickedOutSetBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	showConfigDlg(IDD_CONFIG_OUTSET_DIALOG);
}
