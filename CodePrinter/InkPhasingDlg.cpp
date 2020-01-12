// InkPhasingDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "InkPhasingDlg.h"
#include "BnvImage.h"
#include "InkSystemDlg.h"
#include "CodePrinterDlg.h"
#include "DealXml.h"


// CInkPhasingDlg 对话框

IMPLEMENT_DYNAMIC(CInkPhasingDlg, CDialog)

CInkPhasingDlg::CInkPhasingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInkPhasingDlg::IDD, pParent)
	, m_fixed(0)
{ 

#ifndef _DEBUG
	for(int i = 0; i < 35; i++)
	{
		CBnvImage PngImage;
		PngImage.LoadFromResource(MAKEINTRESOURCE(IDB_PNG_ANG0+i), _T("PNG")); 
		m_AnglehBmp[i] = PngImage.CreatHBitmap();
	}
#else
	CBnvImage PngImage;
	PngImage.LoadFromResource(MAKEINTRESOURCE(IDB_PNG_ANG0), _T("PNG")); 
	HBITMAP h = PngImage.CreatHBitmap();
	for(int i = 0; i < 35; i++)
	{
		m_AnglehBmp[i] = h;
	}
#endif
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
	DDX_Control(pDX, IDC_FIXED_EDIT, m_edit_fiexd);
}


BEGIN_MESSAGE_MAP(CInkPhasingDlg, CDialog)

		ON_WM_CTLCOLOR()

		ON_BN_CLICKED(IDC_PHASING_ADD_BTN, &CInkPhasingDlg::OnBnClickedPhasingAddBtn)
		ON_BN_CLICKED(IDC_PASHING_CUT_BTN, &CInkPhasingDlg::OnBnClickedPashingCutBtn)
		ON_BN_CLICKED(IDC_SET_ADJUST_SMALL_BTN, &CInkPhasingDlg::OnBnClickedSetAdjustSmallBtn)
		ON_BN_CLICKED(IDC_SET_ADJUST_BIG_BTN, &CInkPhasingDlg::OnBnClickedSetAdjustBigBtn)
		ON_BN_CLICKED(IDC_AUTO_SET_BTN, &CInkPhasingDlg::OnBnClickedAutoSetBtn)
		ON_EN_SETFOCUS(IDC_FIXED_EDIT, &CInkPhasingDlg::OnEnSetfocusFixedEdit)
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


void CInkPhasingDlg::save_inksystem_mv_to_xml()
{
	CDealXml dealXml;
	CString pcf_currentname,pcf_currentpath;

	//当前或上次打开的配置文件名
	pcf_currentname = _T("InkSystem.xml");	
	//当前或上次打开的配置文件的路径
	pcf_currentpath = _T("Storage Card\\System");

	CString strTmp;
    strTmp.Format(L"%d",m_fixed);    
    dealXml.WriteXml(pcf_currentname, L"ModulationVoltage", strTmp,pcf_currentpath);
	//WriteXML("inksystem.xml", "ModulationVoltage", texval_inksystem_pha_mv.Text, "\Storage Card\System")

}

//void CInkPhasingDlg::download_inksystem_mv()
//{
//	byte inksystem_parameter_0x05, inksystem_parameter_0x06;
//	int nParam = m_fixed;
//	inksystem_parameter_0x05 = (nParam * 10) & 0xFF; //晶振电压为0到200;缺省是60较合适
//	inksystem_parameter_0x06 = (nParam * 10) >> 8;
//
//	vector<BYTE> tempCtrVec;
//
//	tempCtrVec.push_back(0x01);
//	tempCtrVec.push_back(0x80);
//	tempCtrVec.push_back(0x04);
//	tempCtrVec.push_back(0x05);
//
//	tempCtrVec.push_back(0x05);
//	tempCtrVec.push_back(inksystem_parameter_0x05);
//	tempCtrVec.push_back(inksystem_parameter_0x06);
//
//	tempCtrVec.push_back(0xFF);
//	tempCtrVec.push_back(0xFF);
//
//	theApp.boQueCtrLock.Lock();
//	theApp.queCtr.push(tempCtrVec);
//	theApp.boQueCtrLock.Unlock();
//    //queCtr.Enqueue(New Byte() {&H1, &H80, &H4, &H5, &H5, inksystem_parameter_0x05, inksystem_parameter_0x06, &HFF, &HFF})
//}

void CInkPhasingDlg::OnBnClickedPhasingAddBtn()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	if(m_fixed + theApp.myStatusClass.bytModuStep > 200)
		m_fixed = 200;
	else if(m_fixed + theApp.myStatusClass.bytModuStep <= 200)
		m_fixed = m_fixed + theApp.myStatusClass.bytModuStep;
	UpdateData(false);

	//download_inksystem_mv();
	//theApp.myModuleMain.changeXml("inksystem.xml","ModulationVoltage",theApp.myclassMessage.to_String(m_fixed),"Storage Card\\System");


	save_inksystem_mv_to_xml();
	download_inksystem_mv();

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
 

	//save_inksystem_mv_to_xml();
	//download_inksystem_mv();
	//theApp.myModuleMain.changeXml("inksystem.xml","ModulationVoltage",theApp.myclassMessage.to_String(m_fixed),"Storage Card\\System");
	

	save_inksystem_mv_to_xml();
	download_inksystem_mv();

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
	m_edit_fiexd.SetFont(theApp.m_EditFont);
	//////////////////////////////////////////////////////////////////////////

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}



void CInkPhasingDlg::OnEnSetfocusFixedEdit()
{
	// TODO: 在此添加控件通知处理程序代码
	CEdit *pEdit = &m_edit_fiexd;

	CCodePrinterDlg* dlg;
	dlg = (CCodePrinterDlg*)(GetParent()->GetParent());
	dlg->OpenNumKeyBoard(pEdit);
}

void CInkPhasingDlg::download_inksystem_mv()
{
	BYTE inksystem_parameter_0x05, inksystem_parameter_0x06;
	inksystem_parameter_0x05=(m_fixed*10)&0xFF;
	inksystem_parameter_0x06=(m_fixed*10)>>8;
	vector<BYTE> tempQueVec;
	tempQueVec.push_back(0x1);
	tempQueVec.push_back(0x80);
	tempQueVec.push_back(0x4);
	tempQueVec.push_back(0x5);
	tempQueVec.push_back(0x5);
	tempQueVec.push_back(inksystem_parameter_0x05);
	tempQueVec.push_back(inksystem_parameter_0x06);
	tempQueVec.push_back(0xFF);
	tempQueVec.push_back(0xFF);
	theApp.boQueCtrLock.Lock();

		theApp.queCtr.push(tempQueVec);
	theApp.boQueCtrLock.Unlock();
}