
/********************************************************************
	purpose:	为了显示png图片方便，封装一个image类
*********************************************************************/
#ifndef _BNV_ZWF_IMAGE_H_
#define _BNV_ZWF_IMAGE_H_
//////////////////////////////////////////////////////////////////////////
#include <Windows.h>
#include <imaging.h>
//////////////////////////////////////////////////////////////////////////
class CBnvImage
{
public:
	// 从文件中加载
	BOOL LoadFromFile(const WCHAR *fileName);

	// 从资源中加载，例如g_backImg.LoadFromResource(MAKEINTRESOURCE(IDR_BACKIMG), _T("PNG"));
	BOOL LoadFromResource(LPCWSTR lpName,LPCWSTR lpType);

	// 释放已经加载到的资源
	void ReleaseResource(void);

	// 绘制图像到指定位置,绘制整个图像,会把图像压缩或拉伸填充到指定区域
	void Draw(HDC hdc, const RECT* dstRect);

	// 绘制图像上一部分到指定的部分
	void Draw(HDC hdc, const RECT* dstRect, const RECT* srcRect);

	// 获得图像的宽度
	int GetWidth();

	// 获得图像的高度
	int GetHeight();

public:
	CBnvImage();
	~CBnvImage();

	HBITMAP CreatHBitmap();

protected:

private:
	ImageInfo          m_ImageInfo;
	IImage             *m_pImage;
	IImagingFactory    *m_pImagingFactory;
	BOOL m_blFlag;     // 标识初始化是否成功
	HDC m_hDrawDC;     // 临时保存DC
	HBITMAP m_hBitmap; // 临时保存图片
	HBITMAP m_hOldBitmap; 

private:
	HDC CreatImgDC(HDC hdc);
	void DelImgDC();

};

//////////////////////////////////////////////////////////////////////////
#endif
