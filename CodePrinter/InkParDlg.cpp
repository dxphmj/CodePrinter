// InkParDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "InkParDlg.h"
#include "CodePrinterDlg.h"


// CInkParDlg �Ի���

IMPLEMENT_DYNAMIC(CInkParDlg, CDialog)

CInkParDlg::CInkParDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInkParDlg::IDD, pParent)
	, m_parPressure(0)
	, m_parPumpSpeed(0)
	, m_inkFlowLev(0)
	, m_inkAddLev(0)
	, m_inkEmptyLev(0)
	, m_printheadTemp(0)
	, m_viscoDevia(0)
	, m_solventFlowLev(0)
	, m_solAddLev(0)
	, m_solEmptyLev(0)
{

}

CInkParDlg::~CInkParDlg()
{
}

void CInkParDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PAR_PRESSURE_EDIT, m_parPressure);
	DDX_Text(pDX, IDC_PAR_PUMP_SPEED_EDIT, m_parPumpSpeed);
	DDX_Text(pDX, IDC_INK_FLOW_LEV_EDIT, m_inkFlowLev);
	DDX_Text(pDX, IDC_INK_ADD_LEV_EDIT, m_inkAddLev);
	DDX_Text(pDX, IDC_INK_EMPTY_LEV_EDIT, m_inkEmptyLev);
	DDX_Text(pDX, IDC_PRINTHEAD_TEMP_EDIT, m_printheadTemp);
	DDX_Text(pDX, IDC_VISCO_DEVIA_EDIT, m_viscoDevia);
	DDX_Text(pDX, IDC_SOLVENT_FLOW_LEV_EDIT, m_solventFlowLev);
	DDX_Text(pDX, IDC_SOL_ADD_LEV_EDIT, m_solAddLev);
	DDX_Text(pDX, IDC_SOL_EMPTY_LEV_EDIT, m_solEmptyLev);
	DDX_Control(pDX, IDC_PAR_PRESSURE_EDIT, m_edit_parPressure);
	DDX_Control(pDX, IDC_PRINTHEAD_TEMP_EDIT, m_edit_printheadTemp);
	DDX_Control(pDX, IDC_PAR_PUMP_SPEED_EDIT, m_edit_parPumpSpeed);
	DDX_Control(pDX, IDC_VISCO_DEVIA_EDIT, m_medit_viscoDevia);
	DDX_Control(pDX, IDC_INK_FLOW_LEV_EDIT, m_edit_inkFlowLev);
	DDX_Control(pDX, IDC_SOLVENT_FLOW_LEV_EDIT, m_edit_solventFlowLev);
	DDX_Control(pDX, IDC_INK_ADD_LEV_EDIT, m_edit_inkAddLev);
	DDX_Control(pDX, IDC_SOL_ADD_LEV_EDIT, m_edit_solAddLev);
	DDX_Control(pDX, IDC_INK_EMPTY_LEV_EDIT, m_edit_inkEmptyLev);
	DDX_Control(pDX, IDC_SOL_EMPTY_LEV_EDIT, m_edit_solEmptyLev);
}


BEGIN_MESSAGE_MAP(CInkParDlg, CDialog)

	ON_WM_CTLCOLOR()

	ON_EN_SETFOCUS(IDC_PAR_PRESSURE_EDIT, &CInkParDlg::OnEnSetfocusParPressureEdit)
	ON_EN_SETFOCUS(IDC_PRINTHEAD_TEMP_EDIT, &CInkParDlg::OnEnSetfocusPrintheadTempEdit)
	ON_WM_PAINT()
	ON_EN_SETFOCUS(IDC_PAR_PUMP_SPEED_EDIT, &CInkParDlg::OnEnSetfocusParPumpSpeedEdit)
	ON_EN_SETFOCUS(IDC_VISCO_DEVIA_EDIT, &CInkParDlg::OnEnSetfocusViscoDeviaEdit)
	ON_EN_SETFOCUS(IDC_INK_FLOW_LEV_EDIT, &CInkParDlg::OnEnSetfocusInkFlowLevEdit)
	ON_EN_SETFOCUS(IDC_SOLVENT_FLOW_LEV_EDIT, &CInkParDlg::OnEnSetfocusSolventFlowLevEdit)
	ON_EN_SETFOCUS(IDC_INK_ADD_LEV_EDIT, &CInkParDlg::OnEnSetfocusInkAddLevEdit)
	ON_EN_SETFOCUS(IDC_SOL_ADD_LEV_EDIT, &CInkParDlg::OnEnSetfocusSolAddLevEdit)
	ON_EN_SETFOCUS(IDC_INK_EMPTY_LEV_EDIT, &CInkParDlg::OnEnSetfocusInkEmptyLevEdit)
	ON_EN_SETFOCUS(IDC_SOL_EMPTY_LEV_EDIT, &CInkParDlg::OnEnSetfocusSolEmptyLevEdit)
