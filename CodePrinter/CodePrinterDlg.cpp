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
#include "..\PathDlgDll\PathDlgDll\PathDlgDll.h"
//#include "Tchar.h”
#include "PcfConfig.h"

//#define  def_ttl 1


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
	DDX_Control(pDX, IDC_HEAD_PIC, m_PicHead);
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

 //	CBitmap bitmap;  // CBitmap对象，用于加载位图   
	//HBITMAP hBmp;    // 保存CBitmap加载的位图的句柄   
	//bitmap.LoadBitmap(IDB_CLOSE_BITMAP);  // 将位图IDB_BITMAP1加载到bitmap  
	//hBmp = (HBITMAP)bitmap.GetSafeHandle();  // 获取bitmap加载位图的句柄   
	//m_LogoPicBox.SetBitmap(hBmp);    // 设置图片控件m_jzmPicture的位图图片为IDB_BITMAP1   

   
	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetWindowPos(NULL,0,0,800,600,SWP_SHOWWINDOW );	
    m_PicHead.SetMachineStatus(_T("Shut Down"));
	m_PicHead.ShowLogo(true);
  
	m_Fault = new CFaultDlg;
	m_System = new CSystemDlg;
	m_User = new CUserDlg;
	m_Label = new CLabelDlg;
	m_Confi = new CConfigurationDlg;
	m_FileMan = new CFileManaDlg;
	m_Ink = new CInkSystemDlg;
	m_OnOff = new COnOffDlg; 

	//创建文件夹
	CreateDirectory(_T("Storage Card\\System\\Error"), NULL);
	CreateDirectory(_T("Storage Card\\User\\PrintConfig"), NULL);
	CreateDirectory(_T("Storage Card\\User\\Label"), NULL);
	CreateDirectory(_T("Storage Card\\User\\Logo"), NULL);
	CreateDirectory(_T("Storage Card\\User\\Font"), NULL);
	int nX = 0;
	int nY = 80;
	int nWidth = 800;
	int nHeight = 500;
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
	GetDlgItem(IDC_FAULT_BUTTON)->SetWindowPos(NULL,710,10,80,55,SWP_SHOWWINDOW);
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
	m_ButFault.LoadBitmaps(IDB_FAULT1_BITMAP,IDB_FAULT2_BITMAP,0,0,IDB_FAULT1_BITMAP);
	m_ButFault.SizeToContent(); 
	m_ButSystem.LoadBitmaps(IDB_SYSTEM1_BITMAP,IDB_SYSTEM2_BITMAP,0,0,IDB_SYSTEM1_BITMAP);
	m_ButSystem.SizeToContent(); 
	m_ButUser.LoadBitmaps(IDB_USER1_BITMAP,IDB_USER2_BITMAP,0,0,IDB_LABEL1_BITMAP);
	m_ButUser.SizeToContent(); 
	m_ButLabel.LoadBitmaps(IDB_LABEL1_BITMAP,IDB_LABEL2_BITMAP,0,0,IDB_LABEL1_BITMAP);
	m_ButLabel.SizeToContent(); 
	m_ButConfig.LoadBitmaps(IDB_CONFIG1_BITMAP,IDB_CONFIG2_BITMAP,0,0,IDB_CONFIG1_BITMAP);
	m_ButConfig.SizeToContent(); 
	m_ButFileMana.LoadBitmaps(IDB_FILEMANA1_BITMAP,IDB_FILEMANA2_BITMAP,0,0,IDB_FILEMANA1_BITMAP);
	m_ButFileMana.SizeToContent(); 
	m_ButInk.LoadBitmaps(IDB_INKSYSTEM1_BITMAP,IDB_INKSYSTEM2_BITMAP,0,0,IDB_INKSYSTEM1_BITMAP);
	m_ButInk.SizeToContent(); 

	m_ButOnOrOff.LoadBitmaps(IDB_ONOFF1_BITMAP,IDB_ONOFF2_BITMAP,0,0,IDB_ONOFF1_BITMAP);
	m_ButOnOrOff.SizeToContent(); 
	m_StartPrint.LoadBitmaps(IDB_START_PRINT1_BITMAP,IDB_START_PRINT2_BITMAP,0,0,IDB_START_PRINT1_BITMAP);
	m_StartPrint.SizeToContent(); 
	m_PausePrint.LoadBitmaps(IDB_PAUSE_PRINT1_BITMAP,IDB_PAUSE_PRINT2_BITMAP,0,0,IDB_PAUSE_PRINT1_BITMAP);
	m_PausePrint.SizeToContent(); 

	

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
	testFile = fopen("Storage Card\\System\\InkSystem.xml", "r");
	if (testFile)
	{
		fclose(testFile);
	}
	else
	{
		//createParaXML()
	}

	testFile = fopen("Storage Card\\System\\SoftSystem.xml", "r");
	if (testFile)
	{
		fclose(testFile);
	}
	else
	{
		//createSoftXML()
	}

	//多语言,根据softxml选择语言

	testFile = fopen("Storage Card\\System\\PrintConfig.xml", "r");
	if (testFile)
	{
		fclose(testFile);
	}
	else
	{
		//createPCFXML()
	}

	testFile = fopen("Storage Card\\System\\PrintMessage.xml", "r");
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

    //墨水配置初始化
	CInksystemconfig pInksysConfig(this);
	CPcfConfig pPcfConfig(this);
	SetTimer(TIMER1,1000,NULL);	
	pInksysConfig.get_inksystem_from_xml();

	pInksysConfig.download_inksystem_setup();
	theApp.myStatusClass.download_inksystem_control03();// ?
	pInksysConfig.download_inksystem_parameter();
	
	pPcfConfig.get_pcf_from_xml();
	pPcfConfig.download_pcf();

