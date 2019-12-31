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


	ON_BN_CLICKED(IDC_LAN_ARABIC, &CKeyBoLan::OnBnClickedLanArabic)
	ON_BN_CLICKED(IDC_LAN_CHINESE, &CKeyBoLan::OnBnClickedLanChinese)
	ON_BN_CLICKED(IDC_LAN_CZECH, &CKeyBoLan::OnBnClickedLanCzech)
	ON_BN_CLICKED(IDC_LAN_DUTCH, &CKeyBoLan::OnBnClickedLanDutch)
	ON_BN_CLICKED(IDC_LAN_ENGLISH, &CKeyBoLan::OnBnClickedLanEnglish)
	ON_BN_CLICKED(IDC_LAN_FARSI, &CKeyBoLan::OnBnClickedLanFarsi)

	ON_BN_CLICKED(IDC_LAN_FINNISH, &CKeyBoLan::OnBnClickedLanFinnish)
	ON_BN_CLICKED(IDC_LAN_GERMAN, &CKeyBoLan::OnBnClickedLanGerman)
	ON_BN_CLICKED(IDC_LAN_HINDI, &CKeyBoLan::OnBnClickedLanHindi)
	ON_BN_CLICKED(IDC_LAN_HUNGARIAN, &CKeyBoLan::OnBnClickedLanHungarian)
	ON_BN_CLICKED(IDC_LAN_ITALIAN, &CKeyBoLan::OnBnClickedLanItalian)
	ON_BN_CLICKED(IDC_LAN_JANPANESE, &CKeyBoLan::OnBnClickedLanJapanese)

	ON_BN_CLICKED(IDC_LAN_KOREAN, &CKeyBoLan::OnBnClickedLanKorean)
	ON_BN_CLICKED(IDC_LAN_PORTUGUESE, &CKeyBoLan::OnBnClickedLanPortuguese)
	ON_BN_CLICKED(IDC_LAN_RUSSIAN, &CKeyBoLan::OnBnClickedLanRussian)
	ON_BN_CLICKED(IDC_LAN_SPANISH, &CKeyBoLan::OnBnClickedLanSpanish)
	ON_BN_CLICKED(IDC_LAN_SWEDISH, &CKeyBoLan::OnBnClickedLanSwedish)
	ON_BN_CLICKED(IDC_LAN_THAI, &CKeyBoLan::OnBnClickedLanThai)

	ON_BN_CLICKED(IDC_LAN_TURKISH, &CKeyBoLan::OnBnClickedLanTurkish)


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
	if (pWnd->LanType == 0||pWnd->LanType == 1||pWnd->LanType == 2
		||pWnd->LanType == 3||pWnd->LanType == 21||pWnd->LanType == 22)
	{
		pWnd->btnShow();
		pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
	}
	// TODO: 在此添加控件通知处理程序代码
}

