// PictureDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "PictureDlg.h"


// CPictureDlg 对话框

IMPLEMENT_DYNAMIC(CPictureDlg, CDialog)

CPictureDlg::CPictureDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPictureDlg::IDD, pParent)
{

}

CPictureDlg::~CPictureDlg()
{
}

void CPictureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPictureDlg, CDialog)
	ON_BN_CLICKED(IDC_PICTURE_CLOSE_BUTTON, &CPictureDlg::OnBnClickedPictureCloseButton)
END_MESSAGE_MAP()


// CPictureDlg 消息处理程序

BOOL CPictureDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CPictureDlg::OnBnClickedPictureCloseButton()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
}
