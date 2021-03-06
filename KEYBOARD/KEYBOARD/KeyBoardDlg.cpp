// KeyBoardDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "KeyBoard.h"
#include "KeyBoardDlg.h"
#include "KEYBOARD.h"
#include <sstream>

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
	DDX_Control(pDX, IDC_EDIT_INPUT, m_edit_input);
}

BEGIN_MESSAGE_MAP(CKeyBoardDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_WM_CTLCOLOR()

	ON_WM_CLOSE()
	ON_EN_CHANGE(IDC_EDIT_ZRH, &CKeyBoardDlg::OnEnChangeEditZrh)
	ON_BN_CLICKED(IDC_MIAN_LEFTPAGE, &CKeyBoardDlg::OnBnClickedMainLeftpage)
	ON_BN_CLICKED(IDC_MIAN_RIGHTPAGE, &CKeyBoardDlg::OnBnClickedMainRightpage)
	ON_EN_SETFOCUS(IDC_EDIT_INPUT, &CKeyBoardDlg::OnEnSetfocusEditInput)
	ON_EN_SETFOCUS(IDC_EDIT_ZRH, &CKeyBoardDlg::OnEnSetfocusEditZrh)

	ON_BN_CLICKED(IDC_MIAN_FONT1, &CKeyBoardDlg::OnBnClickedMainFont1)
	ON_BN_CLICKED(IDC_MIAN_FONT2, &CKeyBoardDlg::OnBnClickedMainFont2)
	ON_BN_CLICKED(IDC_MIAN_FONT3, &CKeyBoardDlg::OnBnClickedMainFont3)
	ON_BN_CLICKED(IDC_MIAN_FONT4, &CKeyBoardDlg::OnBnClickedMainFont4)
	ON_BN_CLICKED(IDC_MIAN_FONT5, &CKeyBoardDlg::OnBnClickedMainFont5)
	ON_BN_CLICKED(IDC_MIAN_FONT6, &CKeyBoardDlg::OnBnClickedMainFont6)
	ON_BN_CLICKED(IDC_MIAN_FONT7, &CKeyBoardDlg::OnBnClickedMainFont7)
	ON_BN_CLICKED(IDC_MIAN_FONT8, &CKeyBoardDlg::OnBnClickedMainFont8)
	ON_BN_CLICKED(IDC_MIAN_FONT9, &CKeyBoardDlg::OnBnClickedMainFont9)
	ON_BN_CLICKED(IDC_MIAN_FONT10, &CKeyBoardDlg::OnBnClickedMainFont10)
	ON_BN_CLICKED(IDC_MIAN_FONT11, &CKeyBoardDlg::OnBnClickedMainFont11)
	ON_BN_CLICKED(IDC_MIAN_FONT12, &CKeyBoardDlg::OnBnClickedMainFont12)
	ON_BN_CLICKED(IDC_MIAN_FONT13, &CKeyBoardDlg::OnBnClickedMainFont13)
	ON_BN_CLICKED(IDC_MIAN_FONT14, &CKeyBoardDlg::OnBnClickedMainFont14)
	ON_BN_CLICKED(IDC_MIAN_FONT15, &CKeyBoardDlg::OnBnClickedMainFont15)
	ON_EN_CHANGE(IDC_EDIT_INPUT, &CKeyBoardDlg::OnEnChangeEditInput)
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
	//SetWindowPos(NULL,0,0,800,600,SWP_SHOWWINDOW );	
	SetWindowPos(NULL,0,80,800,520,SWP_SHOWWINDOW );	
	CRect rect;
	GetWindowRect(&rect);
	LanType = English;
	LanTurn = English;
	//颜色，画笔初始化
	m_BKcolor = RGB(210, 231, 251);
	m_DlgBrush.CreateSolidBrush(m_BKcolor); 
	//////中日韩文字选择按键
	CButton* btnFont = new CButton[17];  
	DWORD dwStyle = WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON;
	btnFont[0].Create(_T("<-"), dwStyle,CRect(4,160,4+72,160+40),this,IDC_MIAN_LEFTPAGE);
	btnFont[1].Create(_T("->"), dwStyle,CRect(724,160,724+72,160+40),this,IDC_MIAN_RIGHTPAGE);
	btnFont[2].Create(_T(""), dwStyle,CRect(79,160,79+40,160+40),this,IDC_MIAN_FONT1);
	btnFont[3].Create(_T(""), dwStyle,CRect(122,160,122+40,160+40),this,IDC_MIAN_FONT2);
	btnFont[4].Create(_T(""), dwStyle,CRect(165,160,165+40,160+40),this,IDC_MIAN_FONT3);
	btnFont[5].Create(_T(""), dwStyle,CRect(208,160,208+40,160+40),this,IDC_MIAN_FONT4);
	btnFont[6].Create(_T(""), dwStyle,CRect(251,160,251+40,160+40),this,IDC_MIAN_FONT5);
	btnFont[7].Create(_T(""), dwStyle,CRect(294,160,294+40,160+40),this,IDC_MIAN_FONT6);
	btnFont[8].Create(_T(""), dwStyle,CRect(337,160,337+40,160+40),this,IDC_MIAN_FONT7);
	btnFont[9].Create(_T(""), dwStyle,CRect(380,160,380+40,160+40),this,IDC_MIAN_FONT8);
	btnFont[10].Create(_T(""), dwStyle,CRect(423,160,423+40,160+40),this,IDC_MIAN_FONT9);
	btnFont[11].Create(_T(""), dwStyle,CRect(466,160,466+40,160+40),this,IDC_MIAN_FONT10);
	btnFont[12].Create(_T(""), dwStyle,CRect(509,160,509+40,160+40),this,IDC_MIAN_FONT11);
	btnFont[13].Create(_T(""), dwStyle,CRect(552,160,552+40,160+40),this,IDC_MIAN_FONT12);
	btnFont[14].Create(_T(""), dwStyle,CRect(595,160,595+40,160+40),this,IDC_MIAN_FONT13);
	btnFont[15].Create(_T(""), dwStyle,CRect(638,160,638+40,160+40),this,IDC_MIAN_FONT14);
	btnFont[16].Create(_T(""), dwStyle,CRect(681,160,681+40,160+40),this,IDC_MIAN_FONT15);


	////////////////////////设置字体//////////////////////////////////////////////////
	CFont *pFont = new CFont; 
	pFont->CreatePointFont(180, _T("黑体"));
	GetDlgItem(IDC_MIAN_LEFTPAGE)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_RIGHTPAGE)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_FONT1)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_FONT2)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_FONT3)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_FONT4)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_FONT5)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_FONT6)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_FONT7)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_FONT8)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_FONT9)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_FONT10)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_FONT11)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_FONT12)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_FONT13)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_FONT14)->SetFont(pFont);
	GetDlgItem(IDC_MIAN_FONT15)->SetFont(pFont);
	
	GetDlgItem(IDC_EDIT_INPUT)->SetFont(pFont);
	/////初始化隐藏文字按键，编辑框
	btnHide();
	m_zrh_edit.ShowWindow(SW_HIDE);


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
	CreateJapaneseMapLan();
	CreateKoreanMapLan();
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




void CKeyBoardDlg::setEditText(CString &str)
{//设置文本编辑框文本
	switch (LanType)
	{
	case Chinese_others:
	case English:
	case Czech:
	case Dutch:
	case German:
	case Finnish:
	case Hindi:
	case Hungarian:
	case Italian:
	case Portuguese:
	case Russian:
	case Spanish:
	case Swedish:
	case Thai:
	case Turkish:
	case Symbol:
		{	
			int nPosStart;
			int nPosEnd  = 0; 
			m_edit_input.GetSel(nPosStart, nPosEnd); 
			m_edit_input.SetSel(nPosStart, nPosStart); 
			m_edit_input.ReplaceSel(str);
			break;

		}
	case Chinese:
	case Korean:
	case Japanese:
		{
			int nPosStart;
			int nPosEnd  = 0; 
			m_zrh_edit.GetSel(nPosStart, nPosEnd); 
			m_zrh_edit.SetSel(nPosStart, nPosStart); 
			m_zrh_edit.ReplaceSel(str);
			break;
		}
	case Arabic:
	case Farsi:
		{
			int nPosStart;
			int nPosEnd  = 0; 
			m_edit_input.GetSel(nPosStart, nPosEnd); 
			m_edit_input.SetSel(nPosStart, nPosStart); 
			m_edit_input.ReplaceSel(str);
			m_edit_input.SetSel(nPosStart, nPosStart); 
			break;
		}
	}
}
void CKeyBoardDlg::setEditText_Font(CString &str)
{
	int nPosStart;
	int nPosEnd  = 0; 
	m_edit_input.GetSel(nPosStart, nPosEnd); 
	m_edit_input.SetSel(nPosStart, nPosStart); 
	m_edit_input.ReplaceSel(str);
}


