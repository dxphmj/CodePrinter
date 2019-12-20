// LabelDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "LabelDlg.h"
#include "InputDlg.h"
#include <sstream>
#include <map>
#include "..\KEYBOARD\KEYBOARD\ExportDlg.h"
//#include "PathDlgDll.h"
#include "..\PathDlgDll\PathDlgDll\PathDlgDll.h"
LPCWSTR stringToLPCWSTR(std::string orig)
{
	size_t origsize = orig.length() + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t *wcstring = (wchar_t *)malloc(sizeof(wchar_t)*(orig.length()-1));
	mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);

	return wcstring;
}


//std::string WcharToChar(const wchar_t* wp, size_t m_encode = CP_ACP)
//{
//	std::string str;
//	int len = WideCharToMultiByte(m_encode, 0, wp, wcslen(wp), NULL, 0, NULL, NULL);
//	char	*m_char = new char[len + 1];
//	WideCharToMultiByte(m_encode, 0, wp, wcslen(wp), m_char, len, NULL, NULL);
//	m_char[len] = '\0';
//	str = m_char;
//	delete m_char;
//	return str;
//}

IMPLEMENT_DYNAMIC(CLabelDlg, CDialog)

CLabelDlg::CLabelDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLabelDlg::IDD, pParent)
	, m_zoomLevel(0)
	, m_ssValue(0)
{

}

CLabelDlg::~CLabelDlg()
{
}
//CImageButton m_shrink;
//CImageButton m_zoom;
//CImageButton m_notback;
//CImageButton m_addback;
//CImageButton m_close;
//CImageButton m_far;
//CImageButton m_UD_mirror;
//CImageButton m_LR_mirror;
//CImageButton m_L_select;
//CImageButton m_R_select;
//CImageButton m_U_shift;
//CImageButton m_D_shift;
//CImageButton m_L_shift;
//CImageButton m_R_shift;
//CImageButton m_L_Qshift;
//CImageButton m_R_Qshift;
//CImageButton m_download;
//CImageButton m_newlyBuilt;
//CImageButton m_open;
//CImageButton m_save;
//CImageButton m_return;
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


	DDX_Text(pDX, IDC_EDIT1, m_zoomLevel);
	DDV_MinMaxInt(pDX, m_zoomLevel, 1, 4);
	DDX_Text(pDX, IDC_EDIT2, m_ssValue);
	DDV_MinMaxInt(pDX, m_ssValue, 0, 4);

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

	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_DOWNLOAD_BUTTON, &CLabelDlg::OnBnClickedDownloadButton)
	ON_BN_CLICKED(IDC_LABEL_CLOSE_BTN, &CLabelDlg::OnBnClickedLabelCloseBtn)
	ON_BN_CLICKED(IDC_CLS_BUTTON, &CLabelDlg::OnBnClickedClsButton)
	ON_BN_CLICKED(IDC_SHRINK_BUTTON, &CLabelDlg::OnBnClickedShrinkButton)
END_MESSAGE_MAP()


// CLabelDlg 消息处理程序

