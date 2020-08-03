// LabelDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "CodePrinterDlg.h"
#include "LabelDlg.h"
#include "InputDlg.h"
#include <sstream>
#include <map>
#include "..\KEYBOARD\KEYBOARD\ExportDlg.h"
#include "..\PathDlgDll\PathDlgDll\PathDlgDll.h"

#include "qrcode\zint.h"

LPCWSTR stringToLPCWSTR(std::string orig)
{
	size_t origsize = orig.length() + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t *wcstring = (wchar_t *)malloc(sizeof(wchar_t)*(orig.length()-1));
	mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);

	return wcstring;
}

IMPLEMENT_DYNAMIC(CLabelDlg, CDialog)

CLabelDlg::CLabelDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLabelDlg::IDD, pParent)
	, m_zoomLevel(1)
	, m_ssValue(0)
{
	m_PicBitmap[0].LoadBitmap(IDB_BITMAP_NOTCHANGE);
	m_PicBitmap[1].LoadBitmap(IDB_BITMAP_RBLACK);
	m_PicBitmap[2].LoadBitmap(IDB_BITMAP_RTOPDOWN);
	m_PicBitmap[3].LoadBitmap(IDB_BITMAP_RLEFTRIGHT);
	m_PicBitmap[4].LoadBitmap(IDB_BITMAP_RALL);

	for(int i=0;i<5;i++)
	{
		m_PichBmp[i]=(HBITMAP)m_PicBitmap[i].GetSafeHandle();
	}
}

CLabelDlg::~CLabelDlg()
{
}

void CLabelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_MATRIX, ComboMatrix);
	DDX_Control(pDX, IDC_COMBO2, pixelComboBox);
	DDX_Control(pDX, IDC_STATIC_DESIGN_AREA, m_designArea);

	DDX_Control(pDX, IDC_SHRINK_BUTTON, m_shrink);
	DDX_Control(pDX, IDC_ZOOM_BUTTON, m_zoom);
	DDX_Control(pDX, IDC_NOZZLE_VALVE_BTN, m_notback);
	DDX_Control(pDX, IDC_ADDBACK_BTN, m_addback);
	DDX_Control(pDX, IDC_CLOSE_USER_BTN, m_close);
	DDX_Control(pDX, IDC_FAR_BUTTON, m_far);
	DDX_Control(pDX, IDC_UDMIRROR_BUTTON, m_UD_mirror);
	DDX_Control(pDX, IDC_LRMIRROR_BUTTON, m_LR_mirror);
	DDX_Control(pDX, IDC_LSELECT_BUTTON, m_L_select);
	DDX_Control(pDX, IDC_RSELECT_BUTTON, m_R_select);
	DDX_Control(pDX, IDC_USHIFT_BUTTON, m_U_shift);
	DDX_Control(pDX, IDC_DSHIFT_BUTTON, m_D_shift);
	DDX_Control(pDX, IDC_LSHIFT_BUTTON, m_L_shift);
	DDX_Control(pDX, IDC_RSHIFT_BUTTON, m_R_shift);
	DDX_Control(pDX, IDC_LQSHIFT_BUTTON, m_L_Qshift);
	DDX_Control(pDX, IDC_RQSHIFT_BUTTON, m_R_Qshift);
	DDX_Control(pDX, IDC_DOWNLOAD_BUTTON, m_download);
	DDX_Control(pDX, IDC_CLS_BUTTON, m_newlyBuilt);
	DDX_Control(pDX, IDC_OPEN_BUTTON, m_open);
	DDX_Control(pDX, IDC_SAVE_BUTTON, m_save);
	DDX_Control(pDX, IDC_LABEL_CLOSE_BTN, m_return);

	DDX_Control(pDX, IDC_INPUT_BUTTON, m_input);
	DDX_Control(pDX, IDC_REPEAT_BUTTON, m_repeat);
	DDX_Control(pDX, IDC_COPY_BUTTON, m_copy);
	DDX_Control(pDX, IDC_DELETE_BUTTON, m_delete);

	DDX_Text(pDX, IDC_SHRIK_Z_EDIT, m_zoomLevel);
	DDV_MinMaxInt(pDX, m_zoomLevel, 1, 4);
	DDX_Text(pDX, IDC_CLOSE_F_EDIT, m_ssValue);
	DDV_MinMaxInt(pDX, m_ssValue, 0, 4);

	DDX_Control(pDX, IDC_STATIC_ISBNG, m_picBNG);
	DDX_Control(pDX, IDC_STATIC_ISOVERTURN, m_picOverturn);
	DDX_Control(pDX, IDC_MATRIX_STATIC, m_matrixStatic);
	DDX_Control(pDX, IDC_PIXEL_STATIC, m_pixelStatic);
	DDX_Control(pDX, IDC_REVERSAL_STATIC, m_reversalStatic);
	DDX_Control(pDX, IDC_PERVERSION_STATIC, m_perversionStatic);
	DDX_Control(pDX, IDC_REVERSAL_COMBO, m_reversalCombo);
	DDX_Control(pDX, IDC_PERVERSION_COMBO, m_reversionCombo);
	DDX_Control(pDX, IDC_SCROLLBAR_LABEL, m_ScrollLab);
}


BEGIN_MESSAGE_MAP(CLabelDlg, CDialog)
	ON_BN_CLICKED(IDC_INPUT_BUTTON, &CLabelDlg::OnBnClickedInputButton)

	ON_WM_PAINT()
	ON_CBN_SELCHANGE(IDC_COMBO_MATRIX, &CLabelDlg::OnCbnSelchangeComboMatrix)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CLabelDlg::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_USHIFT_BUTTON, &CLabelDlg::OnBnClickedUshiftButton)
	ON_BN_CLICKED(IDC_LSELECT_BUTTON, &CLabelDlg::OnBnClickedLselectButton)
	ON_BN_CLICKED(IDC_RSELECT_BUTTON, &CLabelDlg::OnBnClickedRselectButton)
	ON_BN_CLICKED(IDC_DSHIFT_BUTTON, &CLabelDlg::OnBnClickedDshiftButton)
	ON_BN_CLICKED(IDC_LSHIFT_BUTTON, &CLabelDlg::OnBnClickedLshiftButton)
	ON_BN_CLICKED(IDC_RSHIFT_BUTTON, &CLabelDlg::OnBnClickedRshiftButton)
	ON_BN_CLICKED(IDC_LQSHIFT_BUTTON, &CLabelDlg::OnBnClickedLqshiftButton)
	ON_BN_CLICKED(IDC_RQSHIFT_BUTTON, &CLabelDlg::OnBnClickedRqshiftButton)
	ON_BN_CLICKED(IDC_SAVE_BUTTON, &CLabelDlg::OnBnClickedSaveButton)
	ON_BN_CLICKED(IDC_OPEN_BUTTON, &CLabelDlg::OnBnClickedOpenButton)
	ON_BN_CLICKED(IDC_REPEAT_BUTTON, &CLabelDlg::OnBnClickedRepeatButton)
	ON_BN_CLICKED(IDC_ZOOM_BUTTON, &CLabelDlg::OnBnClickedZoomButton)
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_DOWNLOAD_BUTTON, &CLabelDlg::OnBnClickedDownloadButton)
	ON_BN_CLICKED(IDC_LABEL_CLOSE_BTN, &CLabelDlg::OnBnClickedLabelCloseBtn)
	ON_BN_CLICKED(IDC_CLS_BUTTON, &CLabelDlg::OnBnClickedClsButton)
	ON_BN_CLICKED(IDC_SHRINK_BUTTON, &CLabelDlg::OnBnClickedShrinkButton)

	ON_BN_CLICKED(IDC_CLOSE_USER_BTN, &CLabelDlg::OnBnClickedCloseUserBtn)
	ON_BN_CLICKED(IDC_FAR_BUTTON, &CLabelDlg::OnBnClickedFarButton)
	ON_BN_CLICKED(IDC_NOZZLE_VALVE_BTN, &CLabelDlg::OnBnClickedNozzleValveBtn)
	ON_BN_CLICKED(IDC_ADDBACK_BTN, &CLabelDlg::OnBnClickedAddbackBtn)
	ON_BN_CLICKED(IDC_UDMIRROR_BUTTON, &CLabelDlg::OnBnClickedUdmirrorButton)
	ON_BN_CLICKED(IDC_LRMIRROR_BUTTON, &CLabelDlg::OnBnClickedLrmirrorButton)

	ON_STN_CLICKED(IDC_STATIC_W, &CLabelDlg::OnStnClickedStaticW)

	ON_WM_CTLCOLOR()

	ON_BN_CLICKED(IDC_COPY_BUTTON, &CLabelDlg::OnBnClickedCopyButton)
	ON_BN_CLICKED(IDC_DELETE_BUTTON, &CLabelDlg::OnBnClickedDeleteButton)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CLabelDlg 消息处理程序

