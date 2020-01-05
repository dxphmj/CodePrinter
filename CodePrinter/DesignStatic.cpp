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
	bitmapTemp.CreateCompatibleBitmap(pDC, 781, 161);//创建内存位图
	dcMem.CreateCompatibleDC(pDC); //依附窗口DC创建兼容的DC
	//pOldBitmap = dcMem.SelectObject(&bitmapTemp);//将内存位图选入内存dc
	dcMem.SelectObject(&bitmapTemp);
	//填充颜色
	GetClientRect(&rectClient);
	dcMem.FillSolidRect(rectClient,RGB(255,255,255));   //填充颜色
	
	CBrush cbrush;
	CBrush* pBrush; //旧笔刷
	int pixel = theApp.myclassMessage.Pixel+1;
	if(1)
	{
		//画网格
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

		//画红线
		CPen cRPen; 
		cRPen.CreatePen(PS_SOLID,1,RGB(255,0,0)); 
		pOldPen = dcMem.SelectObject(&cRPen); //载入笔刷
		dcMem.MoveTo(rectClient.left,rectClient.Height()-1);
		dcMem.LineTo(rectClient.right,rectClient.Height()-1);
		dcMem.MoveTo(rectClient.left,rectClient.Height()-5*pixel-1);
		dcMem.LineTo(rectClient.right,rectClient.Height()-5*pixel-1);
		
		dcMem.SelectObject(pOldPen);
		cRPen.DeleteObject();
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
}
