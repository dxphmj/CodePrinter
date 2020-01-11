// RenameDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "PathDlgDll.h"
#include "RenameDlg.h"
#include "BnvImage.h"

// CRenameDlg 对话框

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


// CRenameDlg 消息处理程序

BOOL CRenameDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_BKcolor = RGB(210, 231, 251);
	m_DlgBrush.CreateSolidBrush(m_BKcolor); 
	// TODO:  在此添加额外的初始化
	//GetDlgItem(IDC_EDIT_RENAMEEDIT)->SetWindowPos(NULL,,rect.top+50,700,30,SWP_SHOWWINDOW);
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
	// 异常: OCX 属性页应返回 FALSE
}

void CRenameDlg::OnOK()
{
	// TODO: 在此添加专用代码和/或调用基类
	GetDlgItem(IDC_EDIT_RENAMEEDIT)->GetWindowText(m_RenameSTR);
	CDialog::OnOK();
}

HBRUSH CRenameDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	pDC->SetBkColor(m_BKcolor);
	return m_DlgBrush;
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
