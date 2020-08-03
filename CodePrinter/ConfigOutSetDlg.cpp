// ConfigOutSet.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "ConfigOutSetDlg.h"
#include "CodePrinterDlg.h"
#include <math.h>

// CConfigOutSet 对话框

IMPLEMENT_DYNAMIC(CConfigOutSetDlg, CDialog)

CConfigOutSetDlg::CConfigOutSetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConfigOutSetDlg::IDD, pParent)
	,m_currentLevelStr("High")
	, m_intImpulse(0)
	, m_intLength(0)
	, m_intTriggerLen(0)
{
        
}

CConfigOutSetDlg::~CConfigOutSetDlg()
{
}

void CConfigOutSetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX,IDC_PRINT_DIRE_LIST,m_printDire);
	DDX_Control(pDX,IDC_ENCODE_SIGN_LIST,m_encodeSign);
	DDX_Control(pDX,IDC_FREQ_MULTI_COMBO,m_FreqMulti);
	DDX_Control(pDX,IDC_PRODUCT_DETE_LIST,m_productDete);
	DDX_Control(pDX,IDC_ACTIVE_LEV_LIST,m_activeLev);
	DDX_Control(pDX,IDC_IMPULSE_EDIT,m_impulse);
	DDX_Control(pDX,IDC_LENGTH_EDIT,m_length);
	DDX_Control(pDX,IDC_CURRENT_LEV_EDIT,m_currentLevel);
	DDX_Control(pDX,IDC_TRIGGER_LEN_EDIT,m_triggerLen);
	DDX_Text(pDX, IDC_CURRENT_LEV_EDIT, m_currentLevelStr);

	DDX_Control(pDX, IDC_CONFIG_OSRETURN_BTN, m_outSetReturn);
	DDX_Control(pDX, IDC_OUTSET_OK_BTN, m_outSetOk);
	DDX_Control(pDX, IDC_PCF_OUTSET_PRINTDIRE_STATIC, m_outsetPrintDir);
	DDX_Control(pDX, IDC_OUTSET_ENCODESIGN_STATIC, m_outsetEncodeSign);
	DDX_Control(pDX, IDC_OUTSET_FREQMULTI_STATIC, m_outsetPreqmulti);
	DDX_Control(pDX, IDC_OUTSET_IMPULSE_STATIC, m_outsetImpulse);
	DDX_Control(pDX, IDC_OUTSET_LENGTH_STATIC, m_outsetLength);
	DDX_Control(pDX, IDC_OUTSET_PRODUCT_DETE_STATIC, m_outsetProduct);
	DDX_Control(pDX, IDC_OUTSET_ACTIVELEV_STATIC, m_outsetActiveLev);
	DDX_Control(pDX, IDC_OUTSET_CUR_LEV_STATIC, m_outsetCurLev);
	DDX_Control(pDX, IDC_OUTSET_TRIGGER_LEN_STATIC, m_outsetTrigger);
	DDX_Text(pDX, IDC_IMPULSE_EDIT, m_intImpulse);
	DDX_Text(pDX, IDC_LENGTH_EDIT, m_intLength);
	DDX_Text(pDX, IDC_TRIGGER_LEN_EDIT, m_intTriggerLen);
}


BEGIN_MESSAGE_MAP(CConfigOutSetDlg, CDialog)
	ON_BN_CLICKED(IDC_CONFIG_OSRETURN_BTN, &CConfigOutSetDlg::OnBnClickedConfigOsreturnBtn)
	ON_WM_CTLCOLOR()
	ON_EN_SETFOCUS(IDC_IMPULSE_EDIT, &CConfigOutSetDlg::OnEnSetfocusImpulseEdit)
	ON_EN_SETFOCUS(IDC_TRIGGER_LEN_EDIT, &CConfigOutSetDlg::OnEnSetfocusTriggerLenEdit)
	ON_EN_SETFOCUS(IDC_LENGTH_EDIT, &CConfigOutSetDlg::OnEnSetfocusLengthEdit)
	ON_BN_CLICKED(IDC_OUTSET_OK_BTN, &CConfigOutSetDlg::OnBnClickedOutsetOkBtn)
END_MESSAGE_MAP()


