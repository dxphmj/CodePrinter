#include "StdAfx.h"
#include "BnvImage.h"
#include <ObjBase.h>
#include <initguid.h>
#include <imgguids.h>

/********************************************************************

	purpose:	为了显示png图片方便，封装一个image类
*********************************************************************/
 
// 构造函数
CBnvImage::CBnvImage()
{
	// 初始化变量
	m_blFlag = TRUE;
	m_pImagingFactory = NULL;
	m_pImage = NULL;
	m_hDrawDC = NULL;
	m_hBitmap = NULL;
	m_hOldBitmap = NULL;

	// COM初始化
	HRESULT hr = NULL;
	if (FAILED(hr = CoInitializeEx(NULL, COINIT_MULTITHREADED)))
	{  
		m_blFlag = FALSE;
	}

	// 创建COM实例
	if(FAILED(hr = CoCreateInstance(CLSID_ImagingFactory,NULL,CLSCTX_INPROC_SERVER,IID_IImagingFactory,(void**) &m_pImagingFactory)))
	{
		m_blFlag = FALSE;
	}

}

// 析构函数
CBnvImage::~CBnvImage()
{
	DelImgDC();		
	if(m_pImage != NULL)
	{
		m_pImage->Release();
		m_pImage = NULL;
	}

	if(m_pImagingFactory != NULL)
	{
		m_pImagingFactory->Release();
		m_pImagingFactory = NULL;
	}

	// 释放COM
	CoUninitialize();
}

/********************************************************************
	函数名：LoadFromFile
	作者：zhangwf
	日期：2009/07/23
	功能：从文件中加载图像        
	参数：fileName     待加载文件名称
	返回：类型(BOOL)   TRUE-加载成功；FALSE-加载失败；
	修改记录：
*********************************************************************/
BOOL CBnvImage::LoadFromFile(const WCHAR *fileName)
{
	// 初始化失败
	if (m_blFlag == FALSE)
	{
		return FALSE;
	}

	// 参数有效性
	if (fileName == NULL)
	{
		return FALSE;
	}

	// 释放DC
	DelImgDC();

	// 已经加载了则释放
	if (m_pImage != NULL)
	{
		m_pImage->Release();
		m_pImage = NULL;
	}

	// 从文件中创建图片
	HRESULT hr = NULL;
	if(FAILED(hr = m_pImagingFactory->CreateImageFromFile(fileName, &m_pImage)))
	{
		return FALSE;
	}

	// 得到图片信息
	if(FAILED(hr = m_pImage->GetImageInfo(&m_ImageInfo)))
	{
		return FALSE;
	}
	
	// 成功获得图片信息
	return TRUE;
}

/********************************************************************
	函数名：LoadFromResource
	作者：zhangwf
	日期：2009/07/24
	功能：从资源中加载图片数据       
	参数：lpName   资源ID
	      lpType   资源类型	      
	返回：类型(BOOL)  TRUE-加载成功;FALSE-加载失败;
	修改记录：
*********************************************************************/
BOOL CBnvImage::LoadFromResource(LPCWSTR lpName, LPCWSTR lpType)
{
	// 释放DC
	DelImgDC();

	// 已经加载则释放
	if (m_pImage != NULL)
	{
		m_pImage->Release();
		m_pImage = NULL;
	}

	// 在资源中寻找
	HRSRC     hr;
	DWORD    dwsize;
	HGLOBAL    hg;
	LPSTR    lp;
	HMODULE hModule_Current = GetModuleHandle(NULL);
	hr = FindResource(hModule_Current, lpName, lpType);
	dwsize = SizeofResource(GetModuleHandle(NULL), hr);
	hg = LoadResource(GetModuleHandle(NULL), hr);
	lp = (LPSTR)LockResource(hg);

	// 从缓冲区创建图片
	HRESULT hrt = NULL;
	if(FAILED(hrt = m_pImagingFactory->CreateImageFromBuffer(lp, dwsize, DISPOSAL_NONE, &m_pImage)))
	{
		DeleteObject(hr);
		return FALSE;
	}

	// 得到图片信息
	if(FAILED(hrt = m_pImage->GetImageInfo(&m_ImageInfo)))
	{
		DeleteObject(hr);
		return FALSE;
	}

	// 成功获得图片信息
	DeleteObject(hr);
	return TRUE;
}

/********************************************************************
	函数名：ReleaseResource
	作者：zhangwf
	日期：2009/09/09
	功能：释放已经加载到的资源,用于释放大的图片暂用的内存        
	参数：
	返回：类型(void)
	修改记录：
*********************************************************************/
void CBnvImage::ReleaseResource(void)
{
	// 释放DC
	DelImgDC();

	if(m_pImage != NULL)
	{
		m_pImage->Release();
		m_pImage = NULL;
	}
}