#ifdef def_ttl
	LPTSTR strTempCmd;
	BYTE readArr[8]={0x1,0x80,0x3,0x8f,0x0,0x25,0xaa,0x55};
	strTempCmd=(LPTSTR)readArr;	 
	theApp.myCIOVsd.Send(strTempCmd,8);
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
	//showDlg(IDD_FILEMANA_DIALOG);

	TCHAR path[MAX_PATH];
	//labModule.string2tchar(testpath,path);

	string xmlPath;
	ShowPathDlg(path, MAX_PATH,0,theApp.myUserPower.booFileManage);

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
	    m_PicHead.SetOperationString(_T("System Manage")); 
	}
	else if (ID == IDD_USER_DIALOG)
	{
		m_User->ShowWindow(SW_SHOW);
	    m_PicHead.SetOperationString(_T("User Manage")); 
	}
	else if(ID == IDD_LABEL_DIALOG)
	{
		m_Label->ShowWindow(SW_SHOW);
	    m_PicHead.SetOperationString(_T("Label Manage")); 
	}
	else if(ID == IDD_CONFIGURATION_DIALOG)
	{
		m_Confi->ShowWindow(SW_SHOW);
	    m_PicHead.SetOperationString(_T("Configure")); 
	}

	//else if(ID == IDD_FILEMANA_DIALOG)
	//{
	//	m_FileMan->ShowWindow(SW_SHOW);
	//	GetDlgItem(IDC_STATIC_SHOW_DLG)->SetWindowText(_T("File Manage"));
	//}


	else if(ID == IDD_INKSYSTEM_DIALOG)
	{
		m_Ink->ShowWindow(SW_SHOW);
	    m_PicHead.SetOperationString(_T("Ink System")); 
	}
	else if (ID == IDD_FAULT_DIALOG)
	{
		m_Fault->ShowWindow(SW_SHOW);
	    m_PicHead.SetOperationString(_T("Fault System")); 
	}
	else if (ID == IDD_ONOFF_DIALOG)
	{
		m_OnOff->ShowWindow(SW_SHOW);
	}
}

