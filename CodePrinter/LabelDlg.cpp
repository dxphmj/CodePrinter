// LabelDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "LabelDlg.h"
#include "InputDlg.h"


// CLabelDlg �Ի���

IMPLEMENT_DYNAMIC(CLabelDlg, CDialog)

CLabelDlg::CLabelDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLabelDlg::IDD, pParent)
{

}

CLabelDlg::~CLabelDlg()
{
}

void CLabelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_MATRIX, ComboMatrix);
}


BEGIN_MESSAGE_MAP(CLabelDlg, CDialog)
	ON_BN_CLICKED(IDC_INPUT_BUTTON, &CLabelDlg::OnBnClickedInputButton)
END_MESSAGE_MAP()


// CLabelDlg ��Ϣ�������

BOOL CLabelDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetWindowPos(NULL,0,0,800,600,SWP_SHOWWINDOW );	
	CRect rect;
	GetWindowRect(&rect);

	//Ϊ������Ͽ����Ԫ��
	//combo_matrix.SetDroppedWidth(10);  //�ı������б��µĿ�� 
	ComboMatrix.AddString(_T("1L5M"));
	ComboMatrix.AddString(_T("1L7M"));
	ComboMatrix.AddString(_T("1L9M"));
	ComboMatrix.AddString(_T("1L12M"));
	ComboMatrix.AddString(_T("1L19M"));
	ComboMatrix.AddString(_T("1L25M"));
	ComboMatrix.AddString(_T("2L7M"));
	ComboMatrix.SetCurSel(-1);


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CLabelDlg::OnBnClickedInputButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CInputDlg Input;
	Input.DoModal();
}
