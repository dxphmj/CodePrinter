// InkSystemDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "InkSystemDlg.h"


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
//	DDX_Text(pDX, IDC_PRESSURE_EDIT, m_Pressure);
	DDX_Text(pDX, IDC_PUMP_SPEED_EDIT, m_Pumpspeed);
	DDX_Text(pDX, IDC_INK_TEMP_EDIT, m_InkTemp);
	DDX_Text(pDX, IDC_PRINTHEAD_TEMP_EDIT, m_PrintheadTemp);
	DDX_Text(pDX, IDC_INK_LEV_EDIT, m_InkLev);
	DDX_Text(pDX, IDC_SOLVENT_LEV_EDIT, m_SolventLev);
	DDX_Text(pDX, IDC_TARGET_VISCO_EDIT, m_TargetVisco);
	DDX_Text(pDX, IDC_ACTUAL_VISCO_EDIT, m_ActualVisco);
	DDX_Text(pDX, IDC_HIGH_VOL_EDIT, m_HighVol);
	DDX_Text(pDX, IDC_INKFLOW_EDIT, m_Inkflow);
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

	m_inkAdv->Create(IDD_INK_ADVANCE_DIALOG,this);
	m_inkAdv->MoveWindow(300,20,450,400);

	int nX = 0;
	int nY = 0;
	int nWidth = 800;
	int nHeight = 400;
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
    SetTimer(TIMER1,1000,NULL);

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
	}
	if (ID == IDD_INK_SETUP_DIALOG)
	{
		m_setup->ShowWindow(SW_SHOW);
	}
	if (ID == IDD_INK_PAR_DIALOG)
	{
		m_par->ShowWindow(SW_SHOW);
	}
	if (ID == IDD_INK_PHASING_DIALOG)
	{
		m_phas->ShowWindow(SW_SHOW);
	}
	if (0)
	{
		return;
	}


}

void CInkSystemDlg::OnBnClickedInkCloseBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
	showInkDlg(0);

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

void CInkSystemDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CDialog::OnTimer(nIDEvent);
	switch(nIDEvent)
		case TIMER1:
	{
		theApp.myStatusClass.byStatusFromSlaveState();
		theApp.myStatusClass.getstatu();
		
		
		GetDlgItem(IDC_PRESSURE_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myclassMessage.to_String(theApp.myStatusClass.staPressure)));
		GetDlgItem(IDC_PUMP_SPEED_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myclassMessage.to_String(theApp.myStatusClass.staBumSpe)));
		GetDlgItem(IDC_INK_TEMP_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myclassMessage.to_String(theApp.myStatusClass.staInkTem)));

		GetDlgItem(IDC_PRINTHEAD_TEMP_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myclassMessage.to_String(theApp.myStatusClass.staPriHeaTem)));
		GetDlgItem(IDC_INK_LEV_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myclassMessage.to_String(theApp.myStatusClass.staInkLev)));
		GetDlgItem(IDC_SOLVENT_LEV_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myclassMessage.to_String(theApp.myStatusClass.staSolLev)));
		GetDlgItem(IDC_TARGET_VISCO_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myclassMessage.to_String(theApp.myStatusClass.staTarVis)));
		GetDlgItem(IDC_ACTUAL_VISCO_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myclassMessage.to_String(theApp.myStatusClass.staTarVis)));
		GetDlgItem(IDC_HIGH_VOL_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myclassMessage.to_String(theApp.myStatusClass.staHigVol)));

		//m_Pressure=theApp.myStatusClass.staPressure;IDC_INKFLOW_EDIT
		//m_Pumpspeed=theApp.myStatusClass.staBumSpe;
		//m_InkTemp=theApp.myStatusClass.staInkTem;
		//m_PrintheadTemp=theApp.myStatusClass.staPriHeaTem;
		//m_InkLev=theApp.myStatusClass.staInkLev;       
		//m_SolventLev=theApp.myStatusClass.staSolLev;   
		//m_TargetVisco=theApp.myStatusClass.staTarVis;  
		//m_ActualVisco=theApp.myStatusClass.staActVis;  
		//m_HighVol=theApp.myStatusClass.staHigVol;
		
		break;
		//m_Inkflow=; 
			/*回收故障
		If staInkFloSenOff = True Then  '回收关
		staInkFloFau = False '回收故障
		labval_inksystem_ua_inkflow.Text = "Disable"
		Else
		If staInkFloFau = True And staInkFloFauLas = False Then
		staInkFloFauLas = True
		labval_onoff_name.Text = StartingUp
		labval_onoff_nameText = "Starting Up"
		ctr0X03bit0 = 0
		download_inksystem_control03()
		ctr0X00bit5 = 0
		ctr0X00bit3 = 0
		ctr0X00bit2 = 0
		ctr0X00bit1 = 1
		ctr0X00bit0 = 0
		download_inksystem_control00()
		If Not pangro_infor.Location.X = 126 Then
		pangro_infor.BringToFront()
		pangro_infor.Location = New Point(126, 244)
		labval_infor_mes.Text = "Recyle fault"
		End If
		lisbox_error_receive.Items.Add(Format(DateTime.Now, "yyyy/MM/dd") & Space(5) & Format(DateTime.Now, "HH:mm:ss") & Space(10) & "Red" & Space(13) & "Recyle fault")
		labval_inksystem_ua_inkflow.Text = "Abnormal"
		ElseIf staInkFloFau = False Then
		If staInkFloFauLas = True Then staInkFloFauLas = False
		labval_inksystem_ua_inkflow.Text = "Normal"
		End If
		End If
*/
	}
}


void CInkSystemDlg::OnBnClickedSpeedModeBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.myStatusClass.ctr0X00bit2=(theApp.myStatusClass.ctr0X00bit2==1?0:1);
	theApp.myStatusClass.download_inksystem_control00();


}
