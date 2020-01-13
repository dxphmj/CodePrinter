// SystemDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "SystemDlg.h"
#include "EnvDlg.h"
#include "ComDlg.h"
#include "Version.h"
#include "CodePrinterDlg.h"

// CSystemDlg 对话框

IMPLEMENT_DYNAMIC(CSystemDlg, CDialog)

CSystemDlg::CSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSystemDlg::IDD, pParent)
{

}

CSystemDlg::~CSystemDlg()
{
}

void CSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SYS_FRESH1_BTN, m_freshUp);
	DDX_Control(pDX, IDC_SYS_FRESH2_BTN, m_freshDown);
	DDX_Control(pDX, IDC_SYSTEM_CLOSE_BTN, m_sysReturn);
	DDX_Control(pDX, IDC_SYS_OK_BTN, m_sysOk);
	DDX_Control(pDX, IDC_DHCP_BTN, m_dhcp);

	DDX_Control(pDX, IDC_NET_BTN, m_ButNet);
	DDX_Control(pDX, IDC_COM_BTN, m_ButSerial);
	DDX_Control(pDX, IDC_EVN_BTN, m_ButEnv);
	DDX_Control(pDX, IDC_CUSTON_BUTTON, m_ButCustom);
	DDX_Control(pDX, IDC_VERSION_BTN, m_ButVersion);

	DDX_Control(pDX, IDC_SYS_SERVER_IP_STATIC, m_serverIpStatic);
	DDX_Control(pDX, IDC_SYS_SERVER_PORT_STATIC, m_serverPortStatic);
	DDX_Control(pDX, IDC_VALID_EQUIP_STATIC, m_validEquipStatic);
	DDX_Control(pDX, IDC_SYS_NET_NAME_STATIC, m_netNameStatic);
	DDX_Control(pDX, IDC_SYS_LOCAL_IP_STATIC, m_localIpStatic); 
	DDX_Control(pDX, IDC_SYS_LOCAL_PORT_STATIC, m_localPortStatic);
	DDX_Control(pDX, IDC_SYS_SUBNETMASK_STATIC, m_subNetMaskStatic);
	DDX_Control(pDX, IDC_SYS_GATEWAY_STATIC, m_gatewayStatic);
	DDX_Control(pDX, IDC_SYS_DHCP_STATIC, m_DHCPStatic);

}


BEGIN_MESSAGE_MAP(CSystemDlg, CDialog)
	ON_BN_CLICKED(IDC_EVN_BTN, &CSystemDlg::OnBnClickedEvnBtn)
	ON_BN_CLICKED(IDC_COM_BTN, &CSystemDlg::OnBnClickedComBtn)
	ON_BN_CLICKED(IDC_VERSION_BTN, &CSystemDlg::OnBnClickedVersionBtn)
	ON_BN_CLICKED(IDC_NET_BTN, &CSystemDlg::OnBnClickedNetBtn)
	ON_BN_CLICKED(IDC_SYSTEM_CLOSE_BTN, &CSystemDlg::OnBnClickedSystemCloseBtn)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CSystemDlg 消息处理程序

BOOL CSystemDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	pEvn = new CEnvDlg;
	pCom = new CComDlg;
	pVersion = new CVersion;

	pEvn->Create(IDD_ENV_DIALOG,this);
 	pCom->Create(IDD_COM_DIALOG,this);
 	pVersion->Create(IDD_VERSION_DIALOG,this);

	int nX = 0;
	int nY = 100;
	int nWidth = 800;
	int nHeight = 350;
	pEvn->MoveWindow(nX,nY,nWidth,nHeight);
	pCom->MoveWindow(nX,nY,nWidth,nHeight);
	pVersion->MoveWindow(nX,nY,nWidth,nHeight);	 

	m_freshUp.LoadBitmaps(IDB_FRESH1_BITMAP,IDB_FRESH2_BITMAP,0,0,IDB_80_55_BITMAP);
	m_freshUp.SizeToContent(); 
	m_freshDown.LoadBitmaps(IDB_FRESH1_BITMAP,IDB_FRESH2_BITMAP,0,0,IDB_80_55_BITMAP);
	m_freshDown.SizeToContent(); 
	m_sysReturn.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_80_55_BITMAP);
	m_sysReturn.SizeToContent(); 
	m_sysOk.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_80_55_BITMAP);
	m_sysOk.SizeToContent(); 
	m_dhcp.LoadBitmaps(IDB_DHCP1_BITMAP,IDB_DHCP2_BITMAP,0,0,IDB_80_55_BITMAP);
	m_dhcp.SizeToContent(); 

	m_ButNet.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_80_55_BITMAP,true);
	m_ButNet.SizeToContent(); 
	m_ButSerial.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_80_55_BITMAP,true);
	m_ButSerial.SizeToContent(); 
	m_ButEnv.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_80_55_BITMAP,true);
	m_ButEnv.SizeToContent(); 
	m_ButCustom.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_80_55_BITMAP,true);
	m_ButCustom.SizeToContent(); 
	m_ButVersion.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_80_55_BITMAP,true);
	m_ButVersion.SizeToContent(); 

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CSystemDlg::OnBnClickedEvnBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	showSystemDlg(IDD_ENV_DIALOG);
}

