// InputDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "InputDlg.h"
#include "EditTextDlg.h"
#include "EditFigureDlg.h"
#include "DateDlg.h"
#include "PictureDlg.h"
#include "BarCodeDlg.h"
#include <atlimage.h>
#include "..\PathDlgDll\PathDlgDll\PathDlgDll.h"
// CInputDlg 对话框

IMPLEMENT_DYNAMIC(CInputDlg, CDialog)

CInputDlg::CInputDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInputDlg::IDD, pParent)
{

}

CInputDlg::~CInputDlg()
{
}

void CInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDITTEXT_BUTTON, m_editTextIB);
	DDX_Control(pDX, IDC_EDITFIGURE_BUTTON, m_editFigureIB);
	DDX_Control(pDX, IDC_EDITDATE_BUTTON, m_editDateIB);
	DDX_Control(pDX, IDC_EDITPICTURE_BUTTON, m_editPictureIB);
	DDX_Control(pDX, IDC_BARCODE_BUTTON, m_editCodeIB);
	DDX_Control(pDX, IDC_ODBC_BUTTON, m_odbcIB);
	DDX_Control(pDX, IDC_INPUT_CLOSE_BTN, m_returnIB);
}


BEGIN_MESSAGE_MAP(CInputDlg, CDialog)
	ON_BN_CLICKED(IDC_EDITTEXT_BUTTON, &CInputDlg::OnBnClickedEdittextButton)
	ON_BN_CLICKED(IDC_EDITFIGURE_BUTTON, &CInputDlg::OnBnClickedEditfigureButton)
	ON_BN_CLICKED(IDC_EDITDATE_BUTTON, &CInputDlg::OnBnClickedEditdateButton)
	ON_BN_CLICKED(IDC_EDITPICTURE_BUTTON, &CInputDlg::OnBnClickedEditpictureButton)
	ON_BN_CLICKED(IDC_BARCODE_BUTTON, &CInputDlg::OnBnClickedBarcodeButton)
	ON_BN_CLICKED(IDC_INPUT_CLOSE_BTN, &CInputDlg::OnBnClickedInputCloseBtn)
	ON_WM_CTLCOLOR()

END_MESSAGE_MAP()


// CInputDlg 消息处理程序

BOOL CInputDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	pEditText = new CEditTextDlg;
	pEditFigure = new CEditFigureDlg;
	pDate = new CDateDlg;
	pPic = new CPictureDlg;
	pBarCode = new CBarCodeDlg;

	int nX = 0;
	int nY = 90;
	int nWidth = 800;
	int nHeight = 600-nY;
	pEditText->Create(IDD_EDITTEXT_DIALOG,this);
	pEditText->MoveWindow(nX,nY,nWidth,nHeight);

	pEditFigure->Create(IDD_EDITFIGURE_DIALOG,this);
	pEditFigure->MoveWindow(nX,nY,nWidth,nHeight);
	pEditFigure->ShowWindow(SW_HIDE);

	pDate->Create(IDD_DATE_DIALOG,this);
	pDate->MoveWindow(nX,nY,nWidth,nHeight);
	pDate->ShowWindow(SW_HIDE);

	pPic->Create(IDD_PICTURE_DIALOG,this);
	pPic->MoveWindow(nX,nY,nWidth,nHeight);

	pBarCode->Create(IDD_BARCODE_DIALOG,this);
	pBarCode->MoveWindow(nX,nY,nWidth,nHeight);
	pBarCode->ShowWindow(SW_HIDE);

