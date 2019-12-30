// ConfigurationDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "ConfigurationDlg.h"
#include "PcfConfig.h"
#include "CodePrinterDlg.h"
#include "..\PathDlgDll\PathDlgDll\PathDlgDll.h"

// CConfigurationDlg 对话框

IMPLEMENT_DYNAMIC(CConfigurationDlg, CDialog)

CConfigurationDlg::CConfigurationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConfigurationDlg::IDD, pParent)
	, m_height(70)
	, m_dotPitch(0.423)
	, m_delay(100)
	, m_repeatDis(300)
	, m_speed(20)
{

}

CConfigurationDlg::~CConfigurationDlg()
{
}

void CConfigurationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_HEIGHT_EDIT, m_height);
	DDX_Control(pDX, IDC_REVERSE_COMBO, m_reverse);
	DDX_Control(pDX, IDC_INVERSE_COMBO, m_inverse);
	DDX_Text(pDX, IDC_DOT_PITCH_EDIT, m_dotPitch);
	DDX_Text(pDX, IDC_DELAY_EDIT, m_delay);
	DDX_Text(pDX, IDC_REPEAT_DIS_EDIT, m_repeatDis);
	DDX_Control(pDX, IDC_SPEED_WAY_COMBO, m_speedWay);
	DDX_Text(pDX, IDC_SPEED_EDIT, m_speed);

	DDX_Control(pDX, IDC_CONFI_CLOSE_BTN, m_returnIB);
	DDX_Control(pDX, IDC_PRINT_SET_BTN, m_printSetIB);
	DDX_Control(pDX, IDC_OUT_SET_BTN, m_outSetIB);
	DDX_Control(pDX, IDC_CONFI_OPEN_BTN, m_configOpenIB);
	DDX_Control(pDX, IDC_CONFI_SAVE_BTN, m_configSaveIB);
	DDX_Control(pDX, IDC_CONFIG_OK_BTN, m_configOkIB);
	DDX_Control(pDX, IDC_PIC_PRINTER_SETUP, m_PCFdiagram);
}


BEGIN_MESSAGE_MAP(CConfigurationDlg, CDialog)
	ON_BN_CLICKED(IDC_CONFI_CLOSE_BTN, &CConfigurationDlg::OnBnClickedConfiCloseBtn)
	ON_BN_CLICKED(IDC_PRINT_SET_BTN, &CConfigurationDlg::OnBnClickedPrintSetBtn)
	ON_BN_CLICKED(IDC_OUT_SET_BTN, &CConfigurationDlg::OnBnClickedOutSetBtn)
	ON_BN_CLICKED(IDC_CONFIG_OK_BTN, &CConfigurationDlg::OnBnClickedSavePcf)

	ON_BN_CLICKED(IDC_CONFI_OPEN_BTN, &CConfigurationDlg::OnBnClickedConfiOpenBtn)
	ON_BN_CLICKED(IDC_CONFI_SAVE_BTN, &CConfigurationDlg::OnBnClickedConfiSaveBtn)

	ON_WM_CTLCOLOR()

	ON_CBN_SELCHANGE(IDC_INVERSE_COMBO, &CConfigurationDlg::OnCbnSelchangeInverseCombo)
END_MESSAGE_MAP()


// CConfigurationDlg 消息处理程序

