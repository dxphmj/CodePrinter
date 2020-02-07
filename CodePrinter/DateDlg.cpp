// DateDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "DateDlg.h"
#include "CodePrinterDlg.h"
// CDateDlg 对话框

IMPLEMENT_DYNAMIC(CDateDlg, CDialog)

CDateDlg::CDateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDateDlg::IDD, pParent)
{

}

CDateDlg::~CDateDlg()
{
}

void CDateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATE_CLOSE_BTN, m_returnIB);
	DDX_Control(pDX, IDC_DATE_OK_BTN, m_okIB);
	DDX_Control(pDX, IDC_DATE_REFRESH_BTN, m_freshIB);
	DDX_Control(pDX, IDC_DATE_ADD_BTN, m_dateAddBtn);
	DDX_Control(pDX, IDC_DATE_SKEW_VALUE_EDIT, m_skewValue);
	DDX_Control(pDX, IDC_DATE_PREVIEW_STATIC, m_previewStatic);
	DDX_Control(pDX, IDC_DATE_TIME_STATIC, m_dateTimeStatic);
	DDX_Control(pDX, IDC_DATE_FORMAT_STATIC, m_formatStatic);
	DDX_Control(pDX, IDC_DATE_FONT_STATIC, m_fontStatic);
	DDX_Control(pDX, IDC_DATE_SKEW_STATIC, m_skewStatic);
	DDX_Control(pDX, IDC_DATE_SKEW_VALUE_STATIC, m_skewVauleStatic);
	DDX_Control(pDX, IDC_DATE_SKEW_UNIT_STATIC, m_skewUnitStatic);
	DDX_Control(pDX, IDC_FORMAT_LIST, m_formatList);
	DDX_Control(pDX, IDC_SKEW_UNIT_LIST, m_skewUnitList);
	DDX_Control(pDX, IDC_DATE_FONT_COMBO, m_dateFontCombo);
	DDX_Control(pDX, IDC_DATE_SKEW_COMBO, m_dateSkewCombo);
}


BEGIN_MESSAGE_MAP(CDateDlg, CDialog)
	ON_BN_CLICKED(IDC_DATE_CLOSE_BTN, &CDateDlg::OnBnClickedDateCloseBtn)
	ON_WM_CTLCOLOR()
	ON_CBN_SELCHANGE(IDC_DATE_SKEW_COMBO, &CDateDlg::OnCbnSelchangeDateSkewCombo)
	ON_BN_CLICKED(IDC_DATE_ADD_BTN, &CDateDlg::OnBnClickedDateAddBtn)
	ON_BN_CLICKED(IDC_DATE_REFRESH_BTN, &CDateDlg::OnBnClickedDateRefreshBtn)
	ON_LBN_SELCHANGE(IDC_SKEW_UNIT_LIST, &CDateDlg::OnLbnSelchangeSkewUnitList)
	ON_BN_CLICKED(IDC_DATE_OK_BTN, &CDateDlg::OnBnClickedDateOkBtn)
END_MESSAGE_MAP()


// CDateDlg 消息处理程序

BOOL CDateDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	
	//m_returnIB.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RANGE_BITMAP);
	//m_returnIB.SizeToContent(); 
	//m_okIB.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_RANGE_BITMAP);
	//m_okIB.SizeToContent(); 
	//m_freshIB.LoadBitmaps(IDB_FRESH1_BITMAP,IDB_FRESH2_BITMAP,0,0,IDB_RANGE_BITMAP);
	//m_freshIB.SizeToContent();
	//m_dateAddBtn.LoadBitmaps(IDB_70_45_1_BITMAP,IDB_70_45_BITMAP,0,0,IDB_70_45_1_BITMAP,true);
	//m_dateAddBtn.SizeToContent(); 

