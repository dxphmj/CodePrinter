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
#include "ClientContext.h"
#include "ClientManager.h"
#include <Winsock2.h>
//#include "Tchar.h”
#include "PcfConfig.h"
#include "DealXml.h"

#define  def_ttl 1
//对话框左上角
#define ID_SYSTEM_MANAGEMENT				WM_USER+3000
#define ID_SYSTEM_NETWORK					WM_USER+3001
#define ID_SYSTEM_COM						WM_USER+3002
#define ID_SYSTEM_ENV						WM_USER+3003
#define ID_SYSTEM_VERSION					WM_USER+3004

#define ID_USER_MANAGEMENT					WM_USER+3005
#define ID_USER_MANAGEMENT_NEW				WM_USER+3006
#define ID_USER_MANAGEMENT_EDIT				WM_USER+3007
#define ID_USER_MANAGEMENT_DEL				WM_USER+3008
#define ID_USER_MANAGEMENT_FRESH			WM_USER+3009

#define ID_LABEL_MANAGEMENT					WM_USER+3010

#define ID_CONFIGURATION_MANAGEMENT			WM_USER+3011
#define ID_CONFIGURATION_PRINTMODE			WM_USER+3012
#define ID_CONFIGURATION_OUTSET				WM_USER+3013
#define ID_OPEN_CONFIGURATION				WM_USER+3014
#define ID_NEW_CONFIGURATION				WM_USER+3015

#define ID_FILE_MANAGEMENT					WM_USER+3016

#define ID_INKSYSTEM_MANAGEMENT				WM_USER+3017
#define ID_INKSYSTEM_USUAL					WM_USER+3018
#define ID_INKSYSTEM_ADVANCE				WM_USER+3019
#define ID_INKSYSTEM_SETUP					WM_USER+3020
#define ID_INKSYSTEM_PARAMETER				WM_USER+3021
#define ID_INKSYSTEM_PHASING				WM_USER+3022

#define ID_ERROR_INFORMATION				WM_USER+3023

//打印机状态
#define IDC_MACHINE_STATUS					WM_USER+3024
#define IDC_READY_TO_PRINT					WM_USER+3025
#define IDC_SYSTEM_READY					WM_USER+3026
#define IDC_SEQUENCING_ON					WM_USER+3027
#define IDC_SEQUENCING_OFF					WM_USER+3028
#define IDC_PRINTER_OFF						WM_USER+3029
//开关机界面
#define ID_ON_TITLE							WM_USER+3030
#define ID_OFF_TITLE						WM_USER+3031




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
	DDX_Control(pDX, IDC_STATIC_MAIN_PICTURE, m_PictureMain);
	DDX_Control(pDX, IDC_RESET_COUNT_BTN, m_ButResetCounter);
	DDX_Control(pDX, IDC_RESET_SERIAL_BTN, m_ButResetSerial);
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
	ON_BN_CLICKED(IDC_RESET_COUNT_BTN, &CCodePrinterDlg::OnBnClickedResetCountBtn)
	ON_BN_CLICKED(IDC_RESET_SERIAL_BTN, &CCodePrinterDlg::OnBnClickedResetSerialBtn)
END_MESSAGE_MAP()


// CCodePrinterDlg 消息处理程序



BOOL CCodePrinterDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	//this->ShowWindow(SW_HIDE);
   
	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	//dealmxl.WriteXml(_T("LoadConfig.xml"),_T("Value"),_T("10"),_T("Storage Card\\System"));
    theApp.SetProgressBar(5);
	// TODO: 在此添加额外的初始化代码
		//全屏显示
		//隐藏HHTaskBar窗口代码如下:       
	HWND hTaskBar = ::FindWindow(TEXT("HHTaskBar"), NULL);        
	if (hTaskBar != NULL)       
	{       
		::EnableWindow(hTaskBar, FALSE);       
		::ShowWindow(hTaskBar, SW_HIDE);       
	}       	
	m_PicHead.SetWindowPos(NULL,0,0,800,75,SWP_SHOWWINDOW );
	bool iniLanXml;
	iniLanXml = theApp.myLanguage.readLanguageXml("ChineseSimplified.xml");
	wstring lanStr;
	lanStr=theApp.myLanguage.LanguageMap["IDC_MACHINE_STATUS"];
    m_PicHead.SetMachineStatus(lanStr.c_str());//Shut Down
	m_PicHead.ShowLogo(true);
	m_PictureMain.SetWindowPos(NULL,0,0,640,129, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);
	mainPicStruct.myMainPicture=&m_PictureMain;
	m_Fault = new CFaultDlg;
	m_System = new CSystemDlg;
	m_User = new CUserDlg;
	m_Label = new CLabelDlg;
	m_Confi = new CConfigurationDlg;
	m_FileMan = new CFileManaDlg;
	m_Ink = new CInkSystemDlg;
	m_resetSerial = new CResetSerial;
	//创建文件夹
	CreateDirectory(_T("Storage Card\\System\\Error"), NULL);
	CreateDirectory(_T("Storage Card\\User\\PrintConfig"), NULL);
	CreateDirectory(_T("Storage Card\\User\\Label"), NULL);
	CreateDirectory(_T("Storage Card\\User\\Logo"), NULL);
	CreateDirectory(_T("Storage Card\\User\\Font"), NULL);
	CreateDirectory(_T("Storage Card\\User\\LanguageXml"), NULL);//多语言文件夹，以后移动到system文件夹下比较好
	int nX = 0;
	int nY = 75;
	int nWidth = 800;
	int nHeight = 525;
	
	m_Fault->Create(IDD_FAULT_DIALOG,this);
	m_Fault->MoveWindow(nX,nY,nWidth,nHeight); 
 	
	m_System->Create(IDD_SYSTEM_DIALOG,this);
	m_System->MoveWindow(nX,nY,nWidth,nHeight);
	theApp.SetProgressBar(20);
	m_User->Create(IDD_USER_DIALOG,this);
	m_User->MoveWindow(nX,nY,nWidth,nHeight);
	theApp.SetProgressBar(30);
	
	m_Confi->Create(IDD_CONFIGURATION_DIALOG,this);
 	m_Confi->MoveWindow(nX,nY,nWidth,nHeight);
	theApp.SetProgressBar(50);

	m_FileMan->Create(IDD_FILEMANA_DIALOG,this);
	m_FileMan->MoveWindow(nX,nY,nWidth,nHeight);
	theApp.SetProgressBar(55);
	m_Ink->Create(IDD_INKSYSTEM_DIALOG,this);
	m_Ink->MoveWindow(nX,nY,nWidth,nHeight); 
	theApp.SetProgressBar(70);
	m_Label->Create(IDD_LABEL_DIALOG,this);
	m_Label->MoveWindow(nX,nY,nWidth,nHeight); 
	/*theApp.SetProgressBar(85);*/
	
	m_resetSerial->Create(IDD_RESET_SERIAL_DIALOG,this);
	m_resetSerial->MoveWindow(nX,nY,nWidth,nHeight); 

	//右侧一列设置按钮的位置及大小
	GetDlgItem(IDC_FAULT_BUTTON)->SetWindowPos(NULL,710,10,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_SYSTEM_BUTTON)->SetWindowPos(NULL,700,100,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_USER_BUTTON)->SetWindowPos(NULL,700,170,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_LABEL_BUTTON)->SetWindowPos(NULL,700,240,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_CONFIGURATION_BUTTON)->SetWindowPos(NULL,700,310,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_FILEMANA_BUTTON)->SetWindowPos(NULL,700,380,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_INK_BUTTON)->SetWindowPos(NULL,700,450,80,55,SWP_SHOWWINDOW);
	//下面两个按钮
	//GetDlgItem(IDC_RESET_COUNT_BTN)->SetWindowPos(NULL,40,330,80,50,SWP_SHOWWINDOW);
	//GetDlgItem(IDC_RESET_SERIAL_BTN)->SetWindowPos(NULL,360,330,80,50,SWP_SHOWWINDOW);
	//开机和喷印
	GetDlgItem(IDC_ONOROFF_BUTTON)->SetWindowPos(NULL,50,450,80,50,SWP_SHOWWINDOW);
	GetDlgItem(IDC_STARTPRINT_BUTTON)->SetWindowPos(NULL,280,420,80,55,SWP_SHOWWINDOW);
	GetDlgItem(IDC_PAUSEPRINT_BUTTON)->SetWindowPos(NULL,450,420,80,55,SWP_SHOWWINDOW);
	//彩色按钮
	//dealmxl.WriteXml(_T("LoadConfig.xml"),_T("Value"),_T("90"),_T("Storage Card\\System"));
	m_ButResetCounter.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_80_55_BITMAP,true);
	m_ButResetCounter.SizeToContent(); 
	m_ButResetSerial.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_80_55_BITMAP,true);
	m_ButResetSerial.SizeToContent(); 
	theApp.SetProgressBar(85);
	m_ButFault.LoadBitmaps(IDB_FAULT1_BITMAP,IDB_FAULT2_BITMAP,0,0,IDB_80_55_BITMAP);
	m_ButFault.SizeToContent(); 
	m_ButSystem.LoadBitmaps(IDB_SYSTEM1_BITMAP,IDB_SYSTEM2_BITMAP,0,0,IDB_80_55_BITMAP);
	m_ButSystem.SizeToContent(); 
	m_ButUser.LoadBitmaps(IDB_USER1_BITMAP,IDB_USER2_BITMAP,0,0,IDB_80_55_BITMAP);
	m_ButUser.SizeToContent(); 
	m_ButLabel.LoadBitmaps(IDB_LABEL1_BITMAP,IDB_LABEL2_BITMAP,0,0,IDB_80_55_BITMAP);
	m_ButLabel.SizeToContent(); 
	m_ButConfig.LoadBitmaps(IDB_CONFIG1_BITMAP,IDB_CONFIG2_BITMAP,0,0,IDB_80_55_BITMAP);
	m_ButConfig.SizeToContent(); 
	m_ButFileMana.LoadBitmaps(IDB_FILEMANA1_BITMAP,IDB_FILEMANA2_BITMAP,0,0,IDB_80_55_BITMAP);
	m_ButFileMana.SizeToContent(); 
	m_ButInk.LoadBitmaps(IDB_INKSYSTEM1_BITMAP,IDB_INKSYSTEM2_BITMAP,0,0,IDB_80_55_BITMAP);
	m_ButInk.SizeToContent(); 
	theApp.SetProgressBar(90);

	m_ButOnOrOff.LoadBitmaps(IDB_ONOFF1_BITMAP,IDB_ONOFF2_BITMAP,0,0,IDB_ONOFF1_BITMAP);
	m_ButOnOrOff.SizeToContent(); 
	m_StartPrint.LoadBitmaps(IDB_START_PRINT1_BITMAP,IDB_START_PRINT2_BITMAP,0,0,IDB_START_PRINT1_BITMAP);
	m_StartPrint.SizeToContent(); 
	m_PausePrint.LoadBitmaps(IDB_PAUSE_PRINT1_BITMAP,IDB_PAUSE_PRINT2_BITMAP,0,0,IDB_PAUSE_PRINT1_BITMAP);
	m_PausePrint.SizeToContent(); 
	//dealmxl.WriteXml(_T("LoadConfig.xml"),_T("Value"),_T("100"),_T("Storage Card\\System"));
	//m_PictureMain.Invalidate();
	theApp.SetProgressBar(95);


