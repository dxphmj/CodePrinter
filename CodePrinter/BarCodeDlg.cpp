// BarCodeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "BarCodeDlg.h"
#include "qrencode.h"
#include "InputDlg.h"
//#include "ModuleMain.h"
#include "qrcode\zint.h"


#pragma comment(lib,"lib\\QRlib.lib")
// CBarCodeDlg 对话框

IMPLEMENT_DYNAMIC(CBarCodeDlg, CDialog)

CBarCodeDlg::CBarCodeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBarCodeDlg::IDD, pParent)
{
	m_nCodeType = 58;
}

CBarCodeDlg::~CBarCodeDlg()
{
}

void CBarCodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_BARCODE_PICTURE, m_barcodeDesignArea);

	DDX_Control(pDX, IDC_BARCODE_VERSION_COMBO, VersionBox);
	DDX_Control(pDX, IDC_BARCODE_ECC_LEV_COMBO, ErrLevelBox);
	DDX_Control(pDX, IDC_BARCODE_ZONE_COMBO, EncodingModeBox);

	DDX_Control(pDX, IDC_BARCODE_CLOSE_BTN, m_returnIB);
	DDX_Control(pDX, IDC_QR_CODE_BTN, m_qrCodeIB);
	DDX_Control(pDX, IDC_DATA_MATRIX_BTN, m_dataMatrixIB);
	DDX_Control(pDX, IDC_CODE_39_BTN, m_code39IB);
	DDX_Control(pDX, IDC_CODE_128_BTN, m_code128IB);
	DDX_Control(pDX, IDC_BARCODE_OK_BTN, m_okIB);
	DDX_Control(pDX, IDC_BARCODE_L_BUTTON, m_L_shiftIB);
	DDX_Control(pDX, IDC_BARCODE_R_BUTTON, m_R_shiftIB);
	DDX_Control(pDX, IDC_BARCODE_DELETE_BUTTON, m_DeleteIB);
	DDX_Control(pDX, IDC_BARCODE_TEXT_STATIC, m_barText);
	DDX_Control(pDX, IDC_BARCODE_FIGURE_BTN, m_barcodeFigureBtn);
	DDX_Control(pDX, IDC_BARCODE_DATE_BTN, m_barcodeDateBtn);
	DDX_Control(pDX, IDC_BARCODE_FIGURE_STATIC, m_figureStatic);
	DDX_Control(pDX, IDC_BARCODE_DATE_STATIC, m_dateStatic);
}

BEGIN_MESSAGE_MAP(CBarCodeDlg, CDialog)
	ON_BN_CLICKED(IDC_BARCODE_CLOSE_BTN, &CBarCodeDlg::OnBnClickedBarcodeCloseBtn)
	ON_BN_CLICKED(IDC_QR_CODE_BTN, &CBarCodeDlg::OnBnClickedQrCodeBtn)
	ON_BN_CLICKED(IDC_DATA_MATRIX_BTN, &CBarCodeDlg::OnBnClickedDataMatrixBtn)
	ON_BN_CLICKED(IDC_BARCODE_OK_BTN, &CBarCodeDlg::OnBnClickedBarcodeOkBtn)
	ON_CBN_SELCHANGE(IDC_BARCODE_VERSION_COMBO, &CBarCodeDlg::OnCbnSelchangeBarcodeVersionCombo)
	ON_CBN_SELCHANGE(IDC_BARCODE_ECC_LEV_COMBO, &CBarCodeDlg::OnCbnSelchangeBarcodeEccLevCombo)
	ON_CBN_SELCHANGE(IDC_BARCODE_ZONE_COMBO, &CBarCodeDlg::OnCbnSelchangeBarcodeZoneCombo)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_CODE_128_BTN, &CBarCodeDlg::OnBnClickedCode128Btn)
	ON_BN_CLICKED(IDC_CODE_39_BTN, &CBarCodeDlg::OnBnClickedCode39Btn)
	ON_BN_CLICKED(IDC_BARCODE_FIGURE_BTN, &CBarCodeDlg::OnBnClickedBarcodeFigureBtn)
	ON_BN_CLICKED(IDC_BARCODE_DATE_BTN, &CBarCodeDlg::OnBnClickedBarcodeDateBtn)
	ON_BN_CLICKED(IDC_BARCODE_L_BUTTON, &CBarCodeDlg::OnBnClickedBarcodeLButton)
	ON_BN_CLICKED(IDC_BARCODE_R_BUTTON, &CBarCodeDlg::OnBnClickedBarcodeRButton)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BARCODE_DELETE_BUTTON, &CBarCodeDlg::OnBnClickedBarcodeDelButton)