//	m_skewValue.SetFont(theApp.m_EditFont);
//	GetDlgItem(IDC_DATE_SKEW_VALUE_EDIT)->SetWindowText(_T("0"));
//	m_formatList.SetItemHeight(0,20);
//	m_skewUnitList.SetItemHeight(0,20);
	/*
	m_skewUnitList.AddString(_T("Year"));
	m_skewUnitList.AddString(_T("Month"));
	m_skewUnitList.AddString(_T("Day"));
	m_skewUnitList.AddString(_T("Hour"));
	m_skewUnitList.AddString(_T("Minute"));
    m_skewUnitList.SetCurSel(0);
	m_dateFontCombo.SetFont(theApp.m_ListBoxFont); //设置下拉框字体
	m_dateFontCombo.SendMessage(CB_SETITEMHEIGHT,-1,30);//设置下拉框高度
	m_dateFontCombo.SendMessage(CB_SETITEMHEIGHT,0,30);//设置下拉框条目高度
	m_dateFontCombo.AddString(_T("5x5"));
	m_dateFontCombo.AddString(_T("7x5"));
	m_dateFontCombo.AddString(_T("12x12"));
	m_dateFontCombo.AddString(_T("16x12"));
	m_dateFontCombo.SetCurSel(1);

	m_dateSkewCombo.SetFont(theApp.m_ListBoxFont); //设置下拉框字体
	m_dateSkewCombo.SendMessage(CB_SETITEMHEIGHT,-1,30);//设置下拉框高度
	m_dateSkewCombo.SendMessage(CB_SETITEMHEIGHT,0,30);//设置下拉框条目高度
	m_dateSkewCombo.AddString(_T("OFF"));
	m_dateSkewCombo.AddString(_T("ON"));
	m_dateSkewCombo.SetCurSel(0);

	//时间
	CListBox* dataList=(CListBox*)GetDlgItem(IDC_FORMAT_LIST);
	dataList->AddString(_T("%Y - Year (0000 - 9999)"));
	dataList->AddString(_T("%y - Year (00 - 99)"));
	dataList->AddString(_T("%m - Month (01 - 12)"));
	dataList->AddString(_T("%d - Day  (01 - 31)"));
	dataList->AddString(_T("%H - Hour (00 - 23)"));
	dataList->AddString(_T("I - Hour (01 - 12)"));
	//dataList->AddString(_T("%p - A.M. / P.M. "));
	dataList->AddString(_T("%M - Minute (00 - 59)"));
	dataList->AddString(_T("%S - Second (00 - 59)"));
	dataList->AddString(_T("%U - Week, Sunday first (00 - 53)"));
	dataList->AddString(_T("%W - Week, Monday first (00 - 53)"));
	//dataList->AddString(_T("%V - Weekday (1 - 7; Sunday is 1)"));
	//dataList->AddString(_T("%v - Weekday (1 - 7; Monday is 1)"));
	dataList->AddString(_T("%w - Weekday (0 - 6; Sunday is 0)"));
	//dataList->AddString(_T("%w - Weekday (0 - 6; Monday is 0)"));
	//dataList->AddString(_T("%Q - Quarter number of year (1 - 4)"));
	dataList->AddString(_T("%j - Day number of year (001 - 366)"));
	dataList->AddString(_T("%a - Abbreviated weekday name"));
	dataList->AddString(_T("%A - Full weekday name"));
	dataList->AddString(_T("%b - Abbreviated month name"));
	dataList->AddString(_T("%B - Full month name"));
	dataList->AddString(_T("%p - am / pm"));
	dataList->SetCurSel(0);
	*/
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CDateDlg::OnBnClickedDateCloseBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
}

HBRUSH CDateDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	//if(nCtlColor == CTLCOLOR_STATIC)
	//{		 
	//	pDC->SelectObject(theApp.m_StaticFont);
	//	pDC->SetBkMode(TRANSPARENT);
	//	pDC->SetTextColor(RGB(0,0,0));	
	//	return theApp.m_StaticBrush;
	//}
	//if(nCtlColor == CTLCOLOR_EDIT)
	//{ 
	//// 	pDC->SelectObject(theApp.m_EditFont);
	//	pDC->SetBkMode(TRANSPARENT);
	//	pDC->SetTextColor(RGB(0,0,0));	
	//	return theApp.m_StaticBrush;
	//}
	//if(nCtlColor == CTLCOLOR_LISTBOX)
	//{
	//	pDC->SelectObject(theApp.m_ListBoxFont);
	//	pDC->SetBkMode(TRANSPARENT);
	//	pDC->SetTextColor(RGB(0,0,0));	
	//	return theApp.m_ListBoxBrush;
	//}
	//pDC->SetBkColor(theApp.m_BKcolor);	
	//// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return theApp.m_DlgBrush;
}
void CDateDlg::OnCbnSelchangeDateSkewCombo()
{
	// TODO: 在此添加控件通知处理程序代码
	//ChangeTime();
}

