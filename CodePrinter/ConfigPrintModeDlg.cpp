// ConfigPrintModeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "ConfigPrintModeDlg.h"


// CConfigPrintModeDlg �Ի���

IMPLEMENT_DYNAMIC(CConfigPrintModeDlg, CDialog)

CConfigPrintModeDlg::CConfigPrintModeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConfigPrintModeDlg::IDD, pParent)
	, m_repeatCount(0)
{

}

CConfigPrintModeDlg::~CConfigPrintModeDlg()
{
}

void CConfigPrintModeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PRINT_MODE_LIST, m_printMode);
	DDX_Control(pDX, IDC_WORK_LIST_LIST, m_workList);
	DDX_Text(pDX, IDC_REAPEAT_COUNT_EDIT, m_repeatCount);
	DDX_Control(pDX, IDC_VIRTUAL_PRINT_LIST, m_virtualPrint);
}


BEGIN_MESSAGE_MAP(CConfigPrintModeDlg, CDialog)
	ON_BN_CLICKED(IDC_CONFIG_CLOSE_BTN, &CConfigPrintModeDlg::OnBnClickedConfigCloseBtn)
END_MESSAGE_MAP()


// CConfigPrintModeDlg ��Ϣ�������

void CConfigPrintModeDlg::OnBnClickedConfigCloseBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->ShowWindow(SW_HIDE);
}

BOOL CConfigPrintModeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_printMode.AddString(L"OFF");
	m_printMode.AddString(L"Continuous");
	m_printMode.SetCurSel(0);

	m_workList.AddString(L"OFF");
	m_workList.AddString(L"ON");
	m_workList.SetCurSel(0);

	m_virtualPrint.AddString(L"OFF");
	m_virtualPrint.AddString(L"ON");
	m_virtualPrint.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