#ifndef _DEBUG
//#ifdef def_ttl
	//串口初始化
	theApp.InitCommMsg();
#endif

	//CTime localT=CTime::GetCurrentTime(); //时间类，以后日期用这个！！
	//string timeErr="Storage Card\\System\\Error\\";
	//timeErr=timeErr+OBJ_Control::to_String(localT.GetYear())+OBJ_Control::to_String(localT.GetMonth())+OBJ_Control::to_String(localT.GetDay())+".txt";
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
		theApp.m_MessageEdit.labName="Default.lab";
		theApp.m_MessageEdit.labPath="Storage Card\\User\\Label";
		theApp.m_MessageEdit.createLABXML();
		GetDlgItem(IDC_STATIC_LABNAME)->SetWindowText(_T("Default.lab"));
	}
	delete testFile;
	/*dealmxl.WriteXml(_T("LoadConfig.xml"),_T("Value"),_T("80"),_T("Storage Card\\System"));*/
	//theApp.myStatusClass.download_inksystem_control03();


	//Sleep(10);
	//theApp.readCount=theApp.myCIOVsd.Read();
 //   theApp.TTLcom=AfxBeginThread(TTLcomLoop,NULL,THREAD_PRIORITY_HIGHEST);
	//SetTimer(TIMER1,300,NULL);	
    //墨水配置初始化
	CInksystemconfig pInksysConfig(this);
	CPcfConfig pPcfConfig(this);
	pInksysConfig.get_inksystem_from_xml();
	pInksysConfig.download_inksystem_setup();
	theApp.myStatusClass.download_inksystem_control03();// ?
	pInksysConfig.download_inksystem_parameter();
	
	pPcfConfig.get_pcf_from_xml();
	pPcfConfig.download_pcf();

	GetDlgItem(IDC_STATIC_PCFNAME)->SetWindowText(pPcfConfig.m_pcfName);
	m_Confi->pcfNameDlg = pPcfConfig.m_pcfName;
	//dealmxl.WriteXml(_T("LoadConfig.xml"),_T("Value"),_T("100"),_T("Storage Card\\System"));
#ifndef _DEBUG
//#ifdef def_ttl

	LPTSTR strTempCmd;
	BYTE readArr[8]={0x1,0x80,0x3,0x8f,0x0,0x25,0xaa,0x55};
	strTempCmd=(LPTSTR)readArr;	 
	theApp.myCIOVsd.Send(strTempCmd,8);
	Sleep(10);
	theApp.readCount=theApp.myCIOVsd.Read();
 
	theApp.TTLcom=AfxBeginThread(TTLcomLoop,NULL,THREAD_PRIORITY_HIGHEST);
	//定时器初始化 (不要在定时器后面初始化)
		

#endif 	
	theApp.SetProgressBar(100);

    int iFullWidth  = GetSystemMetrics(SM_CXSCREEN);
	int iFullHeight = GetSystemMetrics(SM_CYSCREEN);
	::SetWindowPos(this->m_hWnd, HWND_TOPMOST,0,0,iFullWidth, iFullHeight,SWP_NOOWNERZORDER|SWP_SHOWWINDOW);

	SetTimer(TIMER1,300,NULL);
	m_pNumKey = NULL;
	//GetDlgItem(IDC_PAUSEPRINT_BUTTON)->SetFocus();
	//HWND hWnd = NULL;
	//hWnd = ::FindWindow(NULL,_T("Load"));
	//if (hWnd == NULL)
	//{
	//	return TRUE;
	//}
	//
	//DWORD dwProcessId;
	////得到该窗口的进程ID
	//GetWindowThreadProcessId(hWnd,&dwProcessId);
	////从进程ID打开进程句柄
	//HANDLE handle = OpenProcess(0,false,dwProcessId);
	////强制终止进程
	//TerminateProcess(handle,0);
	//::SendMessage(hWnd,WM_CLOSE,0,0);
	/*dealmxl.WriteXml(_T("LoadConfig.xml"),_T("Value"),_T("100"),_T("Storage Card\\System"));*/
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

void CCodePrinterDlg::OpenNumKeyBoard(CEdit * pWnd,int dlgNum)
{
	if(!m_pNumKey)
	{
		m_pNumKey = new CNumKey();
		m_pNumKey->Create( IDD_DIALOG_NUMKEY,pWnd->GetParent()); 
		m_pNumKey->m_dlgNum = dlgNum;
		m_pNumKey->m_edit = pWnd;
		m_pNumKey->ShowWindow(SW_SHOW);
		m_pNumKey->m_pCodePrinterDlg = this;
	}
}

void CCodePrinterDlg::OnBnClickedFaultButton()
{
	// TODO: 在此添加控件通知处理程序代码
	m_Fault->get_save_error();

	m_Fault->openfailurefile("Storage Card\\System\\Error\\99999999.txt");
	//保存操作提示字符串，等该故障窗口关闭后再恢复显示。
	if(m_PicHead.m_bShowLogo == true)
		m_Fault->m_strPreOperation = _T("");
	else
		m_Fault->m_strPreOperation = m_PicHead.m_strOperation;
	m_PicHead.SetOperationString(_T("故障")); //Fault System

	m_Fault->GetDlgItem(IDC_MUL_LANGV_STATIC)->SetWindowText(NULL);//清空翻译
	showDlg(IDD_FAULT_DIALOG);
	m_Fault->ShowWindow(SW_SHOW);	
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
	//showDlg(IDD_ONOFF_DIALOG);
	COnOffDlg OnOffDlg;
    OnOffDlg.DoModal();	
}
//开始喷印
void CCodePrinterDlg::OnBnClickedStartprintButton()
{
 // TODO: 在此添加控件通知处理程序代码
	if (theApp.myStatusClass.ctr0X03bit0 == 1 && theApp.myPcfClass.pcf0X00bit4 == 1)
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

void CCodePrinterDlg::OnBnClickedResetSerialBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	showDlg(IDD_RESET_SERIAL_DIALOG);
}