void CKeyBoardDlg::getEditText()
{//获取文本编辑框文本 
/*	CWnd* pWnd = GetDlgItem(IDC_EDIT_INPUT);
	pWnd->GetWindowText(m_strRet);*/	
	m_edit_input.GetWindowText(m_strRet);
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
	ChineseLanMap[_T("ai")] = _T("哎,哀,唉,埃,挨,皑,癌,矮,蔼,艾,爱,隘,碍, , ");
	ChineseLanMap[_T("a")] = _T("阿,啊, , , , , , , , , , , , , ");
	ChineseLanMap[_T("yi")] = _T("一,伊,衣,医,依,铱,壹,揖,仪,夷,沂,宜,姨,胰,移,遗,颐,疑,彝,乙,已,以,矣,蚁,倚,椅,义,亿,忆,艺,议,亦,屹,异,役,抑,译,邑,易,绎,诣,疫,益,谊,翌,逸,意,溢,肄,裔,毅,翼,臆, , , , , , , , , ");
	ChineseLanMap[_T("ang")] = _T("肮,昂,盎, , , , , , , , , , , , ");
	ChineseLanMap[_T("ao")] = _T("凹,敖,熬,翱,袄,傲,奥,澳,懊, , , , , , ");
	ChineseLanMap[_T("ba")] = _T("八,巴,叭,扒,吧,疤,捌,笆,拔,跋,把,靶,坝,爸,罢,霸, , , , , , , , , , , , , , ");
	ChineseLanMap[_T("bai")] = _T("白,百,佰,柏,摆,败,拜,稗, , , , , , , ");
	ChineseLanMap[_T("ban")] = _T("扳,班,般,颁,斑,搬,板,版,办,半,伴,扮,拌,绊,瓣");
	ChineseLanMap[_T("bang")] = _T("邦,帮,梆,绑,榜,膀,蚌,傍,棒,谤,磅,镑, , , ");
	ChineseLanMap[_T("bao")] = _T("包,苞,胞,褒,雹,宝,饱,保,堡,报,抱,豹,鲍,暴,爆,剥,薄,瀑, , , , , , , , , , , , ");
	ChineseLanMap[_T("bei")] = _T("卑,杯,悲,碑,北,贝,狈,备,背,钡,倍,被,惫,焙,辈");
	ChineseLanMap[_T("ben")] = _T("奔,本,苯,笨,夯, , , , , , , , , , ");
	ChineseLanMap[_T("beng")] = _T("崩,绷,甭,泵,迸,蹦, , , , , , , , ,");

	ChineseLanMap[_T("bi")] = _T("逼,鼻,比,彼,笔,鄙,币,必,毕,闭,庇,毖,陛,毙,敝,痹,蓖,弊,碧,蔽,壁,避,臂, , , , , , , ");
	ChineseLanMap[_T("bian")] = _T("边,编,鞭,贬,扁,卞,便,变,遍,辨,辩,辫, , , ");
	ChineseLanMap[_T("biao")] = _T("彪,标,膘,表, , , , , , , , , , , ");
	ChineseLanMap[_T("bie")] = _T("憋,鳖,别,瘪, , , , , , , , , , , ");
	ChineseLanMap[_T("bin")] = _T("宾,彬,斌,滨,濒,摈, , , , , , , , , ");
	ChineseLanMap[_T("bing")] = _T("冰,兵,丙,秉,柄,炳,饼,并,病, , , , , , ");
	ChineseLanMap[_T("bo")] = _T("拨,波,玻,钵,脖,菠,播,伯,驳,帛,泊,勃,铂,舶,博,渤,搏,箔,膊,卜, , , , , , , , , , ");
	ChineseLanMap[_T("bu")] = _T("补,哺,捕,不,布,步,怖,部,埠,簿, , , , , ");
	ChineseLanMap[_T("ca")] = _T("擦, , , , , , , , , , , , , , ");
	ChineseLanMap[_T("cai")] = _T("猜,才,材,财,裁,采,彩,睬,踩,菜,蔡, , , , ");
	ChineseLanMap[_T("can")] = _T("参,餐,残,蚕,惭,惨,灿, , , , , , , , ");
	ChineseLanMap[_T("cang")] = _T("仓,沧,苍,舱,藏, , , , , , , , , , ");
	ChineseLanMap[_T("cao")] = _T("操,糙,曹,槽,草, , , , , , , , , , ");


	ChineseLanMap[_T("ce")] = _T("册,侧,厕,测,策, , , , , , , , , , ");


	ChineseLanMap[_T("ceng")] = _T("层,蹭,曾, , , , , , , , , , , , ");


	ChineseLanMap[_T("cha")] = _T("叉,插,查,茬,茶,搽,察,碴,岔,诧,差,刹, , , ");


	ChineseLanMap[_T("chai")] = _T("拆,柴,豺, , , , , , , , , , , , ");


	ChineseLanMap[_T("chan")] = _T("掺,搀,谗,馋,缠,蝉,产,铲,阐,颤, , , , , ");


	ChineseLanMap[_T("chang")] = _T("昌,猖,肠,尝,偿,常,厂,场,敞,畅,倡,唱, , , ");


	ChineseLanMap[_T("chao")] = _T("抄,钞,超,巢,朝,嘲,潮,吵,炒,绰, , , , , ");


	ChineseLanMap[_T("che")] = _T("车,扯,彻,掣,撤,澈, , , , , , , , , ");


	ChineseLanMap[_T("chen")] = _T("郴,尘,臣,忱,沉,辰,陈,晨,衬,趁, , , , , ");


	ChineseLanMap[_T("cheng")] = _T("称,撑,成,呈,承,诚,城,乘,惩,程,澄,橙,逞,骋,秤");


	ChineseLanMap[_T("chi")] = _T("吃,痴,弛,池,驰,迟,持,尺,侈,齿,耻,斥,赤,炽,翅");


	ChineseLanMap[_T("chong")] = _T("充,冲,虫,崇,宠, , , , , , , , , , ");


	ChineseLanMap[_T("chou")] = _T("抽,仇,绸,畴,愁,稠,筹,酬,踌,丑,瞅,臭, , , ");


	ChineseLanMap[_T("chu")] = _T("出,初,除,厨,滁,锄,雏,橱,躇,础,储,楚,处,搐,触,矗,畜, , , , , , , , , , , , , ");


	ChineseLanMap[_T("chuai")] = _T("揣, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("chuan")] = _T("川,穿,传,船,椽,喘,串, , , , , , , , ");


	ChineseLanMap[_T("chuang")] = _T("闯,疮,窗,床,创, , , , , , , , , , ");


	ChineseLanMap[_T("chun")] = _T("春,椿,纯,唇,淳,醇,蠢, , , , , , , , ");


	ChineseLanMap[_T("chuo")] = _T("戳, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("ci")] = _T("疵,词,茨,瓷,慈,辞,磁,雌,此,次,刺,赐, , , ");


	ChineseLanMap[_T("cong")] = _T("囱,从,匆,葱,聪,丛, , , , , , , , , ");


	ChineseLanMap[_T("cou")] = _T("凑, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("cu")] = _T("粗,促,醋,簇, , , , , , , , , , , ");


	ChineseLanMap[_T("cuan")] = _T("蹿,窜,篡, , , , , , , , , , , , ");


	ChineseLanMap[_T("cui")] = _T("崔,催,摧,脆,淬,瘁,粹,翠, , , , , , , ");


	ChineseLanMap[_T("cun")] = _T("村,存,寸, , , , , , , , , , , , ");


	ChineseLanMap[_T("cuo")] = _T("搓,磋,撮,挫,措,错, , , , , , , , , ");


	ChineseLanMap[_T("da")] = _T("搭,达,答,瘩,打,大, , , , , , , , , ");


	ChineseLanMap[_T("dai")] = _T("呆,歹,傣,代,带,待,怠,殆,贷,袋,逮,戴, , , ");


	ChineseLanMap[_T("dan")] = _T("丹,单,担,耽,郸,胆,掸,旦,但,诞,弹,惮,淡,蛋,氮");


	ChineseLanMap[_T("dang")] = _T("当,挡,党,荡,档, , , , , , , , , , ");


	ChineseLanMap[_T("dao")] = _T("刀,导,岛,倒,捣,祷,蹈,到,悼,盗,道,稻, , , ");


	ChineseLanMap[_T("de")] = _T("得,德,的, , , , , , , , , , , , ");


	ChineseLanMap[_T("deng")] = _T("灯,登,蹬,等,邓,凳,瞪, , , , , , , , ");


	ChineseLanMap[_T("di")] = _T("低,堤,滴,狄,迪,敌,涤,笛,嫡,底,抵,地,弟,帝,递,第,缔,蒂, , , , , , , , , , , , ");


	ChineseLanMap[_T("dian")] = _T("掂,滇,颠,典,点,碘,电,佃,甸,店,垫,惦,淀,奠,殿,靛, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("diao")] = _T("刁,叼,凋,碉,雕,吊,钓,掉, , , , , , , ");


	ChineseLanMap[_T("die")] = _T("爹,跌,迭,谍,叠,碟,蝶, , , , , , , , ");


	ChineseLanMap[_T("ding")] = _T("丁,叮,盯,钉,顶,鼎,订,定,锭, , , , , , ");


	ChineseLanMap[_T("diu")] = _T("丢, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("dong")] = _T("东,冬,董,懂,动,冻,侗,恫,栋,洞, , , , , ");


	ChineseLanMap[_T("dou")] = _T("都,兜 ,斗,抖,陡,豆,逗,痘, , , , , , , ");


	ChineseLanMap[_T("du")] = _T("督,毒,读,犊,独,堵,赌,睹,妒,杜,肚,度,渡,镀, ");


	ChineseLanMap[_T("duan")] = _T("端,短,段,断,缎,锻, , , , , , , , , ");


	ChineseLanMap[_T("dui")] = _T("堆,队,对,兑, , , , , , , , , , , ");


	ChineseLanMap[_T("dun")] = _T("吨,敦,墩,蹲,盾,钝,顿,遁, , , , , , , ");


	ChineseLanMap[_T("duo")] = _T("多,哆,夺,掇,朵,垛,躲,剁,堕,舵,惰,跺, , , ");


	ChineseLanMap[_T("e")] = _T("讹,俄,娥,峨,鹅,蛾,额,厄,扼,恶,饿,鄂,遏, , ");


	ChineseLanMap[_T("en")] = _T("恩, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("er")] = _T("儿,而,尔,耳,洱,饵,二,贰, , , , , , , ");


	ChineseLanMap[_T("fa")] = _T("发,乏,伐,罚,阀,筏,法,珐, , , , , , , ");



	ChineseLanMap[_T("fan")] = _T("帆,番,翻,藩,凡,矾,钒,烦,樊,繁,反,返,犯,泛,饭,范,贩, , , , , , , , , , , , , ");


	ChineseLanMap[_T("fang")] = _T("方,坊,芳,防,妨,房,肪,仿,访,纺,放, , , , ");


	ChineseLanMap[_T("fei")] = _T("飞,非,啡,菲,肥,匪,诽,吠,废,沸,肺,费, , , ");


	ChineseLanMap[_T("fen")] = _T("分,吩,纷,芬,氛,酚,坟,汾,焚,粉,份,奋,忿,愤,粪");


	ChineseLanMap[_T("feng")] = _T("丰,风,枫,封,疯,峰,烽,锋,蜂,冯,逢,缝,讽,凤,奉");


	ChineseLanMap[_T("fo")] = _T("佛, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("fou")] = _T("否, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("fu")] = _T("夫,肤,孵,敷,弗,伏,扶,拂,服,俘,氟,浮,涪,符,袱,幅,福,辐,抚,甫,府,斧,俯,釜,辅,腑,腐,父,讣,付,妇,负,附,咐,阜,复,赴,副,傅,富,赋,缚,腹,覆, ");


	ChineseLanMap[_T("ga")] = _T("嘎,噶, , , , , , , , , , , , , ");


	ChineseLanMap[_T("gai")] = _T("该,改,钙,盖,溉,概, , , , , , , , , ");


	ChineseLanMap[_T("gan")] = _T("干,甘,杆,肝,柑,竿,秆,赶,敢,感,赣, , , , ");


	ChineseLanMap[_T("gang")] = _T("冈,刚,岗,纲,肛,缸,钢,港,杠, , , , , , ");


	ChineseLanMap[_T("gao")] = _T("皋,羔,高,膏,篙,糕,搞,稿,镐,告, , , , , ");


	ChineseLanMap[_T("ge")] = _T("戈,疙,哥,胳,鸽,割,搁,歌,阁,革,格,葛,隔,个,各,铬,咯, , , , , , , , , , , , , ");


	ChineseLanMap[_T("gei")] = _T("给, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("gen")] = _T("根,跟, , , , , , , , , , , , , ");


	ChineseLanMap[_T("geng")] = _T("更,庚,耕,羹,埂,耿,梗, , , , , , , , ");


	ChineseLanMap[_T("gong")] = _T("工,弓,公,功,攻,供,宫,恭,躬,龚,巩,汞,拱,共,贡");


	ChineseLanMap[_T("gou")] = _T("勾,沟,钩,狗,苟,构,购,垢,够, , , , , , ");


	ChineseLanMap[_T("gu")] = _T("估,咕,姑,孤,沽,菇,辜,箍,古,谷,股,骨,蛊,鼓,固,故,顾,雇, , , , , , , , , , , , ");


	ChineseLanMap[_T("gua")] = _T("瓜,刮,剐,寡,挂,褂, , , , , , , , , ");


	ChineseLanMap[_T("guai")] = _T("乖,拐,怪, , , , , , , , , , , , ");


	ChineseLanMap[_T("guan")] = _T("关,观,官,冠,棺,馆,管,贯,惯,灌,罐, , , , ");


	ChineseLanMap[_T("guang")] = _T("光,广,逛, , , , , , , , , , , , ");


	ChineseLanMap[_T("gui")] = _T("归,圭,龟,规,闺,硅,瑰,轨,诡,癸,鬼,刽,柜,贵,桂,跪, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("gun")] = _T("辊,滚,棍, , , , , , , , , , , , ");


	ChineseLanMap[_T("guo")] = _T("郭,锅,国,果,裹,过, , , , , , , , , ");


	ChineseLanMap[_T("ha")] = _T("蛤,哈, , , , , , , , , , , , , ");


	ChineseLanMap[_T("hai")] = _T("孩,骸,海,亥,骇,害,氦, , , , , , , , ");


	ChineseLanMap[_T("han")] = _T("酣,憨,含,邯,函,涵,寒,韩,罕,喊,汉,汗,旱,悍,捍,焊,憾,撼,翰, , , , , , , , , , , ");


	ChineseLanMap[_T("hang")] = _T("杭,航,行, , , , , , , , , , , , ");


	ChineseLanMap[_T("hao")] = _T("毫,豪,嚎,壕,好,郝,号,浩,耗, , , , , , ");


	ChineseLanMap[_T("he")] = _T("呵,喝,禾,合,何,和,河,阂,核,荷,涸,盒,菏,贺,褐,赫,鹤, , , , , , , , , , , , , ");


	ChineseLanMap[_T("hei")] = _T("黑,嘿, , , , , , , , , , , , , ");


	ChineseLanMap[_T("hen")] = _T("痕,很,狠,恨, , , , , , , , , , , ");


	ChineseLanMap[_T("heng")] = _T("亨,哼,恒,横,衡, , , , , , , , , , ");


	ChineseLanMap[_T("hong")] = _T("轰,哄,烘,弘,红,宏,洪,虹,鸿, , , , , , ");


	ChineseLanMap[_T("hou")] = _T("侯,喉,猴,吼,后,厚,候, , , , , , , , ");


	ChineseLanMap[_T("hu")] = _T("乎,呼,忽,弧,狐,胡,壶,湖,葫,瑚,糊,蝴,虎,唬,互,户,护,沪, , , , , , , , , , , , ");


	ChineseLanMap[_T("hua")] = _T("花,华,哗,滑,猾,化,划,画,话, , , , , , ");


	ChineseLanMap[_T("huai")] = _T("怀,徊,淮,槐,坏, , , , , , , , , , ");


	ChineseLanMap[_T("huan")] = _T("欢,还,环,桓,缓,幻,宦,唤,换,涣,患,焕,痪,豢, ");


	ChineseLanMap[_T("huang")] = _T("荒,慌,皇,凰,黄,惶,煌,蝗,磺,簧,恍,晃,谎,幌, ");


	ChineseLanMap[_T("hui")] = _T("灰,恢,挥,辉,徽,回,蛔,悔,卉,汇,会,讳,绘,诲,烩,贿,晦,秽,惠,毁,慧, , , , , , , , , ");


	ChineseLanMap[_T("hun")] = _T("昏,荤,婚,浑,魂,混, , , , , , , , , ");


	ChineseLanMap[_T("huo")] = _T("豁,活,火,伙,或,货,获,祸,惑,霍, , , , , ");


	ChineseLanMap[_T("ji")] = _T("讥,击,饥,圾,机,肌,鸡,迹,姬,积,基,绩,缉,畸,箕,稽,激,及,吉,汲,级,即,极,急,疾,棘,集,嫉,辑,籍,几,己,挤,脊,计,记,伎,纪,妓,忌,技,际,剂,季,既,济,继,寂,寄,悸,祭,蓟,冀,藉, , , , , , ");


	ChineseLanMap[_T("jia")] = _T("加,夹,佳,枷,家,嘉,荚,颊,甲,贾,钾,价,驾,架,假,嫁,稼,挟, , , , , , , , , , , , ");


	ChineseLanMap[_T("jian")] = _T("奸,尖,坚,歼,间,肩,艰,兼,监,笺,缄,煎,拣,俭,柬,茧,捡,减,剪,检,硷,简,碱,见,件,建,饯,剑,荐,贱,健,涧,舰,渐,溅,践,鉴,键,箭, , , , , , ");


	ChineseLanMap[_T("jiang")] = _T("江,姜,将,浆,僵,疆,讲,奖,桨,蒋,匠,降,酱, , ");


	ChineseLanMap[_T("jiao")] = _T("交,郊,娇,浇,骄,胶,椒,焦,蕉,礁,角,狡,绞,饺,矫,脚,铰,搅,剿,缴,叫,轿,较,教,窖,酵,觉,嚼, , ");


	ChineseLanMap[_T("jie")] = _T("阶,皆,接,秸,揭,街,节,劫,杰,洁,结,捷,睫,截,竭,姐,解,介,戒,芥,届,界,疥,诫,借, , , , , ");


	ChineseLanMap[_T("jin")] = _T("巾,今,斤,金,津,筋,襟,仅,紧,谨,锦,尽,劲,近,进,晋,浸,烬,禁,靳, , , , , , , , , , ");


	ChineseLanMap[_T("jing")] = _T("京,经,茎,荆,惊,晶,睛,粳,兢,精,鲸,井,颈,景,警,净,径,痉,竞,竟,敬,靖,境,静,镜, , , , , ");


	ChineseLanMap[_T("jiong")] = _T("炯,窘, , , , , , , , , , , , , ");


	ChineseLanMap[_T("jiu")] = _T("纠,究,揪,九,久,灸,玖,韭,酒,旧,臼,咎,疚,厩,救,就,舅, , , , , , , , , , , , , ");


	ChineseLanMap[_T("ju")] = _T("居,拘,狙,驹,疽,鞠,局,桔,菊,咀,沮,举,矩,句,巨,拒,具,炬,俱,剧,惧,据,距,锯,聚,踞, , , , ");


	ChineseLanMap[_T("juan")] = _T("娟,捐,鹃,卷,倦,绢,眷, , , , , , , , ");


	ChineseLanMap[_T("jue")] = _T("撅,决,诀,抉,绝,倔,掘,爵,攫, , , , , , ");


	ChineseLanMap[_T("jun")] = _T("军,君,均,钧,菌,俊,郡,峻,浚,骏,竣, , , , ");


	ChineseLanMap[_T("ka")] = _T("咖,喀,卡, , , , , , , , , , , , ");


	ChineseLanMap[_T("kai")] = _T("开,揩,凯,慨,楷, , , , , , , , , , ");


	ChineseLanMap[_T("kan")] = _T("槛,刊,勘,堪,坎,砍,看, , , , , , , , ");


	ChineseLanMap[_T("kang")] = _T("康,慷,糠,扛,亢,抗,炕, , , , , , , , ");


	ChineseLanMap[_T("kao")] = _T("考,拷,烤,靠, , , , , , , , , , , ");


	ChineseLanMap[_T("ke")] = _T("坷,苛,柯,科,棵,颗,磕,壳,咳,可,渴,克,刻,客,课");


	ChineseLanMap[_T("ken")] = _T("肯,垦,恳,啃, , , , , , , , , , , ");


	ChineseLanMap[_T("keng")] = _T("吭,坑, , , , , , , , , , , , , ");


	ChineseLanMap[_T("kong")] = _T("空,孔,恐,控, , , , , , , , , , , ");


	ChineseLanMap[_T("kou")] = _T("抠,口,扣,寇, , , , , , , , , , , ");


	ChineseLanMap[_T("ku")] = _T("枯,哭,窟,苦,库,裤,酷, , , , , , , , ");


	ChineseLanMap[_T("kua")] = _T("夸,垮,挎,胯,跨, , , , , , , , , , ");


	ChineseLanMap[_T("kuai")] = _T("块,快,侩,筷, , , , , , , , , , , ");


	ChineseLanMap[_T("kuan")] = _T("宽,款, , , , , , , , , , , , , ");


	ChineseLanMap[_T("kuang")] = _T("匡,筐,狂,况,旷,矿,框,眶, , , , , , , ");


	ChineseLanMap[_T("kui")] = _T("亏,岿,盔,窥,奎,葵,魁,傀,愧,溃,馈, , , , ");


	ChineseLanMap[_T("kun")] = _T("坤,昆,捆,困, , , , , , , , , , , ");


	ChineseLanMap[_T("kuo")] = _T("扩,括,阔,廓, , , , , , , , , , , ");


	ChineseLanMap[_T("la")] = _T("垃,拉,啦,喇,腊,蜡,辣, , , , , , , , ");


	ChineseLanMap[_T("lai")] = _T("来,莱,赖, , , , , , , , , , , , ");


	ChineseLanMap[_T("lan")] = _T("兰,拦,栏,婪,阑,蓝,谰,澜,篮,览,揽,缆,懒,烂,滥");


	ChineseLanMap[_T("lang")] = _T("郎,狼,廊,琅,榔,朗,浪, , , , , , , , ");


	ChineseLanMap[_T("lao")] = _T("捞,劳,牢,老,佬,姥,涝,烙,酪, , , , , , ");


	ChineseLanMap[_T("le")] = _T("乐,勒,了, , , , , , , , , , , , ");


	ChineseLanMap[_T("lei")] = _T("雷,镭,垒,磊,蕾,儡,肋,泪,类,累,擂, , , , ");


	ChineseLanMap[_T("leng")] = _T("棱,楞,冷, , , , , , , , , , , , ");


	ChineseLanMap[_T("li")] = _T("厘,梨,狸,离,莉,犁,漓,璃,黎,篱,礼,李,里,哩,理,鲤,力,历,厉,立,吏,丽,利,励,沥,例,隶,俐,荔,栗,砾,粒,傈,痢, , , , , , , , , , , ");


	ChineseLanMap[_T("lian")] = _T("连,帘,怜,涟,莲,联,廉,镰,敛,脸,练,炼,恋,链, ");


	ChineseLanMap[_T("liang")] = _T("俩,良,凉,梁,粮,粱,两,亮,谅,辆,晾,量, , , ");


	ChineseLanMap[_T("liao")] = _T("潦,辽,疗,聊,僚,寥,廖,撩,燎,镣,料,撂, , , ");


	ChineseLanMap[_T("lie")] = _T("列,劣,烈,猎,裂, , , , , , , , , , ");


	ChineseLanMap[_T("lin")] = _T("邻,林,临,淋,琳,霖,磷,鳞,凛,吝,赁,拎, , , ");


	ChineseLanMap[_T("ling")] = _T("伶,灵,岭,玲,凌,铃,陵,羚,菱,零,龄,领,令,另, ");


	ChineseLanMap[_T("liu")] = _T("溜,刘,流,留,琉,硫,馏,榴,瘤,柳,六, , , , ");


	ChineseLanMap[_T("long")] = _T("龙,咙,笼,聋,隆,窿,陇,垄,拢, , , , , , ");


	ChineseLanMap[_T("lou")] = _T("娄,楼,搂,篓,陋,漏, , , , , , , , , ");


	ChineseLanMap[_T("lu")] = _T("露,卢,庐,芦,炉,颅,卤,虏,掳,鲁,陆,录,赂,鹿,禄,碌,路,戮,潞,麓, , , , , , , , , , ");


	ChineseLanMap[_T("luan")] = _T("孪,峦,挛,滦,卵,乱, , , , , , , , , ");


	ChineseLanMap[_T("lue")] = _T("掠,略 , , , , , , , , , , , , , ");


	ChineseLanMap[_T("lun")] = _T("抡,仑,伦,沦,纶,轮,论, , , , , , , , ");


	ChineseLanMap[_T("luo")] = _T("罗,萝,逻,锣,箩,骡,螺,裸,洛,络,骆,落, , , ");


	ChineseLanMap[_T("lv")] = _T("滤,驴,吕,侣,旅,铝,屡,缕,履,律,虑,率,绿,氯, ");


	ChineseLanMap[_T("ma")] = _T("妈,麻,马,玛,码,蚂,骂,吗,嘛, , , , , , ");


	ChineseLanMap[_T("mai")] = _T("埋,买,迈,麦,卖,脉, , , , , , , , , ");


	ChineseLanMap[_T("man")] = _T("蛮,馒,瞒,满,曼,谩,慢,漫,蔓, , , , , , ");


	ChineseLanMap[_T("mang")] = _T("忙,芒,盲,茫,莽,氓, , , , , , , , , ");


	ChineseLanMap[_T("mao")] = _T("猫,毛,矛,茅,锚,卯,铆,茂,冒,贸,帽,貌, , , ");


	ChineseLanMap[_T("me")] = _T("么, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("mei")] = _T("没,枚,玫,眉,梅,媒,煤,酶,霉,每,美,镁,妹,昧,媚,寐, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("men")] = _T("门,闷,们, , , , , , , , , , , , ");


	ChineseLanMap[_T("meng")] = _T("萌,盟,檬,猛,蒙,锰,孟,梦, , , , , , , ");


	ChineseLanMap[_T("mi")] = _T("弥,迷,谜,醚,糜,靡,米,眯,泌,觅,秘,密,幂,蜜, ");


	ChineseLanMap[_T("mian")] = _T("眠,绵,棉,免,勉,娩,冕,缅,面, , , , , , ");


	ChineseLanMap[_T("miao")] = _T("苗,瞄,秒,渺,藐,妙,庙, , , , , , , , ");


	ChineseLanMap[_T("mie")] = _T("灭,蔑, , , , , , , , , , , , , ");


	ChineseLanMap[_T("min")] = _T("民,皿,抿,闽,悯,敏, , , , , , , , , ");


	ChineseLanMap[_T("ming")] = _T("名,明,鸣,铭,螟,命, , , , , , , , , ");


	ChineseLanMap[_T("miu")] = _T("谬, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("mo")] = _T("貉,摸,摹,模,膜,摩,磨,蘑,魔,抹,末,沫,陌,莫,寞,漠,墨,默, , , , , , , , , , , , ");


	ChineseLanMap[_T("mou")] = _T("牟,谋,某, , , , , , , , , , , , ");


	ChineseLanMap[_T("mu")] = _T("母,亩,牡,姆,拇,木,目,牧,募,墓,幕,睦,慕,暮,穆");


	ChineseLanMap[_T("na")] = _T("拿,哪,那,纳,娜,钠,呐, , , , , , , , ");


	ChineseLanMap[_T("nai")] = _T("乃,奶,氖,奈,耐, , , , , , , , , , ");


	ChineseLanMap[_T("nan")] = _T("男,难,南, , , , , , , , , , , , ");


	ChineseLanMap[_T("nang")] = _T("囊, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("ne")] = _T("呢, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("nao")] = _T("挠,恼,脑,闹,淖, , , , , , , , , , ");


	ChineseLanMap[_T("nei")] = _T("内,馁, , , , , , , , , , , , , ");


	ChineseLanMap[_T("nen")] = _T("嫩, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("neng")] = _T("能, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("ni")] = _T("妮,尼,泥,倪,霓,你,拟,逆,匿,溺,腻, , , , ");


	ChineseLanMap[_T("nian")] = _T("拈,年,捻,撵,碾,念,蔫, , , , , , , , ");


	ChineseLanMap[_T("niang")] = _T("娘,酿, , , , , , , , , , , , , ");


	ChineseLanMap[_T("niao")] = _T("鸟,尿, , , , , , , , , , , , , ");


	ChineseLanMap[_T("nie")] = _T("捏,涅,聂,啮,镊,镍,孽, , , , , , , , ");


	ChineseLanMap[_T("nin")] = _T("您, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("nuan")] = _T("暖, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("ning")] = _T("宁,拧,狞,柠,凝,泞, , , , , , , , , ");


	ChineseLanMap[_T("niu")] = _T("牛,扭,纽,钮, , , , , , , , , , , ");


	ChineseLanMap[_T("nong")] = _T("农,浓,脓,弄, , , , , , , , , , , ");


	ChineseLanMap[_T("nu")] = _T("奴,努,怒, , , , , , , , , , , , ");


	ChineseLanMap[_T("nue")] = _T("疟,虐, , , , , , , , , , , , , ");


	ChineseLanMap[_T("nuo")] = _T("挪,诺,懦,糯, , , , , , , , , , , ");


	ChineseLanMap[_T("nv")] = _T("女, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("o")] = _T("哦, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("ou")] = _T("欧,殴,鸥,呕,偶,藕,沤, , , , , , , , ");


	ChineseLanMap[_T("pa")] = _T("趴,啪,爬,耙,琶,帕,怕, , , , , , , , ");


	ChineseLanMap[_T("pai")] = _T("拍,徘,排,牌,派,湃, , , , , , , , , ");


	ChineseLanMap[_T("pan")] = _T("潘,攀,盘,磐,判,叛,盼,畔, , , , , , , ");


	ChineseLanMap[_T("pang")] = _T("乓,庞,旁,耪,胖, , , , , , , , , , ");


	ChineseLanMap[_T("pao")] = _T("抛,刨,咆,炮,袍,跑,泡, , , , , , , , ");


	ChineseLanMap[_T("pei")] = _T("呸,陪,培,赔,裴,沛,佩,配, , , , , , , ");


	ChineseLanMap[_T("pen")] = _T("喷,盆, , , , , , , , , , , , , ");


	ChineseLanMap[_T("peng")] = _T("抨,砰,烹,朋,彭,棚,硼,蓬,鹏,澎,篷,膨,捧,碰, ");


	ChineseLanMap[_T("pi")] = _T("辟,批,坯,披,砒,劈,霹,皮,毗,疲,啤,琵,脾,匹,痞,屁,僻,譬, , , , , , , , , , , , ");


	ChineseLanMap[_T("pian")] = _T("片,偏,篇,骗, , , , , , , , , , , ");


	ChineseLanMap[_T("piao")] = _T("漂,飘,瓢,票, , , , , , , , , , , ");


	ChineseLanMap[_T("pie")] = _T("撇,瞥, , , , , , , , , , , , , ");


	ChineseLanMap[_T("pin")] = _T("拼,贫,频,品,聘, , , , , , , , , , ");


	ChineseLanMap[_T("ping")] = _T("乒,平,评,凭,坪,苹,屏,瓶,萍, , , , , , ");


	ChineseLanMap[_T("po")] = _T("坡,泼,颇,婆,迫,破,粕,魄, , , , , , , ");


	ChineseLanMap[_T("pou")] = _T("剖, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("pu")] = _T("脯,仆,扑,铺,莆,菩,葡,蒲,朴,圃,埔,浦,普,谱,曝");


	ChineseLanMap[_T("qi")] = _T("七,沏,妻,柒,凄,栖,戚,期,欺,漆,祁,齐,其,奇,歧,祈,脐,崎,畦,骑,棋,旗,乞,企,岂,启,起,气,讫,迄,弃,汽,泣,契,砌,器, , , , , , , , , ");


	ChineseLanMap[_T("qia")] = _T("掐,恰,洽, , , , , , , , , , , , ");


	ChineseLanMap[_T("qian")] = _T("千,仟,扦,迁,钎,牵,铅,谦,签,前,钱,钳,乾,潜,黔,浅,遣,谴,欠,堑,嵌,歉, , , , , , , , ");


	ChineseLanMap[_T("qiang")] = _T("呛,羌,枪,腔,强,墙,蔷,抢, , , , , , , ");


	ChineseLanMap[_T("qiao")] = _T("悄,敲,锹,橇,乔,侨,桥,瞧,巧,俏,峭,窍,翘,撬,鞘");


	ChineseLanMap[_T("qie")] = _T("切,茄,且,怯,窃, , , , , , , , , , ");


	ChineseLanMap[_T("qin")] = _T("亲,侵,钦,芹,秦,琴,禽,勤,擒,寝,沁, , , , ");


	ChineseLanMap[_T("qing")] = _T("青,氢,轻,倾,卿,清,情,晴,氰,擎,顷,请,庆, , ");


	ChineseLanMap[_T("qiong")] = _T("穷,琼, , , , , , , , , , , , , ");


	ChineseLanMap[_T("qiu")] = _T("丘,邱,秋,囚,求,泅,酋,球, , , , , , , ");


	ChineseLanMap[_T("qu")] = _T("区,曲,驱,屈,蛆,躯,趋,渠,取,娶,龋,去,趣, , ");


	ChineseLanMap[_T("quan")] = _T("圈,全,权,泉,拳,痊,醛,颧,犬,劝,券, , , , ");


	ChineseLanMap[_T("que")] = _T("炔,缺,瘸,却,雀,确,鹊,榷, , , , , , , ");


	ChineseLanMap[_T("qun")] = _T("裙,群, , , , , , , , , , , , , ");


	ChineseLanMap[_T("ran")] = _T("然,燃,冉,染, , , , , , , , , , , ");


	ChineseLanMap[_T("rang")] = _T("瓤,嚷,壤,攘,让, , , , , , , , , , ");


	ChineseLanMap[_T("rao")] = _T("饶,扰,绕, , , , , , , , , , , , ");


	ChineseLanMap[_T("re")] = _T("惹,热, , , , , , , , , , , , , ");


	ChineseLanMap[_T("ren")] = _T("人,仁,壬,忍,刃,认,任,纫,妊,韧, , , , , ");


	ChineseLanMap[_T("reng")] = _T("扔,仍, , , , , , , , , , , , , ");


	ChineseLanMap[_T("ri")] = _T("日, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("rong")] = _T("戎,绒,茸,荣,容,溶,蓉,熔,融,冗, , , , , ");


	ChineseLanMap[_T("rou")] = _T("柔,揉,肉, , , , , , , , , , , , ");


	ChineseLanMap[_T("ru")] = _T("如,茹,儒,孺,蠕,汝,乳,辱,入,褥, , , , , ");


	ChineseLanMap[_T("ruan")] = _T("阮,软, , , , , , , , , , , , , ");


	ChineseLanMap[_T("rui")] = _T("蕊,锐,瑞, , , , , , , , , , , , ");


	ChineseLanMap[_T("run")] = _T("闰,润, , , , , , , , , , , , , ");


	ChineseLanMap[_T("ruo")] = _T("若,弱, , , , , , , , , , , , , ");


	ChineseLanMap[_T("sa")] = _T("撒,洒,萨, , , , , , , , , , , , ");


	ChineseLanMap[_T("sai")] = _T("塞,腮,鳃,赛, , , , , , , , , , , ");


	ChineseLanMap[_T("san")] = _T("三,叁,伞,散, , , , , , , , , , , ");


	ChineseLanMap[_T("sang")] = _T("桑,嗓,丧, , , , , , , , , , , , ");


	ChineseLanMap[_T("sao")] = _T("搔,骚,扫,嫂, , , , , , , , , , , ");


	ChineseLanMap[_T("se")] = _T("色,涩,瑟, , , , , , , , , , , , ");


	ChineseLanMap[_T("sen")] = _T("森, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("seng")] = _T("僧, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("sha")] = _T("杀,沙,纱,砂,莎,傻,啥,煞,厦, , , , , , ");


	ChineseLanMap[_T("shai")] = _T("筛,晒, , , , , , , , , , , , , ");


	ChineseLanMap[_T("shan")] = _T("山,删,杉,衫,珊,煽,闪,陕,汕,苫,扇,善,缮,擅,膳,赡,栅, , , , , , , , , , , , , ");


	ChineseLanMap[_T("shang")] = _T("伤,商,墒,裳,晌,赏,上,尚, , , , , , , ");


	ChineseLanMap[_T("shao")] = _T("捎,梢,烧,稍,勺,芍,韶,少,邵,绍,哨, , , , ");


	ChineseLanMap[_T("she")] = _T("奢,赊,舌,蛇,舍,设,社,射,涉,赦,慑,摄, , , ");


	ChineseLanMap[_T("shen")] = _T("申,伸,身,呻,绅,娠,砷,深,神,沈,审,婶,肾,甚,渗,慎,什, , , , , , , , , , , , , ");



	ChineseLanMap[_T("sheng")] = _T("升,生,声,牲,胜,甥,绳,省,圣,盛,剩, , , , ");


	ChineseLanMap[_T("shi")] = _T("匙,尸,失,师,虱,诗,施,狮,湿,十,石,时,识,实,拾,蚀,食,史,矢,使,始,驶,屎,士,氏,世,仕,市,示,式,事,侍,势,视,试,饰,室,恃,拭,是,柿,适,逝,释,嗜,誓,噬,似, , , , , , , , , , , , ");


	ChineseLanMap[_T("shou")] = _T("收,手,守,首,寿,受,兽,售,授,瘦, , , , , ");


	ChineseLanMap[_T("shu")] = _T("书,抒,叔,枢,殊,梳,淑,疏,舒,输,蔬,孰,赎,熟,暑,黍,署,鼠,蜀,薯,曙,术,戍,束,述,树,竖,恕,庶,数,墅,漱,属, , , , , , , , , , , , ");


	ChineseLanMap[_T("shua")] = _T("刷,耍, , , , , , , , , , , , , ");


	ChineseLanMap[_T("shuai")] = _T("衰,摔,甩,帅, , , , , , , , , , , ");


	ChineseLanMap[_T("shuan")] = _T("拴,栓, , , , , , , , , , , , , ");


	ChineseLanMap[_T("shuang")] = _T("双,霜,爽, , , , , , , , , , , , ");


	ChineseLanMap[_T("shui")] = _T("谁,水,税,睡, , , , , , , , , , , ");


	ChineseLanMap[_T("shun")] = _T("吮,顺,舜,瞬, , , , , , , , , , , ");


	ChineseLanMap[_T("shuo")] = _T("说,烁,朔,硕, , , , , , , , , , , ");


	ChineseLanMap[_T("si")] = _T("丝,司,私,思,斯,嘶,撕,死,巳,四,寺,伺,饲,嗣,肆");


	ChineseLanMap[_T("song")] = _T("松,怂,耸,讼,宋,诵,送,颂, , , , , , , ");


	ChineseLanMap[_T("sou")] = _T("嗽,搜,艘,擞, , , , , , , , , , , ");


	ChineseLanMap[_T("su")] = _T("苏,酥,俗,诉,肃,素,速,粟,塑,溯,僳, , , , ");


	ChineseLanMap[_T("suan")] = _T("酸,蒜,算, , , , , , , , , , , , ");


	ChineseLanMap[_T("sui")] = _T("虽,绥,隋,随,髓,岁,祟,遂,碎,隧,穗, , , , ");


	ChineseLanMap[_T("sun")] = _T("孙,损,笋, , , , , , , , , , , , ");


	ChineseLanMap[_T("suo")] = _T("唆,梭,蓑,缩,所,索,琐,锁, , , , , , , ");


	ChineseLanMap[_T("ta")] = _T("她,他,它,塌,塔,獭,挞,踏,蹋, , , , , , ");


	ChineseLanMap[_T("tai")] = _T("胎,台,抬,苔,太,汰,态,泰,酞, , , , , , ");


	ChineseLanMap[_T("tan")] = _T("坍,贪,摊,滩,瘫,坛,谈,痰,谭,潭,檀,坦,袒,毯,叹,炭,探,碳, , , , , , , , , , , , ");


	ChineseLanMap[_T("tang")] = _T("汤,唐,堂,棠,塘,搪,膛,糖,倘,淌,躺,烫,趟, , ");


	ChineseLanMap[_T("tao")] = _T("涛,绦,掏,滔,逃,桃,陶,淘,萄,讨,套, , , , ");


	ChineseLanMap[_T("te")] = _T("特, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("teng")] = _T("疼,腾,誊,藤, , , , , , , , , , , ");


	ChineseLanMap[_T("ti")] = _T("剔,梯,锑,踢,啼,提,题,蹄,体,屉,剃,涕,惕,替,嚏");


	ChineseLanMap[_T("tian")] = _T("天,添,田,恬,甜,填,腆,舔, , , , , , , ");


	ChineseLanMap[_T("tiao")] = _T("调,挑,条,迢,眺,跳, , , , , , , , , ");


	ChineseLanMap[_T("tie")] = _T("贴,铁,帖, , , , , , , , , , , , ");


	ChineseLanMap[_T("ting")] = _T("厅,汀,听,烃,廷,亭,庭,停,挺,艇, , , , , ");


	ChineseLanMap[_T("tong")] = _T("通,同,彤,桐,铜,童,酮,瞳,统,捅,桶,筒,痛, , ");


	ChineseLanMap[_T("tou")] = _T("偷,头,投,透, , , , , , , , , , , ");


	ChineseLanMap[_T("tu")] = _T("凸,秃,突,图,徒,涂,途,屠,土,吐,兔, , , , ");


	ChineseLanMap[_T("tuan")] = _T("湍,团, , , , , , , , , , , , , ");


	ChineseLanMap[_T("tui")] = _T("推,颓,腿,退,蜕,褪, , , , , , , , , ");


	ChineseLanMap[_T("tun")] = _T("囤,吞,屯,臀, , , , , , , , , , , ");


	ChineseLanMap[_T("tuo")] = _T("托,拖,脱,驮,陀,驼,鸵,妥,椭,拓,唾, , , , ");


	ChineseLanMap[_T("wa")] = _T("哇,娃,挖,洼,蛙,瓦,袜, , , , , , , , ");


	ChineseLanMap[_T("wai")] = _T("歪,外, , , , , , , , , , , , , ");


	ChineseLanMap[_T("wan")] = _T("弯,湾,豌,丸,完,玩,顽,烷,宛,挽,晚,婉,惋,皖,碗,万,腕, , , , , , , , , , , , , ");


	ChineseLanMap[_T("wang")] = _T("汪,亡,王,网,往,枉,妄,忘,旺,望, , , , , ");


	ChineseLanMap[_T("wei")] = _T("危,威,微,巍,为,韦,围,违,桅,唯,惟,维,潍,伟,伪,尾,纬,苇,委,萎,卫,未,位,味,畏,胃,尉,谓,喂,渭,蔚,慰,魏, , , , , , , , , , , , ");



	ChineseLanMap[_T("wen")] = _T("温,瘟,文,纹,闻,蚊,吻,紊,稳,问, , , , , ");


	ChineseLanMap[_T("weng")] = _T("翁,嗡,瓮, , , , , , , , , , , , ");


	ChineseLanMap[_T("wo")] = _T("挝,涡,窝,蜗,我,沃,卧,握,斡, , , , , , ");


	ChineseLanMap[_T("wu")] = _T("乌,污,呜,巫,屋,诬,钨,无,毋,吴,吾,芜,梧,五,午,伍,坞,武,侮,捂,舞,勿,务,戊,物,误,悟,晤,雾, ");


	ChineseLanMap[_T("xi")] = _T("夕,汐,西,吸,希,昔,析,矽,息,牺,悉,惜,烯,硒,晰,犀,稀,溪,锡,熄,熙,嘻,膝,习,席,袭,媳,檄,洗,喜,戏,系,细,隙, , , , , , , , , , , ");


	ChineseLanMap[_T("xia")] = _T("虾,瞎,匣,侠,峡,狭,暇,辖,霞,下,吓,夏, , , ");


	ChineseLanMap[_T("xian")] = _T("铣,仙,先,纤,掀,锨,鲜,闲,弦,贤,咸,涎,舷,衔,嫌,显,险,县,现,线,限,宪,陷,馅,羡,献,腺, , , ");


	ChineseLanMap[_T("xiang")] = _T("乡,相,香,厢,湘,箱,襄,镶,详,祥,翔,享,响,想,向,巷,项,象,像,橡, , , , , , , , , , ");


	ChineseLanMap[_T("xiao")] = _T("宵,消,萧,硝,销,霄,嚣,淆,小,晓,孝,肖,哮,效,校,笑,啸, , , , , , , , , , , , , ");


	ChineseLanMap[_T("xie")] = _T("些,楔,歇,蝎,协,邪,胁,斜,谐,携,鞋,写,泄,泻,卸,屑,械,谢,懈,蟹, , , , , , , , , , ");


	ChineseLanMap[_T("xin")] = _T("心,忻,芯,辛,欣,锌,新,薪,信,衅,鑫, , , , ");


	ChineseLanMap[_T("xing")] = _T("兴,星,惺,猩,腥,刑,邢,形,型,醒,杏,姓,幸,性, ");


	ChineseLanMap[_T("xiong")] = _T("凶,兄,匈,汹,胸,雄,熊, , , , , , , , ");


	ChineseLanMap[_T("xiu")] = _T("宿,休,修,羞,朽,秀,绣,袖,锈,嗅, , , , , ");


	ChineseLanMap[_T("xu")] = _T("戌,须,虚,嘘,需,墟,徐,许,旭,序,叙,恤,绪,续,酗,婿,絮,蓄,吁, , , , , , , , , , , ");


	ChineseLanMap[_T("xuan")] = _T("轩,宣,喧,玄,悬,旋,选,癣,绚,眩, , , , , ");


	ChineseLanMap[_T("xue")] = _T("削,靴,薛,穴,学,雪,血, , , , , , , , ");


	ChineseLanMap[_T("xun")] = _T("勋,熏,寻,巡,旬,驯,询,循,训,讯,汛,迅,逊,殉, ");


	ChineseLanMap[_T("ya")] = _T("丫,压,呀,押,鸦,鸭,牙,芽,蚜,崖,涯,衙,哑,雅,亚,讶, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("yan")] = _T("咽,烟,淹,焉,阉,延,严,言,岩,沿,炎,研,盐,阎,蜒,颜,奄,衍,掩,眼,演,厌,彦,砚,唁,宴,艳,验,谚,堰,焰,雁,燕, , , , , , , , , , , , ");


	ChineseLanMap[_T("yang")] = _T("央,殃,秧,鸯,扬,羊,阳,杨,佯,疡,洋,仰,养,氧,痒,样,漾, , , , , , , , , , , , , ");


	ChineseLanMap[_T("yao")] = _T("侥,妖,腰,邀,尧,姚,窑,谣,摇,遥,瑶,咬,舀,药,要,耀,钥, , , , , , , , , , , , , ");


	ChineseLanMap[_T("ye")] = _T("椰,噎,爷,耶,也,冶,野,业,叶,曳,页,夜,掖,液,腋, , , , , , , , , , , , , , , ");


	ChineseLanMap[_T("yin")] = _T("因,阴,姻,茵,荫,音,殷,吟,寅,淫,银,尹,引,饮,隐,印, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("ying")] = _T("应,英,婴,缨,樱,鹰,迎,盈,荧,莹,萤,营,蝇,赢,颖,影,映,硬, , , , , , , , , , , , ");


	ChineseLanMap[_T("yo")] = _T("哟, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("yong")] = _T("佣,拥,痈,庸,雍,臃,永,咏,泳,勇,涌,恿,蛹,踊,用");


	ChineseLanMap[_T("you")] = _T("优,忧,幽,悠,尤,由,犹,邮,油,铀,游,友,有,酉,又,右,幼,佑,诱,釉, , , , , , , , , , ");


	ChineseLanMap[_T("yu")] = _T("迂,淤,渝,于,予,余,盂,鱼,俞,娱,渔,隅,愉,逾,愚,榆,虞,舆,与,宇,屿,羽,雨,禹,语,玉,驭,芋,育,郁,狱,峪,浴,预,域,欲,喻,寓,御,裕,遇,愈,誉,豫, ");


	ChineseLanMap[_T("yuan")] = _T("冤,鸳,渊,元,员,园,垣,原,圆,袁,援,缘,源,猿,辕,远,苑,怨,院,愿, , , , , , , , , , ");


	ChineseLanMap[_T("yue")] = _T("曰,约,月,岳,悦,阅,跃,粤,越, , , , , , ");


	ChineseLanMap[_T("yun")] = _T("云,匀,郧,耘,允,陨,孕,运,晕,酝,韵,蕴, , , ");


	ChineseLanMap[_T("za")] = _T("匝,杂,砸,咋, , , , , , , , , , , ");


	ChineseLanMap[_T("zai")] = _T("灾,哉,栽,宰,载,再,在,仔, , , , , , , ");


	ChineseLanMap[_T("zan")] = _T("咱,攒,暂,赞, , , , , , , , , , , ");


	ChineseLanMap[_T("zang")] = _T("赃,脏,葬, , , , , , , , , , , , ");


	ChineseLanMap[_T("zao")] = _T("遭,糟,凿,早,枣,蚤,澡,藻,灶,皂,造,噪,燥,躁, ");


	ChineseLanMap[_T("ze")] = _T("则,择,泽,责, , , , , , , , , , , ");


	ChineseLanMap[_T("zei")] = _T("贼, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("zen")] = _T("怎, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("zeng")] = _T("增,憎,赠, , , , , , , , , , , , ");


	ChineseLanMap[_T("zha")] = _T("喳,渣,扎,札,轧,闸,铡,眨,乍,诈,炸,榨,柞, , ");


	ChineseLanMap[_T("zhai")] = _T("斋,摘,宅,翟,窄,债,寨, , , , , , , , ");


	ChineseLanMap[_T("zhan")] = _T("沾,毡,粘,詹,瞻,斩,展,盏,崭,辗,占,战,栈,站,绽,湛,蘸, , , , , , , , , , , , , ");


	ChineseLanMap[_T("zhang")] = _T("长,张,章,彰,漳,樟,涨,掌,丈,仗,帐,杖,胀,账,障,瘴, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("zhao")] = _T("招,昭,找,沼,召,兆,赵,照,罩,肇,爪, , , , ");


	ChineseLanMap[_T("zhe")] = _T("遮,折,哲,蛰,辙,者,锗,这,浙,蔗,着, , , , ");


	ChineseLanMap[_T("zhen")] = _T("贞,针,侦,珍,真,砧,斟,甄,臻,诊,枕,疹,阵,振,镇,震,帧, , , , , , , , , , , , , ");


	ChineseLanMap[_T("zheng")] = _T("争,征,怔,挣,狰,睁,蒸,拯,整,正,证,郑,政,症, ");


	ChineseLanMap[_T("zhi")] = _T("之,支,汁,芝,吱,枝,知,织,肢,脂,蜘,执,侄,直,值,职,植,殖,止,只,旨,址,纸,指,趾,至,志,制,帜,治,炙,质,峙,挚,秩,致,掷,痔,窒,智,滞,稚,置, , ");


	ChineseLanMap[_T("zhong")] = _T("中,忠,终,盅,钟,衷,肿,种,仲,众,重, , , , ");


	ChineseLanMap[_T("zhou")] = _T("州,舟,诌,周,洲,粥,轴,肘,帚,咒,宙,昼,皱,骤, ");


	ChineseLanMap[_T("zhu")] = _T("朱,诛,株,珠,诸,猪,蛛,竹,烛,逐,主,拄,煮,嘱,瞩,住,助,注,贮,驻,柱,祝,著,蛀,筑,铸, , , , ");


	ChineseLanMap[_T("zhua")] = _T("抓, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("zhuai")] = _T("拽, , , , , , , , , , , , , , ");


	ChineseLanMap[_T("zhuan")] = _T("专,砖,转,撰,篆, , , , , , , , , , ");


	ChineseLanMap[_T("zhuang")] = _T("妆,庄,桩,装,壮,状,幢,撞, , , , , , ,");


	ChineseLanMap[_T("zhui")] = _T("追,椎,锥,坠,缀,赘, , , , , , , , , ");


	ChineseLanMap[_T("zhun")] = _T("谆,准, , , , , , , , , , , , , ");


	ChineseLanMap[_T("zhuo")] = _T("卓,拙,捉,桌,灼,茁,浊,酌,啄,琢, , , , , ");


	ChineseLanMap[_T("zi")] = _T("孜,兹,咨,姿,资,淄,滋,籽,子,紫,滓,字,自,渍, ");


	ChineseLanMap[_T("zong")] = _T("宗,综,棕,踪,鬃,总,纵, , , , , , , , ");


	ChineseLanMap[_T("zou")] = _T("邹,走,奏,揍, , , , , , , , , , , ");


	ChineseLanMap[_T("zu")] = _T("租,足,卒,族,诅,阻,组,祖, , , , , , , ");


	ChineseLanMap[_T("zuan")] = _T("赚,纂,钻, , , , , , , , , , , , ");


	ChineseLanMap[_T("zui")] = _T("嘴,最,罪,醉, , , , , , , , , , , ");


	ChineseLanMap[_T("zun")] = _T("尊,遵, , , , , , , , , , , , , ");


	ChineseLanMap[_T("zuo")] = _T("昨,左,佐,作,坐,座,做, , , , , , , , ");



}


void CKeyBoardDlg::CreateJapaneseMapLan()
{
	JapaneseLanMap[_T("a")] = _T("あ,ア, , , , , , , , , , , , , ");



	JapaneseLanMap[_T("ka")] = _T("か,カ, , , , , , , , , , , , , ");



	JapaneseLanMap[_T("sa")] = _T("さ,サ, , , , , , , , , , , , , ");



	JapaneseLanMap[_T("ta")] = _T("た,タ, , , , , , , , , , , , , ");



	JapaneseLanMap[_T("na")] = _T("な,ナ, , , , , , , , , , , , , ");



	JapaneseLanMap[_T("ha")] = _T("は,ハ, , , , , , , , , , , , , ");



	JapaneseLanMap[_T("ma")] = _T("ま,マ, , , , , , , , , , , , , ");



	JapaneseLanMap[_T("ya")] = _T("や,ヤ, , , , , , , , , , , , , ");



	JapaneseLanMap[_T("ra")] = _T("ら,ラ, , , , , , , , , , , , , ");



	JapaneseLanMap[_T("wa")] = _T("わ,ワ, , , , , , , , , , , , , ");



	JapaneseLanMap[_T("n")] = _T("ん,ン, , , , , , , , , , , , , ");



	JapaneseLanMap[_T("i")] = _T("い,イ, , , , , , , , , , , , , ");



	JapaneseLanMap[_T("ki")] = _T("き,キ, , , , , , , , , , , , , ");



	JapaneseLanMap[_T("shi")] = _T("し,シ, , , , , , , , , , , , , ");



	JapaneseLanMap[_T("chi")] = _T("ち,チ, , , , , , , , , , , , , ");



	JapaneseLanMap[_T("ni")] = _T("に,ニ, , , , , , , , , , , , , ");



	JapaneseLanMap[_T("hi")] = _T("ひ,ヒ, , , , , , , , , , , , , ");



	JapaneseLanMap[_T("mi")] = _T("み,ミ, , , , , , , , , , , , , ");



	JapaneseLanMap[_T("ri")] = _T("り,リ, , , , , , , , , , , , , ");



	JapaneseLanMap[_T("u")] = _T("う,ウ, , , , , , , , , , , , , ");



	JapaneseLanMap[_T("ku")] = _T("く,ク, , , , , , , , , , , , , ");



	JapaneseLanMap[_T("su")] = _T("す,ス, , , , , , , , , , , , , ");



	JapaneseLanMap[_T("tsu")] = _T("つ,ツ, , , , , , , , , , , , , ");

	JapaneseLanMap[_T("nu")] = _T("ぬ,ヌ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("fu")] = _T("ふ,フ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("mu")] = _T("む,ム, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("yu")] = _T("ゆ,ユ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("ru")] = _T("る,ル, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("e")] = _T("え,エ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("ke")] = _T("け,ケ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("se")] = _T("せ,セ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("te")] = _T("て,テ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("ne")] = _T("ね,ネ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("he")] = _T("へ,ヘ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("me")] = _T("め,メ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("re")] = _T("れ,レ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("o")] = _T("お,オ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("ko")] = _T("こ,コ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("so")] = _T("そ,ソ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("to")] = _T("と,ト, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("no")] = _T("の,ノ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("ho")] = _T("ほ,ホ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("mo")] = _T("も,モ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("yo")] = _T("よ,ヨ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("ro")] = _T("ろ,ロ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("wo")] = _T("を,ヲ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("ga")] = _T("が,ガ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("za")] = _T("ざ,ザ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("da")] = _T("だ,ダ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("ba")] = _T("ば,バ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("gi")] = _T("ぎ,ギ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("ji")] = _T("じ,ジ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("zi")] = _T("じ,ジ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("di")] = _T("ぢ,ヂ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("bi")] = _T("び,ビ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("gu")] = _T("ぐ,グ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("zu")] = _T("ず,ズ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("du")] = _T("づ,ヅ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("bu")] = _T("ぶ,ブ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("ge")] = _T("げ,ゲ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("ze")] = _T("ぜ,ゼ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("de")] = _T("で,デ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("be")] = _T("べ,ベ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("go")] = _T("ご,ゴ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("zo")] = _T("ぞ,ゾ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("do")] = _T("ど,ド, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("bo")] = _T("ぼ,ボ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("pa")] = _T("ぱ,パ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("pi")] = _T("ぴ,ピ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("pu")] = _T("プ,ピ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("pe")] = _T("ぺ,ペ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("po")] = _T("ぽ,ポ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("kya")] = _T("きゃ,キャ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("gya")] = _T("ぎゃ,ギャ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("sha")] = _T("しゃ,シャ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("ja")] = _T("じゃ,ジャ,ヂャ, , , , , , , , , , , , ");


	JapaneseLanMap[_T("cha")] = _T("ちゃ,チャ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("nya")] = _T("にゃ,ニャ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("dya")] = _T("ぢゃ, , , , , , , , , , , , , , ");


	JapaneseLanMap[_T("hya")] = _T("ひゃ,ヒャ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("bya")] = _T("びゃ,ビャ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("pya")] = _T("ぴゃ,ピャ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("mya")] = _T("みゃ,ミャ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("rya")] = _T("りゃ,リャ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("kyu")] = _T("キュ,きゅ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("gyu")] = _T("ぎゅ,ギュ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("shu")] = _T("しゅ,シュ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("ju")] = _T("じゅ,ジュ,ヂュ, , , , , , , , , , , , ");


	JapaneseLanMap[_T("chu")] = _T("ちゅ,チュ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("nyu")] = _T("にゅ,ニュ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("hyu")] = _T("ひゅ,ヒュ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("byu")] = _T("びゅ,ビュ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("pyu")] = _T("ぴゅ,ピュ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("myu")] = _T("みゅ,ミュ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("ryu")] = _T("りゅ,リュ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("kyo")] = _T("きょ,キョ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("gyo")] = _T("ぎょ,ギョ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("sho")] = _T("しょ,ショ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("jo")] = _T("じょ,ジョ,ジョ, , , , , , , , , , , , ");


	JapaneseLanMap[_T("cho")] = _T("ちょ,ショ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("dyo")] = _T("ぢょ, , , , , , , , , , , , , , ");


	JapaneseLanMap[_T("nyo")] = _T("にょ,ニョ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("hyo")] = _T("ひょ,ヒョ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("byo")] = _T("びょ,ビョ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("pyo")] = _T("ぴょ,ピョ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("myo")] = _T("みょ,ミョ, , , , , , , , , , , , , ");


	JapaneseLanMap[_T("ryo")] = _T("りょ,リョ, , , , , , , , , , , , , ");
}

void CKeyBoardDlg::CreateKoreanMapLan()
{
	KoreanLanMap[_T("ㄱ"

		)] = _T("ㄱ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄴ"

		)] = _T("ㄴ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄹ"

		)] = _T("ㄹ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅁ"

		)] = _T("ㅁ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅂ"

		)] = _T("ㅂ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅅ"

		)] = _T("ㅅ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅇ"

		)] = _T("ㅇ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅈ"

		)] = _T("ㅈ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅊ"

		)] = _T("ㅊ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅋ"

		)] = _T("ㅋ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅌ"

		)] = _T("ㅌ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅍ"

		)] = _T("ㅍ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅎ"

		)] = _T("ㅎ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄲ"

		)] = _T("ㄲ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄸ"

		)] = _T("ㄸ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅃ"

		)] = _T("ㅃ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅆ"

		)] = _T("ㅆ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅉ"

		)] = _T("ㅉ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅏ"

		)] = _T("ㅏ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅑ"

		)] = _T("ㅅ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅓ"

		)] = _T("ㅓ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅕ"

		)] = _T("ㅕ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅗ"

		)] = _T("ㅗ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅛ"

		)] = _T("ㅛ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅜ"

		)] = _T("ㅜ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅠ"

		)] = _T("ㅠ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅡ"

		)] = _T("ㅡ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅣ"

		)] = _T("ㅣ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅐ"

		)] = _T("ㅐ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅒ"

		)] = _T("ㅒ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅔ"

		)] = _T("ㅔ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅖ"

		)] = _T("ㅖ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅘ"

		)] = _T("ㅘ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅙ"

		)] = _T("ㅙ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅚ"

		)] = _T("ㅚ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅝ"

		)] = _T("ㅝ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅞ"

		)] = _T("ㅞ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅟ"

		)] = _T("ㅟ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅢ"

		)] = _T("ㅢ, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("가"

		)] = _T("가, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("나"

		)] = _T("나, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("다"

		)] = _T("다, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("라"

		)] = _T("라, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("마"

		)] = _T("마, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("바"

		)] = _T("바, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("사"

		)] = _T("사, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("아"

		)] = _T("아, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("자"

		)] = _T("자, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("차"

		)] = _T("차, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("카"

		)] = _T("카, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("타"

		)] = _T("타, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("파"

		)] = _T("파, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("하"

		)] = _T("하, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄱㅏ"

		)] = _T("가, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄱㅑ"

		)] = _T("갸, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄱㅓ"

		)] = _T("거, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄱㅕ"

		)] = _T("겨, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄱㅗ"

		)] = _T("고, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄱㅛ"

		)] = _T("교, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄱㅜ"

		)] = _T("구, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄱㅠ"

		)] = _T("규, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄱㅡ"

		)] = _T("그, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄱㅣ"

		)] = _T("기, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄴㅏ"

		)] = _T("나, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄴㅑ"

		)] = _T("냐, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄴㅓ"

		)] = _T("너, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄴㅕ"

		)] = _T("녀, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄴㅗ"

		)] = _T("노, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄴㅛ"

		)] = _T("뇨, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄴㅜ"

		)] = _T("누, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄴㅠ"

		)] = _T("뉴, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄴㅡ"

		)] = _T("느, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄴㅣ"

		)] = _T("니, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄷㅏ"

		)] = _T("다, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄷㅑ"

		)] = _T("댜, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄷㅓ"

		)] = _T("더, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄷㅕ"

		)] = _T("뎌, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄷㅗ"

		)] = _T("도, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄷㅛ"

		)] = _T("됴, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄷㅜ"

		)] = _T("두, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄷㅠ"

		)] = _T("듀, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄷㅡ"

		)] = _T("드, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄷㅣ"

		)] = _T("디, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄹㅏ"

		)] = _T("라, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄹㅑ"

		)] = _T("랴, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄹㅓ"

		)] = _T("러, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄹㅕ"

		)] = _T("려, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄹㅗ"

		)] = _T("로, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄹㅛ"

		)] = _T("료, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄹㅜ"

		)] = _T("루, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄹㅠ"

		)] = _T("류, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄹㅡ"

		)] = _T("르, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄹㅣ"

		)] = _T("리, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅁㅏ"

		)] = _T("마, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅁㅑ"

		)] = _T("먀, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅁㅓ"

		)] = _T("머, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅁㅕ"

		)] = _T("며, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅁㅗ"

		)] = _T("모, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅁㅛ"

		)] = _T("묘, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅁㅜ"

		)] = _T("무, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅁㅠ"

		)] = _T("뮤, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅁㅡ"

		)] = _T("므, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅁㅣ"

		)] = _T("미, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅂㅏ"

		)] = _T("바, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅂㅑ"

		)] = _T("뱌, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅂㅓ"

		)] = _T("버, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅂㅕ"

		)] = _T("벼, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅂㅗ"

		)] = _T("보, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅂㅛ"

		)] = _T("뵤, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅂㅜ"

		)] = _T("부, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅂㅠ"

		)] = _T("뷰, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅂㅡ"

		)] = _T("브, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅂㅣ"

		)] = _T("비, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅅㅏ"

		)] = _T("사, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅅㅑ"

		)] = _T("샤, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅅㅓ"

		)] = _T("서, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅅㅕ"

		)] = _T("셔, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅅㅗ"

		)] = _T("소, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅅㅛ"

		)] = _T("쇼, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅅㅜ"

		)] = _T("수, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅅㅠ"

		)] = _T("슈, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅅㅡ"

		)] = _T("스, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅅㅣ"

		)] = _T("시, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅇㅏ"

		)] = _T("아, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅇㅑ"

		)] = _T("야, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅇㅓ"

		)] = _T("어, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅇㅕ"

		)] = _T("여, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅇㅗ"

		)] = _T("오, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅇㅛ"

		)] = _T("요, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅇㅜ"

		)] = _T("우, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅇㅠ"

		)] = _T("유, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅇㅡ"

		)] = _T("으, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅇㅣ"

		)] = _T("이, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅈㅏ"

		)] = _T("자, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅈㅑ"

		)] = _T("쟈, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅈㅓ"

		)] = _T("저, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅈㅕ"

		)] = _T("져, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅈㅗ"

		)] = _T("조, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅈㅛ"

		)] = _T("쵸, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅈㅜ"

		)] = _T("추, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅈㅠ"

		)] = _T("츄, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅈㅡ"

		)] = _T("츠, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅈㅣ"

		)] = _T("치, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅋㅏ"

		)] = _T("카, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅋㅑ"

		)] = _T("캬, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅋㅓ"

		)] = _T("커, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅋㅕ"

		)] = _T("켜, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅋㅗ"

		)] = _T("코, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅋㅛ"

		)] = _T("쿄, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅋㅜ"

		)] = _T("쿠, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅋㅠ"

		)] = _T("큐, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅋㅡ"

		)] = _T("크, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅋㅣ"

		)] = _T("키, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅌㅏ"

		)] = _T("타, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅌㅑ"

		)] = _T("탸, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅌㅓ"

		)] = _T("터, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅌㅕ"

		)] = _T("텨, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅌㅗ"

		)] = _T("토, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅌㅛ"

		)] = _T("툐, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅌㅜ"

		)] = _T("투, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅌㅠ"

		)] = _T("튜, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅌㅡ"

		)] = _T("트, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅌㅣ"

		)] = _T("티, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅍㅏ"

		)] = _T("파, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅍㅑ"

		)] = _T("퍄, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅍㅓ"

		)] = _T("퍼, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅍㅕ"

		)] = _T("펴, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅍㅗ"

		)] = _T("포, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅍㅛ"

		)] = _T("표, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅍㅜ"

		)] = _T("푸, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅍㅠ"

		)] = _T("퓨, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅍㅡ"

		)] = _T("프, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅍㅣ"

		)] = _T("피, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅎㅏ"

		)] = _T("하, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅎㅑ"

		)] = _T("햐, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅎㅓ"

		)] = _T("허, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅎㅕ"

		)] = _T("혀, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅎㅗ"

		)] = _T("호, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅎㅛ"

		)] = _T("효, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅎㅜ"

		)] = _T("후, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅎㅠ"

		)] = _T("휴, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅎㅡ"

		)] = _T("흐, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅎㅣ"

		)] = _T("히, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄲㅏ"

		)] = _T("까, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄲㅑ"

		)] = _T("꺄, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄲㅓ"

		)] = _T("꺼, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄲㅕ"

		)] = _T("껴, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄲㅗ"

		)] = _T("꼬, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄲㅛ"

		)] = _T("꾜, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄲㅜ"

		)] = _T("꾸, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄲㅠ"

		)] = _T("뀨, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄲㅡ"

		)] = _T("끄, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄲㅣ"

		)] = _T("끼, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄸㅏ"

		)] = _T("따, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄸㅑ"

		)] = _T("땨, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄸㅓ"

		)] = _T("떠, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄸㅕ"

		)] = _T("뗘, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄸㅗ"

		)] = _T("또, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄸㅛ"

		)] = _T("뚀, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄸㅜ"

		)] = _T("뚜, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄸㅠ"

		)] = _T("뜌, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄸㅡ"

		)] = _T("뜨, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄸㅣ"

		)] = _T("띠, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅃㅏ"

		)] = _T("빠, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅃㅑ"

		)] = _T("뺘, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅃㅓ"

		)] = _T("뻐, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅃㅕ"

		)] = _T("뼈, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅃㅗ"

		)] = _T("뽀, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅃㅛ"

		)] = _T("뾰, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅃㅜ"

		)] = _T("뿌, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅃㅠ"

		)] = _T("쀼, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅃㅡ"

		)] = _T("쁘, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅃㅣ"

		)] = _T("삐, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅆㅏ"

		)] = _T("싸, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅆㅑ"

		)] = _T("쌰, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅆㅓ"

		)] = _T("써, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅆㅕ"

		)] = _T("쎠, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅆㅗ"

		)] = _T("쏘, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅆㅛ"

		)] = _T("쑈, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅆㅜ"

		)] = _T("쑤, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅆㅠ"

		)] = _T("쓔, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅆㅡ"

		)] = _T("쓰, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅆㅣ"

		)] = _T("씨, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅉㅏ"

		)] = _T("짜, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅉㅑ"

		)] = _T("쨔, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅉㅓ"

		)] = _T("쩌, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅉㅕ"

		)] = _T("쪄, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅉㅗ"

		)] = _T("쪼, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅉㅛ"

		)] = _T("쬬, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅉㅜ"

		)] = _T("쭈, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅉㅠ"

		)] = _T("쮸, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅉㅡ"

		)] = _T("쯔, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅉㅣ"

		)] = _T("찌, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄱㅐ"

		)] = _T("개, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄱㅒ"

		)] = _T("걔, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄱㅔ"

		)] = _T("게, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄱㅖ"

		)] = _T("계, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄱㅘ"

		)] = _T("과, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄱㅙ"

		)] = _T("괘, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄱㅚ"

		)] = _T("괴, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄱㅝ"

		)] = _T("궈, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄱㅞ"

		)] = _T("궤, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄱㅟ"

		)] = _T("귀, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄱㅢ"

		)] = _T("긔, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄴㅐ"

		)] = _T("내, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄴㅒ"

		)] = _T("냬, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄴㅔ"

		)] = _T("네, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄴㅖ"

		)] = _T("녜, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄴㅘ"

		)] = _T("놔, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄴㅙ"

		)] = _T("놰, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄴㅚ"

		)] = _T("뇌, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄴㅝ"

		)] = _T("눠, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄴㅞ"

		)] = _T("눼, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄴㅟ"

		)] = _T("뉘, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄴㅢ"

		)] = _T("늬, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄷㅐ"

		)] = _T("대, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄷㅒ"

		)] = _T("댸, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄷㅔ"

		)] = _T("데, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄷㅖ"

		)] = _T("뎨, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄷㅘ"

		)] = _T("돠, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄷㅙ"

		)] = _T("돼, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄷㅚ"

		)] = _T("되, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄷㅝ"

		)] = _T("둬, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄷㅞ"

		)] = _T("뒈, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄷㅟ"

		)] = _T("뒤, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄷㅢ"

		)] = _T("듸, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄹㅐ"

		)] = _T("래, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄹㅒ"

		)] = _T("럐, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄹㅔ"

		)] = _T("레, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄹㅖ"

		)] = _T("례, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄹㅘ"

		)] = _T("롸, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄹㅙ"

		)] = _T("뢔, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄹㅚ"

		)] = _T("뢰, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄹㅝ"

		)] = _T("뤄, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄹㅞ"

		)] = _T("뤠, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄹㅟ"

		)] = _T("뤼, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄹㅢ"

		)] = _T("릐, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅁㅐ"

		)] = _T("매, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅁㅒ"

		)] = _T("먜, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅁㅔ"

		)] = _T("메, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅁㅖ"

		)] = _T("몌, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅁㅘ"

		)] = _T("뫄, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅁㅙ"

		)] = _T("뫠, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅁㅚ"

		)] = _T("뫼, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅁㅝ"

		)] = _T("뭐, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅁㅞ"

		)] = _T("뭬, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅁㅟ"

		)] = _T("뮈, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅁㅢ"

		)] = _T("믜, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅂㅐ"

		)] = _T("배, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅂㅒ"

		)] = _T("뱨, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅂㅔ"

		)] = _T("베, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅂㅖ"

		)] = _T("볘, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅂㅘ"

		)] = _T("봐, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅂㅙ"

		)] = _T("봬, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅂㅚ"

		)] = _T("뵈, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅂㅝ"

		)] = _T("붜, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅂㅞ"

		)] = _T("붸, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅂㅟ"

		)] = _T("뷔, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅂㅢ"

		)] = _T("븨, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅅㅐ"

		)] = _T("새, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅅㅒ"

		)] = _T("섀, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅅㅔ"

		)] = _T("세, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅅㅖ"

		)] = _T("셰, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅅㅘ"

		)] = _T("솨, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅅㅙ"

		)] = _T("쇄, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅅㅚ"

		)] = _T("쇠, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅅㅝ"

		)] = _T("숴, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅅㅞ"

		)] = _T("쉐, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅅㅟ"

		)] = _T("쉬, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅅㅢ"

		)] = _T("싀, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅇㅐ"

		)] = _T("애, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅇㅒ"

		)] = _T("얘, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅇㅔ"

		)] = _T("에, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅇㅖ"

		)] = _T("예, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅇㅘ"

		)] = _T("와, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅇㅙ"

		)] = _T("왜, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅇㅚ"

		)] = _T("외, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅇㅝ"

		)] = _T("워, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅇㅞ"

		)] = _T("웨, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅇㅟ"

		)] = _T("위, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅇㅢ"

		)] = _T("의, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅈㅐ"

		)] = _T("재, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅈㅒ"

		)] = _T("쟤, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅈㅔ"

		)] = _T("제, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅈㅖ"

		)] = _T("졔, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅈㅘ"

		)] = _T("좌, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅈㅙ"

		)] = _T("좨, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅈㅚ"

		)] = _T("죄, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅈㅝ"

		)] = _T("줘, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅈㅞ"

		)] = _T("줴, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅈㅟ"

		)] = _T("쥐, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅈㅢ"

		)] = _T("즤, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅊㅐ"

		)] = _T("채, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅊㅒ"

		)] = _T("챼, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅊㅔ"

		)] = _T("체, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅊㅖ"

		)] = _T("쳬, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅊㅘ"

		)] = _T("촤, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅊㅙ"

		)] = _T("쵀, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅊㅚ"

		)] = _T("최, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅊㅝ"

		)] = _T("춰, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅊㅞ"

		)] = _T("췌, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅊㅟ"

		)] = _T("취, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅊㅢ"

		)] = _T("츼, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅋㅐ"

		)] = _T("캐, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅋㅒ"

		)] = _T("컈, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅋㅔ"

		)] = _T("케, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅋㅖ"

		)] = _T("켸, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅋㅘ"

		)] = _T("콰, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅋㅙ"

		)] = _T("쾌, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅋㅚ"

		)] = _T("쾨, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅋㅝ"

		)] = _T("쿼, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅋㅞ"

		)] = _T("퀘, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅋㅟ"

		)] = _T("퀴, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅋㅢ"

		)] = _T("킈, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅌㅐ"

		)] = _T("태, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅌㅒ"

		)] = _T("턔, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅌㅔ"

		)] = _T("테, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅌㅖ"

		)] = _T("톄, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅌㅘ"

		)] = _T("톼, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅌㅙ"

		)] = _T("퇘, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅌㅚ"

		)] = _T("퇴, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅌㅝ"

		)] = _T("퉈, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅌㅞ"

		)] = _T("퉤, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅌㅟ"

		)] = _T("튀, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅌㅢ"

		)] = _T("틔, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅍㅐ"

		)] = _T("패, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅍㅒ"

		)] = _T("퍠, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅍㅔ"

		)] = _T("페, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅍㅖ"

		)] = _T("폐, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅍㅘ"

		)] = _T("퐈, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅍㅙ"

		)] = _T("퐤, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅍㅚ"

		)] = _T("푀, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅍㅝ"

		)] = _T("풔, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅍㅞ"

		)] = _T("풰, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅍㅟ"

		)] = _T("퓌, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅍㅢ"

		)] = _T("픠, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅎㅐ"

		)] = _T("해, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅎㅒ"

		)] = _T("햬, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅎㅔ"

		)] = _T("헤, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅎㅖ"

		)] = _T("혜, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅎㅘ"

		)] = _T("화, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅎㅙ"

		)] = _T("홰, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅎㅚ"

		)] = _T("회, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅎㅝ"

		)] = _T("훠, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅎㅞ"

		)] = _T("훼, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅎㅟ"

		)] = _T("휘, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅎㅢ"

		)] = _T("희, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄲㅐ"

		)] = _T("깨, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄲㅒ"

		)] = _T("꺠, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄲㅔ"

		)] = _T("께, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄲㅖ"

		)] = _T("꼐, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄲㅘ"

		)] = _T("꽈, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄲㅙ"

		)] = _T("꽤, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄲㅚ"

		)] = _T("꾀, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄲㅝ"

		)] = _T("꿔, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄲㅞ"

		)] = _T("꿰, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄲㅟ"

		)] = _T("뀌, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄲㅢ"

		)] = _T("끠, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄸㅐ"

		)] = _T("때, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄸㅒ"

		)] = _T("떄, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄸㅔ"

		)] = _T("떼, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄸㅖ"

		)] = _T("뗴, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄸㅘ"

		)] = _T("똬, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄸㅙ"

		)] = _T("뙈, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄸㅚ"

		)] = _T("뙤, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄸㅝ"

		)] = _T("뚸, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄸㅞ"

		)] = _T("뛔, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄸㅟ"

		)] = _T("뛰, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㄸㅢ"

		)] = _T("띄, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅃㅐ"

		)] = _T("빼, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅃㅒ"

		)] = _T("뺴, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅃㅔ"

		)] = _T("뻬, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅃㅖ"

		)] = _T("뼤, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅃㅘ"

		)] = _T("뽜, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅃㅙ"

		)] = _T("뽸, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅃㅚ"

		)] = _T("뾔, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅃㅝ"

		)] = _T("뿨, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅃㅞ"

		)] = _T("쀄, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅃㅟ"

		)] = _T("쀠, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅃㅢ"

		)] = _T("쁴, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅆㅐ"

		)] = _T("쌔, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅆㅒ"

		)] = _T("썌, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅆㅔ"

		)] = _T("쎄, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅆㅖ"

		)] = _T("쎼, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅆㅘ"

		)] = _T("쏴, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅆㅙ"

		)] = _T("쐐, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅆㅚ"

		)] = _T("쐬, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅆㅝ"

		)] = _T("쒀, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅆㅞ"

		)] = _T("쒜, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅆㅟ"

		)] = _T("쒸, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅆㅢ"

		)] = _T("씌, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅉㅐ"

		)] = _T("째, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅉㅒ"

		)] = _T("쨰, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅉㅔ"

		)] = _T("쩨, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅉㅖ"

		)] = _T("쪠, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅉㅘ"

		)] = _T("쫘, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅉㅙ"

		)] = _T("쫴, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅉㅚ"

		)] = _T("쬐, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅉㅝ"

		)] = _T("쭤, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅉㅞ"

		)] = _T("쮀, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅉㅟ"

		)] = _T("쮜, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("ㅉㅢ"

		)] = _T("쯰, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("가ㄱ"

		)] = _T("각, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("가ㄴ"

		)] = _T("간, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("가ㄷ"

		)] = _T("갇, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("가ㄹ"

		)] = _T("갈, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("가ㅁ"

		)] = _T("감, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("가ㅂ"

		)] = _T("갑, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("가ㅇ"

		)] = _T("강, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("나ㄱ"

		)] = _T("낙, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("나ㄴ"

		)] = _T("난, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("나ㄷ"

		)] = _T("낟, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("나ㄹ"

		)] = _T("날, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("나ㅁ"

		)] = _T("남, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("나ㅂ"

		)] = _T("납, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("나ㅇ"

		)] = _T("낭, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("다ㄱ"

		)] = _T("닥, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("다ㄴ"

		)] = _T("단, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("다ㄷ"

		)] = _T("닫, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("다ㄹ"

		)] = _T("달, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("다ㅁ"

		)] = _T("담, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("다ㅂ"

		)] = _T("답, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("다ㅇ"

		)] = _T("당, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("라ㄱ"

		)] = _T("락, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("라ㄴ"

		)] = _T("란, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("라ㄷ"

		)] = _T("랃, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("라ㄹ"

		)] = _T("랄, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("라ㅁ"

		)] = _T("람, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("라ㅂ"

		)] = _T("랍, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("라ㅇ"

		)] = _T("랑, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("마ㄱ"

		)] = _T("막, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("마ㄴ"

		)] = _T("만, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("마ㄷ"

		)] = _T("맏, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("마ㄹ"

		)] = _T("말, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("마ㅁ"

		)] = _T("맘, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("마ㅂ"

		)] = _T("맙, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("마ㅇ"

		)] = _T("망, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("바ㄱ"

		)] = _T("박, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("바ㄴ"

		)] = _T("반, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("바ㄷ"

		)] = _T("받, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("바ㄹ"

		)] = _T("발, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("바ㅁ"

		)] = _T("밤, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("바ㅂ"

		)] = _T("밥, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("바ㅇ"

		)] = _T("방, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("사ㄱ"

		)] = _T("삭, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("사ㄴ"

		)] = _T("산, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("사ㄷ"

		)] = _T("삳, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("사ㄹ"

		)] = _T("살, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("사ㅁ"

		)] = _T("삼, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("사ㅂ"

		)] = _T("삽, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("사ㅇ"

		)] = _T("상, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("아ㄱ"

		)] = _T("악, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("아ㄴ"

		)] = _T("안, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("아ㄷ"

		)] = _T("앋, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("아ㄹ"

		)] = _T("알, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("아ㅁ"

		)] = _T("암, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("아ㅂ"

		)] = _T("압, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("아ㅇ"

		)] = _T("앙, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("자ㄱ"

		)] = _T("작, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("자ㄴ"

		)] = _T("잔, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("자ㄷ"

		)] = _T("잗, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("자ㄹ"

		)] = _T("잘, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("자ㅁ"

		)] = _T("잠, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("자ㅂ"

		)] = _T("잡, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("자ㅇ"

		)] = _T("장, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("차ㄱ"

		)] = _T("착, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("차ㄴ"

		)] = _T("찬, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("차ㄷ"

		)] = _T("찯, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("차ㄹ"

		)] = _T("찰, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("차ㅁ"

		)] = _T("참, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("차ㅂ"

		)] = _T("찹, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("차ㅇ"

		)] = _T("창, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("카ㄱ"

		)] = _T("칵, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("카ㄴ"

		)] = _T("칸, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("카ㄷ"

		)] = _T("칻, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("카ㄹ"

		)] = _T("칼, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("카ㅁ"

		)] = _T("캄, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("카ㅂ"

		)] = _T("캅, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("카ㅇ"

		)] = _T("캉, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("타ㄱ"

		)] = _T("탁, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("타ㄴ"

		)] = _T("탄, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("타ㄷ"

		)] = _T("탇, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("타ㄹ"

		)] = _T("탈, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("타ㅁ"

		)] = _T("탐, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("타ㅂ"

		)] = _T("탑, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("타ㅇ"

		)] = _T("탕, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("파ㄱ"

		)] = _T("팍, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("파ㄴ"

		)] = _T("판, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("파ㄷ"

		)] = _T("팓, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("파ㄹ"

		)] = _T("팔, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("파ㅁ"

		)] = _T("팜, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("파ㅂ"

		)] = _T("팝, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("파ㅇ"

		)] = _T("팡, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("하ㄱ"

		)] = _T("학, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("하ㄴ"

		)] = _T("한, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("하ㄷ"

		)] = _T("핟, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("하ㄹ"

		)] = _T("할, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("하ㅁ"

		)] = _T("함, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("하ㅂ"

		)] = _T("합, , , , , , , , , , , , , , ");


	KoreanLanMap[_T("하ㅇ"

		)] = _T("항, , , , , , , , , , , , , , ");
}

