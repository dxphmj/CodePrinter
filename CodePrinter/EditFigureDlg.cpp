// EditFigureDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "EditFigureDlg.h"


// CEditFigureDlg 对话框

IMPLEMENT_DYNAMIC(CEditFigureDlg, CDialog)

CEditFigureDlg::CEditFigureDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditFigureDlg::IDD, pParent)
{

}

CEditFigureDlg::~CEditFigureDlg()
{
}

void CEditFigureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDITFIG_CLOSE_BTN, m_returnIB);
	DDX_Control(pDX, IDC_EDITFIGURE_OK_BTN, m_okIB);
	DDX_Control(pDX, IDC_FONT_COMBO, m_FontBox);
	DDX_Control(pDX, IDC_FORMAT_COMBO, m_FormatBox);
	DDX_Control(pDX, IDC_COUNTER_COMBO, m_countBox);
	DDX_Control(pDX, IDC_PREVIEW_STATIC, m_previewStatic);
	DDX_Control(pDX, IDC_FIRST_QUARTILE_STATIC, m_firstQuartileStatic);
	DDX_Control(pDX, IDC_FOUR_QUARTILE_STATIC, m_fourQuartileStatic);
	DDX_Control(pDX, IDC_START_STATIC, m_startStatic);
	DDX_Control(pDX, IDC_STEP_SIZE_STATIC, m_stepSizeStatic);
	DDX_Control(pDX, IDC_REPEAT_COUNT_STATIC, m_repeatCountStatic);
	DDX_Control(pDX, IDC_BIT_DATA_STATIC, m_bitStatic);
	DDX_Control(pDX, IDC_COUNTER_STATIC, m_counterStatic);
	DDX_Control(pDX, IDC_FONT_STATIC, m_fontStatic);
	DDX_Control(pDX, IDC_FORMAT_STATIC, m_formatStatic);
	DDX_Control(pDX, IDC_PREVIEW_EDIT, m_previewEdit);
	DDX_Control(pDX, IDC_FIRST_QUARTILE_EDIT, m_firstQuartileEdit);
	DDX_Control(pDX, IDC_FOUR_QUARTILE_EDIT, m_fourQuartileEdit);
	DDX_Control(pDX, IDC_START_EDIT, m_startEdit);
	DDX_Control(pDX, IDC_STEP_SIZE_EDIT, m_stepSizeEdit);
	DDX_Control(pDX, IDC_REPEAT_COUNT_EDIT, m_repeatCountEdit);
	DDX_Control(pDX, IDC_BIT_DATA_EDIT, m_bitDataEdit);
}


BEGIN_MESSAGE_MAP(CEditFigureDlg, CDialog)
	ON_BN_CLICKED(IDC_EDITFIG_CLOSE_BTN, &CEditFigureDlg::OnBnClickedEditfigCloseBtn)
	ON_WM_CTLCOLOR()
	ON_CBN_SELCHANGE(IDC_FORMAT_COMBO, &CEditFigureDlg::OnCbnSelchangeFormatCombo)
	ON_BN_CLICKED(IDC_EDITFIGURE_OK_BTN, &CEditFigureDlg::OnBnClickedEditfigureOkBtn)
END_MESSAGE_MAP()


// CEditFigureDlg 消息处理程序

BOOL CEditFigureDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CRect rect;
	GetWindowRect(&rect);

	GetDlgItem(IDC_EDITFIG_CLOSE_BTN)->SetWindowPos(NULL,20,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_EDITFIGURE_OK_BTN)->SetWindowPos(NULL,700,390,70,45,SWP_SHOWWINDOW);

	m_returnIB.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_returnIB.SizeToContent(); 
	m_okIB.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_okIB.SizeToContent(); 

	m_countBox.AddString(_T("待添加"));
	m_countBox.SetFont(theApp.m_ListBoxFont); //设置下拉框字体
	m_countBox.SendMessage(CB_SETITEMHEIGHT,-1,30);//设置下拉框高度
	m_countBox.SendMessage(CB_SETITEMHEIGHT,0,30);//设置下拉框条目高度

	m_FontBox.AddString(_T("5x5"));
	m_FontBox.AddString(_T("7x5"));
	m_FontBox.AddString(_T("12x12"));
	m_FontBox.AddString(_T("16x12"));
	m_FontBox.SetCurSel(1);
	m_FontBox.SetFont(theApp.m_ListBoxFont); //设置下拉框字体
	m_FontBox.SendMessage(CB_SETITEMHEIGHT,-1,30);//设置下拉框高度
	m_FontBox.SendMessage(CB_SETITEMHEIGHT,0,30);//设置下拉框条目高度

	m_FormatBox.AddString(_T("Leading Zeroes"));
	m_FormatBox.AddString(_T("Leading Blanks"));
	m_FormatBox.AddString(_T("Left Aligned"));
	m_FormatBox.SetCurSel(0);
	m_FormatBox.SetFont(theApp.m_ListBoxFont); //设置下拉框字体
	m_FormatBox.SendMessage(CB_SETITEMHEIGHT,-1,30);//设置下拉框高度
	m_FormatBox.SendMessage(CB_SETITEMHEIGHT,0,30);//设置下拉框条目高度

	m_previewEdit.SetFont(theApp.m_EditFont);
	m_firstQuartileEdit.SetFont(theApp.m_EditFont);
	m_fourQuartileEdit.SetFont(theApp.m_EditFont);
	m_startEdit.SetFont(theApp.m_EditFont);
	m_stepSizeEdit.SetFont(theApp.m_EditFont);
	m_repeatCountEdit.SetFont(theApp.m_EditFont);
	m_bitDataEdit.SetFont(theApp.m_EditFont);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CEditFigureDlg::OnBnClickedEditfigCloseBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
}

