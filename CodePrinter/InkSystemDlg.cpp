// InkSystemDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "InkSystemDlg.h"
#include "Inksystemconfig.h"
#include "CodePrinterDlg.h"



// CInkSystemDlg 对话框

IMPLEMENT_DYNAMIC(CInkSystemDlg, CDialog)

CInkSystemDlg::CInkSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInkSystemDlg::IDD, pParent)
	
	, m_Pumpspeed(0)
	, m_InkTemp(0)
	, m_PrintheadTemp(0)
	, m_InkLev(0)
	, m_SolventLev(0)
	, m_TargetVisco(0)
	, m_ActualVisco(0)
	, m_HighVol(0)
	, m_Inkflow("Normal")
{

}

CInkSystemDlg::~CInkSystemDlg()
{
}

void CInkSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_INK_CLOSE_BTN, m_returnIB);
	DDX_Control(pDX, IDC_USUAL_BTN, m_usualIB);
	DDX_Control(pDX, IDC_ADVANCE_BTN, m_advanceIB);
	DDX_Control(pDX, IDC_SETUP_BTN, m_setupIB);
	DDX_Control(pDX, IDC_PARAMETER_BTN, m_parameterIB);
	DDX_Control(pDX, IDC_PHASING_BTN, m_phasingIB);
	DDX_Control(pDX, IDC_INK_OK_BTN, m_okIB);
}


BEGIN_MESSAGE_MAP(CInkSystemDlg, CDialog)
	ON_BN_CLICKED(IDC_ADVANCE_BTN, &CInkSystemDlg::OnBnClickedAdvanceBtn)
	ON_BN_CLICKED(IDC_INK_CLOSE_BTN, &CInkSystemDlg::OnBnClickedInkCloseBtn)
	ON_BN_CLICKED(IDC_USUAL_BTN, &CInkSystemDlg::OnBnClickedUsualBtn)
	ON_BN_CLICKED(IDC_SETUP_BTN, &CInkSystemDlg::OnBnClickedSetupBtn)
	ON_BN_CLICKED(IDC_PARAMETER_BTN, &CInkSystemDlg::OnBnClickedParameterBtn)
	ON_BN_CLICKED(IDC_PHASING_BTN, &CInkSystemDlg::OnBnClickedPhasingBtn)
	ON_EN_CHANGE(IDC_PRESSURE_EDIT, &CInkSystemDlg::OnEnChangePressureEdit)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_SPEED_MODE_BTN, &CInkSystemDlg::OnBnClickedSpeedModeBtn)
	ON_BN_CLICKED(IDC_PRESSURE_MODE_BTN, &CInkSystemDlg::OnBnClickedPressureModeBtn)
	ON_BN_CLICKED(IDC_PUMP_BTN, &CInkSystemDlg::OnBnClickedPumpBtn)
	ON_BN_CLICKED(IDC_BLEED_VALVE_BTN, &CInkSystemDlg::OnBnClickedBleedValveBtn)
	ON_BN_CLICKED(IDC_WASH_VALVE_BTN, &CInkSystemDlg::OnBnClickedWashValveBtn)
	ON_BN_CLICKED(IDC_NOZZLE_VALVE_BTN, &CInkSystemDlg::OnBnClickedNozzleValveBtn)
	ON_BN_CLICKED(IDC_FEED_VALVE_BTN, &CInkSystemDlg::OnBnClickedFeedValveBtn)
	ON_BN_CLICKED(IDC_SOLVENT_VALVE_BTN, &CInkSystemDlg::OnBnClickedSolventValveBtn)
	ON_BN_CLICKED(IDC_VISCO_VALVE_BTN, &CInkSystemDlg::OnBnClickedViscoValveBtn)
	ON_BN_CLICKED(IDC_FLUSH_VALVE_BTN, &CInkSystemDlg::OnBnClickedFlushValveBtn)
	ON_BN_CLICKED(IDC_INK_OK_BTN, &CInkSystemDlg::OnBnClickedInkOkBtn)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CInkSystemDlg 消息处理程序

