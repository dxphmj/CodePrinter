// InkSetupDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "InkSetupDlg.h"


// CInkSetupDlg 对话框

IMPLEMENT_DYNAMIC(CInkSetupDlg, CDialog)

CInkSetupDlg::CInkSetupDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInkSetupDlg::IDD, pParent)
	, m_nextService(0)
	, m_inkLifeTime(0)
{

}

CInkSetupDlg::~CInkSetupDlg()
{
}

void CInkSetupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NEXT_SERVICE_EDIT, m_nextService);
	DDX_Text(pDX, IDC_INK_LIFE_TIME_EDIT, m_inkLifeTime);
	DDX_Control(pDX, IDC_SIZE_LIST, m_sizeList);
	DDX_Control(pDX, IDC_MODUL_FRE_LIST, m_modulFreList);
	DDX_Control(pDX, IDC_INK_TYPE_LIST, m_inkTypeList);
	DDX_Control(pDX, IDC_PELTIER_LIST, m_peltierList);
	DDX_Control(pDX, IDC_SLEEP_LIST, m_sleepList);
	DDX_Control(pDX, IDC_SOLVENT_CALIB_BTN, m_solventCalibIB);
	DDX_Control(pDX, IDC_INK_CALIB_BTN, m_inkCalibIB);
	DDX_Control(pDX, IDC_NEXT_SERVICE_EDIT, m_nextSer);
	DDX_Control(pDX, IDC_INK_LIFE_TIME_EDIT, m_inkLifeT);
	DDX_Control(pDX, IDC_INK_SETUP_SIZE_STATIC, m_setupSizeStatic);
	DDX_Control(pDX, IDC_INK_SETUP_RATE_STATIC, m_setupRateStatic);
	DDX_Control(pDX, IDC_INK_SETUP_INKTYPE_STATIC, m_setupInkTypeStatic);
	DDX_Control(pDX, IDC_INK_SETUP_CON_STATIC, m_setupConStatic);
	DDX_Control(pDX, IDC_INK_SETUP_SLEEPMODE_STATIC, m_setupSleepModeStatic);
	DDX_Control(pDX, IDC_INK_SETUP_TIMERESET_STATIC, m_setupTimeResetStatic);
	DDX_Control(pDX, IDC_INK_SETUP_NEXTTIME_STATIC, m_setupNextTimeStatic);
	DDX_Control(pDX, IDC_INK_SETUP_LASTTIME_STATIC, m_setupLastTimeStatic);
	DDX_Control(pDX, IDC_INKSETUP_SOL_LEV_JUST_STATIC, m_setupSolLevStatic);
	DDX_Control(pDX, IDC_INK_SETUP_INK_LEV_JUSTSTATIC, m_setupInkLevStatic);
	DDX_Control(pDX, IDC_STATIC_TIMEREST_SETUP, m_timeResetStatic);
}


BEGIN_MESSAGE_MAP(CInkSetupDlg, CDialog)
	ON_WM_CTLCOLOR()

END_MESSAGE_MAP()


// CInkSetupDlg 消息处理程序

BOOL CInkSetupDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_sizeList.AddString(L"40");
	m_sizeList.AddString(L"50");
	m_sizeList.AddString(L"60");
	m_sizeList.SetCurSel(2);
	m_sizeList.SetItemHeight(0,20);

	m_modulFreList.AddString(L"64000");
	m_modulFreList.AddString(L"78000");
	m_modulFreList.AddString(L"96000");
	m_modulFreList.SetCurSel(0);
	m_modulFreList.SetItemHeight(0,20);

	m_inkTypeList.AddString(L"236");
	m_inkTypeList.AddString(L"252");
	m_inkTypeList.AddString(L"261");
	m_inkTypeList.AddString(L"270");
	m_inkTypeList.AddString(L"445");
	m_inkTypeList.SetCurSel(0);
	m_inkTypeList.SetItemHeight(0,20);

	m_peltierList.AddString(L"OFF");
	m_peltierList.AddString(L"ON");
	m_peltierList.SetCurSel(0);
	m_peltierList.SetItemHeight(0,20);

	m_sleepList.AddString(L"OFF");
	m_sleepList.AddString(L"ON");
	m_sleepList.SetCurSel(0);
	m_sleepList.SetItemHeight(0,20);

	m_nextSer.SetFont(theApp.m_EditFont);
	m_inkLifeT.SetFont(theApp.m_EditFont);

//	GetDlgItem(IDC_SOLVENT_CALIB_BTN)->SetWindowPos(NULL,605,252,70,45,SWP_SHOWWINDOW); 
//	GetDlgItem(IDC_INK_CALIB_BTN)->SetWindowPos(NULL,605,313,70,45,SWP_SHOWWINDOW);

	m_solventCalibIB.LoadBitmaps(IDB_SOLVENT_CALIB1_BITMAP,IDB_SOLVENT_CALIB2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_solventCalibIB.SizeToContent(); 
	m_inkCalibIB.LoadBitmaps(IDB_SOLVENT_CALIB1_BITMAP,IDB_SOLVENT_CALIB2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_inkCalibIB.SizeToContent(); 
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

 
HBRUSH CInkSetupDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

    if(nCtlColor == CTLCOLOR_STATIC)
	{		 
		pDC->SelectObject(theApp.m_StaticFont);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));	
		return theApp.m_StaticBrush;
	} 
	 if(nCtlColor == CTLCOLOR_EDIT)
	{		 
	// 	pDC->SelectObject(theApp.m_EditFont);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));	
		return theApp.m_StaticBrush;
	} 
 	if(nCtlColor == CTLCOLOR_LISTBOX)
	{
		pDC->SelectObject(theApp.m_ListBoxFont);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));	
		return theApp.m_ListBoxBrush;
	}
	// TODO:  在此更改 DC 的任何属性
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return theApp.m_DlgBrush;
}
