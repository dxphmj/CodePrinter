// UserOpenDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "UserOpenDlg.h"


// CUserOpenDlg 对话框

IMPLEMENT_DYNAMIC(CUserOpenDlg, CDialog)

CUserOpenDlg::CUserOpenDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserOpenDlg::IDD, pParent)
{

}

CUserOpenDlg::~CUserOpenDlg()
{
}

void CUserOpenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NOT_GRANTED_LIST, m_notGranted);
	DDX_Control(pDX, IDC_GRANTED_LIST, m_granted);
}


BEGIN_MESSAGE_MAP(CUserOpenDlg, CDialog)

	ON_BN_CLICKED(IDC_RIGHT_MOVE_BTN, &CUserOpenDlg::OnBnClickedRightMoveBtn)
	ON_BN_CLICKED(IDC_LEFT_MOVE_BTN, &CUserOpenDlg::OnBnClickedLeftMoveBtn)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CUserOpenDlg::OnBnClickedButtonClose)
	ON_BN_CLICKED(IDC_BUTTON_OK, &CUserOpenDlg::OnBnClickedButtonOk)

	ON_WM_CTLCOLOR()

END_MESSAGE_MAP()


// CUserOpenDlg 消息处理程序

BOOL CUserOpenDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_notGranted.AddString(L"Set Productcounter");

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CUserOpenDlg::OnBnClickedRightMoveBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	CListBox* m_notBox=(CListBox*)GetDlgItem(IDC_NOT_GRANTED_LIST);
	CListBox* m_grantedBox=(CListBox*)GetDlgItem(IDC_GRANTED_LIST);
	if (m_notBox->GetCount()==0)
	{
		return;
	}
	int intPower=m_notBox->GetCurSel();
	int nextPower=intPower+1;
	if (nextPower<m_notBox->GetCount())
	{
		m_notBox->SetCurSel(nextPower);
	}
	else if ((nextPower-2)>=0)
	{
		m_notBox->SetCurSel(nextPower-2);
	}
	CString strPower;
	m_notBox->GetText(intPower,strPower);
	m_notBox->DeleteString(intPower);

	intPower=m_grantedBox->AddString(strPower);
	m_grantedBox->SetCurSel(intPower);
}

void CUserOpenDlg::OnBnClickedLeftMoveBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	CListBox* m_notBox=(CListBox*)GetDlgItem(IDC_NOT_GRANTED_LIST);
	CListBox* m_grantedBox=(CListBox*)GetDlgItem(IDC_GRANTED_LIST);
	if (m_grantedBox->GetCount()==0)
	{
		return;
	}
	int intPower=m_grantedBox->GetCurSel();
	int nextPower=intPower+1;
	if (nextPower<m_grantedBox->GetCount())
	{
		m_grantedBox->SetCurSel(nextPower);
	}
	else if ((nextPower-2)>=0)
	{
		m_grantedBox->SetCurSel(nextPower-2);
	}
	CString strPower;
	m_grantedBox->GetText(intPower,strPower);
	m_grantedBox->DeleteString(intPower);

	intPower=m_notBox->AddString(strPower);
	m_notBox->SetCurSel(intPower);
}

void CUserOpenDlg::OnBnClickedButtonClose()
{
	// TODO: 在此添加控件通知处理程序代码
	ShowWindow(SW_HIDE);
}

void CUserOpenDlg::OnBnClickedButtonOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString csKEY;
	GetDlgItem(IDC_PASSWARD_EDIT)->GetWindowText(csKEY);
	string passKey=theApp.myModuleMain.CString2string(csKEY);
	if (passKey==theApp.myUserPower.nowUser.userKey)
	{
		CListBox* m_grantedBox=(CListBox*)GetDlgItem(IDC_GRANTED_LIST);
		vector<string> tempStrVec;
		for (int i=0;i<m_grantedBox->GetCount();i++)
		{
			CString strSelect;
			m_grantedBox->GetText(i,strSelect);
			string strStr=theApp.myModuleMain.CString2string(strSelect);
			tempStrVec.push_back(strStr);
		}
		string pathName="Storage Card\\System\\UserPower\\"+theApp.myUserPower.nowUser.userName+".txt";
		theApp.myUserPower.SavePower(pathName,tempStrVec);
		theApp.myUserPower.changeUserPower();
	} 
	else
	{
		CString csMsg ;
		csMsg.Format(_T("密码错误!\n请输入%s的密码"),theApp.myModuleMain.string2CString(theApp.myUserPower.nowUser.userName));
		AfxMessageBox(csMsg);
		return;
	}

	ShowWindow(SW_HIDE);
}

HBRUSH CUserOpenDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return theApp.m_DlgBrush;
}