BOOL CInkSystemDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_inkAdv = new CInkAdvanceDlg;
	m_setup = new CInkSetupDlg;
	m_par = new CInkParDlg;
	m_phas = new CInkPhasingDlg;

	int nX = 0;
	int nY = 100;
	int nWidth = 800;
	int nHeight = 500-nY; //不能遮住下面的一排按钮

	m_inkAdv->Create(IDD_INK_ADVANCE_DIALOG,this);
	m_inkAdv->MoveWindow(nX+300,nY,nWidth,nHeight);

	m_setup->Create(IDD_INK_SETUP_DIALOG,this);
	m_setup->MoveWindow(nX,nY,nWidth,nHeight);

	m_par->Create(IDD_INK_PAR_DIALOG,this);
	m_par->MoveWindow(nX,nY,nWidth,nHeight);
	
	m_phas->Create(IDD_INK_PHASING_DIALOG,this);
	m_phas->MoveWindow(nX,nY,nWidth,nHeight);

	m_inkAdv->ShowWindow(SW_HIDE);
	m_setup->ShowWindow(SW_HIDE);
	m_par->ShowWindow(SW_HIDE);
	m_phas->ShowWindow(SW_HIDE);
    
	GetDlgItem(IDC_SPEED_MODE_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);//泵速模式
	m_CIB_SpeedMode.Attach(IDC_SPEED_MODE_BTN,this);
	GetDlgItem(IDC_PRESSURE_MODE_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);//压力模式
	m_CIB_PressureMode.Attach(IDC_PRESSURE_MODE_BTN,this);
	GetDlgItem(IDC_PUMP_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);//开关泵
	m_CIB_Pump.Attach(IDC_PUMP_BTN,this);
	GetDlgItem(IDC_NOZZLE_VALVE_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);//开关喷嘴
	m_CIB_NozzleValve.Attach(IDC_NOZZLE_VALVE_BTN,this);
	GetDlgItem(IDC_FEED_VALVE_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);  //开关供墨阀
	m_CIB_FeedValve.Attach(IDC_FEED_VALVE_BTN,this);
	GetDlgItem(IDC_BLEED_VALVE_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);//开关排气阀
	m_CIB_BleedValve.Attach(IDC_BLEED_VALVE_BTN,this);	
	GetDlgItem(IDC_FLUSH_VALVE_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);//开关清洗阀
	m_CIB_FlushValve.Attach(IDC_FLUSH_VALVE_BTN,this);
	GetDlgItem(IDC_SOLVENT_VALVE_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);//开关溶剂阀
	m_CIB_SolventValve.Attach(IDC_SOLVENT_VALVE_BTN,this);
	GetDlgItem(IDC_VISCO_VALVE_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);//开关粘度阀
	m_CIB_ViscoValve.Attach(IDC_VISCO_VALVE_BTN,this);
	GetDlgItem(IDC_WASH_VALVE_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);//冲洗
	m_CIB_WashValve.Attach(IDC_WASH_VALVE_BTN,this);

	//CRect rect1;
	//GetDlgItem(IDC_INK_CLOSE_BTN)->GetWindowRect(&rect1);

	//GetDlgItem(IDC_INK_CLOSE_BTN)->SetWindowPos(NULL,11,430,80,55,SWP_SHOWWINDOW);//IDC_SYSTEM_CANCEL_BTN
	//GetDlgItem(IDC_USUAL_BTN)->SetWindowPos(NULL,200,440,80,55,SWP_SHOWWINDOW);
	//GetDlgItem(IDC_ADVANCE_BTN)->SetWindowPos(NULL,300,440,80,55,SWP_SHOWWINDOW);
	//GetDlgItem(IDC_SETUP_BTN)->SetWindowPos(NULL,400,440,80,55,SWP_SHOWWINDOW);
	//GetDlgItem(IDC_PARAMETER_BTN)->SetWindowPos(NULL,500,440,80,55,SWP_SHOWWINDOW);
	//GetDlgItem(IDC_PHASING_BTN)->SetWindowPos(NULL,600,440,80,55,SWP_SHOWWINDOW);
	//GetDlgItem(IDC_INK_OK_BTN)->SetWindowPos(NULL,720,430,80,55,SWP_SHOWWINDOW);

	m_returnIB.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RETURN1_BITMAP);
	m_returnIB.SizeToContent(); 

	//待添加彩色图片
	m_usualIB.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_80_55_BITMAP,true);
	m_usualIB.SizeToContent(); 
	m_advanceIB.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_80_55_BITMAP,true);
	m_advanceIB.SizeToContent(); 
	m_setupIB.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_80_55_BITMAP,true);
	m_setupIB.SizeToContent(); 
	m_parameterIB.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_80_55_BITMAP,true);
	m_parameterIB.SizeToContent(); 
	m_phasingIB.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_80_55_BITMAP,true);
	m_phasingIB.SizeToContent(); 

	m_okIB.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_OK1_BITMAP);
	m_okIB.SizeToContent(); 

	//数字键盘初始化
	//pNumKey = new CNumKey();
	//pNumKey->Create( IDD_DIALOG_NUMKEY,this);  
	//pNumKey->ShowWindow(SW_HIDE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}	     