BOOL CLabelDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
    isFrame = false;
	// TODO:  在此添加额外的初始化
	pInput = new CInputDlg;
	pInput->Create(IDD_INPUT_DIALOG,this);
	pInput->MoveWindow(0,200,800,400);
	pInput->ShowWindow(SW_HIDE);

	//设置按钮的位置及大小
	GetDlgItem(IDC_INPUT_BUTTON)->SetWindowPos(NULL,200,200,65,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_REPEAT_BUTTON)->SetWindowPos(NULL,290,200,65,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_COPY_BUTTON)->SetWindowPos(NULL,380,200,65,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_DELETE_BUTTON)->SetWindowPos(NULL,470,200,65,40,SWP_SHOWWINDOW);
	
	//中间两行
	GetDlgItem(IDC_SHRINK_BUTTON)->SetWindowPos(NULL,200,260,45,40,SWP_SHOWWINDOW);

	//右侧两列
	GetDlgItem(IDC_LSELECT_BUTTON)->SetWindowPos(NULL,585,290,60,35,SWP_SHOWWINDOW);

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
	this->OnCbnSelchangeComboMatrix();
    m_designArea.SetWindowPos(NULL,-1,-1,781,161, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);//781, 161
   
	//彩色按钮
	m_shrink.LoadBitmaps(IDB_SHRINK_BITMAP,IDB_SHRINK_BITMAP,0,0,IDB_SHRINK_BITMAP);
	m_shrink.SizeToContent(); 
	m_zoom.LoadBitmaps(IDB_ZOOM_BITMAP,IDB_ZOOM_BITMAP,0,0,IDB_SHRINK_BITMAP);
	m_zoom.SizeToContent(); 
	m_notback.LoadBitmaps(IDB_NOTBACK_BITMAP,IDB_NOTBACK_BITMAP,0,0,IDB_NOTBACK_BITMAP);
	m_notback.SizeToContent(); 
	m_addback.LoadBitmaps(IDB_ADDBACK_BITMAP,IDB_ADDBACK_BITMAP,0,0,IDB_ADDBACK_BITMAP);
	m_addback.SizeToContent(); 
	m_close.LoadBitmaps(IDB_CLOSE_BITMAP,IDB_CLOSE_BITMAP,0,0,IDB_CLOSE_BITMAP);
	m_close.SizeToContent(); 
	m_far.LoadBitmaps(IDB_FAR_BITMAP,IDB_FAR_BITMAP,0,0,IDB_FAR_BITMAP);
	m_far.SizeToContent(); 
	m_UD_mirror.LoadBitmaps(IDB_UD_MIRROR_BITMAP,IDB_UD_MIRROR_BITMAP,0,0,IDB_UD_MIRROR_BITMAP);
	m_UD_mirror.SizeToContent(); 
	m_LR_mirror.LoadBitmaps(IDB_LR_MIRROR_BITMAP,IDB_LR_MIRROR_BITMAP,0,0,IDB_LR_MIRROR_BITMAP);
	m_LR_mirror.SizeToContent(); 
	m_L_select.LoadBitmaps(IDB_L_SELECT_BITMAP,IDB_L_SELECT_BITMAP,0,0,IDB_L_SELECT_BITMAP);
	m_L_select.SizeToContent(); 
	m_R_select.LoadBitmaps(IDB_R_SELECT_BITMAP,IDB_R_SELECT_BITMAP,0,0,IDB_R_SELECT_BITMAP);
	m_R_select.SizeToContent(); 
	m_U_shift.LoadBitmaps(IDB_U_SHIFT_BITMAP,IDB_U_SHIFT_BITMAP,0,0,IDB_U_SHIFT_BITMAP);
	m_U_shift.SizeToContent(); 
	m_D_shift.LoadBitmaps(IDB_D_SHIFT_BITMAP,IDB_D_SHIFT_BITMAP,0,0,IDB_D_SHIFT_BITMAP);
	m_D_shift.SizeToContent(); 
	m_L_shift.LoadBitmaps(IDB_L_SHIFT_BITMAP,IDB_L_SHIFT_BITMAP,0,0,IDB_L_SHIFT_BITMAP);
	m_L_shift.SizeToContent(); 
	m_R_shift.LoadBitmaps(IDB_R_SHIFT_BITMAP,IDB_R_SHIFT_BITMAP,0,0,IDB_R_SHIFT_BITMAP);
	m_R_shift.SizeToContent(); 
	m_L_Qshift.LoadBitmaps(IDB_L_QSHIFT_BITMAP,IDB_L_QSHIFT_BITMAP,0,0,IDB_L_QSHIFT_BITMAP);
	m_L_Qshift.SizeToContent(); 
	m_R_Qshift.LoadBitmaps(IDB_R_QSHIFT_BITMAP,IDB_R_QSHIFT_BITMAP,0,0,IDB_R_QSHIFT_BITMAP);
	m_R_Qshift.SizeToContent(); 
	m_download.LoadBitmaps(IDB_DOWNLOAD_BITMAP,IDB_DOWNLOAD_BITMAP,0,0,IDB_DOWNLOAD_BITMAP);
	m_download.SizeToContent(); 
	m_newlyBuilt.LoadBitmaps(IDB_LR_MIRROR_BITMAP,IDB_LR_MIRROR_BITMAP,0,0,IDB_LR_MIRROR_BITMAP);
	m_newlyBuilt.SizeToContent(); 
	m_open.LoadBitmaps(IDB_OPEN_BITMAP,IDB_OPEN_BITMAP,0,0,IDB_OPEN_BITMAP);
	m_open.SizeToContent();
	m_save.LoadBitmaps(IDB_SAVE_BITMAP,IDB_SAVE_BITMAP,0,0,IDB_SAVE_BITMAP);
	m_save.SizeToContent();
	m_return.LoadBitmaps(IDB_RETURN_BITMAP,IDB_RETURN_BITMAP,0,0,IDB_RETURN_BITMAP);
	m_return.SizeToContent();

	//test

	//OBJ_Control myOBJ_Control;
	//myOBJ_Control.strType1="text";
	//myOBJ_Control.strType2="text";
	//myOBJ_Control.intLineSize=7;
	//myOBJ_Control.intRowSize=18;
	//myOBJ_Control.strFont="7x5";
	//myOBJ_Control.strText="ABf";
	//myOBJ_Control.booFocus=false;
	//theApp.myclassMessage.OBJ_Vec.push_back(myOBJ_Control);
	//OBJ_Control myNewOBJ;
	//myNewOBJ.strType1="text";
	//myNewOBJ.strType2="text";
	//myNewOBJ.intLineStart=0;
	//myNewOBJ.intRowStart=18;
	//myNewOBJ.intLineSize=7;
	//myNewOBJ.intRowSize=18;
	//myNewOBJ.strFont="7x5";
	//myNewOBJ.strText="987";
	//theApp.myclassMessage.OBJ_Vec.push_back(myNewOBJ);
	theApp.myclassMessage.Reverse="GLOBAL";
	theApp.myclassMessage.Inverse="GLOBAL";


	theApp.myclassMessage.getLabFromXml();
	selectPixel();

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
	CPaintDC dc(this); // device context for painting
	CDC* pDC = m_designArea.GetDC();
	CRect rectClient;
	CDC dcMem,dcBkgnd;
	CBitmap bitmapTemp;//, *pOldBitmap;
	//GetClientRect(&rectClient);//获取窗口信息
	bitmapTemp.CreateCompatibleBitmap(pDC, 781, 161);//创建内存位图
	dcMem.CreateCompatibleDC(pDC); //依附窗口DC创建兼容的DC
	//pOldBitmap = dcMem.SelectObject(&bitmapTemp);//将内存位图选入内存dc
	dcMem.SelectObject(&bitmapTemp);
	//填充颜色
	m_designArea.GetClientRect(&rectClient);
	dcMem.FillSolidRect(rectClient,RGB(255,255,255));   //填充颜色
	
	CBrush cbrush;
	CBrush* pBrush; //旧笔刷
	if(isFrame)
	{//画网格
		CPen cPen; 
		cPen.CreatePen(PS_SOLID,1,RGB(220,220,220)); 
		CPen* pOldPen; 
		pOldPen = dcMem.SelectObject(&cPen); //载入笔刷
		for (int i=0;i<=rectClient.Width();)//竖
		{
			dcMem.MoveTo(i,rectClient.Height()-5*pixel-1);
			dcMem.LineTo(i,rectClient.Height());
			i+=5;
		}
		for (int j=rectClient.Height()-5*pixel-1;j<=rectClient.Height();)
		{
			dcMem.MoveTo(0,j);
			dcMem.LineTo(rectClient.Width(),j);
			j+=5;
		}
		dcMem.SelectObject(pOldPen);
		cPen.DeleteObject();
		pOldPen->DeleteObject();
		//isFrame=false;
	}
	theApp.myclassMessage.DrawDot(&dcMem);
	pDC->BitBlt(0, 0, rectClient.Width(), rectClient.Height(), &dcMem, 0, 0, SRCCOPY);//绘制图片到主dc
	//dcMem.SelectObject(pOldBitmap);//清理
	dcMem.DeleteDC();      // 删除内存DC
	bitmapTemp.DeleteObject();      // 删除内存位图
	//theApp.myclassMessage.DrawDot(pDC);

	ReleaseDC(pDC); 