void CCodePrinterDlg::showDlg(int ID)
{
	theApp.boDrawMainPic = false;
	m_Fault->ShowWindow(SW_HIDE);
	m_System->ShowWindow(SW_HIDE);
	m_User->ShowWindow(SW_HIDE);
	m_Label->ShowWindow(SW_HIDE);
	m_Confi->ShowWindow(SW_HIDE);
	m_FileMan->ShowWindow(SW_HIDE);
	m_Ink->ShowWindow(SW_HIDE);
	m_resetSerial->ShowWindow(SW_HIDE);
	wstring tempstr,tempstr2;
	CString cstr,cstr2;
	if(ID == IDD_SYSTEM_DIALOG)
	{
		tempstr=theApp.myLanguage.LanguageMap["ID_SYSTEM_MANAGEMENT"];
		tempstr2 = theApp.myLanguage.LanguageMap["ID_SYSTEM_NETWORK"];
		cstr = tempstr.c_str();
		cstr2 = tempstr2.c_str();
		m_System->ShowWindow(SW_SHOW);
	    m_PicHead.SetOperationString(cstr+_T(" > ")+cstr2);//System Manage 
	}
	else if (ID == IDD_USER_DIALOG)
	{
		tempstr=theApp.myLanguage.LanguageMap["ID_USER_MANAGEMENT"];
		cstr = tempstr.c_str();
		m_User->ShowWindow(SW_SHOW);
	    m_PicHead.SetOperationString(cstr);//User Manage 
	}
	else if(ID == IDD_LABEL_DIALOG)
	{
		tempstr=theApp.myLanguage.LanguageMap["ID_LABEL_MANAGEMENT"];
		cstr = tempstr.c_str();
		m_Label->ShowWindow(SW_SHOW);
	    m_PicHead.SetOperationString(cstr); //Label Manage
	}
	else if(ID == IDD_CONFIGURATION_DIALOG)
	{
		tempstr=theApp.myLanguage.LanguageMap["ID_CONFIGURATION_MANAGEMENT"];
		cstr = tempstr.c_str();
		m_Confi->ShowWindow(SW_SHOW);
	    m_PicHead.SetOperationString(cstr); //Configure
	}

	else if(ID == IDD_FILEMANA_DIALOG)
	{
		tempstr=theApp.myLanguage.LanguageMap["ID_FILE_MANAGEMENT"];
		cstr = tempstr.c_str();
		//m_FileMan->ShowWindow(SW_SHOW);
		 m_PicHead.SetOperationString(cstr); //File Manage
		TCHAR path[MAX_PATH];
		//labModule.string2tchar(testpath,path);
		
		string xmlPath;
		ShowPathDlg(path, MAX_PATH,0,theApp.myUserPower.booFileManage);
		//ShowWindow(SW_SHOW);
		//GetDlgItem(IDC_STATIC_SHOW_DLG)->SetWindowText(_T("File Manage"));
		m_PicHead.ShowLogo(true);
	}
	else if(ID == IDD_INKSYSTEM_DIALOG)
	{
		tempstr=theApp.myLanguage.LanguageMap["ID_INKSYSTEM_MANAGEMENT"];
		tempstr2 = theApp.myLanguage.LanguageMap["ID_INKSYSTEM_USUAL"];
		cstr = tempstr.c_str();
		cstr2 = tempstr2.c_str();
		m_Ink->ShowWindow(SW_SHOW);
	    m_PicHead.SetOperationString(cstr+_T(" > ")+cstr2);// Ink System
	}
	else if (ID == IDD_FAULT_DIALOG)
	{
		tempstr=theApp.myLanguage.LanguageMap["ID_ERROR_INFORMATION"];
		cstr = tempstr.c_str();
		m_Fault->ShowWindow(SW_SHOW);
	    m_PicHead.SetOperationString(cstr); //Fault System
	}
	/*else if (ID == IDD_ONOFF_DIALOG)
	{
		m_OnOff->ShowWindow(SW_SHOW);
	}*/
	else if(ID == IDD_RESET_SERIAL_DIALOG)
	{
		m_resetSerial->boDlgOpen=true;
		m_resetSerial->GetDlgItem(IDC_SERIAL1_QUAD1_STATIC)->SetWindowText(_T(""));
		m_resetSerial->GetDlgItem(IDC_SERIAL1_QUAD2_STATIC)->SetWindowText(_T(""));
		m_resetSerial->GetDlgItem(IDC_SERIAL1_CUR_STATIC)->SetWindowText(_T(""));
		m_resetSerial->GetDlgItem(IDC_SET_VALUE1_EDIT)->SetWindowText(_T(""));

		m_resetSerial->GetDlgItem(IDC_SERIAL2_QUAD1_STATIC)->SetWindowText(_T(""));
		m_resetSerial->GetDlgItem(IDC_SERIAL2_QUAD2_STATIC)->SetWindowText(_T(""));
		m_resetSerial->GetDlgItem(IDC_SERIAL2_CUR_STATIC)->SetWindowText(_T(""));
		m_resetSerial->GetDlgItem(IDC_SET_VALUE2_EDIT)->SetWindowText(_T(""));

		m_resetSerial->GetDlgItem(IDC_SERIAL3_QUAD1_STATIC)->SetWindowText(_T(""));
		m_resetSerial->GetDlgItem(IDC_SERIAL3_QUAD2_STATIC)->SetWindowText(_T(""));
		m_resetSerial->GetDlgItem(IDC_SERIAL3_CUR_STATIC)->SetWindowText(_T(""));
		m_resetSerial->GetDlgItem(IDC_SET_VALUE3_EDIT)->SetWindowText(_T(""));

		m_resetSerial->GetDlgItem(IDC_SERIAL4_QUAD1_STATIC)->SetWindowText(_T(""));
		m_resetSerial->GetDlgItem(IDC_SERIAL4_QUAD2_STATIC)->SetWindowText(_T(""));
		m_resetSerial->GetDlgItem(IDC_SERIAL4_CUR_STATIC)->SetWindowText(_T(""));
		m_resetSerial->GetDlgItem(IDC_SET_VALUE4_EDIT)->SetWindowText(_T(""));

		for (int i = 0;i < theApp.m_MessagePrint.OBJ_Vec.size();i++)
		{
			if (theApp.m_MessagePrint.OBJ_Vec.at(i)->strType2 == "serial")
			{
				switch(theApp.m_MessagePrint.OBJ_Vec.at(i)->intSerialCounter)
				{
				case 0:
						m_resetSerial->GetDlgItem(IDC_SERIAL1_QUAD1_STATIC)->SetWindowText(theApp.myModuleMain.string2CString(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->intSerialFirstLimit)));
						m_resetSerial->GetDlgItem(IDC_SERIAL1_QUAD2_STATIC)->SetWindowText(theApp.myModuleMain.string2CString(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->intSerialSecondLimit)));
						m_resetSerial->GetDlgItem(IDC_SERIAL1_CUR_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->CountNum)));
						m_resetSerial->GetDlgItem(IDC_SET_VALUE1_EDIT)->SetWindowText(theApp.myModuleMain.string2CString(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->intSerialStartValue)));
					//GetDlgItem(IDC_SEQUENCE1_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->CountNum)));
					break;
				case 1:
					m_resetSerial->GetDlgItem(IDC_SERIAL2_QUAD1_STATIC)->SetWindowText(theApp.myModuleMain.string2CString(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->intSerialFirstLimit)));
					m_resetSerial->GetDlgItem(IDC_SERIAL2_QUAD2_STATIC)->SetWindowText(theApp.myModuleMain.string2CString(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->intSerialSecondLimit)));
					m_resetSerial->GetDlgItem(IDC_SERIAL2_CUR_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->CountNum)));
					m_resetSerial->GetDlgItem(IDC_SET_VALUE2_EDIT)->SetWindowText(theApp.myModuleMain.string2CString(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->intSerialStartValue)));
					//GetDlgItem(IDC_SEQUENCE2_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->CountNum)));
					break;
				case 2:
					m_resetSerial->GetDlgItem(IDC_SERIAL3_QUAD1_STATIC)->SetWindowText(theApp.myModuleMain.string2CString(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->intSerialFirstLimit)));
					m_resetSerial->GetDlgItem(IDC_SERIAL3_QUAD2_STATIC)->SetWindowText(theApp.myModuleMain.string2CString(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->intSerialSecondLimit)));
					m_resetSerial->GetDlgItem(IDC_SERIAL3_CUR_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->CountNum)));
					m_resetSerial->GetDlgItem(IDC_SET_VALUE3_EDIT)->SetWindowText(theApp.myModuleMain.string2CString(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->intSerialStartValue)));
					//GetDlgItem(IDC_SEQUENCE3_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->CountNum)));
					break;
				case 3:
					m_resetSerial->GetDlgItem(IDC_SERIAL4_QUAD1_STATIC)->SetWindowText(theApp.myModuleMain.string2CString(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->intSerialFirstLimit)));
					m_resetSerial->GetDlgItem(IDC_SERIAL4_QUAD2_STATIC)->SetWindowText(theApp.myModuleMain.string2CString(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->intSerialSecondLimit)));
					m_resetSerial->GetDlgItem(IDC_SERIAL4_CUR_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->CountNum)));
					m_resetSerial->GetDlgItem(IDC_SET_VALUE4_EDIT)->SetWindowText(theApp.myModuleMain.string2CString(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->intSerialStartValue)));
					//GetDlgItem(IDC_SEQUENCE4_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->CountNum)));
					break;
				}
			}
		}
		m_resetSerial->ShowWindow(SW_SHOW);
		
	}
}

