// PictureDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "PictureDlg.h"


// CPictureDlg �Ի���

IMPLEMENT_DYNAMIC(CPictureDlg, CDialog)

CPictureDlg::CPictureDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPictureDlg::IDD, pParent)
{

}

CPictureDlg::~CPictureDlg()
{
}

void CPictureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPictureDlg, CDialog)
	ON_BN_CLICKED(IDC_PICTURE_CLOSE_BUTTON, &CPictureDlg::OnBnClickedPictureCloseButton)
END_MESSAGE_MAP()


// CPictureDlg ��Ϣ�������

BOOL CPictureDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CPictureDlg::OnBnClickedPictureCloseButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->ShowWindow(SW_HIDE);
}
