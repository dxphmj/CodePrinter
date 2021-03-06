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
	ON_BN_CLICKED(IDC_MIAN_ENTER, &CKeyBoMain::OnBnClickedMainEnter)
	ON_BN_CLICKED(IDC_MIAN_BACKSPACE, &CKeyBoMain::OnBnClickedMainBackspace)
	ON_BN_CLICKED(IDC_MIAN_LEFT, &CKeyBoMain::OnBnClickedMainLeft)
	ON_BN_CLICKED(IDC_MIAN_RIGHT, &CKeyBoMain::OnBnClickedMainRight)
	ON_BN_CLICKED(IDC_MIAN_DEL, &CKeyBoMain::OnBnClickedMainDel)
	ON_BN_CLICKED(IDC_MIAN_SPACE, &CKeyBoMain::OnBnClickedMainSpace)
	ON_BN_CLICKED(IDC_MIAN_PGDN, &CKeyBoMain::OnBnClickedMainPgDn)
	ON_BN_CLICKED(IDC_MIAN_PGUP, &CKeyBoMain::OnBnClickedMainPgUp)
	ON_BN_CLICKED(IDC_MIAN_NS, &CKeyBoMain::OnBnClickedMainNS)
	ON_BN_CLICKED(IDC_MIAN_ESC, &CKeyBoMain::OnBnClickedMainEsc)

	ON_BN_CLICKED(IDC_MIAN_Q, &CKeyBoMain::OnBnClickedMainQ)
	ON_BN_CLICKED(IDC_MIAN_W, &CKeyBoMain::OnBnClickedMainW)
	ON_BN_CLICKED(IDC_MIAN_E, &CKeyBoMain::OnBnClickedMainE)
	ON_BN_CLICKED(IDC_MIAN_R, &CKeyBoMain::OnBnClickedMainR)
	ON_BN_CLICKED(IDC_MIAN_T, &CKeyBoMain::OnBnClickedMainT)
	ON_BN_CLICKED(IDC_MIAN_Y, &CKeyBoMain::OnBnClickedMainY)
	ON_BN_CLICKED(IDC_MIAN_U, &CKeyBoMain::OnBnClickedMainU)
	ON_BN_CLICKED(IDC_MIAN_I, &CKeyBoMain::OnBnClickedMainI)
	ON_BN_CLICKED(IDC_MIAN_O, &CKeyBoMain::OnBnClickedMainO)
	ON_BN_CLICKED(IDC_MIAN_P, &CKeyBoMain::OnBnClickedMainP)
	ON_BN_CLICKED(IDC_MIAN_A, &CKeyBoMain::OnBnClickedMainA)
	ON_BN_CLICKED(IDC_MIAN_S, &CKeyBoMain::OnBnClickedMainS)
	ON_BN_CLICKED(IDC_MIAN_D, &CKeyBoMain::OnBnClickedMainD)
	ON_BN_CLICKED(IDC_MIAN_F, &CKeyBoMain::OnBnClickedMainF)
	ON_BN_CLICKED(IDC_MIAN_G, &CKeyBoMain::OnBnClickedMainG)
	ON_BN_CLICKED(IDC_MIAN_H, &CKeyBoMain::OnBnClickedMainH)
	ON_BN_CLICKED(IDC_MIAN_J, &CKeyBoMain::OnBnClickedMainJ)
	ON_BN_CLICKED(IDC_MIAN_K, &CKeyBoMain::OnBnClickedMainK)
	ON_BN_CLICKED(IDC_MIAN_L, &CKeyBoMain::OnBnClickedMainL)
	ON_BN_CLICKED(IDC_MIAN_Z, &CKeyBoMain::OnBnClickedMainZ)
	ON_BN_CLICKED(IDC_MIAN_X, &CKeyBoMain::OnBnClickedMainX)
	ON_BN_CLICKED(IDC_MIAN_C, &CKeyBoMain::OnBnClickedMainC)
	ON_BN_CLICKED(IDC_MIAN_V, &CKeyBoMain::OnBnClickedMainV)
	ON_BN_CLICKED(IDC_MIAN_B, &CKeyBoMain::OnBnClickedMainB)
	ON_BN_CLICKED(IDC_MIAN_N, &CKeyBoMain::OnBnClickedMainN)
	ON_BN_CLICKED(IDC_MIAN_M, &CKeyBoMain::OnBnClickedMainM)

	ON_BN_CLICKED(IDC_MIAN_SYM_1, &CKeyBoMain::OnBnClickedMain_SYM_1)
	ON_BN_CLICKED(IDC_MIAN_SYM_2, &CKeyBoMain::OnBnClickedMain_SYM_2)
	ON_BN_CLICKED(IDC_MIAN_SYM_3, &CKeyBoMain::OnBnClickedMain_SYM_3)
	ON_BN_CLICKED(IDC_MIAN_SYM_4, &CKeyBoMain::OnBnClickedMain_SYM_4)
	ON_BN_CLICKED(IDC_MIAN_SYM_5, &CKeyBoMain::OnBnClickedMain_SYM_5)
	ON_BN_CLICKED(IDC_MIAN_SYM_6, &CKeyBoMain::OnBnClickedMain_SYM_6)
	ON_BN_CLICKED(IDC_MIAN_SYM_7, &CKeyBoMain::OnBnClickedMain_SYM_7)
	ON_BN_CLICKED(IDC_MIAN_SYM_8, &CKeyBoMain::OnBnClickedMain_SYM_8)
	ON_BN_CLICKED(IDC_MIAN_SYM_9, &CKeyBoMain::OnBnClickedMain_SYM_9)
	ON_BN_CLICKED(IDC_MIAN_SYM_10, &CKeyBoMain::OnBnClickedMain_SYM_10)
	ON_BN_CLICKED(IDC_MIAN_SYM_11, &CKeyBoMain::OnBnClickedMain_SYM_11)

	ON_BN_CLICKED(IDC_MIAN_1, &CKeyBoMain::OnBnClickedMain_1)
	ON_BN_CLICKED(IDC_MIAN_2, &CKeyBoMain::OnBnClickedMain_2)
	ON_BN_CLICKED(IDC_MIAN_3, &CKeyBoMain::OnBnClickedMain_3)
	ON_BN_CLICKED(IDC_MIAN_4, &CKeyBoMain::OnBnClickedMain_4)
	ON_BN_CLICKED(IDC_MIAN_5, &CKeyBoMain::OnBnClickedMain_5)
	ON_BN_CLICKED(IDC_MIAN_6, &CKeyBoMain::OnBnClickedMain_6)
	ON_BN_CLICKED(IDC_MIAN_7, &CKeyBoMain::OnBnClickedMain_7)
	ON_BN_CLICKED(IDC_MIAN_8, &CKeyBoMain::OnBnClickedMain_8)
	ON_BN_CLICKED(IDC_MIAN_9, &CKeyBoMain::OnBnClickedMain_9)
	ON_BN_CLICKED(IDC_MIAN_0, &CKeyBoMain::OnBnClickedMain_0)
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
	//大小写状态
	Upper = false;//小写
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