//////////////////////////////////////////////////////////////////////////
void CKeyBoLan::OnBnClickedLanArabic()
{//阿拉伯语Arabic
	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pSym->ShowWindow(SW_HIDE);
	pWnd->m_pMain->ShowWindow(SW_SHOW);
	pWnd->m_pCaps->ShowWindow(SW_HIDE);
	//pWnd->btnHide();
	pWnd->LanType = 5;
	pWnd->m_pMain->btnTextSel(pWnd->LanType);
}
void CKeyBoLan::OnBnClickedLanChinese()
{//中文
	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pSym->ShowWindow(SW_HIDE);
	pWnd->m_pMain->ShowWindow(SW_SHOW);
	pWnd->m_pCaps->ShowWindow(SW_HIDE);
	//pWnd->btnShow();
	pWnd->LanType = 0;
	pWnd->m_pMain->btnTextSel(pWnd->LanType);
	pWnd->m_zrh_edit.SetWindowText(_T(""));
	pWnd->FontNull();
}
void CKeyBoLan::OnBnClickedLanCzech()
{//捷克文Czech
	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pSym->ShowWindow(SW_HIDE);
	pWnd->m_pMain->ShowWindow(SW_SHOW);
	pWnd->m_pCaps->ShowWindow(SW_HIDE);
	//pWnd->btnHide();
	pWnd->LanType = 8;
	pWnd->m_pMain->btnTextSel(pWnd->LanType);
}
void CKeyBoLan::OnBnClickedLanDutch()
{//荷兰语Dutch
	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pSym->ShowWindow(SW_HIDE);
	pWnd->m_pMain->ShowWindow(SW_SHOW);
	pWnd->m_pCaps->ShowWindow(SW_HIDE);
	//pWnd->btnHide();
	pWnd->LanType = 9;
	pWnd->m_pMain->btnTextSel(pWnd->LanType);
}
void CKeyBoLan::OnBnClickedLanEnglish()
{//英语	English
	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pSym->ShowWindow(SW_HIDE);
	pWnd->m_pMain->ShowWindow(SW_SHOW);
	pWnd->m_pCaps->ShowWindow(SW_HIDE);
	//pWnd->btnHide();
	pWnd->LanType = 7;
	pWnd->m_pMain->btnTextSel(pWnd->LanType);
}
void CKeyBoLan::OnBnClickedLanFarsi()
{//波斯文Farsi
	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pSym->ShowWindow(SW_HIDE);
	pWnd->m_pMain->ShowWindow(SW_SHOW);
	pWnd->m_pCaps->ShowWindow(SW_HIDE);
	//pWnd->btnHide();
	pWnd->LanType = 6;
	pWnd->m_pMain->btnTextSel(pWnd->LanType);
}
//////////////////////////////////////////////////////////////////////////
void CKeyBoLan::OnBnClickedLanFinnish()
{//芬兰语Finnish
	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pSym->ShowWindow(SW_HIDE);
	pWnd->m_pMain->ShowWindow(SW_SHOW);
	pWnd->m_pCaps->ShowWindow(SW_HIDE);
	//pWnd->btnHide();
	pWnd->LanType = 11;
	pWnd->m_pMain->btnTextSel(pWnd->LanType);
}
void CKeyBoLan::OnBnClickedLanGerman()
{//德语German
	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pSym->ShowWindow(SW_HIDE);
	pWnd->m_pMain->ShowWindow(SW_SHOW);
	pWnd->m_pCaps->ShowWindow(SW_HIDE);
	//pWnd->btnHide();
	pWnd->LanType = 10;
	pWnd->m_pMain->btnTextSel(pWnd->LanType);
}
void CKeyBoLan::OnBnClickedLanHindi()
{//印第语Hindi
	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pSym->ShowWindow(SW_HIDE);
	pWnd->m_pMain->ShowWindow(SW_SHOW);
	pWnd->m_pCaps->ShowWindow(SW_HIDE);
	//pWnd->btnHide();
	pWnd->LanType = 12;
	pWnd->m_pMain->btnTextSel(pWnd->LanType);
}
void CKeyBoLan::OnBnClickedLanHungarian()
{//匈牙利语Hungarian
	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pSym->ShowWindow(SW_HIDE);
	pWnd->m_pMain->ShowWindow(SW_SHOW);
	pWnd->m_pCaps->ShowWindow(SW_HIDE);
	//pWnd->btnHide();
	pWnd->LanType = 13;
	pWnd->m_pMain->btnTextSel(pWnd->LanType);
}
void CKeyBoLan::OnBnClickedLanItalian()
{//意大利语Italian
	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pSym->ShowWindow(SW_HIDE);
	pWnd->m_pMain->ShowWindow(SW_SHOW);
	pWnd->m_pCaps->ShowWindow(SW_HIDE);
	//pWnd->btnHide();
	pWnd->LanType = 14;
	pWnd->m_pMain->btnTextSel(pWnd->LanType);
}
void CKeyBoLan::OnBnClickedLanJapanese()
{//日语Japanese
	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pSym->ShowWindow(SW_HIDE);
	pWnd->m_pMain->ShowWindow(SW_SHOW);
	pWnd->m_pCaps->ShowWindow(SW_HIDE);
	//pWnd->btnShow();
	pWnd->LanType = 1;
	pWnd->m_pMain->btnTextSel(pWnd->LanType);
	pWnd->m_zrh_edit.SetWindowText(_T(""));
	pWnd->FontNull();
}
//////////////////////////////////////////////////////////////////////////
void CKeyBoLan::OnBnClickedLanKorean()
{//韩语Korean
	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pSym->ShowWindow(SW_HIDE);
	pWnd->m_pMain->ShowWindow(SW_SHOW);
	pWnd->m_pCaps->ShowWindow(SW_HIDE);
	//pWnd->btnShow();
	pWnd->LanType = 2;
	pWnd->m_pMain->btnTextSel(pWnd->LanType);
	pWnd->m_zrh_edit.SetWindowText(_T(""));
	pWnd->FontNull();

}
void CKeyBoLan::OnBnClickedLanPortuguese()
{//葡萄牙语Portuguese
	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pSym->ShowWindow(SW_HIDE);
	pWnd->m_pMain->ShowWindow(SW_SHOW);
	pWnd->m_pCaps->ShowWindow(SW_HIDE);
	//pWnd->btnHide();
	pWnd->LanType = 15;
	pWnd->m_pMain->btnTextSel(pWnd->LanType);
}
void CKeyBoLan::OnBnClickedLanRussian()
{//俄语Russian
	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pSym->ShowWindow(SW_HIDE);
	pWnd->m_pMain->ShowWindow(SW_SHOW);
	pWnd->m_pCaps->ShowWindow(SW_HIDE);
	//pWnd->btnHide();
	pWnd->LanType = 16;
	pWnd->m_pMain->btnTextSel(pWnd->LanType);
}
void CKeyBoLan::OnBnClickedLanSpanish()
{//西班牙语Spanish
	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pSym->ShowWindow(SW_HIDE);
	pWnd->m_pMain->ShowWindow(SW_SHOW);
	pWnd->m_pCaps->ShowWindow(SW_HIDE);
	//pWnd->btnHide();
	pWnd->LanType = 17;
	pWnd->m_pMain->btnTextSel(pWnd->LanType);
}
void CKeyBoLan::OnBnClickedLanSwedish()
{//瑞典语Swedish
	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pSym->ShowWindow(SW_HIDE);
	pWnd->m_pMain->ShowWindow(SW_SHOW);
	pWnd->m_pCaps->ShowWindow(SW_HIDE);
	//pWnd->btnHide();
	pWnd->LanType = 18;
	pWnd->m_pMain->btnTextSel(pWnd->LanType);
}
//泰语未实现
void CKeyBoLan::OnBnClickedLanThai()
{//泰语Thai
	//this->ShowWindow(SW_HIDE);
	//CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	//pWnd->m_pSym->ShowWindow(SW_HIDE);
	//pWnd->m_pMain->ShowWindow(SW_SHOW);
	//pWnd->m_pCaps->ShowWindow(SW_HIDE);
	////pWnd->btnHide();
	//pWnd->LanType = 19;
	//pWnd->m_pMain->btnTextSel(pWnd->LanType);
}
//////////////////////////////////////////////////////////////////////////
void CKeyBoLan::OnBnClickedLanTurkish()
{//土耳其语Turkish
	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pSym->ShowWindow(SW_HIDE);
	pWnd->m_pMain->ShowWindow(SW_SHOW);
	pWnd->m_pCaps->ShowWindow(SW_HIDE);
	//pWnd->btnHide();
	pWnd->LanType = 20;
	pWnd->m_pMain->btnTextSel(pWnd->LanType);
}






