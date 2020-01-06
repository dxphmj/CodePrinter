// NewDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PathDlgDll.h"
#include "NewDlg.h"
#include "BnvImage.h"

// CNewDlg �Ի���

IMPLEMENT_DYNAMIC(CNewDlg, CDialog)

CNewDlg::CNewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewDlg::IDD, pParent)
{

}

CNewDlg::~CNewDlg()
{
}

void CNewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, m_OKBUT);
	DDX_Control(pDX, IDCANCEL, m_CLOBUT);
}


BEGIN_MESSAGE_MAP(CNewDlg, CDialog)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CNewDlg ��Ϣ�������

void CNewDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
	GetDlgItem(IDC_EDIT_NEWNAME)->GetWindowText(m_nameSTR);
	CDialog::OnOK();
}

BOOL CNewDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_BKcolor = RGB(210, 231, 251);
	m_DlgBrush.CreateSolidBrush(m_BKcolor); 
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CRect rect;
	//GetWindowRect(&rect);
	GetClientRect(&rect);
	GetDlgItem(IDOK)->SetWindowPos(NULL,rect.left+650,rect.top+450,100,40,SWP_SHOWWINDOW);
	CFont *m_Font;
	m_Font=new CFont;
	m_Font->CreateFont(
		15,                 //����߶�(��ת���������)=56   
		0,                 //������(��ת�������߶�)=20 
		0,                 //������ʾ�Ƕ�  
		0,                  //nOrientation=0 
		700,                 //�������=10  
		FALSE,              //��б��
		FALSE,              //���»���
		FALSE,              //��ɾ����
		DEFAULT_CHARSET,    //ʹ��ȱʡ�ַ���
		OUT_DEFAULT_PRECIS, //ȱʡ�������
		CLIP_DEFAULT_PRECIS,//ȱʡ�ü�����
		DEFAULT_QUALITY,    //nQuality=ȱʡֵ
		DEFAULT_PITCH,      //nPitchAndFamily=ȱʡֵ
		L"@system");         //������=@system  
	//CreatePointFont(120, _T("Arial"), NULL);
	GetDlgItem(IDC_EDIT_NEWNAME)->SetWindowPos(NULL,rect.left+100,rect.top+100,600,40,SWP_SHOWWINDOW);
	GetDlgItem(IDCANCEL)->SetWindowPos(NULL,rect.left+50,rect.top+450,100,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_EDIT_NEWNAME)->SetWindowText(_T("NEWDirectory"));
	GetDlgItem(IDC_EDIT_NEWNAME)->SetFont(m_Font,true);
	m_OKBUT.LoadBitmaps(IDB_BITMAP_OKUP,IDB_BITMAP_OKDOWN,0,0,IDB_BITMAP_OKUP);
	m_OKBUT.SizeToContent(); 
	m_CLOBUT.LoadBitmaps(IDB_BITMAP_CLOUP,IDB_BITMAP_CLODOWN,0,0,IDB_BITMAP_CLOUP);
	m_CLOBUT.SizeToContent(); 

	SetWindowPos(NULL,0,80,800,520,SWP_SHOWWINDOW );
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

HBRUSH CNewDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	pDC->SetBkColor(m_BKcolor);
	return m_DlgBrush;
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}
