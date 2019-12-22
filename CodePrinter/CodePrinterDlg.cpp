// CodePrinterDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "CodePrinterDlg.h"
#include "LabelDlg.h"
#include "FaultDlg.h"
#include "SystemDlg.h"
#include "UserDlg.h"
#include "ConfigurationDlg.h"
#include "FileManaDlg.h"
#include "InkSystemDlg.h"
#include <fstream>
#include "Inksystemconfig.h"

//#include "Tchar.h”
#include "PcfConfig.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCodePrinterDlg 对话框

CCodePrinterDlg::CCodePrinterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCodePrinterDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCodePrinterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FAULT_BUTTON, m_ButFault);
	DDX_Control(pDX, IDC_SYSTEM_BUTTON, m_ButSystem);
	DDX_Control(pDX, IDC_USER_BUTTON, m_ButUser);
	DDX_Control(pDX, IDC_LABEL_BUTTON, m_ButLabel);
	DDX_Control(pDX, IDC_CONFIGURATION_BUTTON, m_ButConfig);
	DDX_Control(pDX, IDC_FILEMANA_BUTTON, m_ButFileMana);
	DDX_Control(pDX, IDC_INK_BUTTON, m_ButInk);
	DDX_Control(pDX, IDC_ONOROFF_BUTTON, m_ButOnOrOff);
	DDX_Control(pDX, IDC_STARTPRINT_BUTTON, m_StartPrint);
	DDX_Control(pDX, IDC_PAUSEPRINT_BUTTON, m_PausePrint);
}

BEGIN_MESSAGE_MAP(CCodePrinterDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_LABEL_BUTTON, &CCodePrinterDlg::OnBnClickedLabelButton)
	ON_BN_CLICKED(IDC_FAULT_BUTTON, &CCodePrinterDlg::OnBnClickedFaultButton)
	ON_BN_CLICKED(IDC_SYSTEM_BUTTON, &CCodePrinterDlg::OnBnClickedSystemButton)
	ON_BN_CLICKED(IDC_USER_BUTTON, &CCodePrinterDlg::OnBnClickedUserButton)
	ON_BN_CLICKED(IDC_CONFIGURATION_BUTTON, &CCodePrinterDlg::OnBnClickedConfigurationButton)
	ON_BN_CLICKED(IDC_FILEMANA_BUTTON, &CCodePrinterDlg::OnBnClickedFilemanaButton)
	ON_BN_CLICKED(IDC_INK_BUTTON, &CCodePrinterDlg::OnBnClickedInkButton)
	ON_BN_CLICKED(IDC_ONOROFF_BUTTON, &CCodePrinterDlg::OnBnClickedOnoroffButton)
	ON_BN_CLICKED(IDC_STARTPRINT_BUTTON, &CCodePrinterDlg::OnBnClickedStartprintButton)
	ON_BN_CLICKED(IDC_PAUSEPRINT_BUTTON, &CCodePrinterDlg::OnBnClickedPauseprintButton)
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()

END_MESSAGE_MAP()


// CCodePrinterDlg 消息处理程序

BOOL CCodePrinterDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	 

    GetDlgItem(IDC_FAULT_BUTTON)->ModifyStyle(0,BS_OWNERDRAW,0);
	m_myButton.Attach(IDC_FAULT_BUTTON,this);
	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetWindowPos(NULL,0,0,800,600,SWP_SHOWWINDOW );	
	CRect rect;
	GetWindowRect(&rect);

	GetDlgItem(IDC_PRINT_STA_STATIC)->SetWindowText(_T("Shut Down"));
	


	m_Fault = new CFaultDlg;
	m_System = new CSystemDlg;
	m_User = new CUserDlg;
	m_Label = new CLabelDlg;
	m_Confi = new CConfigurationDlg;
	m_FileMan = new CFileManaDlg;
	m_Ink = new CInkSystemDlg;
	m_OnOff = new COnOffDlg;
	m_Fault = new CFaultDlg;


	//创建文件夹
	CreateDirectory(_T("Storage Card\\System\\Error"), NULL);
	CreateDirectory(_T("Storage Card\\User\\PrintConfig"), NULL);
	CreateDirectory(_T("Storage Card\\User\\Label"), NULL);
	CreateDirectory(_T("Storage Card\\User\\Logo"), NULL);
	CreateDirectory(_T("Storage Card\\User\\Font"), NULL);
	int nX = 0;
	int nY = 0;
	int nWidth = 800;
	int nHeight = 600;
	m_Fault->Create(IDD_FAULT_DIALOG,this);
	m_Fault->MoveWindow(nX,nY,nWidth,nHeight);

	m_System->Create(IDD_SYSTEM_DIALOG,this);
	m_System->MoveWindow(nX,nY,nWidth,nHeight);

	m_User->Create(IDD_USER_DIALOG,this);
	m_User->MoveWindow(nX,nY,nWidth,nHeight);

	m_Label->Create(IDD_LABEL_DIALOG,this);
	m_Label->MoveWindow(nX,nY,nWidth,nHeight);

	m_Confi->Create(IDD_CONFIGURATION_DIALOG,this);
	m_Confi->MoveWindow(nX,nY,nWidth,nHeight);

	m_FileMan->Create(IDD_FILEMANA_DIALOG,this);
	m_FileMan->MoveWindow(nX,nY,nWidth,nHeight);

	m_Ink->Create(IDD_INKSYSTEM_DIALOG,this);
	m_Ink->MoveWindow(nX,nY,nWidth,nHeight);
	
	m_OnOff->Create(IDD_ONOFF_DIALOG,this);
	m_OnOff->MoveWindow(200,200,300,200);

	
	//右侧一列设置按钮的位置及大小
	GetDlgItem(IDC_FAULT_BUTTON)->SetWindowPos(NULL,730,10,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_SYSTEM_BUTTON)->SetWindowPos(NULL,700,100,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_USER_BUTTON)->SetWindowPos(NULL,700,170,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_LABEL_BUTTON)->SetWindowPos(NULL,700,240,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_CONFIGURATION_BUTTON)->SetWindowPos(NULL,700,310,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_FILEMANA_BUTTON)->SetWindowPos(NULL,700,380,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_INK_BUTTON)->SetWindowPos(NULL,700,450,80,55,SWP_SHOWWINDOW);
	//下面两个按钮
	GetDlgItem(IDC_RESET_COUNT_BTN)->SetWindowPos(NULL,40,330,80,50,SWP_SHOWWINDOW);
	GetDlgItem(IDC_RESET_SERIAL_BTN)->SetWindowPos(NULL,360,330,80,50,SWP_SHOWWINDOW);
	//开机和喷印
	GetDlgItem(IDC_ONOROFF_BUTTON)->SetWindowPos(NULL,50,450,80,50,SWP_SHOWWINDOW);
	GetDlgItem(IDC_STARTPRINT_BUTTON)->SetWindowPos(NULL,280,420,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_PAUSEPRINT_BUTTON)->SetWindowPos(NULL,450,420,80,55,SWP_SHOWWINDOW);
	
	//彩色按钮
	m_ButFault.LoadBitmaps(IDB_FAULT_BITMAP,IDB_FAULT_BITMAP,0,0,IDB_FAULT_BITMAP);
	m_ButFault.SizeToContent(); 
	m_ButSystem.LoadBitmaps(IDB_SYSTEM_BITMAP,IDB_SYSTEM_BITMAP,0,0,IDB_SYSTEM_BITMAP);
	m_ButSystem.SizeToContent(); 
	m_ButUser.LoadBitmaps(IDB_USER_BITMAP,IDB_USER_BITMAP,0,0,IDB_USER_BITMAP);
	m_ButUser.SizeToContent(); 
	m_ButLabel.LoadBitmaps(IDB_LABEL_BITMAP,IDB_LABEL_BITMAP,0,0,IDB_LABEL_BITMAP);
	m_ButLabel.SizeToContent(); 
	m_ButConfig.LoadBitmaps(IDB_CONFIG_BITMAP,IDB_CONFIG_BITMAP,0,0,IDB_CONFIG_BITMAP);
	m_ButConfig.SizeToContent(); 
	m_ButFileMana.LoadBitmaps(IDB_FILEMANA_BITMAP,IDB_FILEMANA_BITMAP,0,0,IDB_FILEMANA_BITMAP);
	m_ButFileMana.SizeToContent(); 
	m_ButInk.LoadBitmaps(IDB_INKSYSTEM_BITMAP,IDB_INKSYSTEM_BITMAP,0,0,IDB_INKSYSTEM_BITMAP);
	m_ButInk.SizeToContent(); 
	m_ButOnOrOff.LoadBitmaps(IDB_ON_OR_OFF_BITMAP,IDB_ON_OR_OFF_BITMAP,0,0,IDB_ON_OR_OFF_BITMAP);
	m_ButOnOrOff.SizeToContent(); 
	m_StartPrint.LoadBitmaps(IDB_START_PRINT_BITMAP,IDB_START_PRINT_BITMAP,0,0,IDB_START_PRINT_BITMAP);
	m_StartPrint.SizeToContent(); 
	m_PausePrint.LoadBitmaps(IDB_PAUSE_PRINT_BITMAP,IDB_PAUSE_PRINT_BITMAP,0,0,IDB_PAUSE_PRINT_BITMAP);
	m_PausePrint.SizeToContent(); 

	