void CCodePrinterDlg::UpdateValve()
{
	//更新阀的信息
	HWND advan;
	advan = m_Ink->m_inkAdv->GetSafeHwnd();
	theApp.myStatusClass.ad_button_onoff(advan);
	HWND usua;
	usua = m_Ink->GetSafeHwnd();
	theApp.myStatusClass.us_button_onoff(usua);
	
	
	//'泵速或者压力模式
	if (theApp.myStatusClass.staBumMod == true /*& m_Ink->m_CIB_Pumpspeed.m_tag==1 & m_Ink->m_CIB_Pressure.m_tag==0*/)//泵速模式
	{
		m_Ink->m_CIB_SpeedMode.m_bDown = true;
		m_Ink->m_CIB_PressureMode.m_bDown = false;
	}
	else if (theApp.myStatusClass.staBumMod == false/*& m_Ink->m_CIB_Pumpspeed.m_tag==0 & m_Ink->m_CIB_Pressure.m_tag==1*/)//压力模式
	{
		m_Ink->m_CIB_SpeedMode.m_bDown = false;
		m_Ink->m_CIB_PressureMode.m_bDown = true;
	}
	m_Ink->m_CIB_SpeedMode.Invalidate();
	m_Ink->m_CIB_PressureMode.Invalidate();

	//开关泵
	if (theApp.myStatusClass.staBum == true)
	{
		m_Ink->m_CIB_Pump.m_bDown = false;
	}

	else if (theApp.myStatusClass.staBum == false)
	{
		m_Ink->m_CIB_Pump.m_bDown = true;
	}
	m_Ink->m_CIB_Pump.Invalidate();


	//开关喷嘴
	if (theApp.myStatusClass.staNozVal == true)
	{
		m_Ink->m_CIB_NozzleValve.m_bDown = false;
	}
	else if (theApp.myStatusClass.staNozVal == false)
	{
		m_Ink->m_CIB_NozzleValve.m_bDown = true;
	}
	m_Ink->m_CIB_NozzleValve.Invalidate();

    //开关供墨阀
	if (theApp.myStatusClass.staFeeVal == true)
	{
		m_Ink->m_CIB_FeedValve.m_bDown = false;
	}
	else if (theApp.myStatusClass.staFeeVal==false)
	{
		m_Ink->m_CIB_FeedValve.m_bDown = true;
	}
	m_Ink->m_CIB_FeedValve.Invalidate();

	//开关排气阀
	if (theApp.myStatusClass.staBleVal == true)
	{
		m_Ink->m_CIB_BleedValve.m_bDown = false;
	}
	else if (theApp.myStatusClass.staBleVal==false)
	{
		m_Ink->m_CIB_BleedValve.m_bDown = true;
	}
	m_Ink->m_CIB_BleedValve.Invalidate();

	//开关清洗阀
	if (theApp.myStatusClass.staFluVal == true)
	{
		m_Ink->m_CIB_FlushValve.m_bDown = false;
		
	}
	else if (theApp.myStatusClass.staFluVal==false)
	{
		m_Ink->m_CIB_FlushValve.m_bDown = true;
	}
	m_Ink->m_CIB_FlushValve.Invalidate();

	//开关溶剂阀
	if (theApp.myStatusClass.staSolVal == true)
	{
		m_Ink->m_CIB_SolventValve.m_bDown = false;
	}
	else if (theApp.myStatusClass.staSolVal==false)
	{
		m_Ink->m_CIB_SolventValve.m_bDown = true;
	}
	m_Ink->m_CIB_SolventValve.Invalidate();

	//开关粘度阀
	if (theApp.myStatusClass.staVisVal == true)
	{
		m_Ink->m_CIB_ViscoValve.m_bDown = false;
	}
	else if (theApp.myStatusClass.staVisVal==false)
	{
		m_Ink->m_CIB_ViscoValve.m_bDown = true;
	}
	m_Ink->m_CIB_ViscoValve.Invalidate();

	//开关冲洗阀
	if (theApp.myStatusClass.staWasVal == true)
	{
		m_Ink->m_CIB_WashValve.m_bDown = false;
	}
	else if (theApp.myStatusClass.staWasVal == false)
	{
		m_Ink->m_CIB_WashValve.m_bDown = true;
	}
	m_Ink->m_CIB_WashValve.Invalidate();

	//关回收检测
	if (theApp.myStatusClass.staInkFloSenOff == true)
	{
		m_Ink->m_inkAdv->m_CIB_InkflowOff.m_bDown = false;
	}
	else if (theApp.myStatusClass.staInkFloSenOff == false)
	{
    	m_Ink->m_inkAdv->m_CIB_InkflowOff.m_bDown = true;
	}
	m_Ink->m_inkAdv->m_CIB_InkflowOff.Invalidate();

    //关闭墨线
	if (theApp.myStatusClass.staCloInkLin == true)
	{
		m_Ink->m_inkAdv->m_CIB_CloseInkline.m_bDown = false;
	}
	else if (theApp.myStatusClass.staCloInkLin == false)
	{
		m_Ink->m_inkAdv->m_CIB_CloseInkline.m_bDown = true;
	}
	m_Ink->m_inkAdv->m_CIB_CloseInkline.Invalidate();

    //开添加溶剂
	if (theApp.myStatusClass.staAddSol == true)
	{
		m_Ink->m_inkAdv->m_CIB_AddSolvent.m_bDown = false;
	}
	else if (theApp.myStatusClass.staAddSol == false)
	{
		m_Ink->m_inkAdv->m_CIB_AddSolvent.m_bDown = true;
		theApp.myStatusClass.ctr0X02bit2 = 0;
	    theApp.myStatusClass.download_inksystem_control02();
	}
	m_Ink->m_inkAdv->m_CIB_AddSolvent.Invalidate();


    //开测试粘度
	if (theApp.myStatusClass.staDetVis == true)
	{
		m_Ink->m_inkAdv->m_CIB_BetectVisco.m_bDown = false;
	}
	else if (theApp.myStatusClass.staDetVis == false)
	{
		m_Ink->m_inkAdv->m_CIB_BetectVisco.m_bDown = true;
		theApp.myStatusClass.ctr0X02bit3 = 0;
		theApp.myStatusClass.download_inksystem_control02();
	}
	m_Ink->m_inkAdv->m_CIB_BetectVisco.Invalidate();

	//开冲洗喷嘴
	if (theApp.myStatusClass.staWasNoz == true)
	{
		m_Ink->m_inkAdv->m_CIB_WashNozzle.m_bDown = false;
	}
	else if (theApp.myStatusClass.staWasNoz == false)
	{
		m_Ink->m_inkAdv->m_CIB_WashNozzle.m_bDown = true;
		theApp.myStatusClass.ctr0X02bit4 = 0;
		theApp.myStatusClass.download_inksystem_control02();
	}
	m_Ink->m_inkAdv->m_CIB_WashNozzle.Invalidate();

	//开反吸喷嘴
	if (theApp.myStatusClass.staSucNoz == true)
	{
		 
		m_Ink->m_inkAdv->m_CIB_SuckNozzle.m_bDown = false;
	}
	else if (theApp.myStatusClass.staSucNoz == false)
	{
		m_Ink->m_inkAdv->m_CIB_SuckNozzle.m_bDown = true;
	}
	m_Ink->m_inkAdv->m_CIB_SuckNozzle.Invalidate();

	//开墨线校准
	if (theApp.myStatusClass.staAdjInkLin == true)
	{
		m_Ink->m_inkAdv->m_CIB_AdjustInkline.m_bDown = false;
	}
	else if (theApp.myStatusClass.staAdjInkLin == false)
	{
	     m_Ink->m_inkAdv->m_CIB_AdjustInkline.m_bDown = true;
		theApp.myStatusClass.ctr0X02bit6 = 0;
		theApp.myStatusClass.download_inksystem_control02();
	}
	m_Ink->m_inkAdv->m_CIB_AdjustInkline.Invalidate();

	//开墨路循环
	if (theApp.myStatusClass.staInkCir == true)
	{
		m_Ink->m_inkAdv->m_CIB_InkCir.m_bDown = false;
	}
	else if (theApp.myStatusClass.staInkCir == false)
	{
		m_Ink->m_inkAdv->m_CIB_InkCir.m_bDown = true;
		theApp.myStatusClass.ctr0X02bit7 = 0;
		theApp.myStatusClass.download_inksystem_control02();
	}
	m_Ink->m_inkAdv->m_CIB_InkCir.Invalidate();

	//高压开关
	if (theApp.myStatusClass.staHigVolSwi == true)
	{
		m_Ink->m_inkAdv->m_CIB_HighVoltage.m_bDown = false;
	}
	else if (theApp.myStatusClass.staHigVolSwi == false)
	{
		m_Ink->m_inkAdv->m_CIB_HighVoltage.m_bDown = true;
	}
	m_Ink->m_inkAdv->m_CIB_HighVoltage.Invalidate();

}