/*
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()

	CDC* pDC = m_designArea.GetDC();
	//先清除打印预览内容
	CBrush cbrush;
	CBrush* pBrush; //旧笔刷
	CRect rect;
	m_designArea.GetClientRect(&rect);
	cbrush.CreateSolidBrush(RGB(255,255,255)); 
	pBrush=pDC->SelectObject(&cbrush); //载入笔刷
	pDC->Rectangle(&rect); //绘制矩形		
	pDC->SelectObject(pBrush); //恢复笔刷
	cbrush.DeleteObject();
	pBrush->DeleteObject();
	if(isFrame)
	{//画网格
		CPen cPen; 
		cPen.CreatePen(PS_SOLID,1,RGB(220,220,220)); 
		CPen* pOldPen; 
		pOldPen = pDC->SelectObject(&cPen); //载入笔刷
		for (int i=0;i<=rect.Width();)//竖
		{
			pDC->MoveTo(i,rect.Height()-5*pixel-1);
			pDC->LineTo(i,rect.Height());
            i+=5;
		}
        for (int j=rect.Height()-5*pixel-1;j<=rect.Height();)
        {
			pDC->MoveTo(0,j);
			pDC->LineTo(rect.Width(),j);
			j+=5;
        }
		pDC->SelectObject(pOldPen);
		cPen.DeleteObject();
		pOldPen->DeleteObject();
		//isFrame=false;
	}


	if(m_bDesign)
	{
		//绘制设计结果
		//m_PrintObjectsDeal.DrawObjects(pDC,m_nStepPixels);
	}
	else
	{		 
		//CPen cPen; 
		//cPen.CreatePen(PS_SOLID,1,RGB(252,157,154)); 
		//CPen* pOldPen; 
		//pOldPen = pDC->SelectObject(&cPen); //载入笔刷

		//for(int i = 0; i < m_nRowSum; i++)
		//{
		//	pDC->MoveTo(0,i*m_nStepPixels);
		//	pDC->LineTo(m_nStepPixels*m_nColSum,i*m_nStepPixels);
		//}
		//for(int i = 0; i < m_nColSum; i++)
		//{
		//	pDC->MoveTo(i*m_nStepPixels,0);
		//	pDC->LineTo(i*m_nStepPixels,m_nStepPixels*m_nRowSum);
		//}
		//pDC->SelectObject(pOldPen);
		//cPen.DeleteObject();
		//pOldPen->DeleteObject();

		//CBrush cbrush;
		//CBrush* pBrush; //旧笔刷	
		//cbrush.CreateSolidBrush(RGB(0,0,0)); 
		//pBrush = pDC->SelectObject(&cbrush); //载入笔刷

		//for(int i = 0; i < m_nRowSum; i++)
		//	for(int j = 0; j < m_nColSum; j++)
		//		DrawOnePoint(pDC,i,j);

		//pDC->SelectObject(pBrush); //恢复笔刷
		//cbrush.DeleteObject();
		//pBrush->DeleteObject();
	}

	theApp.myclassMessage.DrawDot(pDC);

	//myOBJ_Control.DrowDot(pDC);
	//myOBJ_Control.DrawFrame(pDC);
	ReleaseDC(pDC); 
*/

}
//选择Matrix
void CLabelDlg::OnCbnSelchangeComboMatrix()
{
	// TODO: 在此添加控件通知处理程序代码
	CString  strText;
	int nIndex = ComboMatrix.GetCurSel();  //当前选中的项
	ComboMatrix.GetLBText(nIndex,strText);
	theApp.myclassMessage.strMatrix=theApp.myModuleMain.WcharToChar(strText);
	
	switch(nIndex)
	{
	case 0:
		matrix = 9;
        pixelComboBox.ResetContent();
		for (int i=1;i<=5;i++)
		{
			pixelComboBox.AddString(stringToLPCWSTR(theApp.myclassMessage.to_String(i)));
		}
		pixelComboBox.SetCurSel(4);
        break;

	case 1:
		matrix = 9;
		pixelComboBox.ResetContent();
		for (int i=1;i<=7;i++)
		{
			pixelComboBox.AddString(stringToLPCWSTR(theApp.myclassMessage.to_String(i)));
		}
		pixelComboBox.SetCurSel(6);
        break;
	case 2:
		matrix = 9;
		pixelComboBox.ResetContent();
		for (int i=1;i<=9;i++)
		{
			pixelComboBox.AddString(stringToLPCWSTR(theApp.myclassMessage.to_String(i)));
		}
		pixelComboBox.SetCurSel(8);
		break;
	case 3:
		matrix = 12;
		pixelComboBox.ResetContent();
		for (int i=1;i<=12;i++)
		{
			pixelComboBox.AddString(stringToLPCWSTR(theApp.myclassMessage.to_String(i)));
		}
		pixelComboBox.SetCurSel(11);
		break;
	case 4:
		matrix = 19;
		pixelComboBox.ResetContent();
		for (int i=1;i<=19;i++)
		{
			pixelComboBox.AddString(stringToLPCWSTR(theApp.myclassMessage.to_String(i)));
		}
		pixelComboBox.SetCurSel(18);
        break;
	case 5:
		matrix = 25;
		pixelComboBox.ResetContent();
		for (int i=1;i<=25;i++)
		{
			pixelComboBox.AddString(stringToLPCWSTR(theApp.myclassMessage.to_String(i)));
		}
		pixelComboBox.SetCurSel(24);
		break;
	case 6:
		matrix = 14;
		pixelComboBox.ResetContent();
		pixelComboBox.AddString(stringToLPCWSTR(theApp.myclassMessage.to_String(14)));
        pixelComboBox.SetCurSel(13);

	}
	//myclassMessage.Pixel=pixelComboBox.GetCurSel()+1;
	theApp.myclassMessage.Matrix=matrix;
    isFrame=true;
	this->OnCbnSelchangeCombo2();
}
//选择pixel
void CLabelDlg::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
    std::stringstream ss;
	CString  strText;
	int nIndex = pixelComboBox.GetCurSel();  //当前选中的项
	pixel=nIndex+1;
	theApp.myclassMessage.Pixel=pixel;
	//pixelComboBox.GetLBText(nIndex,strText);
	//ss<<strText;
	//ss>>pixel;
	isFrame=true;
}

