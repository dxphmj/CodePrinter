// DesignStatic.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "DesignStatic.h"


// CDesignStatic

IMPLEMENT_DYNAMIC(CDesignStatic, CStatic)

CDesignStatic::CDesignStatic()
{

}

CDesignStatic::~CDesignStatic()
{
}


BEGIN_MESSAGE_MAP(CDesignStatic, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CDesignStatic 消息处理程序



void CDesignStatic::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CStatic::OnPaint()
	CWnd::Default();   // 让控件画它自己的东西
	CClientDC  dc(this);

    CDC* pDC = &dc;
	CRect rectClient;
	CDC dcMem,dcBkgnd;
	CBitmap bitmapTemp;//, *pOldBitmap;
	//GetClientRect(&rectClient);//获取窗口信息
	int tempNeed;
	if (theApp.m_MessageEdit.scrMaxRow<256)
	{
		tempNeed=1276;
	}
	else
	{
		tempNeed=theApp.m_MessageEdit.scrMaxRow*5 + 1;
	}
	bitmapTemp.CreateCompatibleBitmap(pDC, tempNeed, 161);//创建内存位图
	dcMem.CreateCompatibleDC(pDC); //依附窗口DC创建兼容的DC
	//pOldBitmap = dcMem.SelectObject(&bitmapTemp);//将内存位图选入内存dc
	dcMem.SelectObject(&bitmapTemp);
	//填充颜色
	GetClientRect(&rectClient);
	CRect bitRect=rectClient;
	bitRect.right=tempNeed;
	dcMem.FillSolidRect(bitRect,RGB(255,255,255));   //填充颜色
	
	CBrush cbrush;
	CBrush* pBrush; //旧笔刷
	int pixel = theApp.m_MessageEdit.Pixel+1;
	if(theApp.m_MessageEdit.Matrix!=14)//判断是否为2l7m
	{
		//画网格
		CPen cPen; 
		cPen.CreatePen(PS_SOLID,1,RGB(220,220,220)); 
		CPen* pOldPen; 
		pOldPen = dcMem.SelectObject(&cPen); //载入笔刷
		for (int i=0;i<=bitRect.Width();)//竖
		{
			dcMem.MoveTo(i,bitRect.Height()-5*pixel-1);
			dcMem.LineTo(i,bitRect.Height());
			i+=5;
		}
		for (int j=bitRect.Height()-5*pixel-1;j<=bitRect.Height();)
		{
			dcMem.MoveTo(0,j);
			dcMem.LineTo(bitRect.Width(),j);
			j+=5;
		}
		dcMem.SelectObject(pOldPen);
		cPen.DeleteObject();

		//画红线
		CPen cRPen; 
		cRPen.CreatePen(PS_SOLID,1,RGB(255,0,0)); 
		pOldPen = dcMem.SelectObject(&cRPen); //载入笔刷
		dcMem.MoveTo(bitRect.left,bitRect.Height()-1);
		dcMem.LineTo(bitRect.right,bitRect.Height()-1);
		dcMem.MoveTo(bitRect.left,bitRect.Height()-5*pixel-1);
		dcMem.LineTo(bitRect.right,bitRect.Height()-5*pixel-1);
		
		dcMem.SelectObject(pOldPen);
		cRPen.DeleteObject();		 
		//isFrame=false;
	}
	else
	{
		//画网格
		CPen cPen; 
		cPen.CreatePen(PS_SOLID,1,RGB(220,220,220)); 
		CPen* pOldPen; 
		pOldPen = dcMem.SelectObject(&cPen); //载入笔刷
		for (int i=0;i<=bitRect.Width();)//竖
		{
			dcMem.MoveTo(i,bitRect.Height()-5*7-1);
			dcMem.LineTo(i,bitRect.Height());
			dcMem.MoveTo(i,bitRect.Height()-5*15-1);
			dcMem.LineTo(i,bitRect.Height()-5*8-1);
			i+=5;
		}
		for (int j=bitRect.Height()-5*7-1;j<=bitRect.Height();)
		{
			dcMem.MoveTo(0,j);
			dcMem.LineTo(bitRect.Width(),j);
			j+=5;
		}
		for (int j=bitRect.Height()-5*15-1;j<=bitRect.Height()-5*8-1;)
		{
			dcMem.MoveTo(0,j);
			dcMem.LineTo(bitRect.Width(),j);
			j+=5;
		}
		dcMem.SelectObject(pOldPen);
		cPen.DeleteObject();

		//画红线
		CPen cRPen; 
		cRPen.CreatePen(PS_SOLID,1,RGB(255,0,0)); 
		pOldPen = dcMem.SelectObject(&cRPen); //载入笔刷
		dcMem.MoveTo(bitRect.left,bitRect.Height()-1);
		dcMem.LineTo(bitRect.right,bitRect.Height()-1);
		dcMem.MoveTo(bitRect.left,bitRect.Height()-5*7-1);
		dcMem.LineTo(bitRect.right,bitRect.Height()-5*7-1);
		dcMem.MoveTo(bitRect.left,bitRect.Height()-5*8-1);
		dcMem.LineTo(bitRect.right,bitRect.Height()-5*8-1);
		dcMem.MoveTo(bitRect.left,bitRect.Height()-5*15-1);
		dcMem.LineTo(bitRect.right,bitRect.Height()-5*15-1);
		dcMem.SelectObject(pOldPen);
		cRPen.DeleteObject();	
	}
	theApp.m_MessageEdit.DrawDot(&dcMem);
	pDC->BitBlt(0,0,rectClient.Width(),rectClient.Height(),&dcMem,theApp.scrPox*5,0,SRCCOPY);//绘制图片到主dc

	dcMem.DeleteDC();      // 删除内存DC
	bitmapTemp.DeleteObject();      // 删除内存位图
	ReleaseDC(pDC); 
}