BOOL CLabelDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
    isFrame = false;
	// TODO:  在此添加额外的初始化
	theApp.m_MessageEdit.scrMaxRow=0;
	pInput = new CInputDlg;
	pInput->Create(IDD_INPUT_DIALOG,this);
	pInput->MoveWindow(0,260,800,340);
	pInput->ShowWindow(SW_HIDE);
	theApp.SetProgressBar(75);
	//设置按钮的位置及大小
	GetDlgItem(IDC_INPUT_BUTTON)->SetWindowPos(NULL,200,200,60,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_REPEAT_BUTTON)->SetWindowPos(NULL,290,200,60,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_COPY_BUTTON)->SetWindowPos(NULL,380,200,60,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_DELETE_BUTTON)->SetWindowPos(NULL,470,200,60,40,SWP_SHOWWINDOW);
	
	//中间两行
	GetDlgItem(IDC_SHRINK_BUTTON)->SetWindowPos(NULL,200,250,45,40,SWP_SHOWWINDOW);

	CRect rectL;
	GetDlgItem(IDC_NOZZLE_VALVE_BTN)->GetWindowRect(&rectL);
	
	GetDlgItem(IDC_SHRINK_BUTTON)->SetWindowPos(NULL,200,260,45,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_ZOOM_BUTTON)->SetWindowPos(NULL,305,260,45,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_NOZZLE_VALVE_BTN)->SetWindowPos(NULL,380,260,45,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_ADDBACK_BTN)->SetWindowPos(NULL,484,260,45,40,SWP_SHOWWINDOW);
	m_picBNG.SetWindowPos(NULL,430,260,45,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_CLOSE_USER_BTN)->SetWindowPos(NULL,200,320,45,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_FAR_BUTTON)->SetWindowPos(NULL,305,320,45,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_UDMIRROR_BUTTON)->SetWindowPos(NULL,380,320,45,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_LRMIRROR_BUTTON)->SetWindowPos(NULL,484,320,45,40,SWP_SHOWWINDOW);
	m_picOverturn.SetWindowPos(NULL,430,320,45,40,SWP_SHOWWINDOW);
	
	//为矩阵组合框添加元素
	//combo_matrix.SetDroppedWidth(10);  //改变下拉列表下的宽度 
	ComboMatrix.AddString(_T("1L5M"));
	ComboMatrix.AddString(_T("1L7M"));
	ComboMatrix.AddString(_T("1L9M"));
	ComboMatrix.AddString(_T("1L12M"));
	ComboMatrix.AddString(_T("1L19M"));
	ComboMatrix.AddString(_T("1L25M"));
	ComboMatrix.AddString(_T("2L7M"));
	ComboMatrix.SetCurSel(1);
	ComboMatrix.SetFont(theApp.m_ListBoxFont); //设置下拉框字体
	ComboMatrix.SendMessage(CB_SETITEMHEIGHT,-1,30);//设置下拉框高度
	ComboMatrix.SendMessage(CB_SETITEMHEIGHT,0,30);//设置下拉框条目高度
	this->OnCbnSelchangeComboMatrix();
    m_designArea.SetWindowPos(NULL,-1,-1,781,161, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);//781, 161
	//滚动条
	m_ScrollLab.SetWindowPos(NULL,-1,162,781,20, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);
	m_ScrollLab.SetScrollRange(0, 108);  
	SCROLLINFO tempLps;
	m_ScrollLab.GetScrollInfo(&tempLps);
	tempLps.nPage=10;
	m_ScrollLab.SetScrollInfo(&tempLps);
	m_ScrollLab.SetScrollPos(0);

	pixelComboBox.SetFont(theApp.m_ListBoxFont); //设置下拉框字体
	pixelComboBox.SendMessage(CB_SETITEMHEIGHT,-1,25);//设置下拉框高度
	pixelComboBox.SendMessage(CB_SETITEMHEIGHT,0,25);//设置下拉框条目高度
 
	m_reversalCombo.SetFont(theApp.m_ListBoxFont); //设置下拉框字体
	m_reversalCombo.SendMessage(CB_SETITEMHEIGHT,-1,25);//设置下拉框高度
	m_reversalCombo.SendMessage(CB_SETITEMHEIGHT,0,25);//设置下拉框条目高度
	m_reversalCombo.AddString(_T("GLOABL"));
	m_reversalCombo.SetCurSel(0);
	m_reversalCombo.EnableWindow(FALSE);
	m_reversionCombo.SetFont(theApp.m_ListBoxFont); //设置下拉框字体
	m_reversionCombo.SendMessage(CB_SETITEMHEIGHT,-1,25);//设置下拉框高度
	m_reversionCombo.SendMessage(CB_SETITEMHEIGHT,0,25);//设置下拉框条目高度
	m_reversionCombo.AddString(_T("GLOABL"));
	m_reversionCombo.SetCurSel(0);
	m_reversionCombo.EnableWindow(FALSE);
	GetDlgItem(IDC_SHRIK_Z_EDIT)->SetWindowPos(NULL,250,260,45,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_CLOSE_F_EDIT)->SetWindowPos(NULL,250,320,45,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_SHRIK_Z_EDIT)->SetFont(theApp.m_EditFont);
	GetDlgItem(IDC_CLOSE_F_EDIT)->SetFont(theApp.m_EditFont);
	
	//彩色按钮
	m_input.LoadBitmaps(IDB_INPUT1_BITMAP,IDB_INPUT2_BITMAP,0,0,IDB_60_40_BITMAP);
	m_input.SizeToContent(); 
	m_repeat.LoadBitmaps(IDB_REPEAT1_BITMAP,IDB_REPEAT2_BITMAP,0,0,IDB_60_40_BITMAP);
	m_repeat.SizeToContent(); 
	m_copy.LoadBitmaps(IDB_LABEL_COPY1_BITMAP,IDB_LABEL_COPY2_BITMAP,0,0,IDB_60_40_BITMAP);
	m_copy.SizeToContent(); 
	m_delete.LoadBitmaps(IDB_LABEL_DELETE1_BITMAP,IDB_LABEL_DELETE2_BITMAP,0,0,IDB_60_40_BITMAP);
	m_delete.SizeToContent(); 
	
	m_shrink.LoadBitmaps(IDB_SHRINK1_BITMAP,IDB_SHRINK2_BITMAP,0,0,IDB_45_40_BITMAP);
	m_shrink.SizeToContent(); 
	m_zoom.LoadBitmaps(IDB_ZOOM1_BITMAP,IDB_ZOOM2_BITMAP,0,0,IDB_45_40_BITMAP);
	m_zoom.SizeToContent(); 
	m_notback.LoadBitmaps(IDB_NOTBACK1_BITMAP,IDB_NOTBACK2_BITMAP,0,0,IDB_45_40_BITMAP);
	m_notback.SizeToContent(); 
	m_addback.LoadBitmaps(IDB_ADDBACK1_BITMAP,IDB_ADDBACK2_BITMAP,0,0,IDB_45_40_BITMAP);
	m_addback.SizeToContent(); 
	
	m_close.LoadBitmaps(IDB_CLOSE1_BITMAP,IDB_CLOSE2_BITMAP,0,0,IDB_45_40_BITMAP);
	m_close.SizeToContent(); 
	m_far.LoadBitmaps(IDB_FAR1_BITMAP,IDB_FAR2_BITMAP,0,0,IDB_45_40_BITMAP);
	m_far.SizeToContent(); 
	m_UD_mirror.LoadBitmaps(IDB_UD_MIRROR1_BITMAP,IDB_UD_MIRROR2_BITMAP,0,0,IDB_45_40_BITMAP);
	m_UD_mirror.SizeToContent(); 
	m_LR_mirror.LoadBitmaps(IDB_LR_MIRROR1_BITMAP,IDB_LR_MIRROR2_BITMAP,0,0,IDB_45_40_BITMAP);
	m_LR_mirror.SizeToContent(); 
	m_L_select.LoadBitmaps(IDB_L_SELECT1_BITMAP,IDB_L_SELECT2_BITMAP,0,0,IDB_60_35_BITMAP);
	m_L_select.SizeToContent(); 
	m_R_select.LoadBitmaps(IDB_R_SELECT1_BITMAP,IDB_R_SELECT2_BITMAP,0,0,IDB_R_SELECT1_BITMAP);
	m_R_select.SizeToContent(); 
	m_U_shift.LoadBitmaps(IDB_U_SHIFT1_BITMAP,IDB_U_SHIFT2_BITMAP,0,0,IDB_60_35_BITMAP);
	m_U_shift.SizeToContent(); 
	m_D_shift.LoadBitmaps(IDB_D_SHIFT1_BITMAP,IDB_D_SHIFT2_BITMAP,0,0,IDB_60_35_BITMAP);
	m_D_shift.SizeToContent(); 
	
	m_L_shift.LoadBitmaps(IDB_L_SHIFT1_BITMAP,IDB_L_SHIFT2_BITMAP,0,0,IDB_60_35_BITMAP);
	m_L_shift.SizeToContent(); 
	m_R_shift.LoadBitmaps(IDB_R_SHIFT1_BITMAP,IDB_R_SHIFT1_BITMAP,0,0,IDB_60_35_BITMAP);
	m_R_shift.SizeToContent(); 
	m_L_Qshift.LoadBitmaps(IDB_L_QSHIFT1_BITMAP,IDB_L_QSHIFT2_BITMAP,0,0,IDB_60_35_BITMAP);
	m_L_Qshift.SizeToContent(); 
	m_R_Qshift.LoadBitmaps(IDB_R_QSHIFT1_BITMAP,IDB_R_QSHIFT2_BITMAP,0,0,IDB_60_35_BITMAP);
	m_R_Qshift.SizeToContent(); 
	m_download.LoadBitmaps(IDB_DOWNLOAD1_BITMAP,IDB_DOWNLOAD2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_download.SizeToContent(); 
	m_newlyBuilt.LoadBitmaps(IDB_USER_NEW1_BITMAP,IDB_USER_NEW2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_newlyBuilt.SizeToContent(); 
	m_open.LoadBitmaps(IDB_CONFIG_OPEN1_BITMAP,IDB_CONFIG_OPEN2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_open.SizeToContent();
	m_save.LoadBitmaps(IDB_SAVE1_BITMAP,IDB_SAVE2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_save.SizeToContent();
	m_return.LoadBitmaps(IDB_RETURN1_BITMAP,IDB_RETURN2_BITMAP,0,0,IDB_RANGE_BITMAP);
	m_return.SizeToContent();
	theApp.SetProgressBar(80);

	//test

	//OBJ_Control myOBJ_Control;
	//myOBJ_Control.strType1="text";
	//myOBJ_Control.strType2="text";
	//myOBJ_Control.intLineSize=7;
	//myOBJ_Control.intRowSize=18;
	//myOBJ_Control.strFont="7x5";
	//myOBJ_Control.strText="ABf";
	//myOBJ_Control.booFocus=false;
	//theApp.m_MessageEdit.OBJ_Vec.push_back(myOBJ_Control);
	//OBJ_Control myNewOBJ;
	//myNewOBJ.strType1="text";
	//myNewOBJ.strType2="text";
	//myNewOBJ.intLineStart=0;
	//myNewOBJ.intRowStart=18;
	//myNewOBJ.intLineSize=7;
	//myNewOBJ.intRowSize=18;
	//myNewOBJ.strFont="7x5";
	//myNewOBJ.strText="987";
	//theApp.m_MessageEdit.OBJ_Vec.push_back(myNewOBJ);
	theApp.m_MessageEdit.Reverse="GLOBAL";
	theApp.m_MessageEdit.Inverse="GLOBAL";
 
	theApp.m_MessageEdit.getLabFromXml();
	
	for(int i = 0; i < theApp.m_MessageEdit.OBJ_Vec.size(); i++)
	{
		if (theApp.m_MessageEdit.OBJ_Vec[i]->strType2 == "qrcode")
		{
			struct zint_symbol *my_symbol;
			int error_number;
			int rotate_angle;
			int generated;
			int batch_mode;
			int mirror_mode;
			char filetype[4];
			int a;

			error_number = 0;
			rotate_angle = 0;
			generated = 0;
			my_symbol = ZBarcode_Create();
			my_symbol->input_mode = UNICODE_MODE;
			int nType;
			//nType = 58;//先写死
			nType = theApp.m_MessageEdit.OBJ_Vec[i]->nBarcodeType;
			my_symbol->symbology = nType;
			if(nType == 20 || nType == 8)
			my_symbol->height = 12;	 

			int hhh = my_symbol->height;
			my_symbol->scale = 0.5;
			batch_mode = 0;
			mirror_mode = 0;

			std::string strTmp = "";
			strTmp = theApp.m_MessageEdit.OBJ_Vec[i]->strText;

			error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strTmp.c_str(),strTmp.length(),rotate_angle);
			generated = 1;

			//********************************************
			memset(theApp.m_MessageEdit.OBJ_Vec[i]->boDotBmp,false,32*255*sizeof(bool));
			a = 0;
			int r, g, b;
			for (int row = 0; row < my_symbol->bitmap_height; row++)
			{
				for (int col = 0;col < my_symbol->bitmap_width; col++)
				{
					r = my_symbol->bitmap[a];
					g = my_symbol->bitmap[a + 1];
					b = my_symbol->bitmap[a + 2];
					a += 3;
					if (r == 0 && g == 0 && b == 0)
					{
						theApp.m_MessageEdit.OBJ_Vec[i]->boDotBmp[col][my_symbol->bitmap_height-row-1] = true;
					}
					else
					{
						theApp.m_MessageEdit.OBJ_Vec[i]->boDotBmp[col][my_symbol->bitmap_height-row-1] = false;
					}
				}
			}
			ZBarcode_Delete(my_symbol);
			theApp.m_MessageEdit.OBJ_Vec[i]->booFocus = true;
			theApp.m_MessageEdit.OBJ_Vec[i]->isDynamicUse_OBJ = false;
		}
	}

	GetParent()->GetDlgItem(IDC_STATIC_LABNAME)->SetWindowText(theApp.myModuleMain.string2CString(theApp.m_MessageEdit.labName));
	selectPixel();
	OnBnClickedDownloadButton();	
 	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
 
void CLabelDlg::OnBnClickedInputButton()
{
	// TODO: 在此添加控件通知处理程序代码
	showInputDlg(IDD_INPUT_DIALOG);
}

void CLabelDlg::OnPaint()
{
	theApp.m_MessageEdit.isDynamicUse_classMessage = false;//用于判断是否在条形码编辑界面绘制
	CPaintDC dc(this); // device context for painting

	changeDis();

	if (theApp.m_MessageEdit.scrMaxRow>255)
	{
		//theApp.scrPox=theApp.m_MessageEdit.scrMaxRow-156;
		SCROLLINFO tempSCR;
		m_ScrollLab.GetScrollInfo(&tempSCR);
		tempSCR.nMax=theApp.m_MessageEdit.scrMaxRow-147;
		int pos=m_ScrollLab.GetScrollPos();
		if (pos>tempSCR.nMax-9)
		{
			m_ScrollLab.SetScrollPos(0);
			theApp.scrPox=0;
		}
		m_ScrollLab.SetScrollInfo(&tempSCR);
	}
	else
	{
		SCROLLINFO tempSCR;
		m_ScrollLab.GetScrollInfo(&tempSCR);
		tempSCR.nMax=108;
		int pos=m_ScrollLab.GetScrollPos();
		if (pos>tempSCR.nMax-9)
		{
			m_ScrollLab.SetScrollPos(0);
			theApp.scrPox=0;
		}
		m_ScrollLab.SetScrollInfo(&tempSCR);
	}
	m_designArea.Invalidate();
	bool isSetBmp=false;
	for(int i=0;i<theApp.m_MessageEdit.OBJ_Vec.size();i++)
	{
		if (theApp.m_MessageEdit.OBJ_Vec.at(i)->booFocus)
		{
			isSetBmp=true;
			if (theApp.m_MessageEdit.OBJ_Vec.at(i)->booNEG)
			{
				m_picBNG.SetBitmap(m_PichBmp[1]);
			}
			else
			{
				m_picBNG.SetBitmap(m_PichBmp[0]);
			}

			if (theApp.m_MessageEdit.OBJ_Vec.at(i)->booBWDx)
			{
				if (theApp.m_MessageEdit.OBJ_Vec.at(i)->booBWDy)
				{
					m_picOverturn.SetBitmap(m_PichBmp[4]);
				} 
				else
				{
					m_picOverturn.SetBitmap(m_PichBmp[2]);
				}
			}
			else
			{
				if (theApp.m_MessageEdit.OBJ_Vec.at(i)->booBWDy)
				{
					m_picOverturn.SetBitmap(m_PichBmp[3]);
				} 
				else
				{
					m_picOverturn.SetBitmap(m_PichBmp[0]);
				}
			}

			m_zoomLevel=theApp.m_MessageEdit.OBJ_Vec.at(i)->intSW;
			m_ssValue=theApp.m_MessageEdit.OBJ_Vec[i]->intSS;
			UpdateData(FALSE);
			break;
		}
	}
	if (!isSetBmp)
	{
		m_picOverturn.SetBitmap(m_PichBmp[0]);
		m_picBNG.SetBitmap(m_PichBmp[0]);
	}
}

//选择Matrix
void CLabelDlg::OnCbnSelchangeComboMatrix()
{
	// TODO: 在此添加控件通知处理程序代码
	CString  strText;
	int nIndex = ComboMatrix.GetCurSel();  //当前选中的项
	ComboMatrix.GetLBText(nIndex,strText);
	theApp.m_MessageEdit.strMatrix = theApp.myModuleMain.CString2string(strText);
	
	switch(nIndex)
	{
	case 0:
		matrix = 9;
        pixelComboBox.ResetContent();
		for (int i=1;i<=5;i++)
		{
			pixelComboBox.AddString(stringToLPCWSTR(OBJ_Control::to_String(i)));
		}
		pixelComboBox.SetCurSel(4);
        break;

	case 1:
		matrix = 9;
		pixelComboBox.ResetContent();
		for (int i=1;i<=7;i++)
		{
			pixelComboBox.AddString(stringToLPCWSTR(OBJ_Control::to_String(i)));
		}
		pixelComboBox.SetCurSel(6);
        break;
	case 2:
		matrix = 9;
		pixelComboBox.ResetContent();
		for (int i=1;i<=9;i++)
		{
			pixelComboBox.AddString(stringToLPCWSTR(OBJ_Control::to_String(i)));
		}
		pixelComboBox.SetCurSel(8);
		break;
	case 3:
		matrix = 12;
		pixelComboBox.ResetContent();
		for (int i=1;i<=12;i++)
		{
			pixelComboBox.AddString(stringToLPCWSTR(OBJ_Control::to_String(i)));
		}
		pixelComboBox.SetCurSel(11);
		break;
	case 4:
		matrix = 19;
		pixelComboBox.ResetContent();
		for (int i=1;i<=19;i++)
		{
			pixelComboBox.AddString(stringToLPCWSTR(OBJ_Control::to_String(i)));
		}
		pixelComboBox.SetCurSel(18);
        break;
	case 5:
		matrix = 25;
		pixelComboBox.ResetContent();
		for (int i=1;i<=25;i++)
		{
			pixelComboBox.AddString(stringToLPCWSTR(OBJ_Control::to_String(i)));
		}
		pixelComboBox.SetCurSel(24);
		break;
	case 6:
		matrix = 14;
		pixelComboBox.ResetContent();
		pixelComboBox.AddString(stringToLPCWSTR(OBJ_Control::to_String(14)));
        pixelComboBox.SetCurSel(0);

	}
	theApp.m_MessageEdit.Matrix = matrix;
    isFrame = true;
	this->OnCbnSelchangeCombo2();
}

//选择pixel
void CLabelDlg::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
    std::stringstream ss;
	CString  strText;
	int nIndex = pixelComboBox.GetCurSel();  //当前选中的项
	pixel = nIndex;
	theApp.m_MessageEdit.Pixel = pixel;
	if (theApp.m_MessageEdit.Matrix == 14)
	{
		theApp.m_MessageEdit.Pixel = 14;
	}
	 
	isFrame = true;
	OnPaint();
}

void CLabelDlg::OnBnClickedUshiftButton()
{
	// TODO: 在此添加控件通知处理程序代码

	for (int i=0;i<theApp.m_MessageEdit.OBJ_Vec.size();i++)
	{
		if (theApp.m_MessageEdit.OBJ_Vec[i]->booFocus)
		{
			if (theApp.m_MessageEdit.Matrix==14)
			{
				if ((theApp.m_MessageEdit.OBJ_Vec[i]->intLineStart+theApp.m_MessageEdit.OBJ_Vec[i]->intLineSize)>=15)
				{
					break;
				}
				else if (((theApp.m_MessageEdit.OBJ_Vec[i]->intLineStart+theApp.m_MessageEdit.OBJ_Vec[i]->intLineSize)>=(7))&&((theApp.m_MessageEdit.OBJ_Vec[i]->intLineStart+theApp.m_MessageEdit.OBJ_Vec[i]->intLineSize)<15))
				{
					theApp.m_MessageEdit.OBJ_Vec[i]->intLineStart=8;
					OnPaint();
				} 
			} 
			else
			{
				if ((theApp.m_MessageEdit.OBJ_Vec[i]->intLineStart+theApp.m_MessageEdit.OBJ_Vec[i]->intLineSize)>=(pixel+1))
				{
					break;
				}
				theApp.m_MessageEdit.OBJ_Vec[i]->intLineStart++;
				OnPaint();
			}
			break;
		}
	}
}

void CLabelDlg::OnBnClickedLselectButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<theApp.m_MessageEdit.OBJ_Vec.size();i++)
	{
		if (theApp.m_MessageEdit.OBJ_Vec[i]->booFocus)
		{
			if (i>0)
			{
				theApp.m_MessageEdit.OBJ_Vec[i]->booFocus=false;
				theApp.m_MessageEdit.OBJ_Vec[i-1]->booFocus=true;
			}
			else
			{
				break;
			}
			OnPaint();
			break;
		}
	}
}

