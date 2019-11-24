// InputDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "InputDlg.h"
#include "EditTextDlg.h"
#include "EditFigureDlg.h"
#include "DateDlg.h"
#include "PictureDlg.h"
#include "BarCodeDlg.h"

// CInputDlg 对话框

IMPLEMENT_DYNAMIC(CInputDlg, CDialog)

CInputDlg::CInputDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInputDlg::IDD, pParent)
{

}

CInputDlg::~CInputDlg()
{
}

void CInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInputDlg, CDialog)
	ON_BN_CLICKED(IDC_EDITTEXT_BUTTON, &CInputDlg::OnBnClickedEdittextButton)
	ON_BN_CLICKED(IDC_EDITFIGURE_BUTTON, &CInputDlg::OnBnClickedEditfigureButton)
	ON_BN_CLICKED(IDC_EDITDATE_BUTTON, &CInputDlg::OnBnClickedEditdateButton)
	ON_BN_CLICKED(IDC_EDITPICTURE_BUTTON, &CInputDlg::OnBnClickedEditpictureButton)
	ON_BN_CLICKED(IDC_BARCODE_BUTTON, &CInputDlg::OnBnClickedBarcodeButton)
END_MESSAGE_MAP()


// CInputDlg 消息处理程序

BOOL CInputDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetWindowPos(NULL,0,0,800,600,SWP_SHOWWINDOW );	
	CRect rect;
	GetWindowRect(&rect);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CInputDlg::OnBnClickedEdittextButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CEditTextDlg EditText;
	EditText.DoModal();
}

void CInputDlg::OnBnClickedEditfigureButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CEditFigureDlg EditFigure;
	EditFigure.DoModal();
}

void CInputDlg::OnBnClickedEditdateButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CDateDlg Date;
	Date.DoModal();
}

void CInputDlg::OnBnClickedEditpictureButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CPictureDlg Picture;
	Picture.DoModal();
}

void CInputDlg::OnBnClickedBarcodeButton()
{
	// TODO: 在此添加控件通知处理程序代码
	CBarCodeDlg BarCode;
	BarCode.DoModal();
}
