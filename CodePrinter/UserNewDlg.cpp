// UserNewDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "UserNewDlg.h"


// CUserNewDlg 对话框

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
	DDX_Control(pDX, IDC_BUTTON_CLOSE, m_pReturn);
	DDX_Control(pDX, IDC_BUTTON_OK, m_pbtnOK);
	DDX_Control(pDX, IDC_RIGHT_MOVE_BTN, m_pRight_move);
	DDX_Control(pDX, IDC_LEFT_MOVE_BTN, m_pLeft_move);

}


BEGIN_MESSAGE_MAP(CUserNewDlg, CDialog)

	ON_BN_CLICKED(IDC_BUTTON1, &CUserNewDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RIGHT_MOVE_BTN, &CUserNewDlg::OnBnClickedRightMoveBtn)
	ON_BN_CLICKED(IDC_LEFT_MOVE_BTN, &CUserNewDlg::OnBnClickedLeftMoveBtn)
	ON_BN_CLICKED(IDC_BUTTON_OK, &CUserNewDlg::OnBnClickedButtonOk)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CUserNewDlg::OnBnClickedButtonClose)

	ON_WM_CTLCOLOR()

END_MESSAGE_MAP()


// CUserNewDlg 消息处理程序
BOOL CUserNewDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CRect rect1,rect2,rect3,rect4;
	GetDlgItem(IDC_BUTTON_CLOSE)->GetWindowRect(&rect1);
	GetDlgItem(IDC_BUTTON_OK)->GetWindowRect(&rect2);
	GetDlgItem(IDC_LEFT_MOVE_BTN)->GetWindowRect(&rect3);
	GetDlgItem(IDC_RIGHT_MOVE_BTN)->GetWindowRect(&rect4);

	GetDlgItem(IDC_BUTTON_CLOSE)->SetWindowPos(NULL,20,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_OK)->SetWindowPos(NULL,700,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_LEFT_MOVE_BTN)->SetWindowPos(NULL,rect3.left,rect3.top,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_RIGHT_MOVE_BTN)->SetWindowPos(NULL,rect4.left,rect4.top,70,45,SWP_SHOWWINDOW);


	m_pReturn.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_70_45_BITMAP);
	m_pReturn.SizeToContent(); 
	m_pbtnOK.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_70_45_BITMAP);
	m_pbtnOK.SizeToContent(); 
	m_pRight_move.LoadBitmaps(IDB_R_SHIFT1_BITMAP,IDB_R_SHIFT2_BITMAP,0,0,IDB_70_45_BITMAP);
	m_pRight_move.SizeToContent(); 
	m_pLeft_move.LoadBitmaps(IDB_L_SHIFT1_BITMAP,IDB_L_SHIFT2_BITMAP,0,0,IDB_70_45_BITMAP);
	m_pLeft_move.SizeToContent(); 


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CUserNewDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	ShowWindow(SW_HIDE);
}

void CUserNewDlg::OnBnClickedRightMoveBtn()
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

void CUserNewDlg::OnBnClickedLeftMoveBtn()
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

void CUserNewDlg::OnBnClickedButtonOk()
{
	// TODO: 在此添加控件通知处理程序代码
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
		CString csMsg = _T("用户名不能为空！");
		AfxMessageBox(csMsg);
		return;
	}

	CString userKey;
	GetDlgItem(IDC_PASSWARD_EDIT)->GetWindowText(userKey);
	if (userKey.IsEmpty())
	{
		CString csMsg = _T("密码不能为空！");
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
	// TODO: 在此添加控件通知处理程序代码
	ShowWindow(SW_HIDE);
}

HBRUSH CUserNewDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if(nCtlColor == CTLCOLOR_STATIC)
	{		 
		pDC->SelectObject(theApp.m_StaticFont);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));	
	}
	// TODO:  在此更改 DC 的任何属性
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return theApp.m_DlgBrush;
}



