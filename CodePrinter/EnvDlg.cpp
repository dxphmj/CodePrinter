// EnvDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "EnvDlg.h"
#include "SystemDlg.h"
#include "CodePrinterDlg.h"
#include "Arabicconjunction.h"
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
// CEnvDlg �Ի���

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
	DDX_Control(pDX, IDC_ENV_TIME_STATIC, m_evn_timeStatic);
	DDX_Control(pDX, IDC_ENV_DATE_STATIC, m_evn_dateStatic);
	DDX_Control(pDX, IDC_LANGUAGE_STATIC, m_evn_languageStatic);
	DDX_Control(pDX, IDC_ENV_TIME_EDIT, m_envTimeEdit);
	DDX_Control(pDX, IDC_ENV_DATE_EDIT, m_envDateEdit);
}


BEGIN_MESSAGE_MAP(CEnvDlg, CDialog)
	ON_CBN_SELCHANGE(IDC_LANGUAGE_LIST, &CEnvDlg::OnCbnSelchangeLanguageCombo)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_LAN_SEL_BUTTON, &CEnvDlg::OnBnClickedLanSelButton)
END_MESSAGE_MAP()


// CEnvDlg ��Ϣ�������

BOOL CEnvDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

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
	GetDlgItem(IDC_LAN_SEL_BUTTON)->SetWindowPos(NULL,rect1.left,rect1.top,80,55,SWP_SHOWWINDOW);
	m_ButLanSel.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_80_55_BITMAP);

	m_langeageList.SetItemHeight(0,20);
	m_envTimeEdit.SetFont(theApp.m_EditFont);
	m_envDateEdit.SetFont(theApp.m_EditFont);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CEnvDlg::OnCbnSelchangeLanguageCombo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nIndex = m_langeageList.GetCurSel();  //��ǰѡ�е���
	bool isRead=false;
	switch(nIndex)
	{
	case CHINESE_SIMPLIFIED:
        isRead= theApp.myLanguage.readLanguageXml("ChineseSimplified.xml");
		if (isRead)
		{
			ControlTextChange();
		}
		break;
	case ENGLISH:
		isRead= theApp.myLanguage.readLanguageXml("English.xml");
		if (isRead)
		{
			ControlTextChange();
		}
		break;
	case ARABIC:
		isRead= theApp.myLanguage.readLanguageXml("Arabic.xml");
		if (isRead)
		{
			ControlTextChange();
		}
		break;
	case DUTCH:
		isRead= theApp.myLanguage.readLanguageXml("Dutch.xml");
		if (isRead)
		{
			ControlTextChange();
		}
		break;
	case HUNGARIAN:
		isRead= theApp.myLanguage.readLanguageXml("Hungarian.xml");
		if (isRead)
		{
			ControlTextChange();
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
	// TODO:  �ڴ˸��� DC ���κ�����
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return theApp.m_DlgBrush;
}

void CEnvDlg::OnBnClickedLanSelButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//OnCbnSelchangeLanguageCombo();
}