END_MESSAGE_MAP()


// CBarCodeDlg 消息处理程序

BOOL CBarCodeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	VersionBox.AddString(_T("21x21"));
	VersionBox.AddString(_T("25x25"));
	//VersionBox.AddString(_T("1L25M"));
	//VersionBox.AddString(_T("2L7M"));
	VersionBox.SetCurSel(1);
	VersionBox.SetFont(theApp.m_ListBoxFont);//设置下拉框字体
	VersionBox.SendMessage(CB_SETITEMHEIGHT,-1,25);//设置下拉框高度
	VersionBox.SendMessage(CB_SETITEMHEIGHT,0,25);//设置下拉框条目高度

	ErrLevelBox.AddString(_T("L"));
	ErrLevelBox.AddString(_T("M"));
	ErrLevelBox.AddString(_T("Q"));
	ErrLevelBox.AddString(_T("H"));
	ErrLevelBox.SetCurSel(3);
	ErrLevelBox.SetFont(theApp.m_ListBoxFont);
	ErrLevelBox.SendMessage(CB_SETITEMHEIGHT,-1,25);//设置下拉框高度
	ErrLevelBox.SendMessage(CB_SETITEMHEIGHT,0,25);//设置下拉框条目高度

	EncodingModeBox.AddString(_T("Numeric"));
	EncodingModeBox.AddString(_T("Alphabet-numeric"));
	EncodingModeBox.AddString(_T("8-bit data"));
	EncodingModeBox.AddString(_T("Kanji"));
	EncodingModeBox.AddString(_T("STRUCTURE"));
	EncodingModeBox.AddString(_T("ECI"));
	EncodingModeBox.AddString(_T("FNC1FIRST"));
	EncodingModeBox.AddString(_T("FNC1SECOND"));
	EncodingModeBox.SetCurSel(2);
	EncodingModeBox.SetFont(theApp.m_ListBoxFont);//设置下拉框字体
	EncodingModeBox.SendMessage(CB_SETITEMHEIGHT,-1,25);//设置下拉框高度
	EncodingModeBox.SendMessage(CB_SETITEMHEIGHT,0,25);//设置下拉框条目高度

	GetDlgItem(IDC_BARCODE_CLOSE_BTN)->SetWindowPos(NULL,20,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_QR_CODE_BTN)->SetWindowPos(NULL,200,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_DATA_MATRIX_BTN)->SetWindowPos(NULL,300,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_CODE_39_BTN)->SetWindowPos(NULL,400,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_CODE_128_BTN)->SetWindowPos(NULL,500,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BARCODE_OK_BTN)->SetWindowPos(NULL,700,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BARCODE_L_BUTTON)->SetWindowPos(NULL,150,70,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BARCODE_R_BUTTON)->SetWindowPos(NULL,250,70,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BARCODE_DELETE_BUTTON)->SetWindowPos(NULL,350,70,70,45,SWP_SHOWWINDOW);

	m_returnIB.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_returnIB.SizeToContent();

	m_qrCodeIB.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_80_55_BITMAP,true);
	m_qrCodeIB.SizeToContent(); 

	m_dataMatrixIB.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_80_55_BITMAP,true);
	m_dataMatrixIB.SizeToContent(); 

 	m_code39IB.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_80_55_BITMAP,true);
	m_code39IB.SizeToContent(); 

	m_code128IB.LoadBitmaps(IDB_RANGE_BITMAP,IDB_RANGE2_BITMAP,0,0,IDB_80_55_BITMAP,true);
	m_code128IB.SizeToContent();

	m_okIB.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_okIB.SizeToContent(); 

	m_barcodeFigureBtn.LoadBitmaps(IDB_EDIT_FIGURE1_BITMAP,IDB_EDIT_FIGURE2_BITMAP,0,0,IDB_60_40_BITMAP);
	m_barcodeFigureBtn.SizeToContent();

	m_barcodeDateBtn.LoadBitmaps(IDB_EDIT_DATE1_BITMAP,IDB_EDIT_DATE2_BITMAP,0,0,IDB_60_40_BITMAP);
	m_barcodeDateBtn.SizeToContent(); 

	m_L_shiftIB.LoadBitmaps(IDB_L_SHIFT1_BITMAP,IDB_L_SHIFT2_BITMAP,0,0,IDB_60_35_BITMAP);
	m_L_shiftIB.SizeToContent(); 

	m_R_shiftIB.LoadBitmaps(IDB_R_SHIFT1_BITMAP,IDB_R_SHIFT1_BITMAP,0,0,IDB_60_35_BITMAP);
	m_R_shiftIB.SizeToContent(); 

	m_DeleteIB.LoadBitmaps(IDB_LABEL_DELETE1_BITMAP,IDB_LABEL_DELETE2_BITMAP,0,0,IDB_60_40_BITMAP);
	m_DeleteIB.SizeToContent(); 

	m_nCodeType = 58;
	GetDlgItem(IDC_BARCODE_SET_STATIC)->SetWindowText(L"QR_CODE Setting");

	GetDlgItem(IDC_BARCODE_TEXT_EDIT)->SetFont(theApp.m_EditFont);

	m_barcodeDesignArea.SetWindowPos(NULL,-1,-1,781,37, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);//781, 161

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CBarCodeDlg::OnBnClickedBarcodeCloseBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
}

