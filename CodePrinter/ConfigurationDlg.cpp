// ConfigurationDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "ConfigurationDlg.h"
#include "PcfConfig.h"
#include "CodePrinterDlg.h"
#include "..\PathDlgDll\PathDlgDll\PathDlgDll.h"
#include "BnvImage.h"

// CConfigurationDlg �Ի���

IMPLEMENT_DYNAMIC(CConfigurationDlg, CDialog)

CConfigurationDlg::CConfigurationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConfigurationDlg::IDD, pParent)
	, m_height(70)
	, m_dotPitch(0.423)
	, m_delay(100)
	, m_repeatDis(300)
	, m_speed(20)
{

}

CConfigurationDlg::~CConfigurationDlg()
{
}

void CConfigurationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_HEIGHT_EDIT, m_height);
	DDX_Control(pDX, IDC_REVERSE_COMBO, m_reverse);
	DDX_Control(pDX, IDC_INVERSE_COMBO, m_inverse);
	DDX_Text(pDX, IDC_DOT_PITCH_EDIT, m_dotPitch);
	DDX_Text(pDX, IDC_DELAY_EDIT, m_delay);
	DDX_Text(pDX, IDC_REPEAT_DIS_EDIT, m_repeatDis);
	DDX_Control(pDX, IDC_SPEED_WAY_COMBO, m_speedWay);
	DDX_Text(pDX, IDC_SPEED_EDIT, m_speed);

	DDX_Control(pDX, IDC_CONFI_CLOSE_BTN, m_returnIB);
	DDX_Control(pDX, IDC_PRINT_SET_BTN, m_printSetIB);
	DDX_Control(pDX, IDC_OUT_SET_BTN, m_outSetIB);
	DDX_Control(pDX, IDC_CONFI_OPEN_BTN, m_configOpenIB);
	DDX_Control(pDX, IDC_CONFI_SAVE_BTN, m_configSaveIB);
	DDX_Control(pDX, IDC_CONFIG_OK_BTN, m_configOkIB);
	DDX_Control(pDX, IDC_SPEED_EDIT, m_edit_speed);
	DDX_Control(pDX, IDC_DELAY_EDIT, m_edit_delay);
	DDX_Control(pDX, IDC_HEIGHT_EDIT, m_edit_height);
	DDX_Control(pDX, IDC_REPEAT_DIS_EDIT, m_edit_repeatDis);
	DDX_Control(pDX, IDC_DOT_PITCH_EDIT, m_edit_dotPitch);
}


BEGIN_MESSAGE_MAP(CConfigurationDlg, CDialog)
	ON_BN_CLICKED(IDC_CONFI_CLOSE_BTN, &CConfigurationDlg::OnBnClickedConfiCloseBtn)
	ON_BN_CLICKED(IDC_PRINT_SET_BTN, &CConfigurationDlg::OnBnClickedPrintSetBtn)
	ON_BN_CLICKED(IDC_OUT_SET_BTN, &CConfigurationDlg::OnBnClickedOutSetBtn)
	ON_BN_CLICKED(IDC_CONFIG_OK_BTN, &CConfigurationDlg::OnBnClickedSavePcf)

	ON_BN_CLICKED(IDC_CONFI_OPEN_BTN, &CConfigurationDlg::OnBnClickedConfiOpenBtn)
	ON_BN_CLICKED(IDC_CONFI_SAVE_BTN, &CConfigurationDlg::OnBnClickedConfiSaveBtn)

	ON_WM_CTLCOLOR()

	ON_CBN_SELCHANGE(IDC_INVERSE_COMBO, &CConfigurationDlg::OnCbnSelchangeInverseCombo)

	ON_EN_SETFOCUS(IDC_SPEED_EDIT, &CConfigurationDlg::OnEnSetfocusSpeedEdit)
	ON_EN_SETFOCUS(IDC_DELAY_EDIT, &CConfigurationDlg::OnEnSetfocusDelayEdit)

	ON_CBN_SELCHANGE(IDC_REVERSE_COMBO, &CConfigurationDlg::OnCbnSelchangeReverseCombo)
	ON_WM_PAINT()
	ON_EN_CHANGE(IDC_DELAY_EDIT, &CConfigurationDlg::OnEnChangeDelayEdit)

	ON_EN_SETFOCUS(IDC_HEIGHT_EDIT, &CConfigurationDlg::OnEnSetfocusHeightEdit)
	ON_EN_SETFOCUS(IDC_REPEAT_DIS_EDIT, &CConfigurationDlg::OnEnSetfocusRepeatDisEdit)
	ON_EN_SETFOCUS(IDC_DOT_PITCH_EDIT, &CConfigurationDlg::OnEnSetfocusDotPitchEdit)
