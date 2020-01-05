// NumKey.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "NumKey.h"
#include "CodePrinterDlg.h"


// CNumKey �Ի���

IMPLEMENT_DYNAMIC(CNumKey, CDialog)

CNumKey::CNumKey(CWnd* pParent /*=NULL*/)
	: CDialog(CNumKey::IDD, pParent)
{
		isShow = true;
		m_edit = NULL;
}

CNumKey::~CNumKey()
{
}

void CNumKey::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CNumKey, CDialog)
	
	ON_BN_CLICKED(IDC_BUTTON_KEY_ESC, &CNumKey::OnBnClickedButtonKeyEsc)
	ON_BN_CLICKED(IDC_BUTTON_KEY_DEL, &CNumKey::OnBnClickedButtonKeyDel)
	ON_BN_CLICKED(IDC_BUTTON_KEY_OK, &CNumKey::OnBnClickedButtonKeyOk)
	ON_BN_CLICKED(IDC_BUTTON_KEY_LEFT, &CNumKey::OnBnClickedButtonKeyLeft)
	ON_BN_CLICKED(IDC_BUTTON_KEY_RIGHT, &CNumKey::OnBnClickedButtonKeyRight)

	ON_BN_CLICKED(IDC_BUTTON_KEY9, &CNumKey::OnBnClickedButtonKey9)
	ON_BN_CLICKED(IDC_BUTTON_KEY8, &CNumKey::OnBnClickedButtonKey8)
	ON_BN_CLICKED(IDC_BUTTON_KEY7, &CNumKey::OnBnClickedButtonKey7)
	ON_BN_CLICKED(IDC_BUTTON_KEY6, &CNumKey::OnBnClickedButtonKey6)
	ON_BN_CLICKED(IDC_BUTTON_KEY5, &CNumKey::OnBnClickedButtonKey5)
	ON_BN_CLICKED(IDC_BUTTON_KEY4, &CNumKey::OnBnClickedButtonKey4)
	ON_BN_CLICKED(IDC_BUTTON_KEY3, &CNumKey::OnBnClickedButtonKey3)
	ON_BN_CLICKED(IDC_BUTTON_KEY2, &CNumKey::OnBnClickedButtonKey2)
	ON_BN_CLICKED(IDC_BUTTON_KEY1, &CNumKey::OnBnClickedButtonKey1)
	ON_BN_CLICKED(IDC_BUTTON_KEY0, &CNumKey::OnBnClickedButtonKey0)
	ON_BN_CLICKED(IDC_BUTTON_KEY_DOC, &CNumKey::OnBnClickedButtonKeyDoc)
END_MESSAGE_MAP()


// CNumKey ��Ϣ�������

BOOL CNumKey::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CRect rtClient;
	GetWindowRect(rtClient);  
	//::SetWindowPos(m_hWnd, HWND_TOPMOST, rtClient.left, rtClient.top, rtClient.Width(), rtClient.Height(), SWP_SHOWWINDOW);
	this->SetWindowPos(&wndTopMost,0,0,276,159,SWP_NOSIZE|SWP_NOMOVE);
	this->MoveWindow(276,159,rtClient.Width(),rtClient.Height());
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}



void CNumKey::setEditNum( CString Numstr )
{
	int nPosStart;
	int nPosEnd  = 0;
	//CCodePrinterDlg* pWnd = (CCodePrinterDlg*)this->GetParent();
	//pWnd->m_Confi->m_edit_speed.GetSel(nPosStart, nPosEnd); 
	//pWnd->m_Confi->m_edit_speed.SetSel(nPosStart, nPosStart); 
	//pWnd->m_Confi->m_edit_speed.ReplaceSel(Numstr);
	//pResult = (CEdit *)GetDlgItem(IDC_SPEED_EDIT);
	
	CEdit *pResult;
	m_edit->GetSel(nPosStart, nPosEnd); 
	m_edit->SetSel(nPosStart, nPosStart); 
	m_edit->ReplaceSel(Numstr);
}

void CNumKey::getNumFromEdit( CEdit *pEdit )
{
	if ( isShow )
	{
		this->ShowWindow(SW_SHOW);
		isShow = false;
		m_edit = pEdit;
	}
}

