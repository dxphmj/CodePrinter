// OnOffDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "OnOffDlg.h"
#include "CodePrinterDlg.h"

// COnOffDlg �Ի���

IMPLEMENT_DYNAMIC(COnOffDlg, CDialog)

COnOffDlg::COnOffDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COnOffDlg::IDD, pParent)
{

}

COnOffDlg::~COnOffDlg()
{
}

void COnOffDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RETURN_BTN, m_ButReturn);
	DDX_Control(pDX, IDC_SEQUENCE_BTN, m_ButSequence);
	DDX_Control(pDX, IDC_FAST_BTN, m_ButFast);
}


BEGIN_MESSAGE_MAP(COnOffDlg, CDialog)
#if defined(_DEVICE_RESOLUTION_AWARE) && !defined(WIN32_PLATFORM_WFSP)
	ON_WM_SIZE()
#endif
	ON_BN_CLICKED(IDC_SEQUENCE_BTN, &COnOffDlg::OnBnClickedSequenceButton)
	ON_BN_CLICKED(IDC_FAST_BTN, &COnOffDlg::OnBnClickedFastButton)
	ON_BN_CLICKED(IDC_RETURN_BTN, &COnOffDlg::OnBnClickedReturnBtn)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// ��������
void COnOffDlg::OnBnClickedSequenceButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (theApp.myStatusClass.ctr0X00bit0==0)
	{
		theApp.myStatusClass.ctr0X00bit5 = 0;
		theApp.myStatusClass.ctr0X00bit3 = 0;
		theApp.myStatusClass.ctr0X00bit2 = 0;
		theApp.myStatusClass.ctr0X00bit1 = 0;
		theApp.myStatusClass.ctr0X00bit0 = 1;
	}
	else if (theApp.myStatusClass.ctr0X00bit0==1)
	{
		theApp.myStatusClass.ctr0X00bit5 = 0;
		theApp.myStatusClass.ctr0X00bit3 = 0;
		theApp.myStatusClass.ctr0X00bit2 = 0;
		theApp.myStatusClass.ctr0X00bit1 = 0;
		theApp.myStatusClass.ctr0X00bit0 = 0;
	}
	theApp.myStatusClass.download_inksystem_control00();
	this->OnCancel();
	//this->ShowWindow(SW_HIDE);
}
//���ٿ���
void COnOffDlg::OnBnClickedFastButton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (theApp.myStatusClass.ctr0X00bit0==0)
	{
		theApp.myStatusClass.ctr0X00bit5 = 0;
		theApp.myStatusClass.ctr0X00bit3 = 0;
		theApp.myStatusClass.ctr0X00bit2 = 0;
		theApp.myStatusClass.ctr0X00bit1 = 1;
		theApp.myStatusClass.ctr0X00bit0 = 1;
	}
	else if (theApp.myStatusClass.ctr0X00bit0==1)
	{
		theApp.myStatusClass.ctr0X00bit5 = 0;
		theApp.myStatusClass.ctr0X00bit3 = 0;
		theApp.myStatusClass.ctr0X00bit2 = 0;
		theApp.myStatusClass.ctr0X00bit1 = 1;
		theApp.myStatusClass.ctr0X00bit0 = 0;
	}
	theApp.myStatusClass.download_inksystem_control00();

	this->OnCancel();
	//this->ShowWindow(SW_HIDE);
}
void COnOffDlg::OnBnClickedReturnBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->OnCancel();
	//this->ShowWindow(SW_HIDE);
}

HBRUSH COnOffDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	pDC->SetBkColor(theApp.m_BKcolor);
	 
	return theApp.m_DlgBrush;
}

BOOL COnOffDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	//����Ӳ�ɫͼƬ
	m_ButReturn.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_70_45_BITMAP);
	m_ButReturn.SizeToContent(); 
	m_ButSequence.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_70_45_BITMAP,true);
	m_ButSequence.SizeToContent(); 
	m_ButFast.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_70_45_BITMAP,true);
	m_ButFast.SizeToContent(); 
	//������
	OnOffLanChange();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void COnOffDlg::OnOffLanChange()
{
	wstring lanStr;
	CString tempstr;
	CCodePrinterDlg *pCodeDlg = (CCodePrinterDlg*)this->GetParent();//��ȡ���Ի���ָ��

	lanStr=theApp.myLanguage.LanguageMap["IDC_SEQUENCE_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	GetDlgItem(IDC_SEQUENCE_BTN)->SetWindowText(tempstr);

	lanStr=theApp.myLanguage.LanguageMap["IDC_FAST_BTN"];
	tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
	GetDlgItem(IDC_FAST_BTN)->SetWindowText(tempstr);

	if (theApp.m_lastOnOffStatue = 0)//�ػ�
	{
		lanStr=theApp.myLanguage.LanguageMap["ID_ON_TITLE"];
		tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
		this->SetWindowText(tempstr);
	} 
	else if (theApp.m_lastOnOffStatue = 1)//����
	{
		lanStr=theApp.myLanguage.LanguageMap["ID_OFF_TITLE"];
		tempstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(lanStr.c_str());
		this->SetWindowText(tempstr);
	}
}