//#define  def_ttl 1

#ifdef def_ttl
	//串口初始化

	theApp.myModuleMain.InitCommMsg();
#endif

	//CTime localT=CTime::GetCurrentTime(); //时间类，以后日期用这个！！
	//string timeErr="Storage Card\\System\\Error\\";
	//timeErr=timeErr+theApp.myclassMessage.to_String(localT.GetYear())+theApp.myclassMessage.to_String(localT.GetMonth())+theApp.myclassMessage.to_String(localT.GetDay())+".txt";
	//ofstream timeErrout(timeErr.c_str(), ios::out |ios::trunc);
	//timeErrout.close();
	//ofstream out99("Storage Card\\System\\Error\\99999999.TXT", ios::out |ios::trunc);
	//out99.close();




	//墨水维护时间

	//错误日志相关

	//配置相关
	FILE *testFile;
	testFile=fopen("Storage Card\\System\\InkSystem.xml", "r");
	if (testFile)
	{
		fclose(testFile);
	}
	else
	{
		//createParaXML()
	}

	testFile=fopen("Storage Card\\System\\SoftSystem.xml", "r");
	if (testFile)
	{
		fclose(testFile);
	}
	else
	{
		//createSoftXML()
	}

	//多语言,根据softxml选择语言

	testFile=fopen("Storage Card\\System\\PrintConfig.xml", "r");
	if (testFile)
	{
		fclose(testFile);
	}
	else
	{
		//createPCFXML()
	}

	testFile=fopen("Storage Card\\System\\PrintMessage.xml", "r");
	if (testFile)
	{
		fclose(testFile);
	}
	else
	{
		theApp.myclassMessage.labName="Default.lab";
		theApp.myclassMessage.labPath="Storage Card\\User\\Label";
		theApp.myclassMessage.createLABXML();
	}
	delete testFile;

	//theApp.myStatusClass.download_inksystem_control03();


	//Sleep(10);
	//theApp.readCount=theApp.myCIOVsd.Read();
 //   theApp.TTLcom=AfxBeginThread(TTLcomLoop,NULL,THREAD_PRIORITY_HIGHEST);
////墨水配置初始化
	CInksystemconfig pInksysConfig(this);
	CPcfConfig pPcfConfig(this);




	//pInksysConfig.get_inksystem_from_xml();
	//pInksysConfig.download_inksystem_setup();
	pInksysConfig.get_inksystem_from_xml();
	pInksysConfig.download_inksystem_setup();
	pInksysConfig.download_inksystem_parameter();
	pPcfConfig.get_pcf_from_xml();




#ifdef def_ttl
	LPTSTR strTempCmd;
	BYTE readArr[8]={0x1,0x80,0x3,0x8f,0x0,0x25,0xaa,0x55};
	strTempCmd=(LPTSTR)readArr;	 

	Sleep(10);
	theApp.readCount=theApp.myCIOVsd.Read();
 
	theApp.TTLcom=AfxBeginThread(TTLcomLoop,NULL,THREAD_PRIORITY_HIGHEST);
	//定时器初始化 (不要在定时器后面初始化)
	SetTimer(TIMER1,1000,NULL);	

#endif 

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CCodePrinterDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_CODEPRINTER_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_CODEPRINTER_DIALOG));
	}
}
#endif

void CCodePrinterDlg::OnBnClickedLabelButton()
{
	// TODO: 在此添加控件通知处理程序代码
	showDlg(IDD_LABEL_DIALOG);
}

void CCodePrinterDlg::OnBnClickedFaultButton()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Fault->get_save_error();

	m_Fault->openfailurefile("Storage Card\\System\\Error\\99999999.txt");
	showDlg(IDD_FAULT_DIALOG);
}

void CCodePrinterDlg::OnBnClickedSystemButton()
{
	// TODO: 在此添加控件通知处理程序代码
	showDlg(IDD_SYSTEM_DIALOG);
}

