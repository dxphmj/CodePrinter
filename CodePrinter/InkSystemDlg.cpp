// InkSystemDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "InkSystemDlg.h"
#include "Inksystemconfig.h"
#include "CodePrinterDlg.h"



// CInkSystemDlg �Ի���

IMPLEMENT_DYNAMIC(CInkSystemDlg, CDialog)

CInkSystemDlg::CInkSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInkSystemDlg::IDD, pParent)
	
	, m_Pumpspeed(0)
	, m_InkTemp(0)
	, m_PrintheadTemp(0)
	, m_InkLev(0)
	, m_SolventLev(0)
	, m_TargetVisco(0)
	, m_ActualVisco(0)
	, m_HighVol(0)
	, m_Inkflow("Normal")
{

}

CInkSystemDlg::~CInkSystemDlg()
{
}

void CInkSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_INK_CLOSE_BTN, m_returnIB);
	DDX_Control(pDX, IDC_USUAL_BTN, m_usualIB);
	DDX_Control(pDX, IDC_ADVANCE_BTN, m_advanceIB);
	DDX_Control(pDX, IDC_SETUP_BTN, m_setupIB);
	DDX_Control(pDX, IDC_PARAMETER_BTN, m_parameterIB);
	DDX_Control(pDX, IDC_PHASING_BTN, m_phasingIB);
	DDX_Control(pDX, IDC_INK_OK_BTN, m_okIB);
}


BEGIN_MESSAGE_MAP(CInkSystemDlg, CDialog)
	ON_BN_CLICKED(IDC_ADVANCE_BTN, &CInkSystemDlg::OnBnClickedAdvanceBtn)
	ON_BN_CLICKED(IDC_INK_CLOSE_BTN, &CInkSystemDlg::OnBnClickedInkCloseBtn)
	ON_BN_CLICKED(IDC_USUAL_BTN, &CInkSystemDlg::OnBnClickedUsualBtn)
	ON_BN_CLICKED(IDC_SETUP_BTN, &CInkSystemDlg::OnBnClickedSetupBtn)
	ON_BN_CLICKED(IDC_PARAMETER_BTN, &CInkSystemDlg::OnBnClickedParameterBtn)
	ON_BN_CLICKED(IDC_PHASING_BTN, &CInkSystemDlg::OnBnClickedPhasingBtn)
	ON_EN_CHANGE(IDC_PRESSURE_EDIT, &CInkSystemDlg::OnEnChangePressureEdit)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_SPEED_MODE_BTN, &CInkSystemDlg::OnBnClickedSpeedModeBtn)
	ON_BN_CLICKED(IDC_PRESSURE_MODE_BTN, &CInkSystemDlg::OnBnClickedPressureModeBtn)
	ON_BN_CLICKED(IDC_PUMP_BTN, &CInkSystemDlg::OnBnClickedPumpBtn)
	ON_BN_CLICKED(IDC_BLEED_VALVE_BTN, &CInkSystemDlg::OnBnClickedBleedValveBtn)
	ON_BN_CLICKED(IDC_WASH_VALVE_BTN, &CInkSystemDlg::OnBnClickedWashValveBtn)
	ON_BN_CLICKED(IDC_NOZZLE_VALVE_BTN, &CInkSystemDlg::OnBnClickedNozzleValveBtn)
	ON_BN_CLICKED(IDC_FEED_VALVE_BTN, &CInkSystemDlg::OnBnClickedFeedValveBtn)
	ON_BN_CLICKED(IDC_SOLVENT_VALVE_BTN, &CInkSystemDlg::OnBnClickedSolventValveBtn)
	ON_BN_CLICKED(IDC_VISCO_VALVE_BTN, &CInkSystemDlg::OnBnClickedViscoValveBtn)
	ON_BN_CLICKED(IDC_FLUSH_VALVE_BTN, &CInkSystemDlg::OnBnClickedFlushValveBtn)
	ON_BN_CLICKED(IDC_INK_OK_BTN, &CInkSystemDlg::OnBnClickedInkOkBtn)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CInkSystemDlg ��Ϣ�������

BOOL CInkSystemDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_inkAdv = new CInkAdvanceDlg;
	m_setup = new CInkSetupDlg;
	m_par = new CInkParDlg;
	m_phas = new CInkPhasingDlg;

	int nX = 0;
	int nY = 100;
	int nWidth = 800;
	int nHeight = 500-nY; //������ס�����һ�Ű�ť

	m_inkAdv->Create(IDD_INK_ADVANCE_DIALOG,this);
	m_inkAdv->MoveWindow(nX+300,nY,nWidth,nHeight);

	m_setup->Create(IDD_INK_SETUP_DIALOG,this);
	m_setup->MoveWindow(nX,nY,nWidth,nHeight);

	m_par->Create(IDD_INK_PAR_DIALOG,this);
	m_par->MoveWindow(nX,nY,nWidth,nHeight);
	
	m_phas->Create(IDD_INK_PHASING_DIALOG,this);
	m_phas->MoveWindow(nX,nY,nWidth,nHeight);

	m_inkAdv->ShowWindow(SW_HIDE);
	m_setup->ShowWindow(SW_HIDE);
	m_par->ShowWindow(SW_HIDE);
	m_phas->ShowWindow(SW_HIDE);
    
	GetDlgItem(IDC_SPEED_MODE_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);//����ģʽ
	m_CIB_SpeedMode.Attach(IDC_SPEED_MODE_BTN,this);
	GetDlgItem(IDC_PRESSURE_MODE_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);//ѹ��ģʽ
	m_CIB_PressureMode.Attach(IDC_PRESSURE_MODE_BTN,this);
	GetDlgItem(IDC_PUMP_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);//���ر�
	m_CIB_Pump.Attach(IDC_PUMP_BTN,this);
	GetDlgItem(IDC_NOZZLE_VALVE_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);//��������
	m_CIB_NozzleValve.Attach(IDC_NOZZLE_VALVE_BTN,this);
	GetDlgItem(IDC_FEED_VALVE_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);  //���ع�ī��
	m_CIB_FeedValve.Attach(IDC_FEED_VALVE_BTN,this);
	GetDlgItem(IDC_BLEED_VALVE_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);//����������
	m_CIB_BleedValve.Attach(IDC_BLEED_VALVE_BTN,this);	
	GetDlgItem(IDC_FLUSH_VALVE_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);//������ϴ��
	m_CIB_FlushValve.Attach(IDC_FLUSH_VALVE_BTN,this);
	GetDlgItem(IDC_SOLVENT_VALVE_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);//�����ܼ���
	m_CIB_SolventValve.Attach(IDC_SOLVENT_VALVE_BTN,this);
	GetDlgItem(IDC_VISCO_VALVE_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);//����ճ�ȷ�
	m_CIB_ViscoValve.Attach(IDC_VISCO_VALVE_BTN,this);
	GetDlgItem(IDC_WASH_VALVE_BTN)->ModifyStyle(0,BS_OWNERDRAW,0);//��ϴ
	m_CIB_WashValve.Attach(IDC_WASH_VALVE_BTN,this);

	//CRect rect1;
	//GetDlgItem(IDC_INK_CLOSE_BTN)->GetWindowRect(&rect1);

	//GetDlgItem(IDC_INK_CLOSE_BTN)->SetWindowPos(NULL,11,430,80,55,SWP_SHOWWINDOW);//IDC_SYSTEM_CANCEL_BTN
	//GetDlgItem(IDC_USUAL_BTN)->SetWindowPos(NULL,200,440,80,55,SWP_SHOWWINDOW);
	//GetDlgItem(IDC_ADVANCE_BTN)->SetWindowPos(NULL,300,440,80,55,SWP_SHOWWINDOW);
	//GetDlgItem(IDC_SETUP_BTN)->SetWindowPos(NULL,400,440,80,55,SWP_SHOWWINDOW);
	//GetDlgItem(IDC_PARAMETER_BTN)->SetWindowPos(NULL,500,440,80,55,SWP_SHOWWINDOW);
	//GetDlgItem(IDC_PHASING_BTN)->SetWindowPos(NULL,600,440,80,55,SWP_SHOWWINDOW);
	//GetDlgItem(IDC_INK_OK_BTN)->SetWindowPos(NULL,720,430,80,55,SWP_SHOWWINDOW);

	m_returnIB.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RETURN1_BITMAP);
	m_returnIB.SizeToContent(); 

	//����Ӳ�ɫͼƬ
	m_usualIB.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_80_55_BITMAP,true);
	m_usualIB.SizeToContent(); 
	m_advanceIB.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_80_55_BITMAP,true);
	m_advanceIB.SizeToContent(); 
	m_setupIB.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_80_55_BITMAP,true);
	m_setupIB.SizeToContent(); 
	m_parameterIB.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_80_55_BITMAP,true);
	m_parameterIB.SizeToContent(); 
	m_phasingIB.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_80_55_BITMAP,true);
	m_phasingIB.SizeToContent(); 

	m_okIB.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_OK1_BITMAP);
	m_okIB.SizeToContent(); 

	//���ּ��̳�ʼ��
	//pNumKey = new CNumKey();
	//pNumKey->Create( IDD_DIALOG_NUMKEY,this);  
	//pNumKey->ShowWindow(SW_HIDE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}	     

