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
	DDX_Control(pDX, IDC_INK_CLOSE_BTN, m_CIB_InkCir);
	DDX_Control(pDX, IDC_INKFLOW_OFF_BTN, m_CIB_InkflowOff);
	DDX_Control(pDX, IDC_ADJUST_INKLINE_BTN, m_CIB_AdjustInkline);
	DDX_Control(pDX, IDC_ADD_SOLVENT_BTN, m_CIB_AddSolvent);
	DDX_Control(pDX, IDC_SUCK_NOZZLE_BTN, m_CIB_SuckNozzle);
	DDX_Control(pDX, IDC_HIGH_VOLTAGE_BTN, m_CIB_HighVoltage);
	DDX_Control(pDX, IDC_WASH_NOZZLE_BTN, m_CIB_WashNozzle);
	DDX_Control(pDX, IDC_CLOSE_INKLINE_BTN, m_CIB_CloseInkline);
	DDX_Control(pDX, IDC_BETECT_VISCO_BTN, m_CIB_BetectVisco);
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
	//��ɫ��ť ����ͨ��
	m_CIB_InkCir.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
	m_CIB_InkCir.SizeToContent(); 
	m_CIB_InkflowOff.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
	m_CIB_InkflowOff.SizeToContent(); 
	m_CIB_AdjustInkline.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
	m_CIB_AdjustInkline.SizeToContent(); 
	m_CIB_AddSolvent.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
	m_CIB_AddSolvent.SizeToContent(); 
	m_CIB_SuckNozzle.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
	m_CIB_SuckNozzle.SizeToContent(); 
	m_CIB_HighVoltage.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
	m_CIB_HighVoltage.SizeToContent(); 
	m_CIB_WashNozzle.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
	m_CIB_WashNozzle.SizeToContent(); 
	m_CIB_CloseInkline.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
	m_CIB_CloseInkline.SizeToContent(); 
	m_CIB_BetectVisco.LoadBitmaps(IDB_OFF_BITMAP,IDB_OFF_BITMAP,0,0,IDB_OFF_BITMAP);
	m_CIB_BetectVisco.SizeToContent(); 

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
