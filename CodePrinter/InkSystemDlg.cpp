// InkSystemDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "InkSystemDlg.h"


// CInkSystemDlg �Ի���

IMPLEMENT_DYNAMIC(CInkSystemDlg, CDialog)

CInkSystemDlg::CInkSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInkSystemDlg::IDD, pParent)
{

}

CInkSystemDlg::~CInkSystemDlg()
{
}

void CInkSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInkSystemDlg, CDialog)
END_MESSAGE_MAP()


// CInkSystemDlg ��Ϣ�������

BOOL CInkSystemDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