void CCodePrinterDlg::UpdateValve()
{
	//更新阀的信息
	if (theApp.myUserPower.booInkAdvance)
	{
		HWND advan;
		advan = m_Ink->m_inkAdv->GetSafeHwnd();
		theApp.myStatusClass.ad_button_onoff(advan);
	}
	if (theApp.myUserPower.booInkUsual)
	{
		HWND usua;
		usua = m_Ink->GetSafeHwnd();
		theApp.myStatusClass.us_button_onoff(usua);
	}
	
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
  //  m_Fault->m_faultList.ResetContent();    
	//墨水温度传感器故障
    if (theApp.myStatusClass.staInkTemSenFau == true && m_Fault->m_staInkTemSenFauLas == false)
	{
		/*theApp.myStatusClass.staInkTemSenFauLas = true;*/
		m_Fault->m_staInkTemSenFauLas = true;
		CString csMsg ;
		csMsg.Format(_T("Ink temperature sensor fault"));
		string m_tmpt;
		m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Yellow" + "               ";
		csMsg = theApp.myModuleMain.string2CString(m_tmpt) + csMsg;
		m_Fault->m_faultList.AddString(csMsg);		
		m_Fault->m_faultList.SetFont(theApp.m_StaticFont);
	}
	else if(theApp.myStatusClass.staInkTemSenFau == false && m_Fault->m_staInkTemSenFauLas == true)
	{
	   m_Fault->m_staInkTemSenFauLas = false;
	}

	//喷头温度传感器故障
	if (theApp.myStatusClass.staPriHeaTemFau == true && m_Fault->m_staPriHeaTemFauLas == false)
	{
	/*	theApp.myStatusClass.staPriHeaTemFauLas = true;*/
		m_Fault->m_staPriHeaTemFauLas = true;
		CString csMsg ;
		csMsg.Format(_T("Printhead temperature sensor fault"));
		string m_tmpt;
		m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Yellow" + "               ";
		csMsg = theApp.myModuleMain.string2CString(m_tmpt) + csMsg;
		m_Fault->m_faultList.AddString(csMsg);
		m_Fault->m_faultList.SetFont(theApp.m_StaticFont);
	}
	else if (theApp.myStatusClass.staPriHeaTemFau == false && m_Fault->m_staPriHeaTemFauLas == true)
	{
		m_Fault->m_staPriHeaTemFauLas = false;
	}

	//泵超速保护
	if (theApp.myStatusClass.staBumSpeOveFau == true && m_Fault->m_staBumSpeOveFauLas == false)
	{
		//theApp.myStatusClass.staBumSpeOveFauLas = true;
		m_Fault->m_staBumSpeOveFauLas = true;
		//缺starting up

		/*m_Onoff->SetWindowText(_T("Starting Up"));*/

		theApp.myStatusClass.ctr0X03bit0 = 0;
		theApp.myStatusClass.download_inksystem_control03();
		theApp.myStatusClass.ctr0X00bit5 = 0;
		theApp.myStatusClass.ctr0X00bit3 = 0;
		theApp.myStatusClass.ctr0X00bit2 = 0;
		theApp.myStatusClass.ctr0X00bit1 = 1;
		theApp.myStatusClass.ctr0X00bit0 = 0;
		theApp.myStatusClass.download_inksystem_control00();
		CString csMsg ;
		csMsg.Format(_T("Pump speed abnormal"));
		string m_tmpt;
		m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Red" + "               ";
		csMsg = theApp.myModuleMain.string2CString(m_tmpt) + csMsg;
		m_Fault->m_faultList.AddString(csMsg);
		m_Fault->m_faultList.SetFont(theApp.m_StaticFont);
	}
	else if (theApp.myStatusClass.staBumSpeOveFau == false && m_Fault->m_staBumSpeOveFauLas == true)
	{
		m_Fault->m_staBumSpeOveFauLas = false;
	}


	//过压保护
	if (theApp.myStatusClass.staPreOveFau == true && m_Fault->m_staPreOveFauLas == false)
	{
		//theApp.myStatusClass.staPreOveFauLas = true;
		m_Fault->m_staPreOveFauLas = true;
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
		csMsg.Format(_T("Pressure abnormal"));
		string m_tmpt;
		m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Red" + "               ";
		csMsg = theApp.myModuleMain.string2CString(m_tmpt) + csMsg;
		m_Fault->m_faultList.AddString(csMsg);
		m_Fault->m_faultList.SetFont(theApp.m_StaticFont);
	}
	else if (theApp.myStatusClass.staPreOveFau == false && m_Fault->m_staPreOveFauLas == true)
	{
		m_Fault->m_staPreOveFauLas = false;
	}


	//粘度异常
	if (theApp.myStatusClass.staVisAbnFau == true && m_Fault->m_staVisAbnFauLas == false)
	{
		//theApp.myStatusClass.staVisAbnFauLas = true;
		m_Fault->m_staVisAbnFauLas = true;
		CString csMsg ;
		csMsg.Format(_T("Ink Visco abnormal"));
		string m_tmpt;
		m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Yellow" + "               ";
		csMsg = theApp.myModuleMain.string2CString(m_tmpt) + csMsg;
		m_Fault->m_faultList.AddString(csMsg);
		m_Fault->m_faultList.SetFont(theApp.m_StaticFont);
	}
	else if (theApp.myStatusClass.staVisAbnFau == false && m_Fault->m_staVisAbnFauLas == true)
	{
		m_Fault->m_staVisAbnFauLas = false;
	}


	//粘度计故障
	if (theApp.myStatusClass.staVisSenFau == true && m_Fault->m_staVisSenFauLas == false)
	{
		//theApp.myStatusClass.staVisSenFauLas = true;
		m_Fault->m_staVisSenFauLas = true;
		CString csMsg ;
		csMsg.Format(_T("Viscometer fault"));
		string m_tmpt;
		m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Yellow" + "               ";
		csMsg = theApp.myModuleMain.string2CString(m_tmpt) + csMsg;
		m_Fault->m_faultList.AddString(csMsg);
		m_Fault->m_faultList.SetFont(theApp.m_StaticFont);
	}
	else if (theApp.myStatusClass.staVisSenFau == false && m_Fault->m_staVisSenFauLas == true)
	{
		m_Fault->m_staVisSenFauLas = false;
	}


	//回收故障
	if(theApp.myStatusClass.staInkFloSenOff == true)
	{
       theApp.myStatusClass.staInkFloFau = true;
	   m_Ink->GetDlgItem(IDC_INKFLOW_EDIT)->SetWindowText(_T("Disable"));
	}
	else
	{
		if (theApp.myStatusClass.staInkFloFau == true && m_Fault->m_staInkFloFauLas == false)
		{
			//theApp.myStatusClass.staInkFloFauLas = true;
			m_Fault->m_staInkFloFauLas = true;
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
			csMsg.Format(_T("Recyle fault"));
			string m_tmpt;
			m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Red" + "               ";
			csMsg = theApp.myModuleMain.string2CString(m_tmpt) + csMsg;
			m_Fault->m_faultList.AddString(csMsg);
			m_Fault->m_faultList.SetFont(theApp.m_StaticFont);
			m_Ink->GetDlgItem(IDC_INKFLOW_EDIT)->SetWindowText(_T("Abnormal"));
		}		
		
		else if (theApp.myStatusClass.staInkFloFau == false)
		{
			if (m_Fault->m_staInkFloFauLas == true  )
			{
				m_Fault->m_staInkFloFauLas = false;
				
			}
			m_Ink->GetDlgItem(IDC_INKFLOW_EDIT)->SetWindowText(_T("Normal"));
		}
	}


	//风扇故障
	if (theApp.myStatusClass.staFanFau == true && m_Fault->m_staFanFauLas == false)
	{
		//theApp.myStatusClass.staFanFauLas = true;
		 m_Fault->m_staFanFauLas = true;
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
		csMsg.Format(_T("Fan fault"));
		string m_tmpt;
		m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Red" + "               ";
		csMsg = theApp.myModuleMain.string2CString(m_tmpt) + csMsg;
		m_Fault->m_faultList.AddString(csMsg);
		m_Fault->m_faultList.SetFont(theApp.m_StaticFont);
	}
	else if (theApp.myStatusClass.staFanFau == false && m_Fault->m_staFanFauLas == true)
	{
		 m_Fault->m_staFanFauLas = false;
	}


	//充电故障
	if (theApp.myStatusClass.staChaFau == true && m_Fault->m_staChaFauLas == false)
	{
		//theApp.myStatusClass.staChaFauLas = true;
		m_Fault->m_staChaFauLas = true;
		m_PicHead.SetMachineStatus(_T("充电故障"));//Charge fault

		theApp.myStatusClass.ctr0X03bit0 = 0;
		theApp.myStatusClass.download_inksystem_control03();
		CString csMsg ;
		csMsg.Format(_T("充电故障"));//Charge fault
		string m_tmpt;
		m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Yellow" + "               ";
		csMsg = theApp.myModuleMain.string2CString(m_tmpt) + csMsg;
		m_Fault->m_faultList.AddString(csMsg);
		m_Fault->m_faultList.SetFont(theApp.m_StaticFont);
	}
	else if (theApp.myStatusClass.staChaFau == false && m_Fault->m_staChaFauLas == true)
	{
		m_Fault->m_staChaFauLas = false;
	}


	//相位故障
	if (theApp.myStatusClass.staPhaFau == true && m_Fault->m_staPhaFauLas == false)
	{
		//theApp.myStatusClass.staPhaFauLas = true;
		m_Fault->m_staPhaFauLas = true;
		m_PicHead.SetMachineStatus(_T("相位故障"));//Phase fault

		theApp.myStatusClass.ctr0X03bit0 = 0;
		theApp.myStatusClass.download_inksystem_control03();
		CString csMsg ;
		csMsg.Format(_T("相位故障"));//Phase fault
		string m_tmpt;
		m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Yellow" + "               ";
		csMsg = theApp.myModuleMain.string2CString(m_tmpt) + csMsg;
		m_Fault->m_faultList.AddString(csMsg);
		m_Fault->m_faultList.SetFont(theApp.m_StaticFont);
	}
	else if (theApp.myStatusClass.staPhaFau == false && m_Fault->m_staPhaFauLas == true)
	{
		m_Fault->m_staPhaFauLas = false;
	}


	//高压故障
	if (theApp.myStatusClass.staHigVolFau == true && m_Fault->m_staHigVolFauLas == false)
	{
		//theApp.myStatusClass.staHigVolFauLas = true;
		m_Fault->m_staHigVolFauLas = true;
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
		csMsg.Format(_T("高压故障"));//High voltage faul
		string m_tmpt;
		m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Red" + "               ";
		csMsg = theApp.myModuleMain.string2CString(m_tmpt) + csMsg;
		m_Fault->m_faultList.AddString(csMsg);
		m_Fault->m_faultList.SetFont(theApp.m_StaticFont);
	}
	else if (theApp.myStatusClass.staHigVolFau == false && m_Fault->m_staHigVolFauLas == true)
	{
		m_Fault->m_staHigVolFauLas = false;
	}


	//溶剂液位状态
	if (theApp.myStatusClass.staSolLevFau == "00" && m_Fault->m_staSolLevFauLas != "00" && theApp.myStatusClass.staInkLevFau == "00")
	{
		//theApp.myTimClass.staSolLevFauLas = "00";
		m_Fault->m_staSolLevFauLas = "00";
		m_PicHead.SetBlueAlarm(false);
	}
	else if (theApp.myStatusClass.staSolLevFau == "01" && m_Fault->m_staSolLevFauLas != "01")
	{
		//theApp.myTimClass.staSolLevFauLas = "01";
		m_Fault->m_staSolLevFauLas = "01";
		CString csMsg;
		csMsg.Format(_T("Add solvent"));
		string m_tmpt;
		m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Blue" + "               ";
		csMsg = theApp.myModuleMain.string2CString(m_tmpt) + csMsg;
		m_Fault->m_faultList.AddString(csMsg);
		m_Fault->m_faultList.SetFont(theApp.m_StaticFont);
		/*picAlarmBlue.Tag = "im003"
		picAlarmBlue.Image = My.Resources.ResourceBng.im003*/
		m_PicHead.SetBlueAlarm(true);
	}
	else if (theApp.myStatusClass.staSolLevFau == "10" && m_Fault->m_staSolLevFauLas != "10")
	{
		//theApp.myTimClass.staSolLevFauLas = "10";
		m_Fault->m_staSolLevFauLas = "10";
		m_PicHead.SetBlueAlarm(true);
		/*picAlarmBlue.Tag = "im003"
		picAlarmBlue.Image = My.Resources.ResourceBng.im003*/
		CString csMsg ;
		csMsg.Format(_T("Solvent empty"));
		string m_tmpt;
		m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Blue" + "               ";
		csMsg = theApp.myModuleMain.string2CString(m_tmpt) + csMsg;
		m_Fault->m_faultList.AddString(csMsg);
		m_Fault->m_faultList.SetFont(theApp.m_StaticFont);
	}
	else if (theApp.myStatusClass.staSolLevFau == "11" && m_Fault->m_staSolLevFauLas != "11")
	{
		//theApp.myTimClass.staSolLevFauLas = "11";
		m_Fault->m_staSolLevFauLas = "11";
		m_PicHead.SetBlueAlarm(true);
		/*picAlarmBlue.Tag = "im003"
		picAlarmBlue.Image = My.Resources.ResourceBng.im003*/
		CString csMsg ;
		csMsg.Format(_T("Solvent overfull"));
		string m_tmpt;
		m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Blue" + "               ";
		csMsg = theApp.myModuleMain.string2CString(m_tmpt) + csMsg;
		m_Fault->m_faultList.AddString(csMsg);
		m_Fault->m_faultList.SetFont(theApp.m_StaticFont);
	}

	//墨水液位状态
	if (theApp.myStatusClass.staInkLevFau == "00" && m_Fault->m_staInkLevFauLas != "00" && theApp.myStatusClass.staSolLevFau == "00")
	{
		//theApp.myTimClass.staInkLevFauLas = "00";
		m_Fault->m_staInkLevFauLas = "00";
		m_PicHead.SetBlueAlarm(false);
		/*picAlarmBlue.Tag = "im004"
		picAlarmBlue.Image = My.Resources.ResourceBng.im004*/
		theApp.myTimClass.staInkEmpFau = false;
		theApp.myTimClass.staInkOveFau = false;
	}
	else if (theApp.myStatusClass.staInkLevFau == "01" && m_Fault->m_staInkLevFauLas != "01")
	{
		//theApp.myTimClass.staInkLevFauLas = "01";
		m_Fault->m_staInkLevFauLas = "01";
		m_PicHead.SetBlueAlarm(true);
		/*picAlarmBlue.Tag = "im003"
		picAlarmBlue.Image = My.Resources.ResourceBng.im003*/
		theApp.myTimClass.staInkEmpFau = false;
		theApp.myTimClass.staInkOveFau = false;
		CString csMsg ;
		csMsg.Format(_T("Add ink"));
		string m_tmpt;
		m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Blue" + "               ";
		csMsg = theApp.myModuleMain.string2CString(m_tmpt) + csMsg;
		m_Fault->m_faultList.AddString(csMsg);
		m_Fault->m_faultList.SetFont(theApp.m_StaticFont);
	}
	else if (theApp.myStatusClass.staInkLevFau == "10" && m_Fault->m_staInkLevFauLas != "10")
	{
		//theApp.myTimClass.staInkLevFauLas = "10";
		m_Fault->m_staInkLevFauLas = "10";
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
		string m_tmpt;
		m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Blue" + "               ";
		csMsg = theApp.myModuleMain.string2CString(m_tmpt) + csMsg;
		m_Fault->m_faultList.AddString(csMsg);
		m_Fault->m_faultList.SetFont(theApp.m_StaticFont);
	}
	else if (theApp.myStatusClass.staInkLevFau == "11" && m_Fault->m_staInkLevFauLas != "11")
	{
		//theApp.myTimClass.staInkLevFauLas = "11";
		m_Fault->m_staInkLevFauLas = "11";
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
		string m_tmpt;
		m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Blue" + "               ";
		csMsg = theApp.myModuleMain.string2CString(m_tmpt) + csMsg;
		m_Fault->m_faultList.AddString(csMsg);
		m_Fault->m_faultList.SetFont(theApp.m_StaticFont);

    }

	//电眼过快
	if (theApp.myStatusClass.staProSenFas == true && m_Fault->m_staProSenFasLas == false)
	{
		//theApp.myStatusClass.staProSenFasLas = true;
		m_Fault->m_staProSenFasLas = true;
		CString csMsg ;
		csMsg.Format(_T("Much too product"));
		string m_tmpt;
		m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Yellow" + "               ";
		csMsg = theApp.myModuleMain.string2CString(m_tmpt) + csMsg;
		m_Fault->m_faultList.AddString(csMsg);
		m_Fault->m_faultList.SetFont(theApp.m_StaticFont);
	}
	else if (theApp.myStatusClass.staProSenFas == false && m_Fault->m_staProSenFasLas == true)
	{
		m_Fault->m_staProSenFasLas = false;
	}

	//自动分裂失败
	if (theApp.myStatusClass.staAutModFau == true && m_Fault->m_staAutModFauLas == false)
	{
		//theApp.myStatusClass.staAutModFauLas = true;
		m_Fault->m_staAutModFauLas = true;
		m_PicHead.SetMachineStatus(_T("Fault Condition"));

		theApp.myStatusClass.ctr0X03bit0 = 0;
		theApp.myStatusClass.download_inksystem_control03();
		CString csMsg ;
		csMsg.Format(_T("Auto modulation fault"));
		string m_tmpt;
		m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Yellow" + "               ";
		csMsg = theApp.myModuleMain.string2CString(m_tmpt) + csMsg;
		m_Fault->m_faultList.AddString(csMsg);
		m_Fault->m_faultList.SetFont(theApp.m_StaticFont);
	}
	else if (theApp.myStatusClass.staAutModFau == false && m_Fault->m_staAutModFauLas == true)
	{
		m_Fault->m_staAutModFauLas = false;
	}

	//阀故障
	if(theApp.myStatusClass.staValFau == true && m_Fault->m_staValFauLas == false) 
	{
		//theApp.myStatusClass.staValFauLas = true;
		m_Fault->m_staValFauLas = true;
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
		string m_tmpt;
		m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Red" + "               ";
		csMsg = theApp.myModuleMain.string2CString(m_tmpt) + csMsg;
		m_Fault->m_faultList.AddString(csMsg);
		m_Fault->m_faultList.SetFont(theApp.m_StaticFont);
	}
	else if(theApp.myStatusClass.staValFau == false && m_Fault->m_staValFauLas == true) 
	{
		m_Fault->m_staValFauLas = false;
	}

	//编码器过快
	if (theApp.myStatusClass.staLinFas == true && m_Fault->m_staLinFasLas == false )
	{
		//theApp.myStatusClass.staLinFasLas = true;
		m_Fault->m_staLinFasLas = true;
		CString csMsg ;
		csMsg.Format(_T("Too fast"));
		string m_tmpt;
		m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Yellow" + "               ";
		csMsg = theApp.myModuleMain.string2CString(m_tmpt) + csMsg;
		m_Fault->m_faultList.AddString(csMsg);
		m_Fault->m_faultList.SetFont(theApp.m_StaticFont);
	}
	else if (theApp.myStatusClass.staLinFas == false && m_Fault->m_staLinFasLas == true )
	{
		m_Fault->m_staLinFasLas = false;
	}

	//恒温故障
	if (theApp.myStatusClass.staPriHeaHotFau == true && m_Fault->m_staPriHeaHotFauLas == false )
	{
		//theApp.myStatusClass.staPriHeaHotFauLas = true;
		m_Fault->m_staPriHeaHotFauLas = true;
		CString csMsg ;
		csMsg.Format(_T("Constant temperature fault"));
		string m_tmpt;
		m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Yellow" + "               ";
		csMsg = theApp.myModuleMain.string2CString(m_tmpt) + csMsg;
		m_Fault->m_faultList.AddString(csMsg);
		m_Fault->m_faultList.SetFont(theApp.m_StaticFont);
	}
	else if (theApp.myStatusClass.staPriHeaHotFau == false && m_Fault->m_staPriHeaHotFauLas == true )
	{
		m_Fault->m_staPriHeaHotFauLas = false;
	}
	    m_Fault->m_faultList.SetItemHeight(0,35);
}


