// BarCodeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "BarCodeDlg.h"
#include "qrencode.h"
//#include "ModuleMain.h"
#pragma comment(lib,"lib\\QRlib.lib")
// CBarCodeDlg 对话框

IMPLEMENT_DYNAMIC(CBarCodeDlg, CDialog)

CBarCodeDlg::CBarCodeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBarCodeDlg::IDD, pParent)
{

}

CBarCodeDlg::~CBarCodeDlg()
{
}

void CBarCodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BARCODE_VERSION_COMBO, VersionBox);
	DDX_Control(pDX, IDC_BARCODE_ECC_LEV_COMBO, ErrLevelBox);
	DDX_Control(pDX, IDC_BARCODE_ZONE_COMBO, EncodingModeBox);

	DDX_Control(pDX, IDC_BARCODE_CLOSE_BTN, m_returnIB);
	DDX_Control(pDX, IDC_QR_CODE_BTN, m_qrCodeIB);
	DDX_Control(pDX, IDC_DATA_MATRIX_BTN, m_dataMatrixIB);
	DDX_Control(pDX, IDC_CODE_39_BTN, m_code39IB);
	DDX_Control(pDX, IDC_CODE_128_BTN, m_code128IB);
	DDX_Control(pDX, IDC_BARCODE_OK_BTN, m_okIB);
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

	ErrLevelBox.AddString(_T("L"));
	ErrLevelBox.AddString(_T("M"));
	ErrLevelBox.AddString(_T("Q"));
	ErrLevelBox.AddString(_T("H"));
	ErrLevelBox.SetCurSel(3);

	EncodingModeBox.AddString(_T("Numeric"));
	EncodingModeBox.AddString(_T("Alphabet-numeric"));
	EncodingModeBox.AddString(_T("8-bit data"));
	EncodingModeBox.AddString(_T("Kanji"));
	EncodingModeBox.AddString(_T("STRUCTURE"));
	EncodingModeBox.AddString(_T("ECI"));
	EncodingModeBox.AddString(_T("FNC1FIRST"));
	EncodingModeBox.AddString(_T("FNC1SECOND"));
	EncodingModeBox.SetCurSel(2);

	GetDlgItem(IDC_BARCODE_CLOSE_BTN)->SetWindowPos(NULL,20,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_QR_CODE_BTN)->SetWindowPos(NULL,200,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_DATA_MATRIX_BTN)->SetWindowPos(NULL,300,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_CODE_39_BTN)->SetWindowPos(NULL,400,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_CODE_128_BTN)->SetWindowPos(NULL,500,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BARCODE_OK_BTN)->SetWindowPos(NULL,700,390,70,45,SWP_SHOWWINDOW);

	m_returnIB.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_returnIB.SizeToContent(); 
	m_qrCodeIB.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_qrCodeIB.SizeToContent(); 
	m_dataMatrixIB.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_dataMatrixIB.SizeToContent(); 
	m_code39IB.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_code39IB.SizeToContent(); 
	m_code128IB.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_code128IB.SizeToContent(); 
	m_okIB.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_okIB.SizeToContent(); 
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CBarCodeDlg::OnBnClickedBarcodeCloseBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
}

void CBarCodeDlg::OnBnClickedQrCodeBtn()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CBarCodeDlg::OnBnClickedDataMatrixBtn()
{
	// TODO: 在此添加控件通知处理程序代码
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
		return TRUE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CBarCodeDlg::OnBnClickedBarcodeOkBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_BARCODE_TEXT_EDIT);
	CString str;
	pEdit-> GetWindowText(str);
    //ModuleMain bQModule;

	//char szStr[256] = {};  
	//wcstombs(szStr, str, str.GetLength());//将宽字符转换成多字符  

	//const char * QRTEXT = bQModule.CString2ConstChar(str);

	USES_CONVERSION;
	//函数T2A和W2A均支持ATL和MFC中的字符
	//char * pFileName = T2A(str);  
	const char * QRTEXT = W2A(str.GetBuffer(0));
   // QRTEXT="一111";
	int xPos=0;
	int yPos=0;
	for(int i=0;i<theApp.myclassMessage.OBJ_Vec.size();i++)
	{
		if (theApp.myclassMessage.OBJ_Vec.at(i).booFocus)
		{
			theApp.myclassMessage.OBJ_Vec.at(i).booFocus=false;
			yPos=theApp.myclassMessage.OBJ_Vec.at(i).intLineStart;
			xPos=theApp.myclassMessage.OBJ_Vec.at(i).intRowSize+theApp.myclassMessage.OBJ_Vec.at(i).intRowStart;
		}
	}
	//xmlPath=bQModule.TCHAR2STRING(path);
	//CImage myImage;
	//myImage.Load(NULL);
	OBJ_Control bmpObj;
	bmpObj.intLineStart=yPos;
	bmpObj.intRowStart=xPos;
	bmpObj.strType1="text";
	bmpObj.strType2="qrcode";

	bmpObj.intQRVersion=VersionBox.GetCurSel()+1;
	bmpObj.intQRErrLevel=ErrLevelBox.GetCurSel();
	bmpObj.intQREncodingMode=EncodingModeBox.GetCurSel();
	bmpObj.boQRBig=true;

	QRcode * qrCode;
	int version = bmpObj.intQRVersion;//设置版本号，这里设为2，对应尺寸：25 * 25
	QRecLevel level = (QRecLevel)bmpObj.intQRErrLevel;//纠错级别
	QRencodeMode hint = (QRencodeMode)bmpObj.intQREncodingMode;//编码模式
	int casesensitive = bmpObj.boQRBig;//是否区分大小写，true/false
	qrCode = QRcode_encodeString(QRTEXT, version, level, hint, casesensitive);
	if (NULL == qrCode)
	{
		return;
	}
	bmpObj.intLineSize=qrCode->width;
	bmpObj.intRowSize=qrCode->width;
	//以下先写死
	bmpObj.intSW=1;
	bmpObj.intSS=0;
	bmpObj.booNEG=false;
	bmpObj.booBWDx=false;
	bmpObj.booBWDy=false;
    for (int i=0;i<qrCode->width;i++)
    {
		for (int j=0;j<qrCode->width;j++)
		{
			if (qrCode->data[j*qrCode->width + i] & 0x01)
			{
				bmpObj.boDotBmp[i][qrCode->width-j-1]=true;
			}
			else
			{
				bmpObj.boDotBmp[i][qrCode->width-1-j]=false;
			}
		}
    }
	//bmpObj.strFont="7x5";
	bmpObj.strText=theApp.myModuleMain.CString2string(str);
	bmpObj.booFocus=true;
	theApp.myclassMessage.OBJ_Vec.push_back(bmpObj);

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
	}
	// TODO:  在此更改 DC 的任何属性
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return theApp.m_DlgBrush;
}