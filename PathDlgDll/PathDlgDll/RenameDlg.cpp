// RenameDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PathDlgDll.h"
#include "RenameDlg.h"
#include "BnvImage.h"

// CRenameDlg �Ի���

IMPLEMENT_DYNAMIC(CRenameDlg, CDialog)

CRenameDlg::CRenameDlg(CString renameSTR,CWnd* pParent /*=NULL*/)
	: CDialog(CRenameDlg::IDD, pParent)
{
	m_RenameSTR=renameSTR;
}

CRenameDlg::~CRenameDlg()
{
}

void CRenameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, m_OKBUT);
	DDX_Control(pDX, IDCANCEL, m_CLOBUT);
}


BEGIN_MESSAGE_MAP(CRenameDlg, CDialog)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CRenameDlg ��Ϣ�������

BOOL CRenameDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_BKcolor = RGB(210, 231, 251);
	m_DlgBrush.CreateSolidBrush(m_BKcolor); 
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//GetDlgItem(IDC_EDIT_RENAMEEDIT)->SetWindowPos(NULL,,rect.top+50,700,30,SWP_SHOWWINDOW);
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
	GetDlgItem(IDC_EDIT_RENAMEEDIT)->SetWindowPos(NULL,rect.left+100,rect.top+100,600,40,SWP_SHOWWINDOW);
	GetDlgItem(IDCANCEL)->SetWindowPos(NULL,rect.left+50,rect.top+450,100,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_EDIT_RENAMEEDIT)->SetWindowText(m_RenameSTR);
	GetDlgItem(IDC_EDIT_RENAMEEDIT)->SetFont(m_Font,true);
	m_OKBUT.LoadBitmaps(IDB_BITMAP_OKUP,IDB_BITMAP_OKDOWN,0,0,IDB_BITMAP_OKUP);
	m_OKBUT.SizeToContent(); 
	m_CLOBUT.LoadBitmaps(IDB_BITMAP_CLOUP,IDB_BITMAP_CLODOWN,0,0,IDB_BITMAP_CLOUP);
	m_CLOBUT.SizeToContent(); 

	SetWindowPos(NULL,0,80,800,520,SWP_SHOWWINDOW );
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CRenameDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
	GetDlgItem(IDC_EDIT_RENAMEEDIT)->GetWindowText(m_RenameSTR);
	CDialog::OnOK();
}

HBRUSH CRenameDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	pDC->SetBkColor(m_BKcolor);
	return m_DlgBrush;
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}
