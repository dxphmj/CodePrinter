// BarCodeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "BarCodeDlg.h"


// CBarCodeDlg 对话框

IMPLEMENT_DYNAMIC(CBarCodeDlg, CDialog)

CBarCodeDlg::CBarCodeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBarCodeDlg::IDD, pParent)
{

}

CBarCodeDlg::~CBarCodeDlg()
{
}

void CBarCodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBarCodeDlg, CDialog)
	

	ON_BN_CLICKED(IDC_BARCODE_CLOSE_BTN, &CBarCodeDlg::OnBnClickedBarcodeCloseBtn)
	ON_BN_CLICKED(IDC_QR_CODE_BTN, &CBarCodeDlg::OnBnClickedQrCodeBtn)
	ON_BN_CLICKED(IDC_DATA_MATRIX_BTN, &CBarCodeDlg::OnBnClickedDataMatrixBtn)
END_MESSAGE_MAP()


// CBarCodeDlg 消息处理程序

BOOL CBarCodeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CBarCodeDlg::OnBnClickedBarcodeCloseBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
}

void CBarCodeDlg::OnBnClickedQrCodeBtn()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CBarCodeDlg::OnBnClickedDataMatrixBtn()
{
	// TODO: 在此添加控件通知处理程序代码
}