void CLabelDlg::OnBnClickedUshiftButton()
{
	// TODO: 在此添加控件通知处理程序代码

	for (int i=0;i<theApp.myclassMessage.OBJ_Vec.size();i++)
	{
		if (theApp.myclassMessage.OBJ_Vec[i].booFocus)
		{
			if ((theApp.myclassMessage.OBJ_Vec[i].intLineStart+theApp.myclassMessage.OBJ_Vec[i].intLineSize)>=pixel)
			{
				break;
			}
			theApp.myclassMessage.OBJ_Vec[i].intLineStart++;
			OnPaint();
			break;
		}
	}
}

void CLabelDlg::OnBnClickedLselectButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<theApp.myclassMessage.OBJ_Vec.size();i++)
	{
		if (theApp.myclassMessage.OBJ_Vec[i].booFocus)
		{
			if (i>0)
			{
				theApp.myclassMessage.OBJ_Vec[i].booFocus=false;
				theApp.myclassMessage.OBJ_Vec[i-1].booFocus=true;
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
	for (int i=0;i<theApp.myclassMessage.OBJ_Vec.size();i++)
	{
		if (theApp.myclassMessage.OBJ_Vec[i].booFocus)
		{
			if (i<theApp.myclassMessage.OBJ_Vec.size()-1)
			{
				theApp.myclassMessage.OBJ_Vec[i].booFocus=false;
				theApp.myclassMessage.OBJ_Vec[i+1].booFocus=true;
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
	for (int i=0;i<theApp.myclassMessage.OBJ_Vec.size();i++)
	{
		if (theApp.myclassMessage.OBJ_Vec[i].booFocus)
		{
			if ((theApp.myclassMessage.OBJ_Vec[i].intLineStart)<=0)
			{
				break;
			}
			theApp.myclassMessage.OBJ_Vec[i].intLineStart--;
			OnPaint();
			break;
		}
	}
}

void CLabelDlg::OnBnClickedLshiftButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<theApp.myclassMessage.OBJ_Vec.size();i++)
	{
		if (theApp.myclassMessage.OBJ_Vec[i].booFocus)
		{
			if ((theApp.myclassMessage.OBJ_Vec[i].intRowStart)<=0)
			{
				break;
			}
			theApp.myclassMessage.OBJ_Vec[i].intRowStart--;
			OnPaint();
			break;
		}
	}
}

void CLabelDlg::OnBnClickedRshiftButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<theApp.myclassMessage.OBJ_Vec.size();i++)
	{
		if (theApp.myclassMessage.OBJ_Vec[i].booFocus)
		{
			theApp.myclassMessage.OBJ_Vec[i].intRowStart++;
			OnPaint();
			break;
		}
	}
}

void CLabelDlg::OnBnClickedLqshiftButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<theApp.myclassMessage.OBJ_Vec.size();i++)
	{
		if (theApp.myclassMessage.OBJ_Vec[i].booFocus)
		{
			if ((theApp.myclassMessage.OBJ_Vec[i].intRowStart)<=0)
			{
				break;
			}
			if ((theApp.myclassMessage.OBJ_Vec[i].intRowStart)<=1)
			{
				theApp.myclassMessage.OBJ_Vec[i].intRowStart--;
				OnPaint();
				break;
			}
			if ((theApp.myclassMessage.OBJ_Vec[i].intRowStart)<=2)
			{
				theApp.myclassMessage.OBJ_Vec[i].intRowStart=theApp.myclassMessage.OBJ_Vec[i].intRowStart-2;
				OnPaint();
				break;
			}
			theApp.myclassMessage.OBJ_Vec[i].intRowStart=theApp.myclassMessage.OBJ_Vec[i].intRowStart-3;
			OnPaint();
			break;
		}
	}
}

