// InkParDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "InkParDlg.h"


// CInkParDlg 对话框

IMPLEMENT_DYNAMIC(CInkParDlg, CDialog)

CInkParDlg::CInkParDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInkParDlg::IDD, pParent)
	, m_parPressure(3000)
	, m_parPumpSpeed(2000)
	, m_inkFlowLev(100)
	, m_inkAddLev(30)
	, m_inkEmptyLev(10)
	, m_printheadTemp(24)
	, m_viscoDevia(20)
	, m_solventFlowLev(100)
	, m_solAddLev(50)
	, m_solEmptyLev(10)
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

BOOL CInkParDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
