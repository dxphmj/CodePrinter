// FaultDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "FaultDlg.h"


// CFaultDlg �Ի���

IMPLEMENT_DYNAMIC(CFaultDlg, CDialog)

CFaultDlg::CFaultDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFaultDlg::IDD, pParent)
{

}

CFaultDlg::~CFaultDlg()
{
}

void CFaultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFaultDlg, CDialog)
	ON_BN_CLICKED(IDC_FAULT_CLOSE_BTN, &CFaultDlg::OnBnClickedFaultCloseBtn)
END_MESSAGE_MAP()


// CFaultDlg ��Ϣ�������

BOOL CFaultDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CFaultDlg::OnBnClickedFaultCloseBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->ShowWindow(SW_HIDE);
}
