// EnvDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "EnvDlg.h"
#include "SystemDlg.h"
#include "CodePrinterDlg.h"
using namespace std;

#define ARABIC					0 
#define CHINESE_SIMPLIFIED		1
#define CHINESE_TRADITIONAL		2
#define CZECH					3
#define DUTCH					4
#define ENGLISH					5 
#define ESTONIAN				6 
#define FARSI					7 
#define FINNISH					8 
#define FRENCH					9 
#define GERMAN					10 
#define HINDI					11 
#define HUNGARIAN				12 
#define ITALIAN					13 
#define JAPANESE				14 
#define KANNADA					15 
#define KOREAN					16 
#define POLISH					17 
#define PORTUGUESE				18 
#define ROMANIAN				19 
#define RUSSIAN					20 
#define SERBIAN					21 
#define SPANISH					22 
#define SWEDISH					23 
#define TAMIL					24 
#define THAI					25 
#define TURKISH					26 
#define VIETNAMESE				27 
// CEnvDlg 对话框

IMPLEMENT_DYNAMIC(CEnvDlg, CDialog)



CEnvDlg::CEnvDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEnvDlg::IDD, pParent)
{

}

CEnvDlg::~CEnvDlg()
{
}

void CEnvDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LANGUAGE_LIST, m_langeageList);
	DDX_Control(pDX, IDC_LAN_SEL_BUTTON, m_ButLanSel);
}


BEGIN_MESSAGE_MAP(CEnvDlg, CDialog)
	ON_CBN_SELCHANGE(IDC_LANGUAGE_LIST, &CEnvDlg::OnCbnSelchangeLanguageCombo)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_LAN_SEL_BUTTON, &CEnvDlg::OnBnClickedLanSelButton)
END_MESSAGE_MAP()


// CEnvDlg 消息处理程序