END_MESSAGE_MAP()


// CConfigurationDlg ��Ϣ�������

BOOL CConfigurationDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

    //��ť�����ʼ��
	m_ConfigPM= new CConfigPrintModeDlg;
	m_ConfigOS = new CConfigOutSetDlg;
	int nX = 0;
	int nY = 75;
	int nWidth = 800;
	int nHeight = 525;
	
	m_ConfigPM->Create(IDD_CONFIG_PRINT_MODE_DIALOG,this);
	m_ConfigPM->MoveWindow(nX,nY,nWidth,nHeight);
	m_ConfigPM->ShowWindow(SW_HIDE);
    theApp.SetProgressBar(35);
 	m_ConfigOS->Create(IDD_CONFIG_OUTSET_DIALOG,this);
	m_ConfigOS->MoveWindow(nX,nY,nWidth,nHeight);
	m_ConfigOS->ShowWindow(SW_HIDE);
	theApp.SetProgressBar(40);
 
	m_reverse.AddString(L"OFF");
	m_reverse.AddString(L"ON");
	m_reverse.SetCurSel(0);

	m_inverse.AddString(L"OFF");
	m_inverse.AddString(L"ON");
	m_inverse.SetCurSel(0);

	m_speedWay.AddString(L"Fixed");
	m_speedWay.AddString(L"Variable");
	m_speedWay.SetCurSel(0);

	CRect rect1;
	GetDlgItem(IDC_CONFI_CLOSE_BTN)->GetWindowRect(&rect1);

	int nBottomButtonHeight = 420;

	GetDlgItem(IDC_CONFI_CLOSE_BTN)->SetWindowPos(NULL,11,nBottomButtonHeight,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_PRINT_SET_BTN)->SetWindowPos(NULL,200,nBottomButtonHeight,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_OUT_SET_BTN)->SetWindowPos(NULL,300,nBottomButtonHeight,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_CONFI_OPEN_BTN)->SetWindowPos(NULL,400,nBottomButtonHeight,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_CONFI_SAVE_BTN)->SetWindowPos(NULL,500,nBottomButtonHeight,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_CONFIG_OK_BTN)->SetWindowPos(NULL,700,nBottomButtonHeight,70,45,SWP_SHOWWINDOW);

	m_returnIB.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RETURN1_BITMAP);
	m_returnIB.SizeToContent(); 
	m_printSetIB.LoadBitmaps(IDB_PRINT_SET1_BITMAP,IDB_PRINT_SET2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_printSetIB.SizeToContent(); 
	m_outSetIB.LoadBitmaps(IDB_OUT_SET1_BITMAP,IDB_OUT_SET2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_outSetIB.SizeToContent(); 
	m_configOpenIB.LoadBitmaps(IDB_CONFIG_OPEN1_BITMAP,IDB_CONFIG_OPEN2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_configOpenIB.SizeToContent(); 
	m_configSaveIB.LoadBitmaps(IDB_SAVE1_BITMAP,IDB_SAVE2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_configSaveIB.SizeToContent(); 
	m_configOkIB.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_OK1_BITMAP);
	m_configOkIB.SizeToContent(); 


	

	m_edit_height.SetFont(theApp.m_EditFont);
	m_edit_repeatDis.SetFont(theApp.m_EditFont);
	m_edit_dotPitch.SetFont(theApp.m_EditFont);
	m_edit_delay.SetFont(theApp.m_EditFont);
	m_edit_speed.SetFont(theApp.m_EditFont);
	theApp.SetProgressBar(45);
	//////////////////////////////////////////////////////////////////////////
	for(int i = 0; i < 8; i++)
	{
		CBnvImage PngImage;
		PngImage.LoadFromResource(MAKEINTRESOURCE(IDB_SETUP_017+i), _T("PNG")); 
		m_HBitmap[i] = PngImage.CreatHBitmap(); 
	}
	m_nPcfPic = IDB_SETUP_017-IDB_SETUP_017;;
	pcf_diagram_select(); 
	
	m_reverse.SetFont(theApp.m_ListBoxFont); //��������������
	m_inverse.SetFont(theApp.m_ListBoxFont);
	m_speedWay.SetFont(theApp.m_ListBoxFont);

	m_reverse.SendMessage(CB_SETITEMHEIGHT,-1,25);//����������߶�
	m_reverse.SendMessage(CB_SETITEMHEIGHT,0,25);//������������Ŀ�߶�

	m_inverse.SendMessage(CB_SETITEMHEIGHT,-1,25);
	m_inverse.SendMessage(CB_SETITEMHEIGHT,0,25);

	m_speedWay.SendMessage(CB_SETITEMHEIGHT,-1,25);
	m_speedWay.SendMessage(CB_SETITEMHEIGHT,0,25);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CConfigurationDlg::OnBnClickedConfiCloseBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->ShowWindow(SW_HIDE);
	showConfigDlg(0);
	((CCodePrinterDlg*)GetParent())->m_PicHead.ShowLogo(true); 
}

void CConfigurationDlg::showConfigDlg(int ID)
{
	m_ConfigPM->ShowWindow(SW_HIDE);
	m_ConfigOS->ShowWindow(SW_HIDE);
	wstring tempstr1,tempstr2;
	CString cstr1,cstr2;
	if (ID == IDD_CONFIG_PRINT_MODE_DIALOG)
	{
		tempstr1 = theApp.myLanguage.LanguageMap["ID_CONFIGURATION_MANAGEMENT"];
		tempstr2 = theApp.myLanguage.LanguageMap["ID_CONFIGURATION_PRINTMODE"];
		cstr1 = tempstr1.c_str();
		cstr2 = tempstr2.c_str();
		m_ConfigPM->ShowWindow(SW_SHOW);
		((CCodePrinterDlg*)GetParent())->m_PicHead.SetOperationString(cstr1+_T(" > ")+cstr2); 
	}
	else if (ID == IDD_CONFIG_OUTSET_DIALOG)
	{
		tempstr1 = theApp.myLanguage.LanguageMap["ID_CONFIGURATION_MANAGEMENT"];
		tempstr2 = theApp.myLanguage.LanguageMap["ID_CONFIGURATION_OUTSET"];
		cstr1 = tempstr1.c_str();
		cstr2 = tempstr2.c_str();
		m_ConfigOS->ShowWindow(SW_SHOW);
		((CCodePrinterDlg*)GetParent())->m_PicHead.SetOperationString(cstr1+_T(" > ")+cstr2); 

	}	 
	else if (ID == IDC_CONFI_OPEN_BTN)
	{
		tempstr1 = theApp.myLanguage.LanguageMap["ID_OPEN_CONFIGURATION"];
		cstr1 = tempstr1.c_str();
		m_ConfigOS->ShowWindow(SW_SHOW);
		((CCodePrinterDlg*)GetParent())->m_PicHead.SetOperationString(cstr1); 

	}	 
	else if (ID == IDC_CONFI_SAVE_BTN)
	{
		tempstr1 = theApp.myLanguage.LanguageMap["ID_NEW_CONFIGURATION"];
		cstr1 = tempstr1.c_str();
		m_ConfigOS->ShowWindow(SW_SHOW);
		((CCodePrinterDlg*)GetParent())->m_PicHead.SetOperationString(cstr1); 

	}	 
}

void CConfigurationDlg::OnBnClickedPrintSetBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	showConfigDlg(IDD_CONFIG_PRINT_MODE_DIALOG);
}

void CConfigurationDlg::OnBnClickedOutSetBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	showConfigDlg(IDD_CONFIG_OUTSET_DIALOG);
}

