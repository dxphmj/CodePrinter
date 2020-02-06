// EditTextDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "EditTextDlg.h"

//#include "..\KEYBOARD\KEYBOARD\ExportDlg.h"
//#include "ModuleMain.h"
// CEditTextDlg �Ի���

IMPLEMENT_DYNAMIC(CEditTextDlg, CDialog)

CEditTextDlg::CEditTextDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditTextDlg::IDD, pParent)
{

}

CEditTextDlg::~CEditTextDlg()
{
}

void CEditTextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, Combo_Font, fontComboBox);
	DDX_Control(pDX, IDC_EDITTEXT_CLOSE_BTN, m_returnIB);
	DDX_Control(pDX, IDC_BUTTON_EDITOK, m_okIB);
	DDX_Control(pDX, Static_Text, m_textStatic);
	DDX_Control(pDX, Static_Font, m_fontStatic);
	DDX_Control(pDX, Static_DataField, m_dataFieldStatic);
	DDX_Control(pDX, IDC_EDIT1, m_textEdit);
}


BEGIN_MESSAGE_MAP(CEditTextDlg, CDialog)
	ON_BN_CLICKED(IDC_EDITTEXT_CLOSE_BTN, &CEditTextDlg::OnBnClickedEdittextCloseBtn)
	ON_EN_CHANGE(IDC_EDIT1, &CEditTextDlg::OnEnChangeEdit1)
	ON_CBN_SELCHANGE(Combo_Font, &CEditTextDlg::OnCbnSelchangeFont)
	ON_BN_CLICKED(IDC_BUTTON_EDITOK, &CEditTextDlg::OnBnClickedButtonEditok)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CEditTextDlg ��Ϣ�������

BOOL CEditTextDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	fontComboBox.AddString(_T("5x5"));
	fontComboBox.AddString(_T("7x5"));
	fontComboBox.AddString(_T("12x12"));
	fontComboBox.AddString(_T("16x12"));
	fontComboBox.SetCurSel(1);
	fontComboBox.SetFont(theApp.m_ListBoxFont); //��������������
	fontComboBox.SendMessage(CB_SETITEMHEIGHT,-1,30);//����������߶�
	fontComboBox.SendMessage(CB_SETITEMHEIGHT,0,30);//������������Ŀ�߶�

	GetDlgItem(IDC_EDITTEXT_CLOSE_BTN)->SetWindowPos(NULL,20,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_EDITOK)->SetWindowPos(NULL,700,390,70,45,SWP_SHOWWINDOW);

	m_returnIB.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_returnIB.SizeToContent(); 
	m_okIB.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_okIB.SizeToContent(); 

	m_textEdit.SetFont(theApp.m_EditFont);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CEditTextDlg::OnBnClickedEdittextCloseBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->ShowWindow(SW_HIDE);
}

void CEditTextDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	//CEdit* pBoxOne;
	//pBoxOne = (CEdit*) GetDlgItem(IDC_EDIT1);
	//CString str;
	//pBoxOne-> GetWindowText(str);

	//CExportDlg myCExportDlg;
	////CString ts;
	////ts.Format(L"%s",_T("sdfsa"));
	//str=myCExportDlg.GetInputText(str);
 //   pBoxOne-> SetWindowText(str);

}

BOOL CEditTextDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	ASSERT(pEdit && pEdit->GetSafeHwnd());
	if(WM_LBUTTONDOWN == pMsg->message && pEdit->GetSafeHwnd() == pMsg->hwnd)
	{
		//pEdit->SetFocus();
		//pEdit->SetSel(-1);
		CString str;
		pEdit-> GetWindowText(str);

		CExportDlg myCExportDlg;
		//CString ts;
		//ts.Format(L"%s",_T("sdfsa"));
		str=myCExportDlg.GetInputText(str);
		pEdit-> SetWindowText(str);
		return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CEditTextDlg::OnCbnSelchangeFont()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

}