void CLabelDlg::OnBnClickedRselectButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<theApp.m_MessageEdit.OBJ_Vec.size();i++)
	{
		if (theApp.m_MessageEdit.OBJ_Vec[i]->booFocus)
		{
			if (i<theApp.m_MessageEdit.OBJ_Vec.size()-1)
			{
				theApp.m_MessageEdit.OBJ_Vec[i]->booFocus=false;
				theApp.m_MessageEdit.OBJ_Vec[i+1]->booFocus=true;
			}
			else
			{
				break;
			}
			OnPaint();
			break;
		}
	}
}

void CLabelDlg::OnBnClickedDshiftButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<theApp.m_MessageEdit.OBJ_Vec.size();i++)
	{
		if (theApp.m_MessageEdit.OBJ_Vec[i]->booFocus)
		{
			if (theApp.m_MessageEdit.Matrix==14)
			{
				if ((theApp.m_MessageEdit.OBJ_Vec[i]->intLineStart)<=0)
				{
					break;
				}
				theApp.m_MessageEdit.OBJ_Vec[i]->intLineStart=0;
				OnPaint();
			} 
			else
			{
				if ((theApp.m_MessageEdit.OBJ_Vec[i]->intLineStart)<=0)
				{
					break;
				}
				theApp.m_MessageEdit.OBJ_Vec[i]->intLineStart--;
				OnPaint();
			}
			break;
		}
	}
}