void CLabelDlg::OnBnClickedRqshiftButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<theApp.myclassMessage.OBJ_Vec.size();i++)
	{
		if (theApp.myclassMessage.OBJ_Vec[i].booFocus)
		{
			theApp.myclassMessage.OBJ_Vec[i].intRowStart=theApp.myclassMessage.OBJ_Vec[i].intRowStart+3;
			OnPaint();
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

    string xmlPath;
	if(ShowPathDlg(path, MAX_PATH))
	{
		//AfxMessageBox(path);
		xmlPath=theApp.myModuleMain.TCHAR2STRING(path);
		//xmlPath+="sss1";
		if (xmlPath[xmlPath.length()-4]!='.')
		{
			xmlPath+=".xml";
		}
		//myclassMessage.SaveObjectsToXml("\\Storage Card\\user\\Label\\sss.xml");
		theApp.myclassMessage.SaveObjectsToXml(const_cast<char*>(xmlPath.c_str()));
	}

	
}
//打开xml
void CLabelDlg::OnBnClickedOpenButton()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR path[MAX_PATH];
	//labModule.string2tchar(testpath,path);

	string xmlPath;
	if(ShowPathDlg(path, MAX_PATH))
	{
		//AfxMessageBox(path);
		xmlPath=theApp.myModuleMain.TCHAR2STRING(path);
		//xmlPath+="sss.xml";
		//myclassMessage.SaveObjectsToXml("\\Storage Card\\user\\Label\\sss.xml");
		theApp.myclassMessage.ReadObjectsFromXml(const_cast<char*>(xmlPath.c_str()));
	}

	//myclassMessage.ReadObjectsFromXml("\\Storage Card\\user\\Label\\sss.xml");
	//if (theApp.myclassMessage.strMatrix=="1L5M")
	//{
	//	ComboMatrix.SetCurSel(0);
	//	OnCbnSelchangeComboMatrix();

	//} 
	//else if(theApp.myclassMessage.strMatrix=="1L7M")
	//{
	//	ComboMatrix.SetCurSel(1);
	//	OnCbnSelchangeComboMatrix();
	//}
	//else if(theApp.myclassMessage.strMatrix=="1L9M")
	//{
	//	ComboMatrix.SetCurSel(2);
	//	OnCbnSelchangeComboMatrix();
	//}
	//else if(theApp.myclassMessage.strMatrix=="1L12M")
	//{
	//	ComboMatrix.SetCurSel(3);
	//	OnCbnSelchangeComboMatrix();
	//}
	//else if(theApp.myclassMessage.strMatrix=="1L19M")
	//{
	//	ComboMatrix.SetCurSel(4);
	//	OnCbnSelchangeComboMatrix();
	//}
	//else if(theApp.myclassMessage.strMatrix=="1L25M")
	//{
	//	ComboMatrix.SetCurSel(5);
	//	OnCbnSelchangeComboMatrix();
	//}
	//else if(theApp.myclassMessage.strMatrix=="2L7M")
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

//修改，弹出键盘
void CLabelDlg::OnBnClickedRepeatButton()
{
	// TODO: 在此添加控件通知处理程序代码
    CExportDlg myCExportDlg;
	CString ts;
	ts.Format(L"%s",_T("sdfsa"));
	myCExportDlg.GetInputText(ts);



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
		nCol = point.x / 5;
		vector<OBJ_Control>::iterator itr = theApp.myclassMessage.OBJ_Vec.begin();
		while (itr != theApp.myclassMessage.OBJ_Vec.end())
		{		
			itr->booFocus = false;
			if (nRow>=itr->intLineStart&&nRow<=(itr->intLineStart+itr->intLineSize)
				&&nCol>=itr->intRowStart&&nCol<=(itr->intRowStart+itr->intRowSize))
			{
				itr->booFocus=true;
			}
			++itr;
		}
	}
	OnPaint();
	CDialog::OnLButtonDown(nFlags, point);
}