void CCodePrinterDlg::GetFaultInfo()
{
	//故障列表要清除，但又得防止刷新太快，最好判断一下如果列表中已显示该类型故障就不用添加了。
    m_Fault->m_faultList.ResetContent();

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
			if (theApp.myStatusClass.staInkFloFauLas == true  )
			{
				theApp.myStatusClass.staInkFloFauLas = false;
				
			}
			m_Ink->GetDlgItem(IDC_INKFLOW_EDIT)->SetWindowText(_T("Normal"));
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
		m_PicHead.SetMachineStatus(_T("Charge fault"));

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
		m_PicHead.SetMachineStatus(_T("Phase fault"));

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
		m_PicHead.SetBlueAlarm(false);
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
		m_PicHead.SetBlueAlarm(true);
	}
	else if (theApp.myStatusClass.staSolLevFau == "10" && theApp.myTimClass.staSolLevFauLas != "10")
	{
		theApp.myTimClass.staSolLevFauLas = "10";
		m_PicHead.SetBlueAlarm(true);
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
		m_PicHead.SetBlueAlarm(true);
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
		m_PicHead.SetBlueAlarm(false);
		/*picAlarmBlue.Tag = "im004"
		picAlarmBlue.Image = My.Resources.ResourceBng.im004*/
		theApp.myTimClass.staInkEmpFau = false;
		theApp.myTimClass.staInkOveFau = false;
	}
	else if (theApp.myStatusClass.staInkLevFau == "01" && theApp.myTimClass.staInkLevFauLas != "01")
	{
		theApp.myTimClass.staInkLevFauLas = "01";
		m_PicHead.SetBlueAlarm(true);
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

	//电眼过快
	if (theApp.myStatusClass.staProSenFas == true && theApp.myStatusClass.staProSenFasLas == false)
	{
		theApp.myStatusClass.staProSenFasLas = true;
		CString csMsg ;
		csMsg.Format(_T("Much too product"));
		csMsg.Format(_T("%s"),csMsg);
		m_Fault->m_faultList.AddString(csMsg);//还需要加时间和日期以及故障弹框
	}
	else if (theApp.myStatusClass.staProSenFas == false && theApp.myStatusClass.staProSenFasLas == true)
	{
		theApp.myStatusClass.staProSenFasLas = false;
	}

	//自动分裂失败
	if (theApp.myStatusClass.staAutModFau == true && theApp.myStatusClass.staAutModFauLas == false)
	{
		theApp.myStatusClass.staAutModFauLas = true;
		m_PicHead.SetMachineStatus(_T("Fault Condition"));

		theApp.myStatusClass.ctr0X03bit0 = 0;
		theApp.myStatusClass.download_inksystem_control03();
		CString csMsg ;
		csMsg.Format(_T("Auto modulation fault"));
		csMsg.Format(_T("%s"),csMsg);
		m_Fault->m_faultList.AddString(csMsg);//还需要加时间和日期以及故障弹框
	}
	else if (theApp.myStatusClass.staAutModFau == false && theApp.myStatusClass.staAutModFauLas == true)
	{
		theApp.myStatusClass.staAutModFauLas = false;
	}

	//阀故障
	if(theApp.myStatusClass.staValFau == true && theApp.myStatusClass.staValFauLas == false) 
	{
		theApp.myStatusClass.staValFauLas = true;
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
		csMsg.Format(_T("Valve fault"));
		csMsg.Format(_T("%s"),csMsg);
		m_Fault->m_faultList.AddString(csMsg);//还需要加时间和日期以及故障弹框
	}
	else if(theApp.myStatusClass.staValFau == false && theApp.myStatusClass.staValFauLas == true) 
	{
		theApp.myStatusClass.staValFauLas = false;
	}

	//编码器过快
	if (theApp.myStatusClass.staLinFas == true && theApp.myStatusClass.staLinFasLas == false )
	{
		theApp.myStatusClass.staLinFasLas = true;
		CString csMsg ;
		csMsg.Format(_T("Too fast"));
		csMsg.Format(_T("%s"),csMsg);
		m_Fault->m_faultList.AddString(csMsg);//还需要加时间和日期以及故障弹框
	}
	else if (theApp.myStatusClass.staLinFas == false && theApp.myStatusClass.staLinFasLas == true )
	{
		theApp.myStatusClass.staLinFasLas = false;
	}

	//恒温故障
	if (theApp.myStatusClass.staPriHeaHotFau == true && theApp.myStatusClass.staPriHeaHotFauLas == false )
	{
		theApp.myStatusClass.staPriHeaHotFauLas = true;
		CString csMsg ;
		csMsg.Format(_T("Constant temperature fault"));
		csMsg.Format(_T("%s"),csMsg);
		m_Fault->m_faultList.AddString(csMsg);//还需要加时间和日期以及故障弹框
	}
	else if (theApp.myStatusClass.staPriHeaHotFau == false && theApp.myStatusClass.staPriHeaHotFauLas == true )
	{
		theApp.myStatusClass.staPriHeaHotFauLas = false;
	}
}