/////////////////////设置字体/////////////////////////////////////////////////////
	CFont *pFont = new CFont; //创建一个指向新字体类型的指针pFont
	pFont->CreatePointFont(180, _T("黑体"));
	GetDlgItem(IDC_MIAN_PGDN)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_PGUP)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_SYM_11)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_SYM_10)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_SYM_9)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_M)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_N)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_B)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_V)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_C)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_X)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_SYMBOL)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_Z)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_RIGHT)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_LEFT)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_NS)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_LAN)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_SPACE)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_ENTER)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_SYM_8)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_SYM_7)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_L)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_K)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_J)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_H)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_G)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_F)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_D)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_S)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_CAPS)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_A)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_DEL)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_SYM_6)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_SYM_5)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_SYM_4)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_P)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_O)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_I)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_U)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_Y)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_T)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_R)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_E)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_W)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_ESC)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_Q)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_BACKSPACE)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_SYM_3)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_SYM_2)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_0)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_9)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_8)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_7)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_6)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_5)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_4)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_3)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_2)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_1)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_SYM_1)->SetFont(pFont);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
/////////////////////////////////键值响应///////////////////////////////////
void CKeyBoMain::OnBnClickedMainCaps()
{//切换大小写
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	btnTextUpper();
	// TODO: 在此添加控件通知处理程序代码
}

void CKeyBoMain::OnBnClickedMainSym()
{//打开符号Sym窗口
	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pLan->ShowWindow(SW_HIDE);
	pWnd->m_pSym->ShowWindow(SW_SHOW);
	pWnd->m_pCaps->ShowWindow(SW_HIDE);
	pWnd->btnHide();
	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
	
	pWnd->LantypeReverse = pWnd->LanType;
	pWnd->LanType = 23;//切换为符号输入
	
	// TODO: 在此添加控件通知处理程序代码
}
void CKeyBoMain::OnBnClickedMainLan()
{//打开语言Lan窗口
	this->ShowWindow(SW_HIDE);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_pLan->ShowWindow(SW_SHOW);
	pWnd->m_pSym->ShowWindow(SW_HIDE);
	pWnd->m_pCaps->ShowWindow(SW_HIDE);
	pWnd->btnHide();
	pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
	// TODO: 在此添加控件通知处理程序代码
}



void CKeyBoMain::OnBnClickedMainEnter()
{
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
    pWnd->getEditText();

    //pWnd->SendMessage(WM_CLOSE);
	pWnd->EndDialog(0);
	//pWnd->DestroyWindow();
}

void CKeyBoMain::OnBnClickedMainBackspace()
{
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	switch (pWnd->LanType)
	{
	

	case 3:  //Chinese_others
	case 5:  //Arabic
	case 6:	 //Farsi
	case 7:  //English
	case 8:	 //Czech
	case 9:  //Dutch
	case 10: //German
	case 11: //Finnish
	case 12: //Hindi
	case 13: //Hungarian
	case 14: //Italian
	case 15: //Portuguese
	case 16: //Russian
	case 17: //Spanish
	case 18: //Swedish
	case 19: //Thai
	case 20: //Turkish
	case 21: //Japanese_others
	case 22: //Korean_others
		{	
			int nPosStart;
			int nPosEnd  = 0; 
			pWnd->m_edit_input.GetSel(nPosStart, nPosEnd); 
			pWnd->m_edit_input.SetSel(nPosStart-1, nPosStart);                            
			pWnd->m_edit_input.ReplaceSel(_T(""));
			pWnd->m_edit_input.SetFocus();
			break;
		}
	case 0:  //chinese
	case 1:  //Japanese
	case 2:  //Korean
		{
			int nPosStart;
			int nPosEnd  = 0; 
			pWnd->m_zrh_edit.GetSel(nPosStart, nPosEnd); 
			pWnd->m_zrh_edit.SetSel(nPosStart-1, nPosStart);                            
			pWnd->m_zrh_edit.ReplaceSel(_T(""));
			pWnd->m_edit_input.SetFocus();
			break;
		}
	}
}