void CLabelDlg::OnBnClickedLshiftButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<theApp.m_MessageEdit.OBJ_Vec.size();i++)
	{
		if (theApp.m_MessageEdit.OBJ_Vec[i]->booFocus)
		{
			if ((theApp.m_MessageEdit.OBJ_Vec[i]->intRowStart)<=0)
			{
				break;
			}
			theApp.m_MessageEdit.OBJ_Vec[i]->intRowStart--;
			OnPaint();
			break;
		}
	}
}

void CLabelDlg::OnBnClickedRshiftButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<theApp.m_MessageEdit.OBJ_Vec.size();i++)
	{
		if (theApp.m_MessageEdit.OBJ_Vec[i]->booFocus)
		{
			theApp.m_MessageEdit.OBJ_Vec[i]->intRowStart++;
			if (theApp.m_MessageEdit.scrMaxRow<theApp.m_MessageEdit.OBJ_Vec[i]->intRowSize+theApp.m_MessageEdit.OBJ_Vec[i]->intRowStart)
			{
				theApp.m_MessageEdit.scrMaxRow=theApp.m_MessageEdit.OBJ_Vec[i]->intRowSize+theApp.m_MessageEdit.OBJ_Vec[i]->intRowStart;
			}
			OnPaint();
			break;
		}
	}
}

void CLabelDlg::OnBnClickedLqshiftButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<theApp.m_MessageEdit.OBJ_Vec.size();i++)
	{
		if (theApp.m_MessageEdit.OBJ_Vec[i]->booFocus)
		{
			if ((theApp.m_MessageEdit.OBJ_Vec[i]->intRowStart)<=0)
			{
				break;
			}
			if ((theApp.m_MessageEdit.OBJ_Vec[i]->intRowStart)<=1)
			{
				theApp.m_MessageEdit.OBJ_Vec[i]->intRowStart--;
				OnPaint();
				break;
			}
			if ((theApp.m_MessageEdit.OBJ_Vec[i]->intRowStart)<=2)
			{
				theApp.m_MessageEdit.OBJ_Vec[i]->intRowStart=theApp.m_MessageEdit.OBJ_Vec[i]->intRowStart-2;
				OnPaint();
				break;
			}
			theApp.m_MessageEdit.OBJ_Vec[i]->intRowStart=theApp.m_MessageEdit.OBJ_Vec[i]->intRowStart-3;
			OnPaint();
			break;
		}
	}
}

void CLabelDlg::OnBnClickedRqshiftButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<theApp.m_MessageEdit.OBJ_Vec.size();i++)
	{
		if (theApp.m_MessageEdit.OBJ_Vec[i]->booFocus)
		{
			theApp.m_MessageEdit.OBJ_Vec[i]->intRowStart=theApp.m_MessageEdit.OBJ_Vec[i]->intRowStart+3;
			if (theApp.m_MessageEdit.scrMaxRow<theApp.m_MessageEdit.OBJ_Vec[i]->intRowSize+theApp.m_MessageEdit.OBJ_Vec[i]->intRowStart)
			{
				theApp.m_MessageEdit.scrMaxRow=theApp.m_MessageEdit.OBJ_Vec[i]->intRowSize+theApp.m_MessageEdit.OBJ_Vec[i]->intRowStart;
			}
			m_designArea.Invalidate();
			//OnPaint();
			break;
		}
	}
}

//保存xml
void CLabelDlg::OnBnClickedSaveButton()
{
	// TODO: 在此添加控件通知处理程序代码
	//string testpath="\\Storage Card\\user\\Label";
	TCHAR path[MAX_PATH];
	//labModule.string2tchar(testpath,path);
	wstring tempstr;
	CString cstr;
	CCodePrinterDlg *pCodeDlg = (CCodePrinterDlg*)this->GetParent();//获取主对话框指针
	tempstr=theApp.myLanguage.LanguageMap["SelectSavePath"];
	cstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(tempstr.c_str());
	((CCodePrinterDlg*)GetParent())->m_PicHead.SetSecondLineOpeString(cstr);
    string xmlPath;
	if(ShowPathDlg(path, MAX_PATH,1))
	{
		//AfxMessageBox(path);
		xmlPath=theApp.myModuleMain.TCHAR2STRING(path);
		//xmlPath+="sss1";
		if (xmlPath[xmlPath.length()-4]!='.')
		{
			xmlPath+=".xml";
		}
		//m_MessageEdit.SaveObjectsToXml("\\Storage Card\\user\\Label\\sss.xml");
		theApp.m_MessageEdit.SaveObjectsToXml(const_cast<char*>(xmlPath.c_str()));
	}	
	CString labFileName;
	labFileName = xmlPath.c_str();
	labFileName.Delete(0,24);//删除路径(Storage Card\user\Label\)
	((CCodePrinterDlg*)GetParent())->m_PicHead.SetSecondLineOpeString(labFileName);
}

//打开xml
void CLabelDlg::OnBnClickedOpenButton()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR path[MAX_PATH];
	//labModule.string2tchar(testpath,path);
	wstring tempstr;
	CString cstr;
	CCodePrinterDlg *pCodeDlg = (CCodePrinterDlg*)this->GetParent();//获取主对话框指针
	tempstr=theApp.myLanguage.LanguageMap["SelectLABfile"];
	cstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(tempstr.c_str());
	((CCodePrinterDlg*)GetParent())->m_PicHead.SetSecondLineOpeString(cstr);
	string xmlPath;
	if(ShowPathDlg(path, MAX_PATH,1))
	{
		//AfxMessageBox(path);
		xmlPath=theApp.myModuleMain.TCHAR2STRING(path);
		//xmlPath+="sss.xml";
		//m_MessageEdit.SaveObjectsToXml("\\Storage Card\\user\\Label\\sss.xml");
		theApp.m_MessageEdit.ReadObjectsFromXml(const_cast<char*>(xmlPath.c_str()));
		theApp.scrPox=0;
		m_ScrollLab.SetScrollPos(0);
	}
	CString labFileName;
	labFileName = xmlPath.c_str();
	labFileName.Delete(0,24);//删除路径(Storage Card\user\Label\)
	((CCodePrinterDlg*)GetParent())->m_PicHead.SetSecondLineOpeString(labFileName);
	//////////////////////////////////////////////////////////////////////////
	for(int i = 0; i < theApp.m_MessageEdit.OBJ_Vec.size(); i++)
	{
		if (theApp.m_MessageEdit.OBJ_Vec[i]->strType2 == "qrcode")
		{
			struct zint_symbol *my_symbol;
			int error_number;
			int rotate_angle;
			int generated;
			int batch_mode;
			int mirror_mode;
			char filetype[4];
			int a;

			error_number = 0;
			rotate_angle = 0;
			generated = 0;
			my_symbol = ZBarcode_Create();
			my_symbol->input_mode = UNICODE_MODE;
			int nType;
			//nType = 58;//先写死
			nType = theApp.m_MessageEdit.OBJ_Vec[i]->nBarcodeType;
			my_symbol->symbology = nType;
			if(nType == 20 || nType == 8)
			my_symbol->height = 12;	 

			int hhh = my_symbol->height;
			my_symbol->scale = 0.5;
			batch_mode = 0;
			mirror_mode = 0;

			std::string strTmp = "";
			strTmp = theApp.m_MessageEdit.OBJ_Vec[i]->strText;

			error_number = ZBarcode_Encode_and_Buffer(my_symbol, (unsigned char*) strTmp.c_str(),strTmp.length(),rotate_angle);
			generated = 1;

			//********************************************
			memset(theApp.m_MessageEdit.OBJ_Vec[i]->boDotBmp,false,32*255*sizeof(bool));
			a = 0;
			int r, g, b;
			for (int row = 0; row < my_symbol->bitmap_height; row++)
			{
				for (int col = 0;col < my_symbol->bitmap_width; col++)
				{
					r = my_symbol->bitmap[a];
					g = my_symbol->bitmap[a + 1];
					b = my_symbol->bitmap[a + 2];
					a += 3;
					if (r == 0 && g == 0 && b == 0)
					{
						theApp.m_MessageEdit.OBJ_Vec[i]->boDotBmp[col][my_symbol->bitmap_height-row-1] = true;
					}
					else
					{
						theApp.m_MessageEdit.OBJ_Vec[i]->boDotBmp[col][my_symbol->bitmap_height-row-1] = false;
					}
				}
			}
			ZBarcode_Delete(my_symbol);
			theApp.m_MessageEdit.OBJ_Vec[i]->booFocus = true;
			theApp.m_MessageEdit.OBJ_Vec[i]->isDynamicUse_OBJ = false;
		}
	}

	//m_MessageEdit.ReadObjectsFromXml("\\Storage Card\\user\\Label\\sss.xml");
	//if (theApp.m_MessageEdit.strMatrix=="1L5M")
	//{
	//	ComboMatrix.SetCurSel(0);
	//	OnCbnSelchangeComboMatrix();

	//} 
	//else if(theApp.m_MessageEdit.strMatrix=="1L7M")
	//{
	//	ComboMatrix.SetCurSel(1);
	//	OnCbnSelchangeComboMatrix();
	//}
	//else if(theApp.m_MessageEdit.strMatrix=="1L9M")
	//{
	//	ComboMatrix.SetCurSel(2);
	//	OnCbnSelchangeComboMatrix();
	//}
	//else if(theApp.m_MessageEdit.strMatrix=="1L12M")
	//{
	//	ComboMatrix.SetCurSel(3);
	//	OnCbnSelchangeComboMatrix();
	//}
	//else if(theApp.m_MessageEdit.strMatrix=="1L19M")
	//{
	//	ComboMatrix.SetCurSel(4);
	//	OnCbnSelchangeComboMatrix();
	//}
	//else if(theApp.m_MessageEdit.strMatrix=="1L25M")
	//{
	//	ComboMatrix.SetCurSel(5);
	//	OnCbnSelchangeComboMatrix();
	//}
	//else if(theApp.m_MessageEdit.strMatrix=="2L7M")
	//{
	//	ComboMatrix.SetCurSel(6);
	//	OnCbnSelchangeComboMatrix();
	//}
	//else
	//{
	//	ComboMatrix.SetCurSel(5);
	//	OnCbnSelchangeComboMatrix();
	//}
	selectPixel();
	OnPaint();
}