void CSystemDlg::OnBnClickedComBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	showSystemDlg(IDD_COM_DIALOG);	
}

void CSystemDlg::OnBnClickedVersionBtn()
{
	// TODO: 在此添加控件通知处理程序代码

	showSystemDlg(IDD_VERSION_DIALOG);	
}

void CSystemDlg::OnBnClickedNetBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	showSystemDlg(IDD_SYSTEM_DIALOG);	
}

void CSystemDlg::OnBnClickedSystemCloseBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
	pEvn->ShowWindow(SW_HIDE);
	pCom->ShowWindow(SW_HIDE);
	pVersion->ShowWindow(SW_HIDE);
	((CCodePrinterDlg*)GetParent())->m_PicHead.ShowLogo(true); 
}


void CSystemDlg::showSystemDlg(int ID)
{
	pEvn->ShowWindow(SW_HIDE);
	pCom->ShowWindow(SW_HIDE);
	pVersion->ShowWindow(SW_HIDE);
	wstring tempstr1,tempstr2;
	CString cstr1,cstr2;
	if (ID == IDD_SYSTEM_DIALOG)
	{
		tempstr1 = theApp.myLanguage.LanguageMap["ID_SYSTEM_MANAGEMENT"];
		tempstr2 = theApp.myLanguage.LanguageMap["ID_SYSTEM_NETWORK"];
		cstr1 = tempstr1.c_str();
		cstr2 = tempstr2.c_str();
		this->ShowWindow(SW_SHOW);
		((CCodePrinterDlg*)GetParent())->m_PicHead.SetOperationString(cstr1+_T(" > ")+cstr2);
	}
	if (ID == IDD_ENV_DIALOG)
	{
		tempstr1 = theApp.myLanguage.LanguageMap["ID_SYSTEM_MANAGEMENT"];
		tempstr2 = theApp.myLanguage.LanguageMap["ID_SYSTEM_ENV"];
		cstr1 = tempstr1.c_str();
		cstr2 = tempstr2.c_str();
		pEvn->ShowWindow(SW_SHOW);
		((CCodePrinterDlg*)GetParent())->m_PicHead.SetOperationString(cstr1+_T(" > ")+cstr2);
	}
	else if(ID == IDD_COM_DIALOG)
	{
		tempstr1 = theApp.myLanguage.LanguageMap["ID_SYSTEM_MANAGEMENT"];
		tempstr2 = theApp.myLanguage.LanguageMap["ID_SYSTEM_COM"];
		cstr1 = tempstr1.c_str();
		cstr2 = tempstr2.c_str();
		pCom->ShowWindow(SW_SHOW);
		((CCodePrinterDlg*)GetParent())->m_PicHead.SetOperationString(cstr1+_T(" > ")+cstr2);
	}
	else if(ID == IDD_VERSION_DIALOG)
	{
		tempstr1 = theApp.myLanguage.LanguageMap["ID_SYSTEM_MANAGEMENT"];
		tempstr2 = theApp.myLanguage.LanguageMap["ID_SYSTEM_VERSION"];
		cstr1 = tempstr1.c_str();
		cstr2 = tempstr2.c_str();
		pVersion->ShowWindow(SW_SHOW);
		((CCodePrinterDlg*)GetParent())->m_PicHead.SetOperationString(cstr1+_T(" > ")+cstr2);
	}
}

HBRUSH CSystemDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
