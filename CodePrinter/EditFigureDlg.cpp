// EditFigureDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "EditFigureDlg.h"


// CEditFigureDlg �Ի���

IMPLEMENT_DYNAMIC(CEditFigureDlg, CDialog)

CEditFigureDlg::CEditFigureDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditFigureDlg::IDD, pParent)
{

}

CEditFigureDlg::~CEditFigureDlg()
{
}

void CEditFigureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDITFIG_CLOSE_BTN, m_returnIB);
	DDX_Control(pDX, IDC_EDITFIGURE_OK_BTN, m_okIB);
}


BEGIN_MESSAGE_MAP(CEditFigureDlg, CDialog)
	ON_BN_CLICKED(IDC_EDITFIG_CLOSE_BTN, &CEditFigureDlg::OnBnClickedEditfigCloseBtn)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CEditFigureDlg ��Ϣ�������

BOOL CEditFigureDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetWindowPos(NULL,0,0,800,600,SWP_SHOWWINDOW );	
	CRect rect;
	GetWindowRect(&rect);

	GetDlgItem(IDC_EDITFIG_CLOSE_BTN)->SetWindowPos(NULL,20,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_EDITFIGURE_OK_BTN)->SetWindowPos(NULL,700,390,70,45,SWP_SHOWWINDOW);

	m_returnIB.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_returnIB.SizeToContent(); 
	m_okIB.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_okIB.SizeToContent(); 

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CEditFigureDlg::OnBnClickedEditfigCloseBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->ShowWindow(SW_HIDE);
}

HBRUSH CEditFigureDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return theApp.m_DlgBrush;
}