void CEditTextDlg::OnBnClickedButtonEditok()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (theApp.bochange)
	{
		for(int i=0;i<theApp.myclassMessage.OBJ_Vec.size();i++)
		{
			if (theApp.myclassMessage.OBJ_Vec.at(i)->booFocus)
			{
				CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
				CString strText;
				pEdit-> GetWindowText(strText);
				//tempObj.strText=theApp.myModuleMain.CString2string(strText);
				theApp.myclassMessage.OBJ_Vec[i]->strText=theApp.myModuleMain.UnicodeToUtf8_CSTR(strText);
				CString  fontText;
				int nIndex = fontComboBox.GetCurSel();  //��ǰѡ�е���
				switch(nIndex)
				{
				case 0:
					theApp.myclassMessage.OBJ_Vec[i]->intLineSize=5;
					theApp.myclassMessage.OBJ_Vec[i]->intRowSize=strText.GetLength()*6;//////////���Ǹ��ӣ�ע�Ⱒ������Ҫ����
					break;
				case 1:
					theApp.myclassMessage.OBJ_Vec[i]->intLineSize=7;
					theApp.myclassMessage.OBJ_Vec[i]->intRowSize=strText.GetLength()*6;//////////���Ǹ��ӣ�ע�Ⱒ������Ҫ����
					break;
				case 2:
					theApp.myclassMessage.OBJ_Vec[i]->intLineSize=12;
					theApp.myclassMessage.OBJ_Vec[i]->intRowSize=strText.GetLength()*13;//////////���Ǹ��ӣ�ע�Ⱒ������Ҫ����
					break;
				case 3:
					theApp.myclassMessage.OBJ_Vec[i]->intLineSize=16;
					theApp.myclassMessage.OBJ_Vec[i]->intRowSize=strText.GetLength()*13;//////////���Ǹ��ӣ�ע�Ⱒ������Ҫ����
					break;
				}
				fontComboBox.GetLBText(nIndex,fontText);


				if ((theApp.myclassMessage.OBJ_Vec[i]->intRowStart+theApp.myclassMessage.OBJ_Vec[i]->intRowSize)>theApp.myclassMessage.scrMaxRow)
				{
					theApp.myclassMessage.scrMaxRow=theApp.myclassMessage.OBJ_Vec[i]->intRowStart+theApp.myclassMessage.OBJ_Vec[i]->intRowSize;
				}

				theApp.myclassMessage.OBJ_Vec[i]->strFont=theApp.myModuleMain.CString2string(fontText);

				break;
			}
		}
		theApp.bochange=false;
		this->ShowWindow(SW_HIDE);
		return;
	}
	int xPos=0;
	int yPos=0;
	for(int i=0;i<theApp.myclassMessage.OBJ_Vec.size();i++)
	{
		if (theApp.myclassMessage.OBJ_Vec.at(i)->booFocus)
		{
			theApp.myclassMessage.OBJ_Vec.at(i)->booFocus=false;
			yPos=theApp.myclassMessage.OBJ_Vec.at(i)->intLineStart;
			xPos=theApp.myclassMessage.OBJ_Vec.at(i)->intRowSize+theApp.myclassMessage.OBJ_Vec.at(i)->intRowStart;
			break;
		}
	}
	OBJ_Control* tempObj = new OBJ_Control;
	tempObj->intLineStart=yPos;
	tempObj->intRowStart=xPos;
	tempObj->strType1="text";
	tempObj->strType2="text";
	//������д��
	tempObj->intSW=1;
	tempObj->intSS=0;
	tempObj->booNEG=false;
	tempObj->booBWDx=false;
	tempObj->booBWDy=false;
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
	CString strText;
	pEdit->GetWindowText(strText);
	//tempObj.strText=theApp.myModuleMain.CString2string(strText);
	tempObj->strText=theApp.myModuleMain.UnicodeToUtf8_CSTR(strText);
	//USES_CONVERSION;
	////����T2A��W2A��֧��ATL��MFC�е��ַ�
	////char * pFileName = T2A(str);  
	//const char * tempTEXT = W2A(strText.GetBuffer(0));
	//tempObj.strText=tempTEXT;
	//delete tempTEXT;
	//tempObj.strText="�й�";
	CString  fontText;
	int nIndex = fontComboBox.GetCurSel();  //��ǰѡ�е���
	switch(nIndex)
	{
	case 0:
		tempObj->intLineSize=5;
		tempObj->intRowSize=strText.GetLength()*6;//////////���Ǹ��ӣ�ע�Ⱒ������Ҫ����
		break;
	case 1:
		tempObj->intLineSize=7;
		tempObj->intRowSize=strText.GetLength()*6;//////////���Ǹ��ӣ�ע�Ⱒ������Ҫ����
		break;
	case 2:
		tempObj->intLineSize=12;
		tempObj->intRowSize=strText.GetLength()*13;//////////���Ǹ��ӣ�ע�Ⱒ������Ҫ����
		break;
	case 3:
		tempObj->intLineSize=16;
		tempObj->intRowSize=strText.GetLength()*13;//////////���Ǹ��ӣ�ע�Ⱒ������Ҫ����
		break;
	}
	fontComboBox.GetLBText(nIndex,fontText);
	tempObj->strFont=theApp.myModuleMain.CString2string(fontText);



	if ((tempObj->intRowStart+tempObj->intRowSize)>theApp.myclassMessage.scrMaxRow)
	{
		theApp.myclassMessage.scrMaxRow=tempObj->intRowStart+tempObj->intRowSize;
	}


	tempObj->booFocus=true;

	theApp.myclassMessage.OBJ_Vec.push_back(tempObj);
	this->ShowWindow(SW_HIDE);
}

HBRUSH CEditTextDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	if(nCtlColor == CTLCOLOR_STATIC)
	{		 
		pDC->SelectObject(theApp.m_StaticFont);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));	
		return theApp.m_StaticBrush;
	}
	if(nCtlColor == CTLCOLOR_EDIT)
	{ 
	// 	pDC->SelectObject(theApp.m_EditFont);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));	
		return theApp.m_StaticBrush;
	}
	// TODO:  �ڴ˸��� DC ���κ�����
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return theApp.m_DlgBrush;
}