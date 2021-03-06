// KeyBoSym.cpp : 实现文件
//

#include "stdafx.h"
#include "KeyBoard.h"
#include "KeyBoSym.h"
#include "KeyBoardDlg.h"


// CKeyBoSym 对话框

IMPLEMENT_DYNAMIC(CKeyBoSym, CDialog)

CKeyBoSym::CKeyBoSym(CWnd* pParent /*=NULL*/)
	: CDialog(CKeyBoSym::IDD, pParent)
{

}

CKeyBoSym::~CKeyBoSym()
{
}

void CKeyBoSym::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CKeyBoSym, CDialog)

	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_SYM_ALPHABET, &CKeyBoSym::OnBnClickedSymAlphbet)
	ON_BN_CLICKED(IDC_SYM_BACKSPACE, &CKeyBoSym::OnBnClickedSymBackspace)
	ON_BN_CLICKED(IDC_SYM_SPACE, &CKeyBoSym::OnBnClickedSymSpace)
	ON_BN_CLICKED(IDC_SYM_PGDN, &CKeyBoSym::OnBnClickedSymPgDn)
	ON_BN_CLICKED(IDC_SYM_PGUP, &CKeyBoSym::OnBnClickedSymPgUp)
	ON_BN_CLICKED(IDC_SYM_DEL, &CKeyBoSym::OnBnClickedSymDel)
	ON_BN_CLICKED(IDC_SYM_ENTER, &CKeyBoSym::OnBnClickedSymEnter)
	ON_BN_CLICKED(IDC_SYM_RIGHT, &CKeyBoSym::OnBnClickedSymRight)
	ON_BN_CLICKED(IDC_SYM_LEFT, &CKeyBoSym::OnBnClickedSymLeft)

	ON_BN_CLICKED(IDC_SYM_SYM1_1, &CKeyBoSym::OnBnClickedSym_1_1)
	ON_BN_CLICKED(IDC_SYM_SYM1_2, &CKeyBoSym::OnBnClickedSym_1_2)
	ON_BN_CLICKED(IDC_SYM_SYM1_3, &CKeyBoSym::OnBnClickedSym_1_3)
	ON_BN_CLICKED(IDC_SYM_SYM1_4, &CKeyBoSym::OnBnClickedSym_1_4)
	ON_BN_CLICKED(IDC_SYM_SYM1_5, &CKeyBoSym::OnBnClickedSym_1_5)
	ON_BN_CLICKED(IDC_SYM_SYM1_6, &CKeyBoSym::OnBnClickedSym_1_6)
	ON_BN_CLICKED(IDC_SYM_SYM1_7, &CKeyBoSym::OnBnClickedSym_1_7)
	ON_BN_CLICKED(IDC_SYM_SYM1_8, &CKeyBoSym::OnBnClickedSym_1_8)
	ON_BN_CLICKED(IDC_SYM_SYM1_9, &CKeyBoSym::OnBnClickedSym_1_9)
	ON_BN_CLICKED(IDC_SYM_SYM1_10, &CKeyBoSym::OnBnClickedSym_1_10)
	ON_BN_CLICKED(IDC_SYM_SYM1_11, &CKeyBoSym::OnBnClickedSym_1_11)

	ON_BN_CLICKED(IDC_SYM_SYM2_1, &CKeyBoSym::OnBnClickedSym_2_1)
	ON_BN_CLICKED(IDC_SYM_SYM2_2, &CKeyBoSym::OnBnClickedSym_2_2)
	ON_BN_CLICKED(IDC_SYM_SYM2_3, &CKeyBoSym::OnBnClickedSym_2_3)
	ON_BN_CLICKED(IDC_SYM_SYM2_4, &CKeyBoSym::OnBnClickedSym_2_4)
	ON_BN_CLICKED(IDC_SYM_SYM2_5, &CKeyBoSym::OnBnClickedSym_2_5)
	ON_BN_CLICKED(IDC_SYM_SYM2_6, &CKeyBoSym::OnBnClickedSym_2_6)
	ON_BN_CLICKED(IDC_SYM_SYM2_7, &CKeyBoSym::OnBnClickedSym_2_7)
	ON_BN_CLICKED(IDC_SYM_SYM2_8, &CKeyBoSym::OnBnClickedSym_2_8)
	ON_BN_CLICKED(IDC_SYM_SYM2_9, &CKeyBoSym::OnBnClickedSym_2_9)
	ON_BN_CLICKED(IDC_SYM_SYM2_10, &CKeyBoSym::OnBnClickedSym_2_10)
	ON_BN_CLICKED(IDC_SYM_SYM2_11, &CKeyBoSym::OnBnClickedSym_2_11)

	ON_BN_CLICKED(IDC_SYM_SYM3_1, &CKeyBoSym::OnBnClickedSym_3_1)
	ON_BN_CLICKED(IDC_SYM_SYM3_2, &CKeyBoSym::OnBnClickedSym_3_2)
	ON_BN_CLICKED(IDC_SYM_SYM3_3, &CKeyBoSym::OnBnClickedSym_3_3)
	ON_BN_CLICKED(IDC_SYM_SYM3_4, &CKeyBoSym::OnBnClickedSym_3_4)
	ON_BN_CLICKED(IDC_SYM_SYM3_5, &CKeyBoSym::OnBnClickedSym_3_5)
	ON_BN_CLICKED(IDC_SYM_SYM3_6, &CKeyBoSym::OnBnClickedSym_3_6)
	ON_BN_CLICKED(IDC_SYM_SYM3_7, &CKeyBoSym::OnBnClickedSym_3_7)
	ON_BN_CLICKED(IDC_SYM_SYM3_8, &CKeyBoSym::OnBnClickedSym_3_8)
	ON_BN_CLICKED(IDC_SYM_SYM3_9, &CKeyBoSym::OnBnClickedSym_3_9)
	ON_BN_CLICKED(IDC_SYM_SYM3_10, &CKeyBoSym::OnBnClickedSym_3_10)
	ON_BN_CLICKED(IDC_SYM_SYM3_11, &CKeyBoSym::OnBnClickedSym_3_11)

	ON_BN_CLICKED(IDC_SYM_SYM4_1, &CKeyBoSym::OnBnClickedSym_4_1)
	ON_BN_CLICKED(IDC_SYM_SYM4_2, &CKeyBoSym::OnBnClickedSym_4_2)
	ON_BN_CLICKED(IDC_SYM_SYM4_3, &CKeyBoSym::OnBnClickedSym_4_3)
	ON_BN_CLICKED(IDC_SYM_SYM4_4, &CKeyBoSym::OnBnClickedSym_4_4)
	ON_BN_CLICKED(IDC_SYM_SYM4_5, &CKeyBoSym::OnBnClickedSym_4_5)
	ON_BN_CLICKED(IDC_SYM_SYM4_6, &CKeyBoSym::OnBnClickedSym_4_6)
	ON_BN_CLICKED(IDC_SYM_SYM4_7, &CKeyBoSym::OnBnClickedSym_4_7)
	ON_BN_CLICKED(IDC_SYM_SYM4_8, &CKeyBoSym::OnBnClickedSym_4_8)
	ON_BN_CLICKED(IDC_SYM_SYM4_9, &CKeyBoSym::OnBnClickedSym_4_9)
	ON_BN_CLICKED(IDC_SYM_SYM4_10, &CKeyBoSym::OnBnClickedSym_4_10)
	ON_BN_CLICKED(IDC_SYM_SYM4_11, &CKeyBoSym::OnBnClickedSym_4_11)

