// ImageButton.cpp : 实现文件
//

#include "stdafx.h"
#include "ImageButton.h"
#include "resource.h"
// CImageButton

IMPLEMENT_DYNAMIC(CImageButton, CButton)

CImageButton::CImageButton()
{
	m_textColor = RGB(255, 255, 255);//GetSysColor(COLOR_BTNTEXT);	
	m_pTextFont = NULL;
	m_isBitmapMaskLoaded = FALSE;
	m_isCreateRgnFromBitmap = FALSE;
	m_alignStyle = AS_OVERLAPPED;
	m_imageDrawStyle = IDS_BITBLT;
	m_menuParentWnd = NULL;
	m_isMenuDisplayed = FALSE;
	m_hMenu = NULL;

	VERIFY(m_TextFont.CreateFont(18,                        // nHeight  
		0,                         // nWidth 
		0,                         // nEscapement
		0,                         // nOrientation 
		FW_NORMAL,                 // nWeight  
		FALSE,                     // bItalic  
		FALSE,                     // bUnderline  
		0,                         // cStrikeOut  
		ANSI_CHARSET,              // nCharSet  
		OUT_DEFAULT_PRECIS,        // nOutPrecision  
		CLIP_DEFAULT_PRECIS,       // nClipPrecision 
		DEFAULT_QUALITY,           // nQuality   
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily 
		_T("Arial")));                 // lpszFacename
	  
}

CImageButton::~CImageButton()
{
	m_bitmapNorm.DeleteObject();
	m_bitmapSel.DeleteObject();
	m_bitmapFocus.DeleteObject();
	m_bitmapDisabled.DeleteObject();
	m_bitmapMask.DeleteObject();

	  
	if (m_hMenu)	::DestroyMenu(m_hMenu);
}

BEGIN_MESSAGE_MAP(CImageButton, CButton)
	ON_CONTROL_REFLECT_EX(BN_CLICKED, OnClicked)
END_MESSAGE_MAP()

// CImageButton 消息处理程序
void CImageButton::PreSubclassWindow()
{
	CButton::PreSubclassWindow();

	// add owner draw styles
	ModifyStyle(0, BS_OWNERDRAW);

	//m_ownerDrawMenu.LoadMenu(IDR_MENU1);
	//m_ownerDrawMenu.MakeItemsOwnDraw(TRUE);
}


//#define DRAWTEXT

void CImageButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	ASSERT(lpDrawItemStruct != NULL);
	// must have at least the first bitmap loaded before calling DrawItem
	ASSERT(m_bitmapNorm.m_hObject != NULL);     // required

	//Get button state
	BOOL isFocus = false;//lpDrawItemStruct->itemState & ODS_FOCUS;
	BOOL isPush = lpDrawItemStruct->itemState & ODS_SELECTED;
	/*if (m_hMenu && m_isMenuDisplayed)
	{
		isPush = TRUE;
	}*/
	BOOL isDisable = lpDrawItemStruct->itemState & ODS_DISABLED;

	//Get button rect
	CRect btnRect(lpDrawItemStruct->rcItem);
	CRect frameControlRect(btnRect);
	int drawOffSet = 0;

	// get GDI resource: font,CDC,bitmap...
	CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
	CBitmap* pBitmap = &m_bitmapNorm;
	if (isDisable)
	{
		if (m_bitmapDisabled.m_hObject != NULL)
		{
			pBitmap = &m_bitmapDisabled;
		}
	}
	if (isPush)
	{
		if (m_bitmapSel.m_hObject != NULL)
		{
			pBitmap = &m_bitmapSel;
		}

		if (!m_isCreateRgnFromBitmap)
		{
			drawOffSet = 1;
		}		
	}
	else if (isFocus)
	{
		if (m_bitmapFocus.m_hObject != NULL)
		{
			pBitmap = &m_bitmapFocus;
		}
		frameControlRect.DeflateRect(1,1);
	}

	// if don't use bitmap as rgn and disable, draw button face and frame rect
	if (!m_isCreateRgnFromBitmap && !isDisable)
	{
		// fill button face with default system button face color
		pDC->FillRect( btnRect , &CBrush( GetSysColor( COLOR_BTNFACE ) ) );

		if (!isPush)
		{
			pDC->DrawFrameControl(frameControlRect,DFC_BUTTON,DFCS_BUTTONPUSH);
		}

		pDC->FrameRect(btnRect,CBrush::FromHandle((HBRUSH)GetStockObject(BLACK_BRUSH)));
	}	
	
	// when button is disabled, if have not disable image,just fill image rect like text.
	// otherwise, use disabled image to fill this rect
	if (isDisable && m_bitmapDisabled.m_hObject == NULL)
	{
		//pDC->DrawState(CPoint(m_imageRect.left,m_imageRect.top),CSize(m_bitmap.bmWidth,m_bitmap.bmHeight),pBitmap,DST_BITMAP|DSS_DISABLED));		
		CRect imageRect(m_imageRect);
		imageRect.OffsetRect(1,1);
		pDC->FillRect(imageRect,&CBrush(GetSysColor(COLOR_WINDOW)));
		imageRect.OffsetRect(-1,-1);
		pDC->FillRect(imageRect,&CBrush(GetSysColor(COLOR_GRAYTEXT)));
	}
	else
	{
		CDC memDC;
		memDC.CreateCompatibleDC(pDC);
		CBitmap* pOld = memDC.SelectObject(pBitmap);
		if (pOld == NULL)
			return;

		CRect imageRect(m_imageRect);
		imageRect.OffsetRect(drawOffSet,0);
		pDC->BitBlt(imageRect.left, imageRect.top, imageRect.Width(), imageRect.Height(),&memDC, 0, 0, SRCCOPY);
		memDC.SelectObject(pOld);
		memDC.DeleteDC();
	}	

	if(m_bDrawText)
	{
		CString text;
		GetWindowText(text);
		if (!text.IsEmpty())
		{			
			if (isDisable)
			{
				CRect textRect(m_textRect);
				textRect.OffsetRect(1,1);
				pDC->SetTextColor(GetSysColor(COLOR_WINDOW));
				int oldMode = pDC->SetBkMode(TRANSPARENT);
				CFont* pOldFont = pDC->SelectObject(GetTextFont());
				pDC->DrawText(text,textRect,DT_SINGLELINE | DT_CENTER|DT_VCENTER);

				textRect.OffsetRect(-1,-1);
				pDC->SetTextColor(GetSysColor(COLOR_GRAYTEXT));
				pDC->DrawText(text,textRect, DT_SINGLELINE | DT_CENTER|DT_VCENTER);
				if (pOldFont)
				{
					pDC->SelectObject(pOldFont);
				}
				pDC->SetBkMode(oldMode);
			}
			else
			{
				CRect textRect(m_textRect);
				textRect.OffsetRect(drawOffSet,0);
				pDC->SetTextColor(m_textColor);
				int oldMode = pDC->SetBkMode(TRANSPARENT);
				CFont* pOldFont = pDC->SelectObject(GetTextFont());
				pDC->DrawText(text,textRect,DT_SINGLELINE | DT_CENTER|DT_VCENTER);
				if (pOldFont)
				{
					pDC->SelectObject(pOldFont);
				}
				pDC->SetBkMode(oldMode);
			}		
		}
	}

	if (!isDisable && isFocus && !m_isCreateRgnFromBitmap)
	{
		CRect focusRect(btnRect);
		focusRect.DeflateRect(2,2);
		focusRect.OffsetRect(drawOffSet,0);
		pDC->DrawFocusRect(focusRect);
	}
}