void CKeyBoMain::OnBnClickedMainLeft()
{
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	switch (pWnd->LanType)
	{

	case 3:  //Chinese_others
	case 5:  //Arabic
	case 6:	 //Farsi
	case 7:  //English
	case 8:	 //Czech
	case 9:  //Dutch
	case 10: //German
	case 11: //Finnish
	case 12: //Hindi
	case 13: //Hungarian
	case 14: //Italian
	case 15: //Portuguese
	case 16: //Russian
	case 17: //Spanish
	case 18: //Swedish
	case 19: //Thai
	case 20: //Turkish
	case 21: //Japanese_others
	case 22: //Korean_others
		{	
			int nPosStart;
			int nPosEnd  = 0; 
			pWnd->m_edit_input.GetSel(nPosStart, nPosEnd); 
			pWnd->m_edit_input.SetSel(nPosStart-1, nPosStart-1);
			pWnd->m_edit_input.SetFocus();
			break;
		}
	case 0:  //chinese
	case 1:  //Japanese
	case 2:  //Korean
		{
			int nPosStart;
			int nPosEnd  = 0; 
			pWnd->m_zrh_edit.GetSel(nPosStart, nPosEnd); 
			pWnd->m_zrh_edit.SetSel(nPosStart-1, nPosStart-1);
			pWnd->m_zrh_edit.SetFocus();
			break;
		}
	}
}

void CKeyBoMain::OnBnClickedMainRight()
{
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	switch (pWnd->LanType)
	{

	case 3:  //Chinese_others
	case 5:  //Arabic
	case 6:	 //Farsi
	case 7:  //English
	case 8:	 //Czech
	case 9:  //Dutch
	case 10: //German
	case 11: //Finnish
	case 12: //Hindi
	case 13: //Hungarian
	case 14: //Italian
	case 15: //Portuguese
	case 16: //Russian
	case 17: //Spanish
	case 18: //Swedish
	case 19: //Thai
	case 20: //Turkish
	case 21: //Japanese_others
	case 22: //Korean_others
		{	
			int nPosStart;
			int nPosEnd  = 0; 
			pWnd->m_edit_input.GetSel(nPosStart, nPosEnd); 
			pWnd->m_edit_input.SetSel(nPosStart+1, nPosStart+1); 
			pWnd->m_edit_input.SetFocus();
			break;
		}
	case 0:  //chinese
	case 1:  //Japanese
	case 2:  //Korean
		{
			int nPosStart;
			int nPosEnd  = 0; 
			pWnd->m_zrh_edit.GetSel(nPosStart, nPosEnd); 
			pWnd->m_edit_input.SetSel(nPosStart+1, nPosStart+1); 
			pWnd->m_zrh_edit.SetFocus();
			break;
		}
	}
}

void CKeyBoMain::OnBnClickedMainDel()
{
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	switch (pWnd->LanType)
	{

	case 3:  //Chinese_others
	case 5:  //Arabic
	case 6:	 //Farsi
	case 7:  //English
	case 8:	 //Czech
	case 9:  //Dutch
	case 10: //German
	case 11: //Finnish
	case 12: //Hindi
	case 13: //Hungarian
	case 14: //Italian
	case 15: //Portuguese
	case 16: //Russian
	case 17: //Spanish
	case 18: //Swedish
	case 19: //Thai
	case 20: //Turkish
	case 21: //Japanese_others
	case 22: //Korean_others
		{	
			int nPosStart;
			int nPosEnd  = 0; 
			pWnd->m_edit_input.GetSel(nPosStart, nPosEnd); 
			pWnd->m_edit_input.SetSel(nPosStart, nPosStart+1);                            
			pWnd->m_edit_input.ReplaceSel(_T(""));
			pWnd->m_edit_input.SetFocus();
			break;
		}
	case 0:  //chinese
	case 1:  //Japanese
	case 2:  //Korean
		{
			int nPosStart;
			int nPosEnd  = 0; 
			pWnd->m_zrh_edit.GetSel(nPosStart, nPosEnd); 
			pWnd->m_zrh_edit.SetSel(nPosStart, nPosStart+1);                            
			pWnd->m_zrh_edit.ReplaceSel(_T(""));
			pWnd->m_edit_input.SetFocus();
			break;
		}
	}
}

void CKeyBoMain::OnBnClickedMainSpace()
{
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	switch (pWnd->LanType)
	{

	case 3:  //Chinese_others
	case 5:  //Arabic
	case 6:	 //Farsi
	case 7:  //English
	case 8:	 //Czech
	case 9:  //Dutch
	case 10: //German
	case 11: //Finnish
	case 12: //Hindi
	case 13: //Hungarian
	case 14: //Italian
	case 15: //Portuguese
	case 16: //Russian
	case 17: //Spanish
	case 18: //Swedish
	case 19: //Thai
	case 20: //Turkish
	case 21: //Japanese_others
	case 22: //Korean_others
		{	
			int nPosStart;
			int nPosEnd  = 0; 
			pWnd->m_edit_input.GetSel(nPosStart, nPosEnd); 
			pWnd->m_edit_input.SetSel(nPosStart, nPosStart);                            
			pWnd->m_edit_input.ReplaceSel(_T(" "));
			break;
		}
	case 0:  //chinese
	case 1:  //Japanese
	case 2:  //Korean
		{
			int nPosStart;
			int nPosEnd  = 0; 
			pWnd->m_zrh_edit.GetSel(nPosStart, nPosEnd); 
			pWnd->m_zrh_edit.SetSel(nPosStart, nPosStart);                            
			pWnd->m_zrh_edit.ReplaceSel(_T(" "));
			break;
		}
	}
}