std::vector<CString> CKeyBoardDlg::split(CString str)
{
	int length = str.GetLength();
	vector< CString >SplitOut;
	//////
	int i = 0;
	CString strGet;
	while (AfxExtractSubString(strGet, str, i++, _T(',')))
	{
		SplitOut.push_back(strGet);
	}
	return SplitOut;
	////
	//CString outstr = _T("");
	//for ( int i =0 ;i < length;i++)
	//{
	//	CString temp,first;
	//	temp = str.GetAt(i);
	//	first = str.GetAt(0);
	//	if ( first == "0")
	//	{
	//		if ( temp != ',')
	//		{
	//			outstr+=str.GetAt(i);
	//			if (i == length-1)
	//			{
	//				SplitOut.push_back(outstr);
	//			}
	//		}
	//		else
	//		{
	//			SplitOut.push_back(outstr);
	//			outstr = _T("");
	//		}
	//	} 
	//	else
	//	{
	//		CString temp2;
	//		temp2 = str.GetAt(i);
	//		if ( temp2 != ',')
	//		{
	//			SplitOut.push_back(temp2);
	//		}
	//	}
	//}
	//return SplitOut;
}
void CKeyBoardDlg::OnEnChangeEditZrh()
{
	Language();
}





void CKeyBoardDlg::FontSelect()
{
	GetDlgItem(IDC_MIAN_FONT1)->SetWindowText(splitOut[j1]);
	GetDlgItem(IDC_MIAN_FONT2)->SetWindowText(splitOut[j1 + 1]);
	GetDlgItem(IDC_MIAN_FONT3)->SetWindowText(splitOut[j1 + 2]);
	GetDlgItem(IDC_MIAN_FONT4)->SetWindowText(splitOut[j1 + 3]);
	GetDlgItem(IDC_MIAN_FONT5)->SetWindowText(splitOut[j1 + 4]);
	GetDlgItem(IDC_MIAN_FONT6)->SetWindowText(splitOut[j1 + 5]);
	GetDlgItem(IDC_MIAN_FONT7)->SetWindowText(splitOut[j1 + 6]);
	GetDlgItem(IDC_MIAN_FONT8)->SetWindowText(splitOut[j1 + 7]);
	GetDlgItem(IDC_MIAN_FONT9)->SetWindowText(splitOut[j1 + 8]);
	GetDlgItem(IDC_MIAN_FONT10)->SetWindowText(splitOut[j1 + 9]);
	GetDlgItem(IDC_MIAN_FONT11)->SetWindowText(splitOut[j1 + 10]);
	GetDlgItem(IDC_MIAN_FONT12)->SetWindowText(splitOut[j1 + 11]);
	GetDlgItem(IDC_MIAN_FONT13)->SetWindowText(splitOut[j1 + 12]);
	GetDlgItem(IDC_MIAN_FONT14)->SetWindowText(splitOut[j1 + 13]);
	GetDlgItem(IDC_MIAN_FONT15)->SetWindowText(splitOut[j1 + 14]);
}