std::string ASCToUTF8(const std::string& str) 
{
	int unicodeLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);   
	wchar_t *pUnicode = new  wchar_t[unicodeLen + 1];   
	memset(pUnicode, 0, (unicodeLen + 1) * sizeof(wchar_t));  
	::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, (LPWSTR)pUnicode, unicodeLen);  
	std::wstring wrt = (wchar_t*)pUnicode;    delete  pUnicode;   
	int iTextLen = WideCharToMultiByte(CP_UTF8, 0, wrt.c_str(), -1, NULL, 0, NULL, NULL);  
	char *pElementText = new char[iTextLen + 1];   
	memset((void*)pElementText, 0, sizeof(char) * (iTextLen + 1)); 
	::WideCharToMultiByte(CP_UTF8, 0, wrt.c_str(), -1, pElementText, iTextLen, NULL, NULL);   
	std::string strText = pElementText;    delete pElementText;    
	return strText;
}
 
void CBarCodeDlg::Create2Dcode(int nType)
{
	struct zint_symbol *my_symbol;
    int error_number;
    int rotate_angle;
    int generated;
    int batch_mode;
    int mirror_mode;
    char filetype[4];
    int i;

	error_number = 0;
	rotate_angle = 0;
	generated = 0;
	my_symbol = ZBarcode_Create();
	my_symbol->input_mode = UNICODE_MODE;
	my_symbol->symbology = nType;
	if(nType == 20 || nType == 8)
		my_symbol->height = 12;	 

	my_symbol->scale = 0.5;
	batch_mode = 0;
	mirror_mode = 0;

	//CEdit* pEdit = (CEdit*)GetDlgItem(IDC_BARCODE_TEXT_EDIT);
	//CString str;
	//pEdit-> GetWindowText(str);
	//USES_CONVERSION;	
	//char * QRTEXT = W2A(str.GetBuffer(0));	
	//std::string strTmp = ASCToUTF8(QRTEXT);
	//////////////////////////////////////////////////////////////////////////

	std::string strTmp = "";
	for(int i = 0; i < theApp.m_MessageEdit.DynOBJ_Vec.size(); i++)
	{
		strTmp += theApp.m_MessageEdit.DynOBJ_Vec[i]->strText;
	}
	//////////////////////////////////////////////////////////////////////////
    error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strTmp.c_str(),strTmp.length(),rotate_angle);
	generated = 1;
	
	theApp.m_MessageEdit.isDynamicUse_classMessage = false;//
	int xPos=0;
	int yPos=0;
	theApp.m_MessageEdit.GetNextObjPosition(xPos,yPos);
	 
	OBJ_Control* bmpObj = new OBJ_Control;
	bmpObj->intLineStart = yPos;
	bmpObj->intRowStart = xPos;
	bmpObj->strType1 = "text";
	bmpObj->strType2 = "qrcode";

	bmpObj->intQRVersion = VersionBox.GetCurSel()+1;
	bmpObj->intQRErrLevel = ErrLevelBox.GetCurSel();
	bmpObj->intQREncodingMode = EncodingModeBox.GetCurSel();
	bmpObj->boQRBig = true;	 
	int version = bmpObj->intQRVersion;//设置版本号，这里设为2，对应尺寸：25 * 25
 	int casesensitive = bmpObj->boQRBig;//是否区分大小写，true/false

 	bmpObj->intLineSize = my_symbol->bitmap_height;
	bmpObj->intRowSize = my_symbol->bitmap_width;

	//以下先写死
	bmpObj->intSW = 1;
	bmpObj->intSS = 0;
	bmpObj->booNEG = false;
	bmpObj->booBWDx = false;
	bmpObj->booBWDy = false;
	i = 0;
	int r, g, b;

    for (int row = 0; row < my_symbol->bitmap_height; row++)
    {
		for (int col = 0;col < my_symbol->bitmap_width; col++)
		{
			r = my_symbol->bitmap[i];
            g = my_symbol->bitmap[i + 1];
            b = my_symbol->bitmap[i + 2];
            i += 3;
			if (r == 0 && g == 0 && b == 0)
			{
				bmpObj->boDotBmp[col][my_symbol->bitmap_height-row-1] = true;
			}
			else
			{
				bmpObj->boDotBmp[col][my_symbol->bitmap_height-row-1] = false;
			}
		}
    }


	ZBarcode_Delete(my_symbol);
	//bmpObj->strText = theApp.myModuleMain.CString2string(str);
	bmpObj->strText = strTmp;
	if((bmpObj->intRowStart+bmpObj->intRowSize) > theApp.m_MessageEdit.scrMaxRow)
	{
		theApp.m_MessageEdit.scrMaxRow = bmpObj->intRowStart+bmpObj->intRowSize;
	}
	bmpObj->booFocus = true;
	bmpObj->isDynamicUse_OBJ = false;

	for(int i=0;i<theApp.m_MessageEdit.DynOBJ_Vec.size();i++)
	{
		if ( theApp.m_MessageEdit.DynOBJ_Vec[i]->strType2 == "serial" || theApp.m_MessageEdit.DynOBJ_Vec[i]->strType2 == "time")
		{
			bmpObj->intDynamicQRPrint = 1;//动态二维码打印
		}
	}
	bmpObj->nBarcodeType = nType;
	bmpObj->Qr_Vec = theApp.m_MessageEdit.DynOBJ_Vec;
	theApp.m_MessageEdit.OBJ_Vec.push_back(bmpObj); 
}