BOOL CEnvDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_langeageList.AddString(L"Arabic");
	m_langeageList.AddString(L"Chinese Simplified");
	m_langeageList.AddString(L"Chinese Traditional");
	m_langeageList.AddString(L"Czech");
	m_langeageList.AddString(L"Dutch");
	m_langeageList.AddString(L"English");
	m_langeageList.AddString(L"Estonian");
	m_langeageList.AddString(L"Farsi");
	m_langeageList.AddString(L"Finnish");
	m_langeageList.AddString(L"French");
	m_langeageList.AddString(L"German");
	m_langeageList.AddString(L"Hindi");
	m_langeageList.AddString(L"Hungarian");
	m_langeageList.AddString(L"Italian");
	m_langeageList.AddString(L"Japanese");
	m_langeageList.AddString(L"Kannada");
	m_langeageList.AddString(L"Korean");
	m_langeageList.AddString(L"Polish");
	m_langeageList.AddString(L"Portuguese");
	m_langeageList.AddString(L"Romanian");
	m_langeageList.AddString(L"Russian");
	m_langeageList.AddString(L"Serbian");
	m_langeageList.AddString(L"Spanish");
	m_langeageList.AddString(L"Swedish");
	m_langeageList.AddString(L"Tamil");
	m_langeageList.AddString(L"Thai");
	m_langeageList.AddString(L"Turkish");
	m_langeageList.AddString(L"Vietnamese");

	CRect rect1;
	GetDlgItem(IDC_LAN_SEL_BUTTON)->GetWindowRect(&rect1);
	GetDlgItem(IDC_LAN_SEL_BUTTON)->SetWindowPos(NULL,rect1.left,rect1.top,70,45,SWP_SHOWWINDOW);
	m_ButLanSel.LoadBitmaps(IDB_FRESH1_BITMAP,IDB_FRESH2_BITMAP,0,0,IDB_FRESH1_BITMAP);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CEnvDlg::OnCbnSelchangeLanguageCombo()
{
	// TODO: 在此添加控件通知处理程序代码
	int nIndex = m_langeageList.GetCurSel();  //当前选中的项
	bool isRead=false;
	switch(nIndex)
	{
	case CHINESE_SIMPLIFIED:
		//theApp.myLanguage.LanguageMap.clear();
        isRead= theApp.myLanguage.readLanguageXml("ChineseSimplified.xml");
		if (isRead)
		{

			wstring lanStr;
			CCodePrinterDlg *pCodeDlg = (CCodePrinterDlg*)this->GetParent()->GetParent();//获取主对话框指针
			//初始化表头,开机状态
			lanStr=theApp.myLanguage.LanguageMap["IDC_MACHINE_STATUS"];
			pCodeDlg->m_PicHead.SetMachineStatus(lanStr.c_str());//Shut Down
			pCodeDlg->showDlg(IDD_SYSTEM_DIALOG);
			//打印机主界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_PRINT_PRE_STATIC"];
			pCodeDlg->GetDlgItem(IDC_PRINT_PRE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_PRINT_LAB_STATIC"];
			pCodeDlg->GetDlgItem(IDC_MAIN_PRINT_LAB_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_PRINT_PCF_STATIC"];
			pCodeDlg->GetDlgItem(IDC_MAIN_PRINT_PCF_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_COUNTER_STATIC"];
			pCodeDlg->GetDlgItem(IDC_MAIN_COUNTER_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_PRODUCT_DETECTED_STATIC"];
			pCodeDlg->GetDlgItem(IDC_MAIN_PRODUCT_DETECTED_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_PRODUCT_PRINTED_STATIC"];
			pCodeDlg->GetDlgItem(IDC_MAIN_PRODUCT_PRINTED_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_SERIAL_NUM_STATIC"];
			pCodeDlg->GetDlgItem(IDC_MAIN_SERIAL_NUM_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_NUM1_STATIC"];
			pCodeDlg->GetDlgItem(IDC_MAIN_NUM1_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_NUM2_STATIC"];
			pCodeDlg->GetDlgItem(IDC_MAIN_NUM2_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_NUM3_STATIC"];
			pCodeDlg->GetDlgItem(IDC_MAIN_NUM3_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_NUM4_STATIC"];
			pCodeDlg->GetDlgItem(IDC_MAIN_NUM4_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_RESET_COUNT_BTN"];
			pCodeDlg->GetDlgItem(IDC_RESET_COUNT_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_RESET_SERIAL_BTN"];
			pCodeDlg->GetDlgItem(IDC_RESET_SERIAL_BTN)->SetWindowText(lanStr.c_str());
			//开机/关机界面
			//lanStr=theApp.myLanguage.LanguageMap["IDC_SEQUENCE_BTN"];
			//GetDlgItem(IDC_SEQUENCE_BTN)->SetWindowText(lanStr.c_str());
			//lanStr=theApp.myLanguage.LanguageMap["IDC_FAST_BTN"];
			//GetDlgItem(IDC_FAST_BTN)->SetWindowText(lanStr.c_str());
			//系统-网络界面(主界面)
			CSystemDlg *pSysDlg = (CSystemDlg*)this->GetParent();//获取系统对话框指针
			lanStr=theApp.myLanguage.LanguageMap["IDC_SYS_SERVER_IP_STATIC"];
			pSysDlg->GetDlgItem(IDC_SYS_SERVER_IP_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SYS_SERVER_PORT_STATIC"];
			pSysDlg->GetDlgItem(IDC_SYS_SERVER_PORT_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_VALID_EQUIP_STATIC"];
			pSysDlg->GetDlgItem(IDC_VALID_EQUIP_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SYS_NET_NAME_STATIC"];
			pSysDlg->GetDlgItem(IDC_SYS_NET_NAME_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SYS_LOCAL_IP_STATIC"];
			pSysDlg->GetDlgItem(IDC_SYS_LOCAL_IP_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SYS_LOCAL_PORT_STATIC"];
			pSysDlg->GetDlgItem(IDC_SYS_LOCAL_PORT_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SYS_SUBNETMASK_STATIC"];
			pSysDlg->GetDlgItem(IDC_SYS_SUBNETMASK_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SYS_GATEWAY_STATIC"];
			pSysDlg->GetDlgItem(IDC_SYS_GATEWAY_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SYS_DHCP_STATIC"];
			pSysDlg->GetDlgItem(IDC_SYS_DHCP_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_NET_BTN"];
			pSysDlg->GetDlgItem(IDC_NET_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_COM_BTN"];
			pSysDlg->GetDlgItem(IDC_COM_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_EVN_BTN"];
			pSysDlg->GetDlgItem(IDC_EVN_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_CUSTON_BUTTON"];
			pSysDlg->GetDlgItem(IDC_CUSTON_BUTTON)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_VERSION_BTN"];
			pSysDlg->GetDlgItem(IDC_VERSION_BTN)->SetWindowText(lanStr.c_str());
			//系统-串口界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_COM1_BIT_STATIC"];
			pSysDlg->pCom->GetDlgItem(IDC_COM1_BIT_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_COM1_CHECK_STATIC"];
			pSysDlg->pCom->GetDlgItem(IDC_COM1_CHECK_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_COM2_BIT_STATIC"];
			pSysDlg->pCom->GetDlgItem(IDC_COM2_BIT_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_COM2_CHECK_STATIC"];
			pSysDlg->pCom->GetDlgItem(IDC_COM2_CHECK_STATIC)->SetWindowText(lanStr.c_str());
			//系统-环境界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_ENV_TIME_STATIC"];
			GetDlgItem(IDC_ENV_TIME_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_ENV_DATE_STATIC"];
			GetDlgItem(IDC_ENV_DATE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_LANGUAGE_STATIC"];
			GetDlgItem(IDC_LANGUAGE_STATIC)->SetWindowText(lanStr.c_str());
			//系统-版本界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_CODEPRINTER_TYPE_STATIC"];
			pSysDlg->pVersion->GetDlgItem(IDC_CODEPRINTER_TYPE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_CODEPRINTE_ID_RSTATIC"];
			pSysDlg->pVersion->GetDlgItem(IDC_CODEPRINTE_ID_RSTATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MAINBOARD_ID_STATIC"];
			pSysDlg->pVersion->GetDlgItem(IDC_MAINBOARD_ID_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MAINBOARD_HARDWARE_TYPE_STATIC"];
			pSysDlg->pVersion->GetDlgItem(IDC_MAINBOARD_HARDWARE_TYPE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_HARDWARE_UPDATE_TIME_STATIC"];
			pSysDlg->pVersion->GetDlgItem(IDC_HARDWARE_UPDATE_TIME_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MAINBOARD_SOFTWARE_TYPE_STATIC"];
			pSysDlg->pVersion->GetDlgItem(IDC_MAINBOARD_SOFTWARE_TYPE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SOFTWARE_UPDATE_TIME_STATIC"];
			pSysDlg->pVersion->GetDlgItem(IDC_SOFTWARE_UPDATE_TIME_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SYSTEM_SOFTWARE_TYPE_STATIC"];
			pSysDlg->pVersion->GetDlgItem(IDC_SYSTEM_SOFTWARE_TYPE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SYSTEM_SOFTWARE_UPDATE_TIME_STATIC"];
			pSysDlg->pVersion->GetDlgItem(IDC_SYSTEM_SOFTWARE_UPDATE_TIME_STATIC)->SetWindowText(lanStr.c_str());
			//用户-主界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_USER_CURUSERS_STATIC"];
			pCodeDlg->m_User->GetDlgItem(IDC_USER_CURUSERS_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_USER_NAME_STATIC"];
			pCodeDlg->m_User->GetDlgItem(IDC_USER_NAME_STATIC)->SetWindowText(lanStr.c_str());
			//用户-新建界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_USER_NEW_NAME_STATIC"];
			pCodeDlg->m_User->pUserNew->GetDlgItem(IDC_USER_NEW_NAME_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_USER_NEW_UNAUTHORIZED_STATIC"];
			pCodeDlg->m_User->pUserNew->GetDlgItem(IDC_USER_NEW_UNAUTHORIZED_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_NEW_PASSWARD_STATIC"];
			pCodeDlg->m_User->pUserNew->GetDlgItem(IDC_NEW_PASSWARD_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_USER_NEW_AUTHORIZED_STATIC"];
			pCodeDlg->m_User->pUserNew->GetDlgItem(IDC_USER_NEW_AUTHORIZED_STATIC)->SetWindowText(lanStr.c_str());
			//用户-打开界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_USER_OPEN_NAME_STATIC"];
			pCodeDlg->m_User->pUserOpen->GetDlgItem(IDC_USER_OPEN_NAME_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_USER_OPEN_UNAUTHORIZED_STATIC"];
			pCodeDlg->m_User->pUserOpen->GetDlgItem(IDC_USER_OPEN_UNAUTHORIZED_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_USER_OPEN_NAME_STATIC"];
			pCodeDlg->m_User->pUserOpen->GetDlgItem(IDC_OPEN_PASSWARD_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_USER_OPEN_AUTHORIZED_STATIC"];
			pCodeDlg->m_User->pUserOpen->GetDlgItem(IDC_USER_OPEN_AUTHORIZED_STATIC)->SetWindowText(lanStr.c_str());
			//用户-删除界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_USER_DEL_DEL_STATIC"];
			pCodeDlg->m_User->pUserDelete->GetDlgItem(IDC_USER_DEL_DEL_STATIC)->SetWindowText(lanStr.c_str());
			//用户-刷新界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_USER_FRESH_NAME_STATIC"];
			pCodeDlg->m_User->pUserFresh->GetDlgItem(IDC_USER_FRESH_NAME_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_FRESH_PASSWORD_STATIC"];
			pCodeDlg->m_User->pUserFresh->GetDlgItem(IDC_FRESH_PASSWORD_STATIC)->SetWindowText(lanStr.c_str());

			//喷印配置-主界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_HEIGHT_STATIC"];
			pCodeDlg->m_Confi->GetDlgItem(IDC_HEIGHT_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_REVERSE_STATIC"];
			pCodeDlg->m_Confi->GetDlgItem(IDC_REVERSE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INVERSE_STATIC"];
			pCodeDlg->m_Confi->GetDlgItem(IDC_INVERSE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_DOT_PITCH_STATIC"];
			pCodeDlg->m_Confi->GetDlgItem(IDC_DOT_PITCH_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_DELAY_STATIC"];
			pCodeDlg->m_Confi->GetDlgItem(IDC_DELAY_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_REPEAT_DIS_STATIC"];
			pCodeDlg->m_Confi->GetDlgItem(IDC_REPEAT_DIS_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SPEED_WAY_STATIC"];
			pCodeDlg->m_Confi->GetDlgItem(IDC_SPEED_WAY_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SPEED_STATIC"];
			pCodeDlg->m_Confi->GetDlgItem(IDC_SPEED_STATIC)->SetWindowText(lanStr.c_str());
			//喷印配置-喷印模式界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_PRINT_MODE_STATIC"];
			pCodeDlg->m_Confi->m_ConfigPM->GetDlgItem(IDC_PRINT_MODE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_WORK_LIST_STATIC"];
			pCodeDlg->m_Confi->m_ConfigPM->GetDlgItem(IDC_WORK_LIST_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_REAPEAT_COUNT_STATIC"];
			pCodeDlg->m_Confi->m_ConfigPM->GetDlgItem(IDC_REAPEAT_COUNT_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_VIRTUAL_PRINT_STATIC"];
			pCodeDlg->m_Confi->m_ConfigPM->GetDlgItem(IDC_VIRTUAL_PRINT_STATIC)->SetWindowText(lanStr.c_str());
			//喷印配置-外部安装界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_PCF_OUTSET_PRINTDIRE_STATIC"];
			pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_PCF_OUTSET_PRINTDIRE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_OUTSET_ENCODESIGN_STATIC"];
			pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_OUTSET_ENCODESIGN_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_OUTSET_FREQMULTI_STATIC"];
			pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_OUTSET_FREQMULTI_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_OUTSET_IMPULSE_STATIC"];
			pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_OUTSET_IMPULSE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_OUTSET_LENGTH_STATIC"];
			pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_OUTSET_LENGTH_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_OUTSET_PRODUCT_DETE_STATIC"];
			pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_OUTSET_PRODUCT_DETE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_OUTSET_ACTIVELEV_STATIC"];
			pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_OUTSET_ACTIVELEV_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_OUTSET_CUR_LEV_STATIC"];
			pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_OUTSET_CUR_LEV_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_OUTSET_TRIGGER_LEN_STATIC"];
			pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_OUTSET_TRIGGER_LEN_STATIC)->SetWindowText(lanStr.c_str());
			//文字编辑-主界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_MATRIX_STATIC"];
			pCodeDlg->m_Label->GetDlgItem(IDC_MATRIX_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_PIXEL_STATIC"];
			pCodeDlg->m_Label->GetDlgItem(IDC_PIXEL_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_REVERSAL_STATIC"];
			pCodeDlg->m_Label->GetDlgItem(IDC_REVERSAL_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_PERVERSION_STATIC"];
			pCodeDlg->m_Label->GetDlgItem(IDC_PERVERSION_STATIC)->SetWindowText(lanStr.c_str());

			//墨水系统-普通界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_PRESSURE_STATIC"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_PRESSURE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_PUMP_SPEED_STATIC"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_PUMP_SPEED_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_TEMP_STATIC"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_INK_TEMP_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_PTINTHEAD_TEMP_STATIC"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_PTINTHEAD_TEMP_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_LEV_STATIC"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_INK_LEV_STATIC)->SetWindowText(lanStr.c_str());

			lanStr=theApp.myLanguage.LanguageMap["IDC_SOLVENT_LEV_STATIC"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_SOLVENT_LEV_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_TARGET_VISCO_STATIC"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_TARGET_VISCO_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_ACTUAL_VISCO_STATIC"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_ACTUAL_VISCO_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_HIGH_VOL_STATIC"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_HIGH_VOL_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INKFLOW_STATIC"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_INKFLOW_STATIC)->SetWindowText(lanStr.c_str());

			lanStr=theApp.myLanguage.LanguageMap["IDC_SPEED_MODE_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_SPEED_MODE_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_BLEED_VALVE_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_BLEED_VALVE_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_WASH_VALVE_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_WASH_VALVE_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_FEED_VALVE_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_FEED_VALVE_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_VISCO_VALVE_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_VISCO_VALVE_BTN)->SetWindowText(lanStr.c_str());

			lanStr=theApp.myLanguage.LanguageMap["IDC_PRESSURE_MODE_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_PRESSURE_MODE_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_PUMP_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_PUMP_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_NOZZLE_VALVE_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_NOZZLE_VALVE_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SOLVENT_VALVE_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_SOLVENT_VALVE_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_FLUSH_VALVE_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_FLUSH_VALVE_BTN)->SetWindowText(lanStr.c_str());

			lanStr=theApp.myLanguage.LanguageMap["IDC_USUAL_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_USUAL_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_ADVANCE_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_ADVANCE_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SETUP_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_SETUP_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_PARAMETER_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_PARAMETER_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_PHASING_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_PHASING_BTN)->SetWindowText(lanStr.c_str());
			//墨水系统-高级界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_CIR_BTN"];
			pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_INK_CIR_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_ADJUST_INKLINE_BTN"];
			pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_ADJUST_INKLINE_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SUCK_NOZZLE_BTN"];
			pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_SUCK_NOZZLE_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_WASH_NOZZLE_BTN"];
			pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_WASH_NOZZLE_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_BETECT_VISCO_BTN"];
			pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_BETECT_VISCO_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INKFLOW_OFF_BTN"];
			pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_INKFLOW_OFF_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_ADD_SOLVENT_BTN"];
			pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_ADD_SOLVENT_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_HIGH_VOLTAGE_BTN"];
			pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_HIGH_VOLTAGE_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_CLOSE_INKLINE_BTN"];
			pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_CLOSE_INKLINE_BTN)->SetWindowText(lanStr.c_str());
			//墨水系统-安装界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_SIZE_STATIC"];
			pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_SIZE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_RATE_STATIC"];
			pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_RATE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_INKTYPE_STATIC"];
			pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_INKTYPE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_CON_STATIC"];
			pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_CON_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_SLEEPMODE_STATIC"];
			pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_SLEEPMODE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_TIMERESET_STATIC"];
			pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_TIMERESET_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_NEXTTIME_STATIC"];
			pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_NEXTTIME_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_LASTTIME_STATIC"];
			pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_LASTTIME_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INKSETUP_SOL_LEV_JUST_STATIC"];
			pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INKSETUP_SOL_LEV_JUST_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_INK_LEV_JUSTSTATIC"];
			pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_INK_LEV_JUSTSTATIC)->SetWindowText(lanStr.c_str());
			//墨水系统-参数界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_PAR_PRESSURE_STATIC"];
			pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_PAR_PRESSURE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_PAR_PUMP_SPEED_STATIC"];
			pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_PAR_PUMP_SPEED_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_FLOW_LEV_STATIC"];
			pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_INK_FLOW_LEV_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_ADD_LEV_STATIC"];
			pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_INK_ADD_LEV_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_EMPTY_LEV_STATIC"];
			pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_INK_EMPTY_LEV_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_PRINTHEAD_TEMP_STATIC"];
			pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_PRINTHEAD_TEMP_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_VISCO_DEVIA_STATIC"];
			pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_VISCO_DEVIA_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SOLVENT_FLOW_LEV_STATIC"];
			pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_SOLVENT_FLOW_LEV_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SOL_ADD_LEV_STATIC"];
			pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_SOL_ADD_LEV_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SOL_EMPTY_LEV_STATIC"];
			pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_SOL_EMPTY_LEV_STATIC)->SetWindowText(lanStr.c_str());
			//墨水系统-相位界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_MODULATION_V_STATIC"];
			pCodeDlg->m_Ink->m_phas->GetDlgItem(IDC_MODULATION_V_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_FIXED_STATIC"];
			pCodeDlg->m_Ink->m_phas->GetDlgItem(IDC_FIXED_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_AUTO_SET_STATIC"];
			pCodeDlg->m_Ink->m_phas->GetDlgItem(IDC_AUTO_SET_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_AUTO_SET_STATIC"];
			pCodeDlg->m_Ink->m_phas->GetDlgItem(IDC_SET_ADJUST_BIG_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SET_ADJUST_SMALL_STATIC"];
			pCodeDlg->m_Ink->m_phas->GetDlgItem(IDC_SET_ADJUST_SMALL_STATIC)->SetWindowText(lanStr.c_str());
			//故障界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_DATE_STATIC"];
			pCodeDlg->m_Fault->GetDlgItem(IDC_DATE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_TIME_STATIC"];
			pCodeDlg->m_Fault->GetDlgItem(IDC_TIME_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_TYPE_STATIC"];
			pCodeDlg->m_Fault->GetDlgItem(IDC_TYPE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MESSAGE_STATIC"];
			pCodeDlg->m_Fault->GetDlgItem(IDC_MESSAGE_STATIC)->SetWindowText(lanStr.c_str());
		}
		break;
	case ENGLISH:
		//theApp.myLanguage.LanguageMap.clear();
		isRead= theApp.myLanguage.readLanguageXml("English.xml");
		if (isRead)
		{
			wstring lanStr;
			CCodePrinterDlg *pCodeDlg = (CCodePrinterDlg*)this->GetParent()->GetParent();//获取主对话框指针
			//初始化表头,开机状态
			lanStr=theApp.myLanguage.LanguageMap["IDC_MACHINE_STATUS"];
			pCodeDlg->m_PicHead.SetMachineStatus(lanStr.c_str());//Shut Down
			pCodeDlg->showDlg(IDD_SYSTEM_DIALOG);
			//打印机主界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_PRINT_PRE_STATIC"];
			pCodeDlg->GetDlgItem(IDC_PRINT_PRE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_PRINT_LAB_STATIC"];
			pCodeDlg->GetDlgItem(IDC_MAIN_PRINT_LAB_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_PRINT_PCF_STATIC"];
			pCodeDlg->GetDlgItem(IDC_MAIN_PRINT_PCF_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_COUNTER_STATIC"];
			pCodeDlg->GetDlgItem(IDC_MAIN_COUNTER_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_PRODUCT_DETECTED_STATIC"];
			pCodeDlg->GetDlgItem(IDC_MAIN_PRODUCT_DETECTED_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_PRODUCT_PRINTED_STATIC"];
			pCodeDlg->GetDlgItem(IDC_MAIN_PRODUCT_PRINTED_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_SERIAL_NUM_STATIC"];
			pCodeDlg->GetDlgItem(IDC_MAIN_SERIAL_NUM_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_NUM1_STATIC"];
			pCodeDlg->GetDlgItem(IDC_MAIN_NUM1_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_NUM2_STATIC"];
			pCodeDlg->GetDlgItem(IDC_MAIN_NUM2_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_NUM3_STATIC"];
			pCodeDlg->GetDlgItem(IDC_MAIN_NUM3_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_NUM4_STATIC"];
			pCodeDlg->GetDlgItem(IDC_MAIN_NUM4_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_RESET_COUNT_BTN"];
			pCodeDlg->GetDlgItem(IDC_RESET_COUNT_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_RESET_SERIAL_BTN"];
			pCodeDlg->GetDlgItem(IDC_RESET_SERIAL_BTN)->SetWindowText(lanStr.c_str());
			//开机/关机界面
			//lanStr=theApp.myLanguage.LanguageMap["IDC_SEQUENCE_BTN"];
			//GetDlgItem(IDC_SEQUENCE_BTN)->SetWindowText(lanStr.c_str());
			//lanStr=theApp.myLanguage.LanguageMap["IDC_FAST_BTN"];
			//GetDlgItem(IDC_FAST_BTN)->SetWindowText(lanStr.c_str());
			//系统-网络界面(主界面)
			CSystemDlg *pSysDlg = (CSystemDlg*)this->GetParent();//获取系统对话框指针
			lanStr=theApp.myLanguage.LanguageMap["IDC_SYS_SERVER_IP_STATIC"];
			pSysDlg->GetDlgItem(IDC_SYS_SERVER_IP_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SYS_SERVER_PORT_STATIC"];
			pSysDlg->GetDlgItem(IDC_SYS_SERVER_PORT_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_VALID_EQUIP_STATIC"];
			pSysDlg->GetDlgItem(IDC_VALID_EQUIP_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SYS_NET_NAME_STATIC"];
			pSysDlg->GetDlgItem(IDC_SYS_NET_NAME_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SYS_LOCAL_IP_STATIC"];
			pSysDlg->GetDlgItem(IDC_SYS_LOCAL_IP_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SYS_LOCAL_PORT_STATIC"];
			pSysDlg->GetDlgItem(IDC_SYS_LOCAL_PORT_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SYS_SUBNETMASK_STATIC"];
			pSysDlg->GetDlgItem(IDC_SYS_SUBNETMASK_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SYS_GATEWAY_STATIC"];
			pSysDlg->GetDlgItem(IDC_SYS_GATEWAY_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SYS_DHCP_STATIC"];
			pSysDlg->GetDlgItem(IDC_SYS_DHCP_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_NET_BTN"];
			pSysDlg->GetDlgItem(IDC_NET_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_COM_BTN"];
			pSysDlg->GetDlgItem(IDC_COM_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_EVN_BTN"];
			pSysDlg->GetDlgItem(IDC_EVN_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_CUSTON_BUTTON"];
			pSysDlg->GetDlgItem(IDC_CUSTON_BUTTON)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_VERSION_BTN"];
			pSysDlg->GetDlgItem(IDC_VERSION_BTN)->SetWindowText(lanStr.c_str());
			//系统-串口界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_COM1_BIT_STATIC"];
			pSysDlg->pCom->GetDlgItem(IDC_COM1_BIT_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_COM1_CHECK_STATIC"];
			pSysDlg->pCom->GetDlgItem(IDC_COM1_CHECK_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_COM2_BIT_STATIC"];
			pSysDlg->pCom->GetDlgItem(IDC_COM2_BIT_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_COM2_CHECK_STATIC"];
			pSysDlg->pCom->GetDlgItem(IDC_COM2_CHECK_STATIC)->SetWindowText(lanStr.c_str());
			//系统-环境界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_ENV_TIME_STATIC"];
			GetDlgItem(IDC_ENV_TIME_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_ENV_DATE_STATIC"];
			GetDlgItem(IDC_ENV_DATE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_LANGUAGE_STATIC"];
			GetDlgItem(IDC_LANGUAGE_STATIC)->SetWindowText(lanStr.c_str());
			//系统-版本界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_CODEPRINTER_TYPE_STATIC"];
			pSysDlg->pVersion->GetDlgItem(IDC_CODEPRINTER_TYPE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_CODEPRINTE_ID_RSTATIC"];
			pSysDlg->pVersion->GetDlgItem(IDC_CODEPRINTE_ID_RSTATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MAINBOARD_ID_STATIC"];
			pSysDlg->pVersion->GetDlgItem(IDC_MAINBOARD_ID_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MAINBOARD_HARDWARE_TYPE_STATIC"];
			pSysDlg->pVersion->GetDlgItem(IDC_MAINBOARD_HARDWARE_TYPE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_HARDWARE_UPDATE_TIME_STATIC"];
			pSysDlg->pVersion->GetDlgItem(IDC_HARDWARE_UPDATE_TIME_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MAINBOARD_SOFTWARE_TYPE_STATIC"];
			pSysDlg->pVersion->GetDlgItem(IDC_MAINBOARD_SOFTWARE_TYPE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SOFTWARE_UPDATE_TIME_STATIC"];
			pSysDlg->pVersion->GetDlgItem(IDC_SOFTWARE_UPDATE_TIME_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SYSTEM_SOFTWARE_TYPE_STATIC"];
			pSysDlg->pVersion->GetDlgItem(IDC_SYSTEM_SOFTWARE_TYPE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SYSTEM_SOFTWARE_UPDATE_TIME_STATIC"];
			pSysDlg->pVersion->GetDlgItem(IDC_SYSTEM_SOFTWARE_UPDATE_TIME_STATIC)->SetWindowText(lanStr.c_str());
			//用户-主界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_USER_CURUSERS_STATIC"];
			pCodeDlg->m_User->GetDlgItem(IDC_USER_CURUSERS_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_USER_NAME_STATIC"];
			pCodeDlg->m_User->GetDlgItem(IDC_USER_NAME_STATIC)->SetWindowText(lanStr.c_str());
			//用户-新建界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_USER_NEW_NAME_STATIC"];
			pCodeDlg->m_User->pUserNew->GetDlgItem(IDC_USER_NEW_NAME_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_USER_NEW_UNAUTHORIZED_STATIC"];
			pCodeDlg->m_User->pUserNew->GetDlgItem(IDC_USER_NEW_UNAUTHORIZED_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_NEW_PASSWARD_STATIC"];
			pCodeDlg->m_User->pUserNew->GetDlgItem(IDC_NEW_PASSWARD_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_USER_NEW_AUTHORIZED_STATIC"];
			pCodeDlg->m_User->pUserNew->GetDlgItem(IDC_USER_NEW_AUTHORIZED_STATIC)->SetWindowText(lanStr.c_str());
			//用户-打开界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_USER_OPEN_NAME_STATIC"];
			pCodeDlg->m_User->pUserOpen->GetDlgItem(IDC_USER_OPEN_NAME_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_USER_OPEN_UNAUTHORIZED_STATIC"];
			pCodeDlg->m_User->pUserOpen->GetDlgItem(IDC_USER_OPEN_UNAUTHORIZED_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_USER_OPEN_NAME_STATIC"];
			pCodeDlg->m_User->pUserOpen->GetDlgItem(IDC_OPEN_PASSWARD_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_USER_OPEN_AUTHORIZED_STATIC"];
			pCodeDlg->m_User->pUserOpen->GetDlgItem(IDC_USER_OPEN_AUTHORIZED_STATIC)->SetWindowText(lanStr.c_str());
			//用户-删除界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_USER_DEL_DEL_STATIC"];
			pCodeDlg->m_User->pUserDelete->GetDlgItem(IDC_USER_DEL_DEL_STATIC)->SetWindowText(lanStr.c_str());
			//用户-刷新界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_USER_FRESH_NAME_STATIC"];
			pCodeDlg->m_User->pUserFresh->GetDlgItem(IDC_USER_FRESH_NAME_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_FRESH_PASSWORD_STATIC"];
			pCodeDlg->m_User->pUserFresh->GetDlgItem(IDC_FRESH_PASSWORD_STATIC)->SetWindowText(lanStr.c_str());

			//喷印配置-主界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_HEIGHT_STATIC"];
			pCodeDlg->m_Confi->GetDlgItem(IDC_HEIGHT_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_REVERSE_STATIC"];
			pCodeDlg->m_Confi->GetDlgItem(IDC_REVERSE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INVERSE_STATIC"];
			pCodeDlg->m_Confi->GetDlgItem(IDC_INVERSE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_DOT_PITCH_STATIC"];
			pCodeDlg->m_Confi->GetDlgItem(IDC_DOT_PITCH_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_DELAY_STATIC"];
			pCodeDlg->m_Confi->GetDlgItem(IDC_DELAY_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_REPEAT_DIS_STATIC"];
			pCodeDlg->m_Confi->GetDlgItem(IDC_REPEAT_DIS_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SPEED_WAY_STATIC"];
			pCodeDlg->m_Confi->GetDlgItem(IDC_SPEED_WAY_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SPEED_STATIC"];
			pCodeDlg->m_Confi->GetDlgItem(IDC_SPEED_STATIC)->SetWindowText(lanStr.c_str());
			//喷印配置-喷印模式界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_PRINT_MODE_STATIC"];
			pCodeDlg->m_Confi->m_ConfigPM->GetDlgItem(IDC_PRINT_MODE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_WORK_LIST_STATIC"];
			pCodeDlg->m_Confi->m_ConfigPM->GetDlgItem(IDC_WORK_LIST_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_REAPEAT_COUNT_STATIC"];
			pCodeDlg->m_Confi->m_ConfigPM->GetDlgItem(IDC_REAPEAT_COUNT_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_VIRTUAL_PRINT_STATIC"];
			pCodeDlg->m_Confi->m_ConfigPM->GetDlgItem(IDC_VIRTUAL_PRINT_STATIC)->SetWindowText(lanStr.c_str());
			//喷印配置-外部安装界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_PCF_OUTSET_PRINTDIRE_STATIC"];
			pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_PCF_OUTSET_PRINTDIRE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_OUTSET_ENCODESIGN_STATIC"];
			pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_OUTSET_ENCODESIGN_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_OUTSET_FREQMULTI_STATIC"];
			pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_OUTSET_FREQMULTI_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_OUTSET_IMPULSE_STATIC"];
			pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_OUTSET_IMPULSE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_OUTSET_LENGTH_STATIC"];
			pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_OUTSET_LENGTH_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_OUTSET_PRODUCT_DETE_STATIC"];
			pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_OUTSET_PRODUCT_DETE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_OUTSET_ACTIVELEV_STATIC"];
			pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_OUTSET_ACTIVELEV_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_OUTSET_CUR_LEV_STATIC"];
			pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_OUTSET_CUR_LEV_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_OUTSET_TRIGGER_LEN_STATIC"];
			pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_OUTSET_TRIGGER_LEN_STATIC)->SetWindowText(lanStr.c_str());
			//文字编辑-主界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_MATRIX_STATIC"];
			pCodeDlg->m_Label->GetDlgItem(IDC_MATRIX_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_PIXEL_STATIC"];
			pCodeDlg->m_Label->GetDlgItem(IDC_PIXEL_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_REVERSAL_STATIC"];
			pCodeDlg->m_Label->GetDlgItem(IDC_REVERSAL_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_PERVERSION_STATIC"];
			pCodeDlg->m_Label->GetDlgItem(IDC_PERVERSION_STATIC)->SetWindowText(lanStr.c_str());

			//墨水系统-普通界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_PRESSURE_STATIC"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_PRESSURE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_PUMP_SPEED_STATIC"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_PUMP_SPEED_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_TEMP_STATIC"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_INK_TEMP_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_PTINTHEAD_TEMP_STATIC"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_PTINTHEAD_TEMP_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_LEV_STATIC"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_INK_LEV_STATIC)->SetWindowText(lanStr.c_str());

			lanStr=theApp.myLanguage.LanguageMap["IDC_SOLVENT_LEV_STATIC"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_SOLVENT_LEV_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_TARGET_VISCO_STATIC"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_TARGET_VISCO_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_ACTUAL_VISCO_STATIC"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_ACTUAL_VISCO_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_HIGH_VOL_STATIC"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_HIGH_VOL_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INKFLOW_STATIC"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_INKFLOW_STATIC)->SetWindowText(lanStr.c_str());

			lanStr=theApp.myLanguage.LanguageMap["IDC_SPEED_MODE_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_SPEED_MODE_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_BLEED_VALVE_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_BLEED_VALVE_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_WASH_VALVE_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_WASH_VALVE_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_FEED_VALVE_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_FEED_VALVE_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_VISCO_VALVE_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_VISCO_VALVE_BTN)->SetWindowText(lanStr.c_str());

			lanStr=theApp.myLanguage.LanguageMap["IDC_PRESSURE_MODE_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_PRESSURE_MODE_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_PUMP_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_PUMP_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_NOZZLE_VALVE_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_NOZZLE_VALVE_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SOLVENT_VALVE_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_SOLVENT_VALVE_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_FLUSH_VALVE_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_FLUSH_VALVE_BTN)->SetWindowText(lanStr.c_str());

			lanStr=theApp.myLanguage.LanguageMap["IDC_USUAL_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_USUAL_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_ADVANCE_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_ADVANCE_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SETUP_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_SETUP_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_PARAMETER_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_PARAMETER_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_PHASING_BTN"];
			pCodeDlg->m_Ink->GetDlgItem(IDC_PHASING_BTN)->SetWindowText(lanStr.c_str());
			//墨水系统-高级界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_CIR_BTN"];
			pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_INK_CIR_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_ADJUST_INKLINE_BTN"];
			pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_ADJUST_INKLINE_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SUCK_NOZZLE_BTN"];
			pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_SUCK_NOZZLE_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_WASH_NOZZLE_BTN"];
			pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_WASH_NOZZLE_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_BETECT_VISCO_BTN"];
			pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_BETECT_VISCO_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INKFLOW_OFF_BTN"];
			pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_INKFLOW_OFF_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_ADD_SOLVENT_BTN"];
			pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_ADD_SOLVENT_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_HIGH_VOLTAGE_BTN"];
			pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_HIGH_VOLTAGE_BTN)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_CLOSE_INKLINE_BTN"];
			pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_CLOSE_INKLINE_BTN)->SetWindowText(lanStr.c_str());
			//墨水系统-安装界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_SIZE_STATIC"];
			pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_SIZE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_RATE_STATIC"];
			pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_RATE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_INKTYPE_STATIC"];
			pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_INKTYPE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_CON_STATIC"];
			pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_CON_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_SLEEPMODE_STATIC"];
			pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_SLEEPMODE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_TIMERESET_STATIC"];
			pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_TIMERESET_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_NEXTTIME_STATIC"];
			pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_NEXTTIME_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_LASTTIME_STATIC"];
			pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_LASTTIME_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INKSETUP_SOL_LEV_JUST_STATIC"];
			pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INKSETUP_SOL_LEV_JUST_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_INK_LEV_JUSTSTATIC"];
			pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_INK_LEV_JUSTSTATIC)->SetWindowText(lanStr.c_str());
			//墨水系统-参数界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_PAR_PRESSURE_STATIC"];
			pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_PAR_PRESSURE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_PAR_PUMP_SPEED_STATIC"];
			pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_PAR_PUMP_SPEED_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_FLOW_LEV_STATIC"];
			pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_INK_FLOW_LEV_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_ADD_LEV_STATIC"];
			pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_INK_ADD_LEV_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_INK_EMPTY_LEV_STATIC"];
			pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_INK_EMPTY_LEV_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_PRINTHEAD_TEMP_STATIC"];
			pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_PRINTHEAD_TEMP_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_VISCO_DEVIA_STATIC"];
			pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_VISCO_DEVIA_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SOLVENT_FLOW_LEV_STATIC"];
			pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_SOLVENT_FLOW_LEV_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SOL_ADD_LEV_STATIC"];
			pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_SOL_ADD_LEV_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SOL_EMPTY_LEV_STATIC"];
			pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_SOL_EMPTY_LEV_STATIC)->SetWindowText(lanStr.c_str());
			//墨水系统-相位界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_MODULATION_V_STATIC"];
			pCodeDlg->m_Ink->m_phas->GetDlgItem(IDC_MODULATION_V_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_FIXED_STATIC"];
			pCodeDlg->m_Ink->m_phas->GetDlgItem(IDC_FIXED_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_AUTO_SET_STATIC"];
			pCodeDlg->m_Ink->m_phas->GetDlgItem(IDC_AUTO_SET_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_AUTO_SET_STATIC"];
			pCodeDlg->m_Ink->m_phas->GetDlgItem(IDC_SET_ADJUST_BIG_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_SET_ADJUST_SMALL_STATIC"];
			pCodeDlg->m_Ink->m_phas->GetDlgItem(IDC_SET_ADJUST_SMALL_STATIC)->SetWindowText(lanStr.c_str());
			//故障界面
			lanStr=theApp.myLanguage.LanguageMap["IDC_DATE_STATIC"];
			pCodeDlg->m_Fault->GetDlgItem(IDC_DATE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_TIME_STATIC"];
			pCodeDlg->m_Fault->GetDlgItem(IDC_TIME_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_TYPE_STATIC"];
			pCodeDlg->m_Fault->GetDlgItem(IDC_TYPE_STATIC)->SetWindowText(lanStr.c_str());
			lanStr=theApp.myLanguage.LanguageMap["IDC_MESSAGE_STATIC"];
			pCodeDlg->m_Fault->GetDlgItem(IDC_MESSAGE_STATIC)->SetWindowText(lanStr.c_str());
		}
		break;
	default:
		return;
	}
}

HBRUSH CEnvDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

void CEnvDlg::OnBnClickedLanSelButton()
{
	// TODO: 在此添加控件通知处理程序代码
	//OnCbnSelchangeLanguageCombo();
}