void CKeyBoardDlg::FontNull()
{
	GetDlgItem(IDC_MIAN_FONT1)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_FONT2)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_FONT3)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_FONT4)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_FONT5)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_FONT6)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_FONT7)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_FONT8)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_FONT9)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_FONT10)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_FONT11)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_FONT12)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_FONT13)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_FONT14)->SetWindowText(_T(""));
	GetDlgItem(IDC_MIAN_FONT15)->SetWindowText(_T(""));
}

void CKeyBoardDlg::Language()
{
	switch (LanType)
	{
	case Chinese: 
		{	
			CString key;
			GetDlgItem(IDC_EDIT_ZRH)->GetWindowText(key);
			CString value = ChineseLanMap[key];
			if ( value == "" )
			{	
				splitOut = split(_T(" , , , , , , , , , , , , , , ,"));
				j1 = 0;
				i1 = 1;
				FontSelect();
				break;
			}
			else
			{
				j1 = 0;
				value +=_T(",");
				splitOut = split(value);
				if ( splitOut.size() < 16 )
				{
					i1 = 1;
				} 
				else if( splitOut.size() < 31)
				{
					i1 = 16;
				}
				else if( splitOut.size() < 46)
				{
					i1 = 31;
				}
				else
				{
					i1 = 46;
				}
				FontSelect();
				break;
			}
		}
	case Japanese:  
		{	
			CString key;
			GetDlgItem(IDC_EDIT_ZRH)->GetWindowText(key);
			CString value = JapaneseLanMap[key];
			if ( value == "" )
			{	
				splitOut = split(_T(" , , , , , , , , , , , , , , ,"));
				j1 = 0;
				i1 = 1;
				FontSelect();
				break;
			}
			else
			{
				j1 = 0;
				value +=_T(",");
				splitOut = split(value);
				if ( splitOut.size() < 16 )
				{
					i1 = 1;
				} 
				else if( splitOut.size() < 31)
				{
					i1 = 16;
				}
				else if( splitOut.size() < 46)
				{
					i1 = 31;
				}
				else
				{
					i1 = 46;
				}
				FontSelect();
				break;
			}
		}
	case Korean:   
		{
			CString key;
			GetDlgItem(IDC_EDIT_ZRH)->GetWindowText(key);
			CString value = KoreanLanMap[key];
			if ( value == "" )
			{	
				splitOut = split(_T(" , , , , , , , , , , , , , , ,"));
				j1 = 0;
				i1 = 1;
				FontSelect();
				break;
			}
			else
			{
				j1 = 0;
				value +=_T(",");
				splitOut = split(value);
				if ( splitOut.size() < 16 )
				{
					i1 = 1;
				} 
				else if( splitOut.size() < 31)
				{
					i1 = 16;
				}
				else if( splitOut.size() < 46)
				{
					i1 = 31;
				}
				else
				{
					i1 = 46;
				}
				FontSelect();
				break;
			}
		}
	}
}


