// UserDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "UserDlg.h"
#include "UserOpenDlg.h"
#include "UserNewDlg.h"
#include "UserDeleteDlg.h"
#include "UserFreshDlg.h"

// CUserDlg 对话框

IMPLEMENT_DYNAMIC(CUserDlg, CDialog)

CUserDlg::CUserDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserDlg::IDD, pParent)
{

}

CUserDlg::~CUserDlg()
{
}

void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUserDlg, CDialog)
	ON_BN_CLICKED(IDC_OPEN_BTN, &CUserDlg::OnBnClickedOpenButton)
	ON_BN_CLICKED(IDC_NEW_BTN, &CUserDlg::OnBnClickedNewBtn)
	ON_BN_CLICKED(IDC_DELETE_BTN, &CUserDlg::OnBnClickedDeleteBtn)
	ON_BN_CLICKED(IDC_USER_FRESH_BTN, &CUserDlg::OnBnClickedUserFreshBtn)
	ON_BN_CLICKED(IDC_CLOSE_USER_BTN, &CUserDlg::OnBnClickedCloseUserBtn)
END_MESSAGE_MAP()


// CUserDlg 消息处理程序

BOOL CUserDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// TODO:  在此添加额外的初始化
	pUserOpen = new CUserOpenDlg;
	pUserNew = new CUserNewDlg;
	pUserDelete = new CUserDeleteDlg;
	pUserFresh = new CUserFreshDlg;

	int nX = 0;
	int nY = 80;
	int nWidth = 800;
	int nHeight = 520;
	pUserOpen->Create(IDD_USER_OPEN_DIALOG,this);
	pUserOpen->MoveWindow(nX,nY,nWidth,nHeight);

	pUserNew->Create(IDD_USER_NEW_DIALOG,this);
	pUserNew->MoveWindow(nX,nY,nWidth,nHeight);

	pUserDelete->Create(IDD_USER_DELETE_DIALOG,this);
	pUserDelete->MoveWindow(nX,nY,nWidth,nHeight);

	pUserFresh->Create(IDD_USER_FRESH_DIALOG,this);
	pUserFresh->MoveWindow(nX,nY,nWidth,nHeight);

	GetDlgItem(IDC_EDIT_NOWUSER)->SetWindowText(theApp.myModuleMain.string2CString(theApp.myUserPower.nowUser.userName));
	CListBox* m_errBox=(CListBox*)GetDlgItem(IDC_LIST_ALLUSER);
	m_errBox->AddString(_T("root"));
	for(map<string,UserStruct>::iterator iter=theApp.myUserPower.userMap.begin();iter!=theApp.myUserPower.userMap.end();iter++ )
	{
		//CListBox* m_errBox=(CListBox*)GetDlgItem(IDC_LIST_ALLUSER);
		m_errBox->AddString(theApp.myModuleMain.string2CString(iter->first));
	}
	m_errBox->SelectString(0,theApp.myModuleMain.stringToLPCWSTR(theApp.myUserPower.nowUser.userName));
	//m_errBox->SetCurSel(0);
	//delete m_errBox;
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CUserDlg::OnBnClickedOpenButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CListBox* m_errBox=(CListBox*)pUserOpen->GetDlgItem(IDC_NOT_GRANTED_LIST);
	m_errBox->ResetContent();

	CListBox* m_grantedBox=(CListBox*)pUserOpen->GetDlgItem(IDC_GRANTED_LIST);
	m_grantedBox->ResetContent();
	string filePathName="Storage Card\\System\\UserPower\\";
	filePathName=filePathName+theApp.myUserPower.nowUser.userName+".txt";
	vector<string> nowUserPower=theApp.myUserPower.GetPower(filePathName);
	for (int i=0;i<nowUserPower.size();i++)
	{
		m_grantedBox->AddString(theApp.myModuleMain.stringToLPCWSTR(nowUserPower.at(i)));
	}
	m_grantedBox->SetCurSel(0);

	string fatherPathName="Storage Card\\System\\UserPower\\";
	fatherPathName=fatherPathName+theApp.myUserPower.nowUser.fatherName+".txt";
	vector<string> fatherPower=theApp.myUserPower.GetPower(fatherPathName);
	for(int i=0;i<fatherPower.size();i++)
	{
		vector<string>::iterator findIter=find(nowUserPower.begin(),nowUserPower.end(),fatherPower.at(i));
		if (findIter==nowUserPower.end())
		{
			m_errBox->AddString(theApp.myModuleMain.stringToLPCWSTR(fatherPower.at(i)));
		}
	}

	if (m_errBox->GetCount()>0)
	{
		m_errBox->SetCurSel(0);
	}

	pUserOpen->GetDlgItem(IDC_USER_NAME_EDIT)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myUserPower.nowUser.userName));
	pUserOpen->GetDlgItem(IDC_PASSWARD_EDIT)->SetWindowText(_T(""));
	showUserDlg(IDD_USER_OPEN_DIALOG);
}

