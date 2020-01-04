#include "StdAfx.h"
#include "BnvImage.h"
#include <ObjBase.h>
#include <initguid.h>
#include <imgguids.h>

/********************************************************************

	purpose:	Ϊ����ʾpngͼƬ���㣬��װһ��image��
*********************************************************************/
 
// ���캯��
CBnvImage::CBnvImage()
{
	// ��ʼ������
	m_blFlag = TRUE;
	m_pImagingFactory = NULL;
	m_pImage = NULL;
	m_hDrawDC = NULL;
	m_hBitmap = NULL;
	m_hOldBitmap = NULL;

	// COM��ʼ��
	HRESULT hr = NULL;
	if (FAILED(hr = CoInitializeEx(NULL, COINIT_MULTITHREADED)))
	{  
		m_blFlag = FALSE;
	}

	// ����COMʵ��
	if(FAILED(hr = CoCreateInstance(CLSID_ImagingFactory,NULL,CLSCTX_INPROC_SERVER,IID_IImagingFactory,(void**) &m_pImagingFactory)))
	{
		m_blFlag = FALSE;
	}

}

// ��������
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

	// �ͷ�COM
	CoUninitialize();
}

/********************************************************************
	��������LoadFromFile
	���ߣ�zhangwf
	���ڣ�2009/07/23
	���ܣ����ļ��м���ͼ��        
	������fileName     �������ļ�����
	���أ�����(BOOL)   TRUE-���سɹ���FALSE-����ʧ�ܣ�
	�޸ļ�¼��
*********************************************************************/
BOOL CBnvImage::LoadFromFile(const WCHAR *fileName)
{
	// ��ʼ��ʧ��
	if (m_blFlag == FALSE)
	{
		return FALSE;
	}

	// ������Ч��
	if (fileName == NULL)
	{
		return FALSE;
	}

	// �ͷ�DC
	DelImgDC();

	// �Ѿ����������ͷ�
	if (m_pImage != NULL)
	{
		m_pImage->Release();
		m_pImage = NULL;
	}

	// ���ļ��д���ͼƬ
	HRESULT hr = NULL;
	if(FAILED(hr = m_pImagingFactory->CreateImageFromFile(fileName, &m_pImage)))
	{
		return FALSE;
	}

	// �õ�ͼƬ��Ϣ
	if(FAILED(hr = m_pImage->GetImageInfo(&m_ImageInfo)))
	{
		return FALSE;
	}
	
	// �ɹ����ͼƬ��Ϣ
	return TRUE;
}

/********************************************************************
	��������LoadFromResource
	���ߣ�zhangwf
	���ڣ�2009/07/24
	���ܣ�����Դ�м���ͼƬ����       
	������lpName   ��ԴID
	      lpType   ��Դ����	      
	���أ�����(BOOL)  TRUE-���سɹ�;FALSE-����ʧ��;
	�޸ļ�¼��
*********************************************************************/
BOOL CBnvImage::LoadFromResource(LPCWSTR lpName, LPCWSTR lpType)
{
	// �ͷ�DC
	DelImgDC();

	// �Ѿ��������ͷ�
	if (m_pImage != NULL)
	{
		m_pImage->Release();
		m_pImage = NULL;
	}

	// ����Դ��Ѱ��
	HRSRC     hr;
	DWORD    dwsize;
	HGLOBAL    hg;
	LPSTR    lp;
	HMODULE hModule_Current = GetModuleHandle(NULL);
	hr = FindResource(hModule_Current, lpName, lpType);
	dwsize = SizeofResource(GetModuleHandle(NULL), hr);
	hg = LoadResource(GetModuleHandle(NULL), hr);
	lp = (LPSTR)LockResource(hg);

	// �ӻ���������ͼƬ
	HRESULT hrt = NULL;
	if(FAILED(hrt = m_pImagingFactory->CreateImageFromBuffer(lp, dwsize, DISPOSAL_NONE, &m_pImage)))
	{
		DeleteObject(hr);
		return FALSE;
	}

	// �õ�ͼƬ��Ϣ
	if(FAILED(hrt = m_pImage->GetImageInfo(&m_ImageInfo)))
	{
		DeleteObject(hr);
		return FALSE;
	}

	// �ɹ����ͼƬ��Ϣ
	DeleteObject(hr);
	return TRUE;
}