void CKeyBoardDlg::OnBnClickedMainLeftpage()
{
	j1 = j1 - 15;

	if ( j1 >= 0 )
	{
		FontSelect();
	} 
	else if( j1 < 1 )
	{
		j1 = 0;
	}
}

void CKeyBoardDlg::OnBnClickedMainRightpage()
{
	j1 = j1 + 15;
	if ( j1 < i1  )
	{
		FontSelect();
	} 
	else if( j1 > i1 )
	{
		j1 = i1 - 1;
		j1 = j1 - 15;
	}
}

void CKeyBoardDlg::OnEnSetfocusEditInput()
{
	// TODO: 在此添加控件通知处理程序代码
	if ( LanType== Chinese  )
	{
		LanType = Chinese_others;
	}
	else if ( LanType== Japanese )
	{
		LanType = Japanese_others;
	} 
	else if ( LanType== Korean )
	{
		LanType = Korean_others;
	}
}

void CKeyBoardDlg::OnEnSetfocusEditZrh()
{
	// TODO: 在此添加控件通知处理程序代码
	if ( LanType== Chinese_others )
	{
		LanType = Chinese;
	}
	else if ( LanType== Japanese_others )
	{
		LanType = Japanese;
	} 
	else if ( LanType== Korean_others )
	{
		LanType = Korean;
	}

}

