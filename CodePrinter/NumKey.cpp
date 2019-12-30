// NumKey.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "NumKey.h"


// CNumKey 对话框

IMPLEMENT_DYNAMIC(CNumKey, CDialog)

CNumKey::CNumKey(CWnd* pParent /*=NULL*/)
	: CDialog(CNumKey::IDD, pParent)
{

}

CNumKey::~CNumKey()
{
}

void CNumKey::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CNumKey, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_KEY7, &CNumKey::OnBnClickedButtonKey7)
	ON_BN_CLICKED(IDC_BUTTON_KEY_ESC, &CNumKey::OnBnClickedButtonKeyEsc)
	ON_BN_CLICKED(IDC_BUTTON_KEY8, &CNumKey::OnBnClickedButtonKey8)
END_MESSAGE_MAP()


// CNumKey 消息处理程序

BOOL CNumKey::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CRect rtClient;
	GetWindowRect(rtClient);  
	::SetWindowPos(m_hWnd, HWND_TOPMOST, rtClient.left, rtClient.top, rtClient.Width(), rtClient.Height(), SWP_SHOWWINDOW);

	//SetWindowPos(&CWnd::wndTopMost,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
	//SetWindowPos(NULL,0,284,800,316,SWP_SHOWWINDOW );
	bool isShow = false;
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CNumKey::OnBnClickedButtonKey7()
{
	// TODO: 在此添加控件通知处理程序代码
	CString tempstr;
	GetDlgItem(IDC_BUTTON_KEY7)->GetWindowText(tempstr);
	//m_curNum = _wtoi(tempstr.GetBuffer(0));
	setEditNum( tempstr );
}

void CNumKey::setEditNum( CString Numstr )
{
	int nPosStart;
	int nPosEnd  = 0;
	CEdit* pEdit = (CEdit*)GetDlgItem(m_EditId);
	pEdit->GetSel(nPosStart, nPosEnd); 
	pEdit->SetSel(nPosStart, nPosStart); 
	pEdit->ReplaceSel(Numstr);
}

void CNumKey::getNumFromEdit(int num,int ID)
{
	
	if ( !isShow )
	{
		this->ShowWindow(SW_SHOW);
		isShow = true;
	}
	m_curNum = num;
	m_EditId = ID;
}

void CNumKey::OnBnClickedButtonKeyEsc()
{
	this->ShowWindow(SW_HIDE);
	isShow = false;
	// TODO: 在此添加控件通知处理程序代码
}

void CNumKey::OnBnClickedButtonKey8()
{
	// TODO: 在此添加控件通知处理程序代码
	CString tempstr;
	GetDlgItem(IDC_BUTTON_KEY7)->GetWindowText(tempstr);
	//m_curNum = _wtoi(tempstr.GetBuffer(0));
	setEditNum( tempstr );
}
