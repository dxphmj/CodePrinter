// ResetSerial.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "ResetSerial.h"


// CResetSerial 对话框

IMPLEMENT_DYNAMIC(CResetSerial, CDialog)

CResetSerial::CResetSerial(CWnd* pParent /*=NULL*/)
	: CDialog(CResetSerial::IDD, pParent)
{

}

CResetSerial::~CResetSerial()
{
}

void CResetSerial::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RESET_SERIAL_RETURN_BTN, m_returnIB);
}


BEGIN_MESSAGE_MAP(CResetSerial, CDialog)
	ON_BN_CLICKED(IDC_RESET_SERIAL_RETURN_BTN, &CResetSerial::OnBnClickedResetSerialReturnBtn)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CResetSerial 消息处理程序

BOOL CResetSerial::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_returnIB.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RETURN1_BITMAP);
	m_returnIB.SizeToContent(); 

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CResetSerial::OnBnClickedResetSerialReturnBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
}

HBRUSH CResetSerial::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性

	if(nCtlColor == CTLCOLOR_STATIC)
	{		 
		pDC->SelectObject(theApp.m_StaticFont);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));	
	}

	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return theApp.m_DlgBrush;	 
}
