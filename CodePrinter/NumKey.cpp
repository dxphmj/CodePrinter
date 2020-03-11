// NumKey.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "NumKey.h"
#include "CodePrinterDlg.h"
#include "InkParDlg.h"
#include "InkSystemDlg.h"

#define InkParDlg     1
#define InkPhasingDlg 2
// CNumKey 对话框

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


// CNumKey 消息处理程序

BOOL CNumKey::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CRect rtClient;
	GetWindowRect(rtClient);  
	//::SetWindowPos(m_hWnd, HWND_TOPMOST, rtClient.left, rtClient.top, rtClient.Width(), rtClient.Height(), SWP_SHOWWINDOW);
	this->SetWindowPos(&wndTopMost,0,0,276,159,SWP_NOSIZE|SWP_NOMOVE);
	this->MoveWindow(276,159,rtClient.Width(),rtClient.Height());

	CFont *pFont = new CFont; //创建一个指向新字体类型的指针pFont
	pFont->CreatePointFont(180, _T("黑体"));
	GetDlgItem(IDC_BUTTON_KEY_ESC)->SetFont(pFont);
	GetDlgItem(IDC_BUTTON_KEY_DEL)->SetFont(pFont);
	GetDlgItem(IDC_BUTTON_KEY_OK)->SetFont(pFont);
	GetDlgItem(IDC_BUTTON_KEY_LEFT)->SetFont(pFont);
	GetDlgItem(IDC_BUTTON_KEY_RIGHT)->SetFont(pFont);
	GetDlgItem(IDC_BUTTON_KEY9)->SetFont(pFont);
	GetDlgItem(IDC_BUTTON_KEY8)->SetFont(pFont);
	GetDlgItem(IDC_BUTTON_KEY7)->SetFont(pFont);
	GetDlgItem(IDC_BUTTON_KEY6)->SetFont(pFont);
	GetDlgItem(IDC_BUTTON_KEY5)->SetFont(pFont);
	GetDlgItem(IDC_BUTTON_KEY4)->SetFont(pFont);
	GetDlgItem(IDC_BUTTON_KEY3)->SetFont(pFont);
	GetDlgItem(IDC_BUTTON_KEY2)->SetFont(pFont);
	GetDlgItem(IDC_BUTTON_KEY1)->SetFont(pFont);
	GetDlgItem(IDC_BUTTON_KEY0)->SetFont(pFont);
	GetDlgItem(IDC_BUTTON_KEY_DOC)->SetFont(pFont);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
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
	m_edit->GetParent()->SetFocus();

	CInkSystemDlg* pardlg;
	if ( m_dlgNum == InkParDlg )
	{
		pardlg = (CInkSystemDlg*)(m_edit->GetParent()->GetParent());
		pardlg->m_par->m_parPressureStatic.SetFocus();
	}
	else if ( m_dlgNum == InkPhasingDlg )
	{
		pardlg = (CInkSystemDlg*)(m_edit->GetParent()->GetParent());
		pardlg->m_phas->m_fixedStatic.SetFocus();
	}

	CCodePrinterDlg* dlg;
	dlg = (CCodePrinterDlg*)(m_pCodePrinterDlg);

	delete dlg->m_pNumKey;
	dlg->m_pNumKey = NULL;
	m_edit = NULL;

	// TODO: 在此添加控件通知处理程序代码
}
void CNumKey::OnBnClickedButtonKeyOk()
{
	// TODO: 在此添加控件通知处理程序代码
	m_edit->GetParent()->SetFocus();

	CInkSystemDlg* pardlg;
	if ( m_dlgNum == InkParDlg )
	{
		pardlg = (CInkSystemDlg*)(m_edit->GetParent()->GetParent());
		pardlg->m_par->m_parPressureStatic.SetFocus();
	}
	else if ( m_dlgNum == InkPhasingDlg )
	{
		pardlg = (CInkSystemDlg*)(m_edit->GetParent()->GetParent());
		pardlg->m_phas->m_fixedStatic.SetFocus();
	}

	CCodePrinterDlg* dlg;
	dlg = (CCodePrinterDlg*)(m_pCodePrinterDlg);

	delete dlg->m_pNumKey;
	dlg->m_pNumKey = NULL;
	m_edit = NULL;

}
void CNumKey::OnBnClickedButtonKeyDel()
{
	// TODO: 在此添加控件通知处理程序代码
	int nPosStart;
	int nPosEnd  = 0; 
	m_edit->GetSel(nPosStart, nPosEnd); 
	m_edit->SetSel(nPosStart-1, nPosStart);                            
	m_edit->ReplaceSel(_T(""));

}



