// BarCodeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "BarCodeDlg.h"


// CBarCodeDlg �Ի���

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


// CBarCodeDlg ��Ϣ�������

BOOL CBarCodeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CBarCodeDlg::OnBnClickedBarcodeCloseBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->ShowWindow(SW_HIDE);
}

void CBarCodeDlg::OnBnClickedQrCodeBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CBarCodeDlg::OnBnClickedDataMatrixBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
