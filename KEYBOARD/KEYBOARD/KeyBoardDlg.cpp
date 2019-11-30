// KeyBoardDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "KeyBoard.h"
#include "KeyBoardDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif
// CKeyBoardDlg �Ի���

CKeyBoardDlg::CKeyBoardDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKeyBoardDlg::IDD, pParent)
{
	pMain = NULL;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CKeyBoardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CKeyBoardDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	//}}AFX_MSG_MAP
	ON_EN_SETFOCUS(IDC_EDIT1, &CKeyBoardDlg::OnEnSetfocusEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CKeyBoardDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CKeyBoardDlg ��Ϣ�������

BOOL CKeyBoardDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//���öԻ����λ�úͳߴ�
	SetWindowPos(NULL,0,0,800,600,SWP_SHOWWINDOW );	
	CRect rect;
	GetWindowRect(&rect);
	//��ʼʱ�Ի����ý���
	GetDlgItem(IDD_KEYBOARD_DIALOG)->SetFocus();

	
	return FALSE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
void CKeyBoardDlg::OnSize(UINT /*nType*/, int /*cx*/, int /*cy*/)
{
	if (AfxIsDRAEnabled())
	{
		DRA::RelayoutDialog(
			AfxGetResourceHandle(), 
			this->m_hWnd, 
			DRA::GetDisplayMode() != DRA::Portrait ? 
			MAKEINTRESOURCE(IDD_KEYBOARD_DIALOG_WIDE) : 
			MAKEINTRESOURCE(IDD_KEYBOARD_DIALOG));
	}
}
#endif


void CKeyBoardDlg::OnEnSetfocusEdit1()
{


	if (NULL == pMain)   
	{   
		// ������ģ̬�Ի���ʵ��   
		pMain = new CKeyBoMain();
		pMain->Create( IDD_KEYBOARD_MAIN,this);
	}  
	pMain->ShowWindow(SW_SHOW);
	//CKeyBoMain mian;
	//mian.DoModal();
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CKeyBoardDlg::OnBnClickedButton1()
{

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CKeyBoardDlg::setEditText(CString &str)
{
	CString allstr,str1;
	CWnd* pWnd = GetDlgItem(IDC_EDIT1);
	pWnd->GetWindowText(str1);
	allstr = str1+str;
	pWnd->SetWindowText(allstr);
}