void CConfigurationDlg::OnBnClickedSavePcf()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	//���汣�浽Ŀǰ����ӡ����xml�ļ���pcf�ļ���  
	CPcfConfig pPcfConfig((CCodePrinterDlg*)(this->GetParent()));
	pPcfConfig.save_pcf_to_xml();
	pPcfConfig.get_pcf_from_xml();
	pPcfConfig.download_pcf();
	theApp.m_MessageEdit.SerialCountNew = false;
	//CString tempNum;
	CCodePrinterDlg* mainDlg=(CCodePrinterDlg*)GetParent();
	mainDlg->m_Label->CreatePrintData();
	mainDlg->GetDlgItem(IDC_STATIC_PCFNAME)->SetWindowText(pcfNameDlg);
}


void CConfigurationDlg::OnBnClickedConfiOpenBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TCHAR path[MAX_PATH];
	//labModule.string2tchar(testpath,path);
	//���ı�ͷ
	wstring tempstr1;
	CString cstr1;
	tempstr1 = theApp.myLanguage.LanguageMap["ID_OPEN_CONFIGURATION"];
	cstr1 = tempstr1.c_str();
	((CCodePrinterDlg*)GetParent())->m_PicHead.SetOperationString(cstr1); 
	//////////////////////////////////////////////////////////////////////////
	string xmlPath;
	if(ShowPathDlg(path, MAX_PATH,3))
	{
		//AfxMessageBox(path);
		xmlPath=theApp.myModuleMain.TCHAR2STRING(path);
		//xmlPath+="sss.xml";
		//m_MessageEdit.SaveObjectsToXml("\\Storage Card\\user\\Label\\sss.xml");
		//theApp.m_MessageEdit.ReadObjectsFromXml(const_cast<char*>(xmlPath.c_str()));
		CPcfConfig pPcfConfig((CCodePrinterDlg*)(this->GetParent()));
		pPcfConfig.getPcfFromXml(xmlPath);
		pcfNameDlg=pPcfConfig.m_pcfName;

	}
	
	//
}

