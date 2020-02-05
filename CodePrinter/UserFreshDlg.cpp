// UserFreshDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "UserFreshDlg.h"
#include "CodePrinterDlg.h"


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
	DDX_Control(pDX, IDC_BUTTON_CLOSE, m_pReturn);
	DDX_Control(pDX, IDC_BUTTON_OK, m_pbtnOK);
	
	DDX_Control(pDX, IDC_USER_FRESH_NAME_STATIC, m_freshUserNameStatic);
	DDX_Control(pDX, IDC_FRESH_PASSWORD_STATIC, m_freshPasswordStatic);
	DDX_Control(pDX, IDC_FRESH_USER_NAME_LIST, m_userNameList);
	DDX_Control(pDX, IDC_FRESH_PASSWARD_EDIT, m_passwordEdit);
}


BEGIN_MESSAGE_MAP(CUserFreshDlg, CDialog)

	ON_BN_CLICKED(IDC_BUTTON_CLOSE, &CUserFreshDlg::OnBnClickedButtonClose)
	ON_BN_CLICKED(IDC_BUTTON_OK, &CUserFreshDlg::OnBnClickedButtonOk)

	ON_WM_CTLCOLOR()

END_MESSAGE_MAP()


// CUserFreshDlg ��Ϣ�������
BOOL CUserFreshDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CRect rect1,rect2;
	GetDlgItem(IDC_BUTTON_CLOSE)->GetWindowRect(&rect1);
	GetDlgItem(IDC_BUTTON_OK)->GetWindowRect(&rect2);

	GetDlgItem(IDC_BUTTON_CLOSE)->SetWindowPos(NULL,20,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_OK)->SetWindowPos(NULL,700,390,70,45,SWP_SHOWWINDOW);

	m_pReturn.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_80_55_BITMAP);
	m_pReturn.SizeToContent(); 
	m_pbtnOK.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_80_55_BITMAP);
	m_pbtnOK.SizeToContent(); 

	m_userNameList.SetItemHeight(0,20);
	m_passwordEdit.SetFont(theApp.m_EditFont);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CUserFreshDlg::OnBnClickedButtonClose()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShowWindow(SW_HIDE);
	wstring tempstr;
	CString cstr;
	tempstr=theApp.myLanguage.LanguageMap["ID_USER_MANAGEMENT"];
	cstr = tempstr.c_str();
	((CCodePrinterDlg*)GetParent()->GetParent())->m_PicHead.SetOperationString(cstr);//User Manage 
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

HBRUSH CUserFreshDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
	// TODO:  �ڴ˸��� DC ���κ�����
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return theApp.m_DlgBrush;
}




BOOL CUserFreshDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_FRESH_PASSWARD_EDIT);
	ASSERT(pEdit && pEdit->GetSafeHwnd());
	if(WM_LBUTTONDOWN == pMsg->message && pEdit->GetSafeHwnd() == pMsg->hwnd)
	{
		//pEdit->SetFocus();
		//pEdit->SetSel(-1);
		CString str;
		pEdit-> GetWindowText(str);

		CExportDlg myCExportDlg;
		//CString ts;
		//ts.Format(L"%s",_T("sdfsa"));
		str=myCExportDlg.GetInputText(str);
		pEdit-> SetWindowText(str);
		return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}