void CCodePrinterDlg::UpdatePhase()
{
	if (theApp.myTimClass.staPhaseLas != theApp.myStatusClass.staPhase)
	{
		m_Ink->m_phas->m_PicPhaAngle.SetBitmap(m_Ink->m_phas->m_AnglehBmp[theApp.myStatusClass.staPhase]);
		theApp.myTimClass.staPhaseLas = theApp.myStatusClass.staPhase;
		m_Ink->m_phas->m_PicPhaAngle.Invalidate();
	}
}

//定时器
void CCodePrinterDlg::OnTimer(UINT_PTR nIDEvent)
{
	CDialog::OnTimer(nIDEvent);
	wstring Readytoprint,Systemready,SequencingOn,SequencingOff,PrinterOff;
	Readytoprint=theApp.myLanguage.LanguageMap["IDC_READY_TO_PRINT"];
	Systemready=theApp.myLanguage.LanguageMap["IDC_SYSTEM_READY"];
	SequencingOn=theApp.myLanguage.LanguageMap["IDC_SEQUENCING_ON"];
	SequencingOff=theApp.myLanguage.LanguageMap["IDC_SEQUENCING_OFF"];
	PrinterOff=theApp.myLanguage.LanguageMap["IDC_PRINTER_OFF"];
	switch(nIDEvent)
		
	case TIMER1:
	{
		//系统日期
		CTime tmSCan=CTime::GetCurrentTime();
		CString szTime=tmSCan.Format(_T("%Y-%m-%d %H:%M:%S"));
		GetDlgItem(IDC_TIME_STATIC)->SetWindowText(szTime);
		//KillTimer(TIMER1);
		if (theApp.myUserPower.isChangeUser)
		{
		 ChangeBottonEnable();
		 theApp.myUserPower.isChangeUser=false;
		}
		//日期
		m_currentDate = theApp.myModuleMain.CString2string(tmSCan.Format(_T("%Y/%m/%d")));
		//时间
		m_currentTime = theApp.myModuleMain.CString2string(tmSCan.Format(_T("%H:%M:%S")));
		theApp.myStatusClass.byStatusFromSlaveState();
		theApp.myStatusClass.getstatu();
        
		UpdateValve(); //更新各种阀的信息，通过颜色显示出来，蓝色表示没按下去

		GetFaultInfo(); //获得各种故障信息

		
		//开打印中
		if (theApp.myStatusClass.ctr0X03bit0 == 1 && theApp.myStatusClass.staSysRea == true)//开了打印功能和系统准备好
		{
			m_PicHead.SetMachineStatus(Readytoprint.c_str());//Ready to print
 		}
		else if (theApp.myStatusClass.ctr0X03bit0 == 0)//未开打印功能
		{
			if (theApp.myStatusClass.staSysRea == true)//系统准备好
			{				 
				m_PicHead.SetMachineStatus(Systemready.c_str());//System ready
			}
			else if (theApp.myStatusClass.staSysRea == false) //系统未准备好
			{
				if (theApp.myStatusClass.staSysBus == true) //系统忙
				{
					if (theApp.myStatusClass.ctr0X00bit0 == 1 /*&& picAlarmRed.Tag = "im008" && picAlarmYellow.Tag = "im006"*/)//开关机位=1
					{
						m_PicHead.SetMachineStatus(SequencingOn.c_str());//Sequencing On
					}
					else if (theApp.myStatusClass.ctr0X00bit0 == 0 /*&& picAlarmRed.Tag = "im008" && picAlarmYellow.Tag = "im006"*/)//开关机位=0

					{
						m_PicHead.SetMachineStatus(SequencingOff.c_str());//Sequencing Off
					}
				}
				else if (theApp.myStatusClass.staSysBus == false /*&& picAlarmRed.Tag = "im008" && picAlarmYellow.Tag = "im006"*/ )//系统不忙
				{					 
					m_PicHead.SetMachineStatus(PrinterOff.c_str());//Printer Off
				}//系统忙
			}//系统准备好

		}//开了打印功能和系统准备好
		//判断开关机
		if (theApp.myStatusClass.ctr0X00bit0 == 0 && theApp.m_lastOnOffStatue == 1)//关机
		{
			m_ButOnOrOff.LoadBitmaps(IDB_ONOFF1_BITMAP,IDB_ONOFF1_BITMAP,0,0,IDB_ONOFF1_BITMAP);
			m_ButOnOrOff.SizeToContent(); 
			theApp.m_lastOnOffStatue = 0;
		}
		else if (theApp.myStatusClass.ctr0X00bit0 == 1 && theApp.m_lastOnOffStatue == 0)//开机
		{
			m_ButOnOrOff.LoadBitmaps(IDB_ONOFF2_BITMAP,IDB_ONOFF2_BITMAP,0,0,IDB_ONOFF2_BITMAP);
			m_ButOnOrOff.SizeToContent(); 
			theApp.m_lastOnOffStatue = 1;
		}
		//打印按钮的开启
		if (theApp.myStatusClass.ctr0X03bit0 == 0 && theApp.m_lastStartPrint == 1) //开打印功能，1开启
		{
			m_StartPrint.LoadBitmaps(IDB_START_PRINT1_BITMAP,IDB_START_PRINT2_BITMAP,0,0,IDB_START_PRINT1_BITMAP);
			m_StartPrint.SizeToContent(); 
			m_PausePrint.LoadBitmaps(IDB_PAUSE_PRINT3_BITMAP,IDB_PAUSE_PRINT4_BITMAP,0,0,IDB_PAUSE_PRINT3_BITMAP);
			m_PausePrint.SizeToContent(); 
			theApp.m_lastStartPrint = 0;
		}
		else if (theApp.myStatusClass.ctr0X03bit0 == 1 && theApp.m_lastStartPrint == 0)
		{
			m_StartPrint.LoadBitmaps(IDB_START_PRINT3_BITMAP,IDB_START_PRINT4_BITMAP,0,0,IDB_START_PRINT3_BITMAP);
			m_StartPrint.SizeToContent(); 
			m_PausePrint.LoadBitmaps(IDB_PAUSE_PRINT1_BITMAP,IDB_PAUSE_PRINT2_BITMAP,0,0,IDB_PAUSE_PRINT1_BITMAP);
			m_PausePrint.SizeToContent(); 
			theApp.m_lastStartPrint = 1;
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
		m_Ink->GetDlgItem(IDC_PRESSURE_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(OBJ_Control::to_String(theApp.myStatusClass.staPressure)));
		//实时泵速	
		m_Ink->GetDlgItem(IDC_PUMP_SPEED_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(OBJ_Control::to_String(theApp.myStatusClass.staBumSpe)));
		m_Ink->GetDlgItem(IDC_INK_TEMP_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(OBJ_Control::to_String(theApp.myStatusClass.staInkTem)));
		m_Ink->GetDlgItem(IDC_PRINTHEAD_TEMP_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(OBJ_Control::to_String(theApp.myStatusClass.staPriHeaTem)));
		m_Ink->GetDlgItem(IDC_INK_LEV_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(OBJ_Control::to_String(theApp.myStatusClass.staInkLev)));
		m_Ink->GetDlgItem(IDC_SOLVENT_LEV_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(OBJ_Control::to_String(theApp.myStatusClass.staSolLev)));
		m_Ink->GetDlgItem(IDC_TARGET_VISCO_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(OBJ_Control::to_String(theApp.myStatusClass.staTarVis)));
		m_Ink->GetDlgItem(IDC_ACTUAL_VISCO_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR((theApp.myStatusClass.staActVis)>0?OBJ_Control::to_String(theApp.myStatusClass.staActVis):"***"));
		m_Ink->GetDlgItem(IDC_HIGH_VOL_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(OBJ_Control::to_String(theApp.myStatusClass.staHigVol)));


		//实时相位
        UpdatePhase();

		//自动分裂电压
		m_Ink->m_phas->GetDlgItem(IDC_MODULATION_NUM_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(OBJ_Control::to_String(theApp.myStatusClass.staAutModVol)));
		//墨水时间分析改写并显示
		//if (theApp.myStatusClass.staSetTimeEna == false)
		//{
		//	CString m_tmptSetTime;
		//	m_Ink->m_setup->GetDlgItem(IDC_STATIC_TIMEREST_SETUP)->GetWindowText(m_tmptSetTime);
		//	if ( m_tmptSetTime != "Disabled")
		//	{
		//		m_Ink->m_setup->GetDlgItem(IDC_STATIC_TIMEREST_SETUP)->SetWindowText(_T("Disabled"));
		//	}			
		//	string tempLifeTime;
		//	tempLifeTime = OBJ_Control::to_String((theApp.myStatusClass.staInkLifeTime)/60);
		//	CString m_tmptLifeTime;
		//	m_Ink->m_setup->GetDlgItem(IDC_NEXT_SERVICE_EDIT)->GetWindowText(m_tmptLifeTime);
		//	if (theApp.myModuleMain.string2CString(tempLifeTime) != m_tmptLifeTime)
		//	{
		//		m_Ink->m_setup->GetDlgItem(IDC_NEXT_SERVICE_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(tempLifeTime));
		//		m_Ink->m_setup->GetDlgItem(IDC_INK_LIFE_TIME_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(tempLifeTime));
		//	}
		//	CTime localT = CTime::GetCurrentTime(); 				
		//	CTimeSpan m_timeSpan;
		//	m_timeSpan = localT- theApp.myTimClass.InkDateTimLas;
		//	CTimeSpan m_timeSpanWri;
		//	m_timeSpanWri = localT- theApp.myTimClass.dateTimLasWri;
		//	if (theApp.myStatusClass.staInkLifeTime == 0)
		//	{
		//		if (theApp.myTimClass.InkLifeTimeLas > 0 )
		//		{
		//			CString csMsg ;
		//			csMsg.Format(_T("Ink has expired"));
		//			string m_tmpt;
		//			m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Red" + "               ";
		//			csMsg = theApp.myModuleMain.string2CString(m_tmpt) + csMsg;
		//			m_Fault->m_faultList.AddString(csMsg);
		//		}
		//		else if (theApp.myStatusClass.staInkLifeTime < 120) //小于2小时，每分钟提醒一次
		//		{
		//			if ((theApp.myStatusClass.staInkLifeTime+1)< theApp.myTimClass.InkLifeTimeLas)		
		//			{
		//				theApp.myTimClass.InkLifeTimeLas = theApp.myStatusClass.staInkLifeTime;
		//				string m_tmpt;
		//				m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Yellow" + "               " + "Ink life remaining " + OBJ_Control::to_String(theApp.myStatusClass.staInkLifeTime) + "minutes";
		//				m_Fault->m_faultList.AddString(theApp.myModuleMain.string2CString(m_tmpt));
		//			}
		//		}
		//		else if (theApp.myStatusClass.staInkLifeTime < 600)//小于10小时，每十分钟提醒一次
		//		{
		//			if ((theApp.myStatusClass.staInkLifeTime + 10)< theApp.myTimClass.InkLifeTimeLas)		
		//			{
		//				theApp.myTimClass.InkLifeTimeLas = theApp.myStatusClass.staInkLifeTime;
		//				string m_tmpt;
		//				m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Yellow" + "               " + "Ink life remaining " + tempLifeTime + "hours";
		//				m_Fault->m_faultList.AddString(theApp.myModuleMain.string2CString(m_tmpt));
		//			}
		//		}
		//		else if (theApp.myStatusClass.staInkLifeTime < 6000)//小于100小时，每一小时提醒一次
		//		{
		//			if ((theApp.myStatusClass.staInkLifeTime + 60)< theApp.myTimClass.InkLifeTimeLas)		
		//			{
		//				theApp.myTimClass.InkLifeTimeLas = theApp.myStatusClass.staInkLifeTime;
		//				string m_tmpt;
		//				m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Yellow" + "               " + "Ink life remaining " + tempLifeTime + "hours";
		//				m_Fault->m_faultList.AddString(theApp.myModuleMain.string2CString(m_tmpt));
		//			}
		//		}
		//	}
		//	else if (theApp.myStatusClass.staSetTimeEna == true)
		//	{
		//		CTime localT = CTime::GetCurrentTime(); 				
		//		CTimeSpan m_timeSpan;
		//		m_timeSpan = localT- theApp.myTimClass.InkDateTimLas;
		//		CTimeSpan m_timeSpanWri;
		//		m_timeSpanWri = localT- theApp.myTimClass.dateTimLasWri;
		//		if (m_timeSpanWri.GetTotalSeconds()>59)//一分钟写一次维护时间
		//		{
		//			//写XML时间
		//			CDealXml dealXml;
		//			if (theApp.myTimClass.ServiceTimeLasXML > 0)
		//			{
		//				theApp.myTimClass.ServiceTimeLasXML = theApp.myTimClass.ServiceTimeLasXML -1;
		//				CString m_serviceTime  /*theApp.myModuleMain.string2CString(OBJ_Control::to_String(theApp.myTimClass.ServiceTimeLasXML))*/;
		//				dealXml.SetIniXML(_T("\nandflash\ini.xml"), _T("Ini"), _T("OperaTime"), _T("ServiceTime"), m_serviceTime);
		//				m_Ink->m_setup->GetDlgItem(IDC_NEXT_SERVICE_EDIT)->SetWindowText(theApp.myModuleMain.string2CString(OBJ_Control::to_String(theApp.myTimClass.ServiceTimeLasXML/60)));
		//			}
		//			if (theApp.myTimClass.InkLifeTimeLasXML > 0)
		//			{
		//				theApp.myTimClass.InkLifeTimeLasXML = theApp.myTimClass.InkLifeTimeLasXML -1;
		//				CString m_InkLifeTime /*= theApp.myModuleMain.string2CString(OBJ_Control::to_String(theApp.myTimClass.InkLifeTimeLasXML))*/;
		//				dealXml.SetIniXML(_T("\nandflash\ini.xml"), _T("Ini"), _T("OperaTime"),_T("InkLifeTime"),m_InkLifeTime);
		//				m_Ink->m_setup->GetDlgItem(IDC_INK_LIFE_TIME_EDIT)->SetWindowText(theApp.myModuleMain.string2CString(OBJ_Control::to_String(theApp.myTimClass.InkLifeTimeLasXML/60)));
		//			}
		//			theApp.myTimClass.dateTimLasWri = localT;
		//		}
		//		if (theApp.myTimClass.InkLifeTimeLasXML == 0)
		//		{
		//			if (theApp.myTimClass.boInkLifeTime == true )
		//			{
		//				string m_tmpt;
		//				m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Red" + "                  " + "Ink has expired";
		//				m_Fault->m_faultList.AddString(theApp.myModuleMain.string2CString(m_tmpt));
		//				theApp.myTimClass.boInkLifeTime = false; 
		//			}
		//			//还有vb界面弹框，但是c++没有做，为防止以后加，特在此留一下标记

		//		}
		//		else if (theApp.myTimClass.InkLifeTimeLasXML < 120)//小于2小时，每分钟提示一次
		//		{
		//			if (m_timeSpan.GetTotalSeconds() > 59)
		//			{
		//				theApp.myTimClass.InkDateTimLas = localT;
		//				string m_tmpt;
		//				m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Yellow" + "                  " + "Ink life remaining" + OBJ_Control::to_String(theApp.myTimClass.InkLifeTimeLasXML/60) + "hours";
		//				m_Fault->m_faultList.AddString(theApp.myModuleMain.string2CString(m_tmpt));
		//			}
		//		}
		//		else if (theApp.myTimClass.InkLifeTimeLasXML < 600)//小于10小时，每10分钟提示一次
		//		{
		//			if (m_timeSpan.GetTotalMinutes() > 9)
		//			{
		//				theApp.myTimClass.InkDateTimLas = localT;
		//				string m_tmpt;
		//				m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Yellow" + "                  " + "Ink life remaining" + OBJ_Control::to_String(theApp.myTimClass.InkLifeTimeLasXML/60) + "hours";
		//				m_Fault->m_faultList.AddString(theApp.myModuleMain.string2CString(m_tmpt));
		//			}
		//		}
		//		else if (theApp.myTimClass.InkLifeTimeLasXML < 6000)//小于100小时，每小时提示一次
		//		{
		//			if (m_timeSpan.GetTotalMinutes() > 59)
		//			{
		//				theApp.myTimClass.InkDateTimLas = localT;
		//				string m_tmpt;
		//				m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Yellow" + "                  " + "Ink life remaining" + OBJ_Control::to_String(theApp.myTimClass.InkLifeTimeLasXML/60) + "hours";
		//				m_Fault->m_faultList.AddString(theApp.myModuleMain.string2CString(m_tmpt));
		//			}
		//		}
		//		if (theApp.myTimClass.ServiceTimeLasXML == 0)
		//		{
		//			if (theApp.myTimClass.boServiceTime == true)
		//			{
		//				string m_tmpt;
		//				m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Red" + "                  " + "Time to servicing now";
		//				m_Fault->m_faultList.AddString(theApp.myModuleMain.string2CString(m_tmpt));
		//				theApp.myTimClass.boServiceTime = false;
		//			}
		//			//还有vb界面弹框，但是c++没有做，为防止以后加，特在此留一下标记

		//		}
		//		else if (theApp.myTimClass.ServiceTimeLasXML < 120)//小于2小时，每分钟提示一次
		//		{
		//			if (m_timeSpan.GetTotalSeconds() > 59)
		//			{
		//				theApp.myTimClass.SerDateTimLas = localT;
		//				string m_tmpt;
		//				m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Yellow" + "                  " + "Next servicing remaining" + OBJ_Control::to_String(theApp.myTimClass.InkLifeTimeLasXML/60) + "hours";
		//				m_Fault->m_faultList.AddString(theApp.myModuleMain.string2CString(m_tmpt));
		//			}
		//		}
		//		else if (theApp.myTimClass.ServiceTimeLasXML < 600)//小于10小时，每10分钟提示一次
		//		{
		//			if (m_timeSpan.GetTotalMinutes() > 9)
		//			{
		//				theApp.myTimClass.SerDateTimLas = localT;
		//				string m_tmpt;
		//				m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Yellow" + "                  " + "Next servicing remaining" + OBJ_Control::to_String(theApp.myTimClass.InkLifeTimeLasXML/60) + "hours";
		//				m_Fault->m_faultList.AddString(theApp.myModuleMain.string2CString(m_tmpt));
		//			}
		//		}
		//		else if (theApp.myTimClass.ServiceTimeLasXML < 6000)//小于100小时，每小时提示一次
		//		{
		//			if (m_timeSpan.GetTotalMinutes() > 59)
		//			{
		//				theApp.myTimClass.SerDateTimLas = localT;
		//				string m_tmpt;
		//				m_tmpt = m_currentDate + "               " + m_currentTime + "               " + "Yellow" + "                  " + "Next servicing remaining" + OBJ_Control::to_String(theApp.myTimClass.InkLifeTimeLasXML/60) + "hours";
		//				m_Fault->m_faultList.AddString(theApp.myModuleMain.string2CString(m_tmpt));
		//			}
		//		}
		//	}
		//	


		//}

		
		//以上有坑，先注掉

		//准备好及绿灯处理
		if (theApp.myStatusClass.staSysRea == true && theApp.myTimClass.staSysReaLas == false  )
		{
			theApp.myTimClass.staSysReaLas = true;
			if (m_PicHead.m_bRedAlarm == false)
			{
				m_PicHead.SetGreenAlarm(true);
			}
			
		}
		else if (theApp.myStatusClass.staSysRea == false && theApp.myTimClass.staSysReaLas == true)
		{
			theApp.myTimClass.staSysReaLas = false;
			if (m_PicHead.m_bRedAlarm == true)
			{
				m_PicHead.SetGreenAlarm(false);
			}
		}
        
		//yellow灯
		if (theApp.myStatusClass.staPriHeaHotFau == false && theApp.myStatusClass.staLinFas == false && theApp.myStatusClass.staInkTemSenFau == false && theApp.myStatusClass.staPriHeaTemFau == false &&
			theApp.myStatusClass.staVisAbnFau == false && theApp.myStatusClass.staVisSenFau == false && theApp.myStatusClass.staChaFau == false && theApp.myStatusClass.staPhaFau == false &&
			theApp.myStatusClass.staProSenFas == false && theApp.myStatusClass.staAutModFau == false )
		{
			m_PicHead.SetYellowAlarm(false);
		}
		else if (theApp.myStatusClass.staPriHeaHotFau == true || theApp.myStatusClass.staLinFas == true || theApp.myStatusClass.staInkTemSenFau == true || theApp.myStatusClass.staPriHeaTemFau == true ||
			theApp.myStatusClass.staVisAbnFau == true || theApp.myStatusClass.staVisSenFau == true || theApp.myStatusClass.staChaFau == true || theApp.myStatusClass.staPhaFau == true ||
			theApp.myStatusClass.staProSenFas == true || theApp.myStatusClass.staAutModFau == true  )
		{
			m_PicHead.SetYellowAlarm(true);
		}
		
		//red灯
		if (theApp.myStatusClass.staValFau == false && theApp.myTimClass.staComFau == false && theApp.myStatusClass.staBumSpeOveFau == false && theApp.myStatusClass.staPreOveFau == false &&
			theApp.myStatusClass.staInkFloFau == false && theApp.myStatusClass.staFanFau == false && theApp.myStatusClass.staHigVolFau == false && theApp.myTimClass.staInkEmpFau == false &&
			theApp.myTimClass.staInkOveFau == false  )
		{
			m_PicHead.SetRedAlarm(false);
		}
		else if (theApp.myStatusClass.staValFau == true || theApp.myTimClass.staComFau == true || theApp.myStatusClass.staBumSpeOveFau == true || theApp.myStatusClass.staPreOveFau == true ||
			theApp.myStatusClass.staInkFloFau == true || theApp.myStatusClass.staFanFau == true || theApp.myStatusClass.staHigVolFau == true || theApp.myTimClass.staInkEmpFau == true ||
			theApp.myTimClass.staInkOveFau == true  )
		{
			m_PicHead.SetRedAlarm(true);
		}

		//故障图标的显示
		if (m_PicHead.m_bBlueAlarm == false && m_PicHead.m_bYellowAlarm == false && m_PicHead.m_bRedAlarm == false )
		{
			m_ButFault.LoadBitmaps(IDB_FAULT1_BITMAP,IDB_FAULT2_BITMAP,0,0,IDB_80_55_BITMAP);
			m_ButFault.SizeToContent(); 

		}
		else if (m_PicHead.m_bBlueAlarm == true || m_PicHead.m_bYellowAlarm == true || m_PicHead.m_bRedAlarm == true )
		{
			m_ButFault.LoadBitmaps(IDB_RED_FAULT1_BITMAP,IDB_RED_FAULT2_BITMAP,0,0,IDB_80_55_BITMAP);
			m_ButFault.SizeToContent(); 
		}
        m_ButFault.Invalidate();
		
			
		//产品计数器
		GetDlgItem(IDC_STATIC_PROCOUNT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(OBJ_Control::to_String(theApp.myStatusClass.staProCou)));
		//打印计数器
		GetDlgItem(IDC_STATIC_PRICOUNT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(OBJ_Control::to_String(theApp.myStatusClass.staPriCou)));

		theApp.refalsetimedata();
		if (theApp.m_MessagePrint.boDynamic)
		{
			for (int i = 0;i < theApp.m_MessagePrint.OBJ_Vec.size();i++)
			{
				if (theApp.m_MessagePrint.OBJ_Vec.at(i)->strType2 == "serial")
				{
					switch(theApp.m_MessagePrint.OBJ_Vec.at(i)->intSerialCounter)
					{
					case 0:
						GetDlgItem(IDC_SEQUENCE1_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->CountNum)));
						break;
					case 1:
						GetDlgItem(IDC_SEQUENCE2_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->CountNum)));
						break;
					case 2:
						GetDlgItem(IDC_SEQUENCE3_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->CountNum)));
						break;
					case 3:
						GetDlgItem(IDC_SEQUENCE4_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->CountNum)));
						break;
					}
				}
			}
			if (m_resetSerial->boDlgOpen)
			{
				for (int i = 0;i < theApp.m_MessagePrint.OBJ_Vec.size();i++)
				{
					if (theApp.m_MessagePrint.OBJ_Vec.at(i)->strType2 == "serial")
					{
						switch(theApp.m_MessagePrint.OBJ_Vec.at(i)->intSerialCounter)
						{
						case 0:
							m_resetSerial->GetDlgItem(IDC_SERIAL1_CUR_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->CountNum)));
							//GetDlgItem(IDC_SEQUENCE1_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->CountNum)));
							break;
						case 1:
							m_resetSerial->GetDlgItem(IDC_SERIAL2_CUR_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->CountNum)));
							//GetDlgItem(IDC_SEQUENCE2_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->CountNum)));
							break;
						case 2:
							m_resetSerial->GetDlgItem(IDC_SERIAL3_CUR_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->CountNum)));
							//GetDlgItem(IDC_SEQUENCE3_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->CountNum)));
							break;
						case 3:
							m_resetSerial->GetDlgItem(IDC_SERIAL4_CUR_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->CountNum)));
							//GetDlgItem(IDC_SEQUENCE4_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->CountNum)));
							break;
						}
					}
				}
			}
		}
		//SetTimer(TIMER1,300,NULL);	
	}

}


