// FileManaDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "FileManaDlg.h"


// CFileManaDlg �Ի���

IMPLEMENT_DYNAMIC(CFileManaDlg, CDialog)

CFileManaDlg::CFileManaDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileManaDlg::IDD, pParent)
{

}

CFileManaDlg::~CFileManaDlg()
{
}

void CFileManaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFileManaDlg, CDialog)
END_MESSAGE_MAP()


// CFileManaDlg ��Ϣ�������

BOOL CFileManaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetWindowPos(NULL,0,0,800,600,SWP_SHOWWINDOW );	
	CRect rect;
	GetWindowRect(&rect);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