HBRUSH CEditFigureDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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
	// TODO:  在此更改 DC 的任何属性
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return theApp.m_DlgBrush;
}

void CEditFigureDlg::RefreshSerial()
{
	string PreviewText;
	CString strDigit;
	GetDlgItem(IDC_BIT_DATA_EDIT)->GetWindowText(strDigit);
	int digital = _ttoi(strDigit);
	CString strStart;
	GetDlgItem(IDC_START_EDIT)->GetWindowText(strStart);
	int startNum = _ttoi(strStart);
	switch(m_FormatBox.GetCurSel())
	{
	case 0:
		for (int a = 0;a < digital; a++)
			PreviewText = PreviewText+"0";
		PreviewText = PreviewText+OBJ_Control::to_String(startNum);
		PreviewText = PreviewText.substr(PreviewText.size()-digital,digital);
		GetDlgItem(IDC_PREVIEW_EDIT)->SetWindowText(theApp.myModuleMain.string2CString(PreviewText));
		break;
	case 1:
		for (int a = 0; a < digital; a++)
			PreviewText = PreviewText+" ";
 		PreviewText = PreviewText+OBJ_Control::to_String(startNum);
		PreviewText = PreviewText.substr(PreviewText.size()-digital,digital);
		GetDlgItem(IDC_PREVIEW_EDIT)->SetWindowText(theApp.myModuleMain.string2CString(PreviewText));
		break;
	case 2:
		PreviewText = OBJ_Control::to_String(startNum);
		int n = digital-PreviewText.length();
		for (int a = 0; a < n; a++)
			PreviewText = PreviewText+" ";
		GetDlgItem(IDC_PREVIEW_EDIT)->SetWindowText(theApp.myModuleMain.string2CString(PreviewText));
		break;
	}
}

