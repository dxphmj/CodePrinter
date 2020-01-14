// ResetSerial.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "ResetSerial.h"


// CResetSerial �Ի���

IMPLEMENT_DYNAMIC(CResetSerial, CDialog)

CResetSerial::CResetSerial(CWnd* pParent /*=NULL*/)
	: CDialog(CResetSerial::IDD, pParent)
{

}

CResetSerial::~CResetSerial()
{
}

void CResetSerial::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RESET_SERIAL_RETURN_BTN, m_returnIB);
}


BEGIN_MESSAGE_MAP(CResetSerial, CDialog)
	ON_BN_CLICKED(IDC_RESET_SERIAL_RETURN_BTN, &CResetSerial::OnBnClickedResetSerialReturnBtn)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CResetSerial ��Ϣ�������

BOOL CResetSerial::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_returnIB.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RETURN1_BITMAP);
	m_returnIB.SizeToContent(); 

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CResetSerial::OnBnClickedResetSerialReturnBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->ShowWindow(SW_HIDE);
}

HBRUSH CResetSerial::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	if(nCtlColor == CTLCOLOR_STATIC)
	{		 
		pDC->SelectObject(theApp.m_StaticFont);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));	
	}

	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return theApp.m_DlgBrush;	 
}
