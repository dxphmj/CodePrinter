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
	ON_BN_CLICKED(IDC_INPUT_CLOSE_BTN, &CInputDlg::OnBnClickedInputCloseBtn)
END_MESSAGE_MAP()


// CInputDlg 消息处理程序

BOOL CInputDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	pEditText = new CEditTextDlg;
	pEditFigure = new CEditFigureDlg;
	pDate = new CDateDlg;
	pPic = new CPictureDlg;
	pBarCode = new CBarCodeDlg;

	int nX = 0;
	int nY = 0;
	int nWidth = 800;
	int nHeight = 600;
	pEditText->Create(IDD_EDITTEXT_DIALOG,this);
	pEditText->MoveWindow(nX,nY,nWidth,nHeight);

	pEditFigure->Create(IDD_EDITFIGURE_DIALOG,this);
	pEditFigure->MoveWindow(nX,nY,nWidth,nHeight);
	pEditFigure->ShowWindow(SW_HIDE);

	pDate->Create(IDD_DATE_DIALOG,this);
	pDate->MoveWindow(nX,nY,nWidth,nHeight);
	pDate->ShowWindow(SW_HIDE);

	pPic->Create(IDD_PICTURE_DIALOG,this);
	pPic->MoveWindow(nX,nY,nWidth,nHeight);

	pBarCode->Create(IDD_BARCODE_DIALOG,this);
	pBarCode->MoveWindow(nX,nY,nWidth,nHeight);
	pBarCode->ShowWindow(SW_HIDE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CInputDlg::OnBnClickedEdittextButton()
{
	// TODO: 在此添加控件通知处理程序代码
	showInputDlg(IDD_EDITTEXT_DIALOG);
}

void CInputDlg::OnBnClickedEditfigureButton()
{
	// TODO: 在此添加控件通知处理程序代码
	showInputDlg(IDD_EDITFIGURE_DIALOG);
}

void CInputDlg::OnBnClickedEditdateButton()
{
	// TODO: 在此添加控件通知处理程序代码
	showInputDlg(IDD_DATE_DIALOG);
}

void CInputDlg::OnBnClickedEditpictureButton()
{
	// TODO: 在此添加控件通知处理程序代码
	showInputDlg(IDD_PICTURE_DIALOG);
}

void CInputDlg::OnBnClickedBarcodeButton()
{
	// TODO: 在此添加控件通知处理程序代码
	showInputDlg(IDD_BARCODE_DIALOG);
}

void CInputDlg::OnBnClickedInputCloseBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
}

void CInputDlg::showInputDlg(int ID)
{
	pEditText->ShowWindow(SW_HIDE);
	pEditFigure->ShowWindow(SW_HIDE);
	pDate->ShowWindow(SW_HIDE);
	pPic->ShowWindow(SW_HIDE);
	pBarCode->ShowWindow(SW_HIDE);

	if (ID ==IDD_EDITTEXT_DIALOG)
	{
		pEditText->ShowWindow(SW_SHOW);
	}
	else if (ID == IDD_EDITFIGURE_DIALOG)
	{
		pEditFigure->ShowWindow(SW_SHOW);
	}
	else if (ID == IDD_DATE_DIALOG)
	{
		pDate->ShowWindow(SW_SHOW);
	}
	else if (ID == IDD_PICTURE_DIALOG)
	{
		pPic->ShowWindow(SW_SHOW);
	}
	else if (ID == IDD_BARCODE_DIALOG)
	{
		pBarCode->ShowWindow(SW_SHOW);
	}
	
}
