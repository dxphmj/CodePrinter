#include "StdAfx.h"
#include "BMPShow.h"


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
	CWnd::Default();   // 让控件画它自己的东西
	CClientDC  dc(this);

	CDC* pDC = &dc;
	CRect rectClient;
	CDC dcMem,dcBkgnd;
	CBitmap bitmapTemp;//, *pOldBitmap;
	//GetClientRect(&rectClient);//获取窗口信息
	bitmapTemp.CreateCompatibleBitmap(pDC, 255, 32);//创建内存位图
	dcMem.CreateCompatibleDC(pDC); //依附窗口DC创建兼容的DC
	//pOldBitmap = dcMem.SelectObject(&bitmapTemp);//将内存位图选入内存dc
	dcMem.SelectObject(&bitmapTemp);
	
	//填充颜色
	GetClientRect(&rectClient);
	CRect bitRect=rectClient;
	//bitRect.right=255;
	//bitRect.top=32;
	dcMem.FillSolidRect(bitRect,RGB(210, 231, 251));   //填充颜色
	CBrush cbrush;
	CBrush* pBrush; //旧笔刷
	//画点
	//CPen cBPen; 
	//cBPen.CreatePen(PS_SOLID,1,RGB(0,0,0)); 
	//CPen cWPen; 
	//cWPen.CreatePen(PS_SOLID,1,RGB(255,255,255)); 
	//CPen* pOldPen; 
	for (int i=0;i<bmpvec.size();i++)
	{
		for(int j=0;j<bmpvec[i].size();j++)
		{
			if (bmpvec[i][j])
			{
				//pOldPen = dcMem.SelectObject(&cBPen); //载入笔刷
				dcMem.SetPixel(bitRect.left+i,bitRect.top+j,RGB(0,0,0));
			} 
			else
			{
				dcMem.SetPixel(bitRect.left+i,bitRect.top+j,RGB(255,255,255));
			}
		}
	}

	//pDC->BitBlt(0,0,255,32,&dcMem,0,0,SRCCOPY);//绘制图片到主dc
	pDC->StretchBlt(0,0,510,64,&dcMem,0,0,255,32,SRCCOPY);
	dcMem.DeleteDC();      // 删除内存DC
	bitmapTemp.DeleteObject();      // 删除内存位图
	ReleaseDC(pDC); 




}
