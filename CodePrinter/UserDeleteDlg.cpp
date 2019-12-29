// UserDeleteDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "UserDeleteDlg.h"


// CUserDeleteDlg �Ի���

IMPLEMENT_DYNAMIC(CUserDeleteDlg, CDialog)

CUserDeleteDlg::CUserDeleteDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserDeleteDlg::IDD, pParent)
{

}

CUserDeleteDlg::~CUserDeleteDlg()
{
}

void CUserDeleteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUserDeleteDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CUserDeleteDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CUserDeleteDlg::OnBnClickedButtonClose)
	ON_BN_CLICKED(IDC_BUTTON_OK, &CUserDeleteDlg::OnBnClickedButtonOk)
END_MESSAGE_MAP()


// CUserDeleteDlg ��Ϣ�������

void CUserDeleteDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CUserDeleteDlg::OnBnClickedButtonClose()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShowWindow(SW_HIDE);
}

void CUserDeleteDlg::OnBnClickedButtonOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CListBox* m_allUserBox=(CListBox*)GetParent()->GetDlgItem(IDC_LIST_ALLUSER);
	CString deletUser;
	int detInt=m_allUserBox->GetCurSel();
	m_allUserBox->GetText(detInt,deletUser);
	if (detInt<m_allUserBox->GetCount()-1)
	{
		m_allUserBox->SetCurSel(detInt+1);
	} 
	else if (detInt>0)
	{
		m_allUserBox->SetCurSel(detInt-1);
	}

	map<string,UserStruct>::iterator findIter=theApp.myUserPower.userMap.find(theApp.myModuleMain.CString2string(deletUser));
	if (findIter!=theApp.myUserPower.userMap.end())
	{
		UserStruct deleteUT=findIter->second;
		if (deleteUT.userLevel>theApp.myUserPower.nowUser.userLevel)
		{
			theApp.myUserPower.userMap.erase(findIter);
			string deletePathName="Storage Card\\System\\UserPower\\"+deleteUT.userName+".txt";
			DeleteFile(theApp.myModuleMain.stringToLPCWSTR(deletePathName));
			theApp.myUserPower.SaveUser();
			m_allUserBox->DeleteString(detInt);
		} 
		else
		{
			CString csMsg ;
			csMsg.Format(_T("Ȩ�޲���!\n����Ȩɾ��%s"),theApp.myModuleMain.string2CString(deleteUT.userName));
			AfxMessageBox(csMsg);
			return;
		}
	} 
	else
	{
		//m_allUserBox->DeleteString(detInt);
		if (theApp.myModuleMain.CString2string(deletUser)=="root")
		{
			CString csMsg = _T("�޷�ɾ�� root ��");
			AfxMessageBox(csMsg);
			return;
		} 
		else
		{
			m_allUserBox->DeleteString(detInt);
		}
	}
	ShowWindow(SW_HIDE);
}