BOOL CImageButton::OnClicked()
{
	//HMENU hMenu = m_ownerDrawMenu.m_hMenu;
	//if (hMenu == NULL)
	//{
	//	hMenu = m_hMenu;
	//}
	//if (hMenu)
	//{
	//	CRect btnRect;
	//	GetWindowRect(&btnRect);

	//	m_isMenuDisplayed = TRUE;
	//	Invalidate();

	//	if (m_ownerDrawMenu.m_hMenu)
	//	{
	//		COwnerDrawMenu* pSubMenu = (COwnerDrawMenu*)m_ownerDrawMenu.GetSubMenu(0);
	//		pSubMenu->TrackPopupMenuEx(TPM_LEFTALIGN,btnRect.left,btnRect.bottom,this,NULL);
	//	}
	//	else
	//	{
	//		HMENU hSubMenu = NULL;
	//		hSubMenu = GetSubMenu(m_hMenu,0);
	//		TrackPopupMenuEx(hSubMenu,TPM_LEFTALIGN,btnRect.left,btnRect.bottom,m_menuParentWnd,NULL);
	//	}

	//	m_isMenuDisplayed = FALSE;
	//	Invalidate();
	//}

	return FALSE;
}


// 把HBITMAP绘制到DC左上角
BOOL DrawHBitmapToDC(HBITMAP hBitmap,HDC hDC)
{   
	// 参数有效性   
	if (hBitmap == NULL || hDC == NULL)    
	{      
		return FALSE;  
	}    
	// 取得位图数据信息，宽度高度等   
	BITMAP bmpObj = {0};   
	if (::GetObject(hBitmap, sizeof(bmpObj), &bmpObj) == 0 || bmpObj.bmWidth <= 0 || bmpObj.bmHeight <= 0)  
	{       
		return FALSE; 
	}    
	// 创建内存DC    
	HDC hMemDC = ::CreateCompatibleDC(hDC);			
	if (hMemDC == NULL)  
	{     
		return FALSE; 
	}     
	// 把HBITMAP选入内存DC   
	HBITMAP hOldBitmap = (HBITMAP)::SelectObject(hMemDC, hBitmap);    
	// 把内存DC拷贝绘制到目标DC上    
	::BitBlt(hDC, 0, 0, bmpObj.bmWidth, bmpObj.bmHeight, hMemDC, 0, 0, SRCCOPY);  
	// 释放内存DC    
	::SelectObject(hMemDC, hOldBitmap);   
	::DeleteDC(hMemDC);          
	// 绘制成功   
	return TRUE;
}

