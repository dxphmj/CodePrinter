// MainPicture.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "MainPicture.h"


// MainPicture

IMPLEMENT_DYNAMIC(MainPicture, CStatic)

MainPicture::MainPicture()
{
	m_pDC = NULL;
	m_pixSize = 4;
}

MainPicture::~MainPicture()
{
	m_dcMem.SelectObject(m_pBrush);
	m_cbrush.DeleteObject();
 	m_dcMem.DeleteDC();               // 删除内存DC
	m_bitmapTemp.DeleteObject();      // 删除内存位图
	ReleaseDC(m_pDC);
}

BEGIN_MESSAGE_MAP(MainPicture, CStatic)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// MainPicture 消息处理程序
void MainPicture::OnPaint()
{
	CWnd::Default();   //让控件画它自己的东西
	if(m_pDC == NULL)
	{
		m_pDC = this->GetDC();
		GetClientRect(&m_rectClient);
		
		m_bitmapTemp.CreateCompatibleBitmap(m_pDC, 640, 129);//创建内存位图
		m_dcMem.CreateCompatibleDC(m_pDC); //依附窗口DC创建兼容的DC
		m_dcMem.SelectObject(&m_bitmapTemp);
		m_cbrush.CreateSolidBrush(RGB(0,0,0)); 
		m_pBrush = m_dcMem.SelectObject(&m_cbrush);
	}

	//填充颜色		
	CRect bkRect = m_rectClient;
	m_drawRect = m_rectClient;
	m_drawRect.top = m_rectClient.top+(32-theApp.mainPicPixel)*m_pixSize;
	bkRect.bottom = (32-theApp.mainPicPixel)*m_pixSize;
	m_dcMem.FillSolidRect(bkRect,theApp.m_BKcolor);
	m_dcMem.FillSolidRect(m_drawRect,RGB(255,255,255));   //填充颜色

	//画网格
	CPen cPen; 
	cPen.CreatePen(PS_SOLID,1,RGB(220,220,220)); 
	CPen* pOldPen; 
	pOldPen = m_dcMem.SelectObject(&cPen); //载入笔刷
	for (int i = 0; i <= m_rectClient.Width(); i += m_pixSize)//竖
	{
		m_dcMem.MoveTo(i,m_rectClient.Height()-m_pixSize*theApp.mainPicPixel-1);
		m_dcMem.LineTo(i,m_rectClient.Height());
	}
	for (int j = m_rectClient.Height()-m_pixSize*theApp.mainPicPixel-1; j <= m_rectClient.Height();j += m_pixSize)
	{
		m_dcMem.MoveTo(0,j);
		m_dcMem.LineTo(m_rectClient.Width(),j);
 	}
	m_dcMem.SelectObject(pOldPen);
	cPen.DeleteObject();		 
	if (theApp.mainPicMatrx == 14)
	{
		CRect bkRect = m_rectClient;
		bkRect.bottom = (32-7)*m_pixSize;
		bkRect.top = (32-8)*m_pixSize;
		m_dcMem.FillSolidRect(bkRect,theApp.m_BKcolor);
	}
	theApp.m_MessagePrint.DrawAllDynamic(&m_dcMem);
	m_pDC->BitBlt(0,0,m_rectClient.Width(),m_rectClient.Height(),&m_dcMem,0,0,SRCCOPY);//绘制图片到主dc

 	theApp.boDrawMainPic = true;
}

UINT MainpageDrawTheard(LPVOID pParam)
{
 	structMP *pstructMP = (structMP *)pParam;
	CClientDC  dc(pstructMP->myMainPicture);

	int pixSize = 4;
	CDC* pDC = &dc;

	while(theApp.mythreadDynamicBoo)
	{
		while(theApp.boDrawMainPic)
		{
			
			if(theApp.ForPreQue.size() >= 2)///////以后删掉
			{
				theApp.m_MessagePrint.intMesDis = theApp.ForPreQue.front();
				theApp.ForPreQue.pop();
			}

			theApp.m_MessagePrint.DrawAllDynamic(pDC);		 
			//Sleep(10);
		}
	}

	return 0;
}

BOOL MainPicture::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	return true;
	return CStatic::OnEraseBkgnd(pDC);
}