void CBarCodeDlg::OnBnClickedQrCodeBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	m_nCodeType = 58;
	GetDlgItem(IDC_BARCODE_SET_STATIC)->SetWindowText(L"QR_CODE Setting");
}

void CBarCodeDlg::OnBnClickedDataMatrixBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	m_nCodeType = 71;
	GetDlgItem(IDC_BARCODE_SET_STATIC)->SetWindowText(L"DataMatrix Setting");

}

BOOL CBarCodeDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_BARCODE_TEXT_EDIT);
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

		//////////////////////////////////////////////////////////////////////////
		int xPos=0;
		int yPos=0;
		theApp.m_MessageEdit.GetNextObjPosition(xPos,yPos);
		OBJ_Control* tempObj = new OBJ_Control;
		tempObj->intLineStart=yPos;
		tempObj->intRowStart=xPos;
		tempObj->strType1="text";
		tempObj->strType2="text";
		//以下先写死
		tempObj->intSW=1;
		tempObj->intSS=0;
		tempObj->booNEG=false;
		tempObj->booBWDx=false;
		tempObj->booBWDy=false;

		CString strText;
		pEdit->GetWindowText(strText);
		//tempObj.strText=theApp.myModuleMain.CString2string(strText);
		tempObj->strText=theApp.myModuleMain.UnicodeToUtf8_CSTR(strText);

		CString  fontText = _T("7x5");//默认为7x5
		tempObj->intLineSize=7;
		tempObj->intRowSize=strText.GetLength()*6;//////////这是个坑，注意阿拉伯语要改这
		tempObj->strFont=theApp.myModuleMain.CString2string(fontText);

		if ((tempObj->intRowStart+tempObj->intRowSize)>theApp.m_MessageEdit.scrMaxRow)
		{
			theApp.m_MessageEdit.scrMaxRow=tempObj->intRowStart+tempObj->intRowSize;
		}

		tempObj->booFocus=true;
		tempObj->isDynamicUse_OBJ = true;//用于判断是否在二维码编辑界面绘制

		theApp.m_MessageEdit.DynOBJ_Vec.push_back(tempObj);
		//////////////////////////////////////////////////////////////////////////

		return TRUE;
	}


	return CDialog::PreTranslateMessage(pMsg);
}