// 由HBITMAP获取位图数据
BOOL GetHBitmapBits(HBITMAP hBitmap, CBitmapBits &bitmapBits)
{    
	// 初始化输出参数   
	bitmapBits.Destroy(); 
	// 参数有效性   
	if (hBitmap == NULL)    
	{        
		return FALSE; 
	}     
	// 取得位图数据信息，宽度高度等    
	BITMAP bmpObj = {0};    
	if (::GetObject(hBitmap, sizeof(bmpObj), &bmpObj) == 0 || bmpObj.bmWidth <= 0 || bmpObj.bmHeight <= 0) 
	{       
		return FALSE;
	}    
	// 创建DIB内存DC   
	HDC hDIBDC = ::CreateCompatibleDC(NULL);      
	if (hDIBDC == NULL)  
	{       
		return FALSE; 
	}    
	// 创建DIB兼容位图    
	BITMAPINFO hdr;       
	ZeroMemory(&hdr , sizeof(BITMAPINFO));      
	hdr.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);  
	hdr.bmiHeader.biWidth = bmpObj.bmWidth;     
	hdr.bmiHeader.biHeight = -bmpObj.bmHeight; // 这里的目的是直接按正常行顺序使用数据
	hdr.bmiHeader.biPlanes = 1;     
	hdr.bmiHeader.biBitCount = 32;   
	BYTE * pbtPixels = NULL;      
	HBITMAP hDIBitmap = ::CreateDIBSection(hDIBDC, (BITMAPINFO *)&hdr, DIB_RGB_COLORS, (void **)&pbtPixels, NULL, 0);   
	if (hDIBitmap == NULL)   
	{      
		::DeleteDC(hDIBDC);  
		return FALSE;   
	}    
	// 把DIB位图选入DIB内存DC   
	HBITMAP hOldDIBBmp = (HBITMAP)::SelectObject(hDIBDC, hDIBitmap);    
	// 把HBITMAP绘制到DIB内存DC上   
	if (DrawHBitmapToDC(hBitmap, hDIBDC) == FALSE)  
	{       
		::SelectObject(hDIBDC, hOldDIBBmp);   
		::DeleteDC(hDIBDC);     
		::DeleteObject(hDIBitmap);     
		return FALSE;    
	}    
	// 从pbtPixels中取得位图数据存放到bitmapBits中    
	// 申请存放数据内存    
	bitmapBits.m_pBitsBuf = new BYTE[bmpObj.bmWidth*bmpObj.bmHeight*4];   
	if (bitmapBits.m_pBitsBuf == NULL)  
	{       
		::SelectObject(hDIBDC, hOldDIBBmp);       
		::DeleteDC(hDIBDC);        
		::DeleteObject(hDIBitmap);    
		return FALSE;   
	}    
	// 记录图片宽度高度    
	bitmapBits.m_dwWidth = bmpObj.bmWidth;   
	bitmapBits.m_dwHeight = bmpObj.bmHeight;   
	// 行优先遍历取得每点RGB数据   
	long lSrcRowStartPos = 0;  
	long lSrcPos = 0;  
	long lDstRowStartPos = 0; 
	long lDstPos = 0;  
	for (long lRowIndex=0; lRowIndex<bmpObj.bmHeight; lRowIndex++)  
	{       
		// 计算行首位置 
		lSrcRowStartPos = lRowIndex * bmpObj.bmWidth * 4;    
		lDstRowStartPos = lRowIndex * bmpObj.bmWidth * 4;      
		// 遍历每一列       
		for (long lColumnIndex=0; lColumnIndex<bmpObj.bmWidth; lColumnIndex++) 
		{           
			// 计算当前像素点的起始位置，以及目标存放位置     
			lSrcPos = lSrcRowStartPos + lColumnIndex*4;      
			lDstPos = lDstRowStartPos + lColumnIndex*4;   
			// 源中应该是BGRA的4字节顺序，这里转存为RGB数据  
			BYTE R = pbtPixels[lSrcPos+0];
			BYTE G = pbtPixels[lSrcPos+1];
			BYTE B = pbtPixels[lSrcPos+2];
			BYTE c = (R+G+B)/3;
			bitmapBits.m_pBitsBuf[lDstPos] = c;  
			bitmapBits.m_pBitsBuf[lDstPos+1] = c;  
			bitmapBits.m_pBitsBuf[lDstPos+2] = c;     

//			bitmapBits.m_pBitsBuf[lDstPos] = pbtPixels[lSrcPos+0];  
//			bitmapBits.m_pBitsBuf[lDstPos+1] = pbtPixels[lSrcPos+1];  
//			bitmapBits.m_pBitsBuf[lDstPos+2] = pbtPixels[lSrcPos+2];     
			bitmapBits.m_pBitsBuf[lDstPos+3] = pbtPixels[lSrcPos+3];     
		}   
	}    
	// 释放DIB内存DC及位图  
	::SelectObject(hDIBDC, hOldDIBBmp);    
	::DeleteDC(hDIBDC);  
	::DeleteObject(hDIBitmap);  
	// 取得数据成功    
	return TRUE;
}


BOOL CImageButton::LoadBitmaps(UINT nIDBitmapResource, UINT nIDBitmapResourceSel,UINT nIDBitmapResourceFocus, UINT nIDBitmapResourceDisabled, UINT nIDBitmapResourceMask,bool bDrawText)
{
	m_bDrawText = bDrawText;
	return LoadBitmaps(MAKEINTRESOURCE(nIDBitmapResource),
		MAKEINTRESOURCE(nIDBitmapResourceSel),
		MAKEINTRESOURCE(nIDBitmapResourceFocus),
		MAKEINTRESOURCE(nIDBitmapResourceDisabled),
		MAKEINTRESOURCE(nIDBitmapResourceMask));
}

