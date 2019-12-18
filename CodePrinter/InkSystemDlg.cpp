// InkSystemDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "InkSystemDlg.h"


// CInkSystemDlg �Ի���

IMPLEMENT_DYNAMIC(CInkSystemDlg, CDialog)

CInkSystemDlg::CInkSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInkSystemDlg::IDD, pParent)
{

}

CInkSystemDlg::~CInkSystemDlg()
{
}

void CInkSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInkSystemDlg, CDialog)
	ON_BN_CLICKED(IDC_ADVANCE_BTN, &CInkSystemDlg::OnBnClickedAdvanceBtn)
	ON_BN_CLICKED(IDC_INK_CLOSE_BTN, &CInkSystemDlg::OnBnClickedInkCloseBtn)
	ON_BN_CLICKED(IDC_USUAL_BTN, &CInkSystemDlg::OnBnClickedUsualBtn)
	ON_BN_CLICKED(IDC_SETUP_BTN, &CInkSystemDlg::OnBnClickedSetupBtn)
	ON_BN_CLICKED(IDC_PARAMETER_BTN, &CInkSystemDlg::OnBnClickedParameterBtn)
	ON_BN_CLICKED(IDC_PHASING_BTN, &CInkSystemDlg::OnBnClickedPhasingBtn)
	ON_BN_CLICKED(IDC_SPEED_MODE_BTN, &CInkSystemDlg::OnBnClickedSpeedModeBtn)
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

	m_inkAdv->Create(IDD_INK_ADVANCE_DIALOG,this);
	m_inkAdv->MoveWindow(300,20,450,400);

	int nX = 0;
	int nY = 0;
	int nWidth = 800;
	int nHeight = 400;
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
	}
	if (ID == IDD_INK_SETUP_DIALOG)
	{
		m_setup->ShowWindow(SW_SHOW);
	}
	if (ID == IDD_INK_PAR_DIALOG)
	{
		m_par->ShowWindow(SW_SHOW);
	}
	if (ID == IDD_INK_PHASING_DIALOG)
	{
		m_phas->ShowWindow(SW_SHOW);
	}
	if (0)
	{
		return;
	}


}
void CInkSystemDlg::OnBnClickedInkCloseBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->ShowWindow(SW_HIDE);
	showInkDlg(0);

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

void CInkSystemDlg::OnBnClickedSpeedModeBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	theApp.myStatusClass.ctr0X00bit2=(theApp.myStatusClass.ctr0X00bit2==1?0:1);
	theApp.myStatusClass.download_inksystem_control00();

}
