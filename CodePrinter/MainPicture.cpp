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
	CDC* pDC = &dc;
	CRect rectClient;
	CDC dcMem,dcBkgnd;
	CBitmap bitmapTemp; 
	bitmapTemp.CreateCompatibleBitmap(pDC, 640, 129);//创建内存位图
	dcMem.CreateCompatibleDC(pDC); //依附窗口DC创建兼容的DC
	dcMem.SelectObject(&bitmapTemp);
	//填充颜色
	int pixSize = 4;
	GetClientRect(&rectClient);
	CRect drawRect=rectClient;
	drawRect.top=rectClient.top+(32-theApp.mainPicPixel)*pixSize;
	CRect bkRect=rectClient;
	bkRect.bottom=(32-theApp.mainPicPixel)*pixSize;
	dcMem.FillSolidRect(bkRect,theApp.m_BKcolor);
	dcMem.FillSolidRect(drawRect,RGB(255,255,255));   //填充颜色

	CBrush cbrush;
 	CBrush *pBrush; //旧笔刷
	cbrush.CreateSolidBrush(RGB(0,0,0)); 
 	//int pixel = theApp.myclassMessage.Pixel+1;

		//画网格
		CPen cPen; 
		cPen.CreatePen(PS_SOLID,1,RGB(220,220,220)); 
		CPen* pOldPen; 
		pOldPen = dcMem.SelectObject(&cPen); //载入笔刷
		for (int i=0;i<=rectClient.Width();)//竖
		{
			dcMem.MoveTo(i,rectClient.Height()-pixSize*theApp.mainPicPixel-1);
			dcMem.LineTo(i,rectClient.Height());
			i+=pixSize;
		}
		for (int j=rectClient.Height()-pixSize*theApp.mainPicPixel-1;j<=rectClient.Height();)
		{
			dcMem.MoveTo(0,j);
			dcMem.LineTo(rectClient.Width(),j);
			j+=pixSize;
		}
		dcMem.SelectObject(pOldPen);
		cPen.DeleteObject();		 
		//isFrame=false;
	if (theApp.mainPicMatrx==14)
	{
		CRect bkRect=rectClient;
		bkRect.bottom=(32-7)*pixSize;
		bkRect.top=(32-8)*pixSize;
		dcMem.FillSolidRect(bkRect,theApp.m_BKcolor);
	}

	pBrush = dcMem.SelectObject(&cbrush);
	theApp.myclassMessage.DrawMainPageDot(&dcMem);
	
	pDC->BitBlt(0, 0, rectClient.Width(), rectClient.Height(), &dcMem, 0, 0, SRCCOPY);//绘制图片到主dc

	dcMem.SelectObject(pBrush);
	cbrush.DeleteObject();

 	dcMem.DeleteDC();               // 删除内存DC
	bitmapTemp.DeleteObject();      // 删除内存位图
 	theApp.boDrawMainPic = true;
	ReleaseDC(pDC); 	
}


UINT methoddis(LPVOID pParam)
{
	structMP *pstructMP = (structMP *)pParam;
	CClientDC  dc(pstructMP->myMainPicture);
	//////////////////////////////////////////////////////////////////////////
	int pixSize = 4;

	////
	CDC* pDC = &dc;
	////目前不用双重缓存
	//CRect rectClient;
	//CDC dcMem,dcBkgnd;
	//CBitmap bitmapTemp;//, *pOldBitmap;
	////GetClientRect(&rectClient);//获取窗口信息
	//bitmapTemp.CreateCompatibleBitmap(pDC, 640, 129);//创建内存位图
	//dcMem.CreateCompatibleDC(pDC); //依附窗口DC创建兼容的DC
	////pOldBitmap = dcMem.SelectObject(&bitmapTemp);//将内存位图选入内存dc
	//dcMem.SelectObject(&bitmapTemp);
	
	while(theApp.mythreadDynamicBoo)
	{
		while(theApp.boDrawMainPic)
		{
			for(int i = 0; i < theApp.myclassMessage.OBJ_Vec.size(); i++)
			{		 
				if (theApp.myclassMessage.OBJ_Vec[i]->strType2 == "serial")
				{	
					int intDynamicRowEnd = theApp.myclassMessage.OBJ_Vec[i]->intRowStart+theApp.myclassMessage.OBJ_Vec[i]->intRowSize-1;
					int nRowStartdis = theApp.myclassMessage.OBJ_Vec[i]->intRowStart;
					int nStartValue = theApp.myclassMessage.OBJ_Vec[i]->intSerialStartValue;
					theApp.myclassMessage.DrawSerialTimeDynamic(nRowStartdis,intDynamicRowEnd,nStartValue,pDC);		
				}
				else if (theApp.myclassMessage.OBJ_Vec[i]->strType2 == "time")
				{	
					int intDynamicRowEnd = theApp.myclassMessage.OBJ_Vec[i]->intRowStart+theApp.myclassMessage.OBJ_Vec[i]->intRowSize-1;
					int nRowStartdis = theApp.myclassMessage.OBJ_Vec[i]->intRowStart;
					 
					theApp.myclassMessage.DrawSerialTimeDynamic(nRowStartdis,intDynamicRowEnd,nRowStartdis,pDC);		
				}
			}
		}
		Sleep(10);
	}

	return 0;
}