//修改
void CLabelDlg::OnBnClickedRepeatButton()
{
	// TODO: 在此添加控件通知处理程序代码
 
	for (int i = 0; i < theApp.m_MessageEdit.OBJ_Vec.size(); i++)
	{
		if (theApp.m_MessageEdit.OBJ_Vec[i]->booFocus)
		{
			theApp.bochange = true;
			if (theApp.m_MessageEdit.OBJ_Vec[i]->strType2 == "text")
			{
				pInput->pEditText->GetDlgItem(IDC_EDIT1)->SetWindowText(theApp.myModuleMain.string2CString(theApp.m_MessageEdit.OBJ_Vec[i]->strText));
				CComboBox* fontBox=(CComboBox*)pInput->pEditText->GetDlgItem(Combo_Font);
				int index= fontBox->FindStringExact(0,theApp.myModuleMain.string2CString(theApp.m_MessageEdit.OBJ_Vec[i]->strFont));
				fontBox->SetCurSel(index);
				pInput->pEditText->ShowWindow(SW_SHOW);
				//fontBox->SetCurSel(theApp.m_MessageEdit.strFont)
			}
			else if (theApp.m_MessageEdit.OBJ_Vec[i]->strType2 == "serial")
			{
				pInput->pEditFigure->GetDlgItem(IDC_FIRST_QUARTILE_EDIT)->SetWindowText(theApp.myModuleMain.string2CString(theApp.myModuleMain.IntToString(theApp.m_MessageEdit.OBJ_Vec[i]->intSerialFirstLimit)));			
				pInput->pEditFigure->GetDlgItem(IDC_FOUR_QUARTILE_EDIT)->SetWindowText(theApp.myModuleMain.string2CString(theApp.myModuleMain.IntToString(theApp.m_MessageEdit.OBJ_Vec[i]->intSerialSecondLimit)));
				pInput->pEditFigure->GetDlgItem(IDC_START_EDIT)->SetWindowText(theApp.myModuleMain.string2CString(theApp.myModuleMain.IntToString(theApp.m_MessageEdit.OBJ_Vec[i]->intSerialStartValue)));
				pInput->pEditFigure->GetDlgItem(IDC_STEP_SIZE_EDIT)->SetWindowText(theApp.myModuleMain.string2CString(theApp.myModuleMain.IntToString(theApp.m_MessageEdit.OBJ_Vec[i]->intSerialStep)));
				pInput->pEditFigure->GetDlgItem(IDC_REPEAT_COUNT_EDIT)->SetWindowText(theApp.myModuleMain.string2CString(theApp.myModuleMain.IntToString(theApp.m_MessageEdit.OBJ_Vec[i]->intSerialRepeat)));
				pInput->pEditFigure->GetDlgItem(IDC_BIT_DATA_EDIT)->SetWindowText(theApp.myModuleMain.string2CString(theApp.myModuleMain.IntToString(theApp.m_MessageEdit.OBJ_Vec[i]->intSerialDigits)));
				pInput->pEditFigure->GetDlgItem(IDC_BIT_DATA_EDIT)->SetWindowText(theApp.myModuleMain.string2CString(theApp.myModuleMain.IntToString(theApp.m_MessageEdit.OBJ_Vec[i]->intSerialDigits)));
				CComboBox *bitBox=(CComboBox *)pInput->pEditFigure->GetDlgItem(IDC_COUNTER_COMBO);
				bitBox->AddString(theApp.myModuleMain.string2CString(theApp.myModuleMain.IntToString(theApp.m_MessageEdit.OBJ_Vec[i]->intSerialCounter+1)));
				bitBox->EnableWindow(FALSE);
				CComboBox *fontBox=(CComboBox *)pInput->pEditFigure->GetDlgItem(IDC_FONT_COMBO);
				fontBox->SelectString(0,theApp.myModuleMain.string2CString(theApp.m_MessageEdit.OBJ_Vec[i]->strFont));
				CComboBox *formatBox=(CComboBox *)pInput->pEditFigure->GetDlgItem(IDC_FORMAT_COMBO);
				formatBox->SetCurSel(theApp.m_MessageEdit.OBJ_Vec[i]->bytSerialFormat);
				pInput->pEditFigure->RefreshSerial();
				pInput->pEditFigure->ShowWindow(SW_SHOW);
			}
			else if (theApp.m_MessageEdit.OBJ_Vec[i]->strType2 == "time")
			{
				pInput->pDate->GetDlgItem(IDC_DATE_DATE_TIME_EDIT)->SetWindowText(theApp.myModuleMain.string2CString(theApp.m_MessageEdit.OBJ_Vec[i]->strTime));
				CComboBox *dfontBox=(CComboBox *)pInput->pDate->GetDlgItem(IDC_DATE_FONT_COMBO);
				dfontBox->SelectString(0,theApp.myModuleMain.string2CString(theApp.m_MessageEdit.OBJ_Vec[i]->strFont));
				CComboBox *boOffBox=(CComboBox *)pInput->pDate->GetDlgItem(IDC_DATE_SKEW_COMBO);
				boOffBox->SetCurSel(theApp.m_MessageEdit.OBJ_Vec[i]->booETimeOffSet);
				pInput->pDate->GetDlgItem(IDC_DATE_SKEW_VALUE_EDIT)->SetWindowText(theApp.myModuleMain.string2CString(theApp.myModuleMain.IntToString(theApp.m_MessageEdit.OBJ_Vec[i]->intTimeOffSet)));
				CComboBox *whereOffBox=(CComboBox *)pInput->pDate->GetDlgItem(IDC_SKEW_UNIT_LIST);
				whereOffBox->SetCurSel(theApp.m_MessageEdit.OBJ_Vec[i]->strTimeOffSet);
				pInput->pDate->ChangeTime();
				pInput->pDate->ShowWindow(SW_SHOW);
			}
			else if (theApp.m_MessageEdit.OBJ_Vec[i]->strType2 == "logo")
			{
				TCHAR path[MAX_PATH];
				//labModule.string2tchar(testpath,path);

				string xmlPath;
				if(ShowPathDlg(path, MAX_PATH,2))
				{
					xmlPath=theApp.myModuleMain.TCHAR2STRING(path);
					theApp.m_MessageEdit.OBJ_Vec[i]->ReadBmp(const_cast<char*>(xmlPath.c_str()));//这个最好返回一个bool变量,就能省去if了
					if (theApp.m_MessageEdit.OBJ_Vec[i]->intLineSize<=0||theApp.m_MessageEdit.OBJ_Vec[i]->intRowSize<=0)
					{
						return;
					}

					theApp.m_MessageEdit.OBJ_Vec[i]->strText=xmlPath;
					if ((theApp.m_MessageEdit.OBJ_Vec[i]->intRowStart+theApp.m_MessageEdit.OBJ_Vec[i]->intRowSize)>theApp.m_MessageEdit.scrMaxRow)
					{
						theApp.m_MessageEdit.scrMaxRow=theApp.m_MessageEdit.OBJ_Vec[i]->intRowStart+theApp.m_MessageEdit.OBJ_Vec[i]->intRowSize;
					}
				}
			}

			else if (theApp.m_MessageEdit.OBJ_Vec[i]->strType2 == "qrcode")
			{
				pInput->pBarCode->ShowWindow(SW_SHOW);
			}
			break;
		}
	}
}

