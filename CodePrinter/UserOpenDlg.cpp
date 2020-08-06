// UserOpenDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "UserOpenDlg.h"
#include "CodePrinterDlg.h"


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
	DDX_Control(pDX, IDC_OPEN_NOT_GRANTED_LIST, m_notGranted);
	DDX_Control(pDX, IDC_OPEN_GRANTED_LIST, m_granted);
	DDX_Control(pDX, IDC_BUTTON_CLOSE, m_pReturn);
	DDX_Control(pDX, IDC_BUTTON_OK, m_pbtnOK);
	DDX_Control(pDX, IDC_RIGHT_MOVE_BTN, m_pRight_move);
	DDX_Control(pDX, IDC_LEFT_MOVE_BTN, m_pLeft_move);

	DDX_Control(pDX, IDC_USER_OPEN_NAME_STATIC, m_openUserNameStatic);
	DDX_Control(pDX, IDC_USER_OPEN_UNAUTHORIZED_STATIC, m_openUnauthorizedStatic);
	DDX_Control(pDX, IDC_OPEN_PASSWARD_STATIC, m_openPasswordStatic);
	DDX_Control(pDX, IDC_USER_OPEN_AUTHORIZED_STATIC, m_openAuthorizedStatic);

	DDX_Control(pDX, IDC_OPEN_NAME_EDIT, m_open_nameEdit);
	DDX_Control(pDX, IDC_OPEN_PASSWARD_EDIT, m_open_passwordEdit);
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

	CRect rect1,rect2,rect3,rect4;
	GetDlgItem(IDC_BUTTON_CLOSE)->GetWindowRect(&rect1);
	GetDlgItem(IDC_BUTTON_OK)->GetWindowRect(&rect2);
	GetDlgItem(IDC_LEFT_MOVE_BTN)->GetWindowRect(&rect3);
	GetDlgItem(IDC_RIGHT_MOVE_BTN)->GetWindowRect(&rect4);

	GetDlgItem(IDC_BUTTON_CLOSE)->SetWindowPos(NULL,20,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_OK)->SetWindowPos(NULL,700,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_LEFT_MOVE_BTN)->SetWindowPos(NULL,rect3.left,rect3.top,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_RIGHT_MOVE_BTN)->SetWindowPos(NULL,rect4.left,rect4.top,70,45,SWP_SHOWWINDOW);


	m_pReturn.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_80_55_BITMAP);
	m_pReturn.SizeToContent(); 
	m_pbtnOK.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_80_55_BITMAP);
	m_pbtnOK.SizeToContent(); 
	m_pRight_move.LoadBitmaps(IDB_R_SHIFT1_BITMAP,IDB_R_SHIFT2_BITMAP,0,0,IDB_60_35_BITMAP);
	m_pRight_move.SizeToContent(); 
	m_pLeft_move.LoadBitmaps(IDB_L_SHIFT1_BITMAP,IDB_L_SHIFT2_BITMAP,0,0,IDB_60_35_BITMAP);
	m_pLeft_move.SizeToContent();

	m_open_nameEdit.SetFont(theApp.m_EditFont);
	m_open_passwordEdit.SetFont(theApp.m_EditFont);

	m_notGranted.SetItemHeight(0,20);
	m_granted.SetItemHeight(0,20);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CUserOpenDlg::OnBnClickedRightMoveBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	CListBox* m_notBox=(CListBox*)GetDlgItem(IDC_OPEN_NOT_GRANTED_LIST);
	CListBox* m_grantedBox=(CListBox*)GetDlgItem(IDC_OPEN_GRANTED_LIST);
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
	CListBox* m_notBox=(CListBox*)GetDlgItem(IDC_OPEN_NOT_GRANTED_LIST);
	CListBox* m_grantedBox=(CListBox*)GetDlgItem(IDC_OPEN_GRANTED_LIST);
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
	wstring tempstr;
	CString cstr;
	CCodePrinterDlg *pCodeDlg = (CCodePrinterDlg*)this->GetParent()->GetParent();//获取主对话框指针
	tempstr=theApp.myLanguage.LanguageMap["ID_USER_MANAGEMENT"];
	cstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(tempstr.c_str());
	((CCodePrinterDlg*)GetParent()->GetParent())->m_PicHead.SetOperationString(cstr);//User Manage 
}

