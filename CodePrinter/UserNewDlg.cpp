// UserNewDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "UserNewDlg.h"


// CUserNewDlg �Ի���

IMPLEMENT_DYNAMIC(CUserNewDlg, CDialog)

CUserNewDlg::CUserNewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserNewDlg::IDD, pParent)
{

}

CUserNewDlg::~CUserNewDlg()
{
}

void CUserNewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUserNewDlg, CDialog)

	ON_BN_CLICKED(IDC_BUTTON1, &CUserNewDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RIGHT_MOVE_BTN, &CUserNewDlg::OnBnClickedRightMoveBtn)
	ON_BN_CLICKED(IDC_LEFT_MOVE_BTN, &CUserNewDlg::OnBnClickedLeftMoveBtn)
	ON_BN_CLICKED(IDC_BUTTON_OK, &CUserNewDlg::OnBnClickedButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CUserNewDlg::OnBnClickedButtonClose)

	ON_WM_CTLCOLOR()

END_MESSAGE_MAP()


// CUserNewDlg ��Ϣ�������


void CUserNewDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShowWindow(SW_HIDE);
}

void CUserNewDlg::OnBnClickedRightMoveBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

void CUserNewDlg::OnBnClickedLeftMoveBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

void CUserNewDlg::OnBnClickedButtonOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CListBox* m_grantedBox=(CListBox*)GetDlgItem(IDC_GRANTED_LIST);
	vector<string> tempStrVec;
	for (int i=0;i<m_grantedBox->GetCount();i++)
	{
		CString strSelect;
		m_grantedBox->GetText(i,strSelect);
		string strStr=theApp.myModuleMain.CString2string(strSelect);
		tempStrVec.push_back(strStr);
	}

	CString userName;
	GetDlgItem(IDC_USER_NAME_EDIT)->GetWindowText(userName);
	if (userName.IsEmpty())
	{
		CString csMsg = _T("�û�������Ϊ�գ�");
		AfxMessageBox(csMsg);
		return;
	}

	CString userKey;
	GetDlgItem(IDC_PASSWARD_EDIT)->GetWindowText(userKey);
	if (userKey.IsEmpty())
	{
		CString csMsg = _T("���벻��Ϊ�գ�");
		AfxMessageBox(csMsg);
		return;
	}

	string pathName="Storage Card\\System\\UserPower\\"+theApp.myModuleMain.CString2string(userName)+".txt";
	theApp.myUserPower.SavePower(pathName,tempStrVec);

	CListBox* m_AllBox=(CListBox*)GetParent()->GetDlgItem(IDC_LIST_ALLUSER);
	m_AllBox->AddString(userName);
	
	map<string,UserStruct>::iterator mapIter=theApp.myUserPower.userMap.find(theApp.myModuleMain.CString2string(userName));
	if (mapIter!=theApp.myUserPower.userMap.end())
	{
		theApp.myUserPower.userMap.erase(mapIter);
	} 
	UserStruct tempUTT;
	tempUTT.userName=theApp.myModuleMain.CString2string(userName);
	tempUTT.userKey=theApp.myModuleMain.CString2string(userKey);
	tempUTT.fatherName=theApp.myUserPower.nowUser.userName;
	if (theApp.myUserPower.nowUser.userName=="root")
	{
		tempUTT.userLevel=1;
	} 
	else
	{
		tempUTT.userLevel=theApp.myUserPower.nowUser.userLevel+1;
	}
	
	theApp.myUserPower.userMap.insert(make_pair(theApp.myModuleMain.CString2string(userName),tempUTT));
	
	theApp.myUserPower.SaveUser();

	ShowWindow(SW_HIDE);
}

void CUserNewDlg::OnBnClickedButtonClose()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShowWindow(SW_HIDE);
}

HBRUSH CUserNewDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return theApp.m_DlgBrush;
}