//重写鼠标点击
void CLabelDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect lRect;
	m_designArea.GetWindowRect(&lRect);  //获取控件相对于屏幕的位置
	ScreenToClient(&lRect);
	//m_nSelectObjIndex = -1;
	if((point.x >= lRect.left && point.x <= lRect.right) && (point.y >= lRect.top && point.y <= lRect.bottom))
	{
		point.x -= lRect.left;
		point.y -= lRect.top;
		int nRow;
		int nCol;	 
		nRow = (161-point.y) / 5;
		nCol = (point.x / 5)+theApp.scrPox;
		/*for (size_t i = 0; i < theApp.m_MessageEdit.OBJ_Vec.size(); i++)
		{
			theApp.m_MessageEdit.OBJ_Vec[i]->booFocus = false;
		}*/
		vector<OBJ_Control*>::iterator itr = theApp.m_MessageEdit.OBJ_Vec.begin();
		bool isFind=false;
		while (itr != theApp.m_MessageEdit.OBJ_Vec.end())
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

//生成下发打印数据
void CLabelDlg::CreatePrintData()
{
	GetParent()->GetDlgItem(IDC_STATIC_LABNAME)->SetWindowText(theApp.myModuleMain.string2CString(theApp.m_MessagePrint.labName));

	theApp.mainPicPixel = theApp.m_MessagePrint.Pixel+1;
	theApp.mainPicMatrx = theApp.m_MessagePrint.Matrix;

	BYTE dotDataLen_l,dotDataLen_h,matrix_name,pixelMes,pixelAll;
	 
	theApp.ForPreQue = queue<vector<BYTE>>();
	 
	//信息重新发送，序列号按信息里面的开始值喷，如只改变喷印参数则按计数器的值继续喷
 	
	theApp.m_MessagePrint.boDynamic = false;
	getMessageDot();

	CCodePrinterDlg *pParent = (CCodePrinterDlg *)GetParent();
	pParent->m_PictureMain.Invalidate();

	if(theApp.m_MessagePrint.IntMes)
		delete []theApp.m_MessagePrint.IntMes;
	theApp.m_MessagePrint.IntMes = new UINT32[theApp.m_MessagePrint.intRowMax];
	memset(theApp.m_MessagePrint.IntMes,0,sizeof(UINT32)*theApp.m_MessagePrint.intRowMax);

	for (int j = 0; j < 32; j++)
		for (int i = 0; i < theApp.m_MessagePrint.intRowMax; i++)
			theApp.m_MessagePrint.IntMes[i] += ((theApp.m_MessagePrint.boDotMes[j][i])?1:0)*pow(2,j);

	vector<BYTE> bytPrintData = theApp.m_MessagePrint.DotToByte(0,theApp.m_MessagePrint.intRowMax);
	dotDataLen_l = bytPrintData.size()%256; //dotDataLen_l与dotDataLen_h共同表达了打印数据的大小dotDataLen_h*256+dotDataLen_l
	dotDataLen_h = bytPrintData.size()/256;
	pixelMes = (BYTE)(pixel+1);
	matrix_name = pixelMes<<2;//低二位为模式 
	pixelAll = pixelMes|0x80; //表示该数据及时生效，开始打印，将前面的清除掉。

	theApp.boPrintNowLock.Lock();
		vector<BYTE>().swap(theApp.m_MessagePrint.bytPrintDataAll);//比clear()好，能够释放内存  
		vector<BYTE>().swap(theApp.m_MessagePrint.bytPrintDataAllOrder);  

		//预先给vector<BYTE>分配大小，然后再使用，效率也会高点，后面改正
		theApp.m_MessagePrint.bytPrintDataAll.push_back(0x1);
		theApp.m_MessagePrint.bytPrintDataAll.push_back(0x80);
		theApp.m_MessagePrint.bytPrintDataAll.push_back(0x6);
		theApp.m_MessagePrint.bytPrintDataAll.push_back(0x1);
		theApp.m_MessagePrint.bytPrintDataAll.push_back(0x11);
		theApp.m_MessagePrint.bytPrintDataAll.push_back(matrix_name);
		theApp.m_MessagePrint.bytPrintDataAll.push_back(pixelMes);
		theApp.m_MessagePrint.bytPrintDataAll.push_back(dotDataLen_l);
		theApp.m_MessagePrint.bytPrintDataAll.push_back(dotDataLen_h);
		theApp.m_MessagePrint.bytPrintDataAll.push_back(0xff);
		theApp.m_MessagePrint.bytPrintDataAll.push_back(0xff);

		//以下参见通信格式说明
		theApp.m_MessagePrint.bytPrintDataAllOrder.push_back(0x1);
		theApp.m_MessagePrint.bytPrintDataAllOrder.push_back(0x80);
		theApp.m_MessagePrint.bytPrintDataAllOrder.push_back(0x6);
		theApp.m_MessagePrint.bytPrintDataAllOrder.push_back(0x1);
		theApp.m_MessagePrint.bytPrintDataAllOrder.push_back(0x11);
		theApp.m_MessagePrint.bytPrintDataAllOrder.push_back(matrix_name);
		theApp.m_MessagePrint.bytPrintDataAllOrder.push_back(pixelAll);
		theApp.m_MessagePrint.bytPrintDataAllOrder.push_back(dotDataLen_l);
		theApp.m_MessagePrint.bytPrintDataAllOrder.push_back(dotDataLen_h);
		theApp.m_MessagePrint.bytPrintDataAllOrder.push_back(0xff);
		theApp.m_MessagePrint.bytPrintDataAllOrder.push_back(0xff);

		bytPrintData.push_back(0xff);
		bytPrintData.push_back(0xff);

		theApp.m_MessagePrint.bytPrintDataAll.insert(theApp.m_MessagePrint.bytPrintDataAll.end(),bytPrintData.begin(),bytPrintData.end());
		theApp.m_MessagePrint.bytPrintDataAllOrder.insert(theApp.m_MessagePrint.bytPrintDataAllOrder.end(),bytPrintData.begin(),bytPrintData.end());
		theApp.m_MessageEdit.bytPrintDataAllOrder.clear();
		theApp.m_MessageEdit.bytPrintDataAllOrder = theApp.m_MessagePrint.bytPrintDataAllOrder;
	theApp.m_MessagePrint.intMesDis = theApp.m_MessagePrint.bytPrintDataAll;
	theApp.m_MessagePrint.boPrintNow = true;		
	theApp.boPrintNowLock.Unlock();

	if (theApp.m_MessagePrint.boDynamic)//是否动态打印
	{
  		theApp.ForPreQue.push(theApp.m_MessagePrint.bytPrintDataAll);  
  	} 	 
}

//开始打印
void CLabelDlg::OnBnClickedDownloadButton()
{		
    //关闭动态打印线程（若有）
	if (theApp.mythreadDynamicBoo)
	{
		theApp.mythreadDynamicBoo = false;
		WaitForSingleObject(theApp.mythreadDynamic->m_hThread,INFINITE);//等待线程结束
		theApp.boDrawMainPic = false;
		WaitForSingleObject(theApp.mythreadDynamicdis->m_hThread,INFINITE);//等待线程结束
		delete theApp.mythreadDynamic;//删除线程
		delete theApp.mythreadDynamicdis;
	}

	//将编辑内容赋值给打印内容
	theApp.m_MessagePrint = theApp.m_MessageEdit;
	theApp.m_MessagePrint.OBJ_Vec = theApp.m_MessageEdit.OBJ_Vec;
	theApp.m_MessagePrint.DynOBJ_Vec = theApp.m_MessageEdit.DynOBJ_Vec;
	//保存参数到目前的喷印配置xml文件和pcf文件里createPCF()	createPCFXML()
	theApp.m_MessagePrint.createLABXML();
	theApp.m_MessagePrint.SerialCountNew = true;

	CreatePrintData();

 	if (theApp.m_MessagePrint.boDynamic)//是否动态打印
	{
		theApp.mythreadDynamicBoo = true;
		theApp.mythreadDynamic = AfxBeginThread(CreateMessageThread,NULL,THREAD_PRIORITY_NORMAL);
		theApp.mythreadDynamic->m_bAutoDelete = FALSE;//线程为手动删除

		CCodePrinterDlg *pDlg = (CCodePrinterDlg*)this->GetParent();
		theApp.mythreadDynamicdis = AfxBeginThread(MainpageDrawTheard,(LPVOID)&pDlg->mainPicStruct,THREAD_PRIORITY_BELOW_NORMAL);
		theApp.mythreadDynamicdis->m_bAutoDelete=  FALSE;//线程为手动删除
	}

	ShowWindow(SW_HIDE);
}

void CLabelDlg::getMessageDot()
{
	CCodePrinterDlg *pParent = (CCodePrinterDlg *)GetParent();
	int nCurSel = pParent->m_Confi->m_reverse.GetCurSel();
	if (nCurSel == 0)
		theApp.m_MessagePrint.boReverse = false;
	else
		theApp.m_MessagePrint.boReverse = true;
	nCurSel = pParent->m_Confi->m_inverse.GetCurSel();
	if (nCurSel == 0)
		theApp.m_MessagePrint.boInverse = false;
	else
		theApp.m_MessagePrint.boInverse = true;

	theApp.m_MessagePrint.intRowMax = 0;

	for(int i=0;i<theApp.m_MessagePrint.OBJ_Vec.size();i++)
	{
		if (theApp.m_MessagePrint.intRowMax < (theApp.m_MessagePrint.OBJ_Vec[i]->intRowSize+theApp.m_MessagePrint.OBJ_Vec[i]->intRowStart))
		{
			theApp.m_MessagePrint.intRowMax = theApp.m_MessagePrint.OBJ_Vec[i]->intRowSize+theApp.m_MessagePrint.OBJ_Vec[i]->intRowStart;
			theApp.m_MessagePrint.scrMaxRow = theApp.m_MessagePrint.intRowMax;
		}
		if (theApp.m_MessagePrint.OBJ_Vec[i]->strType2 == "serial" || theApp.m_MessagePrint.OBJ_Vec[i]->strType2 == "time" )
			theApp.m_MessagePrint.boDynamic = true;
		if ( theApp.m_MessagePrint.OBJ_Vec[i]->strType2 == "qrcode" )
		{
			//if (theApp.m_MessagePrint.OBJ_Vec[i]->intDynamicQRPrint == 1 )
			//{
			//	theApp.m_MessagePrint.boDynamic = true;
			//}
			for(int j=0;j<theApp.m_MessagePrint.OBJ_Vec[i]->Qr_Vec.size();j++)
			{
				if ( theApp.m_MessagePrint.OBJ_Vec[i]->Qr_Vec[j]->strType2 == "serial" || theApp.m_MessagePrint.OBJ_Vec[i]->Qr_Vec[j]->strType2 == "time")
				{
					theApp.m_MessagePrint.boDynamic = true;
				}
			}
		}
	}
	theApp.m_MessagePrint.pcfintDotMesRow = theApp.m_MessagePrint.intRowMax;
	
	if (theApp.m_MessagePrint.boDynamic)
	{
		for (int i = 0;i < theApp.m_MessagePrint.OBJ_Vec.size();i++)
		{
			//下段代码功能是什么？
			if (theApp.m_MessagePrint.OBJ_Vec.at(i)->strType2=="serial")
			{
				if (theApp.m_MessagePrint.SerialCountNew)
				{
					theApp.m_MessagePrint.OBJ_Vec[i]->CountNum = theApp.m_MessagePrint.OBJ_Vec[i]->intSerialStartValue;
					theApp.m_MessagePrint.OBJ_Vec[i]->CountNumRep = 1;
				}
				else if (!theApp.m_MessagePrint.SerialCountNew && !theApp.m_MessagePrint.SerialCountSet[0])
				{
					theApp.m_MessagePrint.OBJ_Vec[i]->intSerialStartValue = theApp.m_MessagePrint.OBJ_Vec[i]->CountNum;
					theApp.m_MessagePrint.OBJ_Vec[i]->CountNumRep = 1;
				}
				CCodePrinterDlg* tempDlg = (CCodePrinterDlg*)GetParent();
				switch(theApp.m_MessagePrint.OBJ_Vec.at(i)->intSerialCounter)
				{
				case 0:
					if (!theApp.m_MessagePrint.SerialCountNew && theApp.m_MessagePrint.SerialCountSet[0])
					{
						CString tempCstr;
						tempDlg->m_resetSerial->GetDlgItem(IDC_SET_VALUE1_EDIT)->GetWindowText(tempCstr);
						theApp.m_MessagePrint.OBJ_Vec[i]->CountNum=_ttoi(tempCstr);
						theApp.m_MessagePrint.OBJ_Vec[i]->intSerialStartValue = theApp.m_MessagePrint.OBJ_Vec[i]->CountNum;
						theApp.m_MessagePrint.OBJ_Vec[i]->CountNumRep = 1;
						theApp.m_MessagePrint.SerialCountSet[0] = false;
					}
					tempDlg->m_resetSerial->GetDlgItem(IDC_SERIAL1_CUR_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->CountNum)));
					UpdateData(FALSE);
					break;
				case 1:
					if (!theApp.m_MessagePrint.SerialCountNew && theApp.m_MessagePrint.SerialCountSet[1])
					{
						CString tempCstr;
						tempDlg->m_resetSerial->GetDlgItem(IDC_SET_VALUE2_EDIT)->GetWindowText(tempCstr);
						theApp.m_MessagePrint.OBJ_Vec[i]->CountNum=_ttoi(tempCstr);
						theApp.m_MessagePrint.OBJ_Vec[i]->intSerialStartValue = theApp.m_MessagePrint.OBJ_Vec[i]->CountNum;
						theApp.m_MessagePrint.OBJ_Vec[i]->CountNumRep = 1;
						theApp.m_MessagePrint.SerialCountSet[1] = false;
					}
					tempDlg->m_resetSerial->GetDlgItem(IDC_SERIAL2_CUR_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->CountNum)));
					UpdateData(FALSE);
					break;
				case 2:
					if (!theApp.m_MessagePrint.SerialCountNew && theApp.m_MessagePrint.SerialCountSet[2])
					{
						CString tempCstr;
						tempDlg->m_resetSerial->GetDlgItem(IDC_SET_VALUE3_EDIT)->GetWindowText(tempCstr);
						theApp.m_MessagePrint.OBJ_Vec[i]->CountNum=_ttoi(tempCstr);
						theApp.m_MessagePrint.OBJ_Vec[i]->intSerialStartValue = theApp.m_MessagePrint.OBJ_Vec[i]->CountNum;
						theApp.m_MessagePrint.OBJ_Vec[i]->CountNumRep = 1;
						theApp.m_MessagePrint.SerialCountSet[2] = false;
					}
					tempDlg->m_resetSerial->GetDlgItem(IDC_SERIAL3_CUR_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->CountNum)));
					UpdateData(FALSE);
					break;
				case 3:
					if (!theApp.m_MessagePrint.SerialCountNew && theApp.m_MessagePrint.SerialCountSet[3])
					{
						CString tempCstr;
						tempDlg->m_resetSerial->GetDlgItem(IDC_SET_VALUE4_EDIT)->GetWindowText(tempCstr);
						theApp.m_MessagePrint.OBJ_Vec[i]->CountNum=_ttoi(tempCstr);
						theApp.m_MessagePrint.OBJ_Vec[i]->intSerialStartValue = theApp.m_MessagePrint.OBJ_Vec[i]->CountNum;
						theApp.m_MessagePrint.OBJ_Vec[i]->CountNumRep = 1;
						theApp.m_MessagePrint.SerialCountSet[3] = false;
					}
					tempDlg->m_resetSerial->GetDlgItem(IDC_SERIAL4_CUR_STATIC)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(theApp.myModuleMain.IntToString(theApp.m_MessagePrint.OBJ_Vec[i]->CountNum)));
					UpdateData(FALSE);
					break;
				}
			}
		}
	}
	theApp.m_MessagePrint.getdot(); 
} 

