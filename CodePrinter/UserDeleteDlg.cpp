// UserDeleteDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "UserDeleteDlg.h"


// CUserDeleteDlg �Ի���

IMPLEMENT_DYNAMIC(CUserDeleteDlg, CDialog)

CUserDeleteDlg::CUserDeleteDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserDeleteDlg::IDD, pParent)
{

}

CUserDeleteDlg::~CUserDeleteDlg()
{
}

void CUserDeleteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUserDeleteDlg, CDialog)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CUserDeleteDlg ��Ϣ�������

HBRUSH CUserDeleteDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return theApp.m_DlgBrush;
}