void CBarCodeDlg::OnBnClickedBarcodeOkBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	Create2Dcode(m_nCodeType);
	this->ShowWindow(SW_HIDE);	
}

void CBarCodeDlg::OnCbnSelchangeBarcodeVersionCombo()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CBarCodeDlg::OnCbnSelchangeBarcodeEccLevCombo()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CBarCodeDlg::OnCbnSelchangeBarcodeZoneCombo()
{
	// TODO: 在此添加控件通知处理程序代码
}

HBRUSH CBarCodeDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

void CBarCodeDlg::OnBnClickedCode128Btn()
{
	// TODO: 在此添加控件通知处理程序代码
	m_nCodeType = 20;
	GetDlgItem(IDC_BARCODE_SET_STATIC)->SetWindowText(L"Code128 Setting");
}

void CBarCodeDlg::OnBnClickedCode39Btn()
{
	// TODO: 在此添加控件通知处理程序代码
	m_nCodeType = 8;
	GetDlgItem(IDC_BARCODE_SET_STATIC)->SetWindowText(L"Code39 Setting");
}

void CBarCodeDlg::OnBnClickedBarcodeFigureBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	CInputDlg *pInputDlg;
	pInputDlg = (CInputDlg*)this->GetParent();

	pInputDlg->pEditFigure->GetDlgItem(IDC_FIRST_QUARTILE_EDIT)->SetWindowText(_T("1"));
	pInputDlg->pEditFigure->GetDlgItem(IDC_FOUR_QUARTILE_EDIT)->SetWindowText(_T("999999999"));
	pInputDlg->pEditFigure->GetDlgItem(IDC_START_EDIT)->SetWindowText(_T("1"));
	pInputDlg->pEditFigure->GetDlgItem(IDC_STEP_SIZE_EDIT)->SetWindowText(_T("1"));
	pInputDlg->pEditFigure->GetDlgItem(IDC_REPEAT_COUNT_EDIT)->SetWindowText(_T("1"));
	pInputDlg->pEditFigure->GetDlgItem(IDC_BIT_DATA_EDIT)->SetWindowText(_T("9"));

	int nSerialNums = theApp.m_MessageEdit.ModifyGetSerialNums();
	if(nSerialNums == 4){
		CString csMsg=_T("操作失败！\n序列号已满！") ;//= _T("串口4打开失败!");
		AfxMessageBox(csMsg);
		return;
	}

	CComboBox *bitComBox = (CComboBox *)pInputDlg->pEditFigure->GetDlgItem(IDC_COUNTER_COMBO);
	bitComBox->ResetContent();
	CString str; str.Format(L"%d",nSerialNums+1);
	bitComBox->AddString(str);
	bitComBox->SetCurSel(0);
	bitComBox->EnableWindow(FALSE);

	pInputDlg->pEditFigure->RefreshSerial();


	pInputDlg->pEditFigure->ShowWindow(SW_SHOW);
	//////////////////////////////////////////////////////////////////////////
	pInputDlg->pEditFigure->isDynamicUse_figureDlg = true;
	theApp.m_MessageEdit.isDynamicUse_classMessage = true;
}