void CLabelDlg::selectPixel()
{
	if (theApp.m_MessageEdit.strMatrix == "1L5M")
	{
		ComboMatrix.SetCurSel(0);
		OnCbnSelchangeComboMatrix();

	} 
	else if(theApp.m_MessageEdit.strMatrix == "1L7M")
	{
		ComboMatrix.SetCurSel(1);
		OnCbnSelchangeComboMatrix();
	}
	else if(theApp.m_MessageEdit.strMatrix == "1L9M")
	{
		ComboMatrix.SetCurSel(2);
		OnCbnSelchangeComboMatrix();
	}
	else if(theApp.m_MessageEdit.strMatrix == "1L12M")
	{
		ComboMatrix.SetCurSel(3);
		OnCbnSelchangeComboMatrix();
	}
	else if(theApp.m_MessageEdit.strMatrix == "1L19M")
	{
		ComboMatrix.SetCurSel(4);
		OnCbnSelchangeComboMatrix();
	}
	else if(theApp.m_MessageEdit.strMatrix == "1L25M")
	{
		ComboMatrix.SetCurSel(5);
		OnCbnSelchangeComboMatrix();
	}
	else if(theApp.m_MessageEdit.strMatrix == "2L7M")
	{
		ComboMatrix.SetCurSel(6);
		OnCbnSelchangeComboMatrix();
	}
	else
	{
		ComboMatrix.SetCurSel(5);
		OnCbnSelchangeComboMatrix();
	}
}

void CLabelDlg::OnBnClickedLabelCloseBtn()
{
	// TODO: 在此添加控件通知处理程序代码

	ShowWindow(SW_HIDE);
	((CCodePrinterDlg*)GetParent())->m_PicHead.ShowLogo(true); 
	((CCodePrinterDlg*)GetParent())->m_PicHead.SetSecondLineOpeString(_T(""));
}

void CLabelDlg::showInputDlg(int ID)
{
	pInput->ShowWindow(SW_HIDE);

	if (ID == IDD_INPUT_DIALOG)
	{
		pInput->ShowWindow(SW_SHOW);
	}

}

//清空，新建
void CLabelDlg::OnBnClickedClsButton()
{

	wstring tempstr;
	CString cstr;
	CCodePrinterDlg *pCodeDlg = (CCodePrinterDlg*)this->GetParent();//获取主对话框指针
	tempstr=theApp.myLanguage.LanguageMap["NewLabel"];
	cstr = pCodeDlg->m_cAbrabicconj->disposeinputtext(tempstr.c_str());
	((CCodePrinterDlg*)GetParent())->m_PicHead.SetSecondLineOpeString(cstr);
	// TODO: 在此添加控件通知处理程序代码
	theApp.m_MessageEdit.OBJ_Vec.clear();
	//memset(theApp.m_MessageEdit.CounterEditMes,false,sizeof(bool)*4);
	m_ssValue = 0;
	m_zoomLevel = 1;
	theApp.scrPox = 0;
	m_ScrollLab.SetScrollPos(0);
	theApp.m_MessageEdit.scrMaxRow = 0;
	UpdateData(FALSE);
	OnPaint();
}

//减粗
void CLabelDlg::OnBnClickedShrinkButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<theApp.m_MessageEdit.OBJ_Vec.size();i++)
	{
		if (theApp.m_MessageEdit.OBJ_Vec[i]->booFocus)
		{
			if(theApp.m_MessageEdit.OBJ_Vec[i]->intSW>1)
			{
				theApp.m_MessageEdit.OBJ_Vec[i]->intSW--;
				//GetDlgItem(IDC_EDIT1).SetWindowText(theApp.m_MessageEdit.OBJ_Vec[i].intSW);
				OnPaint();
			}			
			break;
		}
	}
}

//加粗
void CLabelDlg::OnBnClickedZoomButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<theApp.m_MessageEdit.OBJ_Vec.size();i++)
	{
		if (theApp.m_MessageEdit.OBJ_Vec[i]->booFocus)
		{
			if(theApp.m_MessageEdit.OBJ_Vec[i]->intSW<4)
			{
				theApp.m_MessageEdit.OBJ_Vec[i]->intSW++;
				switch(theApp.m_MessageEdit.OBJ_Vec[i]->intSW)
				{
				case 2:
					theApp.m_MessageEdit.OBJ_Vec[i]->intRowSize=theApp.m_MessageEdit.OBJ_Vec[i]->intRowSize*2;
					break;
				case 3:
					theApp.m_MessageEdit.OBJ_Vec[i]->intRowSize=theApp.m_MessageEdit.OBJ_Vec[i]->intRowSize/2*3;
					break;
				case 4:
					theApp.m_MessageEdit.OBJ_Vec[i]->intRowSize=theApp.m_MessageEdit.OBJ_Vec[i]->intRowSize/3*4;
					break;
				}
				if (theApp.m_MessageEdit.scrMaxRow<theApp.m_MessageEdit.OBJ_Vec[i]->intRowSize+theApp.m_MessageEdit.OBJ_Vec[i]->intRowStart)
				{
					theApp.m_MessageEdit.scrMaxRow=theApp.m_MessageEdit.OBJ_Vec[i]->intRowSize+theApp.m_MessageEdit.OBJ_Vec[i]->intRowStart;
				}
				OnPaint();
			}
			break;
		}
	}
}