// CConfigOutSet 消息处理程序
BOOL CConfigOutSetDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_printDire.AddString(_T("forward"));
	m_printDire.AddString(_T("Backward"));
	m_printDire.SetItemHeight(0,20);
	m_encodeSign.AddString(_T("1 Phase"));	
	m_encodeSign.AddString(_T("2 Phase"));	
	m_encodeSign.SetItemHeight(0,20);
	m_productDete.AddString(_T("OFF"));	
	m_productDete.AddString(_T("ON"));
	m_productDete.SetItemHeight(0,20);
	m_activeLev.AddString(_T("Low"));	
	m_activeLev.AddString(_T("High"));
	m_activeLev.SetItemHeight(0,20);
	m_FreqMulti.AddString(_T("ON"));
	m_FreqMulti.AddString(_T("OFF"));
	m_FreqMulti.SetCurSel(1);	
	m_FreqMulti.SetFont(theApp.m_ListBoxFont);
	m_FreqMulti.SendMessage(CB_SETITEMHEIGHT,-1,30);//设置下拉框高度
	m_FreqMulti.SendMessage(CB_SETITEMHEIGHT,0,30);//设置下拉框条目高度

	m_impulse.SetWindowText(_T("2500"));	
	m_impulse.SetFont(theApp.m_EditFont);
	m_length.SetWindowText(_T("200"));	
	m_length.SetFont(theApp.m_EditFont);
	m_currentLevel.SetWindowText(_T("High"));	 
	m_currentLevel.SetFont(theApp.m_EditFont);
	m_triggerLen.SetWindowText(_T("300"));	
	m_triggerLen.SetFont(theApp.m_EditFont);

	GetDlgItem(IDC_CONFIG_OSRETURN_BTN)->SetWindowPos(NULL,20,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_OUTSET_OK_BTN)->SetWindowPos(NULL,700,390,70,45,SWP_SHOWWINDOW);

	m_outSetReturn.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_outSetReturn.SizeToContent(); 
	m_outSetOk.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_outSetOk.SizeToContent(); 

	//////////////////////////////////////////////////////////////////////////

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CConfigOutSetDlg::OnBnClickedConfigOsreturnBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
	wstring tempstr;
	CString cstr;
	CCodePrinterDlg *pCodeDlg = (CCodePrinterDlg*)this->GetParent()->GetParent();//获取主对话框指针
	tempstr=theApp.myLanguage.LanguageMap["ID_CONFIGURATION_MANAGEMENT"];
	cstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(tempstr.c_str());
	((CCodePrinterDlg*)GetParent()->GetParent())->m_PicHead.SetOperationString(cstr);//User Manage 
}

HBRUSH CConfigOutSetDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
	if(nCtlColor == CTLCOLOR_LISTBOX)
	{
		pDC->SelectObject(theApp.m_ListBoxFont);
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));	
		return theApp.m_ListBoxBrush;
	}
	// TODO:  在此更改 DC 的任何属性
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return theApp.m_DlgBrush;
}

void CConfigOutSetDlg::OnEnSetfocusImpulseEdit()
{
	// TODO: 在此添加控件通知处理程序代码

	CEdit *pEdit = &m_impulse;
	CCodePrinterDlg* dlg;
	dlg = (CCodePrinterDlg*)(GetParent()->GetParent());
	dlg->OpenNumKeyBoard(pEdit,3);
}

void CConfigOutSetDlg::OnEnSetfocusTriggerLenEdit()
{
	// TODO: 在此添加控件通知处理程序代码

	CEdit *pEdit = &m_triggerLen;
	CCodePrinterDlg* dlg;
	dlg = (CCodePrinterDlg*)(GetParent()->GetParent());
	dlg->OpenNumKeyBoard(pEdit,3);
}

void CConfigOutSetDlg::OnEnSetfocusLengthEdit()
{
	// TODO: 在此添加控件通知处理程序代码

	CEdit *pEdit = &m_length;
	CCodePrinterDlg* dlg;
	dlg = (CCodePrinterDlg*)(GetParent()->GetParent());
	dlg->OpenNumKeyBoard(pEdit,3);
}

void CConfigOutSetDlg::OnBnClickedOutsetOkBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	//
	try
	{  
		if ( m_intLength == 0 )
			m_intLength = 0;
	}
	catch (CException* e)
	{
	}

	try
	{  
		if ( m_intTriggerLen == 0 )
			m_intTriggerLen = 0;
	}
	catch (CException* e)
	{
	}
	try
	{  
		if ( m_intImpulse == 0 )
			m_intImpulse = 0;
	}
	catch (CException* e)
	{
	}
	//确认更改，并返回配置页面
	CConfigurationDlg* dlg;
	dlg = (CConfigurationDlg*)(GetParent());
	ModuleMain myModuleMain;
	int nIndex = dlg->m_ConfigPM->m_printMode.GetCurSel();//判断打印模式
	int nIndex1 = dlg->m_speedWay.GetCurSel();//判断内部外部打印
	//
	//try
	//{  
	//	switch(nIndex)
	//	{
	//	case 2:
	//		switch(nIndex1)
	//		{
	//		case 0:
	//			if (dlg->m_dotPitch*3840/dlg->m_speed > theApp.myStatusClass.staPixDotNee)
	//			{
	//				dlg->m_floatlabLength = ceil((ceil(dlg->m_dotPitch*3840/dlg->m_speed)*dlg->m_speed*theApp.m_MessageEdit.pcfintDotMesRow*(dlg->m_ConfigPM->m_repeatCount+1)+dlg->m_repeatDis*dlg->m_ConfigPM->m_repeatCount)/3840);
	//			} 
	//			else
	//			{
	//			}
	//			break;
	//		case 1:

	//			break;
	//		}
	//		break;
	//	case 1:
	//		switch(nIndex1)
	//		{
	//		case 0:

	//			break;
	//		case 1:

	//			break;
	//		}
	//		break;
	//	}	
	//}
	//catch (CException* e)
	//{
	//}
	////////////////////////////////////////////////////////////////////////

	dlg->OnBnClickedSavePcf();
}
