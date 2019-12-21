// InkParDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "InkParDlg.h"


// CInkParDlg 对话框

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
}


BEGIN_MESSAGE_MAP(CInkParDlg, CDialog)
END_MESSAGE_MAP()


// CInkParDlg 消息处理程序