void CCodePrinterDlg::OnBnClickedUserButton()
{
	// TODO: 在此添加控件通知处理程序代码
	showDlg(IDD_USER_DIALOG);
}

void CCodePrinterDlg::OnBnClickedConfigurationButton()
{
	// TODO: 在此添加控件通知处理程序代码
	showDlg(IDD_CONFIGURATION_DIALOG);
}

void CCodePrinterDlg::OnBnClickedFilemanaButton()
{
	// TODO: 在此添加控件通知处理程序代码
	showDlg(IDD_FILEMANA_DIALOG);
}

void CCodePrinterDlg::OnBnClickedInkButton()
{
	// TODO: 在此添加控件通知处理程序代码
	showDlg(IDD_INKSYSTEM_DIALOG);
}
//开关机按钮
void CCodePrinterDlg::OnBnClickedOnoroffButton()
{
	showDlg(IDD_ONOFF_DIALOG);
	
}
//开始喷印
void CCodePrinterDlg::OnBnClickedStartprintButton()
{
 // TODO: 在此添加控件通知处理程序代码
	if (theApp.myStatusClass.ctr0X03bit0==1 /*& theApphaiqueyixiang*/)
	{
		theApp.myStatusClass.ctr0X03bit1 = 1;
	}
	else  
	{
		theApp.myStatusClass.ctr0X03bit0 = 1;
	}
	theApp.myStatusClass.download_inksystem_control03();
}
//开暂停喷印
void CCodePrinterDlg::OnBnClickedPauseprintButton()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.myStatusClass.ctr0X03bit0=0;
	theApp.myStatusClass.download_inksystem_control03();
}

void CCodePrinterDlg::showDlg(int ID)
{
	m_Fault->ShowWindow(SW_HIDE);
	m_System->ShowWindow(SW_HIDE);
	m_User->ShowWindow(SW_HIDE);
	m_Label->ShowWindow(SW_HIDE);
	m_Confi->ShowWindow(SW_HIDE);
	m_FileMan->ShowWindow(SW_HIDE);
	m_Ink->ShowWindow(SW_HIDE);
	m_OnOff->ShowWindow(SW_HIDE);
	if(ID == IDD_SYSTEM_DIALOG)
	{
		m_System->ShowWindow(SW_SHOW);
	}
	else if (ID == IDD_USER_DIALOG)
	{
		m_User->ShowWindow(SW_SHOW);
	}
	else if(ID == IDD_LABEL_DIALOG)
	{
		m_Label->ShowWindow(SW_SHOW);
	}
	else if(ID == IDD_CONFIGURATION_DIALOG)
	{
		m_Confi->ShowWindow(SW_SHOW);
	}
	else if(ID == IDD_FILEMANA_DIALOG)
	{
		m_FileMan->ShowWindow(SW_SHOW);
	}
	else if(ID == IDD_INKSYSTEM_DIALOG)
	{
		m_Ink->ShowWindow(SW_SHOW);
	}
	else if (ID == IDD_FAULT_DIALOG)
	{
		m_Fault->ShowWindow(SW_SHOW);
	}
	else if (ID == IDD_ONOFF_DIALOG)
	{
		m_OnOff->ShowWindow(SW_SHOW);
	}
}