void CKeyBoardDlg::OnBnClickedMainFont1()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_FONT1)->GetWindowText(tempstr);
	this->setEditText_Font(tempstr);
	if (!(tempstr.Compare(_T("")) == 0 || tempstr.Compare(_T(" ")) == 0))//当文字按键不为空时，点击后m_zrh_edit清空
	{
		m_zrh_edit.SetWindowText(_T(""));
		FontNull();
	}
}
void CKeyBoardDlg::OnBnClickedMainFont2()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_FONT2)->GetWindowText(tempstr);
	this->setEditText_Font(tempstr);
	if (!(tempstr.Compare(_T("")) == 0 || tempstr.Compare(_T(" ")) == 0))//当文字按键不为空时，点击后m_zrh_edit清空
	{
		m_zrh_edit.SetWindowText(_T(""));
		FontNull();
	}
}
void CKeyBoardDlg::OnBnClickedMainFont3()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_FONT3)->GetWindowText(tempstr);
	this->setEditText_Font(tempstr);
	if (!(tempstr.Compare(_T("")) == 0 || tempstr.Compare(_T(" ")) == 0))//当文字按键不为空时，点击后m_zrh_edit清空
	{
		m_zrh_edit.SetWindowText(_T(""));
		FontNull();
	}
}
void CKeyBoardDlg::OnBnClickedMainFont4()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_FONT4)->GetWindowText(tempstr);
	this->setEditText_Font(tempstr);
	if (!(tempstr.Compare(_T("")) == 0 || tempstr.Compare(_T(" ")) == 0))//当文字按键不为空时，点击后m_zrh_edit清空
	{
		m_zrh_edit.SetWindowText(_T(""));
		FontNull();
	}
}
void CKeyBoardDlg::OnBnClickedMainFont5()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_FONT5)->GetWindowText(tempstr);
	this->setEditText_Font(tempstr);
	if (!(tempstr.Compare(_T("")) == 0 || tempstr.Compare(_T(" ")) == 0))//当文字按键不为空时，点击后m_zrh_edit清空
	{
		m_zrh_edit.SetWindowText(_T(""));
		FontNull();
	}
}
void CKeyBoardDlg::OnBnClickedMainFont6()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_FONT6)->GetWindowText(tempstr);
	this->setEditText_Font(tempstr);
	if (!(tempstr.Compare(_T("")) == 0 || tempstr.Compare(_T(" ")) == 0))//当文字按键不为空时，点击后m_zrh_edit清空
	{
		m_zrh_edit.SetWindowText(_T(""));
		FontNull();
	}
}
void CKeyBoardDlg::OnBnClickedMainFont7()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_FONT7)->GetWindowText(tempstr);
	this->setEditText_Font(tempstr);
	if (!(tempstr.Compare(_T("")) == 0 || tempstr.Compare(_T(" ")) == 0))//当文字按键不为空时，点击后m_zrh_edit清空
	{
		m_zrh_edit.SetWindowText(_T(""));
		FontNull();
	}
}
void CKeyBoardDlg::OnBnClickedMainFont8()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_FONT8)->GetWindowText(tempstr);
	this->setEditText_Font(tempstr);
	if (!(tempstr.Compare(_T("")) == 0 || tempstr.Compare(_T(" ")) == 0))//当文字按键不为空时，点击后m_zrh_edit清空
	{
		m_zrh_edit.SetWindowText(_T(""));
		FontNull();
	}
}
void CKeyBoardDlg::OnBnClickedMainFont9()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_FONT9)->GetWindowText(tempstr);
	this->setEditText_Font(tempstr);
	if (!(tempstr.Compare(_T("")) == 0 || tempstr.Compare(_T(" ")) == 0))//当文字按键不为空时，点击后m_zrh_edit清空
	{
		m_zrh_edit.SetWindowText(_T(""));
		FontNull();
	}
}
void CKeyBoardDlg::OnBnClickedMainFont10()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_FONT10)->GetWindowText(tempstr);
	this->setEditText_Font(tempstr);
	if (!(tempstr.Compare(_T("")) == 0 || tempstr.Compare(_T(" ")) == 0))//当文字按键不为空时，点击后m_zrh_edit清空
	{
		m_zrh_edit.SetWindowText(_T(""));
		FontNull();
	}
}
void CKeyBoardDlg::OnBnClickedMainFont11()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_FONT11)->GetWindowText(tempstr);
	this->setEditText_Font(tempstr);
	if (!(tempstr.Compare(_T("")) == 0 || tempstr.Compare(_T(" ")) == 0))//当文字按键不为空时，点击后m_zrh_edit清空
	{
		m_zrh_edit.SetWindowText(_T(""));
		FontNull();
	}
}
void CKeyBoardDlg::OnBnClickedMainFont12()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_FONT12)->GetWindowText(tempstr);
	this->setEditText_Font(tempstr);
	if (!(tempstr.Compare(_T("")) == 0 || tempstr.Compare(_T(" ")) == 0))//当文字按键不为空时，点击后m_zrh_edit清空
	{
		m_zrh_edit.SetWindowText(_T(""));
		FontNull();
	}
}
void CKeyBoardDlg::OnBnClickedMainFont13()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_FONT13)->GetWindowText(tempstr);
	this->setEditText_Font(tempstr);
	if (!(tempstr.Compare(_T("")) == 0 || tempstr.Compare(_T(" ")) == 0))//当文字按键不为空时，点击后m_zrh_edit清空
	{
		m_zrh_edit.SetWindowText(_T(""));
		FontNull();
	}
}
void CKeyBoardDlg::OnBnClickedMainFont14()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_FONT14)->GetWindowText(tempstr);
	this->setEditText_Font(tempstr);
	if (!(tempstr.Compare(_T("")) == 0 || tempstr.Compare(_T(" ")) == 0))//当文字按键不为空时，点击后m_zrh_edit清空
	{
		m_zrh_edit.SetWindowText(_T(""));
		FontNull();
	}
}
void CKeyBoardDlg::OnBnClickedMainFont15()
{
	CString tempstr;
	GetDlgItem(IDC_MIAN_FONT15)->GetWindowText(tempstr);
	this->setEditText_Font(tempstr);
	if (!(tempstr.Compare(_T("")) == 0 || tempstr.Compare(_T(" ")) == 0))//当文字按键不为空时，点击后m_zrh_edit清空
	{
		m_zrh_edit.SetWindowText(_T(""));
		FontNull();
	}
}