END_MESSAGE_MAP()


// CKeyBoSym 消息处理程序

BOOL CKeyBoSym::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//设置对话框的位置和尺寸
	SetWindowPos(NULL,0,284,800,316,SWP_SHOWWINDOW );	
	CRect rect;
	GetWindowRect(&rect);
	////
	SymbolGroup = Group1;
	//动态生成按钮
	CButton* btn = new CButton[61];  
	DWORD dwStyle = WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON;
	btn[1].Create(_T("PageDn"), dwStyle,CRect(664,252,664+132,252+60),this,IDC_SYM_PGDN);
	btn[2].Create(_T("PagUp"), dwStyle,CRect(664,190,664+132,190+60),this,IDC_SYM_PGUP);
	btn[3].Create(_T("Enter"), dwStyle,CRect(664,128,664+132,128+60),this,IDC_SYM_ENTER);
	btn[4].Create(_T("Del"), dwStyle,CRect(664,66,664+132,66+60),this,IDC_SYM_DEL);
	btn[5].Create(_T("BackSpace"), dwStyle,CRect(664,4,664+132,4+60),this,IDC_SYM_BACKSPACE);
	btn[6].Create(_T("→"), dwStyle,CRect(552,252,552+110,252+60),this,IDC_SYM_RIGHT);
	btn[7].Create(_T(">"), dwStyle,CRect(604,190,604+58,190+60),this,IDC_SYM_SYM4_11);
	btn[8].Create(_T("}"), dwStyle,CRect(604,128,604+58,128+60),this,IDC_SYM_SYM3_11);
	btn[9].Create(_T("]"), dwStyle,CRect(604,66,604+58,66+60),this,IDC_SYM_SYM2_11);
	btn[10].Create(_T("<"), dwStyle,CRect(544,190,544+58,190+60),this,IDC_SYM_SYM4_10);
	btn[11].Create(_T("{"), dwStyle,CRect(544,128,544+58,128+60),this,IDC_SYM_SYM3_10);
	btn[12].Create(_T("["), dwStyle,CRect(544,66,544+58,66+60),this,IDC_SYM_SYM2_10);
	btn[13].Create(_T(")"), dwStyle,CRect(604,4,604+58,4+60),this,IDC_SYM_SYM1_11);
	btn[14].Create(_T("("), dwStyle,CRect(544,4,544+58,4+60),this,IDC_SYM_SYM1_10);
	btn[15].Create(_T("∞"), dwStyle,CRect(484,190,484+58,190+60),this,IDC_SYM_SYM4_9);
	btn[16].Create(_T("》"), dwStyle,CRect(484,128,484+58,128+60),this,IDC_SYM_SYM3_9);
	btn[17].Create(_T(";"), dwStyle,CRect(484,66,484+58,66+60),this,IDC_SYM_SYM2_9);
	btn[18].Create(_T("^"), dwStyle,CRect(484,4,484+58,4+60),this,IDC_SYM_SYM1_9);
	btn[19].Create(_T("©"), dwStyle,CRect(424,190,424+58,190+60),this,IDC_SYM_SYM4_8);
	btn[20].Create(_T("《"), dwStyle,CRect(424,128,424+58,128+60),this,IDC_SYM_SYM3_8);
	btn[21].Create(_T("|"), dwStyle,CRect(424,66,424+58,66+60),this,IDC_SYM_SYM2_8);
	btn[22].Create(_T("™"), dwStyle,CRect(364,190,364+58,190+60),this,IDC_SYM_SYM4_7);
	btn[23].Create(_T("?"), dwStyle,CRect(364,128,364+58,128+60),this,IDC_SYM_SYM3_7);
	btn[24].Create(_T("\\"), dwStyle,CRect(364,66,364+58,66+60),this,IDC_SYM_SYM2_7);
	btn[25].Create(_T("%"), dwStyle,CRect(424,4,424+58,4+60),this,IDC_SYM_SYM1_8);
	btn[26].Create(_T("$"), dwStyle,CRect(364,4,364+58,4+60),this,IDC_SYM_SYM1_7);
	btn[27].Create(_T("®"), dwStyle,CRect(304,190,304+58,190+60),this,IDC_SYM_SYM4_6);
	btn[28].Create(_T("/"), dwStyle,CRect(304,128,304+58,128+60),this,IDC_SYM_SYM3_6);
	btn[29].Create(_T("+"), dwStyle,CRect(304,66,304+58,66+60),this,IDC_SYM_SYM2_6);
	btn[30].Create(_T("℃"), dwStyle,CRect(244,190,244+58,190+60),this,IDC_SYM_SYM4_5);
	btn[31].Create(_T("."), dwStyle,CRect(244,128,244+58,128+60),this,IDC_SYM_SYM3_5);
	btn[32].Create(_T("="), dwStyle,CRect(244,66,244+58,66+60),this,IDC_SYM_SYM2_5);
	btn[33].Create(_T("#"), dwStyle,CRect(304,4,304+58,4+60),this,IDC_SYM_SYM1_6);
	btn[34].Create(_T("@"), dwStyle,CRect(244,4,244+58,4+60),this,IDC_SYM_SYM1_5);
	btn[35].Create(_T("³"), dwStyle,CRect(184,190,184+58,190+60),this,IDC_SYM_SYM4_4);
	btn[36].Create(_T(","), dwStyle,CRect(184,128,184+58,128+60),this,IDC_SYM_SYM3_4);
	btn[37].Create(_T("_"), dwStyle,CRect(184,66,184+58,66+60),this,IDC_SYM_SYM2_4);
	btn[38].Create(_T("²"), dwStyle,CRect(124,190,124+58,190+60),this,IDC_SYM_SYM4_3);
	btn[39].Create(_T("\""), dwStyle,CRect(124,128,124+58,128+60),this,IDC_SYM_SYM3_3);
	btn[40].Create(_T("-"), dwStyle,CRect(124,66,124+58,66+60),this,IDC_SYM_SYM2_3);
	btn[41].Create(_T("!"), dwStyle,CRect(184,4,184+58,4+60),this,IDC_SYM_SYM1_4);
	btn[42].Create(_T("~"), dwStyle,CRect(124,4,124+58,4+60),this,IDC_SYM_SYM1_3);
	btn[43].Create(_T("℡"), dwStyle,CRect(64,190,64+58,190+60),this,IDC_SYM_SYM4_2);
	btn[44].Create(_T("'"), dwStyle,CRect(64,128,64+58,128+60),this,IDC_SYM_SYM3_2);
	btn[45].Create(_T("*"), dwStyle,CRect(64,66,64+58,66+60),this,IDC_SYM_SYM2_2);
	btn[46].Create(_T("￥"), dwStyle,CRect(4,190,4+58,190+60),this,IDC_SYM_SYM4_1);
	btn[47].Create(_T("←"), dwStyle,CRect(440,252,440+110,252+60),this,IDC_SYM_LEFT);
	btn[48].Create(_T("Alphabet"), dwStyle,CRect(4,252,4+190,252+60),this,IDC_SYM_ALPHABET);
	btn[49].Create(_T("Space"), dwStyle,CRect(196,252,196+242,252+60),this,IDC_SYM_SPACE);
	btn[50].Create(_T(":"), dwStyle,CRect(4,128,4+58,128+60),this,IDC_SYM_SYM3_1);
	btn[51].Create(_T("&&"), dwStyle,CRect(4,66,4+58,66+60),this,IDC_SYM_SYM2_1);
	btn[52].Create(_T("`"), dwStyle,CRect(64,4,64+58,4+60),this,IDC_SYM_SYM1_2);
	btn[53].Create(_T("№"), dwStyle,CRect(4,4,4+58,4+60),this,IDC_SYM_SYM1_1);

	////////////////////////设置字体//////////////////////////////////////////////////
	CFont *pFont = new CFont; //创建一个指向新字体类型的指针pFont
	pFont->CreatePointFont(180, _T("黑体"));
	GetDlgItem(IDC_SYM_PGDN)->SetFont(pFont);
	GetDlgItem(IDC_SYM_PGUP)->SetFont(pFont);
	GetDlgItem(IDC_SYM_ENTER)->SetFont(pFont);
	GetDlgItem(IDC_SYM_DEL)->SetFont(pFont);
	GetDlgItem(IDC_SYM_BACKSPACE)->SetFont(pFont);
	GetDlgItem(IDC_SYM_RIGHT)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM4_11)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM3_11)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM2_11)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM4_10)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM3_10)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM2_10)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM1_11)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM1_10)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM4_9)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM3_9)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM2_9)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM1_9)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM4_8)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM3_8)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM2_8)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM4_7)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM3_7)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM2_7)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM1_8)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM1_7)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM4_6)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM3_6)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM2_6)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM4_5)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM3_5)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM2_5)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM1_6)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM1_5)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM4_4)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM3_4)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM2_4)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM4_3)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM3_3)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM2_3)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM1_4)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM1_3)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM4_2)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM3_2)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM2_2)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM4_1)->SetFont(pFont);
	GetDlgItem(IDC_SYM_LEFT)->SetFont(pFont);
	GetDlgItem(IDC_SYM_ALPHABET)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SPACE)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM3_1)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM2_1)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM1_2)->SetFont(pFont);
	GetDlgItem(IDC_SYM_SYM1_1)->SetFont(pFont);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
