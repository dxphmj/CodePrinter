// PictureStatic.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "PictureStatic.h"


// CPictureStatic

IMPLEMENT_DYNAMIC(CPictureStatic, CStatic)

CPictureStatic::CPictureStatic()
{
	m_bShowLogo = false;
	m_bShowGreenAlarm = m_bShowBlueAlarm = m_bShowYellowAlarm = m_bShowRedAlarm = true;
}

CPictureStatic::~CPictureStatic()
{
}


BEGIN_MESSAGE_MAP(CPictureStatic, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CPictureStatic ��Ϣ�������



void CPictureStatic::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CStatic::OnPaint()

	CWnd::Default();   // �ÿؼ������Լ��Ķ���

   // TODO: Add your message handler code here
   // ���������ֵ��һ��� ����

	CClientDC  dc(this);
	CFont* pof;
 
    //���ƻ�����������������Ϣ
	if(!m_bShowLogo)
	{
		pof = dc.SelectObject(theApp.m_HeadOperationStaFont);

		// ������ɫ
		dc.SetTextColor(RGB(255, 255, 255));
		// ͸��
		dc.SetBkMode(TRANSPARENT);
		CRect rect(10,0,200,95);
		// ������
		dc.DrawText(m_strOperation,&rect,DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		dc.SelectObject(pof);
	}

	 //���ƻ���״̬������Ϣ
	 		
	pof = dc.SelectObject(theApp.m_HeadMachineStaFont);
	// ������ɫ
	dc.SetTextColor(RGB(255, 255, 255));
	// ͸��
	dc.SetBkMode(TRANSPARENT);
	CRect rect2(360,0,440,95);
	// ������
	dc.DrawText(m_strMachineStatus,&rect2,DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	dc.SelectObject(pof); 

	if(m_bShowLogo)
	{ 
		CBitmap bm;
		bm.LoadBitmap(IDB_BITMAP1);
		CRect rect3(0,0,200,95);
 		BITMAP bm1;
		CDC menbm;
		menbm.CreateCompatibleDC(&dc);
		menbm.SelectObject(&bm);
		dc.BitBlt(0,0,rect3.Width(),rect3.Height(),&menbm,1,1,SRCCOPY);
	} 

	int nAlarmStart = 500;
	int nAlarmWidth = 50;
	int nAlarmHeight = 50;
	int nAlarmStep = 5;
	int nCenterY = 50;


	if(m_bShowGreenAlarm)
	{ 
		CBitmap bm;
		bm.LoadBitmap(IDB_GREEN_LAMP_BITMAP);
		CRect rect3(CPoint(nAlarmStart,nCenterY-nAlarmHeight/2),CSize(nAlarmWidth,nAlarmHeight));
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
		CRect rect3(CPoint(nAlarmStart+nAlarmWidth+nAlarmStep,nCenterY-nAlarmHeight/2),CSize(nAlarmWidth,nAlarmHeight));
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
		CRect rect3(CPoint(nAlarmStart+(nAlarmWidth+nAlarmStep)*2,nCenterY-nAlarmHeight/2),CSize(nAlarmWidth,nAlarmHeight));
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
		CRect rect3(CPoint(nAlarmStart+(nAlarmWidth+nAlarmStep)*3,nCenterY-nAlarmHeight/2),CSize(nAlarmWidth,nAlarmHeight));
 		BITMAP bm1;
		CDC menbm;
		menbm.CreateCompatibleDC(&dc);
		menbm.SelectObject(&bm);
		dc.BitBlt(rect3.left,rect3.top,rect3.Width(),rect3.Height(),&menbm,1,1,SRCCOPY);
	} 
}

void CPictureStatic::SetRedAlarm(bool bAlarm)
{
	if(m_bShowRedAlarm != bAlarm)
	{
        m_bShowRedAlarm = bAlarm;
		Invalidate();
	}
}

void CPictureStatic::SetGreenAlarm(bool bAlarm)
{
	if(m_bShowGreenAlarm != bAlarm)
	{
        m_bShowGreenAlarm = bAlarm;
		Invalidate();
	}
}

void CPictureStatic::SetBlueAlarm(bool bAlarm)	
{
	if(m_bShowBlueAlarm != bAlarm)
	{
        m_bShowBlueAlarm = bAlarm;
		Invalidate();
	}
}

void CPictureStatic::SetYellowAlarm(bool bAlarm)
{
	if(m_bShowYellowAlarm != bAlarm)
	{
        m_bShowYellowAlarm = bAlarm;
		Invalidate();
	}
}