HBRUSH CKeyBoardDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	 //TODO:  在此更改 DC 的任何属性
	pDC->SetBkColor(m_BKcolor);	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return m_DlgBrush;
}
CString CKeyBoardDlg::disposeinputtext(CString inputtext)
{	
	if ( inputtext.Compare(_T("")) == 0 )
	{
		return inputtext;
	}
	//inputtext = _T("شصض");
	map<int,CString>textbyte;	
	for (int i = inputtext.GetLength();i > 0;i--)
	{
		CString cstr =inputtext.Mid(inputtext.GetLength() - i,1);
		CString tempstr = ConvertWCHARToHex(cstr,1);
		//textbyte[inputtext.GetLength() - i] = tempstr;
		textbyte[i-1] = tempstr;
	}//转为十六进制字符串

	CString outputtext = _T("");
	vector<CString>textarray;
	vector<CString>textunicodearray;
	vector<CString>arleft;
	map<int,CString>textstring1;
	//bool textbytearrayBoolean[textbyte.size()+2];
	map<int,bool>textbytearrayBoolean;
	for ( int i =0;i < textbyte.size()+2;i++)
	{
		textbytearrayBoolean[i] = false;
	}


	for ( int j = 0;j < textbyte.size();j++)
	{
		if ( ArabicLan(textbyte[j])=="" )
		{
			textbytearrayBoolean[j + 1] = false;
		} 
		else
		{
			textbytearrayBoolean[j + 1] = true;
		}
		textstring1[j] = ArabicLan(textbyte[j]);
	}

	for ( int n = 0;n < textstring1.size();n++ )
	{
		if ( textstring1[n] == "" )//不在变形列表的文字
		{
			CString valueStr = textbyte[n];
			if ( valueStr.Mid(1, 1) == _T("6") || valueStr.Mid(1, 2) == _T("FE") 
				|| valueStr.Mid(1, 3) == _T("FB"))//不在变形列表的阿拉伯文字
			{
				if ( n + 3 == textbyte.size()+2 )//在最后一列
				{
					arleft.push_back(_T("0x") + textbyte[n]);
					for ( int f = 0;f < arleft.size();f++)
					{
						textarray.push_back(arleft.at(f));		
					}
					arleft.clear();
				}
				else//不在最后一列
				{
					if ( textbytearrayBoolean[n] == true && textbytearrayBoolean[n + 2] == true )//空格
					{
						arleft.push_back(_T("0x") + textbyte[n]);
						for ( int f= 0;f < arleft.size();f++)
						{
							textarray.push_back(arleft.at(f));	
						}
						arleft.clear();
					}
					else
					{
						textarray.push_back(_T("0x") + textbyte[n]);//其他文字
					}
				}
			}
			else//不在变形列表的其他文字
			{
				if ( textbytearrayBoolean[n] == true && textbytearrayBoolean[n + 2] == true )//空格
				{
					arleft.push_back(_T("0x") + textbyte[n]);
					for ( int f= 0;f < arleft.size();f++)
					{
						textarray.push_back(arleft.at(f));	
					}
					arleft.clear();
				} 
				else
				{
					textarray.push_back(_T("0x") + textbyte[n]);//其他文字
				}
			}
		} 
		else//在变形列表
		{
			textunicodearray = split(textstring1[n]);
			if ( textbytearrayBoolean[n] == true && textbytearrayBoolean[n + 2] == true )
			{
				arleft.push_back(textunicodearray.at(2));
			} 
			else if( textbytearrayBoolean[n] == true && textbytearrayBoolean[n + 2] == false)
			{
				if ( n + 3 == textbyte.size()+2 )
				{
					arleft.push_back(textunicodearray.at(0));
					for ( int f= 0;f < arleft.size();f++)
					{
						textarray.push_back(arleft.at(f));
					}
					arleft.clear();
				} 
				else
				{
					if ( textbytearrayBoolean[n + 3] == true )
					{
						arleft.push_back(textunicodearray.at(0));
						for ( int f= 0;f < arleft.size();f++)
						{
							textarray.push_back(arleft.at(f));	
						}
						arleft.clear();
					}
					else
					{
						arleft.push_back(textunicodearray.at(0));
						for ( int f= 0;f < arleft.size();f++)
						{
							textarray.push_back(arleft.at(f));	
						}
						arleft.clear();
					}
				}
			}
			else if ( textbytearrayBoolean[n] == false && textbytearrayBoolean[n + 2] == true )
			{
				arleft.push_back(textunicodearray.at(1));
			}
			else if ( textbytearrayBoolean[n] == false && textbytearrayBoolean[n + 2] == false )
			{
				textarray.push_back(textunicodearray.at(3));
			}
		}
	}
	vector<CString>tempVec;
	for (int k = textarray.size(); k > 0;k-- )
	{
		tempVec.push_back(textarray.at(k-1));//倒置
	}
	for ( int m = 0; m < tempVec.size();m++)
	{
		outputtext = outputtext + HexStrToCString(tempVec[m]);
	}
	return outputtext;			
}



