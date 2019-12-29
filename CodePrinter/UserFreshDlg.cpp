// UserFreshDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "UserFreshDlg.h"


// CUserFreshDlg �Ի���

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


// CUserFreshDlg ��Ϣ�������

void CUserFreshDlg::OnBnClickedButtonClose()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShowWindow(SW_HIDE);
}

void CUserFreshDlg::OnBnClickedButtonOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
			csMsg.Format(_T("�������\n����������%s������"),changeUser);
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
				CString csMsg=_T("�������\n����������root������");
				//csMsg.Format(_T("�������\n����������%s������"));
				AfxMessageBox(csMsg);
				return;
			}
		} 
		else
		{
			CString csMsg=_T("δ֪����\n����ϵ����Ա");
			//csMsg.Format(_T("�������\n����������%s������"));
			AfxMessageBox(csMsg);
			return;
		}
	}
	ShowWindow(SW_HIDE);
}
