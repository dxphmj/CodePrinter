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
	DDX_Control(pDX, IDC_RESET_SERIAL1_BTN, ResetBtn1);
	DDX_Control(pDX, IDC_RESET_SERIAL2_BTN, ResetBtn2);
	DDX_Control(pDX, IDC_RESET_SERIAL3_BTN, ResetBtn3);
	DDX_Control(pDX, IDC_RESET_SERIAL4_BTN, ResetBtn4);
	DDX_Control(pDX, IDC_ALL_RESET_BTN, allResetBtn);
	DDX_Control(pDX, IDC_RESET_SERIAL_RETURN_BTN, resetSerialReturnBtn);
	DDX_Control(pDX, IDC_SERIAL1_STATIC, m_serialStatic1);
	DDX_Control(pDX, IDC_SERIAL2_STATIC, m_serialStatic2);
	DDX_Control(pDX, IDC_SERIAL3_STATIC, m_serialStatic3);
	DDX_Control(pDX, IDC_SERIAL4_STATIC, m_serialStatic4);
	DDX_Control(pDX, IDC_SERIAL1_QUAD1_STATIC, m_serial1_quad1_static);
	DDX_Control(pDX, IDC_SERIAL1_QUAD2_STATIC, m_serial1_quad2_static);
	DDX_Control(pDX, IDC_SERIAL2_QUAD1_STATIC, m_serial2_quad1_static);
	DDX_Control(pDX, IDC_SERIAL2_QUAD2_STATIC, m_serial2_quad2_static);
	DDX_Control(pDX, IDC_SERIAL3_QUAD1_STATIC, m_serial3_quad1_static);
	DDX_Control(pDX, IDC_SERIAL3_QUAD2_STATIC, m_serial3_quad2_static);
	DDX_Control(pDX, IDC_SERIAL4_QUAD1_STATIC, m_serial4_quad1_static);
	DDX_Control(pDX, IDC_SERIAL4_QUAD2_STATIC, m_serial4_quad2_static);
	DDX_Control(pDX, IDC_SERIAL1_CUR_STATIC, m_serial1_cur_static);
	DDX_Control(pDX, IDC_SERIAL2_CUR_STATIC, m_serial2_cur_static);
	DDX_Control(pDX, IDC_SERIAL3_CUR_STATIC, m_serial3_cur_static);
	DDX_Control(pDX, IDC_SERIAL4_CUR_STATIC, m_serial4_cur_static);

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
	ResetBtn1.LoadBitmaps(IDB_70_45_1_BITMAP,IDB_70_45_BITMAP,0,0,IDB_70_45_BITMAP,true);
	ResetBtn1.SizeToContent(); 
	ResetBtn2.LoadBitmaps(IDB_70_45_1_BITMAP,IDB_70_45_BITMAP,0,0,IDB_70_45_BITMAP,true);
	ResetBtn2.SizeToContent(); 
	ResetBtn3.LoadBitmaps(IDB_70_45_1_BITMAP,IDB_70_45_BITMAP,0,0,IDB_70_45_BITMAP,true);
	ResetBtn3.SizeToContent(); 
	ResetBtn4.LoadBitmaps(IDB_70_45_1_BITMAP,IDB_70_45_BITMAP,0,0,IDB_70_45_BITMAP,true);
	ResetBtn4.SizeToContent(); 
	resetSerialReturnBtn.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_80_55_BITMAP);
	resetSerialReturnBtn.SizeToContent(); 
	allResetBtn.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_80_55_BITMAP,true);
	allResetBtn.SizeToContent(); 

	GetDlgItem(IDC_RESET_SERIAL_NAME_STATIC)->SetFont(theApp.m_StaticFont);
	GetDlgItem(IDC_QUADRANT1_STATIC)->SetFont(theApp.m_StaticFont);
	GetDlgItem(IDC_QUADRANT2_STATIC)->SetFont(theApp.m_StaticFont);
	GetDlgItem(IDC_CUR_VALUE_STATIC)->SetFont(theApp.m_StaticFont);
	GetDlgItem(IDC_SET_VALUE_STATIC)->SetFont(theApp.m_StaticFont);

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