BOOL CEditFigureDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	//CEdit* previewEdit = (CEdit*)GetDlgItem(IDC_PREVIEW_EDIT);
	CEdit* firstEdit = (CEdit*)GetDlgItem(IDC_FIRST_QUARTILE_EDIT);
	CEdit* twoEdit = (CEdit*)GetDlgItem(IDC_FOUR_QUARTILE_EDIT);
	CEdit* startEdit = (CEdit*)GetDlgItem(IDC_START_EDIT);
	CEdit* stepEdit = (CEdit*)GetDlgItem(IDC_STEP_SIZE_EDIT);
	CEdit* repeatEdit = (CEdit*)GetDlgItem(IDC_REPEAT_COUNT_EDIT);
	CEdit* bitEdit = (CEdit*)GetDlgItem(IDC_BIT_DATA_EDIT);
	//ASSERT(pEdit && pEdit->GetSafeHwnd());
	//if(WM_LBUTTONDOWN == pMsg->message && previewEdit->GetSafeHwnd() == pMsg->hwnd)
	//{
	//	CString str;
	//	previewEdit-> GetWindowText(str);
	//	CExportDlg myCExportDlg;
	//	str=myCExportDlg.GetInputText(str);
	//	previewEdit-> SetWindowText(str);
	//	return TRUE;
	//}
	if(WM_LBUTTONDOWN == pMsg->message && firstEdit->GetSafeHwnd() == pMsg->hwnd)
	{
		CString str;
		firstEdit-> GetWindowText(str);
		CExportDlg myCExportDlg;
		str=myCExportDlg.GetInputText(str);
		if(str.SpanIncluding(_T("0123456789")) != str)
		{
			str=_T("0");
		}
		firstEdit-> SetWindowText(str);
		return TRUE;
	}
	else if(WM_LBUTTONDOWN == pMsg->message && twoEdit->GetSafeHwnd() == pMsg->hwnd)
	{
		CString str;
		twoEdit-> GetWindowText(str);
		CExportDlg myCExportDlg;
		str=myCExportDlg.GetInputText(str);
		if(str.SpanIncluding(_T("0123456789")) != str)
		{
			str=_T("999999999");
		}
		twoEdit-> SetWindowText(str);
		return TRUE;
	}
	else if(WM_LBUTTONDOWN == pMsg->message && startEdit->GetSafeHwnd() == pMsg->hwnd)
	{
		CString str;
		startEdit-> GetWindowText(str);
		CExportDlg myCExportDlg;
		str=myCExportDlg.GetInputText(str);
		if(str.SpanIncluding(_T("0123456789")) != str)
		{
			str=_T("0");
		}
		startEdit-> SetWindowText(str);
		RefreshSerial();
		return TRUE;
	}
	else if(WM_LBUTTONDOWN == pMsg->message && stepEdit->GetSafeHwnd() == pMsg->hwnd)
	{
		CString str;
		stepEdit-> GetWindowText(str);
		CExportDlg myCExportDlg;
		str=myCExportDlg.GetInputText(str);
		if(str.SpanIncluding(_T("0123456789")) != str)
		{
			str=_T("1");
		}
		stepEdit-> SetWindowText(str);
		return TRUE;
	}
	else if(WM_LBUTTONDOWN == pMsg->message && repeatEdit->GetSafeHwnd() == pMsg->hwnd)
	{
		CString str;
		repeatEdit-> GetWindowText(str);
		CExportDlg myCExportDlg;
		str=myCExportDlg.GetInputText(str);
		if(str.SpanIncluding(_T("0123456789")) != str)
		{
			str=_T("1");
		}
		repeatEdit-> SetWindowText(str);
		return TRUE;
	}
	else if(WM_LBUTTONDOWN == pMsg->message && bitEdit->GetSafeHwnd() == pMsg->hwnd)
	{
		CString str;
		bitEdit-> GetWindowText(str);
		CExportDlg myCExportDlg;
		str=myCExportDlg.GetInputText(str);
		int bitNum=_ttoi(str);
		if (bitNum<1)
		{
			str=_T("1");
		}
		else if (bitNum>9)
		{
			str=_T("9");
		}	
		bitEdit-> SetWindowText(str);
		RefreshSerial();
		return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CEditFigureDlg::OnCbnSelchangeFormatCombo()
{
	// TODO: 在此添加控件通知处理程序代码
	RefreshSerial();
}

void CEditFigureDlg::OnBnClickedEditfigureOkBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	CString previewEdit ;
	GetDlgItem(IDC_PREVIEW_EDIT)-> GetWindowText(previewEdit);
	CString firstEdit ;
	GetDlgItem(IDC_FIRST_QUARTILE_EDIT)-> GetWindowText(firstEdit);
	CString twoEdit ;
	GetDlgItem(IDC_FOUR_QUARTILE_EDIT)-> GetWindowText(twoEdit);
	CString startEdit ;
	GetDlgItem(IDC_START_EDIT)-> GetWindowText(startEdit);
	CString stepEdit ;
	GetDlgItem(IDC_STEP_SIZE_EDIT)-> GetWindowText(stepEdit);
	CString repeatEdit; 
	GetDlgItem(IDC_REPEAT_COUNT_EDIT)-> GetWindowText(repeatEdit);
	CString bitEdit ;
	GetDlgItem(IDC_BIT_DATA_EDIT)-> GetWindowText(bitEdit);
	if (theApp.bochange)
	{
		for(int i=0;i<theApp.m_MessageEdit.OBJ_Vec.size();i++)
		{
			if (theApp.m_MessageEdit.OBJ_Vec.at(i)->booFocus)
			{
				theApp.m_MessageEdit.OBJ_Vec[i]->strText=theApp.myModuleMain.CString2string(previewEdit);
				theApp.m_MessageEdit.OBJ_Vec[i]->intSerialFirstLimit=_ttoi(firstEdit);
				theApp.m_MessageEdit.OBJ_Vec[i]->intSerialSecondLimit=_ttoi(twoEdit);
				theApp.m_MessageEdit.OBJ_Vec[i]->intSerialStartValue=_ttoi(startEdit);
				theApp.m_MessageEdit.OBJ_Vec[i]->intSerialStep=_ttoi(stepEdit);
				theApp.m_MessageEdit.OBJ_Vec[i]->intSerialRepeat=_ttoi(repeatEdit);
				theApp.m_MessageEdit.OBJ_Vec[i]->intSerialDigits=_ttoi(bitEdit);

				CString  fontText;
				int nIndex = m_FontBox.GetCurSel();  //当前选中的项
				switch(nIndex)
				{
				case 0:
					theApp.m_MessageEdit.OBJ_Vec[i]->intLineSize=5;
					theApp.m_MessageEdit.OBJ_Vec[i]->intRowSize=previewEdit.GetLength()*6;//////////这是个坑，注意阿拉伯语要改这
					break;
				case 1:
					theApp.m_MessageEdit.OBJ_Vec[i]->intLineSize=7;
					theApp.m_MessageEdit.OBJ_Vec[i]->intRowSize=previewEdit.GetLength()*6;//////////这是个坑，注意阿拉伯语要改这
					break;
				case 2:
					theApp.m_MessageEdit.OBJ_Vec[i]->intLineSize=12;
					theApp.m_MessageEdit.OBJ_Vec[i]->intRowSize=previewEdit.GetLength()*13;//////////这是个坑，注意阿拉伯语要改这
					break;
				case 3:
					theApp.m_MessageEdit.OBJ_Vec[i]->intLineSize=16;
					theApp.m_MessageEdit.OBJ_Vec[i]->intRowSize=previewEdit.GetLength()*13;//////////这是个坑，注意阿拉伯语要改这
					break;
				}
				m_FontBox.GetLBText(nIndex,fontText);
				theApp.m_MessageEdit.OBJ_Vec[i]->strFont=theApp.myModuleMain.CString2string(fontText);

				CString countStr;
				m_countBox.GetLBText(m_countBox.GetCurSel(),countStr);
				theApp.m_MessageEdit.OBJ_Vec[i]->intSerialCounter=_ttoi(countStr)-1;


	
				if ((theApp.m_MessageEdit.OBJ_Vec[i]->intRowStart+theApp.m_MessageEdit.OBJ_Vec[i]->intRowSize)>theApp.m_MessageEdit.scrMaxRow)
				{
					theApp.m_MessageEdit.scrMaxRow=theApp.m_MessageEdit.OBJ_Vec[i]->intRowStart+theApp.m_MessageEdit.OBJ_Vec[i]->intRowSize;
				}

				theApp.m_MessageEdit.OBJ_Vec[i]->bytSerialFormat=m_FormatBox.GetCurSel();

				break;
			}
		}
		theApp.bochange=false;
		ShowWindow(SW_HIDE);
		return;
	}
	int xPos=0;
	int yPos=0;
	theApp.m_MessageEdit.GetNextObjPosition(xPos,yPos);
	OBJ_Control* tempObj = new OBJ_Control;
	tempObj->intLineStart=yPos;
	tempObj->intRowStart=xPos;
	tempObj->strType1="text";
	tempObj->strType2="serial";
	//以下先写死
	tempObj->intSW=1;
	tempObj->intSS=0;
	tempObj->booNEG=false;
	tempObj->booBWDx=false;
	tempObj->booBWDy=false;
	//CEdit* pEdit = (CEdit*)GetDlgItem(IDC_PREVIEW_EDIT);

	tempObj->strText=theApp.myModuleMain.CString2string(previewEdit);
	tempObj->intSerialFirstLimit=_ttoi(firstEdit);
	tempObj->intSerialSecondLimit=_ttoi(twoEdit);
	tempObj->intSerialStartValue=_ttoi(startEdit);
	tempObj->intSerialStep=_ttoi(stepEdit);
	tempObj->intSerialRepeat=_ttoi(repeatEdit);
	tempObj->intSerialDigits=_ttoi(bitEdit);
	CString  fontText;
	int nIndex = m_FontBox.GetCurSel();  //当前选中的项
	switch(nIndex)
	{
	case 0:
		tempObj->intLineSize=5;
		tempObj->intRowSize=previewEdit.GetLength()*6;//////////这是个坑，注意阿拉伯语要改这
		break;
	case 1:
		tempObj->intLineSize=7;
		tempObj->intRowSize=previewEdit.GetLength()*6;//////////这是个坑，注意阿拉伯语要改这
		break;
	case 2:
		tempObj->intLineSize=12;
		tempObj->intRowSize=previewEdit.GetLength()*13;//////////这是个坑，注意阿拉伯语要改这
		break;
	case 3:
		tempObj->intLineSize=16;
		tempObj->intRowSize=previewEdit.GetLength()*13;//////////这是个坑，注意阿拉伯语要改这
		break;
	}
	m_FontBox.GetLBText(nIndex,fontText);
	tempObj->strFont=theApp.myModuleMain.CString2string(fontText);

	CString countStr;
	m_countBox.GetLBText(m_countBox.GetCurSel(),countStr);
	tempObj->intSerialCounter=_ttoi(countStr)-1;


	if ((tempObj->intRowStart+tempObj->intRowSize)>theApp.m_MessageEdit.scrMaxRow)
	{
		theApp.m_MessageEdit.scrMaxRow=tempObj->intRowStart+tempObj->intRowSize;
	}

	tempObj->bytSerialFormat=m_FormatBox.GetCurSel();
	tempObj->booFocus=true;

	theApp.m_MessageEdit.OBJ_Vec.push_back(tempObj);
 	this->ShowWindow(SW_HIDE);
}
