// ConfigPrintModeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "ConfigPrintModeDlg.h"


// CConfigPrintModeDlg �Ի���

IMPLEMENT_DYNAMIC(CConfigPrintModeDlg, CDialog)

CConfigPrintModeDlg::CConfigPrintModeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConfigPrintModeDlg::IDD, pParent)
{

}

CConfigPrintModeDlg::~CConfigPrintModeDlg()
{
}

void CConfigPrintModeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
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