/********************************************************************
	��������ReleaseResource
	���ߣ�zhangwf
	���ڣ�2009/09/09
	���ܣ��ͷ��Ѿ����ص�����Դ,�����ͷŴ��ͼƬ���õ��ڴ�        
	������
	���أ�����(void)
	�޸ļ�¼��
*********************************************************************/
void CBnvImage::ReleaseResource(void)
{
	// �ͷ�DC
	DelImgDC();

	if(m_pImage != NULL)
	{
		m_pImage->Release();
		m_pImage = NULL;
	}
}

/********************************************************************
	��������Draw
	���ߣ�zhangwf
	���ڣ�2009/07/23
	���ܣ�����ָ���ľ�������ͼ��hdc�ϵ�ָ����������  
	������hdc       ��ͼ����
	      dstRect   hdc�ϵ�Ŀ���ͼ�������� 
	      srcRect   ͼ����ָ����Ҫ���Ƴ��ľ�������
	���أ�����()
	�޸ļ�¼��
*********************************************************************/
void CBnvImage::Draw(HDC hdc,const RECT* dstRect)
{
	// ��ȡͼ����Ϣʧ��
	if (m_pImage == NULL)
	{
		return;
	}

	// ����DC
	if (m_hDrawDC == NULL)
	{
		m_hDrawDC = CreatImgDC(hdc);
	}

	// ����ͼ��
	// ���ڴ�DC��ָ���Ĳ��ֿ�����Ŀ��DC��
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
	��������GetWidth
	���ߣ�zhangwf
	���ڣ�2009/07/24
	���ܣ����ͼ����        
	������
	���أ�����(int)   ͼ��Ŀ��
	�޸ļ�¼��
*********************************************************************/
int CBnvImage::GetWidth()
{
	return m_ImageInfo.Width;
}

/********************************************************************
	��������GetHeight
	���ߣ�zhangwf
	���ڣ�2009/07/24
	���ܣ����ͼ��ĸ߶�        
	������
	���أ�����(int)   ͼ��ĸ߶�
	�޸ļ�¼��
*********************************************************************/
int CBnvImage::GetHeight()
{
	return m_ImageInfo.Height;
}

/********************************************************************
	��������DrawPart
	���ߣ�zhangwf
	���ڣ�2009/09/16
	���ܣ�����ͼ����һ���ֵ�ָ���Ĳ���        
	������hdc       ��ͼ����
	      dstRect   hdc�ϵ�Ŀ���ͼ�������� 
	      srcRect   ͼ����ָ����Ҫ���Ƴ��ľ�������
	���أ�����()
	�޸ļ�¼��
*********************************************************************/
void CBnvImage::Draw(HDC hdc, const RECT* dstRect, const RECT* srcRect)
{
	// ��ȡͼ����Ϣʧ��
	if (m_pImage == NULL)
	{
		return;
	}

	// Ŀ���ͼ��ΪNULL
	if (dstRect == NULL)
	{
		return;
	}

	// �����ڴ�DC
	if (m_hDrawDC == NULL)
	{
		m_hDrawDC = CreatImgDC(hdc);
	}

	// ���Դ�����Ͻ�λ��
	int srcLX = 0;
	int srcLY = 0;
	if (srcRect != NULL)
	{
		srcLX = srcRect->left;
		srcLY = srcRect->top;
	}

	// ���ڴ�DC��ָ���Ĳ��ֿ�����Ŀ��DC��
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

	// �����ڴ�DC
	m_hDrawDC = CreateCompatibleDC(hdc);			
	m_hBitmap = CreateCompatibleBitmap(hdc, m_ImageInfo.Width, m_ImageInfo.Height);
	m_hOldBitmap = (HBITMAP)SelectObject(m_hDrawDC, m_hBitmap);

	// ����ͼ���ڴ�DC��
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