//要改
	CRect rect1;
	GetDlgItem(IDC_EDITFIGURE_BUTTON)->GetWindowRect(&rect1);

	GetDlgItem(IDC_EDITTEXT_BUTTON)->SetWindowPos(NULL,224,80,60,40,SWP_SHOWWINDOW);//IDC_SYSTEM_CANCEL_BTN
	GetDlgItem(IDC_EDITFIGURE_BUTTON)->SetWindowPos(NULL,354,80,60,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_EDITDATE_BUTTON)->SetWindowPos(NULL,484,80,60,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_EDITPICTURE_BUTTON)->SetWindowPos(NULL,224,140,60,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BARCODE_BUTTON)->SetWindowPos(NULL,354,140,60,405,SWP_SHOWWINDOW);
	GetDlgItem(IDC_ODBC_BUTTON)->SetWindowPos(NULL,484,140,60,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_INPUT_CLOSE_BTN)->SetWindowPos(NULL,20,220,70,45,SWP_SHOWWINDOW);

	m_editTextIB.LoadBitmaps(IDB_ABC1_BITMAP,IDB_ABC2_BITMAP,0,0,IDB_60_40_BITMAP);
	m_editTextIB.SizeToContent(); 
	m_editFigureIB.LoadBitmaps(IDB_EDIT_FIGURE1_BITMAP,IDB_EDIT_FIGURE2_BITMAP,0,0,IDB_60_40_BITMAP);
	m_editFigureIB.SizeToContent(); 
	m_editDateIB.LoadBitmaps(IDB_EDIT_DATE1_BITMAP,IDB_EDIT_DATE2_BITMAP,0,0,IDB_60_40_BITMAP);
	m_editDateIB.SizeToContent(); 
	m_editPictureIB.LoadBitmaps(IDB_EDIT_PIC1_BITMAP,IDB_EDIT_PIC2_BITMAP,0,0,IDB_60_40_BITMAP);
	m_editPictureIB.SizeToContent(); 
	m_editCodeIB.LoadBitmaps(IDB_EDIT_CODE1_BITMAP,IDB_EDIT_CODE2_BITMAP,0,0,IDB_60_40_BITMAP);
	m_editCodeIB.SizeToContent(); 
	m_odbcIB.LoadBitmaps(IDB_ODBC1_BITMAP,IDB_ODBC2_BITMAP,0,0,IDB_60_40_BITMAP);
	m_odbcIB.SizeToContent(); 
	m_returnIB.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_returnIB.SizeToContent(); 

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CInputDlg::OnBnClickedEdittextButton()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
	showInputDlg(IDD_EDITTEXT_DIALOG);
}

void CInputDlg::OnBnClickedEditfigureButton()
{
	// TODO: 在此添加控件通知处理程序代码
	showInputDlg(IDD_EDITFIGURE_DIALOG);
}

void CInputDlg::OnBnClickedEditdateButton()
{
	// TODO: 在此添加控件通知处理程序代码
	showInputDlg(IDD_DATE_DIALOG);
}

void CInputDlg::OnBnClickedEditpictureButton()
{
	// TODO: 在此添加控件通知处理程序代码
	//showInputDlg(IDD_PICTURE_DIALOG);
	TCHAR path[MAX_PATH];
	//labModule.string2tchar(testpath,path);

	string xmlPath;
	if(ShowPathDlg(path, MAX_PATH,2))
	{
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
		xmlPath=theApp.myModuleMain.TCHAR2STRING(path);
		//CImage myImage;
		//myImage.Load(NULL);
		OBJ_Control bmpObj;
		bmpObj.intLineStart=yPos;
		bmpObj.intRowStart=xPos;
		bmpObj.ReadBmp(const_cast<char*>(xmlPath.c_str()));//这个最好返回一个bool变量,就能省去if了
        if (bmpObj.intLineSize<=0||bmpObj.intRowSize<=0)
        {
			return;
        }
		bmpObj.strType1="text";
		bmpObj.strType2="logo";
		//以下先写死
		bmpObj.intSW=1;
		bmpObj.intSS=0;
		bmpObj.booNEG=false;
		bmpObj.booBWDx=false;
		bmpObj.booBWDy=false;

		//bmpObj.strFont="7x5";
		bmpObj.strText=xmlPath;
		bmpObj.booFocus=true;
		theApp.myclassMessage.OBJ_Vec.push_back(bmpObj);
	}
}

void CInputDlg::OnBnClickedBarcodeButton()
{
	// TODO: 在此添加控件通知处理程序代码
	showInputDlg(IDD_BARCODE_DIALOG);
	this->ShowWindow(SW_HIDE);
}

void CInputDlg::OnBnClickedInputCloseBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	this->ShowWindow(SW_HIDE);
}

void CInputDlg::showInputDlg(int ID)
{
	pEditText->ShowWindow(SW_HIDE);
	pEditFigure->ShowWindow(SW_HIDE);
	pDate->ShowWindow(SW_HIDE);
	pPic->ShowWindow(SW_HIDE);
	pBarCode->ShowWindow(SW_HIDE);

	if (ID ==IDD_EDITTEXT_DIALOG)
	{
		pEditText->ShowWindow(SW_SHOW);
	}
	else if (ID == IDD_EDITFIGURE_DIALOG)
	{
		pEditFigure->ShowWindow(SW_SHOW);
	}
	else if (ID == IDD_DATE_DIALOG)
	{
		pDate->ShowWindow(SW_SHOW);
	}
	else if (ID == IDD_PICTURE_DIALOG)
	{
		pPic->ShowWindow(SW_SHOW);
	}
	else if (ID == IDD_BARCODE_DIALOG)
	{
		pBarCode->ShowWindow(SW_SHOW);
	}
	
}


HBRUSH CInputDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return theApp.m_DlgBrush;
}