//定时器
void CCodePrinterDlg::OnTimer(UINT_PTR nIDEvent)
{
	CDialog::OnTimer(nIDEvent);
	switch(nIDEvent)
		
	case TIMER1:
	{
		//临时变量
		CString m_printStatus;   //记录故障等同于VB的 labPrinterStatusText


		theApp.myStatusClass.byStatusFromSlaveState();
		theApp.myStatusClass.getstatu();


		//更新阀的信息
		HWND advan;
		advan=m_Ink->m_inkAdv->GetSafeHwnd();
		theApp.myStatusClass.ad_button_onoff(advan);
		HWND usua;
		usua=m_Ink->GetSafeHwnd();
		theApp.myStatusClass.us_button_onoff(usua);
		
		m_Ink->GetDlgItem(IDC_PRESSURE_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myclassMessage.to_String(theApp.myStatusClass.staPressure)));
//		
		m_Ink->GetDlgItem(IDC_PUMP_SPEED_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myclassMessage.to_String(theApp.myStatusClass.staBumSpe)));
		m_Ink->GetDlgItem(IDC_INK_TEMP_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myclassMessage.to_String(theApp.myStatusClass.staInkTem)));

		m_Ink->GetDlgItem(IDC_PRINTHEAD_TEMP_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myclassMessage.to_String(theApp.myStatusClass.staPriHeaTem)));
		m_Ink->GetDlgItem(IDC_INK_LEV_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myclassMessage.to_String(theApp.myStatusClass.staInkLev)));
		m_Ink->GetDlgItem(IDC_SOLVENT_LEV_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myclassMessage.to_String(theApp.myStatusClass.staSolLev)));
		m_Ink->GetDlgItem(IDC_TARGET_VISCO_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myclassMessage.to_String(theApp.myStatusClass.staTarVis)));
		m_Ink->GetDlgItem(IDC_ACTUAL_VISCO_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR((theApp.myStatusClass.staActVis)>0?theApp.myclassMessage.to_String(theApp.myStatusClass.staActVis):"***"));
		m_Ink->GetDlgItem(IDC_HIGH_VOL_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myclassMessage.to_String(theApp.myStatusClass.staHigVol)));
       
		//'泵速或者压力模式
		if (theApp.myStatusClass.staBumMod==true /*& m_Ink->m_CIB_Pumpspeed.m_tag==1 & m_Ink->m_CIB_Pressure.m_tag==0*/)//泵速模式
		{
			/*m_Ink->m_CIB_Pumpspeed.m_tag = 0;
            m_Ink->m_CIB_Pressure.m_tag = 1;*/
			m_Ink->GetDlgItem(IDC_SPEED_MODE_BTN)->SetWindowText(_T("泵速模式开"));
			m_Ink->GetDlgItem(IDC_PRESSURE_MODE_BTN)->SetWindowText(_T("压力模式"));
			/*m_Ink->m_CIB_SpeedMode.LoadBitmaps(IDB_ON_BITMAP,IDB_ON_BITMAP,0,0,IDB_ON_BITMAP);
			m_Ink->m_CIB_SpeedMode.SizeToContent(); 
			m_Ink->m_CIB_PressureMode.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
			m_Ink->m_CIB_PressureMode.SizeToContent(); */
		}
		else if (theApp.myStatusClass.staBumMod==false/*& m_Ink->m_CIB_Pumpspeed.m_tag==0 & m_Ink->m_CIB_Pressure.m_tag==1*/)//压力模式
		{
			/*m_Ink->m_CIB_Pumpspeed.m_tag = 1;
            m_Ink->m_CIB_Pressure.m_tag = 0;*/
			/*m_Ink->m_CIB_PressureMode.LoadBitmaps(IDB_ON_BITMAP,IDB_ON_BITMAP,0,0,IDB_ON_BITMAP);
			m_Ink->m_CIB_PressureMode.SizeToContent(); 
			m_Ink->m_CIB_SpeedMode.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
			m_Ink->m_CIB_SpeedMode.SizeToContent(); */
			m_Ink->GetDlgItem(IDC_SPEED_MODE_BTN)->SetWindowText(_T("泵速模式"));
			m_Ink->GetDlgItem(IDC_PRESSURE_MODE_BTN)->SetWindowText(_T("压力模式开"));
		}
		//开关泵
		if (theApp.myStatusClass.staBum == true)
		{
			m_Ink->GetDlgItem(IDC_PUMP_BTN)->SetWindowText(_T("压力泵开"));
			/*m_Ink->m_CIB_Pump.LoadBitmaps(IDB_ON_BITMAP,IDB_ON_BITMAP,0,0,IDB_ON_BITMAP);
			m_Ink->m_CIB_Pump.SizeToContent(); */
		}
		else if (theApp.myStatusClass.staBum == false)
		{
			m_Ink->GetDlgItem(IDC_PUMP_BTN)->SetWindowText(_T("压力泵"));
		/*	m_Ink->m_CIB_Pump.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
			m_Ink->m_CIB_Pump.SizeToContent(); */
		}
		//开关喷嘴
		if (theApp.myStatusClass.staNozVal==true)
		{
			m_Ink->GetDlgItem(IDC_NOZZLE_VALVE_BTN)->SetWindowText(_T("喷嘴阀开"));
			/*m_Ink->m_CIB_NozzleValve.LoadBitmaps(IDB_ON_BITMAP,IDB_ON_BITMAP,0,0,IDB_ON_BITMAP);
			m_Ink->m_CIB_NozzleValve.SizeToContent(); */
		}
		else if (theApp.myStatusClass.staNozVal==false)
		{
			m_Ink->GetDlgItem(IDC_NOZZLE_VALVE_BTN)->SetWindowText(_T("喷嘴阀"));
		/*	m_Ink->m_CIB_NozzleValve.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
			m_Ink->m_CIB_NozzleValve.SizeToContent(); */
		}
        //开关供墨阀
		if (theApp.myStatusClass.staFeeVal == true)
		{
			m_Ink->GetDlgItem(IDC_FEED_VALVE_BTN)->SetWindowText(_T("供墨阀开"));
			/*m_Ink->m_CIB_FeedValve.LoadBitmaps(IDB_ON_BITMAP,IDB_ON_BITMAP,0,0,IDB_ON_BITMAP);
			m_Ink->m_CIB_FeedValve.SizeToContent(); */
		}
		else if (theApp.myStatusClass.staFeeVal==false)
		{
			m_Ink->GetDlgItem(IDC_FEED_VALVE_BTN)->SetWindowText(_T("供墨阀"));
			/*m_Ink->m_CIB_FeedValve.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
			m_Ink->m_CIB_FeedValve.SizeToContent(); */
		}
		//开关排气阀
		if (theApp.myStatusClass.staBleVal == true)
		{
			m_Ink->GetDlgItem(IDC_BLEED_VALVE_BTN)->SetWindowText(_T("排气阀开"));
			/*m_Ink->m_CIB_BleedValve.LoadBitmaps(IDB_ON_BITMAP,IDB_ON_BITMAP,0,0,IDB_ON_BITMAP);
			m_Ink->m_CIB_BleedValve.SizeToContent(); */
		}
		else if (theApp.myStatusClass.staBleVal==false)
		{
			m_Ink->GetDlgItem(IDC_BLEED_VALVE_BTN)->SetWindowText(_T("排气阀"));
			/*m_Ink->m_CIB_BleedValve.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
			m_Ink->m_CIB_BleedValve.SizeToContent(); */
		}
		//开关清洗阀
		if (theApp.myStatusClass.staFluVal == true)
		{
			m_Ink->GetDlgItem(IDC_FLUSH_VALVE_BTN)->SetWindowText(_T("清洗阀开"));
			/*m_Ink->m_CIB_FlushValve.LoadBitmaps(IDB_ON_BITMAP,IDB_ON_BITMAP,0,0,IDB_ON_BITMAP);
			m_Ink->m_CIB_FlushValve.SizeToContent(); */
		}
		else if (theApp.myStatusClass.staFluVal==false)
		{
			m_Ink->GetDlgItem(IDC_FLUSH_VALVE_BTN)->SetWindowText(_T("清洗阀"));
			/*m_Ink->m_CIB_FlushValve.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
			m_Ink->m_CIB_FlushValve.SizeToContent(); */
		}
		//开关溶剂阀
		if (theApp.myStatusClass.staSolVal == true)
		{
			m_Ink->GetDlgItem(IDC_SOLVENT_VALVE_BTN)->SetWindowText(_T("溶剂阀开"));
			/*m_Ink->m_CIB_SolventValve.LoadBitmaps(IDB_ON_BITMAP,IDB_ON_BITMAP,0,0,IDB_ON_BITMAP);
			m_Ink->m_CIB_SolventValve.SizeToContent(); */
		}
		else if (theApp.myStatusClass.staSolVal==false)
		{
			m_Ink->GetDlgItem(IDC_SOLVENT_VALVE_BTN)->SetWindowText(_T("溶剂阀"));
			/*m_Ink->m_CIB_SolventValve.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
			m_Ink->m_CIB_SolventValve.SizeToContent(); */
		}
		//开关粘度阀
		if (theApp.myStatusClass.staVisVal == true)
		{
			m_Ink->GetDlgItem(IDC_VISCO_VALVE_BTN)->SetWindowText(_T("粘度阀开"));
			/*m_Ink->m_CIB_ViscoValve.LoadBitmaps(IDB_ON_BITMAP,IDB_ON_BITMAP,0,0,IDB_ON_BITMAP);
			m_Ink->m_CIB_ViscoValve.SizeToContent(); */
		}
		else if (theApp.myStatusClass.staVisVal==false)
		{
			m_Ink->GetDlgItem(IDC_VISCO_VALVE_BTN)->SetWindowText(_T("粘度阀"));
			/*m_Ink->m_CIB_ViscoValve.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
			m_Ink->m_CIB_ViscoValve.SizeToContent(); */
		}
		//开关冲洗阀
		if (theApp.myStatusClass.staWasVal == true)
		{
			m_Ink->GetDlgItem(IDC_WASH_VALVE_BTN)->SetWindowText(_T("冲洗阀开"));
			/*m_Ink->m_CIB_WashValve.LoadBitmaps(IDB_ON_BITMAP,IDB_ON_BITMAP,0,0,IDB_ON_BITMAP);
			m_Ink->m_CIB_WashValve.SizeToContent(); */
		}
		else if (theApp.myStatusClass.staWasVal == false)
		{
			m_Ink->GetDlgItem(IDC_WASH_VALVE_BTN)->SetWindowText(_T("冲洗阀"));
			/*m_Ink->m_CIB_WashValve.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
			m_Ink->m_CIB_WashValve.SizeToContent(); */
		}
		//关回收检测
		if (theApp.myStatusClass.staInkFloSenOff == true)
		{
			m_Ink->m_inkAdv->m_CIB_InkflowOff.LoadBitmaps(IDB_ON_BITMAP,IDB_ON_BITMAP,0,0,IDB_ON_BITMAP);
			m_Ink->m_inkAdv->m_CIB_InkflowOff.SizeToContent(); 
		}
		else if (theApp.myStatusClass.staInkFloSenOff == false)
		{
			m_Ink->m_inkAdv->m_CIB_InkflowOff.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
			m_Ink->m_inkAdv->m_CIB_InkflowOff.SizeToContent(); 
		}
        //关闭墨线
		if (theApp.myStatusClass.staCloInkLin == true)
		{
			m_Ink->m_inkAdv->m_CIB_CloseInkline.LoadBitmaps(IDB_ON_BITMAP,IDB_ON_BITMAP,0,0,IDB_ON_BITMAP);
			m_Ink->m_inkAdv->m_CIB_CloseInkline.SizeToContent(); 
		}
		else if (theApp.myStatusClass.staCloInkLin == false)
		{
			m_Ink->m_inkAdv->m_CIB_CloseInkline.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
			m_Ink->m_inkAdv->m_CIB_CloseInkline.SizeToContent(); 
		}
        //开添加溶剂
		if (theApp.myStatusClass.staAddSol == true)
		{
			m_Ink->m_inkAdv->m_CIB_AddSolvent.LoadBitmaps(IDB_ON_BITMAP,IDB_ON_BITMAP,0,0,IDB_ON_BITMAP);
			m_Ink->m_inkAdv->m_CIB_AddSolvent.SizeToContent(); 
		}
		else if (theApp.myStatusClass.staAddSol == false)
		{
			m_Ink->m_inkAdv->m_CIB_AddSolvent.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
			m_Ink->m_inkAdv->m_CIB_AddSolvent.SizeToContent(); 
			theApp.myStatusClass.ctr0X02bit2 = 0;
		    theApp.myStatusClass.download_inksystem_control02();
		}
        //开测试粘度
		if (theApp.myStatusClass.staDetVis == true)
		{
			m_Ink->m_inkAdv->m_CIB_BetectVisco.LoadBitmaps(IDB_ON_BITMAP,IDB_ON_BITMAP,0,0,IDB_ON_BITMAP);
			m_Ink->m_inkAdv->m_CIB_BetectVisco.SizeToContent(); 
		}
		else if (theApp.myStatusClass.staDetVis == false)
		{
			m_Ink->m_inkAdv->m_CIB_BetectVisco.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
			m_Ink->m_inkAdv->m_CIB_BetectVisco.SizeToContent(); 
			theApp.myStatusClass.ctr0X02bit3 = 0;
			theApp.myStatusClass.download_inksystem_control02();
		}
		//开冲洗喷嘴
		if (theApp.myStatusClass.staWasNoz == true)
		{
			m_Ink->m_inkAdv->m_CIB_WashNozzle.LoadBitmaps(IDB_ON_BITMAP,IDB_ON_BITMAP,0,0,IDB_ON_BITMAP);
			m_Ink->m_inkAdv->m_CIB_WashNozzle.SizeToContent(); 
		}
		else if (theApp.myStatusClass.staWasNoz == false)
		{
			m_Ink->m_inkAdv->m_CIB_WashNozzle.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
			m_Ink->m_inkAdv->m_CIB_WashNozzle.SizeToContent(); 
			theApp.myStatusClass.ctr0X02bit4 = 0;
			theApp.myStatusClass.download_inksystem_control02();
		}
		//开反吸喷嘴
		if (theApp.myStatusClass.staSucNoz == true)
		{
			m_Ink->m_inkAdv->m_CIB_SuckNozzle.LoadBitmaps(IDB_ON_BITMAP,IDB_ON_BITMAP,0,0,IDB_ON_BITMAP);
			m_Ink->m_inkAdv->m_CIB_SuckNozzle.SizeToContent(); 
		}
		else if (theApp.myStatusClass.staSucNoz == false)
		{
			m_Ink->m_inkAdv->m_CIB_SuckNozzle.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
			m_Ink->m_inkAdv->m_CIB_SuckNozzle.SizeToContent(); 
			theApp.myStatusClass.ctr0X02bit5 = 0;
			theApp.myStatusClass.download_inksystem_control02();
		}
		//开墨线校准
		if (theApp.myStatusClass.staAdjInkLin == true)
		{
			m_Ink->m_inkAdv->m_CIB_AdjustInkline.LoadBitmaps(IDB_ON_BITMAP,IDB_ON_BITMAP,0,0,IDB_ON_BITMAP);
			m_Ink->m_inkAdv->m_CIB_AdjustInkline.SizeToContent(); 
		}
		else if (theApp.myStatusClass.staAdjInkLin == false)
		{
			m_Ink->m_inkAdv->m_CIB_AdjustInkline.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
			m_Ink->m_inkAdv->m_CIB_AdjustInkline.SizeToContent(); 
			theApp.myStatusClass.ctr0X02bit6 = 0;
			theApp.myStatusClass.download_inksystem_control02();
		}
		//开墨路循环
		if (theApp.myStatusClass.staInkCir == true)
		{
			m_Ink->m_inkAdv->m_CIB_InkCir.LoadBitmaps(IDB_ON_BITMAP,IDB_ON_BITMAP,0,0,IDB_ON_BITMAP);
			m_Ink->m_inkAdv->m_CIB_InkCir.SizeToContent(); 
		}
		else if (theApp.myStatusClass.staInkCir == false)
		{
			m_Ink->m_inkAdv->m_CIB_InkCir.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
			m_Ink->m_inkAdv->m_CIB_InkCir.SizeToContent(); 
			theApp.myStatusClass.ctr0X02bit7 = 0;
			theApp.myStatusClass.download_inksystem_control02();
		}
        //当前电平

		/*if (theApp.myStatusClass.staActProSen == true && m_Confi->m_ConfigOutSetDlg->m_currentLevelStr == "Low")

		CString m_currentLev;
		m_Confi->m_ConfigOutSetDlg->GetDlgItem(IDC_CURRENT_LEV_EDIT)->GetWindowTextW(m_currentLev);
		if (theApp.myStatusClass.staActProSen == true && m_currentLev == "Low")
		{
			m_Confi->m_ConfigOutSetDlg->m_currentLevelStr="High";
            m_Confi->m_ConfigOutSetDlg->UpdateData(FALSE);
		}
		else if (theApp.myStatusClass.staActProSen == false && m_Confi->m_ConfigOutSetDlg->m_currentLevelStr == "High")
		{
			m_Confi->m_ConfigOutSetDlg->m_currentLevelStr="Low";
			m_Confi->m_ConfigOutSetDlg->UpdateData(FALSE);
		}*/

		//墨水温度传感器故障
	if (theApp.myStatusClass.staInkTemSenFau == true && theApp.myStatusClass.staInkTemSenFauLas == false)
		{
			theApp.myStatusClass.staInkTemSenFauLas = true;
			CString csMsg ;
			csMsg.Format(_T("Ink temperature sensor fault!"));

            csMsg.Format(_T("%s"),csMsg);
			m_Fault->m_faultList.AddString(csMsg);//还需要加时间和日期
		}
		else if(theApp.myStatusClass.staInkTemSenFau == false && theApp.myStatusClass.staInkTemSenFauLas == true)
		{
		   theApp.myStatusClass.staInkTemSenFauLas = false;
		}
		//喷头温度传感器故障
		if (theApp.myStatusClass.staPriHeaTemFau == true && theApp.myStatusClass.staPriHeaTemFauLas == false)
		{
			theApp.myStatusClass.staPriHeaTemFauLas = true;
			CString csMsg ;
			csMsg.Format(_T("Printhead temperature sensor fault!"));			
			csMsg.Format(_T("%s"),csMsg);
			m_Fault->m_faultList.AddString(csMsg);//还需要加时间和日期
		}
		else if (theApp.myStatusClass.staPriHeaTemFau == false && theApp.myStatusClass.staPriHeaTemFauLas == true)
		{
			theApp.myStatusClass.staPriHeaTemFauLas = false;
		}
		//泵超速保护
		if (theApp.myStatusClass.staBumSpeOveFau == true && theApp.myStatusClass.staBumSpeOveFauLas == false)
		{
			theApp.myStatusClass.staBumSpeOveFauLas = true;
//缺starting up

			theApp.myStatusClass.ctr0X03bit0 = 0;
			theApp.myStatusClass.download_inksystem_control03();
			theApp.myStatusClass.ctr0X00bit5 = 0;
			theApp.myStatusClass.ctr0X00bit3 = 0;
			theApp.myStatusClass.ctr0X00bit2 = 0;
			theApp.myStatusClass.ctr0X00bit1 = 1;
			theApp.myStatusClass.ctr0X00bit0 = 0;
			theApp.myStatusClass.download_inksystem_control00();
			CString csMsg ;
			csMsg.Format(_T("Pump speed abnormal!"));
		
			csMsg.Format(_T("%s"),csMsg);
			m_Fault->m_faultList.AddString(csMsg);//还需要加时间和日期
		}
		else if (theApp.myStatusClass.staBumSpeOveFau == false && theApp.myStatusClass.staBumSpeOveFauLas == true)
		{
			theApp.myStatusClass.staBumSpeOveFauLas = false;
		}
		//过压保护
		if (theApp.myStatusClass.staPreOveFau == true && theApp.myStatusClass.staPreOveFauLas == false)
		{
			theApp.myStatusClass.staPreOveFauLas = true;
			//缺starting up

			theApp.myStatusClass.ctr0X03bit0 = 0;
			theApp.myStatusClass.download_inksystem_control03();
			theApp.myStatusClass.ctr0X00bit5 = 0;
			theApp.myStatusClass.ctr0X00bit3 = 0;
			theApp.myStatusClass.ctr0X00bit2 = 0;
			theApp.myStatusClass.ctr0X00bit1 = 1;
			theApp.myStatusClass.ctr0X00bit0 = 0;
			theApp.myStatusClass.download_inksystem_control00();
			CString csMsg ;
			csMsg.Format(_T("Pressure abnormal!"));
		
			csMsg.Format(_T("%s"),csMsg);
			m_Fault->m_faultList.AddString(csMsg);//还需要加时间和日期
		}
		else if (theApp.myStatusClass.staPreOveFau == false && theApp.myStatusClass.staPreOveFauLas == true)
		{
			theApp.myStatusClass.staPreOveFauLas = false;
		}
		//粘度异常
		if (theApp.myStatusClass.staVisAbnFau == true && theApp.myStatusClass.staVisAbnFauLas == false)
		{
			theApp.myStatusClass.staVisAbnFauLas = true;
			CString csMsg ;
		    csMsg.Format(_T("Ink Visco abnormal!"));
			/*AfxMessageBox(csMsg);*/
			csMsg.Format(_T("%s"),csMsg);
			m_Fault->m_faultList.AddString(csMsg);//还需要加时间和日期
		}
		//粘度计故障
		if (theApp.myStatusClass.staVisSenFau == true && theApp.myStatusClass.staVisSenFauLas == false)
		{
			theApp.myStatusClass.staVisSenFauLas = true;
			CString csMsg ;
			csMsg.Format(_T("Viscometer fault!"));
			/*AfxMessageBox(csMsg);*/
			csMsg.Format(_T("%s"),csMsg);
			m_Fault->m_faultList.AddString(csMsg);//还需要加时间和日期
		}
		else if (theApp.myStatusClass.staVisSenFau == false && theApp.myStatusClass.staVisSenFauLas == true)
		{
			theApp.myStatusClass.staVisSenFauLas = false;
		}
		//回收故障
		if(theApp.myStatusClass.staInkFloSenOff == true)
		{
           theApp.myStatusClass.staInkFloFau = true;
		   m_Ink->GetDlgItem(IDC_INKFLOW_EDIT)->SetWindowText(_T("Disable"));
		}
		else
		{
			if (theApp.myStatusClass.staInkFloFau == true && theApp.myStatusClass.staInkFloFauLas == false)
			{
				theApp.myStatusClass.staInkFloFauLas = true;
				//缺starting up

				theApp.myStatusClass.ctr0X03bit0 = 0;		
				theApp.myStatusClass.download_inksystem_control03();
				theApp.myStatusClass.ctr0X00bit5 = 0;
				theApp.myStatusClass.ctr0X00bit3 = 0;
				theApp.myStatusClass.ctr0X00bit2 = 0;
				theApp.myStatusClass.ctr0X00bit1 = 1;
				theApp.myStatusClass.ctr0X00bit0 = 0;
				theApp.myStatusClass.download_inksystem_control00();
				CString csMsg ;
				csMsg.Format(_T("Recyle fault!"));
				csMsg.Format(_T("%s"),csMsg);
				m_Fault->m_faultList.AddString(csMsg);//还需要加时间和日期以及故障弹框
				m_Ink->GetDlgItem(IDC_INKFLOW_EDIT)->SetWindowText(_T("Abnormal"));
			}
			else if (theApp.myStatusClass.staInkFloFau == false)
			{
				if (theApp.myStatusClass.staInkFloFauLas == true && theApp.myStatusClass.staInkFloFauLas == false)
				{
					m_Ink->GetDlgItem(IDC_INKFLOW_EDIT)->SetWindowText(_T("Normal"));
				}
			}
		}
		//风扇故障
		if (theApp.myStatusClass.staFanFau == true && theApp.myStatusClass.staFanFauLas == false)
		{
			theApp.myStatusClass.staFanFauLas = true;
			//缺starting up
			
			theApp.myStatusClass.ctr0X03bit0 = 0;
			theApp.myStatusClass.download_inksystem_control03();
			theApp.myStatusClass.ctr0X00bit5 = 0;
			theApp.myStatusClass.ctr0X00bit3 = 0;
			theApp.myStatusClass.ctr0X00bit2 = 0;
			theApp.myStatusClass.ctr0X00bit1 = 1;
			theApp.myStatusClass.ctr0X00bit0 = 0;
			theApp.myStatusClass.download_inksystem_control00();
			CString csMsg;
			csMsg.Format(_T("Fan fault!"));
			csMsg.Format(_T("%s"),csMsg);
			m_Fault->m_faultList.AddString(csMsg);//还需要加时间和日期以及故障弹框
		}
		else if (theApp.myStatusClass.staFanFau == false && theApp.myStatusClass.staFanFauLas == true)
		{
			theApp.myStatusClass.staFanFauLas = false;
		}
		//充电故障
		if (theApp.myStatusClass.staChaFau == true && theApp.myStatusClass.staChaFauLas == false)
		{
			theApp.myStatusClass.staChaFauLas = true;
			GetDlgItem(IDC_PRINT_STA_STATIC)->SetWindowText(_T("Chargefault"));
			m_printStatus ="Charge fault";
			theApp.myStatusClass.ctr0X03bit0 = 0;

			theApp.myStatusClass.download_inksystem_control03();
			CString csMsg ;
			csMsg.Format(_T("Charge fault!"));
			csMsg.Format(_T("%s"),csMsg);
			m_Fault->m_faultList.AddString(csMsg);//还需要加时间和日期以及故障弹框
		}
		else if (theApp.myStatusClass.staChaFau == false && theApp.myStatusClass.staChaFauLas == true)
		{
			theApp.myStatusClass.staChaFauLas = false;
		}
		//相位故障
		if (theApp.myStatusClass.staPhaFau == true && theApp.myStatusClass.staPhaFauLas == false)
		{
			theApp.myStatusClass.staPhaFauLas = true;
			GetDlgItem(IDC_PRINT_STA_STATIC)->SetWindowText(_T("Phasefault"));
			m_printStatus ="Phase fault";
			theApp.myStatusClass.ctr0X03bit0 = 0;
			theApp.myStatusClass.download_inksystem_control03();
			CString csMsg ;
			csMsg.Format(_T("Phase fault!"));
			csMsg.Format(_T("%s"),csMsg);
			m_Fault->m_faultList.AddString(csMsg);//还需要加时间和日期以及故障弹框
		}
		else if (theApp.myStatusClass.staPhaFau == false && theApp.myStatusClass.staPhaFauLas == true)
		{
			theApp.myStatusClass.staPhaFauLas = false;
		}
		//高压故障
		if (theApp.myStatusClass.staHigVolFau == true && theApp.myStatusClass.staHigVolFauLas == false)
		{
			theApp.myStatusClass.staHigVolFauLas = true;
			//缺starting up

			
			theApp.myStatusClass.ctr0X03bit0 = 0;
			theApp.myStatusClass.download_inksystem_control03();
			theApp.myStatusClass.ctr0X00bit5 = 0;
			theApp.myStatusClass.ctr0X00bit3 = 0;
			theApp.myStatusClass.ctr0X00bit2 = 0;
			theApp.myStatusClass.ctr0X00bit1 = 1;
			theApp.myStatusClass.ctr0X00bit0 = 0;
			theApp.myStatusClass.download_inksystem_control00();
			CString csMsg ;
			csMsg.Format(_T("High voltage fault!"));
			csMsg.Format(_T("%s"),csMsg);
			m_Fault->m_faultList.AddString(csMsg);//还需要加时间和日期以及故障弹框
		}
		else if (theApp.myStatusClass.staHigVolFau == false && theApp.myStatusClass.staHigVolFauLas == true)
		{
			theApp.myStatusClass.staHigVolFauLas = false;
		}
		//溶剂液位状态
		if (theApp.myStatusClass.staSolLevFau == "00" && theApp.myTimClass.staSolLevFauLas != "00" && theApp.myStatusClass.staInkLevFau == "00")
		{
			theApp.myTimClass.staSolLevFauLas = "00";
			/*picAlarmBlue.Tag = "im004"
			picAlarmBlue.Image = My.Resources.ResourceBng.im004*/
		}
		else if (theApp.myStatusClass.staSolLevFau == "01" && theApp.myTimClass.staSolLevFauLas != "01")
		{
			theApp.myTimClass.staSolLevFauLas = "01";
			CString csMsg ;
			csMsg.Format(_T("Add solvent"));
			csMsg.Format(_T("%s"),csMsg);
			m_Fault->m_faultList.AddString(csMsg);//还需要加时间和日期以及故障弹框
			/*picAlarmBlue.Tag = "im003"
			picAlarmBlue.Image = My.Resources.ResourceBng.im003*/
		}
		else if (theApp.myStatusClass.staSolLevFau == "10" && theApp.myTimClass.staSolLevFauLas != "10")
		{
			theApp.myTimClass.staSolLevFauLas = "10";
			/*picAlarmBlue.Tag = "im003"
			picAlarmBlue.Image = My.Resources.ResourceBng.im003*/
			CString csMsg ;
			csMsg.Format(_T("Solvent empty"));
			csMsg.Format(_T("%s"),csMsg);
			m_Fault->m_faultList.AddString(csMsg);//还需要加时间和日期以及故障弹框
		}
		else if (theApp.myStatusClass.staSolLevFau == "11" && theApp.myTimClass.staSolLevFauLas != "11")
		{
			theApp.myTimClass.staSolLevFauLas = "11";
			/*picAlarmBlue.Tag = "im003"
			picAlarmBlue.Image = My.Resources.ResourceBng.im003*/
			CString csMsg ;
			csMsg.Format(_T("Solvent overfull"));
			csMsg.Format(_T("%s"),csMsg);
			m_Fault->m_faultList.AddString(csMsg);//还需要加时间和日期以及故障弹框
		}
		//墨水液位状态
		if (theApp.myStatusClass.staInkLevFau == "00" && theApp.myTimClass.staInkLevFauLas != "00" && theApp.myStatusClass.staSolLevFau == "00")
		{
			theApp.myTimClass.staInkLevFauLas = "00";
			/*picAlarmBlue.Tag = "im004"
			picAlarmBlue.Image = My.Resources.ResourceBng.im004*/
			theApp.myTimClass.staInkEmpFau = false;
			theApp.myTimClass.staInkOveFau = false;
		}
		else if (theApp.myStatusClass.staInkLevFau == "01" && theApp.myTimClass.staInkLevFauLas != "01")
		{
			theApp.myTimClass.staInkLevFauLas = "01";
			/*picAlarmBlue.Tag = "im003"
			picAlarmBlue.Image = My.Resources.ResourceBng.im003*/
			theApp.myTimClass.staInkEmpFau = false;
			theApp.myTimClass.staInkOveFau = false;
			CString csMsg ;
			csMsg.Format(_T("Add ink"));
			csMsg.Format(_T("%s"),csMsg);
			m_Fault->m_faultList.AddString(csMsg);//还需要加时间和日期以及故障弹框
		}
		else if (theApp.myStatusClass.staInkLevFau == "10" && theApp.myTimClass.staInkLevFauLas != "10")
		{
			theApp.myTimClass.staInkLevFauLas = "10";
			//缺starting up

			theApp.myStatusClass.ctr0X00bit5 = 0;
			theApp.myStatusClass.ctr0X00bit3 = 0;
			theApp.myStatusClass.ctr0X00bit2 = 0;
			theApp.myStatusClass.ctr0X00bit1 = 1;
			theApp.myStatusClass.ctr0X00bit0 = 0;
			theApp.myStatusClass.download_inksystem_control00();
			theApp.myTimClass.staInkEmpFau = true;
			theApp.myTimClass.staInkOveFau = false;
			CString csMsg ;
			csMsg.Format(_T("Ink empty"));
			csMsg.Format(_T("%s"),csMsg);
			m_Fault->m_faultList.AddString(csMsg);//还需要加时间和日期以及故障弹框
		}
		else if (theApp.myStatusClass.staInkLevFau == "11" && theApp.myTimClass.staInkLevFauLas != "11")
		{
			theApp.myTimClass.staInkLevFauLas = "11";
			//缺starting up

			theApp.myStatusClass.ctr0X00bit5 = 0;
			theApp.myStatusClass.ctr0X00bit3 = 0;
			theApp.myStatusClass.ctr0X00bit2 = 0;
			theApp.myStatusClass.ctr0X00bit1 = 1;
			theApp.myStatusClass.ctr0X00bit0 = 0;
			theApp.myStatusClass.download_inksystem_control00();
			theApp.myTimClass.staInkOveFau = true;
			theApp.myTimClass.staInkEmpFau = false;
			CString csMsg ;
			csMsg.Format(_T("Ink overfull"));
			csMsg.Format(_T("%s"),csMsg);
			m_Fault->m_faultList.AddString(csMsg);//还需要加时间和日期以及故障弹框
	    }
		//开打印中
		if (theApp.myStatusClass.ctr0X03bit0 == 1 && theApp.myStatusClass.staSysRea == true)//开了打印功能和系统准备好
		{
			if (m_printStatus != "Ready to print")
			{
				GetDlgItem(IDC_PRINT_STA_STATIC)->SetWindowText(_T("Readytoprint"));
				m_printStatus = "Ready to print";
			}
		}
		else if (theApp.myStatusClass.ctr0X03bit0 == 0)//未开打印功能
		{
			if (theApp.myStatusClass.staSysRea == true)//系统准备好
			{
				if (m_printStatus != "System ready")
				{
					GetDlgItem(IDC_PRINT_STA_STATIC)->SetWindowText(_T("Systemready"));
					m_printStatus = "System ready";
				}
			}
			else if (theApp.myStatusClass.staSysRea == false) //系统未准备好
			{
				if (theApp.myStatusClass.staSysBus == true) //系统忙
				{
					if (theApp.myStatusClass.ctr0X00bit0 == 1 /*&& picAlarmRed.Tag = "im008" && picAlarmYellow.Tag = "im006"*/)//开关机位=1
					{
						if (m_printStatus != ("Sequencing On"))
						{
							GetDlgItem(IDC_PRINT_STA_STATIC)->SetWindowText(_T("SequencingOn"));
							m_printStatus = "Sequencing On";
						}
					}
					else if (theApp.myStatusClass.ctr0X00bit0 == 0 /*&& picAlarmRed.Tag = "im008" && picAlarmYellow.Tag = "im006"*/)//开关机位=0
					{
						if (m_printStatus != "Sequencing Off")
						{
							GetDlgItem(IDC_PRINT_STA_STATIC)->SetWindowText(_T("SequencingOff"));
							m_printStatus != "Sequencing Off";
						}
					}
				}
				else if (theApp.myStatusClass.staSysBus == false /*&& picAlarmRed.Tag = "im008" && picAlarmYellow.Tag = "im006"*/ )//系统不忙
				{
					if (m_printStatus !="Printer Off")
					{
						GetDlgItem(IDC_PRINT_STA_STATIC)->SetWindowText(_T("PrinterOff"));
						m_printStatus ="Printer Off";
					}
				}//系统忙
			}//系统准备好

		}//开了打印功能和系统准备好
		






		break;

	}
}



HBRUSH CCodePrinterDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	pDC->SetBkColor(theApp.m_BKcolor);
	 
	 
	return theApp.m_DlgBrush;
}