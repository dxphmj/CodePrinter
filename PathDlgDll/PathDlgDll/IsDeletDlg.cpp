// IsDeletDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PathDlgDll.h"
#include "IsDeletDlg.h"


// CIsDeletDlg 对话框

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


// CIsDeletDlg 消息处理程序

BOOL CIsDeletDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CRect rect;
	//GetWindowRect(&rect);
	GetClientRect(&rect);
	GetDlgItem(IDOK)->SetWindowPos(NULL,rect.left+650,rect.top+450,100,40,SWP_SHOWWINDOW);
	CFont *m_Font;
	m_Font=new CFont;
	m_Font->CreateFont(
		15,                 //字体高度(旋转后的字体宽度)=56   
		0,                 //字体宽度(旋转后的字体高度)=20 
		0,                 //字体显示角度  
		0,                  //nOrientation=0 
		700,                 //字体磅数=10  
		FALSE,              //非斜体
		FALSE,              //无下划线
		FALSE,              //无删除线
		DEFAULT_CHARSET,    //使用缺省字符集
		OUT_DEFAULT_PRECIS, //缺省输出精度
		CLIP_DEFAULT_PRECIS,//缺省裁减精度
		DEFAULT_QUALITY,    //nQuality=缺省值
		DEFAULT_PITCH,      //nPitchAndFamily=缺省值
		L"@system");         //字体名=@system  
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
	// 异常: OCX 属性页应返回 FALSE
}
