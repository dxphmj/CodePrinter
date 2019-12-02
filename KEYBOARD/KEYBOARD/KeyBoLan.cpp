// KeyBoLan.cpp : 实现文件
//

#include "stdafx.h"
#include "KeyBoard.h"
#include "KeyBoLan.h"
#include "KeyBoardDlg.h"


// CKeyBoLan 对话框

IMPLEMENT_DYNAMIC(CKeyBoLan, CDialog)

CKeyBoLan::CKeyBoLan(CWnd* pParent /*=NULL*/)
	: CDialog(CKeyBoLan::IDD, pParent)
{

}

CKeyBoLan::~CKeyBoLan()
{
}

void CKeyBoLan::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CKeyBoLan, CDialog)

	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_LAN_ESC, &CKeyBoLan::OnBnClickedLanEsc)
	ON_BN_CLICKED(IDC_LAN_CHINESE, &CKeyBoLan::OnBnClickedLanChinese)

END_MESSAGE_MAP()


// CKeyBoLan 消息处理程序

BOOL CKeyBoLan::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化



	//设置对话框的位置和尺寸
	SetWindowPos(NULL,0,284,800,316,SWP_SHOWWINDOW );	
	CRect rect;
	GetWindowRect(&rect);

	//动态生成按钮
	CButton* btn = new CButton[61];  
	DWORD dwStyle = WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON;
	btn[1].Create(_T("Thai"), dwStyle,CRect(665,128,665+130,128+60),this,IDC_LAN_THAI);
	btn[2].Create(_T("Farsi"), dwStyle,CRect(665,4,665+130,4+60),this,IDC_LAN_FARSI);
	btn[3].Create(_T("Japanese"), dwStyle,CRect(665,66,665+130,66+60),this,IDC_LAN_JANPANESE);
	btn[4].Create(_T(""), dwStyle,CRect(665,190,665+130,190+60),this,IDC_LAN_NU5);
	btn[5].Create(_T("Esc"), dwStyle,CRect(665,252,665+130,252+60),this,IDC_LAN_ESC);
	btn[6].Create(_T("Swedish"), dwStyle,CRect(533,128,533+130,128+60),this,IDC_LAN_SWEDISH);
	btn[7].Create(_T("English"), dwStyle,CRect(533,4,533+130,4+60),this,IDC_LAN_ENGLISH);
	btn[8].Create(_T("Italian"), dwStyle,CRect(533,66,533+130,66+60),this,IDC_LAN_ITALIAN);
	btn[9].Create(_T(""), dwStyle,CRect(533,190,533+130,190+60),this,IDC_LAN_NU4);
	btn[10].Create(_T(""), dwStyle,CRect(533,252,533+130,252+60),this,IDC_LAN_NU10);
	btn[11].Create(_T("Spanish"), dwStyle,CRect(401,128,401+130,128+60),this,IDC_LAN_SPANISH);
	btn[12].Create(_T("Dutch"), dwStyle,CRect(401,4,401+130,4+60),this,IDC_LAN_DUTCH);
	btn[13].Create(_T("Hungarian"), dwStyle,CRect(401,66,401+130,66+60),this,IDC_LAN_HUNGARIAN);
	btn[14].Create(_T(""), dwStyle,CRect(401,190,401+130,190+60),this,IDC_LAN_NU3);
	btn[15].Create(_T(""), dwStyle,CRect(401,252,401+130,252+60),this,IDC_LAN_NU9);
	btn[16].Create(_T("Russian"), dwStyle,CRect(269,128,269+130,128+60),this,IDC_LAN_RUSSIAN);
	btn[17].Create(_T("Czech"), dwStyle,CRect(269,4,269+130,4+60),this,IDC_LAN_CZECH);
	btn[18].Create(_T("Hindi"), dwStyle,CRect(269,66,269+130,66+60),this,IDC_LAN_HINDI);
	btn[19].Create(_T(""), dwStyle,CRect(269,190,269+130,190+60),this,IDC_LAN_NU2);
	btn[20].Create(_T(""), dwStyle,CRect(269,252,269+130,252+60),this,IDC_LAN_NU8);
	btn[21].Create(_T("Portuguese"), dwStyle,CRect(137,128,137+130,128+60),this,IDC_LAN_PORTUGUESE);
	btn[22].Create(_T("Chinese"), dwStyle,CRect(137,4,137+130,4+60),this,IDC_LAN_CHINESE);
	btn[23].Create(_T("German"), dwStyle,CRect(137,66,137+130,66+60),this,IDC_LAN_GERMAN);
	btn[24].Create(_T(""), dwStyle,CRect(137,190,137+130,190+60),this,IDC_LAN_NU1);
	btn[25].Create(_T(""), dwStyle,CRect(137,252,137+130,252+60),this,IDC_LAN_NU7);
	btn[26].Create(_T("Korean"), dwStyle,CRect(5,128,5+130,128+60),this,IDC_LAN_KOREAN);
	btn[27].Create(_T("Arabic"), dwStyle,CRect(5,4,5+130,4+60),this,IDC_LAN_ARABIC);
	btn[28].Create(_T("Finnish"), dwStyle,CRect(5,66,5+130,66+60),this,IDC_LAN_FINNISH);
	btn[29].Create(_T("Turkish"), dwStyle,CRect(5,190,5+130,190+60),this,IDC_LAN_TURKISH);
	btn[30].Create(_T(""), dwStyle,CRect(5,252,5+130,252+60),this,IDC_LAN_NU6);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
void CKeyBoLan::OnBnClickedLanEsc()
{//打开主Main窗口

	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pSym->ShowWindow(SW_HIDE);
	pWnd->m_pMain->ShowWindow(SW_SHOW);
	pWnd->m_pCaps->ShowWindow(SW_HIDE);  
	// TODO: 在此添加控件通知处理程序代码
}

void CKeyBoLan::OnBnClickedLanChinese()
{
	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pSym->ShowWindow(SW_HIDE);
	pWnd->m_pMain->ShowWindow(SW_SHOW);
	pWnd->m_pCaps->ShowWindow(SW_HIDE);
	pWnd->btnShow();
	
	pWnd->LanType = 0;
}
