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
	ON_BN_CLICKED(IDC_FILEMANA_CLOSE_BTN, &CFileManaDlg::OnBnClickedFilemanaCloseBtn)
END_MESSAGE_MAP()


// CFileManaDlg ��Ϣ�������

BOOL CFileManaDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CFileManaDlg::OnBnClickedFilemanaCloseBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->ShowWindow(SW_HIDE);
}