void CKeyBoSym::OnBnClickedSymAlphbet()
{//打开Main窗口
	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pLan->ShowWindow(SW_HIDE);
	pWnd->m_pMain->ShowWindow(SW_SHOW);
	pWnd->m_pCaps->ShowWindow(SW_HIDE);
	pWnd->LanType = pWnd->LantypeReverse;
	if (pWnd->LanType == 0||pWnd->LanType == 1||pWnd->LanType == 2||
		pWnd->LanType == 3||pWnd->LanType == 21||pWnd->LanType == 22)
	{
		pWnd->btnShow();
		pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
	}
	// TODO: 在此添加控件通知处理程序代码
}

void CKeyBoSym::OnBnClickedSymBackspace()
{
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	//pWnd->m_pMain->OnBnClickedMainBackspace();
	int nPosStart;
	int nPosEnd  = 0; 
	pWnd->m_edit_input.GetSel(nPosStart, nPosEnd); 
	pWnd->m_edit_input.SetSel(nPosStart-1, nPosStart);                            
	pWnd->m_edit_input.ReplaceSel(_T(""));
}

void CKeyBoSym::OnBnClickedSymSpace()
{
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	//pWnd->m_pMain->OnBnClickedMainSpace();
	int nPosStart;
	int nPosEnd  = 0; 
	pWnd->m_edit_input.GetSel(nPosStart, nPosEnd); 
	pWnd->m_edit_input.SetSel(nPosStart, nPosStart);                            
	pWnd->m_edit_input.ReplaceSel(_T(" "));
}

void CKeyBoSym::OnBnClickedSymDel()
{
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	//pWnd->m_pMain->OnBnClickedMainDel();
	int nPosStart;
	int nPosEnd  = 0; 
	pWnd->m_edit_input.GetSel(nPosStart, nPosEnd); 
	pWnd->m_edit_input.SetSel(nPosStart, nPosStart+1);                            
	pWnd->m_edit_input.ReplaceSel(_T(""));
}

void CKeyBoSym::OnBnClickedSymEnter()
{
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pMain->OnBnClickedMainEnter();
}

void CKeyBoSym::OnBnClickedSymRight()
{
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	//pWnd->m_pMain->OnBnClickedMainRight();
	int nPosStart;
	int nPosEnd  = 0; 
	pWnd->m_edit_input.GetSel(nPosStart, nPosEnd); 
	pWnd->m_edit_input.SetSel(nPosStart+1, nPosStart+1); 
	pWnd->m_edit_input.SetFocus();
}

void CKeyBoSym::OnBnClickedSymLeft()
{
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	//pWnd->m_pMain->OnBnClickedMainLeft();
	int nPosStart;
	int nPosEnd  = 0; 
	pWnd->m_edit_input.GetSel(nPosStart, nPosEnd); 
	pWnd->m_edit_input.SetSel(nPosStart-1, nPosStart-1);
	pWnd->m_edit_input.SetFocus();
}

void CKeyBoSym::OnBnClickedSymPgDn()
{
	CString strCur;
	GetDlgItem(IDC_SYM_SYM1_1)->GetWindowText(strCur);
	if ( strCur == "№")
	{
		GetDlgItem(IDC_SYM_SYM4_11)->SetWindowText(_T("ω"));
		GetDlgItem(IDC_SYM_SYM4_10)->SetWindowText(_T("ψ"));
		GetDlgItem(IDC_SYM_SYM4_9)->SetWindowText(_T("χ"));	
		GetDlgItem(IDC_SYM_SYM4_8)->SetWindowText(_T("φ"));
		GetDlgItem(IDC_SYM_SYM4_7)->SetWindowText(_T("㏒"));
		GetDlgItem(IDC_SYM_SYM4_6)->SetWindowText(_T("㏑"));
		GetDlgItem(IDC_SYM_SYM4_5)->SetWindowText(_T("㏕"));	
		GetDlgItem(IDC_SYM_SYM4_4)->SetWindowText(_T("↓"));	
		GetDlgItem(IDC_SYM_SYM4_3)->SetWindowText(_T("→"));	
		GetDlgItem(IDC_SYM_SYM4_2)->SetWindowText(_T("↑"));
		GetDlgItem(IDC_SYM_SYM4_1)->SetWindowText(_T("←"));
		GetDlgItem(IDC_SYM_SYM3_11)->SetWindowText(_T("½"));
		GetDlgItem(IDC_SYM_SYM3_10)->SetWindowText(_T("£"));
		GetDlgItem(IDC_SYM_SYM3_9)->SetWindowText(_T("¢"));
		GetDlgItem(IDC_SYM_SYM3_8)->SetWindowText(_T("仝"));
		GetDlgItem(IDC_SYM_SYM3_7)->SetWindowText(_T("ベ"));
		GetDlgItem(IDC_SYM_SYM3_6)->SetWindowText(_T("ヘ"));
		GetDlgItem(IDC_SYM_SYM3_5)->SetWindowText(_T("ゞ"));
		GetDlgItem(IDC_SYM_SYM3_4)->SetWindowText(_T("ゝ"));
		GetDlgItem(IDC_SYM_SYM3_3)->SetWindowText(_T("」"));
		GetDlgItem(IDC_SYM_SYM3_2)->SetWindowText(_T("「"));
		GetDlgItem(IDC_SYM_SYM3_1)->SetWindowText(_T("〇"));
		GetDlgItem(IDC_SYM_SYM2_11)->SetWindowText(_T("〆"));
		GetDlgItem(IDC_SYM_SYM2_10)->SetWindowText(_T("々"));
		GetDlgItem(IDC_SYM_SYM2_9)->SetWindowText(_T("♂"));
		GetDlgItem(IDC_SYM_SYM2_8)->SetWindowText(_T("♀"));
		GetDlgItem(IDC_SYM_SYM2_7)->SetWindowText(_T("☆"));
		GetDlgItem(IDC_SYM_SYM2_6)->SetWindowText(_T("★"));
		GetDlgItem(IDC_SYM_SYM2_5)->SetWindowText(_T("●"));
		GetDlgItem(IDC_SYM_SYM2_4)->SetWindowText(_T("◎"));
		GetDlgItem(IDC_SYM_SYM2_3)->SetWindowText(_T("¤"));
		GetDlgItem(IDC_SYM_SYM2_2)->SetWindowText(_T("ß"));
		GetDlgItem(IDC_SYM_SYM2_1)->SetWindowText(_T("Ł"));
		GetDlgItem(IDC_SYM_SYM1_11)->SetWindowText(_T("ł"));
		GetDlgItem(IDC_SYM_SYM1_10)->SetWindowText(_T("Đ"));
		GetDlgItem(IDC_SYM_SYM1_9)->SetWindowText(_T("đ"));
		GetDlgItem(IDC_SYM_SYM1_8)->SetWindowText(_T("≧"));
		GetDlgItem(IDC_SYM_SYM1_7)->SetWindowText(_T("≦"));
		GetDlgItem(IDC_SYM_SYM1_6)->SetWindowText(_T("≠"));
		GetDlgItem(IDC_SYM_SYM1_5)->SetWindowText(_T("∴"));
		GetDlgItem(IDC_SYM_SYM1_4)->SetWindowText(_T("‖"));
		GetDlgItem(IDC_SYM_SYM1_3)->SetWindowText(_T("※"));
		GetDlgItem(IDC_SYM_SYM1_2)->SetWindowText(_T("‰"));
		GetDlgItem(IDC_SYM_SYM1_1)->SetWindowText(_T("℅"));
	} 
	else if( strCur == "℅")
	{	
		GetDlgItem(IDC_SYM_SYM4_11)->SetWindowText(_T("υ"));
		GetDlgItem(IDC_SYM_SYM4_10)->SetWindowText(_T("τ"));
		GetDlgItem(IDC_SYM_SYM4_9)->SetWindowText(_T("σ"));	
		GetDlgItem(IDC_SYM_SYM4_8)->SetWindowText(_T("ρ"));
		GetDlgItem(IDC_SYM_SYM4_7)->SetWindowText(_T("π"));
		GetDlgItem(IDC_SYM_SYM4_6)->SetWindowText(_T("ο"));
		GetDlgItem(IDC_SYM_SYM4_5)->SetWindowText(_T("ξ"));	
		GetDlgItem(IDC_SYM_SYM4_4)->SetWindowText(_T("ν"));	
		GetDlgItem(IDC_SYM_SYM4_3)->SetWindowText(_T("μ"));	
		GetDlgItem(IDC_SYM_SYM4_2)->SetWindowText(_T("λ"));
		GetDlgItem(IDC_SYM_SYM4_1)->SetWindowText(_T("κ"));
		GetDlgItem(IDC_SYM_SYM3_11)->SetWindowText(_T("ι"));
		GetDlgItem(IDC_SYM_SYM3_10)->SetWindowText(_T("θ"));
		GetDlgItem(IDC_SYM_SYM3_9)->SetWindowText(_T("η"));
		GetDlgItem(IDC_SYM_SYM3_8)->SetWindowText(_T("ζ"));
		GetDlgItem(IDC_SYM_SYM3_7)->SetWindowText(_T("ε"));
		GetDlgItem(IDC_SYM_SYM3_6)->SetWindowText(_T("δ"));
		GetDlgItem(IDC_SYM_SYM3_5)->SetWindowText(_T("γ"));
		GetDlgItem(IDC_SYM_SYM3_4)->SetWindowText(_T("β"));
		GetDlgItem(IDC_SYM_SYM3_3)->SetWindowText(_T("α"));
		GetDlgItem(IDC_SYM_SYM3_2)->SetWindowText(_T("Ω"));
		GetDlgItem(IDC_SYM_SYM3_1)->SetWindowText(_T("Ψ"));
		GetDlgItem(IDC_SYM_SYM2_11)->SetWindowText(_T("Χ"));
		GetDlgItem(IDC_SYM_SYM2_10)->SetWindowText(_T("Φ"));
		GetDlgItem(IDC_SYM_SYM2_9)->SetWindowText(_T("Υ"));
		GetDlgItem(IDC_SYM_SYM2_8)->SetWindowText(_T("Τ"));
		GetDlgItem(IDC_SYM_SYM2_7)->SetWindowText(_T("Σ"));
		GetDlgItem(IDC_SYM_SYM2_6)->SetWindowText(_T("Ρ"));
		GetDlgItem(IDC_SYM_SYM2_5)->SetWindowText(_T("Π"));
		GetDlgItem(IDC_SYM_SYM2_4)->SetWindowText(_T("Ο"));
		GetDlgItem(IDC_SYM_SYM2_3)->SetWindowText(_T("Ξ"));
		GetDlgItem(IDC_SYM_SYM2_2)->SetWindowText(_T("Ν"));
		GetDlgItem(IDC_SYM_SYM2_1)->SetWindowText(_T("Μ"));
		GetDlgItem(IDC_SYM_SYM1_11)->SetWindowText(_T("Λ"));
		GetDlgItem(IDC_SYM_SYM1_10)->SetWindowText(_T("Κ"));
		GetDlgItem(IDC_SYM_SYM1_9)->SetWindowText(_T("Ι"));
		GetDlgItem(IDC_SYM_SYM1_8)->SetWindowText(_T("Θ"));
		GetDlgItem(IDC_SYM_SYM1_7)->SetWindowText(_T("Η"));
		GetDlgItem(IDC_SYM_SYM1_6)->SetWindowText(_T("Ζ"));
		GetDlgItem(IDC_SYM_SYM1_5)->SetWindowText(_T("Ε"));
		GetDlgItem(IDC_SYM_SYM1_4)->SetWindowText(_T("Γ"));
		GetDlgItem(IDC_SYM_SYM1_3)->SetWindowText(_T("Β"));
		GetDlgItem(IDC_SYM_SYM1_2)->SetWindowText(_T("Α"));
		GetDlgItem(IDC_SYM_SYM1_1)->SetWindowText(_T("¡"));
	}
	else
	{
		return;
	}

}

void CKeyBoSym::OnBnClickedSymPgUp()
{
	CString strCur;
	GetDlgItem(IDC_SYM_SYM1_1)->GetWindowText(strCur);
	if ( strCur == _T("¡"))
	{
		GetDlgItem(IDC_SYM_SYM4_11)->SetWindowText(_T("ω"));
		GetDlgItem(IDC_SYM_SYM4_10)->SetWindowText(_T("ψ"));
		GetDlgItem(IDC_SYM_SYM4_9)->SetWindowText(_T("χ"));	
		GetDlgItem(IDC_SYM_SYM4_8)->SetWindowText(_T("φ"));
		GetDlgItem(IDC_SYM_SYM4_7)->SetWindowText(_T("㏒"));
		GetDlgItem(IDC_SYM_SYM4_6)->SetWindowText(_T("㏑"));
		GetDlgItem(IDC_SYM_SYM4_5)->SetWindowText(_T("㏕"));	
		GetDlgItem(IDC_SYM_SYM4_4)->SetWindowText(_T("↓"));	
		GetDlgItem(IDC_SYM_SYM4_3)->SetWindowText(_T("→"));	
		GetDlgItem(IDC_SYM_SYM4_2)->SetWindowText(_T("↑"));
		GetDlgItem(IDC_SYM_SYM4_1)->SetWindowText(_T("←"));
		GetDlgItem(IDC_SYM_SYM3_11)->SetWindowText(_T("½"));
		GetDlgItem(IDC_SYM_SYM3_10)->SetWindowText(_T("£"));
		GetDlgItem(IDC_SYM_SYM3_9)->SetWindowText(_T("¢"));
		GetDlgItem(IDC_SYM_SYM3_8)->SetWindowText(_T("仝"));
		GetDlgItem(IDC_SYM_SYM3_7)->SetWindowText(_T("ベ"));
		GetDlgItem(IDC_SYM_SYM3_6)->SetWindowText(_T("ヘ"));
		GetDlgItem(IDC_SYM_SYM3_5)->SetWindowText(_T("ゞ"));
		GetDlgItem(IDC_SYM_SYM3_4)->SetWindowText(_T("ゝ"));
		GetDlgItem(IDC_SYM_SYM3_3)->SetWindowText(_T("」"));
		GetDlgItem(IDC_SYM_SYM3_2)->SetWindowText(_T("「"));
		GetDlgItem(IDC_SYM_SYM3_1)->SetWindowText(_T("〇"));
		GetDlgItem(IDC_SYM_SYM2_11)->SetWindowText(_T("〆"));
		GetDlgItem(IDC_SYM_SYM2_10)->SetWindowText(_T("々"));
		GetDlgItem(IDC_SYM_SYM2_9)->SetWindowText(_T("♂"));
		GetDlgItem(IDC_SYM_SYM2_8)->SetWindowText(_T("♀"));
		GetDlgItem(IDC_SYM_SYM2_7)->SetWindowText(_T("☆"));
		GetDlgItem(IDC_SYM_SYM2_6)->SetWindowText(_T("★"));
		GetDlgItem(IDC_SYM_SYM2_5)->SetWindowText(_T("●"));
		GetDlgItem(IDC_SYM_SYM2_4)->SetWindowText(_T("◎"));
		GetDlgItem(IDC_SYM_SYM2_3)->SetWindowText(_T("¤"));
		GetDlgItem(IDC_SYM_SYM2_2)->SetWindowText(_T("ß"));
		GetDlgItem(IDC_SYM_SYM2_1)->SetWindowText(_T("Ł"));
		GetDlgItem(IDC_SYM_SYM1_11)->SetWindowText(_T("ł"));
		GetDlgItem(IDC_SYM_SYM1_10)->SetWindowText(_T("Đ"));
		GetDlgItem(IDC_SYM_SYM1_9)->SetWindowText(_T("đ"));
		GetDlgItem(IDC_SYM_SYM1_8)->SetWindowText(_T("≧"));
		GetDlgItem(IDC_SYM_SYM1_7)->SetWindowText(_T("≦"));
		GetDlgItem(IDC_SYM_SYM1_6)->SetWindowText(_T("≠"));
		GetDlgItem(IDC_SYM_SYM1_5)->SetWindowText(_T("∴"));
		GetDlgItem(IDC_SYM_SYM1_4)->SetWindowText(_T("‖"));
		GetDlgItem(IDC_SYM_SYM1_3)->SetWindowText(_T("※"));
		GetDlgItem(IDC_SYM_SYM1_2)->SetWindowText(_T("‰"));
		GetDlgItem(IDC_SYM_SYM1_1)->SetWindowText(_T("℅"));
	} 
	else if( strCur == "℅")
	{	
		GetDlgItem(IDC_SYM_SYM4_11)->SetWindowText(_T(">"));
		GetDlgItem(IDC_SYM_SYM4_10)->SetWindowText(_T("<"));
		GetDlgItem(IDC_SYM_SYM4_9)->SetWindowText(_T("∞"));	
		GetDlgItem(IDC_SYM_SYM4_8)->SetWindowText(_T("©"));
		GetDlgItem(IDC_SYM_SYM4_7)->SetWindowText(_T("™"));
		GetDlgItem(IDC_SYM_SYM4_6)->SetWindowText(_T("®"));
		GetDlgItem(IDC_SYM_SYM4_5)->SetWindowText(_T("℃"));	
		GetDlgItem(IDC_SYM_SYM4_4)->SetWindowText(_T("³"));	
		GetDlgItem(IDC_SYM_SYM4_3)->SetWindowText(_T("²"));	
		GetDlgItem(IDC_SYM_SYM4_2)->SetWindowText(_T("。"));
		GetDlgItem(IDC_SYM_SYM4_1)->SetWindowText(_T("￥"));
		GetDlgItem(IDC_SYM_SYM3_11)->SetWindowText(_T("}"));
		GetDlgItem(IDC_SYM_SYM3_10)->SetWindowText(_T("{"));
		GetDlgItem(IDC_SYM_SYM3_9)->SetWindowText(_T("》"));
		GetDlgItem(IDC_SYM_SYM3_8)->SetWindowText(_T("《"));
		GetDlgItem(IDC_SYM_SYM3_7)->SetWindowText(_T("?"));
		GetDlgItem(IDC_SYM_SYM3_6)->SetWindowText(_T("/"));
		GetDlgItem(IDC_SYM_SYM3_5)->SetWindowText(_T("."));
		GetDlgItem(IDC_SYM_SYM3_4)->SetWindowText(_T(","));
		GetDlgItem(IDC_SYM_SYM3_3)->SetWindowText(_T("\""));
		GetDlgItem(IDC_SYM_SYM3_2)->SetWindowText(_T("'"));
		GetDlgItem(IDC_SYM_SYM3_1)->SetWindowText(_T(":"));
		GetDlgItem(IDC_SYM_SYM2_11)->SetWindowText(_T("]"));
		GetDlgItem(IDC_SYM_SYM2_10)->SetWindowText(_T("["));
		GetDlgItem(IDC_SYM_SYM2_9)->SetWindowText(_T(";"));
		GetDlgItem(IDC_SYM_SYM2_8)->SetWindowText(_T("|"));
		GetDlgItem(IDC_SYM_SYM2_7)->SetWindowText(_T("\\"));
		GetDlgItem(IDC_SYM_SYM2_6)->SetWindowText(_T("+"));
		GetDlgItem(IDC_SYM_SYM2_5)->SetWindowText(_T("="));
		GetDlgItem(IDC_SYM_SYM2_4)->SetWindowText(_T("_"));
		GetDlgItem(IDC_SYM_SYM2_3)->SetWindowText(_T("-"));
		GetDlgItem(IDC_SYM_SYM2_2)->SetWindowText(_T("*"));
		GetDlgItem(IDC_SYM_SYM2_1)->SetWindowText(_T("&&"));
		GetDlgItem(IDC_SYM_SYM1_11)->SetWindowText(_T(")"));
		GetDlgItem(IDC_SYM_SYM1_10)->SetWindowText(_T("("));
		GetDlgItem(IDC_SYM_SYM1_9)->SetWindowText(_T("^"));
		GetDlgItem(IDC_SYM_SYM1_8)->SetWindowText(_T("%"));
		GetDlgItem(IDC_SYM_SYM1_7)->SetWindowText(_T("$"));
		GetDlgItem(IDC_SYM_SYM1_6)->SetWindowText(_T("#"));
		GetDlgItem(IDC_SYM_SYM1_5)->SetWindowText(_T("@"));
		GetDlgItem(IDC_SYM_SYM1_4)->SetWindowText(_T("!"));
		GetDlgItem(IDC_SYM_SYM1_3)->SetWindowText(_T("~"));
		GetDlgItem(IDC_SYM_SYM1_2)->SetWindowText(_T("`"));
		GetDlgItem(IDC_SYM_SYM1_1)->SetWindowText(_T("№"));
	}
	else
	{
		return;
	}
}
//////////////////////////////////////////////////////////////////////////
void CKeyBoSym::OnBnClickedSym_1_1()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM1_1)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_1_2()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM1_2)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_1_3()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM1_3)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_1_4()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM1_4)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_1_5()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM1_5)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_1_6()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM1_6)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_1_7()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM1_7)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_1_8()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM1_8)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_1_9()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM1_9)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_1_10()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM1_10)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_1_11()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM1_11)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
//////////////////////////////////////////////////////////////////////////
void CKeyBoSym::OnBnClickedSym_2_1()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM2_1)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_2_2()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM2_2)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_2_3()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM2_3)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_2_4()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM2_4)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_2_5()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM2_5)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_2_6()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM2_6)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_2_7()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM2_7)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_2_8()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM2_8)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_2_9()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM2_9)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_2_10()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM2_10)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_2_11()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM2_11)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
//////////////////////////////////////////////////////////////////////////
void CKeyBoSym::OnBnClickedSym_3_1()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM3_1)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_3_2()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM3_2)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_3_3()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM3_3)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_3_4()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM3_4)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_3_5()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM3_5)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_3_6()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM3_6)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_3_7()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM3_7)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_3_8()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM3_8)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_3_9()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM3_9)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_3_10()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM3_10)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_3_11()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM3_11)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
//////////////////////////////////////////////////////////////////////////
void CKeyBoSym::OnBnClickedSym_4_1()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM4_1)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_4_2()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM4_2)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_4_3()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM4_3)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_4_4()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM4_4)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_4_5()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM4_5)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_4_6()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM4_6)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_4_7()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM4_7)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_4_8()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM4_8)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_4_9()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM4_9)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_4_10()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM4_10)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoSym::OnBnClickedSym_4_11()
{
	CString tempstr;
	GetDlgItem(IDC_SYM_SYM4_11)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}