void CDateDlg::OnBnClickedDateAddBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	CListBox* dataList=(CListBox*)GetDlgItem(IDC_FORMAT_LIST);
	int nSelect=dataList->GetCurSel();
	CString timeFormatStr;
	GetDlgItem(IDC_DATE_DATE_TIME_EDIT)->GetWindowText(timeFormatStr);
	switch(nSelect)
	{
	case 0:
		timeFormatStr+=_T("%Y");
		break;
	case 1:
		timeFormatStr+=_T("%y");
		break;
	case 2:
		timeFormatStr+=_T("%m");
		break;
	case 3:
		timeFormatStr+=_T("%d");
		break;
	case 4:
		timeFormatStr+=_T("%H");
		break;
	case 5:
		timeFormatStr+=_T("%I");
		break;
	case 6:
		timeFormatStr+=_T("%M");
		break;
	case 7:
		timeFormatStr+=_T("%S");
		break;
	case 8:
		timeFormatStr+=_T("%U");
		break;
	case 9:
		timeFormatStr+=_T("%W");
		break;
	case 10:
		timeFormatStr+=_T("%w");
		break;
	case 11:
		timeFormatStr+=_T("%j");
		break;
	case 12:
		timeFormatStr+=_T("%a");
		break;
	case 13:
		timeFormatStr+=_T("%A");
		break;
	case 14:
		timeFormatStr+=_T("%b");
		break;
	case 15:
		timeFormatStr+=_T("%B");
		break;
	case 16:
		timeFormatStr+=_T("%p");
		break;
	default:
		break;
	}
	GetDlgItem(IDC_DATE_DATE_TIME_EDIT)->SetWindowText(timeFormatStr);
	CString fuckStr;
	m_skewValue.GetWindowText(fuckStr);
	CString nowTimeStr;//=theApp.myModuleMain.string2CString(theApp.myModuleMain.TimeFormatToText(timeFormatStr,m_dateSkewCombo.GetCurSel(),_ttoi(fuckStr),m_skewUnitList.GetCurSel()));
	GetDlgItem(IDC_DATE_PREVIEW_EDIT)->SetWindowText(nowTimeStr);
}

void CDateDlg::OnBnClickedDateRefreshBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	//ChangeTime();
}

void CDateDlg::ChangeTime()
{
	return;
	CString timeFormatStr;
	GetDlgItem(IDC_DATE_DATE_TIME_EDIT)->GetWindowText(timeFormatStr);
	CString fuckStr;
	m_skewValue.GetWindowText(fuckStr);
	CString nowTimeStr;//=theApp.myModuleMain.string2CString(theApp.myModuleMain.TimeFormatToText(timeFormatStr,m_dateSkewCombo.GetCurSel(),_ttoi(fuckStr),m_skewUnitList.GetCurSel()));
	GetDlgItem(IDC_DATE_PREVIEW_EDIT)->SetWindowText(nowTimeStr);
}
void CDateDlg::OnLbnSelchangeSkewUnitList()
{
	// TODO: 在此添加控件通知处理程序代码
	//ChangeTime();
}

