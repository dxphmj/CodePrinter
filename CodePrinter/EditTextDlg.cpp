// EditTextDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "EditTextDlg.h"


// CEditTextDlg �Ի���

IMPLEMENT_DYNAMIC(CEditTextDlg, CDialog)

CEditTextDlg::CEditTextDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditTextDlg::IDD, pParent)
{

}

CEditTextDlg::~CEditTextDlg()
{
}

void CEditTextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEditTextDlg, CDialog)
END_MESSAGE_MAP()


// CEditTextDlg ��Ϣ�������

BOOL CEditTextDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetWindowPos(NULL,0,0,800,600,SWP_SHOWWINDOW );	
	CRect rect;
	GetWindowRect(&rect);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