/********************************************************************
	函数名：Draw
	作者：zhangwf
	日期：2009/07/23
	功能：绘制指定的矩形区域图像到hdc上的指定矩形区域  
	参数：hdc       绘图环境
	      dstRect   hdc上的目标绘图矩形区域 
	      srcRect   图像上指定的要绘制出的矩形区域
	返回：类型()
	修改记录：
*********************************************************************/
void CBnvImage::Draw(HDC hdc,const RECT* dstRect)
{
	// 获取图像信息失败
	if (m_pImage == NULL)
	{
		return;
	}

	// 创建DC
	if (m_hDrawDC == NULL)
	{
		m_hDrawDC = CreatImgDC(hdc);
	}

	// 绘制图像
	// 把内存DC上指定的部分拷贝到目标DC上
	::BitBlt(hdc, 
		 	 dstRect->left, 
			 dstRect->top, 
			 dstRect->right-dstRect->left, 
			 dstRect->bottom-dstRect->top, 
			 m_hDrawDC, 
			 0,
			 0,
			 SRCCOPY);	
}

/********************************************************************
	函数名：GetWidth
	作者：zhangwf
	日期：2009/07/24
	功能：获得图像宽度        
	参数：
	返回：类型(int)   图像的宽度
	修改记录：
*********************************************************************/
int CBnvImage::GetWidth()
{
	return m_ImageInfo.Width;
}

/********************************************************************
	函数名：GetHeight
	作者：zhangwf
	日期：2009/07/24
	功能：获得图像的高度        
	参数：
	返回：类型(int)   图像的高度
	修改记录：
*********************************************************************/
int CBnvImage::GetHeight()
{
	return m_ImageInfo.Height;
}

/********************************************************************
	函数名：DrawPart
	作者：zhangwf
	日期：2009/09/16
	功能：绘制图像上一部分到指定的部分        
	参数：hdc       绘图环境
	      dstRect   hdc上的目标绘图矩形区域 
	      srcRect   图像上指定的要绘制出的矩形区域
	返回：类型()
	修改记录：
*********************************************************************/
void CBnvImage::Draw(HDC hdc, const RECT* dstRect, const RECT* srcRect)
{
	// 获取图像信息失败
	if (m_pImage == NULL)
	{
		return;
	}

	// 目标绘图区为NULL
	if (dstRect == NULL)
	{
		return;
	}

	// 创建内存DC
	if (m_hDrawDC == NULL)
	{
		m_hDrawDC = CreatImgDC(hdc);
	}

	// 获得源的左上角位置
	int srcLX = 0;
	int srcLY = 0;
	if (srcRect != NULL)
	{
		srcLX = srcRect->left;
		srcLY = srcRect->top;
	}

	// 把内存DC上指定的部分拷贝到目标DC上
	::BitBlt(hdc, 
		     dstRect->left, 
			 dstRect->top, 
			 dstRect->right-dstRect->left, 
			 dstRect->bottom-dstRect->top, 
			 m_hDrawDC, 
			 srcLX,
			 srcLY,
			 SRCCOPY);		
}


HDC CBnvImage::CreatImgDC(HDC hdc)
{
	if (m_hDrawDC != NULL)
	{
		return m_hDrawDC;
	}

	// 创建内存DC
	m_hDrawDC = CreateCompatibleDC(hdc);			
	m_hBitmap = CreateCompatibleBitmap(hdc, m_ImageInfo.Width, m_ImageInfo.Height);
	m_hOldBitmap = (HBITMAP)SelectObject(m_hDrawDC, m_hBitmap);

	// 绘制图像到内存DC上
	RECT rcDc = {0, 0, m_ImageInfo.Width, m_ImageInfo.Height};
	m_pImage->Draw(m_hDrawDC, &rcDc, NULL);
	return m_hDrawDC;
}

HBITMAP CBnvImage::CreatHBitmap()
{ 
	CWindowDC dc(0);  
	CDC dcBitmap;  
	dcBitmap.CreateCompatibleDC(&dc);   
	HBITMAP hResult = CreateCompatibleBitmap(dc.GetSafeHdc(),m_ImageInfo.Width,m_ImageInfo.Height);  
	if(hResult){  
		HGDIOBJ   hOldBitmap = dcBitmap.SelectObject(hResult);  
		m_pImage->Draw(dcBitmap.GetSafeHdc(),CRect(0,0,m_ImageInfo.Width,m_ImageInfo.Height),NULL);  
		dcBitmap.SelectObject(hOldBitmap);  
	}
	else return NULL;
	return hResult;
}

void CBnvImage::DelImgDC()
{
	if (m_hDrawDC != NULL)
	{
		SelectObject(m_hDrawDC, m_hOldBitmap);
		DeleteObject(m_hBitmap);		
		DeleteDC(m_hDrawDC);
		m_hDrawDC = NULL;
		m_hBitmap = NULL;
		m_hOldBitmap = NULL;
	}
}
