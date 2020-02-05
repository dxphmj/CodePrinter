// OnOffDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "OnOffDlg.h"
#include "CodePrinterDlg.h"

#define ARABIC					0 
#define CHINESE_SIMPLIFIED		1
#define CHINESE_TRADITIONAL		2
#define CZECH					3
#define DUTCH					4
#define ENGLISH					5 
#define ESTONIAN				6 
#define FARSI					7 
#define FINNISH					8 
#define FRENCH					9 
#define GERMAN					10 
#define HINDI					11 
#define HUNGARIAN				12 
#define ITALIAN					13 
#define JAPANESE				14 
#define KANNADA					15 
#define KOREAN					16 
#define POLISH					17 
#define PORTUGUESE				18 
#define ROMANIAN				19 
#define RUSSIAN					20 
#define SERBIAN					21 
#define SPANISH					22 
#define SWEDISH					23 
#define TAMIL					24 
#define THAI					25 
#define TURKISH					26 
#define VIETNAMESE				27 
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
	CCodePrinterDlg *pCodeDlg = (CCodePrinterDlg*)this->GetParent();//��ȡ���Ի���ָ��
	int nIndex = pCodeDlg->m_System->pEvn->m_langeageList.GetCurSel();  //��ǰ����ѡ�е���
	wstring lanStr;
	switch(nIndex)
	{
	case CHINESE_SIMPLIFIED: //CHINESE_SIMPLIFIED
		lanStr=theApp.myLanguage.LanguageMap["IDC_SEQUENCE_BTN"];
		GetDlgItem(IDC_SEQUENCE_BTN)->SetWindowText(lanStr.c_str());
		lanStr=theApp.myLanguage.LanguageMap["IDC_FAST_BTN"];
		GetDlgItem(IDC_FAST_BTN)->SetWindowText(lanStr.c_str());
		break;
	case ENGLISH://ENGLISH
		lanStr=theApp.myLanguage.LanguageMap["IDC_SEQUENCE_BTN"];
		GetDlgItem(IDC_SEQUENCE_BTN)->SetWindowText(lanStr.c_str());
		lanStr=theApp.myLanguage.LanguageMap["IDC_FAST_BTN"];
		GetDlgItem(IDC_FAST_BTN)->SetWindowText(lanStr.c_str());
		break;
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
