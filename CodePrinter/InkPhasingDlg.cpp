// InkPhasingDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "InkPhasingDlg.h"


// CInkPhasingDlg �Ի���

IMPLEMENT_DYNAMIC(CInkPhasingDlg, CDialog)

CInkPhasingDlg::CInkPhasingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInkPhasingDlg::IDD, pParent)
	, m_fixed(0)
{
}

CInkPhasingDlg::~CInkPhasingDlg()
{
}

void CInkPhasingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FIXED_EDIT, m_fixed);
}


BEGIN_MESSAGE_MAP(CInkPhasingDlg, CDialog)

		ON_WM_CTLCOLOR()

END_MESSAGE_MAP()


// CInkPhasingDlg ��Ϣ�������
HBRUSH CInkPhasingDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return theApp.m_DlgBrush;
}