// Version.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "Version.h"


// CVersion �Ի���

IMPLEMENT_DYNAMIC(CVersion, CDialog)

CVersion::CVersion(CWnd* pParent /*=NULL*/)
	: CDialog(CVersion::IDD, pParent)
{

}

CVersion::~CVersion()
{
}

void CVersion::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CVersion, CDialog)
END_MESSAGE_MAP()


// CVersion ��Ϣ�������

BOOL CVersion::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