void CInkSystemDlg::showInkDlg(int ID)
{
	m_inkAdv->ShowWindow(SW_HIDE);
	m_setup->ShowWindow(SW_HIDE);
	m_par->ShowWindow(SW_HIDE);
	m_phas->ShowWindow(SW_HIDE);

	if (ID == IDD_INK_ADVANCE_DIALOG)
	{
		m_inkAdv->ShowWindow(SW_SHOW);
		((CCodePrinterDlg*)GetParent())->m_PicHead.SetOperationString(_T("Ink System > Adv")); 
	}
	else if (ID == IDD_INK_SETUP_DIALOG)
	{
		m_setup->ShowWindow(SW_SHOW);
		((CCodePrinterDlg*)GetParent())->m_PicHead.SetOperationString(_T("Ink System > Setup")); 
	}
	else if (ID == IDD_INK_PAR_DIALOG)
	{
		m_par->ShowWindow(SW_SHOW);
		((CCodePrinterDlg*)GetParent())->m_PicHead.SetOperationString(_T("Ink System > Param"));
	}
	else if (ID == IDD_INK_PHASING_DIALOG)
	{
		m_phas->ShowWindow(SW_SHOW);
		((CCodePrinterDlg*)GetParent())->m_PicHead.SetOperationString(_T("Ink System > Phase")); 
	}	 
}

void CInkSystemDlg::OnBnClickedInkCloseBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
	showInkDlg(0);
	((CCodePrinterDlg*)GetParent())->m_PicHead.ShowLogo(true); 

}

void CInkSystemDlg::OnBnClickedAdvanceBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	showInkDlg(IDD_INK_ADVANCE_DIALOG);
}


void CInkSystemDlg::OnBnClickedUsualBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	showInkDlg(0);
}

void CInkSystemDlg::OnBnClickedSetupBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	showInkDlg(IDD_INK_SETUP_DIALOG);
}

void CInkSystemDlg::OnBnClickedParameterBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	showInkDlg(IDD_INK_PAR_DIALOG);
}

void CInkSystemDlg::OnBnClickedPhasingBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	showInkDlg(IDD_INK_PHASING_DIALOG);
}


void CInkSystemDlg::OnEnChangePressureEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	// TODO:  在此添加控件通知处理程序代码
   
	//SetDlgItemText(IDC_PRESSURE_EDIT,_T("11"));
}


//泵速模式
void CInkSystemDlg::OnBnClickedSpeedModeBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.myStatusClass.ctr0X00bit2=(theApp.myStatusClass.ctr0X00bit2==1?0:1);
	theApp.myStatusClass.download_inksystem_control00();
}
//压力模式
void CInkSystemDlg::OnBnClickedPressureModeBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.myStatusClass.ctr0X00bit2 = (theApp.myStatusClass.ctr0X00bit2==1?0:1);
	theApp.myStatusClass.download_inksystem_control00();
}
//泵
void CInkSystemDlg::OnBnClickedPumpBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.myStatusClass.ctr0X00bit3 = (theApp.myStatusClass.ctr0X00bit3==1?0:1);
	theApp.myStatusClass.download_inksystem_control00();
}
//排气阀
void CInkSystemDlg::OnBnClickedBleedValveBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.myStatusClass.ctr0X01bit2 = (theApp.myStatusClass.ctr0X01bit2==1?0:1);
	theApp.myStatusClass.download_inksystem_control01();
}
//冲洗阀
void CInkSystemDlg::OnBnClickedWashValveBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.myStatusClass.ctr0X01bit6 = (theApp.myStatusClass.ctr0X01bit6==1?0:1);
	theApp.myStatusClass.download_inksystem_control01();
}
//喷嘴阀
void CInkSystemDlg::OnBnClickedNozzleValveBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.myStatusClass.ctr0X01bit0 = (theApp.myStatusClass.ctr0X01bit0==1?0:1);
	theApp.myStatusClass.download_inksystem_control01();
}
//供墨阀
void CInkSystemDlg::OnBnClickedFeedValveBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.myStatusClass.ctr0X01bit1 = (theApp.myStatusClass.ctr0X01bit1==1?0:1);
	theApp.myStatusClass.download_inksystem_control01();
}
//溶剂阀
void CInkSystemDlg::OnBnClickedSolventValveBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.myStatusClass.ctr0X01bit4 = (theApp.myStatusClass.ctr0X01bit4==1?0:1);
	theApp.myStatusClass.download_inksystem_control01();
}
//粘度阀
void CInkSystemDlg::OnBnClickedViscoValveBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.myStatusClass.ctr0X01bit5 = (theApp.myStatusClass.ctr0X01bit5==1?0:1);
	theApp.myStatusClass.download_inksystem_control01();
}
//清洗阀
void CInkSystemDlg::OnBnClickedFlushValveBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.myStatusClass.ctr0X01bit3 = (theApp.myStatusClass.ctr0X01bit3==1?0:1);
	theApp.myStatusClass.download_inksystem_control01();
}

void CInkSystemDlg::OnBnClickedInkOkBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	CInksystemconfig pInksysConfig((CCodePrinterDlg*)(this->GetParent()));
	pInksysConfig.save_inksystem_to_xml();
// 	pInksysConfig.get_inksystem_from_xml();
	pInksysConfig.download_inksystem_setup();
	pInksysConfig.download_inksystem_parameter();
}
 
HBRUSH CInkSystemDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

