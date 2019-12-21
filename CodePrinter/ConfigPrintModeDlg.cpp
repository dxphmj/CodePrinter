// ConfigPrintModeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "ConfigPrintModeDlg.h"


// CConfigPrintModeDlg �Ի���

IMPLEMENT_DYNAMIC(CConfigPrintModeDlg, CDialog)

CConfigPrintModeDlg::CConfigPrintModeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConfigPrintModeDlg::IDD, pParent)
	, m_reapeatCount(0)
{

}

CConfigPrintModeDlg::~CConfigPrintModeDlg()
{
}

void CConfigPrintModeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PRINT_MODE_LIST, m_printModeList);
	DDX_Control(pDX, IDC_WORK_LIST_LIST, m_workListList);
	DDX_Control(pDX, IDC_VIRTUAL_PRINT_LIST, m_virtualPrintList);
	DDX_Text(pDX, IDC_REAPEAT_COUNT_EDIT, m_reapeatCount);
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
