// KeyBoMain.cpp : 实现文件
//

#include "stdafx.h"
#include "KeyBoard.h"
#include "KeyBoMain.h"
#include "KeyBoardDlg.h"


// CKeyBoMain 对话框

IMPLEMENT_DYNAMIC(CKeyBoMain, CDialog)

CKeyBoMain::CKeyBoMain(CWnd* pParent /*=NULL*/)
	: CDialog(CKeyBoMain::IDD, pParent)
{

}

CKeyBoMain::~CKeyBoMain()
{
}

void CKeyBoMain::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CKeyBoMain, CDialog)

	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_MIAN_CAPS, &CKeyBoMain::OnBnClickedMainCaps)
	ON_BN_CLICKED(IDC_MIAN_SYMBOL, &CKeyBoMain::OnBnClickedMainSym)
	ON_BN_CLICKED(IDC_MIAN_LAN, &CKeyBoMain::OnBnClickedMainLan)
	ON_BN_CLICKED(IDC_MIAN_P, &CKeyBoMain::OnBnClickedMainP)
	ON_BN_CLICKED(IDC_MIAN_Y, &CKeyBoMain::OnBnClickedMainY)
	ON_BN_CLICKED(IDC_MIAN_A, &CKeyBoMain::OnBnClickedMainA)
	ON_BN_CLICKED(IDC_MIAN_N, &CKeyBoMain::OnBnClickedMainN)
	ON_BN_CLICKED(IDC_MIAN_I, &CKeyBoMain::OnBnClickedMainI)
	ON_BN_CLICKED(IDC_MIAN_ENTER, &CKeyBoMain::OnBnClickedMainEnter)
END_MESSAGE_MAP()


// CKeyBoMain 消息处理程序