void CKeyBoMain::OnBnClickedMainPgDn()
{
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();	
	if ( pWnd->LanType == 5 || pWnd->LanType == 6 )//阿拉伯语,波斯语
	{
		CString strCur;
		GetDlgItem(IDC_MIAN_SYM_1)->GetWindowText(strCur);
		strCur = strCur + _T("");
		if ( strCur.Compare(_T("؟")) == 0 )
		{
			LanArabic2();
		}
		else if ( strCur.Compare(_T("ﺎ")) == 0 )
		{
			LanArabic3();
		}
		else if ( strCur.Compare(_T("ﺳ")) == 0 )
		{
			LanArabic4();
		}
		else
		{
			return;
		}
	}

}

void CKeyBoMain::OnBnClickedMainPgUp()
{
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();	
	if ( pWnd->LanType == 5 ||pWnd->LanType == 6 )//阿拉伯语,波斯语
	{
		CString strCur;
		GetDlgItem(IDC_MIAN_SYM_1)->GetWindowText(strCur);
		if ( strCur.Compare(_T("ﻢ")) == 0 )
		{
			LanArabic3();
		}
		else if ( strCur.Compare(_T("ﺳ")) == 0 )
		{
			LanArabic2();
		}
		else if ( strCur.Compare(_T("ﺎ")) == 0 )
		{
			LanArabic1();
		}
		else
		{
			return;
		}
	}
}


void CKeyBoMain::OnBnClickedMainNS()
{
	Upper = false;
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	if ( pWnd->LanType != 7)//不是英语，切换为英语
	{
		btnTextSel(7);
		pWnd->LanTurn = pWnd->LanType;
		pWnd->LanType = 7;
	} 
	else                    //是英语时，切换为其他语言
	{
		btnTextSel(pWnd->LanTurn);
		pWnd->LanType = pWnd->LanTurn;
		pWnd->LanTurn =7;
	}
}



void CKeyBoMain::OnBnClickedMainEsc()
{
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->m_strRet = pWnd->m_strOld;
	//pWnd->getEditText();
	pWnd->EndDialog(0);
}

