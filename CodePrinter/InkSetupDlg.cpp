// InkSetupDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "InkSetupDlg.h"


// CInkSetupDlg �Ի���

IMPLEMENT_DYNAMIC(CInkSetupDlg, CDialog)

CInkSetupDlg::CInkSetupDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInkSetupDlg::IDD, pParent)
	, m_nextService(3000)
	, m_inkLifeTime(1200)
{

}

CInkSetupDlg::~CInkSetupDlg()
{
}

void CInkSetupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NEXT_SERVICE_EDIT, m_nextService);
	DDX_Text(pDX, IDC_INK_LIFE_TIME_EDIT, m_inkLifeTime);
	DDX_Control(pDX, IDC_SIZE_LIST, m_sizeList);
	DDX_Control(pDX, IDC_MODUL_FRE_LIST, m_modulFreList);
	DDX_Control(pDX, IDC_INK_TYPE_LIST, m_inkTypeList);
	DDX_Control(pDX, IDC_PELTIER_LIST, m_peltierList);
	DDX_Control(pDX, IDC_SLEEP_LIST, m_sleepList);
}


BEGIN_MESSAGE_MAP(CInkSetupDlg, CDialog)
END_MESSAGE_MAP()


// CInkSetupDlg ��Ϣ�������

BOOL CInkSetupDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_sizeList.AddString(L"40");
	m_sizeList.AddString(L"50");
	m_sizeList.AddString(L"60");
	m_sizeList.SetCurSel(2);

	m_modulFreList.AddString(L"64000");
	m_modulFreList.AddString(L"78000");
	m_modulFreList.AddString(L"96000");
	m_modulFreList.SetCurSel(0);

	m_inkTypeList.AddString(L"236");
	m_inkTypeList.AddString(L"252");
	m_inkTypeList.AddString(L"261");
	m_inkTypeList.SetCurSel(0);

	m_peltierList.AddString(L"OFF");
	m_peltierList.AddString(L"ON");
	m_peltierList.SetCurSel(0);

	m_sleepList.AddString(L"OFF");
	m_sleepList.AddString(L"ON");
	m_sleepList.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