void CUserDlg::OnBnClickedNewBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	CListBox* m_errBox=(CListBox*)pUserNew->GetDlgItem(IDC_NOT_GRANTED_LIST);
	m_errBox->ResetContent();
	CListBox* m_grantedBox=(CListBox*)pUserNew->GetDlgItem(IDC_GRANTED_LIST);
	m_grantedBox->ResetContent();
	string filePathName="Storage Card\\System\\UserPower\\";
	filePathName=filePathName+theApp.myUserPower.nowUser.userName+".txt";
	vector<string> nowUserPower=theApp.myUserPower.GetPower(filePathName);
	for (int i=0;i<nowUserPower.size();i++)
	{
		m_errBox->AddString(theApp.myModuleMain.stringToLPCWSTR(nowUserPower.at(i)));
	}
	m_errBox->SetCurSel(0);

	pUserNew->GetDlgItem(IDC_USER_NAME_EDIT)->SetWindowText(_T(""));
	pUserNew->GetDlgItem(IDC_PASSWARD_EDIT)->SetWindowText(_T(""));
	showUserDlg(IDD_USER_NEW_DIALOG);
}

void CUserDlg::OnBnClickedDeleteBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	CString deletUser;
	CListBox* m_allUserBox=(CListBox*)GetDlgItem(IDC_LIST_ALLUSER);
	m_allUserBox->GetText(m_allUserBox->GetCurSel(),deletUser);
	CString staticEdit;
	staticEdit.Format(_T("确定删除用户 %s ？"),deletUser);
	pUserDelete->GetDlgItem(IDC_STATIC_DELET)->SetWindowText(staticEdit);
	showUserDlg(IDD_USER_DELETE_DIALOG);
}

void CUserDlg::OnBnClickedUserFreshBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	CListBox* m_freBox=(CListBox*)pUserFresh->GetDlgItem(IDC_FRESH_USER_NAME_LIST);
	m_freBox->ResetContent();
	m_freBox->AddString(_T("root"));
	for(map<string,UserStruct>::iterator iter=theApp.myUserPower.userMap.begin();iter!=theApp.myUserPower.userMap.end();iter++ )
	{
		//CListBox* m_errBox=(CListBox*)GetDlgItem(IDC_LIST_ALLUSER);
		m_freBox->AddString(theApp.myModuleMain.string2CString(iter->first));
	}
	//m_freBox->SetCurSel(0);//IDC_FRESH_PASSWARD_EDIT
	CListBox* m_allUser=(CListBox*) GetDlgItem(IDC_LIST_ALLUSER);
	CString selectUser;
	m_allUser->GetText(m_allUser->GetCurSel(),selectUser);
	m_freBox->SelectString(0,selectUser);
	pUserFresh->GetDlgItem(IDC_FRESH_PASSWARD_EDIT)->SetWindowText(_T(""));
	showUserDlg(IDD_USER_FRESH_DIALOG);
}

void CUserDlg::OnBnClickedCloseUserBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	showUserDlg(0);
}

void CUserDlg::showUserDlg(int ID)
{
	pUserOpen->ShowWindow(SW_HIDE);
	pUserNew->ShowWindow(SW_HIDE);
	pUserDelete->ShowWindow(SW_HIDE);
	pUserFresh->ShowWindow(SW_HIDE);

	if (ID == IDD_USER_OPEN_DIALOG)
	{
		pUserOpen->ShowWindow(SW_SHOW);
	}
	else if (ID == IDD_USER_NEW_DIALOG)
	{
		pUserNew->ShowWindow(SW_SHOW);
	}
	else if (ID == IDD_USER_DELETE_DIALOG)
	{
		pUserDelete->ShowWindow(SW_SHOW);
	}
	else if (ID == IDD_USER_FRESH_DIALOG)
	{
		pUserFresh->ShowWindow(SW_SHOW);
	}
	else if (ID == 0)
	{
		this->ShowWindow(SW_HIDE);
	}

}