//开始打印
void CLabelDlg::OnBnClickedDownloadButton()
{
	 //TODO: 在此添加控件通知处理程序代码
	BYTE dotDataLen_l,dotDataLen_h,matrix_name,pixelMes,pixelAll;

	//1、界面保存到目前的喷印配置xml文件和pcf文件里        createPCF()	createPCFXML()
	theApp.myclassMessage.createLABXML();
	//2、取值并发送至下位机 download_pcf()
	//3、关闭动态打印线程（若有）
    //信息重新发送，序列号按信息里面的开始值喷，如只改变喷印参数则按计数器的值继续喷
	//动态文本关

	//4、分析打印的信息含有的动态文本有哪些及组成的生成元素，并生成第一次的点阵
	int rowMax=0;
	memset(theApp.myclassMessage.boDotMes,false,sizeof(theApp.myclassMessage.boDotMes));
	for(vector<OBJ_Control>::iterator objIter=theApp.myclassMessage.OBJ_Vec.begin();objIter!=theApp.myclassMessage.OBJ_Vec.end();objIter++)
	{
		theApp.myclassMessage.getdot(objIter->strFont,objIter->booBWDy,objIter->booBWDx,objIter->booNEG,objIter->strText,
			objIter->intRowSize,objIter->intLineSize,objIter->intLineStart,objIter->intRowStart,objIter->intSS,objIter->intSW);
		if (rowMax<(objIter->intRowSize+objIter->intRowStart))
		{
			rowMax=objIter->intRowSize+objIter->intRowStart;
		}

	}
	//以上都要放到getMessageDot中，

	//drawPrevFirst（）

	if (theApp.myclassMessage.boDynamic)//是否动态打印
	{
	} 
	else
	{
		vector<BYTE> testByteVec;
		testByteVec=theApp.myclassMessage.DotToByte(0,rowMax);
		dotDataLen_l=testByteVec.size()%256;
		dotDataLen_h=testByteVec.size()/256;
		pixelMes=(BYTE)pixel;
		matrix_name=pixelMes<<2;//低二位为模式，原程序没用到
		pixelAll=pixelMes | 0x80;

		theApp.boPrintNowLock.Lock();
        theApp.myclassMessage.bytPrintDataAll.clear();
		theApp.myclassMessage.bytPrintDataAllOrder.clear();

		theApp.myclassMessage.bytPrintDataAll.push_back(0x1);
		theApp.myclassMessage.bytPrintDataAll.push_back(0x80);
		theApp.myclassMessage.bytPrintDataAll.push_back(0x6);
		theApp.myclassMessage.bytPrintDataAll.push_back(0x1);
		theApp.myclassMessage.bytPrintDataAll.push_back(0x11);
		theApp.myclassMessage.bytPrintDataAll.push_back(matrix_name);
		theApp.myclassMessage.bytPrintDataAll.push_back(pixelMes);
		theApp.myclassMessage.bytPrintDataAll.push_back(dotDataLen_l);
		theApp.myclassMessage.bytPrintDataAll.push_back(dotDataLen_h);
		theApp.myclassMessage.bytPrintDataAll.push_back(0xff);
		theApp.myclassMessage.bytPrintDataAll.push_back(0xff);
		//theApp.myclassMessage.bytPrintDataAllOrder={0x1,0x80,0x6,0x1,0x11,matrix_name,pixelMes,dotDataLen_l,dotDataLen_h,0xff,0xff};
		theApp.myclassMessage.bytPrintDataAllOrder.push_back(0x1);
		theApp.myclassMessage.bytPrintDataAllOrder.push_back(0x80);
		theApp.myclassMessage.bytPrintDataAllOrder.push_back(0x6);
		theApp.myclassMessage.bytPrintDataAllOrder.push_back(0x1);
		theApp.myclassMessage.bytPrintDataAllOrder.push_back(0x11);
		theApp.myclassMessage.bytPrintDataAllOrder.push_back(matrix_name);
		theApp.myclassMessage.bytPrintDataAllOrder.push_back(pixelAll);
		theApp.myclassMessage.bytPrintDataAllOrder.push_back(dotDataLen_l);
		theApp.myclassMessage.bytPrintDataAllOrder.push_back(dotDataLen_h);
		theApp.myclassMessage.bytPrintDataAllOrder.push_back(0xff);
		theApp.myclassMessage.bytPrintDataAllOrder.push_back(0xff);
	
		testByteVec.push_back(0xff);
		testByteVec.push_back(0xff);

		theApp.myclassMessage.bytPrintDataAll.insert(theApp.myclassMessage.bytPrintDataAll.end(),testByteVec.begin(),testByteVec.end());
		theApp.myclassMessage.bytPrintDataAllOrder.insert(theApp.myclassMessage.bytPrintDataAllOrder.end(),testByteVec.begin(),testByteVec.end());
		theApp.myclassMessage.boPrintNow=true;
		theApp.boPrintNowLock.Unlock();
	}

	//BYTE ssss=testByteVec[34];
    //ssss=testByteVec[0];
}


