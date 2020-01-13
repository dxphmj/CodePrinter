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
}


BEGIN_MESSAGE_MAP(CResetSerial, CDialog)
	ON_BN_CLICKED(IDC_RESET_SERIAL_RETURN_BTN, &CResetSerial::OnBnClickedResetSerialReturnBtn)
END_MESSAGE_MAP()


// CResetSerial 消息处理程序

BOOL CResetSerial::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CResetSerial::OnBnClickedResetSerialReturnBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
}
