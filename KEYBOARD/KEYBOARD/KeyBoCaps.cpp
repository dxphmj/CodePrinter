// KeyBoCaps.cpp : 实现文件
//

#include "stdafx.h"
#include "KeyBoard.h"
#include "KeyBoCaps.h"
#include "KeyBoardDlg.h"


// CKeyBoCaps 对话框

IMPLEMENT_DYNAMIC(CKeyBoCaps, CDialog)

CKeyBoCaps::CKeyBoCaps(CWnd* pParent /*=NULL*/)
	: CDialog(CKeyBoCaps::IDD, pParent)
{

}

CKeyBoCaps::~CKeyBoCaps()
{
}

void CKeyBoCaps::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CKeyBoCaps, CDialog)

	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_CAPS_CAPS, &CKeyBoCaps::OnBnClickedCAPS_CAPS)
END_MESSAGE_MAP()


// CKeyBoCaps 消息处理程序

BOOL CKeyBoCaps::OnInitDialog()
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
	btn[1].Create(_T("PgDn"), dwStyle,CRect(719,190,719+77,190+60),this,IDC_CAPS_PGDN);
	btn[2].Create(_T("PgUp"), dwStyle,CRect(641,190,641+77,190+60),this,IDC_CAPS_PGUP);
	btn[3].Create(_T("?"), dwStyle,CRect(590,190,590+50,190+60),this,IDC_CAPS_SYM_11);
	btn[4].Create(_T(">"), dwStyle,CRect(539,190,539+50,190+60),this,IDC_CAPS_SYM_10);
	btn[5].Create(_T("<"), dwStyle,CRect(488,190,488+50,190+60),this,IDC_CAPS_SYM_9);
	btn[6].Create(_T("M"), dwStyle,CRect(437,190,437+50,190+60),this,IDC_CAPS_M);
	btn[7].Create(_T("N"), dwStyle,CRect(386,190,386+50,190+60),this,IDC_CAPS_N);
	btn[8].Create(_T("B"), dwStyle,CRect(335,190,335+50,190+60),this,IDC_CAPS_B);
	btn[9].Create(_T("V"), dwStyle,CRect(284,190,284+50,190+60),this,IDC_CAPS_V);
	btn[10].Create(_T("C"), dwStyle,CRect(233,190,233+50,190+60),this,IDC_CAPS_C);
	btn[11].Create(_T("X"), dwStyle,CRect(182,190,182+50,190+60),this,IDC_CAPS_X);
	btn[12].Create(_T("Symbol"), dwStyle,CRect(4,190,4+126,190+60),this,IDC_CAPS_SYMBOL);
	btn[13].Create(_T("Z"), dwStyle,CRect(131,190,131+50,190+60),this,IDC_CAPS_Z);
	btn[14].Create(_T("→"), dwStyle,CRect(687,252,687+109,252+60),this,IDC_CAPS_RIGHT);
	btn[15].Create(_T("←"), dwStyle,CRect(577,252,577+109,252+60),this,IDC_CAPS_LEFT);
	btn[16].Create(_T("N / S"), dwStyle,CRect(450,252,450+126,252+60),this,IDC_CAPS_NS);
	btn[17].Create(_T("Language"), dwStyle,CRect(4,252,4+190,252+60),this,IDC_CAPS_LAN);
	btn[18].Create(_T("Space"), dwStyle,CRect(195,252,195+254,252+60),this,IDC_CAPS_SPACE);
	btn[19].Create(_T("Enter"), dwStyle,CRect(666,128,666+130,128+60),this,IDC_CAPS_ENTER);
	btn[20].Create(_T("\""), dwStyle,CRect(615,128,615+50,128+60),this,IDC_CAPS_SYM_8);//显示问题
	btn[21].Create(_T(":"), dwStyle,CRect(564,128,564+50,128+60),this,IDC_CAPS_SYM_7);
	btn[22].Create(_T("L"), dwStyle,CRect(513,128,513+50,128+60),this,IDC_CAPS_L);
	btn[23].Create(_T("K"), dwStyle,CRect(462,128,462+50,128+60),this,IDC_CAPS_K);
	btn[24].Create(_T("J"), dwStyle,CRect(411,128,411+50,128+60),this,IDC_CAPS_J);
	btn[25].Create(_T("H"), dwStyle,CRect(360,128,360+50,128+60),this,IDC_CAPS_H);
	btn[26].Create(_T("G"), dwStyle,CRect(309,128,309+50,128+60),this,IDC_CAPS_G);
	btn[27].Create(_T("F"), dwStyle,CRect(258,128,258+50,128+60),this,IDC_CAPS_F);
	btn[28].Create(_T("D"), dwStyle,CRect(207,128,207+50,128+60),this,IDC_CAPS_D);
	btn[29].Create(_T("S"), dwStyle,CRect(156,128,156+50,128+60),this,IDC_CAPS_S);
	btn[30].Create(_T("Caps"), dwStyle,CRect(4,128,4+100,128+60),this,IDC_CAPS_CAPS);
	btn[31].Create(_T("A"), dwStyle,CRect(105,128,105+50,128+60),this,IDC_CAPS_A);
	btn[32].Create(_T("Del"), dwStyle,CRect(731,66,731+65,66+60),this,IDC_CAPS_DEL);
	btn[33].Create(_T(" L "), dwStyle,CRect(680,66,680+50,66+60),this,IDC_CAPS_SYM_6);
	btn[34].Create(_T("}"), dwStyle,CRect(629,66,629+50,66+60),this,IDC_CAPS_SYM_5);
	btn[35].Create(_T("{"), dwStyle,CRect(578,66,578+50,66+60),this,IDC_CAPS_SYM_4);
	btn[36].Create(_T("P"), dwStyle,CRect(527,66,527+50,66+60),this,IDC_CAPS_P);
	btn[37].Create(_T("O"), dwStyle,CRect(476,66,476+50,66+60),this,IDC_CAPS_O);
	btn[38].Create(_T("I"), dwStyle,CRect(425,66,425+50,66+60),this,IDC_CAPS_I);
	btn[39].Create(_T("U"), dwStyle,CRect(374,66,374+50,66+60),this,IDC_CAPS_U);
	btn[40].Create(_T("Y"), dwStyle,CRect(323,66,323+50,66+60),this,IDC_CAPS_Y);
	btn[41].Create(_T("T"), dwStyle,CRect(272,66,272+50,66+60),this,IDC_CAPS_T);
	btn[42].Create(_T("R"), dwStyle,CRect(221,66,224+50,66+60),this,IDC_CAPS_R);
	btn[43].Create(_T("E"), dwStyle,CRect(170,66,170+50,66+60),this,IDC_CAPS_E);
	btn[44].Create(_T("W"), dwStyle,CRect(119,66,119+50,66+60),this,IDC_CAPS_W);
	btn[45].Create(_T("Esc"), dwStyle,CRect(4,66,4+63,66+60),this,IDC_CAPS_ESC);
	btn[46].Create(_T("Q"), dwStyle,CRect(68,66,68+50,66+60),this,IDC_CAPS_Q);
	btn[47].Create(_T("BackSpace"), dwStyle,CRect(667,4,667+129,4+60),this,IDC_CAPS_BACKSPACE);
	btn[48].Create(_T("+"), dwStyle,CRect(616,4,616+50,4+60),this,IDC_CAPS_SYM_3);
	btn[49].Create(_T("_"), dwStyle,CRect(565,4,565+50,4+60),this,IDC_CAPS_SYM_2);
	btn[50].Create(_T("0"), dwStyle,CRect(514,4,514+50,4+60),this,IDC_CAPS_0);
	btn[51].Create(_T("9"), dwStyle,CRect(463,4,463+50,4+60),this,IDC_CAPS_9);
	btn[52].Create(_T("8"), dwStyle,CRect(412,4,412+50,4+60),this,IDC_CAPS_8);
	btn[53].Create(_T("7"), dwStyle,CRect(361,4,361+50,4+60),this,IDC_CAPS_7);
	btn[54].Create(_T("6"), dwStyle,CRect(310,4,310+50,4+60),this,IDC_CAPS_6);
	btn[55].Create(_T("5"), dwStyle,CRect(259,4,259+50,4+60),this,IDC_CAPS_5);
	btn[56].Create(_T("4"), dwStyle,CRect(208,4,208+50,4+60),this,IDC_CAPS_4);
	btn[57].Create(_T("3"), dwStyle,CRect(157,4,157+50,4+60),this,IDC_CAPS_3);
	btn[58].Create(_T("2"), dwStyle,CRect(106,4,106+50,4+60),this,IDC_CAPS_2);
	btn[59].Create(_T("1"), dwStyle,CRect(55,4,55+50,4+60),this,IDC_CAPS_1);
	btn[60].Create(_T("~"), dwStyle,CRect(4,4,4+50,4+60),this,IDC_CAPS_SYM_1);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
void CKeyBoCaps::OnBnClickedCAPS_CAPS()
{//打开Main窗口
	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pLan->ShowWindow(SW_HIDE);
	pWnd->m_pSym->ShowWindow(SW_HIDE);
	pWnd->m_pMain->ShowWindow(SW_SHOW);
}
