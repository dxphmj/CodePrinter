// InputDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "InputDlg.h"
#include "EditTextDlg.h"
#include "EditFigureDlg.h"
#include "DateDlg.h"
#include "PictureDlg.h"
#include "BarCodeDlg.h"

// CInputDlg �Ի���

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


// CInputDlg ��Ϣ�������

BOOL CInputDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetWindowPos(NULL,0,0,800,600,SWP_SHOWWINDOW );	
	CRect rect;
	GetWindowRect(&rect);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CInputDlg::OnBnClickedEdittextButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CEditTextDlg EditText;
	EditText.DoModal();
}

void CInputDlg::OnBnClickedEditfigureButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CEditFigureDlg EditFigure;
	EditFigure.DoModal();
}

void CInputDlg::OnBnClickedEditdateButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDateDlg Date;
	Date.DoModal();
}

void CInputDlg::OnBnClickedEditpictureButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CPictureDlg Picture;
	Picture.DoModal();
}

void CInputDlg::OnBnClickedBarcodeButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CBarCodeDlg BarCode;
	BarCode.DoModal();
}