void CNumKey::OnBnClickedButtonKeyEsc()
{
//	m_edit->GetParent()->SetFocus();
	CCodePrinterDlg* dlg;
	dlg = (CCodePrinterDlg*)(m_pCodePrinterDlg);
	
	delete dlg->m_pNumKey;
	dlg->m_pNumKey = NULL;
	m_edit = NULL;
 //   this->DestroyWindow();

	//this->GetParent()->SetFocus();
	//this->ShowWindow(SW_HIDE);
	//isShow = true;
	//m_edit = NULL;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
void CNumKey::OnBnClickedButtonKeyOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CCodePrinterDlg* dlg;
	dlg = (CCodePrinterDlg*)(m_edit->GetParent()->GetParent()->GetParent());

	delete dlg->m_pNumKey;
	dlg->m_pNumKey = NULL;
	m_edit = NULL;
	//this->GetParent()->SetFocus();
	//this->ShowWindow(SW_HIDE);
	//isShow = true;
}
void CNumKey::OnBnClickedButtonKeyDel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nPosStart;
	int nPosEnd  = 0; 
	m_edit->GetSel(nPosStart, nPosEnd); 
	m_edit->SetSel(nPosStart-1, nPosStart);                            
	m_edit->ReplaceSel(_T(""));

}



void CNumKey::OnBnClickedButtonKeyLeft()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nPosStart;
	int nPosEnd  = 0; 
	m_edit->GetSel(nPosStart, nPosEnd); 
	m_edit->SetSel(nPosStart-1, nPosStart-1);
	m_edit->SetFocus();
}

void CNumKey::OnBnClickedButtonKeyRight()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nPosStart;
	int nPosEnd  = 0; 
	m_edit->GetSel(nPosStart, nPosEnd); 
	m_edit->SetSel(nPosStart+1, nPosStart+1); 
	m_edit->SetFocus();
}
void CNumKey::OnBnClickedButtonKey7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString tempstr;
	GetDlgItem(IDC_BUTTON_KEY7)->GetWindowText(tempstr);
	setEditNum( tempstr );
}
void CNumKey::OnBnClickedButtonKey8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString tempstr;
	GetDlgItem(IDC_BUTTON_KEY8)->GetWindowText(tempstr);
	setEditNum( tempstr );
}



void CNumKey::OnBnClickedButtonKey9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString tempstr;
	GetDlgItem(IDC_BUTTON_KEY9)->GetWindowText(tempstr);
	setEditNum( tempstr );
}
void CNumKey::OnBnClickedButtonKey6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString tempstr;
	GetDlgItem(IDC_BUTTON_KEY6)->GetWindowText(tempstr);
	setEditNum( tempstr );
}
void CNumKey::OnBnClickedButtonKey5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString tempstr;
	GetDlgItem(IDC_BUTTON_KEY5)->GetWindowText(tempstr);
	setEditNum( tempstr );
}
void CNumKey::OnBnClickedButtonKey4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString tempstr;
	GetDlgItem(IDC_BUTTON_KEY4)->GetWindowText(tempstr);
	setEditNum( tempstr );
}
void CNumKey::OnBnClickedButtonKey3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString tempstr;
	GetDlgItem(IDC_BUTTON_KEY3)->GetWindowText(tempstr);
	setEditNum( tempstr );
}
void CNumKey::OnBnClickedButtonKey2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString tempstr;
	GetDlgItem(IDC_BUTTON_KEY2)->GetWindowText(tempstr);
	setEditNum( tempstr );
}
void CNumKey::OnBnClickedButtonKey1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString tempstr;
	GetDlgItem(IDC_BUTTON_KEY1)->GetWindowText(tempstr);
	setEditNum( tempstr );
}
void CNumKey::OnBnClickedButtonKey0()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString tempstr;
	GetDlgItem(IDC_BUTTON_KEY0)->GetWindowText(tempstr);
	setEditNum( tempstr );
}
void CNumKey::OnBnClickedButtonKeyDoc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString tempstr;
	GetDlgItem(IDC_BUTTON_KEY_DOC)->GetWindowText(tempstr);
	setEditNum( tempstr );
}