// InkPhasingDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "InkPhasingDlg.h"


// CInkPhasingDlg 对话框

IMPLEMENT_DYNAMIC(CInkPhasingDlg, CDialog)

CInkPhasingDlg::CInkPhasingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInkPhasingDlg::IDD, pParent)
	, m_fixed(0)
{
	for(int i = 0; i < 35; i++)
	{
		m_AngleBitmap[i].LoadBitmap(IDB_PNG_ANG0+i);  // 将位图IDB_BITMAP1加载到bitmap  
		m_AnglehBmp[i] = (HBITMAP)m_AngleBitmap[i].GetSafeHandle();  // 获取bitmap加载位图的句柄   
	}
}

CInkPhasingDlg::~CInkPhasingDlg()
{
}

void CInkPhasingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FIXED_EDIT, m_fixed);
	DDX_Control(pDX, IDC_AUTO_SET_BTN, m_PhaMvAuto);
	DDX_Control(pDX, IDC_SET_ADJUST_BIG_BTN, m_PhaMvStep10);
	DDX_Control(pDX, IDC_SET_ADJUST_SMALL_BTN, m_PhaMvStep1);
	DDX_Control(pDX, IDC_PHASING_ADD_BTN, m_PhaMvAdd);
	DDX_Control(pDX, IDC_PASHING_CUT_BTN, m_PhaMvSub);
	DDX_Control(pDX, IDC_PIC_PHA_ANGLE, m_PicPhaAngle);
}


BEGIN_MESSAGE_MAP(CInkPhasingDlg, CDialog)

		ON_WM_CTLCOLOR()

		ON_BN_CLICKED(IDC_PHASING_ADD_BTN, &CInkPhasingDlg::OnBnClickedPhasingAddBtn)
		ON_BN_CLICKED(IDC_PASHING_CUT_BTN, &CInkPhasingDlg::OnBnClickedPashingCutBtn)
		ON_BN_CLICKED(IDC_SET_ADJUST_SMALL_BTN, &CInkPhasingDlg::OnBnClickedSetAdjustSmallBtn)
		ON_BN_CLICKED(IDC_SET_ADJUST_BIG_BTN, &CInkPhasingDlg::OnBnClickedSetAdjustBigBtn)
		ON_BN_CLICKED(IDC_AUTO_SET_BTN, &CInkPhasingDlg::OnBnClickedAutoSetBtn)
END_MESSAGE_MAP()


// CInkPhasingDlg 消息处理程序
HBRUSH CInkPhasingDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

void CInkPhasingDlg::OnBnClickedPhasingAddBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	if(m_fixed + theApp.myStatusClass.bytModuStep > 200)
		m_fixed = 200;
	else if(m_fixed + theApp.myStatusClass.bytModuStep <= 200)
		m_fixed = m_fixed + theApp.myStatusClass.bytModuStep;
	UpdateData(false);

}

void CInkPhasingDlg::OnBnClickedPashingCutBtn()
{
	// TODO: 在此添加控件通知处理程序代码
    UpdateData();
	if(m_fixed - theApp.myStatusClass.bytModuStep > 0)
		m_fixed = m_fixed - theApp.myStatusClass.bytModuStep;
	else if(m_fixed - theApp.myStatusClass.bytModuStep <= 0)
	{
		m_fixed = 1;
	}
	UpdateData(false);

//If (bytModuVol - bytModuStep) > 0 Then
//bytModuVol = bytModuVol - bytModuStep
//texval_inksystem_pha_mv.Text = CStr(bytModuVol)
//ElseIf (bytModuVol - bytModuStep) <= 0 Then
//bytModuVol = 1
//texval_inksystem_pha_mv.Text = CStr(bytModuVol)
//End If
//save_inksystem_mv_to_xml()
//download_inksystem_mv()

}

void CInkPhasingDlg::OnBnClickedSetAdjustSmallBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.myStatusClass.bytModuStep = 1;
	m_PhaMvStep1.m_bitmapNorm.DeleteObject();
	m_PhaMvStep1.m_bitmapNorm.LoadBitmap(MAKEINTRESOURCE(IDB_BITMAP_PHA_CIRCLE_SEL));

	m_PhaMvStep10.m_bitmapNorm.DeleteObject();
	m_PhaMvStep10.m_bitmapNorm.LoadBitmap(MAKEINTRESOURCE(IDB_BITMAP_PHA_CIRCLE_UNSEL));

	m_PhaMvStep1.Invalidate();
	m_PhaMvStep10.Invalidate();

}

