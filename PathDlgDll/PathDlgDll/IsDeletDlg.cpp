// IsDeletDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PathDlgDll.h"
#include "IsDeletDlg.h"


// CIsDeletDlg �Ի���

IMPLEMENT_DYNAMIC(CIsDeletDlg, CDialog)

CIsDeletDlg::CIsDeletDlg(CString isDetStr,CWnd* pParent /*=NULL*/)
	: CDialog(CIsDeletDlg::IDD, pParent)
{
	m_isDetstr=isDetStr;
}

CIsDeletDlg::~CIsDeletDlg()
{
}

void CIsDeletDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, m_OKBUT);
	DDX_Control(pDX, IDCANCEL, m_CLOBUT);
}


BEGIN_MESSAGE_MAP(CIsDeletDlg, CDialog)
END_MESSAGE_MAP()


// CIsDeletDlg ��Ϣ�������

BOOL CIsDeletDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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
	GetDlgItem(IDC_STATIC_ISDET)->SetWindowPos(NULL,rect.left+50,rect.top+10,700,20,SWP_SHOWWINDOW);
	GetDlgItem(IDC_STATIC_ISDET)->SetWindowPos(NULL,rect.left+100,rect.top+200,600,40,SWP_SHOWWINDOW);
	GetDlgItem(IDCANCEL)->SetWindowPos(NULL,rect.left+50,rect.top+450,100,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_STATIC_ISDET)->SetWindowText(m_isDetstr);
	GetDlgItem(IDC_STATIC_ISDET)->SetFont(m_Font,true);
	m_OKBUT.LoadBitmaps(IDB_BITMAP_OKUP,IDB_BITMAP_OKDOWN,0,0,IDB_BITMAP_OKUP);
	m_OKBUT.SizeToContent(); 
	m_CLOBUT.LoadBitmaps(IDB_BITMAP_CLOUP,IDB_BITMAP_CLODOWN,0,0,IDB_BITMAP_CLOUP);
	m_CLOBUT.SizeToContent(); 

	SetWindowPos(NULL,0,80,800,520,SWP_SHOWWINDOW );	
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