//定时器
void CCodePrinterDlg::OnTimer(UINT_PTR nIDEvent)
{
	CDialog::OnTimer(nIDEvent);
	switch(nIDEvent)
		
	case TIMER1:
	{
		 if (theApp.myUserPower.isChangeUser)
		 {
			 ChangeBottonEnable();
			 theApp.myUserPower.isChangeUser=false;
		 }
		theApp.myStatusClass.byStatusFromSlaveState();
		theApp.myStatusClass.getstatu();
        
		UpdateValve(); //更新各种阀的信息，通过颜色显示出来，蓝色表示没按下去

		GetFaultInfo(); //获得各种故障信息

		//开打印中
		if (theApp.myStatusClass.ctr0X03bit0 == 1 && theApp.myStatusClass.staSysRea == true)//开了打印功能和系统准备好
		{
			m_PicHead.SetMachineStatus(_T("Ready to print"));
 		}
		else if (theApp.myStatusClass.ctr0X03bit0 == 0)//未开打印功能
		{
			if (theApp.myStatusClass.staSysRea == true)//系统准备好
			{				 
				m_PicHead.SetMachineStatus(_T("System ready"));
			}
			else if (theApp.myStatusClass.staSysRea == false) //系统未准备好
			{
				if (theApp.myStatusClass.staSysBus == true) //系统忙
				{
					if (theApp.myStatusClass.ctr0X00bit0 == 1 /*&& picAlarmRed.Tag = "im008" && picAlarmYellow.Tag = "im006"*/)//开关机位=1
					{
						m_PicHead.SetMachineStatus(_T("Sequencing On"));
					}
					else if (theApp.myStatusClass.ctr0X00bit0 == 0 /*&& picAlarmRed.Tag = "im008" && picAlarmYellow.Tag = "im006"*/)//开关机位=0

					{
						m_PicHead.SetMachineStatus(_T("Sequencing Off"));
					}
				}
				else if (theApp.myStatusClass.staSysBus == false /*&& picAlarmRed.Tag = "im008" && picAlarmYellow.Tag = "im006"*/ )//系统不忙
				{					 
					m_PicHead.SetMachineStatus(_T("Printer Off"));
				}//系统忙
			}//系统准备好

		}//开了打印功能和系统准备好

		//打印按钮的开启
		if (theApp.myStatusClass.ctr0X03bit0 == 0 ) //开打印功能，1开启
		{
			
		}
		else if (theApp.myStatusClass.ctr0X03bit0 == 1 )
		{

		}		

       //当前电平
		CString m_currentLev;
		m_Confi->m_ConfigOS->GetDlgItem(IDC_CURRENT_LEV_EDIT)->GetWindowText(m_currentLev);
		if (theApp.myStatusClass.staActProSen == true && m_currentLev == "Low")
		{
			m_Confi->m_ConfigOS->GetDlgItem(IDC_CURRENT_LEV_EDIT)->SetWindowText(_T("High"));
		}
		else if (theApp.myStatusClass.staActProSen == false && m_currentLev == "High")
		{
			m_Confi->m_ConfigOS->GetDlgItem(IDC_CURRENT_LEV_EDIT)->SetWindowText(_T("Low"));
		}

	
		//实时压力
		m_Ink->GetDlgItem(IDC_PRESSURE_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myclassMessage.to_String(theApp.myStatusClass.staPressure)));
		//实时泵速	
		m_Ink->GetDlgItem(IDC_PUMP_SPEED_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myclassMessage.to_String(theApp.myStatusClass.staBumSpe)));
		m_Ink->GetDlgItem(IDC_INK_TEMP_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myclassMessage.to_String(theApp.myStatusClass.staInkTem)));
		m_Ink->GetDlgItem(IDC_PRINTHEAD_TEMP_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myclassMessage.to_String(theApp.myStatusClass.staPriHeaTem)));
		m_Ink->GetDlgItem(IDC_INK_LEV_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myclassMessage.to_String(theApp.myStatusClass.staInkLev)));
		m_Ink->GetDlgItem(IDC_SOLVENT_LEV_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myclassMessage.to_String(theApp.myStatusClass.staSolLev)));
		m_Ink->GetDlgItem(IDC_TARGET_VISCO_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myclassMessage.to_String(theApp.myStatusClass.staTarVis)));
		m_Ink->GetDlgItem(IDC_ACTUAL_VISCO_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR((theApp.myStatusClass.staActVis)>0?theApp.myclassMessage.to_String(theApp.myStatusClass.staActVis):"***"));
		m_Ink->GetDlgItem(IDC_HIGH_VOL_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myclassMessage.to_String(theApp.myStatusClass.staHigVol)));


		//实时相位
		//switch(theApp.myStatusClass.staPhase)
		//	case "0":
		// {
		//	if (theApp.myTimClass.staPhaseLas != "0")
		//	{
		//	}
		// }

		break;

	}
}


