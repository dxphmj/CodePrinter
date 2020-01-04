
/********************************************************************
	purpose:	Ϊ����ʾpngͼƬ���㣬��װһ��image��
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
	// ���ļ��м���
	BOOL LoadFromFile(const WCHAR *fileName);

	// ����Դ�м��أ�����g_backImg.LoadFromResource(MAKEINTRESOURCE(IDR_BACKIMG), _T("PNG"));
	BOOL LoadFromResource(LPCWSTR lpName,LPCWSTR lpType);

	// �ͷ��Ѿ����ص�����Դ
	void ReleaseResource(void);

	// ����ͼ��ָ��λ��,��������ͼ��,���ͼ��ѹ����������䵽ָ������
	void Draw(HDC hdc, const RECT* dstRect);

	// ����ͼ����һ���ֵ�ָ���Ĳ���
	void Draw(HDC hdc, const RECT* dstRect, const RECT* srcRect);

	// ���ͼ��Ŀ��
	int GetWidth();

	// ���ͼ��ĸ߶�
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
	BOOL m_blFlag;     // ��ʶ��ʼ���Ƿ�ɹ�
	HDC m_hDrawDC;     // ��ʱ����DC
	HBITMAP m_hBitmap; // ��ʱ����ͼƬ
	HBITMAP m_hOldBitmap; 

private:
	HDC CreatImgDC(HDC hdc);
	void DelImgDC();

};

//////////////////////////////////////////////////////////////////////////
#endif