BOOL CImageButton::Convert24To4Bmp(CBitmap* bmp24)//24->4灰度图
{	
	DWORD dwByteWritten = 0;

	BITMAP pBitMap;
	bmp24->GetBitmap(&pBitMap);

	// 只处理24位未压缩的图像
	if (pBitMap.bmBitsPixel != 24)
	{
		return FALSE;
	}

	// 计算图像数据大小
	DWORD dwOldSize = pBitMap.bmWidthBytes*pBitMap.bmHeight;
	UCHAR  color = 0;
	DWORD dwIndex = 0;
	char* p = (char*)(pBitMap.bmBits);
	BYTE R,G,B;

	while( dwIndex < dwOldSize )//
	{
		R = p[dwIndex]; 
		G = p[dwIndex+1]; 
		B = p[dwIndex+2]; 
		color = (R+G+B)/3;
		p[dwIndex] = color;
		p[dwIndex+1] = color;
		p[dwIndex+2] = color;
	}
	return TRUE;	
}

BOOL CImageButton::CopyCBitmapFromSrc(CBitmap* pBitmapDest, CBitmap* pBitmapSrc)
{	
	BOOL bFlag = FALSE; 
	CDC dcMemSrc;	
	CDC dcMemDest;	
	BITMAP bmpSrc;
	dcMemSrc.CreateCompatibleDC(NULL);	
	dcMemSrc.SelectObject(pBitmapSrc);
	pBitmapSrc->GetBitmap(&bmpSrc); 	
	dcMemDest.CreateCompatibleDC(NULL);
	pBitmapDest->CreateCompatibleBitmap(&dcMemSrc, bmpSrc.bmWidth, bmpSrc.bmHeight);
	dcMemDest.SelectObject(pBitmapDest); 
	bFlag = dcMemDest.BitBlt(0, 0, bmpSrc.bmWidthBytes, bmpSrc.bmHeight, &dcMemSrc, 0, 0, SRCCOPY); 
	dcMemSrc.DeleteDC();	
	dcMemDest.DeleteDC();
	return bFlag;
}
  

// LoadBitmaps will load in one, two, three or all four bitmaps
// returns TRUE if all specified images are loaded
BOOL CImageButton::LoadBitmaps(LPCTSTR lpszBitmapResource,
								LPCTSTR lpszBitmapResourceSel, LPCTSTR lpszBitmapResourceFocus,
								LPCTSTR lpszBitmapResourceDisabled,LPCTSTR lpszBitmapResourceMask)
{
	// delete old bitmaps (if present)
	m_bitmapNorm.DeleteObject();
	m_bitmapSel.DeleteObject();
	m_bitmapFocus.DeleteObject();
	m_bitmapDisabled.DeleteObject();
	m_bitmapMask.DeleteObject();

	if (!m_bitmapNorm.LoadBitmap(lpszBitmapResource))
	{
		return FALSE;   // need this one image
	}
	ASSERT(m_bitmapNorm.m_hObject != NULL);
	VERIFY(m_bitmapNorm.GetObject(sizeof(m_bitmap), &m_bitmap) == sizeof(m_bitmap));

	BOOL bAllLoaded = TRUE;
	if (lpszBitmapResourceSel != NULL)
	{
		if (!m_bitmapSel.LoadBitmap(lpszBitmapResourceSel))
		{			
			bAllLoaded = FALSE;
		}
	}
	if (lpszBitmapResourceFocus != NULL)
	{
		if (!m_bitmapFocus.LoadBitmap(lpszBitmapResourceFocus))
			bAllLoaded = FALSE;
	}
	if (lpszBitmapResourceDisabled != NULL)
	{
		if (!m_bitmapDisabled.LoadBitmap(lpszBitmapResourceDisabled))
			bAllLoaded = FALSE;
	}
	else
	{	
		CBitmapBits bitmapBits;   
		GetHBitmapBits((HBITMAP)m_bitmapNorm.GetSafeHandle(),bitmapBits);
	 	HBITMAP hBitmap = ::CreateBitmap(bitmapBits.m_dwWidth,bitmapBits.m_dwHeight,1,32,bitmapBits.m_pBitsBuf);
        m_bitmapDisabled.Attach(hBitmap);
	}

	if (lpszBitmapResourceMask != NULL)
	{
		if (m_bitmapMask.LoadBitmap(lpszBitmapResourceMask))
		{
			m_isBitmapMaskLoaded = TRUE;
			m_isCreateRgnFromBitmap = TRUE;
			m_hClipRgn = CreateRgnFromBitmap(m_bitmapMask,RGB(255,255,255));
			if (m_hClipRgn)
			{
				SetWindowRgn(m_hClipRgn,TRUE);
				CDC* pDC = GetDC();
				if (pDC)
				{
					SelectClipRgn(pDC->GetSafeHdc(),m_hClipRgn);
					ReleaseDC(pDC);
				}
			}
		}
	}
	return bAllLoaded;
}

void CImageButton::SizeToContent()
{	
	// use DrawText with parameter DT_CALCRECT to calculate text's width and height
	if (m_bitmapNorm.m_hObject == NULL)
	{
		GetClientRect(m_textRect);
		return;
	}

	CString text;
	CRect textRect;
	
	GetWindowText(text);
	textRect.SetRectEmpty();
	if (!text.IsEmpty())
	{
		CDC* pDC = GetDC();
		if (pDC)
		{
			CFont* pOldFont = pDC->SelectObject(GetTextFont());	
			pDC->DrawText(text,&textRect,DT_CALCRECT|DT_WORDBREAK);
			pDC->SelectObject(pOldFont);
			ReleaseDC(pDC);
		}		
	}	

	if (m_isCreateRgnFromBitmap)
	{
		VERIFY(SetWindowPos(NULL, -1, -1, m_bitmap.bmWidth, m_bitmap.bmHeight,
			SWP_NOMOVE|SWP_NOZORDER|SWP_NOREDRAW|SWP_NOACTIVATE));

		m_imageRect.SetRect(0,0,m_bitmap.bmWidth,m_bitmap.bmHeight);
		m_textRect = m_imageRect;
	}
	else
	{
		int newWidth;
		int newHeight;
		CRect btnRect;
		switch (m_alignStyle)
		{
		case AS_IMAGE_LEFT_TEXT_RIGHT:
			newWidth = m_bitmap.bmWidth + textRect.Width() + 4;
			newHeight = max(m_bitmap.bmHeight, textRect.Height())+4;
			VERIFY(SetWindowPos(NULL, -1, -1, newWidth, newHeight,
				SWP_NOMOVE|SWP_NOZORDER|SWP_NOREDRAW|SWP_NOACTIVATE));

			//Calculate image rect and text rect			
			GetClientRect(btnRect);
			m_imageRect.SetRect(2,2,m_bitmap.bmWidth,m_bitmap.bmHeight);
			if (!text.IsEmpty())
			{
				m_textRect = btnRect;
				m_textRect.left = m_imageRect.right + 1;
				m_textRect.right -= 2; 
			}
			break;
		case AS_IMAGE_TOP_TEXT_BOTTOM:
			break;
		case AS_OVERLAPPED:
			newWidth = max(m_bitmap.bmWidth,textRect.Width()) + 4;
			newHeight = max(m_bitmap.bmHeight,textRect.Height()) + 4;
			VERIFY(SetWindowPos(NULL, -1, -1, newWidth, newHeight,
				SWP_NOMOVE|SWP_NOZORDER|SWP_NOREDRAW|SWP_NOACTIVATE));

			//Calculate image rect and text rect
			GetClientRect(btnRect);
			m_imageRect.SetRect(0,0,m_bitmap.bmWidth,m_bitmap.bmHeight);
			CenterRectAtPoint(m_imageRect,btnRect.Width()/2,btnRect.Height()/2);
			if (!text.IsEmpty())
			{
				m_textRect = btnRect;				
			}
			break;
		}		
	}		
}

void CImageButton::SetTextColor(COLORREF textColor)
{
	m_textColor = textColor;
}

CFont* CImageButton::GetTextFont()
{
	return &m_TextFont;

	if (!m_pTextFont)
	{
		m_pTextFont = CFont::FromHandle( ( HFONT )GetStockObject( DEFAULT_GUI_FONT ) );
	}
	return m_pTextFont;
}

HRGN CImageButton::CreateRgnFromBitmap(HBITMAP hBmp, COLORREF color)
{
	if (!hBmp) return NULL;

	BITMAP bm;
	GetObject( hBmp, sizeof(BITMAP), &bm );	// get bitmap attributes

	CDC dcBmp;
	CDC *pDC = GetDC();
	if (!pDC) return NULL;
	dcBmp.CreateCompatibleDC(pDC);	//Creates a memory device context for the bitmap
	ReleaseDC(pDC);
	HBITMAP hOldBitmap = (HBITMAP)dcBmp.SelectObject(hBmp);	//selects the bitmap in the device context

	const DWORD RDHDR = sizeof(RGNDATAHEADER);
	const DWORD MAXBUF = 40;		// size of one block in RECTs
	// (i.e. MAXBUF*sizeof(RECT) in bytes)
	LPRECT	pRects;								
	DWORD	cBlocks = 0;			// number of allocated blocks

	INT		i, j;					// current position in mask image
	INT		first = 0;				// left position of current scan line
	// where mask was found
	bool	wasfirst = false;		// set when if mask was found in current scan line
	bool	ismask;					// set when current color is mask color

	// allocate memory for region data
	RGNDATAHEADER* pRgnData = (RGNDATAHEADER*)new BYTE[ RDHDR + ++cBlocks * MAXBUF * sizeof(RECT) ];
	memset( pRgnData, 0, RDHDR + cBlocks * MAXBUF * sizeof(RECT) );
	// fill it by default
	pRgnData->dwSize	= RDHDR;
	pRgnData->iType		= RDH_RECTANGLES;
	pRgnData->nCount	= 0;
	for ( i = 0; i < bm.bmHeight; i++ )
		for ( j = 0; j < bm.bmWidth; j++ ){
			// get color
			ismask=(dcBmp.GetPixel(j,bm.bmHeight-i-1)!=color);
			// place part of scan line as RECT region if transparent color found after mask color or
			// mask color found at the end of mask image
			if (wasfirst && ((ismask && (j==(bm.bmWidth-1)))||(ismask ^ (j<bm.bmWidth)))){
				// get offset to RECT array if RGNDATA buffer
				pRects = (LPRECT)((LPBYTE)pRgnData + RDHDR);
				// save current RECT
				pRects[ pRgnData->nCount++ ] = CRect( first, bm.bmHeight - i - 1, j+(j==(bm.bmWidth-1)), bm.bmHeight - i );
				// if buffer full reallocate it
				if ( pRgnData->nCount >= cBlocks * MAXBUF ){
					LPBYTE pRgnDataNew = new BYTE[ RDHDR + ++cBlocks * MAXBUF * sizeof(RECT) ];
					memcpy( pRgnDataNew, pRgnData, RDHDR + (cBlocks - 1) * MAXBUF * sizeof(RECT) );
					delete pRgnData;
					pRgnData = (RGNDATAHEADER*)pRgnDataNew;
				}
				wasfirst = false;
			} else if ( !wasfirst && ismask ){		// set wasfirst when mask is found
				first = j;
				wasfirst = true;
			}
		}
		dcBmp.SelectObject( hOldBitmap );
		dcBmp.DeleteDC();	//release the bitmap
		// create region
		/*  Under WinNT the ExtCreateRegion returns NULL (by Fable@aramszu.net) */
		//	HRGN hRgn = ExtCreateRegion( NULL, RDHDR + pRgnData->nCount * sizeof(RECT), (LPRGNDATA)pRgnData );
		/* ExtCreateRegion replacement { */
		HRGN hRgn=CreateRectRgn(0, 0, 0, 0);
		ASSERT( hRgn!=NULL );
		pRects = (LPRECT)((LPBYTE)pRgnData + RDHDR);
		for(i=0;i<(int)pRgnData->nCount;i++)
		{
			HRGN hr=CreateRectRgn(pRects[i].left, pRects[i].top, pRects[i].right, pRects[i].bottom);
			VERIFY(CombineRgn(hRgn, hRgn, hr, RGN_OR)!=ERROR);
			if (hr) DeleteObject(hr);
		}
		ASSERT( hRgn!=NULL );
		/* } ExtCreateRegion replacement */

		delete pRgnData;
		return hRgn;
}

