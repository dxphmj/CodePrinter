#pragma once

 
 
#include "CommonType.h"
// Return values
#ifndef	BTNST_OK
#define	BTNST_OK						0
#endif
#ifndef	BTNST_INVALIDRESOURCE
#define	BTNST_INVALIDRESOURCE			1
#endif
#ifndef	BTNST_FAILEDMASK
#define	BTNST_FAILEDMASK				2
#endif
#ifndef	BTNST_INVALIDINDEX
#define	BTNST_INVALIDINDEX				3
#endif
#ifndef	BTNST_INVALIDALIGN
#define	BTNST_INVALIDALIGN				4
#endif

// CImageButton

enum ImageDrawStyle
{
	IDS_BITBLT,
	IDS_STRETCHBLT
};

class CImageButton : public CButton
{
	DECLARE_DYNAMIC(CImageButton)

public:
	CImageButton();
	virtual ~CImageButton();

protected:
	DECLARE_MESSAGE_MAP()
	CBitmap m_bitmapNorm;           // normal image (REQUIRED)
	CBitmap m_bitmapSel;        // selected image (OPTIONAL)
	CBitmap m_bitmapFocus;      // focused but not selected (OPTIONAL)
	CBitmap m_bitmapDisabled;   // disabled bitmap (OPTIONAL)
	CBitmap m_bitmapMask;
	CFont* m_pTextFont;
	COLORREF m_textColor;
	CRect m_textRect;
	CRect m_imageRect;
	BOOL m_isCreateRgnFromBitmap;
	BOOL m_isBitmapMaskLoaded;
	
	HRGN	m_hClipRgn;
	BITMAP m_bitmap;
	AlignStyle m_alignStyle;
	ImageDrawStyle m_imageDrawStyle;
	HMENU m_hMenu;
	 
	HWND m_menuParentWnd;
	BOOL m_isMenuDisplayed;
	HRGN CreateRgnFromBitmap(HBITMAP hBmp, COLORREF color);
	afx_msg BOOL OnClicked();
public:
	BOOL LoadBitmaps(UINT nIDBitmapResource,
		UINT nIDBitmapResourceSel = 0, UINT nIDBitmapResourceFocus = 0,
		UINT nIDBitmapResourceDisabled = 0,UINT nIDBitmapResourceMask = 0);
	BOOL LoadBitmaps(LPCTSTR lpszBitmapResource,
		LPCTSTR lpszBitmapResourceSel = NULL,
		LPCTSTR lpszBitmapResourceFocus = NULL,
		LPCTSTR lpszBitmapResourceDisabled = NULL,
		LPCTSTR lpszBitmapResourceMask = NULL);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void PreSubclassWindow();
	void SizeToContent();
	void SetTextColor(COLORREF textColor);
	CFont* GetTextFont();
	void SetAlignStyle(AlignStyle alignStyle);
	void SetImageDrawStyle(ImageDrawStyle imageDrawStyle);
	void CenterRectAtPoint(CRect& rect,int x,int y);
	DWORD SetMenu(UINT menuId,HWND hParent,BOOL bRepaint = TRUE);
	DWORD SetMenu(UINT nMenu, HWND hParentWnd, UINT nToolbarID = NULL,BOOL bWinXPStyle = TRUE,CSize sizeToolbarIcon = CSize(16, 16), COLORREF crToolbarBk = RGB(255, 0, 255), BOOL bRepaint = TRUE);
	//BOOL SetCreateRgnFromBitmap(BOOL isCreateRgnFromBitmap);
	int m_tag;
};


