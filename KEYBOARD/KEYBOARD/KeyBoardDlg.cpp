// KeyBoardDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "KeyBoard.h"
#include "KeyBoardDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// CKeyBoardDlg 对话框

CKeyBoardDlg::CKeyBoardDlg(CString strIn,CWnd* pParent /*=NULL*/)
	: CDialog(CKeyBoardDlg::IDD, pParent)
{
	m_strRet = m_strOld = strIn;
	m_pMain = NULL;
	m_pLan = NULL;
	m_pSym = NULL;
	m_pCaps = NULL;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKeyBoardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ZRH, m_zrh_edit);
}

BEGIN_MESSAGE_MAP(CKeyBoardDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_EN_SETFOCUS(IDC_EDIT_INPUT, &CKeyBoardDlg::OnEnSetfocusEdit1)
	ON_WM_CLOSE()
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

	//////中日韩文字选择按键
	CButton* btnFont = new CButton[17];  
	DWORD dwStyle = WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON;
	btnFont[0].Create(_T("<-"), dwStyle,CRect(4,240,4+72,240+40),this,IDC_MIAN_LEFTPAGE);
	btnFont[1].Create(_T("->"), dwStyle,CRect(724,240,724+72,240+40),this,IDC_MIAN_RIGHTPAGE);
	btnFont[2].Create(_T(""), dwStyle,CRect(79,240,79+40,240+40),this,IDC_MIAN_FONT1);
	btnFont[3].Create(_T(""), dwStyle,CRect(122,240,122+40,240+40),this,IDC_MIAN_FONT2);
	btnFont[4].Create(_T(""), dwStyle,CRect(165,240,165+40,240+40),this,IDC_MIAN_FONT3);
	btnFont[5].Create(_T(""), dwStyle,CRect(208,240,208+40,240+40),this,IDC_MIAN_FONT4);
	btnFont[6].Create(_T(""), dwStyle,CRect(251,240,251+40,240+40),this,IDC_MIAN_FONT5);
	btnFont[7].Create(_T(""), dwStyle,CRect(294,240,294+40,240+40),this,IDC_MIAN_FONT6);
	btnFont[8].Create(_T(""), dwStyle,CRect(337,240,337+40,240+40),this,IDC_MIAN_FONT7);
	btnFont[9].Create(_T(""), dwStyle,CRect(380,240,380+40,240+40),this,IDC_MIAN_FONT8);
	btnFont[10].Create(_T(""), dwStyle,CRect(423,240,423+40,240+40),this,IDC_MIAN_FONT9);
	btnFont[11].Create(_T(""), dwStyle,CRect(466,240,466+40,240+40),this,IDC_MIAN_FONT10);
	btnFont[12].Create(_T(""), dwStyle,CRect(509,240,509+40,240+40),this,IDC_MIAN_FONT11);
	btnFont[13].Create(_T(""), dwStyle,CRect(552,240,552+40,240+40),this,IDC_MIAN_FONT12);
	btnFont[14].Create(_T(""), dwStyle,CRect(595,240,595+40,240+40),this,IDC_MIAN_FONT13);
	btnFont[15].Create(_T(""), dwStyle,CRect(638,240,638+40,240+40),this,IDC_MIAN_FONT14);
	btnFont[16].Create(_T(""), dwStyle,CRect(681,240,681+40,240+40),this,IDC_MIAN_FONT15);

	/////隐藏
	btnHide();


	////////////初始化创建键盘窗口/////////////////////////////////
	if (NULL == m_pLan)   
	{//Lan对话框   
		// 创建非模态对话框实例   
		m_pLan = new CKeyBoLan();
		m_pLan->Create( IDD_KEYBOARD_LAN,this);
	}  
	m_pLan->ShowWindow(SW_SHOW);
	

	if (NULL == m_pSym)   
	{//Sym对话框
		// 创建非模态对话框实例   
		m_pSym = new CKeyBoSym();
		m_pSym->Create( IDD_KEYBOARD_SYM,this);
	}  
	m_pSym->ShowWindow(SW_SHOW); 

	if (NULL == m_pCaps)   
	{//Caps对话框
		// 创建非模态对话框实例   
		m_pCaps = new CKeyBoCaps();
		m_pCaps->Create( IDD_KEYBOARD_CAPS,this);
	}  
	m_pCaps->ShowWindow(SW_SHOW); 

	if (NULL == m_pMain)   
	{//主对话框   
		// 创建非模态对话框实例   
		m_pMain = new CKeyBoMain();
		m_pMain->Create( IDD_KEYBOARD_MAIN,this);
	}  
	m_pMain->ShowWindow(SW_SHOW); 

	////初始化设置EDIT_INPUT文本
	CWnd* pWnd = GetDlgItem(IDC_EDIT_INPUT);
	pWnd->SetWindowText(m_strOld);
	/////中日韩语言初始化
	CreateChineseMapLan();
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

}

void CKeyBoardDlg::OnBnClickedButton1()
{

	// TODO: 在此添加控件通知处理程序代码
}