void CImageButton::SetAlignStyle(AlignStyle alignStyle)
{
	m_alignStyle = alignStyle;
}

void CImageButton::SetImageDrawStyle(ImageDrawStyle imageDawStyle)
{
	m_imageDrawStyle = imageDawStyle;
}

void CImageButton::CenterRectAtPoint(CRect& rect,int x,int y)
{
	int offsetX = x - rect.Width()/2;
	int offsetY = y - rect.Height()/2;
	rect.OffsetRect(offsetX,offsetY);
}

DWORD CImageButton::SetMenu(UINT menuId,HWND hParent,BOOL bRepaint)
{
	if (m_hMenu)
	{
		DestroyMenu(m_hMenu);
		m_menuParentWnd = NULL;
		m_isMenuDisplayed = FALSE;
		m_hMenu = NULL;
	}

	if (menuId)
	{
		HINSTANCE hInstance = AfxFindResourceHandle(MAKEINTRESOURCE(menuId),RT_MENU);
		m_hMenu = LoadMenu(hInstance,MAKEINTRESOURCE(menuId));
		m_menuParentWnd = hParent;
		if (m_hMenu == NULL) 
			return BTNST_INVALIDRESOURCE;
	}

	if (bRepaint)
	{
		Invalidate();
	}

	return BTNST_OK;
}

DWORD CImageButton::SetMenu(UINT nMenu, HWND hParentWnd, UINT nToolbarID,BOOL bWinXPStyle,CSize sizeToolbarIcon, COLORREF crToolbarBk, BOOL bRepaint)
{
	/*
	if (m_menuPopup.m_hMenu)
	{
		m_menuPopup.DestroyMenu();
		m_menuParentWnd = NULL;
		m_isMenuDisplayed = FALSE;
		
	}

	if (nMenu)
	{
		BOOL bRetValue;
		m_menuPopup.SetMenuDrawMode(FALSE);
		// Load menu
		bRetValue = m_menuPopup.LoadMenu(nMenu);
		// If something wrong
		if (bRetValue == FALSE) return BTNST_INVALIDRESOURCE;

		// Load toolbar
		if (nToolbarID)
		{
			m_menuPopup.SetBitmapBackground(crToolbarBk);
			m_menuPopup.SetIconSize(sizeToolbarIcon.cx, sizeToolbarIcon.cy);

			bRetValue = m_menuPopup.LoadToolbar(nToolbarID);
			// If something wrong
			if (bRetValue == FALSE) 
			{
				m_menuPopup.DestroyMenu();
				return BTNST_INVALIDRESOURCE;
			} // if
		} // if

		m_menuParentWnd = hParentWnd;
	}

	if (bRepaint)
	{
		Invalidate();
	}
	*/

	return BTNST_OK;
}