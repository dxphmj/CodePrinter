// UserOpenDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "UserOpenDlg.h"


// CUserOpenDlg �Ի���

IMPLEMENT_DYNAMIC(CUserOpenDlg, CDialog)

CUserOpenDlg::CUserOpenDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserOpenDlg::IDD, pParent)
{

}

CUserOpenDlg::~CUserOpenDlg()
{
}

void CUserOpenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUserOpenDlg, CDialog)
END_MESSAGE_MAP()


// CUserOpenDlg ��Ϣ�������
