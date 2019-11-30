// KeyBoSym.cpp : 实现文件
//

#include "stdafx.h"
#include "KeyBoard.h"
#include "KeyBoSym.h"


// CKeyBoSym 对话框

IMPLEMENT_DYNAMIC(CKeyBoSym, CDialog)

CKeyBoSym::CKeyBoSym(CWnd* pParent /*=NULL*/)
	: CDialog(CKeyBoSym::IDD, pParent)
{
		pSymMain = NULL;
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
	btn[24].Create(_T(" \\ "), dwStyle,CRect(364,66,364+58,66+60),this,IDC_SYM_SYM2_7);//显示问题
	btn[25].Create(_T("%"), dwStyle,CRect(424,4,424+58,4+60),this,IDC_SYM_SYM1_8);
	btn[26].Create(_T("$"), dwStyle,CRect(364,4,364+58,4+60),this,IDC_SYM_SYM1_7);
	btn[27].Create(_T("®"), dwStyle,CRect(304,190,304+58,190+60),this,IDC_SYM_SYM4_6);
	btn[28].Create(_T("/"), dwStyle,CRect(304,128,304+58,128+60),this,IDC_SYM_SYM3_6);
	btn[29].Create(_T("+"), dwStyle,CRect(304,66,304+58,66+60),this,IDC_SYM_SYM2_6);
	btn[30].Create(_T("℃"), dwStyle,CRect(244,190,244+58,190+60),this,IDC_SYM_SYM4_5);
	btn[31].Create(_T("."), dwStyle,CRect(244,128,244+58,128+60),this,IDC_SYM_SYM3_5);
	btn[32].Create(_T("="), dwStyle,CRect(244,66,244+58,66+60),this,IDC_SYM_SYM2_5);
	btn[33].Create(_T(" # "), dwStyle,CRect(304,4,304+58,4+60),this,IDC_SYM_SYM1_6);
	btn[34].Create(_T("@"), dwStyle,CRect(244,4,244+58,4+60),this,IDC_SYM_SYM1_5);
	btn[35].Create(_T("³"), dwStyle,CRect(184,190,184+58,190+60),this,IDC_SYM_SYM4_4);
	btn[36].Create(_T(","), dwStyle,CRect(184,128,184+58,128+60),this,IDC_SYM_SYM3_4);
	btn[37].Create(_T("_"), dwStyle,CRect(184,66,184+58,66+60),this,IDC_SYM_SYM2_4);
	btn[38].Create(_T("²"), dwStyle,CRect(124,190,124+58,190+60),this,IDC_SYM_SYM4_3);
	btn[39].Create(_T("\""), dwStyle,CRect(124,128,124+58,128+60),this,IDC_SYM_SYM3_3);//显示问题
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


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
void CKeyBoSym::OnBnClickedSymAlphbet()
{

	if (NULL == pSymMain)   
	{   
		// 创建非模态对话框实例   
		pSymMain = new CKeyBoMain();
		pSymMain->Create( IDD_KEYBOARD_MAIN,this);
	}  
	pSymMain->ShowWindow(SW_SHOW);

	// TODO: 在此添加控件通知处理程序代码
}