/*
BOOL CDateDlg::PreTranslateMessage(MSG* pMsg)
{
	
	// TODO: 在此添加专用代码和/或调用基类
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_DATE_DATE_TIME_EDIT);
	CEdit* cEdit = (CEdit*)GetDlgItem(IDC_DATE_SKEW_VALUE_EDIT);
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
	if(WM_LBUTTONDOWN == pMsg->message && cEdit->GetSafeHwnd() == pMsg->hwnd)
	{
		//pEdit->SetFocus();
		//pEdit->SetSel(-1);
		CCodePrinterDlg* dlg;
		dlg = (CCodePrinterDlg*)(GetParent()->GetParent()->GetParent());
		dlg->OpenNumKeyBoard(cEdit);
		return TRUE;
	}

	//CEdit *pEdit = &m_edit_fiexd;
	ChangeTime();
	 
	return CDialog::PreTranslateMessage(pMsg);
}
*/
void CDateDlg::OnBnClickedDateOkBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	if (theApp.bochange)
	{
		for(int i=0;i<theApp.myclassMessage.OBJ_Vec.size();i++)
		{
			if (theApp.myclassMessage.OBJ_Vec.at(i)->booFocus)
			{
				CEdit* pEdit = (CEdit*)GetDlgItem(IDC_DATE_PREVIEW_EDIT);
				CString strText;
				pEdit-> GetWindowText(strText);
				theApp.myclassMessage.OBJ_Vec[i]->strText=theApp.myModuleMain.UnicodeToUtf8_CSTR(strText);

				CString formatText;
				GetDlgItem(IDC_DATE_DATE_TIME_EDIT)->GetWindowText(formatText);
				theApp.myclassMessage.OBJ_Vec[i]->strTime=theApp.myModuleMain.CString2string(formatText);

				CString  fontText;
				int nIndex = m_dateFontCombo.GetCurSel();  //当前选中的项
				switch(nIndex)
				{
				case 0:
					theApp.myclassMessage.OBJ_Vec[i]->intLineSize=5;
					theApp.myclassMessage.OBJ_Vec[i]->intRowSize=strText.GetLength()*6;//////////这是个坑，注意阿拉伯语要改这
					break;
				case 1:
					theApp.myclassMessage.OBJ_Vec[i]->intLineSize=7;
					theApp.myclassMessage.OBJ_Vec[i]->intRowSize=strText.GetLength()*6;//////////这是个坑，注意阿拉伯语要改这
					break;
				case 2:
					theApp.myclassMessage.OBJ_Vec[i]->intLineSize=12;
					theApp.myclassMessage.OBJ_Vec[i]->intRowSize=strText.GetLength()*13;//////////这是个坑，注意阿拉伯语要改这
					break;
				case 3:
					theApp.myclassMessage.OBJ_Vec[i]->intLineSize=16;
					theApp.myclassMessage.OBJ_Vec[i]->intRowSize=strText.GetLength()*13;//////////这是个坑，注意阿拉伯语要改这
					break;
				}
				m_dateFontCombo.GetLBText(nIndex,fontText);
				theApp.myclassMessage.OBJ_Vec[i]->strFont=theApp.myModuleMain.CString2string(fontText);

				theApp.myclassMessage.OBJ_Vec[i]->booETimeOffSet=m_dateSkewCombo.GetCurSel();
				CString timeOffText;
				GetDlgItem(IDC_DATE_SKEW_VALUE_EDIT)->GetWindowText(timeOffText);


				if ((theApp.myclassMessage.OBJ_Vec[i]->intRowStart+theApp.myclassMessage.OBJ_Vec[i]->intRowSize)>theApp.myclassMessage.scrMaxRow)
				{
					theApp.myclassMessage.scrMaxRow=theApp.myclassMessage.OBJ_Vec[i]->intRowStart+theApp.myclassMessage.OBJ_Vec[i]->intRowSize;
				}

				theApp.myclassMessage.OBJ_Vec[i]->intTimeOffSet=_ttoi(timeOffText);
				theApp.myclassMessage.OBJ_Vec[i]->strTimeOffSet=m_skewUnitList.GetCurSel();

				break;
			}
		}
		theApp.bochange=false;

		ShowWindow(SW_HIDE);
		return;
	}
	int xPos=0;
	int yPos=0;
	theApp.myclassMessage.GetNextObjPosition(xPos,yPos);

	OBJ_Control* tempObj = new OBJ_Control;
	tempObj->intLineStart=yPos;
	tempObj->intRowStart=xPos;
	tempObj->strType1="text";
	tempObj->strType2="time";
	//以下先写死
	tempObj->intSW=1;
	tempObj->intSS=0;
	tempObj->booNEG=false;
	tempObj->booBWDx=false;
	tempObj->booBWDy=false;

	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_DATE_PREVIEW_EDIT);
	CString strText;
	pEdit-> GetWindowText(strText);
	tempObj->strText=theApp.myModuleMain.UnicodeToUtf8_CSTR(strText);

	CString formatText;
	GetDlgItem(IDC_DATE_DATE_TIME_EDIT)->GetWindowText(formatText);
	tempObj->strTime=theApp.myModuleMain.CString2string(formatText);

	CString  fontText;
	int nIndex = m_dateFontCombo.GetCurSel();  //当前选中的项
	switch(nIndex)
	{
	case 0:
		tempObj->intLineSize=5;
		tempObj->intRowSize=strText.GetLength()*6;//////////这是个坑，注意阿拉伯语要改这
		break;
	case 1:
		tempObj->intLineSize=7;
		tempObj->intRowSize=strText.GetLength()*6;//////////这是个坑，注意阿拉伯语要改这
		break;
	case 2:
		tempObj->intLineSize=12;
		tempObj->intRowSize=strText.GetLength()*13;//////////这是个坑，注意阿拉伯语要改这
		break;
	case 3:
		tempObj->intLineSize=16;
		tempObj->intRowSize=strText.GetLength()*13;//////////这是个坑，注意阿拉伯语要改这
		break;
	}
	m_dateFontCombo.GetLBText(nIndex,fontText);
	tempObj->strFont=theApp.myModuleMain.CString2string(fontText);
	
	tempObj->booETimeOffSet=m_dateSkewCombo.GetCurSel();
	CString timeOffText;
	GetDlgItem(IDC_DATE_SKEW_VALUE_EDIT)->GetWindowText(timeOffText);
	tempObj->intTimeOffSet=_ttoi(timeOffText);
	tempObj->strTimeOffSet=m_skewUnitList.GetCurSel();



	if ((tempObj->intRowStart+tempObj->intRowSize)>theApp.myclassMessage.scrMaxRow)
	{
		theApp.myclassMessage.scrMaxRow=tempObj->intRowStart+tempObj->intRowSize;
	}

	tempObj->booFocus=true;

	theApp.myclassMessage.OBJ_Vec.push_back(tempObj);
	this->ShowWindow(SW_HIDE);
}
