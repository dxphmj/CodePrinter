// UserDeleteDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "UserDeleteDlg.h"


// CUserDeleteDlg 对话框

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
	DDX_Control(pDX, IDC_BUTTON_CLOSE_DEL, m_pReturn);
	DDX_Control(pDX, IDC_BUTTON_OK_DEL, m_pbtnOK);
}


BEGIN_MESSAGE_MAP(CUserDeleteDlg, CDialog)

	//ON_BN_CLICKED(IDC_BUTTON_CLOSE_DEL, &CUserDeleteDlg::OnBnClickedButtonClose)
	ON_BN_CLICKED(IDC_BUTTON_OK_DEL, &CUserDeleteDlg::OnBnClickedButtonOk)

	ON_WM_CTLCOLOR()

	ON_BN_CLICKED(IDC_BUTTON_CLOSE_DEL, &CUserDeleteDlg::OnBnClickedButtonCloseDel)
END_MESSAGE_MAP()


// CUserDeleteDlg 消息处理程序
BOOL CUserDeleteDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	CRect rect1,rect2;
	GetDlgItem(IDC_BUTTON_CLOSE_DEL)->GetWindowRect(&rect1);
	GetDlgItem(IDC_BUTTON_OK_DEL)->GetWindowRect(&rect2);

	GetDlgItem(IDC_BUTTON_CLOSE_DEL)->SetWindowPos(NULL,20,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_OK_DEL)->SetWindowPos(NULL,700,390,70,45,SWP_SHOWWINDOW);

	m_pReturn.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_70_45_BITMAP);
	m_pReturn.SizeToContent(); 
	m_pbtnOK.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_70_45_BITMAP);
	m_pbtnOK.SizeToContent(); 
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}




//void CUserDeleteDlg::OnBnClickedButtonClose()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	ShowWindow(SW_HIDE);
//}

void CUserDeleteDlg::OnBnClickedButtonOk()
{
	// TODO: 在此添加控件通知处理程序代码
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
			csMsg.Format(_T("权限不足!\n您无权删除%s"),theApp.myModuleMain.string2CString(deleteUT.userName));
			AfxMessageBox(csMsg);
			return;
		}
	} 
	else
	{
		//m_allUserBox->DeleteString(detInt);
		if (theApp.myModuleMain.CString2string(deletUser)=="root")
		{
			CString csMsg = _T("无法删除 root ！");
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

HBRUSH CUserDeleteDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


void CUserDeleteDlg::OnBnClickedButtonCloseDel()
{
	// TODO: 在此添加控件通知处理程序代码
	ShowWindow(SW_HIDE);
}

