// ComDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "ComDlg.h"


// CComDlg �Ի���

IMPLEMENT_DYNAMIC(CComDlg, CDialog)

CComDlg::CComDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CComDlg::IDD, pParent)
{

}

CComDlg::~CComDlg()
{
}

void CComDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CComDlg, CDialog)
END_MESSAGE_MAP()


// CComDlg ��Ϣ�������

BOOL CComDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//SetWindowPos(NULL,0,0,800,450,SWP_SHOWWINDOW );	
	//CRect rect;
	//GetWindowRect(&rect);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