CString CKeyBoardDlg::ArabicLan(CString inputstring)
{
	CString outputstring = _T("");
	if (inputstring.Compare(_T("0621")) == 0|| inputstring.Compare(_T("FE80")) == 0 
		||inputstring.Compare(_T("FE80")) == 0 ||inputstring.Compare(_T("FE80")) == 0 ||inputstring.Compare(_T("FE80")) == 0) 
		outputstring = _T("0xFE80, 0xFE80, 0xFE80, 0xFE80");

	else if (inputstring.Compare(_T("0622")) == 0|| inputstring.Compare(_T("FE82")) == 0 
		||inputstring.Compare(_T("FE81")) == 0 ||inputstring.Compare(_T("FE82")) == 0 ||inputstring.Compare(_T("FE81")) == 0)
		outputstring = _T("0xFE82, 0xFE81, 0xFE82, 0xFE81");

	else if (inputstring.Compare(_T("0623")) == 0|| inputstring.Compare(_T("FE84")) == 0 
		||inputstring.Compare(_T("FE83")) == 0 ||inputstring.Compare(_T("FE84")) == 0 ||inputstring.Compare(_T("FE83")) == 0)
		outputstring = _T("0xFE84, 0xFE83, 0xFE84, 0xFE83");


	else if (inputstring.Compare(_T("0624")) == 0|| inputstring.Compare(_T("FE86")) == 0 
		||inputstring.Compare(_T("FE85")) == 0 ||inputstring.Compare(_T("FE86")) == 0 ||inputstring.Compare(_T("FE85")) == 0)
		outputstring = _T("0xFE86, 0xFE85, 0xFE86, 0xFE85");


	else if (inputstring.Compare(_T("0625")) == 0|| inputstring.Compare(_T("FE88")) == 0 
		||inputstring.Compare(_T("FE87")) == 0 ||inputstring.Compare(_T("FE88")) == 0 ||inputstring.Compare(_T("FE87")) == 0)
		outputstring = _T("0xFE88, 0xFE87, 0xFE88, 0xFE87");


	else if (inputstring.Compare(_T("0626")) == 0|| inputstring.Compare(_T("FE8A")) == 0 
		||inputstring.Compare(_T("FE8B")) == 0 ||inputstring.Compare(_T("FE8C")) == 0 ||inputstring.Compare(_T("FE89")) == 0)
		outputstring = _T("0xFE8A, 0xFE8B, 0xFE8C, 0xFE89");


	else if (inputstring.Compare(_T("0627")) == 0|| inputstring.Compare(_T("FE8E")) == 0 
		||inputstring.Compare(_T("FE8D")) == 0 ||inputstring.Compare(_T("FE8E")) == 0 ||inputstring.Compare(_T("FE8D")) == 0)
		outputstring = _T("0xFE8E, 0xFE8D, 0xFE8E, 0xFE8D");


	else if (inputstring.Compare(_T("0628")) == 0|| inputstring.Compare(_T("FE90")) == 0 
		||inputstring.Compare(_T("FE91")) == 0 ||inputstring.Compare(_T("FE92")) == 0 ||inputstring.Compare(_T("FE8F")) == 0)
		outputstring = _T("0xFE90, 0xFE91, 0xFE92, 0xFE8F");


	else if (inputstring.Compare(_T("0629")) == 0|| inputstring.Compare(_T("FE94")) == 0 
		||inputstring.Compare(_T("FE93")) == 0 ||inputstring.Compare(_T("FE94")) == 0 ||inputstring.Compare(_T("FE93")) == 0)
		outputstring = _T("0xFE94, 0xFE93, 0xFE94, 0xFE93");


	else if (inputstring.Compare(_T("062A")) == 0|| inputstring.Compare(_T("FE96")) == 0 
		||inputstring.Compare(_T("FE97")) == 0 ||inputstring.Compare(_T("FE98")) == 0 ||inputstring.Compare(_T("FE95")) == 0)
		outputstring = _T("0xFE96, 0xFE97, 0xFE98, 0xFE95");

	else if (inputstring.Compare(_T("062B")) == 0|| inputstring.Compare(_T("FE9A")) == 0 
		||inputstring.Compare(_T("FE9B")) == 0 ||inputstring.Compare(_T("FE9C")) == 0 ||inputstring.Compare(_T("FE99")) == 0)
		outputstring = _T("0xFE9A, 0xFE9B, 0xFE9C, 0xFE99");


	else if (inputstring.Compare(_T("062C")) == 0|| inputstring.Compare(_T("FE9E")) == 0 
		||inputstring.Compare(_T("FE9F")) == 0 ||inputstring.Compare(_T("FEA0")) == 0 ||inputstring.Compare(_T("FE9D")) == 0)
		outputstring = _T("0xFE9E, 0xFE9F, 0xFEA0, 0xFE9D");


	else if (inputstring.Compare(_T("062D")) == 0|| inputstring.Compare(_T("FEA2")) == 0 
		||inputstring.Compare(_T("FEA3")) == 0 ||inputstring.Compare(_T("FEA4")) == 0 ||inputstring.Compare(_T("FEA1")) == 0)
		outputstring = _T("0xFEA2, 0xFEA3, 0xFEA4, 0xFEA1");


	else if (inputstring.Compare(_T("062E")) == 0|| inputstring.Compare(_T("FEA6")) == 0 
		||inputstring.Compare(_T("FEA7")) == 0 ||inputstring.Compare(_T("FEA8")) == 0 ||inputstring.Compare(_T("FEA5")) == 0)
		outputstring = _T("0xFEA6, 0xFEA7, 0xFEA8, 0xFEA5");


	else if (inputstring.Compare(_T("062F")) == 0|| inputstring.Compare(_T("FEAA")) == 0 
		||inputstring.Compare(_T("FEA9")) == 0 ||inputstring.Compare(_T("FEAA")) == 0 ||inputstring.Compare(_T("FEA9")) == 0)
		outputstring = _T("0xFEAA, 0xFEA9, 0xFEAA, 0xFEA9");


	else if (inputstring.Compare(_T("0630")) == 0|| inputstring.Compare(_T("FEAC")) == 0 
		||inputstring.Compare(_T("FEAB")) == 0 ||inputstring.Compare(_T("FEAC")) == 0 ||inputstring.Compare(_T("FEAB")) == 0)
		outputstring = _T("0xFEAC, 0xFEAB, 0xFEAC, 0xFEAB");


	else if (inputstring.Compare(_T("0631")) == 0|| inputstring.Compare(_T("FEAE")) == 0 
		||inputstring.Compare(_T("FEAD")) == 0 ||inputstring.Compare(_T("FEAE")) == 0 ||inputstring.Compare(_T("FEAD")) == 0)
		outputstring = _T("0xFEAE, 0xFEAD, 0xFEAE, 0xFEAD");


	else if (inputstring.Compare(_T("0632")) == 0|| inputstring.Compare(_T("FEB0")) == 0 
		||inputstring.Compare(_T("FEAF")) == 0 ||inputstring.Compare(_T("FEB0")) == 0 ||inputstring.Compare(_T("FEAF")) == 0)
		outputstring = _T("0xFEB0, 0xFEAF, 0xFEB0, 0xFEAF");


	else if (inputstring.Compare(_T("0633")) == 0|| inputstring.Compare(_T("FEB2")) == 0 
		||inputstring.Compare(_T("FEB3")) == 0 ||inputstring.Compare(_T("FEB4")) == 0 ||inputstring.Compare(_T("FEB1")) == 0 )
		outputstring = _T("0xFEB2, 0xFEB3, 0xFEB4, 0xFEB1");


	else if (inputstring.Compare(_T("0634")) == 0|| inputstring.Compare(_T("FEB6")) == 0 
		||inputstring.Compare(_T("FEB7")) == 0 ||inputstring.Compare(_T("FEB8")) == 0 ||inputstring.Compare(_T("FEB5")) == 0 )
		outputstring = _T("0xFEB6, 0xFEB7, 0xFEB8, 0xFEB5");


	else if (inputstring.Compare(_T("0635")) == 0|| inputstring.Compare(_T("FEBA")) == 0 
		||inputstring.Compare(_T("FEBB")) == 0 ||inputstring.Compare(_T("FEBC")) == 0 ||inputstring.Compare(_T("FEB9")) == 0)
		outputstring = _T("0xFEBA, 0xFEBB, 0xFEBC, 0xFEB9");


	else if (inputstring.Compare(_T("0636")) == 0|| inputstring.Compare(_T("FEBE")) == 0 
		||inputstring.Compare(_T("FEBF")) == 0 ||inputstring.Compare(_T("FEC0")) == 0 ||inputstring.Compare(_T("FEBD")) == 0)
		outputstring = _T("0xFEBE, 0xFEBF, 0xFEC0, 0xFEBD");


	else if (inputstring.Compare(_T("0637")) == 0|| inputstring.Compare(_T("FEC2")) == 0 
		||inputstring.Compare(_T("FEC3")) == 0 ||inputstring.Compare(_T("FEC4")) == 0 ||inputstring.Compare(_T("FEC1")) == 0)
		outputstring = _T("0xFEC2, 0xFEC3, 0xFEC4, 0xFEC1");


	else if (inputstring.Compare(_T("0638")) == 0|| inputstring.Compare(_T("FEC6")) == 0 
		||inputstring.Compare(_T("FEC7")) == 0 ||inputstring.Compare(_T("FEC8")) == 0 ||inputstring.Compare(_T("FEC5")) == 0)
		outputstring = _T("0xFEC6, 0xFEC7, 0xFEC8, 0xFEC5");


	else if (inputstring.Compare(_T("0639")) == 0|| inputstring.Compare(_T("FECA")) == 0 
		||inputstring.Compare(_T("FECB")) == 0 ||inputstring.Compare(_T("FECC")) == 0 ||inputstring.Compare(_T("FEC9")) == 0)
		outputstring = _T("0xFECA, 0xFECB, 0xFECC, 0xFEC9");


	else if (inputstring.Compare(_T("063A")) == 0|| inputstring.Compare(_T("FECE")) == 0 
		||inputstring.Compare(_T("FECF")) == 0 ||inputstring.Compare(_T("FED0")) == 0 ||inputstring.Compare(_T("FECD")) == 0)
		outputstring = _T("0xFECE, 0xFECF, 0xFED0, 0xFECD");


	else if (inputstring.Compare(_T("063B")) == 0|| inputstring.Compare(_T("63B")) == 0 
		||inputstring.Compare(_T("63B")) == 0 ||inputstring.Compare(_T("63B")) == 0 ||inputstring.Compare(_T("63B")) == 0)
		outputstring = _T("0x63B, 0x63B, 0x63B, 0x63B");


	else if (inputstring.Compare(_T("063C")) == 0|| inputstring.Compare(_T("63C")) == 0 
		||inputstring.Compare(_T("63C")) == 0 ||inputstring.Compare(_T("63C")) == 0 ||inputstring.Compare(_T("63C")) == 0)
		outputstring = _T("0x63C, 0x63C, 0x63C, 0x63C");


	else if (inputstring.Compare(_T("063D")) == 0|| inputstring.Compare(_T("63D")) == 0 
		||inputstring.Compare(_T("63D")) == 0 ||inputstring.Compare(_T("63D")) == 0 ||inputstring.Compare(_T("63D")) == 0)
		outputstring = _T("0x63D, 0x63D, 0x63D, 0x63D");


	else if (inputstring.Compare(_T("063E")) == 0|| inputstring.Compare(_T("63E")) == 0 
		||inputstring.Compare(_T("63E")) == 0 ||inputstring.Compare(_T("63E")) == 0 ||inputstring.Compare(_T("63E")) == 0)
		outputstring = _T("0x63E, 0x63E, 0x63E, 0x63E");


	else if (inputstring.Compare(_T("063F")) == 0|| inputstring.Compare(_T("63F")) == 0 
		||inputstring.Compare(_T("63F")) == 0 ||inputstring.Compare(_T("63F")) == 0 ||inputstring.Compare(_T("63F")) == 0)
		outputstring = _T("0x63F, 0x63F, 0x63F, 0x63F");


	else if (inputstring.Compare(_T("0640")) == 0|| inputstring.Compare(_T("640")) == 0 
		||inputstring.Compare(_T("640")) == 0 ||inputstring.Compare(_T("640")) == 0 ||inputstring.Compare(_T("640")) == 0)
		outputstring = _T("0x640, 0x640, 0x640, 0x640");


	else if (inputstring.Compare(_T("0641")) == 0|| inputstring.Compare(_T("FED2")) == 0 
		||inputstring.Compare(_T("FED3")) == 0 ||inputstring.Compare(_T("FED4")) == 0 ||inputstring.Compare(_T("FED1")) == 0)
		outputstring = _T("0xFED2, 0xFED3, 0xFED4, 0xFED1");


	else if (inputstring.Compare(_T("0642")) == 0|| inputstring.Compare(_T("FED6")) == 0 
		||inputstring.Compare(_T("FED7")) == 0 ||inputstring.Compare(_T("FED8")) == 0 ||inputstring.Compare(_T("FED5")) == 0)
		outputstring = _T("0xFED6, 0xFED7, 0xFED8, 0xFED5");


	else if (inputstring.Compare(_T("0643")) == 0|| inputstring.Compare(_T("FEDA")) == 0 
		||inputstring.Compare(_T("FEDB")) == 0 ||inputstring.Compare(_T("FEDC")) == 0 ||inputstring.Compare(_T("FED9")) == 0)
		outputstring = _T("0xFEDA, 0xFEDB, 0xFEDC, 0xFED9");


	else if (inputstring.Compare(_T("0644")) == 0|| inputstring.Compare(_T("FEDE")) == 0 
		||inputstring.Compare(_T("FEDF")) == 0 ||inputstring.Compare(_T("FEE0")) == 0 ||inputstring.Compare(_T("FEDD")) == 0)
		outputstring = _T("0xFEDE, 0xFEDF, 0xFEE0, 0xFEDD");


	else if (inputstring.Compare(_T("0645")) == 0|| inputstring.Compare(_T("FEE2")) == 0 
		||inputstring.Compare(_T("FEE3")) == 0 ||inputstring.Compare(_T("FEE4")) == 0 ||inputstring.Compare(_T("FEE1")) == 0)
		outputstring = _T("0xFEE2, 0xFEE3, 0xFEE4, 0xFEE1");


	else if (inputstring.Compare(_T("0646")) == 0|| inputstring.Compare(_T("FEE6")) == 0 
		||inputstring.Compare(_T("FEE7")) == 0 ||inputstring.Compare(_T("FEE8")) == 0 ||inputstring.Compare(_T("FEE5")) == 0)
		outputstring = _T("0xFEE6, 0xFEE7, 0xFEE8, 0xFEE5");


	else if (inputstring.Compare(_T("0647")) == 0|| inputstring.Compare(_T("FEEA")) == 0 
		||inputstring.Compare(_T("FEEB")) == 0 ||inputstring.Compare(_T("FEEC")) == 0 ||inputstring.Compare(_T("FEE9")) == 0)
		outputstring = _T("0xFEEA, 0xFEEB, 0xFEEC, 0xFEE9");


	else if (inputstring.Compare(_T("0648")) == 0|| inputstring.Compare(_T("FEEE")) == 0 
		||inputstring.Compare(_T("FEED")) == 0 ||inputstring.Compare(_T("FEEE")) == 0 ||inputstring.Compare(_T("FEED")) == 0)
		outputstring = _T("0xFEEE, 0xFEED, 0xFEEE, 0xFEED");


	else if (inputstring.Compare(_T("0649")) == 0 ||inputstring.Compare(_T("FEF0")) == 0 ||
		inputstring.Compare(_T("FEF3")) == 0 || inputstring.Compare(_T("FEF4")) == 0 || inputstring.Compare(_T("FEEF")) == 0)
		outputstring = _T("0xFEF0, 0xFEF3, 0xFEF4, 0xFEEF");


	else if (inputstring.Compare(_T("064A")) == 0 || inputstring.Compare(_T("FEF2")) == 0 
		||inputstring.Compare(_T("FEF3")) == 0 ||inputstring.Compare(_T("FEF4")) == 0 ||inputstring.Compare(_T("FEF1")) == 0)
		outputstring = _T("0xFEF2, 0xFEF3, 0xFEF4, 0xFEF1");
	return outputstring;
}

void CKeyBoardDlg::W2C(wchar_t w_cn , char c_cn[])
{
	c_cn[0] = w_cn >> 8 ;
	c_cn[1] = (char)w_cn ;
}
CString CKeyBoardDlg::ConvertWCHARToHex(CString Data, long nDataLength)
{
	CString sResult("");
	for (long nLoop=0; nLoop<nDataLength; nLoop++)
	{
		wchar_t ch= Data.GetAt(nLoop);//将wchar_t转换为char[2]
		char c_cn[2]={'0'};
		W2C(ch,c_cn);
		static const char *hex = "0123456789ABCDEF";
		for(int i=0;i<2;i++)
		{
			unsigned char chHexA = hex[((unsigned char)(c_cn[i]) >> 4) & 0x0f];
			unsigned char chHexB = hex[(unsigned char)(c_cn[i]) & 0x0f];
			sResult += (char)chHexA;
			sResult += (char)chHexB;
		}
	}
	return sResult;
}

CString CKeyBoardDlg::HexStrToCString(CString HexStr)
{
	HexStr = _T(" ")+HexStr;
	wchar_t* buf = new wchar_t[2];
	memset(buf, 0, sizeof(wchar_t)*(2));

	TCHAR seps[] = _T(" ");
	TCHAR* token = _tcstok(HexStr.GetBuffer(HexStr.GetLength()), seps);
	while(NULL != token)
	{
		buf[0] = _tcstoul(token, NULL, 16);
		token = _tcstok(NULL, seps);
	}
	HexStr.ReleaseBuffer();
	CString outstr(buf);
	delete[] buf;
	buf = NULL;
	return outstr;
}
void CKeyBoardDlg::OnEnChangeEditInput()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	CString inputtext = _T("");
	m_edit_input.GetWindowText(inputtext);
	if ( LanType == Arabic ||LantypeReverse == Arabic)
	{
		CString outputtext = disposeinputtext(inputtext);
		if ( outputtext != inputtext )
		{
			m_edit_input.SetWindowText(outputtext);
		}
	}
	int a;
	a += 1;
}
