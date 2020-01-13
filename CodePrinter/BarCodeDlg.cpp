// BarCodeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "BarCodeDlg.h"
#include "qrencode.h"
//#include "ModuleMain.h"
#include "qrcode\zint.h"


#pragma comment(lib,"lib\\QRlib.lib")
// CBarCodeDlg �Ի���

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
	DDX_Control(pDX, IDC_BARCODE_TEXT_STATIC, m_barText);
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
END_MESSAGE_MAP()


// CBarCodeDlg ��Ϣ�������

BOOL CBarCodeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	VersionBox.AddString(_T("21x21"));
	VersionBox.AddString(_T("25x25"));
	//VersionBox.AddString(_T("1L25M"));
	//VersionBox.AddString(_T("2L7M"));
	VersionBox.SetCurSel(1);
	VersionBox.SetFont(theApp.m_ListBoxFont);//��������������
	VersionBox.SendMessage(CB_SETITEMHEIGHT,-1,30);//����������߶�
	VersionBox.SendMessage(CB_SETITEMHEIGHT,0,30);//������������Ŀ�߶�

	ErrLevelBox.AddString(_T("L"));
	ErrLevelBox.AddString(_T("M"));
	ErrLevelBox.AddString(_T("Q"));
	ErrLevelBox.AddString(_T("H"));
	ErrLevelBox.SetCurSel(3);
	ErrLevelBox.SetFont(theApp.m_ListBoxFont);
	ErrLevelBox.SendMessage(CB_SETITEMHEIGHT,-1,30);//����������߶�
	ErrLevelBox.SendMessage(CB_SETITEMHEIGHT,0,30);//������������Ŀ�߶�

	EncodingModeBox.AddString(_T("Numeric"));
	EncodingModeBox.AddString(_T("Alphabet-numeric"));
	EncodingModeBox.AddString(_T("8-bit data"));
	EncodingModeBox.AddString(_T("Kanji"));
	EncodingModeBox.AddString(_T("STRUCTURE"));
	EncodingModeBox.AddString(_T("ECI"));
	EncodingModeBox.AddString(_T("FNC1FIRST"));
	EncodingModeBox.AddString(_T("FNC1SECOND"));
	EncodingModeBox.SetCurSel(2);
	EncodingModeBox.SetFont(theApp.m_ListBoxFont);//��������������
	EncodingModeBox.SendMessage(CB_SETITEMHEIGHT,-1,30);//����������߶�
	EncodingModeBox.SendMessage(CB_SETITEMHEIGHT,0,30);//������������Ŀ�߶�

	GetDlgItem(IDC_BARCODE_CLOSE_BTN)->SetWindowPos(NULL,20,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_QR_CODE_BTN)->SetWindowPos(NULL,200,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_DATA_MATRIX_BTN)->SetWindowPos(NULL,300,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_CODE_39_BTN)->SetWindowPos(NULL,400,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_CODE_128_BTN)->SetWindowPos(NULL,500,390,70,45,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BARCODE_OK_BTN)->SetWindowPos(NULL,700,390,70,45,SWP_SHOWWINDOW);

	m_returnIB.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_returnIB.SizeToContent(); 
	m_qrCodeIB.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_RANGE_BITMAP,true);
	m_qrCodeIB.SizeToContent(); 
	m_dataMatrixIB.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RANGE_BITMAP,true);
	m_dataMatrixIB.SizeToContent(); 
	m_code39IB.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_RANGE_BITMAP,true);
	m_code39IB.SizeToContent(); 
	m_code128IB.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RANGE_BITMAP,true);
	m_code128IB.SizeToContent(); 
	m_okIB.LoadBitmaps(IDB_OK1_BITMAP,IDB_OK2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_okIB.SizeToContent(); 
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CBarCodeDlg::OnBnClickedBarcodeCloseBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_BARCODE_TEXT_EDIT);
	CString str;
	pEdit-> GetWindowText(str);     
	USES_CONVERSION;	
	char * QRTEXT = W2A(str.GetBuffer(0));	
	std::string strTmp = ASCToUTF8(QRTEXT);
	error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strTmp.c_str(),strTmp.length(),rotate_angle);
	generated = 1;
 	//if (error_number < 5)  
	//	error_number = ZBarcode_Print(my_symbol, rotate_angle);

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
 
	OBJ_Control bmpObj;
	bmpObj.intLineStart=yPos;
	bmpObj.intRowStart=xPos;
	bmpObj.strType1="text";
	bmpObj.strType2="qrcode";

	bmpObj.intQRVersion=VersionBox.GetCurSel()+1;
	bmpObj.intQRErrLevel=ErrLevelBox.GetCurSel();
	bmpObj.intQREncodingMode=EncodingModeBox.GetCurSel();
	bmpObj.boQRBig = true;	 
	int version = bmpObj.intQRVersion;//���ð汾�ţ�������Ϊ2����Ӧ�ߴ磺25 * 25
 	int casesensitive = bmpObj.boQRBig;//�Ƿ����ִ�Сд��true/false

 	bmpObj.intLineSize=my_symbol->width;
	bmpObj.intRowSize=my_symbol->width;

	//������д��
	bmpObj.intSW=1;
	bmpObj.intSS=0;
	bmpObj.booNEG=false;
	bmpObj.booBWDx=false;
	bmpObj.booBWDy=false;
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
				bmpObj.boDotBmp[row][col] = true;
			}
			else
			{
				bmpObj.boDotBmp[row][col] = false;
			}
		}
    }
	bmpObj.strText=theApp.myModuleMain.CString2string(str);
	bmpObj.booFocus = true;
	theApp.myclassMessage.OBJ_Vec.push_back(bmpObj); 
}

