// OnOffDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "OnOffDlg.h"


// COnOffDlg �Ի���

IMPLEMENT_DYNAMIC(COnOffDlg, CDialog)

COnOffDlg::COnOffDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COnOffDlg::IDD, pParent)
{

}

COnOffDlg::~COnOffDlg()
{
}

void COnOffDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(COnOffDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	ON_BN_CLICKED(IDC_SEQUENCE_BTN, &COnOffDlg::OnBnClickedSequenceButton)
	ON_BN_CLICKED(IDC_FAST_BTN, &COnOffDlg::OnBnClickedFastButton)
	ON_BN_CLICKED(IDC_RETURN_BTN, &COnOffDlg::OnBnClickedReturnBtn)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// ��������
void COnOffDlg::OnBnClickedSequenceButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (theApp.myStatusClass.ctr0X00bit0==0)
	{
		theApp.myStatusClass.ctr0X00bit5 = 0;
		theApp.myStatusClass.ctr0X00bit3 = 0;
		theApp.myStatusClass.ctr0X00bit2 = 0;
		theApp.myStatusClass.ctr0X00bit1 = 0;
		theApp.myStatusClass.ctr0X00bit0 = 1;
	}
	else if (theApp.myStatusClass.ctr0X00bit0==1)
	{
		theApp.myStatusClass.ctr0X00bit5 = 0;
		theApp.myStatusClass.ctr0X00bit3 = 0;
		theApp.myStatusClass.ctr0X00bit2 = 0;
		theApp.myStatusClass.ctr0X00bit1 = 0;
		theApp.myStatusClass.ctr0X00bit0 = 0;
	}
	theApp.myStatusClass.download_inksystem_control00();
	this->OnCancel();
	//this->ShowWindow(SW_HIDE);
}
//���ٿ���
void COnOffDlg::OnBnClickedFastButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (theApp.myStatusClass.ctr0X00bit0==0)
	{
		theApp.myStatusClass.ctr0X00bit5 = 0;
		theApp.myStatusClass.ctr0X00bit3 = 0;
		theApp.myStatusClass.ctr0X00bit2 = 0;
		theApp.myStatusClass.ctr0X00bit1 = 1;
		theApp.myStatusClass.ctr0X00bit0 = 1;
	}
	else if (theApp.myStatusClass.ctr0X00bit0==1)
	{
		theApp.myStatusClass.ctr0X00bit5 = 0;
		theApp.myStatusClass.ctr0X00bit3 = 0;
		theApp.myStatusClass.ctr0X00bit2 = 0;
		theApp.myStatusClass.ctr0X00bit1 = 1;
		theApp.myStatusClass.ctr0X00bit0 = 0;
	}
	theApp.myStatusClass.download_inksystem_control00();

	this->OnCancel();
	//this->ShowWindow(SW_HIDE);
}
void COnOffDlg::OnBnClickedReturnBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->OnCancel();
	//this->ShowWindow(SW_HIDE);
}

HBRUSH COnOffDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	pDC->SetBkColor(theApp.m_BKcolor);
	 
	return theApp.m_DlgBrush;
}