void CUserOpenDlg::OnBnClickedButtonOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CListBox* m_allUserBox=(CListBox*)GetParent()->GetDlgItem(IDC_LIST_ALLUSER);
	CString ChangeUser;
	int detInt=m_allUserBox->GetCurSel();
	m_allUserBox->GetText(detInt,ChangeUser);
	string changeName=theApp.myModuleMain.CString2string(ChangeUser);
	if (changeName=="root")
	{
		CString csMsg ;
		csMsg.Format(_T("错误!\n请勿修改root用户"));
		AfxMessageBox(csMsg);
		return;
	}

	map<string,UserStruct>::iterator findIter=theApp.myUserPower.userMap.find(changeName);
	if (findIter!=theApp.myUserPower.userMap.end())
	{
		UserStruct deleteUT=findIter->second;
		if (deleteUT.userLevel>theApp.myUserPower.nowUser.userLevel)
		{
			CString csKEY;
			GetDlgItem(IDC_OPEN_PASSWARD_EDIT)->GetWindowText(csKEY);
			string passKey=theApp.myModuleMain.CString2string(csKEY);
			if (passKey==deleteUT.userKey)
			{
				CListBox* m_grantedBox=(CListBox*)GetDlgItem(IDC_OPEN_GRANTED_LIST);
				vector<string> tempStrVec;
				for (int i=0;i<m_grantedBox->GetCount();i++)
				{
					CString strSelect;
					m_grantedBox->GetText(i,strSelect);
					string strStr=theApp.myModuleMain.CString2string(strSelect);
					tempStrVec.push_back(strStr);
				}
				string pathName="Storage Card\\System\\UserPower\\"+changeName+".txt";
				theApp.myUserPower.SavePower(pathName,tempStrVec);
				theApp.myUserPower.changeUserPower();
			} 
			else
			{
				CString csMsg ;
				csMsg.Format(_T("密码错误!\n请输入%s的密码"),changeName);
				AfxMessageBox(csMsg);
				return;
			}
		} 
		else
		{
			CString csMsg ;
			csMsg.Format(_T("权限不足!\n您无权更改%s"),theApp.myModuleMain.string2CString(deleteUT.userName));
			AfxMessageBox(csMsg);
			return;
		}
	} 
	else
	{
		{
			m_allUserBox->DeleteString(detInt);
		}
	}

	ShowWindow(SW_HIDE);
}

HBRUSH CUserOpenDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if(nCtlColor == CTLCOLOR_STATIC)
	{		 
		pDC->SelectObject(theApp.m_StaticFont);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));	
		return theApp.m_StaticBrush;
	}
	if(nCtlColor == CTLCOLOR_EDIT)
	{ 
	// 	pDC->SelectObject(theApp.m_EditFont);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));	
		return theApp.m_StaticBrush;
	}
	if(nCtlColor == CTLCOLOR_LISTBOX)
	{
		pDC->SelectObject(theApp.m_ListBoxFont);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));	
		return theApp.m_ListBoxBrush;
	}
	// TODO:  在此更改 DC 的任何属性
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return theApp.m_DlgBrush;
}


BOOL CUserOpenDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_OPEN_NAME_EDIT);
	CEdit* kEdit = (CEdit*)GetDlgItem(IDC_OPEN_PASSWARD_EDIT);
	ASSERT(pEdit && pEdit->GetSafeHwnd());
	ASSERT(kEdit && kEdit->GetSafeHwnd());
	//if(WM_LBUTTONDOWN == pMsg->message && pEdit->GetSafeHwnd() == pMsg->hwnd)
	//{
	//	//pEdit->SetFocus();
	//	//pEdit->SetSel(-1);
	//	CString str;
	//	pEdit-> GetWindowText(str);

	//	CExportDlg myCExportDlg;
	//	//CString ts;
	//	//ts.Format(L"%s",_T("sdfsa"));
	//	str=myCExportDlg.GetInputText(str);
	//	pEdit-> SetWindowText(str);
	//	return TRUE;
	//}
	if(WM_LBUTTONDOWN == pMsg->message && kEdit->GetSafeHwnd() == pMsg->hwnd)
	{
		//pEdit->SetFocus();
		//pEdit->SetSel(-1);
		CString str;
		kEdit-> GetWindowText(str);

		CExportDlg myCExportDlg;
		//CString ts;
		//ts.Format(L"%s",_T("sdfsa"));
		str=myCExportDlg.GetInputText(str);
		kEdit-> SetWindowText(str);
		return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}
