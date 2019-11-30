// CodePrinterDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "CodePrinterDlg.h"
#include "LabelDlg.h"
#include "FaultDlg.h"
#include "SystemDlg.h"
#include "UserDlg.h"
#include "ConfigurationDlg.h"
#include "FileManaDlg.h"
#include "InkSystemDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCodePrinterDlg �Ի���

CCodePrinterDlg::CCodePrinterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCodePrinterDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCodePrinterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FAULT_BUTTON, m_ButFault);
	DDX_Control(pDX, IDC_RESET_COUNT_BTN, m_ButRestCount);
}

BEGIN_MESSAGE_MAP(CCodePrinterDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_LABEL_BUTTON, &CCodePrinterDlg::OnBnClickedLabelButton)
	ON_BN_CLICKED(IDC_FAULT_BUTTON, &CCodePrinterDlg::OnBnClickedFaultButton)
	ON_BN_CLICKED(IDC_SYSTEM_BUTTON, &CCodePrinterDlg::OnBnClickedSystemButton)
	ON_BN_CLICKED(IDC_USER_BUTTON, &CCodePrinterDlg::OnBnClickedUserButton)
	ON_BN_CLICKED(IDC_CONFIGURATION_BUTTON, &CCodePrinterDlg::OnBnClickedConfigurationButton)
	ON_BN_CLICKED(IDC_FILEMANA_BUTTON, &CCodePrinterDlg::OnBnClickedFilemanaButton)
	ON_BN_CLICKED(IDC_INK_BUTTON, &CCodePrinterDlg::OnBnClickedInkButton)
END_MESSAGE_MAP()


// CCodePrinterDlg ��Ϣ�������

BOOL CCodePrinterDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	SetWindowPos(NULL,0,0,800,600,SWP_SHOWWINDOW );	
	CRect rect;
	GetWindowRect(&rect);

	m_ButFault.LoadBitmaps(IDB_BITMAP1,IDB_BITMAP2,0,0,IDB_BITMAP3);
	m_ButFault.SizeToContent(); 
	m_ButRestCount.LoadBitmaps(IDB_BITMAP1,IDB_BITMAP2,0,0,IDB_BITMAP3);
	m_ButRestCount.SizeToContent(); 
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CCodePrinterDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_CODEPRINTER_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_CODEPRINTER_DIALOG));
	}
}
#endif

void CCodePrinterDlg::OnBnClickedLabelButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CLabelDlg Label;
	Label.DoModal();
}

void CCodePrinterDlg::OnBnClickedFaultButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFaultDlg Fault;
	Fault.DoModal();
}

void CCodePrinterDlg::OnBnClickedSystemButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CSystemDlg System;
	System.DoModal();
}

void CCodePrinterDlg::OnBnClickedUserButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CUserDlg User;
	User.DoModal();
}

void CCodePrinterDlg::OnBnClickedConfigurationButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CConfigurationDlg Configuration;
	Configuration.DoModal();
}

void CCodePrinterDlg::OnBnClickedFilemanaButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileManaDlg FileMana;
	FileMana.DoModal();
}

void CCodePrinterDlg::OnBnClickedInkButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CInkSystemDlg InkSystem;
	InkSystem.DoModal();
}
