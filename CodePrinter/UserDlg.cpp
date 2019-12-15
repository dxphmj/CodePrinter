// UserDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "UserDlg.h"
#include "UserOpenDlg.h"
#include "UserNewDlg.h"
#include "UserDeleteDlg.h"
#include "UserFreshDlg.h"

// CUserDlg �Ի���

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


// CUserDlg ��Ϣ�������

BOOL CUserDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	pUserOpen = new CUserOpenDlg;
	pUserNew = new CUserNewDlg;
	pUserDelete = new CUserDeleteDlg;
	pUserFresh = new CUserFreshDlg;

	int nX = 0;
	int nY = 0;
	int nWidth = 800;
	int nHeight = 450;
	pUserOpen->Create(IDD_USER_OPEN_DIALOG,this);
	pUserOpen->MoveWindow(nX,nY,nWidth,nHeight);

	pUserNew->Create(IDD_USER_NEW_DIALOG,this);
	pUserNew->MoveWindow(nX,nY,nWidth,nHeight);

	pUserDelete->Create(IDD_USER_DELETE_DIALOG,this);
	pUserOpen->MoveWindow(nX,nY,nWidth,nHeight);

	pUserFresh->Create(IDD_USER_FRESH_DIALOG,this);
	pUserFresh->MoveWindow(nX,nY,nWidth,nHeight);


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CUserDlg::OnBnClickedOpenButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	showUserDlg(IDD_USER_OPEN_DIALOG);
}

void CUserDlg::OnBnClickedNewBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	showUserDlg(IDD_USER_NEW_DIALOG);
}

void CUserDlg::OnBnClickedDeleteBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	showUserDlg(IDD_USER_DELETE_DIALOG);
}

void CUserDlg::OnBnClickedUserFreshBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	showUserDlg(IDD_USER_FRESH_DIALOG);
}

void CUserDlg::OnBnClickedCloseUserBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
