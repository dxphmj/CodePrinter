#pragma once

UINT MainpageDrawTheard(LPVOID pParam);
// MainPicture

class MainPicture : public CStatic
{
	DECLARE_DYNAMIC(MainPicture)

public:
	MainPicture();
	virtual ~MainPicture();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	CDC* m_pDC;
	CRect m_rectClient;
	CDC m_dcMem;
	int m_pixSize;
	CBitmap m_bitmapTemp; 
	CBrush m_cbrush;
	CBrush *m_pBrush; //æ…± À¢
	CRect m_drawRect;

	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
struct structMP
{
	MainPicture *myMainPicture;
};