HBRUSH CCodePrinterDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if(nCtlColor == CTLCOLOR_STATIC)
	{		 
		pDC->SelectObject(theApp.m_StaticFont);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));	
	}
	// TODO:  在此更改 DC 的任何属性
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
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
		m_Confi->GetDlgItem(IDC_CONFIG_OK_BTN)->EnableWindow(theApp.myUserPower.booPcfIO);
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
		m_System->GetDlgItem(IDC_SYS_OK_BTN)->EnableWindow(true);
	}
	
	//故障
	m_Fault->GetDlgItem(IDC_DELETE_BTN)->EnableWindow(theApp.myUserPower.booFaultDelete);
	//m_System->
}
//产品和喷印计数器清零
void CCodePrinterDlg::OnBnClickedResetCountBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.myPcfClass.pcf0X00bit5=1;
	theApp.myPcfClass.pcf0X00bit6=1;
	CPcfConfig pPcfConfig(this);
	pPcfConfig.download_pcf();
	theApp.myPcfClass.pcf0X00bit5=0;
	theApp.myPcfClass.pcf0X00bit6=0;
}


/*
 * 接收客户端连接请求
 */
//DWORD WINAPI CCodePrinterDlg::AcceptThread( void *pParam )
//{
//	CCodePrinterDlg	*pServView = (CCodePrinterDlg*)pParam;	//主窗口指针
//	HANDLE		hComPort = pServView->m_hCompPort;	//完成端口
//	SOCKET		sListen = pServView->m_sListen;		//监听套接字
//	SOCKET		sAccept = INVALID_SOCKET;			//接受套接字
//	while(pServView->m_bRunning)
//	{
//		DWORD dwRet;
//		dwRet = WSAWaitForMultipleEvents(1,			//等待网络事件
//										&pServView->m_hEvent2,
//										FALSE,
//										100,
//										FALSE);		
//		if(!pServView->m_bRunning)					//服务器停止服务
//			break;
//		
//		if (dwRet == WSA_WAIT_TIMEOUT)				//函数调用超时
//			continue;
//		
//		WSANETWORKEVENTS events;					//查看发生的网络事件
//		int nRet = WSAEnumNetworkEvents(pServView->m_sListen,
//										pServView->m_hEvent2,//事件对象被重置
//										&events);		
//		if (nRet == SOCKET_ERROR)
//		{
//			AfxMessageBox(_T("WSAEnumNetworkEvents函数错误"));
//			break;
//		}
//
//		if ( events.lNetworkEvents & FD_ACCEPT)		//发生FD_ACCEPT网络事件
//		{
//			if ( events.iErrorCode[FD_ACCEPT_BIT] == 0 && pServView->m_bRunning)
//			{
//				//接受客户端请求
//				SOCKADDR_IN servAddr;
//				int	serAddrLen = sizeof(servAddr);	   
//				if ((sAccept = WSAAccept(sListen, 
//										(SOCKADDR*)&servAddr,
//										&serAddrLen,
//										NULL, 
//										0)) == SOCKET_ERROR)
//				{
//					AfxMessageBox(_T("WSAAccept函数错误"));
//					break;
//				}
//				//创建客户端节点
//				CClientContext *pClient = new CClientContext(sAccept,pServView);				
//				if (CreateIoCompletionPort((HANDLE)sAccept,	//套接字与完成端口关联起来
//							hComPort,
//							(DWORD) pClient,//完成键
//							0) == NULL)
//				//if (bind(sAccept,	//套接字与完成端口关联起来
//				//							(SOCKADDR)hComPort,
//				//							sizeof(sAccept)
//				//							) == NULL)
//				{
//					return -1;
//				}
//				
//				//加入管理客户端链表
//				CClientManager *pClientMgr = CClientManager::GetClientManager();
//				pClientMgr->AddClient(pClient);
//				
//				if(!pClient->AsyncRecvHead())				//接收数据
//				{
//					pClientMgr->DeleteClient(pClient);
//				}				
//			}
//		}		
//	}
//
//	//释放资源
//	CClientManager *pClientMgr = CClientManager::GetClientManager();
//	pClientMgr->DeleteAllClient();
//	pClientMgr->ReleaseManager();
//	return 0;
//}
//
///*
// * 服务线程
// */
//DWORD WINAPI CCodePrinterDlg::ServiceThread( void *pParam )
//{
//	CCodePrinterDlg *pServerView = (CCodePrinterDlg*)pParam;//主窗口指针
//	HANDLE		hComPort = pServerView->m_hCompPort;//完成端口
//	
//	DWORD			dwIoSize;		//传输字节数
//	CClientContext	*pClient;		//客户端指针
//	LPOVERLAPPED	lpOverlapped;	//重叠结构指针
//	bool			bExit = FALSE;	//服务线程退出
//	while (!bExit)
//	{
//		dwIoSize = -1;
//		lpOverlapped = NULL;
//		pClient = NULL;
//		//等待I/O操作结果
//		BOOL bIORet = GetQueuedCompletionStatus(hComPort,
//												&dwIoSize,
//												(LPDWORD) &pClient,
//												&lpOverlapped,
//												INFINITE);
//		//失败的操作完成
//		if (FALSE == bIORet && NULL != pClient)
//		{	
//			//客户端断开
//			if (CClientContext::DOING == pClient->m_eState 
//				|| CClientContext::LOGIN == pClient->m_eState)
//			{
//				pClient->m_eState = CClientContext::DISCON;
//				pClient->SaveDisConnectState();
//			}
//			CClientManager *pClientMgr = CClientManager::GetClientManager();
//			pClientMgr->DeleteClient(pClient);				
//		}
//		//成功的操作完成
//		if(bIORet && lpOverlapped && pClient) 
//		{				
//			CClientManager *pClientMgr = CClientManager::GetClientManager();
//		 
//			pClient->m_strSendData.m_nSpeedTheory = pServerView->m_nSpeed;
//
//			CString strTmp = pServerView->m_cRecieveInfo;
//			int nPos = strTmp.Find(_T("Output"));
//			if(nPos)
//			{
//				strTmp = strTmp.Trim(_T(" Output"));
//				strTmp.TrimLeft();
//				strTmp.TrimRight();
//				pClient->m_strSendData.m_dTemp = atof(theApp.myModuleMain.CString2ConstChar(strTmp));
//			}
//
//			pClient->m_strSendData.m_nFrictionSensor = 1200;//pServerView->m_nFrictionSensor;
//			pClient->m_strSendData.m_nStrainSensor = 1300;//pServerView->m_nStrainSensor;
//
//			pClientMgr->ProcessIO(pClient, lpOverlapped, dwIoSize);				
//		}	
//		//服务器退出
//		if(pClient == NULL&& lpOverlapped ==NULL && !pServerView->m_bRunning)
//		{
//			bExit = TRUE;
//		}		
//	}
//	return 0;
//}
//
//
//void CCodePrinterDlg::OnServerStart() 
//{
//	int	reVal;						//返回值
//	
//	//初始化套接字动态库
//	WSADATA wsaData;	
//	if ((reVal = WSAStartup(0x0202, &wsaData)) != 0)
//	{
//		AfxMessageBox(_T("初始化套接字动态库错误!"));
//		return ;
//	}
//
//	//创建套接字
//	if ((m_sListen = WSASocket(AF_INET,
//		SOCK_STREAM,
//		0,
//		NULL, 
//		0,
//		WSA_FLAG_OVERLAPPED)) == INVALID_SOCKET)
//	{
//		AfxMessageBox(_T("创建套接字错误!"));
//		WSACleanup();
//		return ;
//	} 
//	#define IPV4(a,b,c,d) ((a<<24)|(b<<16)|(c<<8)|(d<<0))
//
//	m_shServPort = 502;
//	m_dwServIP = IPV4(169,254,180,2);//2130706433;//
//	 
//
//	//绑定套接字
//	SOCKADDR_IN	servAddr;//服务器地址
//	servAddr.sin_family = AF_INET;
//	servAddr.sin_addr.s_addr = htonl(m_dwServIP);
//	servAddr.sin_port = htons(m_shServPort);	
//	if (bind(m_sListen, (SOCKADDR*)&servAddr, sizeof(servAddr)) 
//		== SOCKET_ERROR)
//	{
//		AfxMessageBox(_T("绑定套接字错误!"));
//		closesocket(m_sListen);
//		WSACleanup();
//		return ;
//	}
//
//	//监听
//	if(listen(m_sListen, SOMAXCONN) == SOCKET_ERROR)
//	{
//		AfxMessageBox(_T("监听套接字错误!"));
//		closesocket(m_sListen);
//		WSACleanup();
//		return ;
//	}
//
//	m_bRunning = TRUE;	//服务器运行
//
//	//创建接受客户端连接事件对象
//	m_hEvent2 = WSACreateEvent();
//	if ( m_hEvent2 == WSA_INVALID_EVENT )
//	{	
//		closesocket(m_sListen);
//		WSACleanup();
//		return ;
//	}
//
//	//为监听套接字注册FD_ACCEPT网络事件
//	int nRet = WSAEventSelect(m_sListen,
//		m_hEvent2,
//		FD_ACCEPT);	
//	if ( nRet == SOCKET_ERROR )
//	{
//		AfxMessageBox(_T("注册网络事件错误!"));
//		closesocket(m_sListen);
//		WSACleanup();
//		return ;
//	}
//
//	// 创建完成端口
//	if ((m_hCompPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0)) == NULL)
//	{
//		AfxMessageBox(_T("创建完成端口失败!"));
//		WSACloseEvent(m_hEvent2);
//		closesocket(m_sListen);
//		WSACleanup();
//		return ;
//	}
//
//	//创建接受客户端请求线程
//	DWORD dwThreadID;
//	m_hThread[0] = CreateThread(NULL, 
//		0,
//		AcceptThread,
//		this, 
//		0,  
//		&dwThreadID);
//	if (NULL == m_hThread[0])
//	{
//		AfxMessageBox(_T("创建接受客户端线程失败!"));
//		WSACloseEvent(m_hEvent2);
//		closesocket(m_sListen);
//		WSACleanup();
//		return;
//	}
//	m_nThreadNum = 1;
//
//	//获取CPU数量
//	SYSTEM_INFO SystemInfo;
//	GetSystemInfo(&SystemInfo);
//
//	//创建服务线程
//	for(int i = 0; i < SystemInfo.dwNumberOfProcessors * 2; i++)
//	{
//		if ((m_hThread[m_nThreadNum++] = CreateThread(NULL, 
//			0,
//			ServiceThread,
//			this,
//			0, 
//			&dwThreadID)) == NULL)
//		{
//			AfxMessageBox(_T("创建服务线程失败!"));
//			WSACloseEvent(m_hEvent2);
//			closesocket(m_sListen);
//			WSACleanup();
//			return ;
//		}
//
//	}
//	//设置定时器，每1分钟发送WM_TIMER消息
//	//SetTimer(1, 1000 * 60 * 1,NULL);
//}