BOOL CConfigurationDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

    //按钮界面初始化
	m_ConfigPrintModeDlg = new CConfigPrintModeDlg;
	m_ConfigPM= new CConfigPrintModeDlg;
	m_ConfigOS = new CConfigOutSetDlg;

	int nX = 0;
	int nY = 100;
	int nWidth = 800;
	int nHeight = 500;
	m_ConfigPM->Create(IDD_CONFIG_PRINT_MODE_DIALOG,this);
	m_ConfigPM->MoveWindow(nX,nY,nWidth,nHeight);
	m_ConfigPM->ShowWindow(SW_HIDE);
	m_ConfigOS->Create(IDD_CONFIG_OUTSET_DIALOG,this);
	m_ConfigOS->MoveWindow(nX,nY,nWidth,nHeight);
	m_ConfigOS->ShowWindow(SW_HIDE);

	m_reverse.AddString(L"OFF");
	m_reverse.AddString(L"ON");
	m_reverse.SetCurSel(0);

	m_inverse.AddString(L"OFF");
	m_inverse.AddString(L"ON");
	m_inverse.SetCurSel(0);

	m_speedWay.AddString(L"Fixed");
	m_speedWay.AddString(L"Variable");
	m_speedWay.SetCurSel(0);

	CRect rect1;
	GetDlgItem(IDC_CONFI_CLOSE_BTN)->GetWindowRect(&rect1);

	GetDlgItem(IDC_CONFI_CLOSE_BTN)->SetWindowPos(NULL,11,390,70,45,SWP_SHOWWINDOW);//IDC_SYSTEM_CANCEL_BTN
	GetDlgItem(IDC_PRINT_SET_BTN)->SetWindowPos(NULL,200,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_OUT_SET_BTN)->SetWindowPos(NULL,300,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_CONFI_OPEN_BTN)->SetWindowPos(NULL,400,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_CONFI_SAVE_BTN)->SetWindowPos(NULL,500,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_CONFIG_OK_BTN)->SetWindowPos(NULL,700,390,70,45,SWP_SHOWWINDOW);

	m_returnIB.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RETURN1_BITMAP);
	m_returnIB.SizeToContent(); 
	m_printSetIB.LoadBitmaps(IDB_PRINT_SET1_BITMAP,IDB_PRINT_SET2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_printSetIB.SizeToContent(); 
	m_outSetIB.LoadBitmaps(IDB_OUT_SET1_BITMAP,IDB_OUT_SET2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_outSetIB.SizeToContent(); 
	m_configOpenIB.LoadBitmaps(IDB_CONFIG_OPEN1_BITMAP,IDB_CONFIG_OPEN2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_configOpenIB.SizeToContent(); 
	m_configSaveIB.LoadBitmaps(IDB_SAVE1_BITMAP,IDB_SAVE2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_configSaveIB.SizeToContent(); 
	m_configOkIB.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_OK1_BITMAP);
	m_configOkIB.SizeToContent(); 

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CConfigurationDlg::OnBnClickedConfiCloseBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
	showConfigDlg(0);
	((CCodePrinterDlg*)GetParent())->m_PicHead.ShowLogo(true); 
}

void CConfigurationDlg::showConfigDlg(int ID)
{
	m_ConfigPM->ShowWindow(SW_HIDE);
	m_ConfigOS->ShowWindow(SW_HIDE);
	if (ID == IDD_CONFIG_PRINT_MODE_DIALOG)
	{
		m_ConfigPM->ShowWindow(SW_SHOW);
		((CCodePrinterDlg*)GetParent())->m_PicHead.SetOperationString(_T("Configure > PrintMode")); 

	}
	else if (ID == IDD_CONFIG_OUTSET_DIALOG)
	{
		m_ConfigOS->ShowWindow(SW_SHOW);
		((CCodePrinterDlg*)GetParent())->m_PicHead.SetOperationString(_T("Configure > Outset")); 

	}	 
}

void CConfigurationDlg::OnBnClickedPrintSetBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	showConfigDlg(IDD_CONFIG_PRINT_MODE_DIALOG);
}

void CConfigurationDlg::OnBnClickedOutSetBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	showConfigDlg(IDD_CONFIG_OUTSET_DIALOG);
}

void CConfigurationDlg::OnBnClickedSavePcf()
{
	// TODO: 在此添加控件通知处理程序代码

	//界面保存到目前的喷印配置xml文件和pcf文件里  
	CPcfConfig pPcfConfig((CCodePrinterDlg*)(this->GetParent()));
	pPcfConfig.save_pcf_to_xml();
	pPcfConfig.download_pcf();
}



void CConfigurationDlg::OnBnClickedConfiOpenBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR path[MAX_PATH];
	//labModule.string2tchar(testpath,path);

	string xmlPath;
	if(ShowPathDlg(path, MAX_PATH,3))
	{
		//AfxMessageBox(path);
		xmlPath=theApp.myModuleMain.TCHAR2STRING(path);
		//xmlPath+="sss.xml";
		//myclassMessage.SaveObjectsToXml("\\Storage Card\\user\\Label\\sss.xml");
		//theApp.myclassMessage.ReadObjectsFromXml(const_cast<char*>(xmlPath.c_str()));
		CPcfConfig pPcfConfig((CCodePrinterDlg*)(this->GetParent()));
		pPcfConfig.getPcfFromXml(xmlPath);
	}
}

void CConfigurationDlg::OnBnClickedConfiSaveBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR path[MAX_PATH];
	//labModule.string2tchar(testpath,path);

	string xmlPath;
	if(ShowPathDlg(path, MAX_PATH,3))
	{
		//AfxMessageBox(path);
		xmlPath=theApp.myModuleMain.TCHAR2STRING(path);
		//xmlPath+="sss.xml";
		//myclassMessage.SaveObjectsToXml("\\Storage Card\\user\\Label\\sss.xml");
		//theApp.myclassMessage.ReadObjectsFromXml(const_cast<char*>(xmlPath.c_str()));
		CPcfConfig pPcfConfig((CCodePrinterDlg*)(this->GetParent()));
		pPcfConfig.savePcfToXml(xmlPath);
	}
}

HBRUSH CConfigurationDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return theApp.m_DlgBrush;
}

void CConfigurationDlg::pcf_diagram_select()
{
	;
}

void CConfigurationDlg::OnCbnSelchangeInverseCombo()
{
	// TODO: 在此添加控件通知处理程序代码

	pcf_diagram_select();
}