void CConfigurationDlg::OnBnClickedConfiSaveBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TCHAR path[MAX_PATH];
	//labModule.string2tchar(testpath,path);
	//���ı�ͷ
	wstring tempstr1;
	CString cstr1;
	tempstr1 = theApp.myLanguage.LanguageMap["ID_NEW_CONFIGURATION"];
	cstr1 = tempstr1.c_str();
	((CCodePrinterDlg*)GetParent())->m_PicHead.SetOperationString(cstr1); 
	//////////////////////////////////////////////////////////////////////////
	string xmlPath;
	if(ShowPathDlg(path, MAX_PATH,3))
	{
		//AfxMessageBox(path);
		xmlPath=theApp.myModuleMain.TCHAR2STRING(path);
		//xmlPath+="sss.xml";
		//m_MessageEdit.SaveObjectsToXml("\\Storage Card\\user\\Label\\sss.xml");
		//theApp.m_MessageEdit.ReadObjectsFromXml(const_cast<char*>(xmlPath.c_str()));
		CPcfConfig pPcfConfig((CCodePrinterDlg*)(this->GetParent()));
		pPcfConfig.savePcfToXml(xmlPath);//�˴���Ҫ�ܴ���xml
		pcfNameDlg=pPcfConfig.m_pcfName;
	}
	tempstr1 = theApp.myLanguage.LanguageMap["ID_CONFIGURATION_MANAGEMENT"];
	cstr1 = tempstr1.c_str();
	((CCodePrinterDlg*)GetParent())->m_PicHead.SetOperationString(cstr1); 
}

HBRUSH CConfigurationDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	if(nCtlColor == CTLCOLOR_STATIC)
	{		 
		pDC->SelectObject(theApp.m_StaticFont);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));	
	}

	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return theApp.m_DlgBrush;
}