void CKeyBoMain::btnTextSel(int inputLanguage)
{
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	switch (inputLanguage)
	{

	case 0:  //chinese
	case 1:  //Japanese
	case 3:  //Chinese_others
	case 21: //Japanese_others
		{
			LanEnglish();
			pWnd->btnShow();
			pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
	case 2:  //Korean
	case 22: //Korean_others
		{
			LanKorean();
			pWnd->btnShow();
			pWnd->m_zrh_edit.ShowWindow(SW_SHOW);
			break;
		}
	case 5:  //Arabic
		{
			LanArabic1();
			pWnd->btnHide();
			pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 6:  //Farsi
		{
			LanArabic1();
			pWnd->btnHide();
			pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 7:  //English
		{
			LanEnglish();
			pWnd->btnHide();
			pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 8:  //Czech
		{
			LanCzech();
			pWnd->btnHide();
			pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 9:  //Dutch
		{
			LanDutch();
			pWnd->btnHide();
			pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 10: //German
		{
			LanGerman();
			pWnd->btnHide();
			pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 11:  //Finnish
		{
			LanFinnish();
			pWnd->btnHide();
			pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 12:  //Hindi
		{
			LanHindi();
			pWnd->btnHide();
			pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 13:  //Hungarian
		{
			LanHungarian();
			pWnd->btnHide();
			pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 14:  //Italian
		{
			LanItalian();
			pWnd->btnHide();
			pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 15:  //Portuguese
		{
			LanPortuguese();
			pWnd->btnHide();
			pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 16:  //Russian
		{
			LanRussian();
			pWnd->btnHide();
			pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 17:  //Spanish
		{
			LanSpanish();
			pWnd->btnHide();
			pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 18:  //Swedish
		{
			LanSwedish();
			pWnd->btnHide();
			pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 19:  //Thai
		{
			LanThai();
			pWnd->btnHide();
			pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}
	case 20:  //Turkish
		{
			LanTurkish();
			pWnd->btnHide();
			pWnd->m_zrh_edit.ShowWindow(SW_HIDE);
			break;
		}

	}
}

void CKeyBoMain::btnTextUpper()
{
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	if ( Upper == false )
	{
		switch (pWnd->LanType)
		{

		case 0:  //chinese
		case 7:  //English
		case 1:  //Japanese
		case 3: //Chinese_others
		case 21://Japanese_others
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("?"));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(">"));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("<"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("\""));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T(":"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("|"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("}"));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("{"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Y"));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("+"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("_"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("0"));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("9"));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("8"));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("7"));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("6"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("5"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("4"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("3"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("2"));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("1"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("~"));
				break;
			}
		case 2:  //Korean
		case 22: //Korean_others
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("?"));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(">"));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("<"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T(""));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("하"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("파"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("타"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("카"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("차"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("자"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("\""));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T(":"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("아"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("사"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("바"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("마"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("라"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("다"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("나"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("가"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("ㅁ"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("|"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("}"));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("{"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("ㅖ"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("ㅒ"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T(""));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T(""));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T(""));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("ㅆ"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("ㄲ"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("ㄸ"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("ㅉ"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("ㅃ"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("+"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("_"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T(")"));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("("));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("*"));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("^"));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("%"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("$"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("#"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("@"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("!"));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("~"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("/"));
				break;
			}
		case 5:  //Arabic
			{
				break;
			}
		case 6:  //Farsi
			{
				break;
			}
		case 8:  //Czech
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("?"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Y"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("!"));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ů"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("'"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("("));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Ú"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Z"));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("ˇ"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("%"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("É"));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("Í"));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("Á"));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("Ý"));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("Ž"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("Ř"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("Č"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("Š"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("Ě"));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("1"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("°"));
				break;
			}
		case 9:  //Dutch
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("="));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("`"));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("±"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T(">"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("|"));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("^"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Z"));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("~"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("'"));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("_"));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("$"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("#"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("§"));
				break;
			}
		case 10: //German
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("-"));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Y"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("Ä"));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ö"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("'"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("*"));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Ú"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Z"));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("+"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("="));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("/"));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&&"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("$"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("§"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("^"));
				break;
			}
		case 11:  //Finnish
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("Ä"));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ö"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("'"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("´"));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Å"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Z"));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("`"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("="));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("/"));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("¤"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("#"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("½"));
				break;
			}
		case 12:  //Hindi
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("य़"));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("।"));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("ष"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("श"));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("ळ"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("ऴ"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("ऩ"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("ण"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("ँ"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("ऎ"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("ठ"));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("छ"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("थ"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("ख"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("ऱ"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("फ"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("उ"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("इ"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("अ"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("ए"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("ओ"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("ऑ"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("ञ"));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("ढ"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("झ"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("ध"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("घ"));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("ङ"));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("भ"));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("ऊ"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("ई"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("आ"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("ऐ"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("औ"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("ऋ"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("ः"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T(")"));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("("));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("श्र"));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("क्ष"));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("त्र"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("ज्ञ"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("र्"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("्र"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("ॅ"));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("ऍ"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("ऒ"));
				break;
			}
		case 13:  //Hungarian
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("?"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Y"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("Á"));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("É"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("Ű"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("Ú"));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Ő"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Z"));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("Ó"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("Ü"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("Ö"));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("="));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("/"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("!"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("+"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("'"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("§"));
				break;
			}
		case 14:  //Italian
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("°"));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("ç"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("§"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("*"));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("é"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Y"));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("^"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("="));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("/"));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&&"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("$"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("£"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("|"));
				break;
			}
		case 15:  //Portuguese
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("?"));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(">"));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("<"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("^"));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ç"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("}"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("{"));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("`"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Y"));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("+"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("——"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("）"));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("（"));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("*"));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("&&"));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("^"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("$"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("#"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("@"));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("\""));
				break;
			}
		case 16:  //Russian
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("."));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("Ю"));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("Б"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("Ь"));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("Т"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("И"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("М"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("С"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("Ч"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Я"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("Э"));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ж"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("Д"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("Л"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("О"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("Р"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("П"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("А"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("В"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("Ы"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("Ф"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("\\"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("Ъ"));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Х"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("З"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("Щ"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("Ш"));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("Г"));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Н"));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("Е"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("К"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("У"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("Ц"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Й"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("+"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("_"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("）"));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("("));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("*"));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("?"));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T(":"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T(";"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("№"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("Ё"));
				break;
			}
		case 17:  //Spanish
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("¨"));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ñ"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("Ç"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("*"));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("^"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Y"));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("¿"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("="));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("/"));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&&"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("$"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("·"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("ª"));
				break;
			}
		case 18:  //Swedish
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("_"));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(":"));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(";"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("M"));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("N"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("B"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("V"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("C"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("X"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("Z"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("Ä"));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Ö"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("K"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("J"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("H"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("G"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("F"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("D"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("S"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("A"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("*"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("^"));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Å"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("O"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("I"));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("U"));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("Y"));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("T"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("R"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("E"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("W"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("Q"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("`"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("="));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("/"));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&&"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("¤"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("#"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("½"));
				break;
			}
		case 19:  //Thai
			{

			}
		case 20:  //Turkish
			{
				GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T(","));
				GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("."));
				GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("B"));
				GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("S"));
				GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("Z"));
				GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("Ç"));
				GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("C"));
				GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("V"));
				GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("Ö"));
				GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("J"));
				GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("Ş"));
				GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("Y"));
				GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("L"));
				GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("M"));
				GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("K"));
				GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("T"));
				GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("Ü"));
				GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("A"));
				GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("E"));
				GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("İ"));
				GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("U"));
				GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("X"));
				GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("W"));
				GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("Q"));
				GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("P"));
				GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("H"));
				GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("N"));
				GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("R"));
				GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("D"));
				GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("O"));
				GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("I"));
				GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("Ğ"));
				GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("G"));
				GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("F"));
				GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("_"));
				GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("?"));
				GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("="));
				GetDlgItem(IDC_MIAN_9)->SetWindowText(_T(")"));
				GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("("));
				GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("'"));
				GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("&&"));
				GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("%"));
				GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("$"));
				GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("^"));
				GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("\""));
				GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("!"));
				GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("*"));
			}

		}
		Upper = true;
	}
	else
	{
		btnTextSel(pWnd->LanType);
		Upper = false;
    }
}



//////////////////////////////////////////////////////////////////////////
void CKeyBoMain::OnBnClickedMainQ()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_Q)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}

void CKeyBoMain::OnBnClickedMainW()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_W)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}

void CKeyBoMain::OnBnClickedMainE()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_E)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}

void CKeyBoMain::OnBnClickedMainR()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_R)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}

void CKeyBoMain::OnBnClickedMainT()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_T)->GetWindowText(tempstr);
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

void CKeyBoMain::OnBnClickedMainU()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_U)->GetWindowText(tempstr);
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

void CKeyBoMain::OnBnClickedMainO()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_O)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}

void CKeyBoMain::OnBnClickedMainP()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_P)->GetWindowText(tempstr);
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

void CKeyBoMain::OnBnClickedMainS()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_S)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}

void CKeyBoMain::OnBnClickedMainD()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_D)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}

void CKeyBoMain::OnBnClickedMainF()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_F)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}

void CKeyBoMain::OnBnClickedMainG()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_G)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}

void CKeyBoMain::OnBnClickedMainH()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_H)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}

void CKeyBoMain::OnBnClickedMainJ()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_J)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}

void CKeyBoMain::OnBnClickedMainK()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_K)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}

void CKeyBoMain::OnBnClickedMainL()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_L)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}

void CKeyBoMain::OnBnClickedMainZ()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_Z)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}

