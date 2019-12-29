// UserFreshDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "UserFreshDlg.h"


// CUserFreshDlg 对话框

IMPLEMENT_DYNAMIC(CUserFreshDlg, CDialog)

CUserFreshDlg::CUserFreshDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserFreshDlg::IDD, pParent)
{

}

CUserFreshDlg::~CUserFreshDlg()
{
}

void CUserFreshDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUserFreshDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CUserFreshDlg::OnBnClickedButtonClose)
	ON_BN_CLICKED(IDC_BUTTON_OK, &CUserFreshDlg::OnBnClickedButtonOk)
END_MESSAGE_MAP()


// CUserFreshDlg 消息处理程序

void CUserFreshDlg::OnBnClickedButtonClose()
{
	// TODO: 在此添加控件通知处理程序代码
	ShowWindow(SW_HIDE);
}

void CUserFreshDlg::OnBnClickedButtonOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CListBox* m_freshBox=(CListBox*)GetDlgItem(IDC_FRESH_USER_NAME_LIST);
	CString passKey;
	GetDlgItem(IDC_FRESH_PASSWARD_EDIT)->GetWindowText(passKey);
	CString changeUser;
	m_freshBox->GetText(m_freshBox->GetCurSel(),changeUser);
	map<string,UserStruct>::iterator findIter=theApp.myUserPower.userMap.find(theApp.myModuleMain.CString2string(changeUser));
	if (findIter!=theApp.myUserPower.userMap.end())
	{
		if (theApp.myModuleMain.CString2string(passKey)==findIter->second.userKey)
		{
			theApp.myModuleMain.changeXml("SoftSystem.xml","User",theApp.myModuleMain.CString2string(changeUser),"Storage Card\\System");
			theApp.myUserPower.nowUser=findIter->second;
			GetParent()->GetDlgItem(IDC_EDIT_NOWUSER)->SetWindowText(changeUser);
			CListBox* m_allBox=(CListBox*)GetParent()->GetDlgItem(IDC_LIST_ALLUSER);
			m_allBox->SelectString(0,changeUser);
			theApp.myUserPower.changeUserPower();
		} 
		else
		{
			CString csMsg ;
			csMsg.Format(_T("密码错误！\n请重新输入%s的密码"),changeUser);
			AfxMessageBox(csMsg);
			return;
		}
	} 
	else
	{
		if (theApp.myModuleMain.CString2string(changeUser)=="root")
		{
			if (theApp.myModuleMain.CString2string(passKey)==theApp.myUserPower.GetRootPass())
			{
				theApp.myModuleMain.changeXml("SoftSystem.xml","User","root","Storage Card\\System");
				theApp.myUserPower.nowUser.userName="root";
				theApp.myUserPower.nowUser.userKey=theApp.myUserPower.GetRootPass();
				theApp.myUserPower.nowUser.userLevel=0;
				theApp.myUserPower.nowUser.fatherName="";
				GetParent()->GetDlgItem(IDC_EDIT_NOWUSER)->SetWindowText(changeUser);
				CListBox* m_allBox=(CListBox*)GetParent()->GetDlgItem(IDC_LIST_ALLUSER);
				m_allBox->SelectString(0,changeUser);
				theApp.myUserPower.changeUserPower();
			} 
			else
			{
				CString csMsg=_T("密码错误！\n请重新输入root的密码");
				//csMsg.Format(_T("密码错误！\n请重新输入%s的密码"));
				AfxMessageBox(csMsg);
				return;
			}
		} 
		else
		{
			CString csMsg=_T("未知错误！\n请联系管理员");
			//csMsg.Format(_T("密码错误！\n请重新输入%s的密码"));
			AfxMessageBox(csMsg);
			return;
		}
	}
	ShowWindow(SW_HIDE);
}