void CInkSystemDlg::showInkDlg(int ID)
{
	m_inkAdv->ShowWindow(SW_HIDE);
	m_setup->ShowWindow(SW_HIDE);
	m_par->ShowWindow(SW_HIDE);
	m_phas->ShowWindow(SW_HIDE);

	if (ID == IDD_INK_ADVANCE_DIALOG)
	{
		m_inkAdv->ShowWindow(SW_SHOW);
		((CCodePrinterDlg*)GetParent())->m_PicHead.SetOperationString(_T("Ink System > Adv")); 
	}
	else if (ID == IDD_INK_SETUP_DIALOG)
	{
		m_setup->ShowWindow(SW_SHOW);
		((CCodePrinterDlg*)GetParent())->m_PicHead.SetOperationString(_T("Ink System > Setup")); 
	}
	else if (ID == IDD_INK_PAR_DIALOG)
	{
		m_par->ShowWindow(SW_SHOW);
		((CCodePrinterDlg*)GetParent())->m_PicHead.SetOperationString(_T("Ink System > Param"));
	}
	else if (ID == IDD_INK_PHASING_DIALOG)
	{
		m_phas->ShowWindow(SW_SHOW);
		((CCodePrinterDlg*)GetParent())->m_PicHead.SetOperationString(_T("Ink System > Phase")); 
	}	 
}

void CInkSystemDlg::OnBnClickedInkCloseBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->ShowWindow(SW_HIDE);
	showInkDlg(0);
	((CCodePrinterDlg*)GetParent())->m_PicHead.ShowLogo(true); 

}

void CInkSystemDlg::OnBnClickedAdvanceBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	showInkDlg(IDD_INK_ADVANCE_DIALOG);
}


void CInkSystemDlg::OnBnClickedUsualBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	showInkDlg(0);
}

void CInkSystemDlg::OnBnClickedSetupBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	showInkDlg(IDD_INK_SETUP_DIALOG);
}

void CInkSystemDlg::OnBnClickedParameterBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	showInkDlg(IDD_INK_PAR_DIALOG);
}

void CInkSystemDlg::OnBnClickedPhasingBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	showInkDlg(IDD_INK_PHASING_DIALOG);
}


void CInkSystemDlg::OnEnChangePressureEdit()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
   
	//SetDlgItemText(IDC_PRESSURE_EDIT,_T("11"));
}


//����ģʽ
void CInkSystemDlg::OnBnClickedSpeedModeBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.myStatusClass.ctr0X00bit2=(theApp.myStatusClass.ctr0X00bit2==1?0:1);
	theApp.myStatusClass.download_inksystem_control00();
}
//ѹ��ģʽ
void CInkSystemDlg::OnBnClickedPressureModeBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.myStatusClass.ctr0X00bit2 = (theApp.myStatusClass.ctr0X00bit2==1?0:1);
	theApp.myStatusClass.download_inksystem_control00();
}
//��
void CInkSystemDlg::OnBnClickedPumpBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.myStatusClass.ctr0X00bit3 = (theApp.myStatusClass.ctr0X00bit3==1?0:1);
	theApp.myStatusClass.download_inksystem_control00();
}
//������
void CInkSystemDlg::OnBnClickedBleedValveBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.myStatusClass.ctr0X01bit2 = (theApp.myStatusClass.ctr0X01bit2==1?0:1);
	theApp.myStatusClass.download_inksystem_control01();
}
//��ϴ��
void CInkSystemDlg::OnBnClickedWashValveBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.myStatusClass.ctr0X01bit6 = (theApp.myStatusClass.ctr0X01bit6==1?0:1);
	theApp.myStatusClass.download_inksystem_control01();
}
//���췧
void CInkSystemDlg::OnBnClickedNozzleValveBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.myStatusClass.ctr0X01bit0 = (theApp.myStatusClass.ctr0X01bit0==1?0:1);
	theApp.myStatusClass.download_inksystem_control01();
}
//��ī��
void CInkSystemDlg::OnBnClickedFeedValveBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.myStatusClass.ctr0X01bit1 = (theApp.myStatusClass.ctr0X01bit1==1?0:1);
	theApp.myStatusClass.download_inksystem_control01();
}
//�ܼ���
void CInkSystemDlg::OnBnClickedSolventValveBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.myStatusClass.ctr0X01bit4 = (theApp.myStatusClass.ctr0X01bit4==1?0:1);
	theApp.myStatusClass.download_inksystem_control01();
}
//ճ�ȷ�
void CInkSystemDlg::OnBnClickedViscoValveBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.myStatusClass.ctr0X01bit5 = (theApp.myStatusClass.ctr0X01bit5==1?0:1);
	theApp.myStatusClass.download_inksystem_control01();
}
//��ϴ��
void CInkSystemDlg::OnBnClickedFlushValveBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.myStatusClass.ctr0X01bit3 = (theApp.myStatusClass.ctr0X01bit3==1?0:1);
	theApp.myStatusClass.download_inksystem_control01();
}

void CInkSystemDlg::OnBnClickedInkOkBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CInksystemconfig pInksysConfig((CCodePrinterDlg*)(this->GetParent()));
	pInksysConfig.save_inksystem_to_xml();
// 	pInksysConfig.get_inksystem_from_xml();
	pInksysConfig.download_inksystem_setup();
	pInksysConfig.download_inksystem_parameter();
}
 
HBRUSH CInkSystemDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