HBRUSH CCodePrinterDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
   /* if(nCtlColor == CTLCOLOR_STATIC)
	{
		switch(pWnd->GetDlgCtrlID())
		{			
			case IDC_STATIC_SHOW_DLG:
			{
				pDC->SelectObject(theApp.m_HeadOperationStaFont);
				pDC->SetBkMode(TRANSPARENT);
				pDC->SetTextColor(RGB(255,255,255));
				break;
			}
			default:
				break;
		}
	} */

	pDC->SetBkColor(theApp.m_BKcolor);
	 
	return theApp.m_DlgBrush;
}

//改权限实现
void CCodePrinterDlg::ChangeBottonEnable()
{
	GetDlgItem(IDC_RESET_COUNT_BTN)->EnableWindow(theApp.myUserPower.booResetCount);
	GetDlgItem(IDC_RESET_SERIAL_BTN)->EnableWindow(theApp.myUserPower.booResetSerial);
	//墨水Us
	m_Ink->GetDlgItem(IDC_SPEED_MODE_BTN)->EnableWindow(theApp.myUserPower.booInkUsual);
	m_Ink->GetDlgItem(IDC_PRESSURE_MODE_BTN)->EnableWindow(theApp.myUserPower.booInkUsual);
	m_Ink->GetDlgItem(IDC_BLEED_VALVE_BTN)->EnableWindow(theApp.myUserPower.booInkUsual);
	m_Ink->GetDlgItem(IDC_PUMP_BTN)->EnableWindow(theApp.myUserPower.booInkUsual);
	m_Ink->GetDlgItem(IDC_WASH_VALVE_BTN)->EnableWindow(theApp.myUserPower.booInkUsual);
	m_Ink->GetDlgItem(IDC_NOZZLE_VALVE_BTN)->EnableWindow(theApp.myUserPower.booInkUsual);
	m_Ink->GetDlgItem(IDC_FEED_VALVE_BTN)->EnableWindow(theApp.myUserPower.booInkUsual);
	m_Ink->GetDlgItem(IDC_SOLVENT_VALVE_BTN)->EnableWindow(theApp.myUserPower.booInkUsual);
	m_Ink->GetDlgItem(IDC_VISCO_VALVE_BTN)->EnableWindow(theApp.myUserPower.booInkUsual);
	m_Ink->GetDlgItem(IDC_FLUSH_VALVE_BTN)->EnableWindow(theApp.myUserPower.booInkUsual);
	//墨水高级
	theApp.myModuleMain.DisableAllBtn(m_Ink->m_inkAdv->GetSafeHwnd(),theApp.myUserPower.booInkAdvance);
	//m_Ink->m_inkAdv->GetDlgItem(IDC_SUCK_NOZZLE_BTN)->EnableWindow(theApp.myUserPower.booInkAdvance);
	//m_Ink->m_inkAdv->GetDlgItem(IDC_INKFLOW_OFF_BTN)->EnableWindow(theApp.myUserPower.booInkAdvance);
	//m_Ink->m_inkAdv->GetDlgItem(IDC_CLOSE_INKLINE_BTN)->EnableWindow(theApp.myUserPower.booInkAdvance);
	//m_Ink->m_inkAdv->GetDlgItem(IDC_ADD_SOLVENT_BTN)->EnableWindow(theApp.myUserPower.booInkAdvance);
	//m_Ink->m_inkAdv->GetDlgItem(IDC_BETECT_VISCO_BTN)->EnableWindow(theApp.myUserPower.booInkAdvance);
	//m_Ink->m_inkAdv->GetDlgItem(IDC_WASH_NOZZLE_BTN)->EnableWindow(theApp.myUserPower.booInkAdvance);
	//m_Ink->m_inkAdv->GetDlgItem(IDC_ADJUST_INKLINE_BTN)->EnableWindow(theApp.myUserPower.booInkAdvance);
	//m_Ink->m_inkAdv->GetDlgItem(IDC_INK_CIR_BTN)->EnableWindow(theApp.myUserPower.booInkAdvance);
	//m_Ink->m_inkAdv->GetDlgItem(IDC_HIGH_VOLTAGE_BTN)->EnableWindow(theApp.myUserPower.booInkAdvance);
	//墨水安装
	theApp.myModuleMain.DisableAllBtn(m_Ink->m_setup->GetSafeHwnd(),theApp.myUserPower.booInkSetup);
	//m_Ink->m_setup->GetDlgItem(IDC_SIZE_LIST)->EnableWindow(theApp.myUserPower.booInkSetup);
	//m_Ink->m_setup->GetDlgItem(IDC_MODUL_FRE_LIST)->EnableWindow(theApp.myUserPower.booInkSetup);
	//m_Ink->m_setup->GetDlgItem(IDC_INK_TYPE_LIST)->EnableWindow(theApp.myUserPower.booInkSetup);
	//m_Ink->m_setup->GetDlgItem(IDC_PELTIER_LIST)->EnableWindow(theApp.myUserPower.booInkSetup);
	//m_Ink->m_setup->GetDlgItem(IDC_SLEEP_LIST)->EnableWindow(theApp.myUserPower.booInkSetup);
	//m_Ink->m_setup->GetDlgItem(IDC_NEXT_SERVICE_EDIT)->EnableWindow(theApp.myUserPower.booInkSetup);
	//m_Ink->m_setup->GetDlgItem(IDC_INK_LIFE_TIME_EDIT)->EnableWindow(theApp.myUserPower.booInkSetup);
	//m_Ink->m_setup->GetDlgItem(IDC_SOLVENT_CALIB_BTN)->EnableWindow(theApp.myUserPower.booInkSetup);
	//m_Ink->m_setup->GetDlgItem(IDC_INK_CALIB_BTN)->EnableWindow(theApp.myUserPower.booInkSetup);
	//墨水参数
	theApp.myModuleMain.DisableAllBtn(m_Ink->m_par->GetSafeHwnd(),theApp.myUserPower.booInkParameter);
	/*m_Ink->m_par->GetDlgItem(IDC_PAR_PRESSURE_EDIT)->EnableWindow(theApp.myUserPower.booInkParameter);
	m_Ink->m_par->GetDlgItem(IDC_PAR_PUMP_SPEED_EDIT)->EnableWindow(theApp.myUserPower.booInkParameter);
	m_Ink->m_par->GetDlgItem(IDC_INK_FLOW_LEV_EDIT)->EnableWindow(theApp.myUserPower.booInkParameter);
	m_Ink->m_par->GetDlgItem(IDC_INK_ADD_LEV_EDIT)->EnableWindow(theApp.myUserPower.booInkParameter);
	m_Ink->m_par->GetDlgItem(IDC_INK_EMPTY_LEV_EDIT)->EnableWindow(theApp.myUserPower.booInkParameter);
	m_Ink->m_par->GetDlgItem(IDC_PRINTHEAD_TEMP_EDIT)->EnableWindow(theApp.myUserPower.booInkParameter);
	m_Ink->m_par->GetDlgItem(IDC_PRINTHEAD_TEMP_EDIT)->EnableWindow(theApp.myUserPower.booInkParameter);
	m_Ink->m_par->GetDlgItem(IDC_SOLVENT_FLOW_LEV_EDIT)->EnableWindow(theApp.myUserPower.booInkParameter);
	m_Ink->m_par->GetDlgItem(IDC_SOL_ADD_LEV_EDIT)->EnableWindow(theApp.myUserPower.booInkParameter);
	m_Ink->m_par->GetDlgItem(IDC_SOL_EMPTY_LEV_EDIT)->EnableWindow(theApp.myUserPower.booInkParameter);*/
	//墨水相位
	theApp.myModuleMain.DisableAllBtn(m_Ink->m_phas->GetSafeHwnd(),theApp.myUserPower.booInkPhasing);
	//m_Ink->m_phas->GetDlgItem(IDC_PASHING_CUT_BTN)->EnableWindow(theApp.myUserPower.booInkPhasing);
	//m_Ink->m_phas->GetDlgItem(IDC_PHASING_ADD_BTN)->EnableWindow(theApp.myUserPower.booInkPhasing);
	//m_Ink->m_phas->GetDlgItem(IDC_AUTO_SET_BTN)->EnableWindow(theApp.myUserPower.booInkPhasing);
	//m_Ink->m_phas->GetDlgItem(IDC_SET_ADJUST_BIG_BTN)->EnableWindow(theApp.myUserPower.booInkPhasing);
	//m_Ink->m_phas->GetDlgItem(IDC_SET_ADJUST_SMALL_BTN)->EnableWindow(theApp.myUserPower.booInkPhasing);
	
	//文件管理，在dll中实现
	
    
	//配置
	//m_Confi->GetDlgItem(IDC_CONFI_OPEN_BTN)->EnableWindow(theApp.myUserPower)
	theApp.myModuleMain.DisableAllBtn(m_Confi->GetSafeHwnd(),theApp.myUserPower.booPcfAll);
	if (!theApp.myUserPower.booPcfAll)
	{
		m_Confi->GetDlgItem(IDC_CONFI_OPEN_BTN)->EnableWindow(theApp.myUserPower.booPcfIO);
		m_Confi->GetDlgItem(IDC_BUTTON5)->EnableWindow(theApp.myUserPower.booPcfIO);
	}
	m_Confi->GetDlgItem(IDC_CONFI_CLOSE_BTN)->EnableWindow(true);

	//标签
	theApp.myModuleMain.DisableAllBtn(m_Label->GetSafeHwnd(),theApp.myUserPower.booLabelAll);
	if (!theApp.myUserPower.booLabelAll)
	{
		m_Label->GetDlgItem(IDC_OPEN_BUTTON)->EnableWindow(theApp.myUserPower.booLabelIO);
		m_Label->GetDlgItem(IDC_DOWNLOAD_BUTTON)->EnableWindow(theApp.myUserPower.booLabelIO);
	}
	m_Label->GetDlgItem(IDC_LABEL_CLOSE_BTN)->EnableWindow(true);

	//系统
	//网络 串口
	theApp.myModuleMain.DisableAllBtn(m_System->GetSafeHwnd(),theApp.myUserPower.booSysNetComOK);
	theApp.myModuleMain.DisableAllBtn(m_System->pCom->GetSafeHwnd(),theApp.myUserPower.booSysNetComOK);
	m_System->GetDlgItem(IDC_SYSTEM_CLOSE_BTN)->EnableWindow(true);
	m_System->GetDlgItem(IDC_NET_BTN)->EnableWindow(true);
	m_System->GetDlgItem(IDC_COM_BTN)->EnableWindow(true);
	m_System->GetDlgItem(IDC_EVN_BTN)->EnableWindow(true);
	m_System->GetDlgItem(IDC_CUSTON_BUTTON)->EnableWindow(true);
	m_System->GetDlgItem(IDC_VERSION_BTN)->EnableWindow(true);
	//环境 自定义
	theApp.myModuleMain.DisableAllBtn(m_System->pEvn->GetSafeHwnd(),theApp.myUserPower.booSysEnvCusOK);
	if (theApp.myUserPower.booSysEnvCusOK||theApp.myUserPower.booSysNetComOK)
	{
		m_System->GetDlgItem(IDC_BUTTON9)->EnableWindow(true);
	}
	
	//故障
	m_Fault->GetDlgItem(IDC_BUTTON3)->EnableWindow(theApp.myUserPower.booFaultDelete);
	//m_System->
}