BOOL CKeyBoMain::OnInitDialog()
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
	btn[1].Create(_T("PgDn"), dwStyle,CRect(719,190,719+77,190+60),this,IDC_MIAN_PGDN);
	btn[2].Create(_T("PgUp"), dwStyle,CRect(641,190,641+77,190+60),this,IDC_MIAN_PGUP);
	btn[3].Create(_T("/"), dwStyle,CRect(590,190,590+50,190+60),this,IDC_MIAN_SYM_11);
	btn[4].Create(_T("."), dwStyle,CRect(539,190,539+50,190+60),this,IDC_MIAN_SYM_10);
	btn[5].Create(_T(","), dwStyle,CRect(488,190,488+50,190+60),this,IDC_MIAN_SYM_9);
	btn[6].Create(_T("m"), dwStyle,CRect(437,190,437+50,190+60),this,IDC_MIAN_M);
	btn[7].Create(_T("n"), dwStyle,CRect(386,190,386+50,190+60),this,IDC_MIAN_N);
	btn[8].Create(_T("b"), dwStyle,CRect(335,190,335+50,190+60),this,IDC_MIAN_B);
	btn[9].Create(_T("v"), dwStyle,CRect(284,190,284+50,190+60),this,IDC_MIAN_V);
	btn[10].Create(_T("c"), dwStyle,CRect(233,190,233+50,190+60),this,IDC_MIAN_C);
	btn[11].Create(_T("x"), dwStyle,CRect(182,190,182+50,190+60),this,IDC_MIAN_X);
	btn[12].Create(_T("Symbol"), dwStyle,CRect(4,190,4+126,190+60),this,IDC_MIAN_SYMBOL);
	btn[13].Create(_T("z"), dwStyle,CRect(131,190,131+50,190+60),this,IDC_MIAN_Z);
	btn[14].Create(_T("→"), dwStyle,CRect(687,252,687+109,252+60),this,IDC_MIAN_RIGHT);
	btn[15].Create(_T("←"), dwStyle,CRect(577,252,577+109,252+60),this,IDC_MIAN_LEFT);
	btn[16].Create(_T("N / S"), dwStyle,CRect(450,252,450+126,252+60),this,IDC_MIAN_NS);
	btn[17].Create(_T("Language"), dwStyle,CRect(4,252,4+190,252+60),this,IDC_MIAN_LAN);
	btn[18].Create(_T("Space"), dwStyle,CRect(195,252,195+254,252+60),this,IDC_MIAN_SPACE);
	btn[19].Create(_T("Enter"), dwStyle,CRect(666,128,666+130,128+60),this,IDC_MIAN_ENTER);
	btn[20].Create(_T("'"), dwStyle,CRect(615,128,615+50,128+60),this,IDC_MIAN_SYM_8);
	btn[21].Create(_T(";"), dwStyle,CRect(564,128,564+50,128+60),this,IDC_MIAN_SYM_7);
	btn[22].Create(_T("l"), dwStyle,CRect(513,128,513+50,128+60),this,IDC_MIAN_L);
	btn[23].Create(_T("k"), dwStyle,CRect(462,128,462+50,128+60),this,IDC_MIAN_K);
	btn[24].Create(_T("j"), dwStyle,CRect(411,128,411+50,128+60),this,IDC_MIAN_J);
	btn[25].Create(_T("h"), dwStyle,CRect(360,128,360+50,128+60),this,IDC_MIAN_H);
	btn[26].Create(_T("g"), dwStyle,CRect(309,128,309+50,128+60),this,IDC_MIAN_G);
	btn[27].Create(_T("f"), dwStyle,CRect(258,128,258+50,128+60),this,IDC_MIAN_F);
	btn[28].Create(_T("d"), dwStyle,CRect(207,128,207+50,128+60),this,IDC_MIAN_D);
	btn[29].Create(_T("s"), dwStyle,CRect(156,128,156+50,128+60),this,IDC_MIAN_S);
	btn[30].Create(_T("Caps"), dwStyle,CRect(4,128,4+100,128+60),this,IDC_MIAN_CAPS);
	btn[31].Create(_T("a"), dwStyle,CRect(105,128,105+50,128+60),this,IDC_MIAN_A);
	btn[32].Create(_T("Del"), dwStyle,CRect(731,66,731+65,66+60),this,IDC_MIAN_DEL);
	btn[33].Create(_T("\\"), dwStyle,CRect(680,66,680+50,66+60),this,IDC_MIAN_SYM_6);
	btn[34].Create(_T("]"), dwStyle,CRect(629,66,629+50,66+60),this,IDC_MIAN_SYM_5);
	btn[35].Create(_T("["), dwStyle,CRect(578,66,578+50,66+60),this,IDC_MIAN_SYM_4);
	btn[36].Create(_T("p"), dwStyle,CRect(527,66,527+50,66+60),this,IDC_MIAN_P);
	btn[37].Create(_T("o"), dwStyle,CRect(476,66,476+50,66+60),this,IDC_MIAN_O);
	btn[38].Create(_T("i"), dwStyle,CRect(425,66,425+50,66+60),this,IDC_MIAN_I);
	btn[39].Create(_T("u"), dwStyle,CRect(374,66,374+50,66+60),this,IDC_MIAN_U);
	btn[40].Create(_T("y"), dwStyle,CRect(323,66,323+50,66+60),this,IDC_MIAN_Y);
	btn[41].Create(_T("t"), dwStyle,CRect(272,66,272+50,66+60),this,IDC_MIAN_T);
	btn[42].Create(_T("r"), dwStyle,CRect(221,66,224+50,66+60),this,IDC_MIAN_R);
	btn[43].Create(_T("e"), dwStyle,CRect(170,66,170+50,66+60),this,IDC_MIAN_E);
	btn[44].Create(_T("w"), dwStyle,CRect(119,66,119+50,66+60),this,IDC_MIAN_W);
	btn[45].Create(_T("Esc"), dwStyle,CRect(4,66,4+63,66+60),this,IDC_MIAN_ESC);
	btn[46].Create(_T("q"), dwStyle,CRect(68,66,68+50,66+60),this,IDC_MIAN_Q);
	btn[47].Create(_T("BackSpace"), dwStyle,CRect(667,4,667+129,4+60),this,IDC_MIAN_BACKSPACE);
	btn[48].Create(_T("="), dwStyle,CRect(616,4,616+50,4+60),this,IDC_MIAN_SYM_3);
	btn[49].Create(_T("-"), dwStyle,CRect(565,4,565+50,4+60),this,IDC_MIAN_SYM_2);
	btn[50].Create(_T("0"), dwStyle,CRect(514,4,514+50,4+60),this,IDC_MIAN_0);
	btn[51].Create(_T("9"), dwStyle,CRect(463,4,463+50,4+60),this,IDC_MIAN_9);
	btn[52].Create(_T("8"), dwStyle,CRect(412,4,412+50,4+60),this,IDC_MIAN_8);
	btn[53].Create(_T("7"), dwStyle,CRect(361,4,361+50,4+60),this,IDC_MIAN_7);
	btn[54].Create(_T("6"), dwStyle,CRect(310,4,310+50,4+60),this,IDC_MIAN_6);
	btn[55].Create(_T("5"), dwStyle,CRect(259,4,259+50,4+60),this,IDC_MIAN_5);
	btn[56].Create(_T("4"), dwStyle,CRect(208,4,208+50,4+60),this,IDC_MIAN_4);
	btn[57].Create(_T("3"), dwStyle,CRect(157,4,157+50,4+60),this,IDC_MIAN_3);
	btn[58].Create(_T("2"), dwStyle,CRect(106,4,106+50,4+60),this,IDC_MIAN_2);
	btn[59].Create(_T("1"), dwStyle,CRect(55,4,55+50,4+60),this,IDC_MIAN_1);
	btn[60].Create(_T("`"), dwStyle,CRect(4,4,4+50,4+60),this,IDC_MIAN_SYM_1);



	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
/////////////////////////////////键值响应///////////////////////////////////
void CKeyBoMain::OnBnClickedMainCaps()
{//打开Caps窗口

	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pLan->ShowWindow(SW_HIDE);
	pWnd->m_pSym->ShowWindow(SW_HIDE);
	pWnd->m_pCaps->ShowWindow(SW_SHOW);

	// TODO: 在此添加控件通知处理程序代码
}

void CKeyBoMain::OnBnClickedMainSym()
{//打开符号Sym窗口
	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pLan->ShowWindow(SW_HIDE);
	pWnd->m_pSym->ShowWindow(SW_SHOW);
	pWnd->m_pCaps->ShowWindow(SW_HIDE);
	
	// TODO: 在此添加控件通知处理程序代码
}
void CKeyBoMain::OnBnClickedMainLan()
{//打开语言Lan窗口
	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pLan->ShowWindow(SW_SHOW);
	pWnd->m_pSym->ShowWindow(SW_HIDE);
	pWnd->m_pCaps->ShowWindow(SW_HIDE);
	// TODO: 在此添加控件通知处理程序代码
}

void CKeyBoMain::OnBnClickedMainP()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_P)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);

}

void CKeyBoMain::OnBnClickedMainY()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_Y)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}

void CKeyBoMain::OnBnClickedMainA()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_A)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}

void CKeyBoMain::OnBnClickedMainN()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_N)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}


void CKeyBoMain::OnBnClickedMainI()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_I)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}

void CKeyBoMain::OnBnClickedMainEnter()
{
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
    pWnd->getEditText();

    pWnd->SendMessage(WM_CLOSE); 
}
