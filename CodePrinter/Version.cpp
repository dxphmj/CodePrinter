// Version.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "Version.h"


// CVersion 对话框

IMPLEMENT_DYNAMIC(CVersion, CDialog)

CVersion::CVersion(CWnd* pParent /*=NULL*/)
	: CDialog(CVersion::IDD, pParent)
{

}

CVersion::~CVersion()
{
}

void CVersion::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CVersion, CDialog)
END_MESSAGE_MAP()


// CVersion 消息处理程序

BOOL CVersion::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
