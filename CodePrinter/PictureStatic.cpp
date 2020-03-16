// PictureStatic.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "PictureStatic.h"


// CPictureStatic

IMPLEMENT_DYNAMIC(CPictureStatic, CStatic)

CPictureStatic::CPictureStatic()
{
	m_bShowLogo = false;
	m_bShowGreenAlarm = m_bShowBlueAlarm = m_bShowYellowAlarm = m_bShowRedAlarm = false;
}

CPictureStatic::~CPictureStatic()
{
}


BEGIN_MESSAGE_MAP(CPictureStatic, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CPictureStatic 消息处理程序



void CPictureStatic::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CStatic::OnPaint()

	CWnd::Default();   // 让控件画它自己的东西

   // TODO: Add your message handler code here
   // 接下来就轮到我画了 ：）

	CClientDC  dc(this);
	CFont* pof;
 
    //绘制机器操作步骤文字信息
	if(m_bShowLogo)
	{ 
		CBitmap bm;
		bm.LoadBitmap(IDB_BITMAP_LOGO);
		CRect rect3(0,9,275,67);
		CDC menbm;
		menbm.CreateCompatibleDC(&dc);
		menbm.SelectObject(&bm);
		dc.BitBlt(rect3.left,rect3.top,rect3.Width(),rect3.Height(),&menbm,1,1,SRCCOPY);
	} 
	else
	{
		pof = dc.SelectObject(theApp.m_HeadOperationStaFont);

		// 文字颜色
		dc.SetTextColor(RGB(255, 255, 255));
		// 透明
		dc.SetBkMode(TRANSPARENT);
		//CRect rect(15,20,285,75);
		CRect rect(15,0,285,75);
		// 绘文字
		dc.DrawText(m_strOperation,&rect,DT_SINGLELINE | DT_VCENTER);
		dc.SelectObject(pof);
	}

	 //绘制机器状态文字信息
	 		
	pof = dc.SelectObject(theApp.m_HeadMachineStaFont);
	// 文字颜色
	dc.SetTextColor(RGB(255, 255, 255));
	// 透明
	dc.SetBkMode(TRANSPARENT);
	CRect rect2(300,0,495,75);
	// 绘文字
	dc.DrawText(m_strMachineStatus,&rect2,DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	dc.SelectObject(pof); 


	int nAlarmStart = 500;
	int nAlarmWidth = 42;
	int nAlarmHeight = 42;
	int nAlarmStep = 13;
 	int nAlarmTop = 37-21;


	if(m_bShowGreenAlarm)
	{ 
		CBitmap bm;
		bm.LoadBitmap(IDB_GREEN_LAMP_BITMAP);
		CRect rect3(CPoint(nAlarmStart,nAlarmTop),CSize(nAlarmWidth,nAlarmHeight));
 		BITMAP bm1;
		CDC menbm;
		menbm.CreateCompatibleDC(&dc);
		menbm.SelectObject(&bm);
		dc.BitBlt(rect3.left,rect3.top,rect3.Width(),rect3.Height(),&menbm,1,1,SRCCOPY);
	} 

	if(m_bShowBlueAlarm)
	{ 
		CBitmap bm;
		bm.LoadBitmap(IDB_BLUE_LAMP_BITMAP);
		CRect rect3(CPoint(nAlarmStart+nAlarmWidth+nAlarmStep,nAlarmTop),CSize(nAlarmWidth,nAlarmHeight));
 		BITMAP bm1;
		CDC menbm;
		menbm.CreateCompatibleDC(&dc);
		menbm.SelectObject(&bm);
		dc.BitBlt(rect3.left,rect3.top,rect3.Width(),rect3.Height(),&menbm,1,1,SRCCOPY);
	} 

	if(m_bShowYellowAlarm)
	{ 
		CBitmap bm;
		bm.LoadBitmap(IDB_YELLOW_LAMP_BITMAP);
		CRect rect3(CPoint(nAlarmStart+(nAlarmWidth+nAlarmStep)*2,nAlarmTop),CSize(nAlarmWidth,nAlarmHeight));
 		BITMAP bm1;
		CDC menbm;
		menbm.CreateCompatibleDC(&dc);
		menbm.SelectObject(&bm);
		dc.BitBlt(rect3.left,rect3.top,rect3.Width(),rect3.Height(),&menbm,1,1,SRCCOPY);
	} 

	if(m_bShowRedAlarm)
	{ 
		CBitmap bm;
		bm.LoadBitmap(IDB_RED_LAMP_BITMAP);
		CRect rect3(CPoint(nAlarmStart+(nAlarmWidth+nAlarmStep)*3,nAlarmTop),CSize(nAlarmWidth,nAlarmHeight));
 		BITMAP bm1;
		CDC menbm;
		menbm.CreateCompatibleDC(&dc);
		menbm.SelectObject(&bm);
		dc.BitBlt(rect3.left,rect3.top,rect3.Width(),rect3.Height(),&menbm,1,1,SRCCOPY);
	} 
}

void CPictureStatic::SetRedAlarm(bool bAlarm)
{
	m_bRedAlarm = bAlarm;
	if(m_bShowRedAlarm != bAlarm)
	{
        m_bShowRedAlarm = bAlarm;
		Invalidate();
	}
}

void CPictureStatic::SetGreenAlarm(bool bAlarm)
{
	m_bGreenAlarm = bAlarm;
	if(m_bShowGreenAlarm != bAlarm)
	{
        m_bShowGreenAlarm = bAlarm;
		Invalidate();
	}
}

void CPictureStatic::SetBlueAlarm(bool bAlarm)	
{
	m_bBlueAlarm = bAlarm;
	if(m_bShowBlueAlarm != bAlarm)
	{
        m_bShowBlueAlarm = bAlarm;
		Invalidate();
	}
}

void CPictureStatic::SetYellowAlarm(bool bAlarm)
{
	m_bYellowAlarm = bAlarm;
	if(m_bShowYellowAlarm != bAlarm)
	{
        m_bShowYellowAlarm = bAlarm;
		Invalidate();
	}
}

void CPictureStatic::SetOperationString(CString OperationString)
{
	m_strOperation = OperationString;
	m_bShowLogo = false;
	if(m_strOperation.CompareNoCase(_T("")) == 0) 
		m_bShowLogo = true;
	Invalidate();
}