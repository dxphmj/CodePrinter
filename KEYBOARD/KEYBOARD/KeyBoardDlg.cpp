// KeyBoardDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "KeyBoard.h"
#include "KeyBoardDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// CKeyBoardDlg 对话框

CKeyBoardDlg::CKeyBoardDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKeyBoardDlg::IDD, pParent)
{
	pMain = NULL;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKeyBoardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CKeyBoardDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_EN_SETFOCUS(IDC_EDIT1, &CKeyBoardDlg::OnEnSetfocusEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CKeyBoardDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CKeyBoardDlg 消息处理程序

BOOL CKeyBoardDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//设置对话框的位置和尺寸
	SetWindowPos(NULL,0,0,800,600,SWP_SHOWWINDOW );	
	CRect rect;
	GetWindowRect(&rect);
	//开始时对话框获得焦点
	GetDlgItem(IDD_KEYBOARD_DIALOG)->SetFocus();

	
	return FALSE;  // 除非将焦点设置到控件，否则返回 TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CKeyBoardDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_KEYBOARD_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_KEYBOARD_DIALOG));
	}
}
#endif


void CKeyBoardDlg::OnEnSetfocusEdit1()
{


	if (NULL == pMain)   
	{   
		// 创建非模态对话框实例   
		pMain = new CKeyBoMain();
		pMain->Create( IDD_KEYBOARD_MAIN,this);
	}  
	pMain->ShowWindow(SW_SHOW);
	//CKeyBoMain mian;
	//mian.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}

void CKeyBoardDlg::OnBnClickedButton1()
{

	// TODO: 在此添加控件通知处理程序代码
}

void CKeyBoardDlg::setEditText(CString &str)
{
	CString allstr,str1;
	CWnd* pWnd = GetDlgItem(IDC_EDIT1);
	pWnd->GetWindowText(str1);
	allstr = str1+str;
	pWnd->SetWindowText(allstr);
}
