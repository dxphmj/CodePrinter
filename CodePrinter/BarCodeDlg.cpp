// BarCodeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "BarCodeDlg.h"
#include "qrencode.h"
#include "ModuleMain.h"
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
}


BEGIN_MESSAGE_MAP(CBarCodeDlg, CDialog)
	

	ON_BN_CLICKED(IDC_BARCODE_CLOSE_BTN, &CBarCodeDlg::OnBnClickedBarcodeCloseBtn)
	ON_BN_CLICKED(IDC_QR_CODE_BTN, &CBarCodeDlg::OnBnClickedQrCodeBtn)
	ON_BN_CLICKED(IDC_DATA_MATRIX_BTN, &CBarCodeDlg::OnBnClickedDataMatrixBtn)
	ON_BN_CLICKED(IDC_BARCODE_OK_BTN, &CBarCodeDlg::OnBnClickedBarcodeOkBtn)
	ON_CBN_SELCHANGE(IDC_BARCODE_VERSION_COMBO, &CBarCodeDlg::OnCbnSelchangeBarcodeVersionCombo)
	ON_CBN_SELCHANGE(IDC_BARCODE_ECC_LEV_COMBO, &CBarCodeDlg::OnCbnSelchangeBarcodeEccLevCombo)
	ON_CBN_SELCHANGE(IDC_BARCODE_ZONE_COMBO, &CBarCodeDlg::OnCbnSelchangeBarcodeZoneCombo)
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
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CBarCodeDlg::OnBnClickedBarcodeCloseBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	this->ShowWindow(SW_HIDE);
}

void CBarCodeDlg::OnBnClickedQrCodeBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CBarCodeDlg::OnBnClickedDataMatrixBtn()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
    ModuleMain bQModule;

	//char szStr[256] = {};  
	//wcstombs(szStr, str, str.GetLength());//�����ַ�ת���ɶ��ַ�  

	//const char * QRTEXT = bQModule.CString2ConstChar(str);

	USES_CONVERSION;
	//����T2A��W2A��֧��ATL��MFC�е��ַ�
	//char * pFileName = T2A(str);  
	const char * QRTEXT = W2A(str.GetBuffer(0));
    QRTEXT="һ111";
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
	bmpObj.strText=bQModule.CString2string(str);
	bmpObj.booFocus=true;
	theApp.myclassMessage.OBJ_Vec.push_back(bmpObj);

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
