// UserFreshDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "UserFreshDlg.h"


// CUserFreshDlg �Ի���

IMPLEMENT_DYNAMIC(CUserFreshDlg, CDialog)

CUserFreshDlg::CUserFreshDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserFreshDlg::IDD, pParent)
{

}

CUserFreshDlg::~CUserFreshDlg()
{
}

void CUserFreshDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUserFreshDlg, CDialog)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CUserFreshDlg ��Ϣ�������

HBRUSH CUserFreshDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return theApp.m_DlgBrush;
}