void CInkPhasingDlg::OnBnClickedSetAdjustBigBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.myStatusClass.bytModuStep = 10;
	m_PhaMvStep1.m_bitmapNorm.DeleteObject();
	m_PhaMvStep1.m_bitmapNorm.LoadBitmap(MAKEINTRESOURCE(IDB_BITMAP_PHA_CIRCLE_UNSEL));

	m_PhaMvStep10.m_bitmapNorm.DeleteObject();
	m_PhaMvStep10.m_bitmapNorm.LoadBitmap(MAKEINTRESOURCE(IDB_BITMAP_PHA_CIRCLE_SEL));

	m_PhaMvStep1.Invalidate();
	m_PhaMvStep10.Invalidate();

}

void CInkPhasingDlg::OnBnClickedAutoSetBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	theApp.myStatusClass.ctr0X03bit6 = !theApp.myStatusClass.ctr0X03bit6;
	if(theApp.myStatusClass.ctr0X03bit6 == 1)
	{
		m_PhaMvAuto.m_bitmapNorm.DeleteObject();
		m_PhaMvAuto.m_bitmapNorm.LoadBitmap(MAKEINTRESOURCE(IDB_BITMAP_PHA_CIRCLE_SEL));
	}
	else
	{
		m_PhaMvAuto.m_bitmapNorm.DeleteObject();
		m_PhaMvAuto.m_bitmapNorm.LoadBitmap(MAKEINTRESOURCE(IDB_BITMAP_PHA_CIRCLE_UNSEL));
	}
	m_PhaMvAuto.Invalidate();
}

BOOL CInkPhasingDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_PhaMvAuto.LoadBitmaps(IDB_BITMAP_PHA_CIRCLE_UNSEL,IDB_BITMAP_PHA_CIRCLE_UNSEL,0,0,IDB_BITMAP_PHA_CIRCLE_UNSEL);
	m_PhaMvAuto.SizeToContent(); 

	m_PhaMvStep10.LoadBitmaps(IDB_BITMAP_PHA_CIRCLE_UNSEL,IDB_BITMAP_PHA_CIRCLE_UNSEL,0,0,IDB_BITMAP_PHA_CIRCLE_UNSEL);
	m_PhaMvStep10.SizeToContent(); 

	m_PhaMvStep1.LoadBitmaps(IDB_BITMAP_PHA_CIRCLE_UNSEL,IDB_BITMAP_PHA_CIRCLE_UNSEL,0,0,IDB_BITMAP_PHA_CIRCLE_UNSEL);
	m_PhaMvStep1.SizeToContent(); 

	m_PhaMvAdd.LoadBitmaps(IDB_BITMAP_PHA_ADD_UP,IDB_BITMAP_PHA_ADD_DOWM,0,0,IDB_BITMAP_PHA_ADD_DOWM);
	m_PhaMvAdd.SizeToContent(); 

	m_PhaMvSub.LoadBitmaps(IDB_BITMAP_PHA_SUB_UP,IDB_BITMAP_PHA_SUB_DOWM,0,0,IDB_BITMAP_PHA_SUB_DOWM);
	m_PhaMvSub.SizeToContent(); 

	if(theApp.myStatusClass.ctr0X03bit6 == 1)
	{
		m_PhaMvAuto.m_bitmapNorm.DeleteObject();
		m_PhaMvAuto.m_bitmapNorm.LoadBitmap(MAKEINTRESOURCE(IDB_BITMAP_PHA_CIRCLE_SEL));
	}
	else
	{
		m_PhaMvAuto.m_bitmapNorm.DeleteObject();
		m_PhaMvAuto.m_bitmapNorm.LoadBitmap(MAKEINTRESOURCE(IDB_BITMAP_PHA_CIRCLE_UNSEL));
	}
//	m_PhaMvAuto.Invalidate();

	if(theApp.myStatusClass.bytModuStep = 10)
	{
		m_PhaMvStep1.m_bitmapNorm.DeleteObject();
		m_PhaMvStep1.m_bitmapNorm.LoadBitmap(MAKEINTRESOURCE(IDB_BITMAP_PHA_CIRCLE_UNSEL));

		m_PhaMvStep10.m_bitmapNorm.DeleteObject();
		m_PhaMvStep10.m_bitmapNorm.LoadBitmap(MAKEINTRESOURCE(IDB_BITMAP_PHA_CIRCLE_SEL));
	}
	else
	{
		m_PhaMvStep1.m_bitmapNorm.DeleteObject();
		m_PhaMvStep1.m_bitmapNorm.LoadBitmap(MAKEINTRESOURCE(IDB_BITMAP_PHA_CIRCLE_SEL));

		m_PhaMvStep10.m_bitmapNorm.DeleteObject();
		m_PhaMvStep10.m_bitmapNorm.LoadBitmap(MAKEINTRESOURCE(IDB_BITMAP_PHA_CIRCLE_UNSEL));

	}

   	m_PicPhaAngle.SetBitmap(m_AnglehBmp[0]);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