void CLabelDlg::getMessageDot()
{

}
void CLabelDlg::selectPixel()
{
	if (theApp.myclassMessage.strMatrix=="1L5M")
	{
		ComboMatrix.SetCurSel(0);
		OnCbnSelchangeComboMatrix();

	} 
	else if(theApp.myclassMessage.strMatrix=="1L7M")
	{
		ComboMatrix.SetCurSel(1);
		OnCbnSelchangeComboMatrix();
	}
	else if(theApp.myclassMessage.strMatrix=="1L9M")
	{
		ComboMatrix.SetCurSel(2);
		OnCbnSelchangeComboMatrix();
	}
	else if(theApp.myclassMessage.strMatrix=="1L12M")
	{
		ComboMatrix.SetCurSel(3);
		OnCbnSelchangeComboMatrix();
	}
	else if(theApp.myclassMessage.strMatrix=="1L19M")
	{
		ComboMatrix.SetCurSel(4);
		OnCbnSelchangeComboMatrix();
	}
	else if(theApp.myclassMessage.strMatrix=="1L25M")
	{
		ComboMatrix.SetCurSel(5);
		OnCbnSelchangeComboMatrix();
	}
	else if(theApp.myclassMessage.strMatrix=="2L7M")
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
	this->ShowWindow(SW_HIDE);
}

void CLabelDlg::showInputDlg(int ID)
{
	pInput->ShowWindow(SW_HIDE);

	if (ID == IDD_INPUT_DIALOG)
	{
		pInput->ShowWindow(SW_SHOW);
	}

}

void CLabelDlg::OnBnClickedClsButton()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.myclassMessage.OBJ_Vec.clear();
	m_ssValue=0;
	m_zoomLevel=1;

	OnPaint();
}

void CLabelDlg::OnBnClickedShrinkButton()
{
	// TODO: 在此添加控件通知处理程序代码
	for (int i=0;i<theApp.myclassMessage.OBJ_Vec.size();i++)
	{
		if (theApp.myclassMessage.OBJ_Vec[i].booFocus)
		{
			if(theApp.myclassMessage.OBJ_Vec[i].intRowStart=theApp.myclassMessage.OBJ_Vec[i].intSW>1)
			{
				theApp.myclassMessage.OBJ_Vec[i].intRowStart=theApp.myclassMessage.OBJ_Vec[i].intSW--;
				m_zoomLevel=theApp.myclassMessage.OBJ_Vec[i].intRowStart=theApp.myclassMessage.OBJ_Vec[i].intSW;
			}
			OnPaint();
			break;
		}
	}
}
