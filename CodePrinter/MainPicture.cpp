// MainPicture.cpp : 实现文件
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "MainPicture.h"


// MainPicture

IMPLEMENT_DYNAMIC(MainPicture, CStatic)

MainPicture::MainPicture()
{

}

MainPicture::~MainPicture()
{
}


BEGIN_MESSAGE_MAP(MainPicture, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// MainPicture 消息处理程序



void MainPicture::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CStatic::OnPaint()
	CWnd::Default();   // 让控件画它自己的东西
	CClientDC  dc(this);
	//////////////////////////////////////////////////////////////////////////
	int pixSize=4;

	////
	CDC* pDC = &dc;
	CRect rectClient;
	CDC dcMem,dcBkgnd;
	CBitmap bitmapTemp;//, *pOldBitmap;
	//GetClientRect(&rectClient);//获取窗口信息
	bitmapTemp.CreateCompatibleBitmap(pDC, 640, 129);//创建内存位图
	dcMem.CreateCompatibleDC(pDC); //依附窗口DC创建兼容的DC
	//pOldBitmap = dcMem.SelectObject(&bitmapTemp);//将内存位图选入内存dc
	dcMem.SelectObject(&bitmapTemp);
	//填充颜色
	GetClientRect(&rectClient);
	CRect drawRect=rectClient;
	drawRect.top=rectClient.top+(32-theApp.myclassMessage.Pixel)*pixSize;
	CRect bkRect=rectClient;
	bkRect.bottom=(32-theApp.myclassMessage.Pixel)*pixSize;
	dcMem.FillSolidRect(bkRect,theApp.m_BKcolor);
	dcMem.FillSolidRect(drawRect,RGB(255,255,255));   //填充颜色

	CBrush cbrush;
	CBrush cwrush;
	CBrush *pBrush; //旧笔刷
	cbrush.CreateSolidBrush(RGB(0,0,0)); 
	cwrush.CreateSolidBrush(RGB(255,255,255));
	int pixel = theApp.myclassMessage.Pixel;
	if(1)
	{
		//画网格
		CPen cPen; 
		cPen.CreatePen(PS_SOLID,1,RGB(220,220,220)); 
		CPen* pOldPen; 
		pOldPen = dcMem.SelectObject(&cPen); //载入笔刷
		for (int i=0;i<=rectClient.Width();)//竖
		{
			dcMem.MoveTo(i,rectClient.Height()-pixSize*pixel-1);
			dcMem.LineTo(i,rectClient.Height());
			i+=pixSize;
		}
		for (int j=rectClient.Height()-pixSize*pixel-1;j<=rectClient.Height();)
		{
			dcMem.MoveTo(0,j);
			dcMem.LineTo(rectClient.Width(),j);
			j+=pixSize;
		}
		dcMem.SelectObject(pOldPen);
		cPen.DeleteObject();
		pOldPen->DeleteObject();
		//isFrame=false;
	}
	///theApp.myclassMessage.DrawDot(&dcMem);

	//int recSize=4;
	for (int i=0;i<theApp.myclassMessage.Pixel;i++)
	{
		for (int j=0;j<theApp.myclassMessage.intRowMax;j++)
		{
			if (theApp.myclassMessage.boDotMes[i][j])
			{
				int tx=j*pixSize+1;
				int ty=129-(i+1)*pixSize;
				int bx=(j+1)*pixSize;
				int by=129-i*pixSize-1;
				pBrush=dcMem.SelectObject(&cbrush);
				//LPCRECT xyRect;
				//xyRect->left=tx;
				//xyRect->top=ty;
				//xyRect->bottom=by;
				//xyRect->right=bx;
				//dcMem.FillSolidRect(tx,ty,bx,by,RGB(0,0,0));
				dcMem.Rectangle(tx,ty,bx,by);
			}
			//else
			//{
			//	
			//	int tx=j*pixSize+1;
			//	int ty=129-(i+1)*pixSize;
			//	int bx=(j+1)*pixSize;
			//	int by=129-i*pixSize-1;
			//	pBrush=dcMem.SelectObject(&cwrush);
			//	//LPCRECT xyRect;
			//	//xyRect->left=tx;
			//	//xyRect->top=ty;
			//	//xyRect->bottom=by;
			//	//xyRect->right=bx;
			//	//dcMem.FillSolidRect(tx,ty,bx,by,RGB(0,0,0));
			//	dcMem.Rectangle(tx,ty,bx,by);
			//	
			//}
		}
	}
	pDC->BitBlt(0, 0, rectClient.Width(), rectClient.Height(), &dcMem, 0, 0, SRCCOPY);//绘制图片到主dc
	//dcMem.SelectObject(pOldBitmap);//清理
	dcMem.DeleteDC();      // 删除内存DC
	bitmapTemp.DeleteObject();      // 删除内存位图
	//theApp.myclassMessage.DrawDot(pDC);

	ReleaseDC(pDC); 
}