void CBarCodeDlg::OnBnClickedQrCodeBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Create2Dcode(58);
}

void CBarCodeDlg::OnBnClickedDataMatrixBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Create2Dcode(71);
}

BOOL CBarCodeDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->ShowWindow(SW_HIDE);
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_BARCODE_TEXT_EDIT);
	CString str;
	pEdit-> GetWindowText(str);
    //ModuleMain bQModule;

	//char szStr[256] = {};  
	//wcstombs(szStr, str, str.GetLength());//�����ַ�ת���ɶ��ַ�  

	//const char * QRTEXT = bQModule.CString2ConstChar(str);

	USES_CONVERSION;
	//����T2A��W2A��֧��ATL��MFC�е��ַ�
	//char * pFileName = T2A(str);  
	const char * QRTEXT = W2A(str.GetBuffer(0));
   // QRTEXT="һ111";
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
	int version = bmpObj.intQRVersion;//���ð汾�ţ�������Ϊ2����Ӧ�ߴ磺25 * 25
	QRecLevel level = (QRecLevel)bmpObj.intQRErrLevel;//������
	QRencodeMode hint = (QRencodeMode)bmpObj.intQREncodingMode;//����ģʽ
	int casesensitive = bmpObj.boQRBig;//�Ƿ����ִ�Сд��true/false
	qrCode = QRcode_encodeString(QRTEXT, version, level, hint, casesensitive);
	if (NULL == qrCode)
	{
		return;
	}
	bmpObj.intLineSize=qrCode->width;
	bmpObj.intRowSize=qrCode->width;
	//������д��
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
	delete QRTEXT;
	delete qrCode;
}

void CBarCodeDlg::OnCbnSelchangeBarcodeVersionCombo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CBarCodeDlg::OnCbnSelchangeBarcodeEccLevCombo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CBarCodeDlg::OnCbnSelchangeBarcodeZoneCombo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ˸��� DC ���κ�����
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return theApp.m_DlgBrush;
}
void CBarCodeDlg::OnBnClickedCode128Btn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Create2Dcode(20);
}

void CBarCodeDlg::OnBnClickedCode39Btn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Create2Dcode(8);
}
