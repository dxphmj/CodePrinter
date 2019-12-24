// InkAdvanceDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "InkAdvanceDlg.h"


// CInkAdvanceDlg �Ի���

IMPLEMENT_DYNAMIC(CInkAdvanceDlg, CDialog)

CInkAdvanceDlg::CInkAdvanceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInkAdvanceDlg::IDD, pParent)
{

}

CInkAdvanceDlg::~CInkAdvanceDlg()
{
}

void CInkAdvanceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);	
}


BEGIN_MESSAGE_MAP(CInkAdvanceDlg, CDialog)
	ON_BN_CLICKED(IDC_INKFLOW_OFF_BTN, &CInkAdvanceDlg::OnBnClickedInkflowOffBtn)
	ON_BN_CLICKED(IDC_CLOSE_INKLINE_BTN, &CInkAdvanceDlg::OnBnClickedCloseInklineBtn)
	ON_BN_CLICKED(IDC_ADD_SOLVENT_BTN, &CInkAdvanceDlg::OnBnClickedAddSolventBtn)
	ON_BN_CLICKED(IDC_HIGH_VOLTAGE_BTN, &CInkAdvanceDlg::OnBnClickedHighVoltageBtn)
	ON_BN_CLICKED(IDC_BETECT_VISCO_BTN, &CInkAdvanceDlg::OnBnClickedBetectViscoBtn)
	ON_BN_CLICKED(IDC_WASH_NOZZLE_BTN, &CInkAdvanceDlg::OnBnClickedWashNozzleBtn)
	ON_BN_CLICKED(IDC_SUCK_NOZZLE_BTN, &CInkAdvanceDlg::OnBnClickedSuckNozzleBtn)
	ON_BN_CLICKED(IDC_ADJUST_INKLINE_BTN, &CInkAdvanceDlg::OnBnClickedAdjustInklineBtn)
	ON_BN_CLICKED(IDC_INK_CIR_BTN, &CInkAdvanceDlg::OnBnClickedInkCirBtn)
END_MESSAGE_MAP()

//��ʼ��
BOOL CInkAdvanceDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��2
	
	GetDlgItem(IDC_SUCK_NOZZLE_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);
	m_CIB_SuckNozzle.Attach(IDC_SUCK_NOZZLE_BTN,this);
	GetDlgItem(IDC_INKFLOW_OFF_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);//�ػ��ռ��
	m_CIB_InkflowOff.Attach(IDC_INKFLOW_OFF_BTN,this);
	GetDlgItem(IDC_CLOSE_INKLINE_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);//�ر�ī��
	m_CIB_CloseInkline.Attach(IDC_CLOSE_INKLINE_BTN,this);
	GetDlgItem(IDC_ADD_SOLVENT_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);//������ܼ�
	m_CIB_AddSolvent.Attach(IDC_ADD_SOLVENT_BTN,this);
	GetDlgItem(IDC_BETECT_VISCO_BTN)->ModifyStyle(0,BS_OWNERDRAW,0); //������ճ��
	m_CIB_BetectVisco.Attach(IDC_BETECT_VISCO_BTN,this);
	GetDlgItem(IDC_WASH_NOZZLE_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);//����ϴ����
	m_CIB_WashNozzle.Attach(IDC_WASH_NOZZLE_BTN,this);
	GetDlgItem(IDC_ADJUST_INKLINE_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);//��ī��У׼
	m_CIB_AdjustInkline.Attach(IDC_ADJUST_INKLINE_BTN,this);
	GetDlgItem(IDC_INK_CIR_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);//��ī·ѭ��
	m_CIB_InkCir.Attach(IDC_INK_CIR_BTN,this);
	GetDlgItem(IDC_HIGH_VOLTAGE_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);//��ѹ����
	m_CIB_HighVoltage.Attach(IDC_HIGH_VOLTAGE_BTN,this);


	return TRUE;  // return TRUE unless you set the focus to a control
}
	
// CInkAdvanceDlg ��Ϣ�������
//�ػ��ռ�⣬��������¿��·�
void CInkAdvanceDlg::OnBnClickedInkflowOffBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.myStatusClass.ctr0X02bit0=(theApp.myStatusClass.ctr0X02bit0==1?0:1);
	theApp.myStatusClass.download_inksystem_control02();
}
//��ī�ߣ���������¿��·�
void CInkAdvanceDlg::OnBnClickedCloseInklineBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.myStatusClass.ctr0X02bit1=(theApp.myStatusClass.ctr0X02bit1==1?0:1);
	theApp.myStatusClass.download_inksystem_control02();
}
//����ܼ�����������¿��·�
void CInkAdvanceDlg::OnBnClickedAddSolventBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.myStatusClass.ctr0X02bit2=(theApp.myStatusClass.ctr0X02bit2==1?0:1);
	theApp.myStatusClass.download_inksystem_control02();
}
//��ѹ����
void CInkAdvanceDlg::OnBnClickedHighVoltageBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.myStatusClass.ctr0X03bit3=(theApp.myStatusClass.ctr0X03bit3==1?0:1);
	theApp.myStatusClass.ad_button_onoff(GetSafeHwnd());
	theApp.myStatusClass.download_inksystem_control03();
}
//ճ�Ȳ���
void CInkAdvanceDlg::OnBnClickedBetectViscoBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.myStatusClass.ctr0X02bit3=(theApp.myStatusClass.ctr0X02bit3==1?0:1);
	theApp.myStatusClass.ad_button_onoff(GetSafeHwnd());
	theApp.myStatusClass.download_inksystem_control02();
}
//��ϴ����
void CInkAdvanceDlg::OnBnClickedWashNozzleBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.myStatusClass.ctr0X02bit4=(theApp.myStatusClass.ctr0X02bit4==1?0:1);
	theApp.myStatusClass.ad_button_onoff(GetSafeHwnd());
	theApp.myStatusClass.download_inksystem_control02();
}
//��������
void CInkAdvanceDlg::OnBnClickedSuckNozzleBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.myStatusClass.ctr0X02bit5=(theApp.myStatusClass.ctr0X02bit5==1?0:1);
	theApp.myStatusClass.ad_button_onoff(GetSafeHwnd());
	theApp.myStatusClass.download_inksystem_control02();
}
//ī��У׼
void CInkAdvanceDlg::OnBnClickedAdjustInklineBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.myStatusClass.ctr0X02bit6=(theApp.myStatusClass.ctr0X02bit6==1?0:1);
	theApp.myStatusClass.ad_button_onoff(GetSafeHwnd());
	theApp.myStatusClass.download_inksystem_control02();
}
//ī·ѭ��
void CInkAdvanceDlg::OnBnClickedInkCirBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.myStatusClass.ctr0X02bit7=(theApp.myStatusClass.ctr0X02bit7==1?0:1);
	theApp.myStatusClass.ad_button_onoff(GetSafeHwnd());
	theApp.myStatusClass.download_inksystem_control02();
}