void CBarCodeDlg::OnBnClickedBarcodeDateBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	CInputDlg *pInputDlg;
	pInputDlg = (CInputDlg*)this->GetParent();
	pInputDlg->pDate->ShowWindow(SW_SHOW);
	//////////////////////////////////////////////////////////////////////////
	pInputDlg->pDate->isDynamicUse_dateDlg = true;
	theApp.m_MessageEdit.isDynamicUse_classMessage = true;
}

void CBarCodeDlg::OnBnClickedBarcodeLButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<theApp.m_MessageEdit.DynOBJ_Vec.size();i++)
	{
		if (theApp.m_MessageEdit.DynOBJ_Vec[i]->booFocus)
		{
			if (i>=0)
			{
				vector<OBJ_Control*> tempVec;
				tempVec = theApp.m_MessageEdit.DynOBJ_Vec;
				int curRowStart,previousRowStart;
				curRowStart = theApp.m_MessageEdit.DynOBJ_Vec[i]->intRowStart;
				previousRowStart = theApp.m_MessageEdit.DynOBJ_Vec[i-1]->intRowStart;

				theApp.m_MessageEdit.DynOBJ_Vec.erase(theApp.m_MessageEdit.DynOBJ_Vec.begin()+i);
				theApp.m_MessageEdit.DynOBJ_Vec.insert(theApp.m_MessageEdit.DynOBJ_Vec.begin()+i-1,tempVec[i]);
				theApp.m_MessageEdit.DynOBJ_Vec[i-1]->intRowStart = curRowStart - theApp.m_MessageEdit.DynOBJ_Vec[i]->intRowSize;
				theApp.m_MessageEdit.DynOBJ_Vec[i]->intRowStart = previousRowStart + theApp.m_MessageEdit.DynOBJ_Vec[i-1]->intRowSize;
			}
			else
			{
				break;
			}
			OnPaint();
			break;
		}
	}
	m_barcodeDesignArea.Invalidate();
}