END_MESSAGE_MAP()


// CInkParDlg ��Ϣ�������


HBRUSH CInkParDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));	
		return theApp.m_StaticBrush;
	} 


	// TODO:  �ڴ˸��� DC ���κ�����
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return theApp.m_DlgBrush;
}

BOOL CInkParDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_edit_parPressure.SetFont(theApp.m_EditFont);

	m_edit_parPumpSpeed.SetFont(theApp.m_EditFont);
	m_medit_viscoDevia.SetFont(theApp.m_EditFont);
	m_edit_inkFlowLev.SetFont(theApp.m_EditFont);
	m_edit_solventFlowLev.SetFont(theApp.m_EditFont);
	m_edit_inkAddLev.SetFont(theApp.m_EditFont);
	m_edit_solAddLev.SetFont(theApp.m_EditFont);
	m_edit_inkEmptyLev.SetFont(theApp.m_EditFont);
	m_edit_solEmptyLev.SetFont(theApp.m_EditFont);
	m_edit_printheadTemp.SetFont(theApp.m_EditFont);

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//////////////////////////////////////////////////////////////////////////
	GetDlgItem(IDC_SOL_EMPTY_LEV_STATIC)->SetFocus();
	return FALSE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CInkParDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()

//	this->SetFocus();

}

void CInkParDlg::OnEnSetfocusParPressureEdit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CEdit *pEdit = &m_edit_parPressure;

	CCodePrinterDlg* dlg;
	dlg = (CCodePrinterDlg*)(GetParent()->GetParent());
	dlg->OpenNumKeyBoard(pEdit);

}

void CInkParDlg::OnEnSetfocusPrintheadTempEdit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CEdit *pEdit = &m_edit_printheadTemp;

	CCodePrinterDlg* dlg;
	dlg = (CCodePrinterDlg*)(GetParent()->GetParent());
	dlg->OpenNumKeyBoard(pEdit);
}

void CInkParDlg::OnEnSetfocusParPumpSpeedEdit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CEdit *pEdit = &m_edit_parPumpSpeed;

	CCodePrinterDlg* dlg;
	dlg = (CCodePrinterDlg*)(GetParent()->GetParent());
	dlg->OpenNumKeyBoard(pEdit);
}

void CInkParDlg::OnEnSetfocusViscoDeviaEdit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CEdit *pEdit = &m_medit_viscoDevia;

	CCodePrinterDlg* dlg;
	dlg = (CCodePrinterDlg*)(GetParent()->GetParent());
	dlg->OpenNumKeyBoard(pEdit);
}

void CInkParDlg::OnEnSetfocusInkFlowLevEdit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CEdit *pEdit = &m_edit_inkFlowLev;

	CCodePrinterDlg* dlg;
	dlg = (CCodePrinterDlg*)(GetParent()->GetParent());
	dlg->OpenNumKeyBoard(pEdit);
}

void CInkParDlg::OnEnSetfocusSolventFlowLevEdit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CEdit *pEdit = &m_edit_solventFlowLev;

	CCodePrinterDlg* dlg;
	dlg = (CCodePrinterDlg*)(GetParent()->GetParent());
	dlg->OpenNumKeyBoard(pEdit);
}

void CInkParDlg::OnEnSetfocusInkAddLevEdit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CEdit *pEdit = &m_edit_inkAddLev;

	CCodePrinterDlg* dlg;
	dlg = (CCodePrinterDlg*)(GetParent()->GetParent());
	dlg->OpenNumKeyBoard(pEdit);
}

void CInkParDlg::OnEnSetfocusSolAddLevEdit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CEdit *pEdit = &m_edit_solAddLev;

	CCodePrinterDlg* dlg;
	dlg = (CCodePrinterDlg*)(GetParent()->GetParent());
	dlg->OpenNumKeyBoard(pEdit);
}

void CInkParDlg::OnEnSetfocusInkEmptyLevEdit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CEdit *pEdit = &m_edit_inkEmptyLev;

	CCodePrinterDlg* dlg;
	dlg = (CCodePrinterDlg*)(GetParent()->GetParent());
	dlg->OpenNumKeyBoard(pEdit);
}

void CInkParDlg::OnEnSetfocusSolEmptyLevEdit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CEdit *pEdit = &m_edit_solEmptyLev;

	CCodePrinterDlg* dlg;
	dlg = (CCodePrinterDlg*)(GetParent()->GetParent());
	dlg->OpenNumKeyBoard(pEdit);
}