void CEnvDlg::ControlTextChange()
{
	wstring lanStr;
	CString tempstr;
	CCodePrinterDlg *pCodeDlg = (CCodePrinterDlg*)this->GetParent()->GetParent();//��ȡ���Ի���ָ��
	//�������Ժ��ʼ����ͷ,����״̬
	lanStr=theApp.myLanguage.LanguageMap["IDC_MACHINE_STATUS"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_PicHead.SetMachineStatus(tempstr);//Shut Down
	pCodeDlg->showDlg(IDD_SYSTEM_DIALOG);
	//��ӡ��������
	lanStr=theApp.myLanguage.LanguageMap["IDC_PRINT_PRE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->GetDlgItem(IDC_PRINT_PRE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_PRINT_LAB_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->GetDlgItem(IDC_MAIN_PRINT_LAB_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_PRINT_PCF_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->GetDlgItem(IDC_MAIN_PRINT_PCF_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_COUNTER_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->GetDlgItem(IDC_MAIN_COUNTER_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_PRODUCT_DETECTED_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->GetDlgItem(IDC_MAIN_PRODUCT_DETECTED_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_PRODUCT_PRINTED_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->GetDlgItem(IDC_MAIN_PRODUCT_PRINTED_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_SERIAL_NUM_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->GetDlgItem(IDC_MAIN_SERIAL_NUM_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_NUM1_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->GetDlgItem(IDC_MAIN_NUM1_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_NUM2_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->GetDlgItem(IDC_MAIN_NUM2_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_NUM3_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->GetDlgItem(IDC_MAIN_NUM3_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_MAIN_NUM4_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->GetDlgItem(IDC_MAIN_NUM4_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_RESET_COUNT_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->GetDlgItem(IDC_RESET_COUNT_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_RESET_SERIAL_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->GetDlgItem(IDC_RESET_SERIAL_BTN)->SetWindowText(tempstr);
	//ϵͳ-�������(������)
	CSystemDlg *pSysDlg = (CSystemDlg*)this->GetParent();//��ȡϵͳ�Ի���ָ��
	lanStr=theApp.myLanguage.LanguageMap["IDC_SYS_SERVER_IP_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->GetDlgItem(IDC_SYS_SERVER_IP_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_SYS_SERVER_PORT_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->GetDlgItem(IDC_SYS_SERVER_PORT_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_VALID_EQUIP_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->GetDlgItem(IDC_VALID_EQUIP_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_SYS_NET_NAME_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->GetDlgItem(IDC_SYS_NET_NAME_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_SYS_LOCAL_IP_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->GetDlgItem(IDC_SYS_LOCAL_IP_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_SYS_LOCAL_PORT_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->GetDlgItem(IDC_SYS_LOCAL_PORT_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_SYS_SUBNETMASK_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->GetDlgItem(IDC_SYS_SUBNETMASK_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_SYS_GATEWAY_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->GetDlgItem(IDC_SYS_GATEWAY_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_SYS_DHCP_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->GetDlgItem(IDC_SYS_DHCP_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_NET_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->GetDlgItem(IDC_NET_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_COM_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->GetDlgItem(IDC_COM_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_EVN_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->GetDlgItem(IDC_EVN_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_CUSTON_BUTTON"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->GetDlgItem(IDC_CUSTON_BUTTON)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_VERSION_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->GetDlgItem(IDC_VERSION_BTN)->SetWindowText(tempstr);
	//ϵͳ-���ڽ���
	lanStr=theApp.myLanguage.LanguageMap["IDC_COM1_BIT_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->pCom->GetDlgItem(IDC_COM1_BIT_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_COM1_CHECK_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->pCom->GetDlgItem(IDC_COM1_CHECK_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_COM2_BIT_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->pCom->GetDlgItem(IDC_COM2_BIT_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_COM2_CHECK_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->pCom->GetDlgItem(IDC_COM2_CHECK_STATIC)->SetWindowText(tempstr);
	//ϵͳ-��������
	lanStr=theApp.myLanguage.LanguageMap["IDC_ENV_TIME_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	GetDlgItem(IDC_ENV_TIME_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_ENV_DATE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	GetDlgItem(IDC_ENV_DATE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_LANGUAGE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	GetDlgItem(IDC_LANGUAGE_STATIC)->SetWindowText(tempstr);
	//ϵͳ-�汾����
	lanStr=theApp.myLanguage.LanguageMap["IDC_CODEPRINTER_TYPE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->pVersion->GetDlgItem(IDC_CODEPRINTER_TYPE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_CODEPRINTE_ID_RSTATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->pVersion->GetDlgItem(IDC_CODEPRINTE_ID_RSTATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_MAINBOARD_ID_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->pVersion->GetDlgItem(IDC_MAINBOARD_ID_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_MAINBOARD_HARDWARE_TYPE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->pVersion->GetDlgItem(IDC_MAINBOARD_HARDWARE_TYPE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_HARDWARE_UPDATE_TIME_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->pVersion->GetDlgItem(IDC_HARDWARE_UPDATE_TIME_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_MAINBOARD_SOFTWARE_TYPE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->pVersion->GetDlgItem(IDC_MAINBOARD_SOFTWARE_TYPE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_SOFTWARE_UPDATE_TIME_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->pVersion->GetDlgItem(IDC_SOFTWARE_UPDATE_TIME_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_SYSTEM_SOFTWARE_TYPE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->pVersion->GetDlgItem(IDC_SYSTEM_SOFTWARE_TYPE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_SYSTEM_SOFTWARE_UPDATE_TIME_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pSysDlg->pVersion->GetDlgItem(IDC_SYSTEM_SOFTWARE_UPDATE_TIME_STATIC)->SetWindowText(tempstr);
	//�û�-������
	lanStr=theApp.myLanguage.LanguageMap["IDC_USER_CURUSERS_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_User->GetDlgItem(IDC_USER_CURUSERS_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_USER_NAME_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_User->GetDlgItem(IDC_USER_NAME_STATIC)->SetWindowText(tempstr);
	//�û�-�½�����
	lanStr=theApp.myLanguage.LanguageMap["IDC_USER_NEW_NAME_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_User->pUserNew->GetDlgItem(IDC_USER_NEW_NAME_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_USER_NEW_UNAUTHORIZED_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_User->pUserNew->GetDlgItem(IDC_USER_NEW_UNAUTHORIZED_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_NEW_PASSWARD_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_User->pUserNew->GetDlgItem(IDC_NEW_PASSWARD_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_USER_NEW_AUTHORIZED_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_User->pUserNew->GetDlgItem(IDC_USER_NEW_AUTHORIZED_STATIC)->SetWindowText(tempstr);
	//�û�-�򿪽���
	lanStr=theApp.myLanguage.LanguageMap["IDC_USER_OPEN_NAME_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_User->pUserOpen->GetDlgItem(IDC_USER_OPEN_NAME_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_USER_OPEN_UNAUTHORIZED_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_User->pUserOpen->GetDlgItem(IDC_USER_OPEN_UNAUTHORIZED_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_USER_OPEN_NAME_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_User->pUserOpen->GetDlgItem(IDC_OPEN_PASSWARD_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_USER_OPEN_AUTHORIZED_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_User->pUserOpen->GetDlgItem(IDC_USER_OPEN_AUTHORIZED_STATIC)->SetWindowText(tempstr);
	//�û�-ɾ������
	lanStr=theApp.myLanguage.LanguageMap["IDC_USER_DEL_DEL_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_User->pUserDelete->GetDlgItem(IDC_USER_DEL_DEL_STATIC)->SetWindowText(tempstr);
	//�û�-ˢ�½���
	lanStr=theApp.myLanguage.LanguageMap["IDC_USER_FRESH_NAME_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_User->pUserFresh->GetDlgItem(IDC_USER_FRESH_NAME_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_FRESH_PASSWORD_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_User->pUserFresh->GetDlgItem(IDC_FRESH_PASSWORD_STATIC)->SetWindowText(tempstr);

	//��ӡ����-������
	lanStr=theApp.myLanguage.LanguageMap["IDC_HEIGHT_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Confi->GetDlgItem(IDC_HEIGHT_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_REVERSE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Confi->GetDlgItem(IDC_REVERSE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_INVERSE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Confi->GetDlgItem(IDC_INVERSE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_DOT_PITCH_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Confi->GetDlgItem(IDC_DOT_PITCH_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_DELAY_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Confi->GetDlgItem(IDC_DELAY_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_REPEAT_DIS_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Confi->GetDlgItem(IDC_REPEAT_DIS_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_SPEED_WAY_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Confi->GetDlgItem(IDC_SPEED_WAY_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_SPEED_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Confi->GetDlgItem(IDC_SPEED_STATIC)->SetWindowText(tempstr);
	//��ӡ����-��ӡģʽ����
	lanStr=theApp.myLanguage.LanguageMap["IDC_PRINT_MODE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Confi->m_ConfigPM->GetDlgItem(IDC_PRINT_MODE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_WORK_LIST_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Confi->m_ConfigPM->GetDlgItem(IDC_WORK_LIST_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_REAPEAT_COUNT_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Confi->m_ConfigPM->GetDlgItem(IDC_REAPEAT_COUNT_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_VIRTUAL_PRINT_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Confi->m_ConfigPM->GetDlgItem(IDC_VIRTUAL_PRINT_STATIC)->SetWindowText(tempstr);
	//��ӡ����-�ⲿ��װ����
	lanStr=theApp.myLanguage.LanguageMap["IDC_PCF_OUTSET_PRINTDIRE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_PCF_OUTSET_PRINTDIRE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_OUTSET_ENCODESIGN_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_OUTSET_ENCODESIGN_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_OUTSET_FREQMULTI_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_OUTSET_FREQMULTI_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_OUTSET_IMPULSE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_OUTSET_IMPULSE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_OUTSET_LENGTH_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_OUTSET_LENGTH_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_OUTSET_PRODUCT_DETE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_OUTSET_PRODUCT_DETE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_OUTSET_ACTIVELEV_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_OUTSET_ACTIVELEV_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_OUTSET_CUR_LEV_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_OUTSET_CUR_LEV_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_OUTSET_TRIGGER_LEN_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Confi->m_ConfigOS->GetDlgItem(IDC_OUTSET_TRIGGER_LEN_STATIC)->SetWindowText(tempstr);
	//���ֱ༭-������
	lanStr=theApp.myLanguage.LanguageMap["IDC_MATRIX_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->GetDlgItem(IDC_MATRIX_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_PIXEL_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->GetDlgItem(IDC_PIXEL_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_REVERSAL_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->GetDlgItem(IDC_REVERSAL_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_PERVERSION_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->GetDlgItem(IDC_PERVERSION_STATIC)->SetWindowText(tempstr);
	//�ı��༭����
	lanStr=theApp.myLanguage.LanguageMap["IDC_EDITTEXT_TEXT_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pEditText->GetDlgItem(IDC_EDITTEXT_TEXT_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_EDITTEXT_FONT_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pEditText->GetDlgItem(IDC_EDITTEXT_FONT_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_EDITTEXT_DATAFIELD_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pEditText->GetDlgItem(IDC_EDITTEXT_DATAFIELD_STATIC)->SetWindowText(tempstr);
	//���ڱ༭����
	lanStr=theApp.myLanguage.LanguageMap["IDC_DATE_PREVIEW_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pDate->GetDlgItem(IDC_DATE_PREVIEW_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_DATE_DATETIME_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pDate->GetDlgItem(IDC_DATE_DATETIME_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_DATE_FORMAT_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pDate->GetDlgItem(IDC_DATE_FORMAT_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_DATE_FONT_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pDate->GetDlgItem(IDC_DATE_FONT_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_DATE_SKEW_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pDate->GetDlgItem(IDC_DATE_SKEW_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_DATE_SKEW_VALUE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pDate->GetDlgItem(IDC_DATE_SKEW_VALUE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_DATE_SKEW_UNIT_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pDate->GetDlgItem(IDC_DATE_SKEW_UNIT_STATIC)->SetWindowText(tempstr);
	//������༭����
	lanStr=theApp.myLanguage.LanguageMap["IDC_BARCODE_TEXT_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pBarCode->GetDlgItem(IDC_BARCODE_TEXT_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_BARCODE_SET_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pBarCode->GetDlgItem(IDC_BARCODE_SET_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_BARCODE_SIZE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pBarCode->GetDlgItem(IDC_BARCODE_SIZE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_ECC_LEVEL_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pBarCode->GetDlgItem(IDC_ECC_LEVEL_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_ENCODING_MODE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pBarCode->GetDlgItem(IDC_ENCODING_MODE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_BARCODE_DYNAMIC_EDIT_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pBarCode->GetDlgItem(IDC_BARCODE_DYNAMIC_EDIT_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_BARCODE_FIGURE_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pBarCode->GetDlgItem(IDC_BARCODE_FIGURE_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_BARCODE_DATE_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pBarCode->GetDlgItem(IDC_BARCODE_DATE_BTN)->SetWindowText(tempstr);
	//���кű༭����
	lanStr=theApp.myLanguage.LanguageMap["IDC_PREVIEW_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pEditFigure->GetDlgItem(IDC_PREVIEW_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_FIRST_QUARTILE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pEditFigure->GetDlgItem(IDC_FIRST_QUARTILE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_FOUR_QUARTILE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pEditFigure->GetDlgItem(IDC_FOUR_QUARTILE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_START_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pEditFigure->GetDlgItem(IDC_START_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_STEP_SIZE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pEditFigure->GetDlgItem(IDC_STEP_SIZE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_REPEAT_COUNT_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pEditFigure->GetDlgItem(IDC_REPEAT_COUNT_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_BIT_DATA_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pEditFigure->GetDlgItem(IDC_BIT_DATA_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_COUNTER_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pEditFigure->GetDlgItem(IDC_COUNTER_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_FONT_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pEditFigure->GetDlgItem(IDC_FONT_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_FORMAT_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Label->pInput->pEditFigure->GetDlgItem(IDC_FORMAT_STATIC)->SetWindowText(tempstr);
	//īˮϵͳ-��ͨ����
	lanStr=theApp.myLanguage.LanguageMap["IDC_PRESSURE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->GetDlgItem(IDC_PRESSURE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_PUMP_SPEED_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->GetDlgItem(IDC_PUMP_SPEED_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_INK_TEMP_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->GetDlgItem(IDC_INK_TEMP_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_PTINTHEAD_TEMP_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->GetDlgItem(IDC_PTINTHEAD_TEMP_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_INK_LEV_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->GetDlgItem(IDC_INK_LEV_STATIC)->SetWindowText(tempstr);

	lanStr=theApp.myLanguage.LanguageMap["IDC_SOLVENT_LEV_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->GetDlgItem(IDC_SOLVENT_LEV_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_TARGET_VISCO_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->GetDlgItem(IDC_TARGET_VISCO_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_ACTUAL_VISCO_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->GetDlgItem(IDC_ACTUAL_VISCO_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_HIGH_VOL_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->GetDlgItem(IDC_HIGH_VOL_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_INKFLOW_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->GetDlgItem(IDC_INKFLOW_STATIC)->SetWindowText(tempstr);

	lanStr=theApp.myLanguage.LanguageMap["IDC_SPEED_MODE_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->GetDlgItem(IDC_SPEED_MODE_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_BLEED_VALVE_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->GetDlgItem(IDC_BLEED_VALVE_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_WASH_VALVE_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->GetDlgItem(IDC_WASH_VALVE_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_FEED_VALVE_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->GetDlgItem(IDC_FEED_VALVE_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_VISCO_VALVE_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->GetDlgItem(IDC_VISCO_VALVE_BTN)->SetWindowText(tempstr);

	lanStr=theApp.myLanguage.LanguageMap["IDC_PRESSURE_MODE_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->GetDlgItem(IDC_PRESSURE_MODE_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_PUMP_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->GetDlgItem(IDC_PUMP_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_NOZZLE_VALVE_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->GetDlgItem(IDC_NOZZLE_VALVE_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_SOLVENT_VALVE_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->GetDlgItem(IDC_SOLVENT_VALVE_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_FLUSH_VALVE_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->GetDlgItem(IDC_FLUSH_VALVE_BTN)->SetWindowText(tempstr);

	lanStr=theApp.myLanguage.LanguageMap["IDC_USUAL_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->GetDlgItem(IDC_USUAL_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_ADVANCE_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->GetDlgItem(IDC_ADVANCE_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_SETUP_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->GetDlgItem(IDC_SETUP_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_PARAMETER_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->GetDlgItem(IDC_PARAMETER_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_PHASING_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->GetDlgItem(IDC_PHASING_BTN)->SetWindowText(tempstr);
	//īˮϵͳ-�߼�����
	lanStr=theApp.myLanguage.LanguageMap["IDC_INK_CIR_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_INK_CIR_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_ADJUST_INKLINE_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_ADJUST_INKLINE_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_SUCK_NOZZLE_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_SUCK_NOZZLE_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_WASH_NOZZLE_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_WASH_NOZZLE_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_BETECT_VISCO_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_BETECT_VISCO_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_INKFLOW_OFF_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_INKFLOW_OFF_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_ADD_SOLVENT_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_ADD_SOLVENT_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_HIGH_VOLTAGE_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_HIGH_VOLTAGE_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_CLOSE_INKLINE_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_inkAdv->GetDlgItem(IDC_CLOSE_INKLINE_BTN)->SetWindowText(tempstr);
	//īˮϵͳ-��װ����
	lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_SIZE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_SIZE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_RATE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_RATE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_INKTYPE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_INKTYPE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_CON_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_CON_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_SLEEPMODE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_SLEEPMODE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_TIMERESET_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_TIMERESET_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_NEXTTIME_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_NEXTTIME_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_LASTTIME_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_LASTTIME_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_INKSETUP_SOL_LEV_JUST_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INKSETUP_SOL_LEV_JUST_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_INK_SETUP_INK_LEV_JUSTSTATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_setup->GetDlgItem(IDC_INK_SETUP_INK_LEV_JUSTSTATIC)->SetWindowText(tempstr);
	//īˮϵͳ-��������
	lanStr=theApp.myLanguage.LanguageMap["IDC_PAR_PRESSURE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_PAR_PRESSURE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_PAR_PUMP_SPEED_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_PAR_PUMP_SPEED_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_INK_FLOW_LEV_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_INK_FLOW_LEV_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_INK_ADD_LEV_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_INK_ADD_LEV_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_INK_EMPTY_LEV_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_INK_EMPTY_LEV_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_PRINTHEAD_TEMP_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_PRINTHEAD_TEMP_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_VISCO_DEVIA_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_VISCO_DEVIA_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_SOLVENT_FLOW_LEV_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_SOLVENT_FLOW_LEV_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_SOL_ADD_LEV_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_SOL_ADD_LEV_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_SOL_EMPTY_LEV_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_par->GetDlgItem(IDC_SOL_EMPTY_LEV_STATIC)->SetWindowText(tempstr);
	//īˮϵͳ-��λ����
	lanStr=theApp.myLanguage.LanguageMap["IDC_MODULATION_V_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_phas->GetDlgItem(IDC_MODULATION_V_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_FIXED_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_phas->GetDlgItem(IDC_FIXED_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_AUTO_SET_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_phas->GetDlgItem(IDC_AUTO_SET_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_AUTO_SET_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_phas->GetDlgItem(IDC_SET_ADJUST_BIG_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_SET_ADJUST_SMALL_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Ink->m_phas->GetDlgItem(IDC_SET_ADJUST_SMALL_STATIC)->SetWindowText(tempstr);
	//���Ͻ���
	lanStr=theApp.myLanguage.LanguageMap["IDC_DATE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Fault->GetDlgItem(IDC_DATE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_TIME_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Fault->GetDlgItem(IDC_TIME_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_TYPE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Fault->GetDlgItem(IDC_TYPE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_MESSAGE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Fault->GetDlgItem(IDC_MESSAGE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_L_HISTORY_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Fault->GetDlgItem(IDC_L_HISTORY_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_R_HISTORY_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_Fault->GetDlgItem(IDC_R_HISTORY_BTN)->SetWindowText(tempstr);
	//���к����ý���
	lanStr=theApp.myLanguage.LanguageMap["IDC_RESET_SERIAL_NAME_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_resetSerial->GetDlgItem(IDC_RESET_SERIAL_NAME_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_QUADRANT1_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_resetSerial->GetDlgItem(IDC_QUADRANT1_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_QUADRANT2_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_resetSerial->GetDlgItem(IDC_QUADRANT2_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_CUR_VALUE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_resetSerial->GetDlgItem(IDC_CUR_VALUE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_SET_VALUE_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_resetSerial->GetDlgItem(IDC_SET_VALUE_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_SERIAL1_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_resetSerial->GetDlgItem(IDC_SERIAL1_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_SERIAL2_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_resetSerial->GetDlgItem(IDC_SERIAL2_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_SERIAL3_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_resetSerial->GetDlgItem(IDC_SERIAL3_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_SERIAL4_STATIC"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_resetSerial->GetDlgItem(IDC_SERIAL4_STATIC)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_ALL_RESET_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_resetSerial->GetDlgItem(IDC_ALL_RESET_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_RESET_SERIAL1_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_resetSerial->GetDlgItem(IDC_RESET_SERIAL1_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_RESET_SERIAL2_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_resetSerial->GetDlgItem(IDC_RESET_SERIAL2_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_RESET_SERIAL3_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_resetSerial->GetDlgItem(IDC_RESET_SERIAL3_BTN)->SetWindowText(tempstr);
	lanStr=theApp.myLanguage.LanguageMap["IDC_RESET_SERIAL4_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	pCodeDlg->m_resetSerial->GetDlgItem(IDC_RESET_SERIAL4_BTN)->SetWindowText(tempstr);
}