void CBarCodeDlg::OnBnClickedBarcodeRButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<theApp.m_MessageEdit.DynOBJ_Vec.size();i++)
	{
		if (theApp.m_MessageEdit.DynOBJ_Vec[i]->booFocus)
		{
			if (i>=0)
			{
				vector<OBJ_Control*> tempVec;
				tempVec = theApp.m_MessageEdit.DynOBJ_Vec;
				int curRowStart,nextRowStart;
				curRowStart = theApp.m_MessageEdit.DynOBJ_Vec[i]->intRowStart;
				nextRowStart = theApp.m_MessageEdit.DynOBJ_Vec[i+1]->intRowStart;

				theApp.m_MessageEdit.DynOBJ_Vec.erase(theApp.m_MessageEdit.DynOBJ_Vec.begin()+i);
				theApp.m_MessageEdit.DynOBJ_Vec.insert(theApp.m_MessageEdit.DynOBJ_Vec.begin()+i+1,tempVec[i]);
				theApp.m_MessageEdit.DynOBJ_Vec[i]->intRowStart = nextRowStart - theApp.m_MessageEdit.DynOBJ_Vec[i+1]->intRowSize;
				theApp.m_MessageEdit.DynOBJ_Vec[i+1]->intRowStart = curRowStart + theApp.m_MessageEdit.DynOBJ_Vec[i]->intRowSize;
			}
			else
			{
				break;
			}
			OnPaint();
			break;
		}
	}
	m_barcodeDesignArea.Invalidate();
}
void CBarCodeDlg::OnBnClickedBarcodeDelButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for(vector<OBJ_Control*>::iterator iterTemp=theApp.m_MessageEdit.DynOBJ_Vec.begin();iterTemp!=theApp.m_MessageEdit.DynOBJ_Vec.end();iterTemp++)
	{
		if ((*iterTemp)->booFocus)
		{
			int curRowSize = (*iterTemp)->intRowSize;
			theApp.m_MessageEdit.DynOBJ_Vec.erase(iterTemp);
			for (iterTemp;iterTemp!=theApp.m_MessageEdit.DynOBJ_Vec.end();iterTemp++)
			{
				(*iterTemp)->intRowStart = (*iterTemp)->intRowStart - curRowSize;
			}
			break;
		}
	}
	vector<OBJ_Control*>::iterator iterTemp = theApp.m_MessageEdit.DynOBJ_Vec.begin();
	if (iterTemp != theApp.m_MessageEdit.DynOBJ_Vec.end())
	{
		(*iterTemp)->booFocus = true;
	}
	m_barcodeDesignArea.Invalidate();
}

void CBarCodeDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialog::OnPaint()
	theApp.m_MessageEdit.isDynamicUse_classMessage = true;
	m_barcodeDesignArea.Invalidate();
}

//重写鼠标单击
void CBarCodeDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
		CRect lRect;
	m_barcodeDesignArea.GetWindowRect(&lRect);  //获取控件相对于屏幕的位置
	ScreenToClient(&lRect);
	//m_nSelectObjIndex = -1;
	if((point.x >= lRect.left && point.x <= lRect.right) && (point.y >= lRect.top && point.y <= lRect.bottom))
	{
		point.x -= lRect.left;
		point.y -= lRect.top;
		int nRow;
		int nCol;	 
		//nRow = (161-point.y) / 5;
		nRow = (50-point.y) / 5;
		nCol = (point.x / 5)+theApp.scrPox;
		/*for (size_t i = 0; i < theApp.m_MessageEdit.OBJ_Vec.size(); i++)
		{
			theApp.m_MessageEdit.OBJ_Vec[i]->booFocus = false;
		}*/
		vector<OBJ_Control*>::iterator itr = theApp.m_MessageEdit.DynOBJ_Vec.begin();
		bool isFind=false;
		while (itr != theApp.m_MessageEdit.DynOBJ_Vec.end())
		{					 
			(*itr)->booFocus = false;
			if (isFind)
			{
				++itr;
				continue;
			}
			if (nRow>=(*itr)->intLineStart&&nRow<=((*itr)->intLineStart+(*itr)->intLineSize)
				&&nCol>=(*itr)->intRowStart&&nCol<=((*itr)->intRowStart+(*itr)->intRowSize))
			{
				(*itr)->booFocus=true;
				isFind=true;
			}
			++itr;
		}
		OnPaint();
	}

	CDialog::OnLButtonDown(nFlags, point);
}