void CKeyBoMain::OnBnClickedMainX()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_X)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}

void CKeyBoMain::OnBnClickedMainC()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_C)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}

void CKeyBoMain::OnBnClickedMainV()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_V)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}

void CKeyBoMain::OnBnClickedMainB()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_B)->GetWindowText(tempstr);
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

void CKeyBoMain::OnBnClickedMainM()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_M)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
//////////////////////////////////////////////////////////////////////////
void CKeyBoMain::OnBnClickedMain_SYM_1()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_SYM_1)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoMain::OnBnClickedMain_SYM_2()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_SYM_2)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoMain::OnBnClickedMain_SYM_3()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_SYM_3)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoMain::OnBnClickedMain_SYM_4()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_SYM_4)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoMain::OnBnClickedMain_SYM_5()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_SYM_5)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoMain::OnBnClickedMain_SYM_6()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_SYM_6)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoMain::OnBnClickedMain_SYM_7()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_SYM_7)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoMain::OnBnClickedMain_SYM_8()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_SYM_8)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoMain::OnBnClickedMain_SYM_9()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_SYM_9)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoMain::OnBnClickedMain_SYM_10()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_SYM_10)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoMain::OnBnClickedMain_SYM_11()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_SYM_11)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
//////////////////////////////////////////////////////////////////////////
void CKeyBoMain::OnBnClickedMain_1()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_1)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoMain::OnBnClickedMain_2()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_2)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoMain::OnBnClickedMain_3()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_3)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoMain::OnBnClickedMain_4()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_4)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoMain::OnBnClickedMain_5()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_5)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoMain::OnBnClickedMain_6()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_6)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoMain::OnBnClickedMain_7()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_7)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoMain::OnBnClickedMain_8()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_8)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoMain::OnBnClickedMain_9()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_9)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
void CKeyBoMain::OnBnClickedMain_0()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_0)->GetWindowText(tempstr);
	CKeyBoardDlg* pWnd = (CKeyBoardDlg*)this->GetParent();
	pWnd->setEditText(tempstr);
}
//////////////////////////////////////////////////////////////////////////
void CKeyBoMain::LanArabic1()
{
	GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("ظ"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("ز"));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("و"));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("ة"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("ى"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("لا"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("ر"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("ؤ"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("ء"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("ئ"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("ط"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("ك"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("م"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("ن"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("ت"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("ا"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("ل"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("ب"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("ي"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("س"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("ش"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("\\"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("د"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("ج"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("ح"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("خ"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("ه"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("ع"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("غ"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("ف"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("ق"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("ث"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("ص"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("ض"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("="));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("-"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("۰"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("۹"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("۸"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("۷"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("۶"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("۵"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("۴"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("۳"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("۲"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("۱"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("ذ"));
}

void CKeyBoMain::LanArabic2()
{
	GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("ﺲ"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("ﺱ"));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("ﺰ"));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("ﺯ"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("ﺮ"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("ﺭ"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("ﺬ"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("ﺫ"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("ﺪ"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("ﺩ"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("ﺨ"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("ﺧ"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("ﺦ"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("ﺥ"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("ﺤ"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("ﺣ"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("ﺢ"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("ﺡ"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("ﺠ"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("ﺟ"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("ﺞ"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("ﺝ"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("ﺜ"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("ﺛ"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("ﺚ"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("ﺙ"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("ﺘ"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("ﺗ"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("ﺖ"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("ﺕ"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("ﺔ"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("ﺓ"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("ﺒ"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("ﺑ"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("ﺐ"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("ﺏ"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("۰"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("۹"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("۸"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("۷"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("۶"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("۵"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("۴"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("۳"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("۲"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("۱"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("ﺎ"));
}

void CKeyBoMain::LanArabic3()
{
	GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("ﻡ"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("ﻠ"));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("ﻟ"));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("ﻞ"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("ﻝ"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("ﻜ"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("ﻛ"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("ﻚ"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("ﻙ"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("ﻘ"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("ﻗ"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("ﻖ"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("ﻕ"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("ﻔ"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("ﻓ"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("ﻒ"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("ﻑ"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("ﻐ"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("ﻏ"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("ﻎ"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("ﻍ"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("ﻌ"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("ﻋ"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("ﻊ"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("ﻉ"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("ﻈ"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("ﻇ"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("ﻆ"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("ﻅ"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("ﻄ"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("ﻃ"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("ﻂ"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("ﻁ"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("ﻀ"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("ﺿ"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("ﺾ"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("ﺽ"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("ﺼ"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("ﺻ"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("ﺺ"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("ﺹ"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("ﺸ"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("ﺷ"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("ﺶ"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("ﺵ"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("ﺴ"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("ﺳ"));
}

void CKeyBoMain::LanArabic4()
{
	GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T(""));

	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("ﻼ"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("ﻻ"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("ﻺ"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("ﻹ"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("ﻸ"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("ﻷ"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("ﻶ"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("ﻵ"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("ﻴ"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("ﻳ"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("ﻲ"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("ﻱ"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("ﻰ"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("ﻯ"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("ﻮ"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("ﻭ"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("ﻬ"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("ﻫ"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("ﻪ"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("ﻩ"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("ﻨ"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("ﻧ"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("ﻦ"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("ﻥ"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("ﻤ"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("ﻣ"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("ﻢ"));
}

void CKeyBoMain::LanEnglish()
{
	GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("/"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("."));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(","));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("m"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("n"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("b"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("v"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("c"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("x"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("z"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("'"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T(";"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("l"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("k"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("j"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("h"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("g"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("f"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("d"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("s"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("a"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("\\"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("]"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("["));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("p"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("o"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("i"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("u"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("y"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("t"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("r"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("e"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("w"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("q"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("="));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("-"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("0"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("9"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("8"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("7"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("6"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("5"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("4"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("3"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("2"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("1"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("`"));
}

void CKeyBoMain::LanKorean()
{
	GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("/"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("."));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(","));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("ㅡ"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("ㅜ"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("ㅠ"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("ㅍ"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("ㅊ"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("ㅌ"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("ㅋ"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("'"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T(";"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("ㅣ"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("ㅏ"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("ㅓ"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("ㅗ"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("ㅎ"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("ㄹ"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("ㅇ"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("ㄴ"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("ㅁ"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("\\"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("]"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("["));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("ㅔ"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("ㅐ"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("ㅑ"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("ㅕ"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("ㅛ"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("ㅅ"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("ㄱ"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("ㄷ"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("ㅈ"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("ㅂ"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("="));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("-"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("0"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("9"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("8"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("7"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("6"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("5"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("4"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("3"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("2"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("1"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("`"));
}

void CKeyBoMain::LanGerman()
{
	GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("-"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("."));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(","));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("m"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("n"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("b"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("v"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("c"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("x"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("y"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("ä"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("ö"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("l"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("k"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("j"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("h"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("g"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("f"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("d"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("s"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("a"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("#"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("+"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("ü"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("p"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("o"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("i"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("u"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("z"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("t"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("r"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("e"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("w"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("q"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("´"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("ß"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("0"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("9"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("8"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("7"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("6"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("5"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("4"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("3"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("2"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("1"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("^"));
}

void CKeyBoMain::LanCzech()
{
	GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("/"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("."));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(","));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("m"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("n"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("b"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("v"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("c"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("x"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("y"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("§"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("ů"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("l"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("k"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("j"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("h"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("g"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("f"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("d"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("s"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("a"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("¨"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T(")"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("ú"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("p"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("o"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("i"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("u"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("z"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("t"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("r"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("e"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("w"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("q"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("´"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("="));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("é"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("í"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("á"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("ý"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("ž"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("ř"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("č"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("š"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("ě"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("+"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T(";"));
}

void CKeyBoMain::LanDutch()
{
	GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("-"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("."));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(","));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("m"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("n"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("b"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("v"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("c"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("x"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("z"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("´"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("+"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("l"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("k"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("j"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("h"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("g"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("f"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("d"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("s"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("a"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("<"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("*"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("¨"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("p"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("o"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("i"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("u"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("y"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("t"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("r"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("e"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("w"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("q"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("°"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("/"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("0"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("9"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("8"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("7"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("6"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("5"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("4"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("3"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("2"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("1"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("@"));
}

void CKeyBoMain::LanFinnish()
{
	GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("-"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("."));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(","));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("m"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("n"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("b"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("v"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("c"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("x"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("z"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("ä"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("ö"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("l"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("k"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("j"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("h"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("g"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("f"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("d"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("s"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("a"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("'"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("¨"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("å"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("p"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("o"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("i"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("u"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("y"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("t"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("r"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("e"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("w"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("q"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("´"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("+"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("0"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("9"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("8"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("7"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("6"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("5"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("4"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("3"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("2"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("1"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("§"));
}

void CKeyBoMain::LanHindi()
{
	GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("य"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("."));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(","));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("स"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("ल"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("व"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("न"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("म"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("ं"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("ॆ"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("ट"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("च"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("त"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("क"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("र"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("प"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("ु"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("ि"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("्"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("े"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("ो"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("ॉ"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("़"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("ड"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("ज"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("द"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("ग"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("ह"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("ब"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("ू"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("ी"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("ा"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("ै"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("ौ"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("ृ"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("-"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("0"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("9"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("8"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("7"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("6"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("5"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("4"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("3"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("2"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("1"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("ॊ"));
}

void CKeyBoMain::LanHungarian()
{
	GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("-"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("."));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(","));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("m"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("n"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("b"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("v"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("c"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("x"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("y"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("á"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("é"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("l"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("k"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("j"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("h"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("g"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("f"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("d"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("s"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("a"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("ű"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("ú"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("ő"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("p"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("o"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("i"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("u"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("z"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("t"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("r"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("e"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("w"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("q"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("ó"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("ü"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("ö"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("9"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("8"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("7"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("6"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("5"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("4"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("3"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("2"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("1"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("0"));
}

void CKeyBoMain::LanItalian()
{
	GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("-"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("."));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(","));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("m"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("n"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("b"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("v"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("c"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("x"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("z"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("à"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("ò"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("l"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("k"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("j"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("h"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("g"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("f"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("d"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("s"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("a"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("ù"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("+"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("è"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("p"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("o"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("i"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("u"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("y"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("t"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("r"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("e"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("w"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("q"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("ì"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("'"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("0"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("9"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("8"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("7"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("6"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("5"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("4"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("3"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("2"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("1"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("\\"));
}

void CKeyBoMain::LanPortuguese()
{
	GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("/"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("."));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(","));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("m"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("n"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("b"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("v"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("c"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("x"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("z"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("~"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("ç"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("l"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("k"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("j"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("h"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("g"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("f"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("d"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("s"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("a"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("]"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("["));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("´"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("p"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("o"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("i"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("u"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("y"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("t"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("r"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("e"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("w"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("q"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("="));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("-"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("0"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("9"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("8"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("7"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("6"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("5"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("4"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("3"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("2"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("1"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("·"));
}

void CKeyBoMain::LanRussian()
{
	GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("."));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("ю"));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("б"));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("ь"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("т"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("и"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("м"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("с"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("ч"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("я"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("э"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("ж"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("д"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("л"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("о"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("р"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("п"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("а"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("в"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("ы"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("ф"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("\\"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("ъ"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("х"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("з"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("щ"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("ш"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("г"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("н"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("е"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("к"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("у"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("ц"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("й"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("="));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("-"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("0"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("9"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("8"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("7"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("6"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("5"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("4"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("3"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("2"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("1"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("ё"));
}

void CKeyBoMain::LanSpanish()
{
	GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("-"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("."));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(","));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("m"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("n"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("b"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("v"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("c"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("x"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("z"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("'"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("ñ"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("l"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("k"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("j"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("h"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("g"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("f"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("d"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("s"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("a"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("ç"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("+"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("`"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("p"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("o"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("i"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("u"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("y"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("t"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("r"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("e"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("w"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("q"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("¡"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("'"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("0"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("9"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("8"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("7"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("6"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("5"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("4"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("3"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("2"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("1"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("º"));
}

void CKeyBoMain::LanSwedish()
{
	GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T("-"));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("."));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T(","));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("m"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("n"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("b"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("v"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("c"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("x"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("z"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("ä"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("ö"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("l"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("k"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("j"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("h"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("g"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("f"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("d"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("s"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("a"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("'"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("¨"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("å"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("p"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("o"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("i"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("u"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("y"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("t"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("r"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("e"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("w"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("q"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("´"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("+"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("0"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("9"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("8"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("7"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("6"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("5"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("4"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("3"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("2"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("1"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("§"));
}

void CKeyBoMain::LanThai()
{

}

void CKeyBoMain::LanTurkish()
{
	GetDlgItem(IDC_MIAN_SYM_11)->SetWindowText(_T(","));
	GetDlgItem(IDC_MIAN_SYM_10)->SetWindowText(_T("."));
	GetDlgItem(IDC_MIAN_SYM_9)->SetWindowText(_T("b"));
	GetDlgItem(IDC_MIAN_M)->SetWindowText(_T("s"));
	GetDlgItem(IDC_MIAN_N)->SetWindowText(_T("z"));
	GetDlgItem(IDC_MIAN_B)->SetWindowText(_T("ç"));
	GetDlgItem(IDC_MIAN_V)->SetWindowText(_T("c"));
	GetDlgItem(IDC_MIAN_C)->SetWindowText(_T("v"));
	GetDlgItem(IDC_MIAN_X)->SetWindowText(_T("ö"));
	GetDlgItem(IDC_MIAN_Z)->SetWindowText(_T("j"));
	GetDlgItem(IDC_MIAN_SYM_8)->SetWindowText(_T("ş"));
	GetDlgItem(IDC_MIAN_SYM_7)->SetWindowText(_T("y"));
	GetDlgItem(IDC_MIAN_L)->SetWindowText(_T("l"));
	GetDlgItem(IDC_MIAN_K)->SetWindowText(_T("m"));
	GetDlgItem(IDC_MIAN_J)->SetWindowText(_T("k"));
	GetDlgItem(IDC_MIAN_H)->SetWindowText(_T("t"));
	GetDlgItem(IDC_MIAN_G)->SetWindowText(_T("ü"));
	GetDlgItem(IDC_MIAN_F)->SetWindowText(_T("a"));
	GetDlgItem(IDC_MIAN_D)->SetWindowText(_T("e"));
	GetDlgItem(IDC_MIAN_S)->SetWindowText(_T("i"));
	GetDlgItem(IDC_MIAN_A)->SetWindowText(_T("u"));
	GetDlgItem(IDC_MIAN_SYM_6)->SetWindowText(_T("x"));
	GetDlgItem(IDC_MIAN_SYM_5)->SetWindowText(_T("w"));
	GetDlgItem(IDC_MIAN_SYM_4)->SetWindowText(_T("q"));
	GetDlgItem(IDC_MIAN_P)->SetWindowText(_T("p"));
	GetDlgItem(IDC_MIAN_O)->SetWindowText(_T("h"));
	GetDlgItem(IDC_MIAN_I)->SetWindowText(_T("n"));
	GetDlgItem(IDC_MIAN_U)->SetWindowText(_T("r"));
	GetDlgItem(IDC_MIAN_Y)->SetWindowText(_T("d"));
	GetDlgItem(IDC_MIAN_T)->SetWindowText(_T("o"));
	GetDlgItem(IDC_MIAN_R)->SetWindowText(_T("ı"));
	GetDlgItem(IDC_MIAN_E)->SetWindowText(_T("ğ"));
	GetDlgItem(IDC_MIAN_W)->SetWindowText(_T("g"));
	GetDlgItem(IDC_MIAN_Q)->SetWindowText(_T("f"));
	GetDlgItem(IDC_MIAN_SYM_3)->SetWindowText(_T("-"));
	GetDlgItem(IDC_MIAN_SYM_2)->SetWindowText(_T("/"));
	GetDlgItem(IDC_MIAN_0)->SetWindowText(_T("0"));
	GetDlgItem(IDC_MIAN_9)->SetWindowText(_T("9"));
	GetDlgItem(IDC_MIAN_8)->SetWindowText(_T("8"));
	GetDlgItem(IDC_MIAN_7)->SetWindowText(_T("7"));
	GetDlgItem(IDC_MIAN_6)->SetWindowText(_T("6"));
	GetDlgItem(IDC_MIAN_5)->SetWindowText(_T("5"));
	GetDlgItem(IDC_MIAN_4)->SetWindowText(_T("4"));
	GetDlgItem(IDC_MIAN_3)->SetWindowText(_T("3"));
	GetDlgItem(IDC_MIAN_2)->SetWindowText(_T("2"));
	GetDlgItem(IDC_MIAN_1)->SetWindowText(_T("1"));
	GetDlgItem(IDC_MIAN_SYM_1)->SetWindowText(_T("+"));
}

