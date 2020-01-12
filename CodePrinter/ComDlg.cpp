// ComDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "ComDlg.h"
#include <string>


// CComDlg 对话框

IMPLEMENT_DYNAMIC(CComDlg, CDialog)

CComDlg::CComDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CComDlg::IDD, pParent)
{

}

CComDlg::~CComDlg()
{
}

void CComDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COM1_BAUDRATE_LIST, m_com1BaudRate);
	DDX_Control(pDX, IDC_COM2_BAUDRATE_LIST, m_com2Baudrate);
	DDX_Control(pDX, IDC_COM1_PARITY_LIST, m_com1Parity);
	DDX_Control(pDX, IDC_COM2_PARITY_LIST, m_com2Parity);
}


BEGIN_MESSAGE_MAP(CComDlg, CDialog)
	ON_WM_CTLCOLOR()

END_MESSAGE_MAP()


// CComDlg 消息处理程序

BOOL CComDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_com1BaudRate.AddString(L"9600");
	m_com1BaudRate.AddString(L"14400");
	m_com1BaudRate.AddString(L"19200");
	m_com1BaudRate.AddString(L"38400");
	m_com1BaudRate.AddString(L"56000");
	m_com1BaudRate.AddString(L"57600");
	m_com1BaudRate.AddString(L"115200");
	m_com1BaudRate.AddString(L"128000");
	m_com1BaudRate.AddString(L"256000");

	m_com2Baudrate.AddString(L"9600");
	m_com2Baudrate.AddString(L"14400");
	m_com2Baudrate.AddString(L"19200");
	m_com2Baudrate.AddString(L"38400");
	m_com2Baudrate.AddString(L"56000");
	m_com2Baudrate.AddString(L"57600");
	m_com2Baudrate.AddString(L"115200");
	m_com2Baudrate.AddString(L"128000");
	m_com2Baudrate.AddString(L"256000");

	m_com1Parity.AddString(L"none");
	m_com1Parity.AddString(L"odd");
	m_com1Parity.AddString(L"even");
	m_com1Parity.AddString(L"mark");
	m_com1Parity.AddString(L"space");

	m_com2Parity.AddString(L"none");
	m_com2Parity.AddString(L"odd");
	m_com2Parity.AddString(L"even");
	m_com2Parity.AddString(L"mark");
	m_com2Parity.AddString(L"space");

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


HBRUSH CComDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
	// TODO:  在此更改 DC 的任何属性
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return theApp.m_DlgBrush;
}
