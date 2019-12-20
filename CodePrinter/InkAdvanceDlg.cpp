// InkAdvanceDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "InkAdvanceDlg.h"


// CInkAdvanceDlg 对话框

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

//初始化
BOOL CInkAdvanceDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  在此添加额外的初始化2
	//彩色按钮 （普通）
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
	
// CInkAdvanceDlg 消息处理程序
//关回收检测，所有情况下可下发
void CInkAdvanceDlg::OnBnClickedInkflowOffBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.myStatusClass.ctr0X02bit0=(theApp.myStatusClass.ctr0X02bit0==1?0:1);
	theApp.myStatusClass.download_inksystem_control02();
}
//关墨线，所有情况下可下发
void CInkAdvanceDlg::OnBnClickedCloseInklineBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.myStatusClass.ctr0X02bit1=(theApp.myStatusClass.ctr0X02bit1==1?0:1);
	theApp.myStatusClass.download_inksystem_control02();
}
//添加溶剂，所有情况下可下发
void CInkAdvanceDlg::OnBnClickedAddSolventBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.myStatusClass.ctr0X02bit2=(theApp.myStatusClass.ctr0X02bit2==1?0:1);
	theApp.myStatusClass.download_inksystem_control02();
}
//高压开关
void CInkAdvanceDlg::OnBnClickedHighVoltageBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.myStatusClass.ctr0X03bit3=(theApp.myStatusClass.ctr0X03bit3==1?0:1);
	theApp.myStatusClass.ad_button_onoff(GetSafeHwnd());
	theApp.myStatusClass.download_inksystem_control03();
}
//粘度测试
void CInkAdvanceDlg::OnBnClickedBetectViscoBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.myStatusClass.ctr0X02bit3=(theApp.myStatusClass.ctr0X02bit3==1?0:1);
	theApp.myStatusClass.ad_button_onoff(GetSafeHwnd());
	theApp.myStatusClass.download_inksystem_control02();
}
//冲洗喷嘴
void CInkAdvanceDlg::OnBnClickedWashNozzleBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.myStatusClass.ctr0X02bit4=(theApp.myStatusClass.ctr0X02bit4==1?0:1);
	theApp.myStatusClass.ad_button_onoff(GetSafeHwnd());
	theApp.myStatusClass.download_inksystem_control02();
}
//反吸喷嘴
void CInkAdvanceDlg::OnBnClickedSuckNozzleBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.myStatusClass.ctr0X02bit5=(theApp.myStatusClass.ctr0X02bit5==1?0:1);
	theApp.myStatusClass.ad_button_onoff(GetSafeHwnd());
	theApp.myStatusClass.download_inksystem_control02();
}
//墨线校准
void CInkAdvanceDlg::OnBnClickedAdjustInklineBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.myStatusClass.ctr0X02bit6=(theApp.myStatusClass.ctr0X02bit6==1?0:1);
	theApp.myStatusClass.ad_button_onoff(GetSafeHwnd());
	theApp.myStatusClass.download_inksystem_control02();
}
//墨路循环
void CInkAdvanceDlg::OnBnClickedInkCirBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.myStatusClass.ctr0X02bit7=(theApp.myStatusClass.ctr0X02bit7==1?0:1);
	theApp.myStatusClass.ad_button_onoff(GetSafeHwnd());
	theApp.myStatusClass.download_inksystem_control02();
}