//间距减
void CLabelDlg::OnBnClickedCloseUserBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<theApp.m_MessageEdit.OBJ_Vec.size();i++)
	{
		if (theApp.m_MessageEdit.OBJ_Vec[i]->booFocus)
		{
			if(theApp.m_MessageEdit.OBJ_Vec[i]->intSS>0)
			{
				theApp.m_MessageEdit.OBJ_Vec[i]->intSS--;
				//GetDlgItem(IDC_EDIT1).SetWindowText(theApp.m_MessageEdit.OBJ_Vec[i].intSW);

				OnPaint();
			}
			break;
		}
	}
}

//间距加
void CLabelDlg::OnBnClickedFarButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<theApp.m_MessageEdit.OBJ_Vec.size();i++)
	{
		if (theApp.m_MessageEdit.OBJ_Vec[i]->booFocus)
		{
			if(theApp.m_MessageEdit.OBJ_Vec[i]->intSS<4)
			{
				theApp.m_MessageEdit.OBJ_Vec[i]->intSS++;
				//GetDlgItem(IDC_EDIT1).SetWindowText(theApp.m_MessageEdit.OBJ_Vec[i].intSW);
				theApp.m_MessageEdit.OBJ_Vec[i]->intRowSize=theApp.m_MessageEdit.OBJ_Vec[i]->intRowSize+theApp.m_MessageEdit.OBJ_Vec[i]->strText.size();
				if (theApp.m_MessageEdit.scrMaxRow<theApp.m_MessageEdit.OBJ_Vec[i]->intRowSize+theApp.m_MessageEdit.OBJ_Vec[i]->intRowStart)
				{
					theApp.m_MessageEdit.scrMaxRow=theApp.m_MessageEdit.OBJ_Vec[i]->intRowSize+theApp.m_MessageEdit.OBJ_Vec[i]->intRowStart;
				}
				OnPaint();
			}
			break;
		}
	}
}

//黑白转关
void CLabelDlg::OnBnClickedNozzleValveBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<theApp.m_MessageEdit.OBJ_Vec.size();i++)
	{
		if (theApp.m_MessageEdit.OBJ_Vec[i]->booFocus)
		{
			if(theApp.m_MessageEdit.OBJ_Vec[i]->booNEG)
			{
				theApp.m_MessageEdit.OBJ_Vec[i]->booNEG=false;
				//界面换图标
				OnPaint();
			}
			break;
		}
	}
}

//黑白转开
void CLabelDlg::OnBnClickedAddbackBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<theApp.m_MessageEdit.OBJ_Vec.size();i++)
	{
		if (theApp.m_MessageEdit.OBJ_Vec[i]->booFocus)
		{
			if(!theApp.m_MessageEdit.OBJ_Vec[i]->booNEG)
			{
				theApp.m_MessageEdit.OBJ_Vec[i]->booNEG=true;
				//界面换图标
				OnPaint();
			}
			break;
		}
	}
}

//上下翻转
void CLabelDlg::OnBnClickedUdmirrorButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<theApp.m_MessageEdit.OBJ_Vec.size();i++)
	{
		if (theApp.m_MessageEdit.OBJ_Vec[i]->booFocus)
		{
			//if(theApp.m_MessageEdit.OBJ_Vec[i]->booNEG)
			{
				theApp.m_MessageEdit.OBJ_Vec[i]->booBWDx=!theApp.m_MessageEdit.OBJ_Vec[i]->booBWDx;
				//界面换图标
				OnPaint();
			}
			break;
		}
	}
}

//左右翻转
void CLabelDlg::OnBnClickedLrmirrorButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<theApp.m_MessageEdit.OBJ_Vec.size();i++)
	{
		if (theApp.m_MessageEdit.OBJ_Vec[i]->booFocus)
		{
			//if(theApp.m_MessageEdit.OBJ_Vec[i]->booNEG)
			{
				theApp.m_MessageEdit.OBJ_Vec[i]->booBWDy=!theApp.m_MessageEdit.OBJ_Vec[i]->booBWDy;
				//界面换图标
				OnPaint();
			}
			break;
		}
	}
}


void CLabelDlg::OnStnClickedStaticW()
{
	// TODO: 在此添加控件通知处理程序代码
}


//改变位置
void CLabelDlg::changeDis()
{
	for (int i=0;i<theApp.m_MessageEdit.OBJ_Vec.size();i++)
	{
		if (theApp.m_MessageEdit.OBJ_Vec.at(i)->booFocus)
		{
			GetDlgItem(IDC_STATIC_WV)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(OBJ_Control::to_String(theApp.m_MessageEdit.OBJ_Vec.at(i)->intRowSize)));
			GetDlgItem(IDC_STATIC_HV)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(OBJ_Control::to_String(theApp.m_MessageEdit.OBJ_Vec.at(i)->intLineSize)));
			GetDlgItem(IDC_STATIC_XV)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(OBJ_Control::to_String(theApp.m_MessageEdit.OBJ_Vec.at(i)->intRowStart)));
			GetDlgItem(IDC_STATIC_YV)->SetWindowText(theApp.myModuleMain.stringToLPCWSTR(OBJ_Control::to_String(theApp.m_MessageEdit.OBJ_Vec.at(i)->intLineStart)));
			return;
		}
	}
	GetDlgItem(IDC_STATIC_WV)->SetWindowText(_T("*"));
	GetDlgItem(IDC_STATIC_HV)->SetWindowText(_T("*"));
	GetDlgItem(IDC_STATIC_XV)->SetWindowText(_T("*"));
	GetDlgItem(IDC_STATIC_YV)->SetWindowText(_T("*"));
}

HBRUSH CLabelDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
	pDC->SetBkColor(theApp.m_BKcolor);	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return theApp.m_DlgBrush;
}


//复制
void CLabelDlg::OnBnClickedCopyButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for(int i = 0; i < theApp.m_MessageEdit.OBJ_Vec.size(); i++)
	{
		if (theApp.m_MessageEdit.OBJ_Vec.at(i)->booFocus)
		{
			OBJ_Control* tempObj = new OBJ_Control(theApp.m_MessageEdit.OBJ_Vec.at(i));
			for(int j = 0; j < theApp.m_MessageEdit.OBJ_Vec[i]->Qr_Vec.size(); j++)
			{
				OBJ_Control* Obj = new OBJ_Control(theApp.m_MessageEdit.OBJ_Vec[i]->Qr_Vec.at(j));
				tempObj->Qr_Vec.push_back(Obj);
			}
			tempObj->isDynamicUse_OBJ = theApp.m_MessageEdit.OBJ_Vec.at(i)->isDynamicUse_OBJ;//
  			tempObj->intRowStart = tempObj->intRowStart+tempObj->intRowSize;
 
			if (tempObj->strType2 == "serial")
			{
				int nSerialNums = theApp.m_MessageEdit.ModifyGetSerialNums();
				if(nSerialNums < 4)
					tempObj->intSerialCounter = nSerialNums;
				else
				{
					delete tempObj;
					CString csMsg = _T("操作失败！\n序列号已满！");
					AfxMessageBox(csMsg);
					return;
				}
			}
			if (theApp.m_MessageEdit.scrMaxRow < tempObj->intRowStart+tempObj->intRowSize)
			{
				theApp.m_MessageEdit.scrMaxRow = tempObj->intRowStart+tempObj->intRowSize;
			}
			theApp.m_MessageEdit.OBJ_Vec.push_back(tempObj);
			theApp.m_MessageEdit.OBJ_Vec.at(i)->booFocus = false;
			OnPaint();
			break;
		}
	}
}

void CLabelDlg::OnBnClickedDeleteButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for(vector<OBJ_Control*>::iterator iterTemp=theApp.m_MessageEdit.OBJ_Vec.begin();iterTemp!=theApp.m_MessageEdit.OBJ_Vec.end();iterTemp++)
	{
		if ((*iterTemp)->booFocus)
		{
			theApp.m_MessageEdit.ModifyGetSerialNums();
			if ((*iterTemp)->strType2 == "qrcode")
			{
				theApp.m_MessageEdit.DynOBJ_Vec.clear();
			}
			theApp.m_MessageEdit.OBJ_Vec.erase(iterTemp);
			break;
		}
	}
	vector<OBJ_Control*>::iterator iterTemp = theApp.m_MessageEdit.OBJ_Vec.begin();
	if (iterTemp != theApp.m_MessageEdit.OBJ_Vec.end())
	{
		(*iterTemp)->booFocus = true;
	}
	OnPaint();
}

void CLabelDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int pos = m_ScrollLab.GetScrollPos();    // 获取水平滚动条当前位置 
	SCROLLINFO tempSCR;
	m_ScrollLab.GetScrollInfo(&tempSCR);
	switch (nSBCode)   
	{   
		// 如果向左滚动一列，则pos减1  
	case SB_LINELEFT:   
		pos -= 1;   
		break;   
		// 如果向右滚动一列，则pos加1  
	case SB_LINERIGHT:   
		pos  += 1;   
		break;   
		// 如果向左滚动一页，则pos减10  
	case SB_PAGELEFT:   
		pos -= 10;   
		break;   
		// 如果向右滚动一页，则pos加10  
	case SB_PAGERIGHT:   
		pos  += 10;   
		break;   
		// 如果滚动到最左端，则pos为1  
	case SB_LEFT:   
		pos = tempSCR.nMin;   
		break;   
		// 如果滚动到最右端，则pos为100  
	case SB_RIGHT:   
		pos = tempSCR.nMax; 
		break;     
		  //gundongshi
	case SB_THUMBTRACK:
		pos = nPos;
		theApp.scrPox=pos;
		m_designArea.Invalidate();
		break;
		// 如果拖动滚动块滚动到指定位置，则pos赋值为nPos的值
	case SB_THUMBPOSITION:   
		pos = nPos;
		break;   
		// 下面的m_horiScrollbar.SetScrollPos(pos);执行时会第二次进入此函数，最终确定滚动块位置，并且会直接到default分支，所以在此处设置编辑框中显示数值  
	default:   
		//SetDlgItemInt(IDC_HSCROLL_EDIT, pos);
		theApp.scrPox=pos;
		m_designArea.Invalidate();
		return;   
	}   
	
	// 设置滚动块位置  
	m_ScrollLab.SetScrollPos(pos);  

	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}