void CKeyBoardDlg::setEditText(CString &str)
{//设置文本编辑框文本
	CString allstr,str1;
	CWnd* pWnd = GetDlgItem(IDC_EDIT_INPUT);
	pWnd->GetWindowText(str1);
	allstr = str1+str;
	pWnd->SetWindowText(allstr);
}

void CKeyBoardDlg::getEditText()
{//获取文本编辑框文本 
	CWnd* pWnd = GetDlgItem(IDC_EDIT_INPUT);
	pWnd->GetWindowText(m_strRet);	 
}
void CKeyBoardDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

    delete m_pMain;
	CDialog::OnClose();
}

void CKeyBoardDlg::btnHide()
{
	GetDlgItem(IDC_MIAN_LEFTPAGE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MIAN_FONT1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MIAN_FONT2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MIAN_FONT3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MIAN_FONT4)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MIAN_FONT5)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MIAN_FONT6)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MIAN_FONT7)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MIAN_FONT8)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MIAN_FONT9)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MIAN_FONT10)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MIAN_FONT11)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MIAN_FONT12)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MIAN_FONT13)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MIAN_FONT14)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MIAN_FONT15)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MIAN_RIGHTPAGE)->ShowWindow(SW_HIDE);
}

void CKeyBoardDlg::btnShow()
{
	GetDlgItem(IDC_MIAN_LEFTPAGE)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MIAN_FONT1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MIAN_FONT2)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MIAN_FONT3)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MIAN_FONT4)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MIAN_FONT5)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MIAN_FONT6)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MIAN_FONT7)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MIAN_FONT8)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MIAN_FONT9)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MIAN_FONT10)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MIAN_FONT11)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MIAN_FONT12)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MIAN_FONT13)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MIAN_FONT14)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MIAN_FONT15)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_MIAN_RIGHTPAGE)->ShowWindow(SW_SHOW);
}

void CKeyBoardDlg::CreateChineseMapLan()
{
	ChineseLanMap[_T("an")] = _T("安,氨,鞍,俺,岸,按,案,胺,暗, , , , , , ");
}

//void CKeyBoardDlg::FontSelect()
//{
//	//GetDlgItem(IDC_MIAN_FONT1)->SetWindowText(arr[j1]);
//	//GetDlgItem(IDC_MIAN_FONT2)->SetWindowText(arr[j1 + 1]);
//	//GetDlgItem(IDC_MIAN_FONT3)->SetWindowText(arr[j1 + 2]);
//	//GetDlgItem(IDC_MIAN_FONT4)->SetWindowText(arr[j1 + 3]);
//	//GetDlgItem(IDC_MIAN_FONT5)->SetWindowText(arr[j1 + 4]);
//	//GetDlgItem(IDC_MIAN_FONT6)->SetWindowText(arr[j1 + 5]);
//	//GetDlgItem(IDC_MIAN_FONT7)->SetWindowText(arr[j1 + 6]);
//	//GetDlgItem(IDC_MIAN_FONT8)->SetWindowText(arr[j1 + 7]);
//	//GetDlgItem(IDC_MIAN_FONT9)->SetWindowText(arr[j1 + 8]);
//	//GetDlgItem(IDC_MIAN_FONT10)->SetWindowText(arr[j1 + 9]);
//	//GetDlgItem(IDC_MIAN_FONT11)->SetWindowText(arr[j1 + 10]);
//	//GetDlgItem(IDC_MIAN_FONT12)->SetWindowText(arr[j1 + 11]);
//	//GetDlgItem(IDC_MIAN_FONT13)->SetWindowText(arr[j1 + 12]);
//	//GetDlgItem(IDC_MIAN_FONT14)->SetWindowText(arr[j1 + 13]);
//	//GetDlgItem(IDC_MIAN_FONT15)->SetWindowText(arr[j1 + 14]);
//}
//
//void CKeyBoardDlg::Language()
//{
//
//
//
//	switch (LanType)
//	{
//	case Chinese: 
//		{	
//
//			CString value = ChineseLanMap[m_zrh_edit.GetWindowText()];
//			if ( value == "" )
//			{	
//				arr = SplitSymbols(" , , , , , , , , , , , , , , ", ",");
//				j1 = 0;
//				i1 = 1;
//				FontSelect();
//				break;
//			}
//			else
//			{
//				j1 = 0
//				arr = SplitSymbols(value, ",");
//				if ( sizeof(arr) < 16 )sizeof()
//				{
//					i1 = 1
//				} 
//				else if( sizeof(arr) < 31)
//				{
//					i1 = 16
//				}
//				else if( sizeof(arr) < 46)
//				{
//					i1 = 31
//				}
//				else
//				{
//					i1 = 46
//				}
//				FontSelect();
//				break;
//			}
//		}
//	case Japanese:  
//		{	
//
//			break;
//		}
//	case Korean:   
//		{
//
//			break;
//		}
//	}
//}