void CNumKey::OnBnClickedButtonKeyLeft()
{
	// TODO: 在此添加控件通知处理程序代码
	int nPosStart;
	int nPosEnd  = 0; 
	m_edit->GetSel(nPosStart, nPosEnd); 
	m_edit->SetSel(nPosStart-1, nPosStart-1);
	m_edit->SetFocus();
}

void CNumKey::OnBnClickedButtonKeyRight()
{
	// TODO: 在此添加控件通知处理程序代码
	int nPosStart;
	int nPosEnd  = 0; 
	m_edit->GetSel(nPosStart, nPosEnd); 
	m_edit->SetSel(nPosStart+1, nPosStart+1); 
	m_edit->SetFocus();
}
void CNumKey::OnBnClickedButtonKey7()
{
	// TODO: 在此添加控件通知处理程序代码
	CString tempstr;
	GetDlgItem(IDC_BUTTON_KEY7)->GetWindowText(tempstr);
	setEditNum( tempstr );
}
void CNumKey::OnBnClickedButtonKey8()
{
	// TODO: 在此添加控件通知处理程序代码
	CString tempstr;
	GetDlgItem(IDC_BUTTON_KEY8)->GetWindowText(tempstr);
	setEditNum( tempstr );
}



void CNumKey::OnBnClickedButtonKey9()
{
	// TODO: 在此添加控件通知处理程序代码
	CString tempstr;
	GetDlgItem(IDC_BUTTON_KEY9)->GetWindowText(tempstr);
	setEditNum( tempstr );
}
void CNumKey::OnBnClickedButtonKey6()
{
	// TODO: 在此添加控件通知处理程序代码
	CString tempstr;
	GetDlgItem(IDC_BUTTON_KEY6)->GetWindowText(tempstr);
	setEditNum( tempstr );
}
void CNumKey::OnBnClickedButtonKey5()
{
	// TODO: 在此添加控件通知处理程序代码
	CString tempstr;
	GetDlgItem(IDC_BUTTON_KEY5)->GetWindowText(tempstr);
	setEditNum( tempstr );
}
void CNumKey::OnBnClickedButtonKey4()
{
	// TODO: 在此添加控件通知处理程序代码
	CString tempstr;
	GetDlgItem(IDC_BUTTON_KEY4)->GetWindowText(tempstr);
	setEditNum( tempstr );
}
void CNumKey::OnBnClickedButtonKey3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString tempstr;
	GetDlgItem(IDC_BUTTON_KEY3)->GetWindowText(tempstr);
	setEditNum( tempstr );
}
void CNumKey::OnBnClickedButtonKey2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString tempstr;
	GetDlgItem(IDC_BUTTON_KEY2)->GetWindowText(tempstr);
	setEditNum( tempstr );
}
void CNumKey::OnBnClickedButtonKey1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString tempstr;
	GetDlgItem(IDC_BUTTON_KEY1)->GetWindowText(tempstr);
	setEditNum( tempstr );
}
void CNumKey::OnBnClickedButtonKey0()
{
	// TODO: 在此添加控件通知处理程序代码
	CString tempstr;
	GetDlgItem(IDC_BUTTON_KEY0)->GetWindowText(tempstr);
	setEditNum( tempstr );
}
void CNumKey::OnBnClickedButtonKeyDoc()
{
	// TODO: 在此添加控件通知处理程序代码
	CString tempstr;
	GetDlgItem(IDC_BUTTON_KEY_DOC)->GetWindowText(tempstr);
	setEditNum( tempstr );
}