void CConfigurationDlg::pcf_diagram_select()
{
	if(m_ConfigPM->m_printMode.GetCurSel() == 0) //��Ъ��ӡ
	{
		if(m_reverse.GetCurSel() == 0) 
		{
			if(m_inverse.GetCurSel() == 0)
			{
				m_nPcfPic = IDB_SETUP_017-IDB_SETUP_017;

			}
			else
			{
				m_nPcfPic = IDB_SETUP_019-IDB_SETUP_017;

			}
		}
		else
		{
			if(m_inverse.GetCurSel() == 0)
			{
				m_nPcfPic = IDB_SETUP_018-IDB_SETUP_017;

			}
			else
			{
				m_nPcfPic = IDB_SETUP_020-IDB_SETUP_017;
			}
		}
	}
	else //������ӡ
	{
		if(m_reverse.GetCurSel() == 0)
		{
			if(m_inverse.GetCurSel() == 0)
			{
				m_nPcfPic = IDB_SETUP_021-IDB_SETUP_017;

			}
			else
			{
				m_nPcfPic = IDB_SETUP_023-IDB_SETUP_017;

			}
		}
		else
		{
			if(m_inverse.GetCurSel() == 0)
			{
				m_nPcfPic = IDB_SETUP_024-IDB_SETUP_017;

			}
			else
			{
				m_nPcfPic = IDB_SETUP_022-IDB_SETUP_017;
			}
		}
	}
	Invalidate();	 
}

void CConfigurationDlg::OnCbnSelchangeInverseCombo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	pcf_diagram_select();
}



void CConfigurationDlg::OnCbnSelchangeReverseCombo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	pcf_diagram_select();
}

void CConfigurationDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	CRect   rect(0,0,800,420);  
	CDC   dcBmp;             //���岢����һ���ڴ��豸����
	dcBmp.CreateCompatibleDC(&dc);             //����������DC
	CBitmap   bmpBackground;
	bmpBackground.Attach(m_HBitmap[m_nPcfPic]); 

	//��λͼѡ����ʱ�ڴ��豸����
	CBitmap  *pbmpOld = dcBmp.SelectObject(&bmpBackground);

	//���ú�����ʾͼƬStretchBlt��ʾ��״�ɱ�
	dc.BitBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0, SRCCOPY);
	dcBmp.SelectObject(pbmpOld);
	bmpBackground.Detach();	
}

void CConfigurationDlg::OnEnChangeDelayEdit()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������

}

void CConfigurationDlg::OnEnSetfocusHeightEdit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CEdit *pEdit = &m_edit_height;

	CCodePrinterDlg* dlg;
	dlg = (CCodePrinterDlg*)(GetParent());
	dlg->OpenNumKeyBoard(pEdit);
}

void CConfigurationDlg::OnEnSetfocusRepeatDisEdit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CEdit *pEdit = &m_edit_repeatDis;

	CCodePrinterDlg* dlg;
	dlg = (CCodePrinterDlg*)(GetParent());
	dlg->OpenNumKeyBoard(pEdit);
}

void CConfigurationDlg::OnEnSetfocusDotPitchEdit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CEdit *pEdit = &m_edit_dotPitch;

	CCodePrinterDlg* dlg;
	dlg = (CCodePrinterDlg*)(GetParent());
	dlg->OpenNumKeyBoard(pEdit);
}
void CConfigurationDlg::OnEnSetfocusSpeedEdit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CEdit *pEdit = &m_edit_speed;

	CCodePrinterDlg* dlg;
	dlg = (CCodePrinterDlg*)(GetParent());
	dlg->OpenNumKeyBoard(pEdit);
}

void CConfigurationDlg::OnEnSetfocusDelayEdit()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CEdit *pEdit = &m_edit_delay;

	CCodePrinterDlg* dlg;
	dlg = (CCodePrinterDlg*)(GetParent());
	dlg->OpenNumKeyBoard(pEdit);
}