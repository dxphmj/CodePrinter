#pragma once


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
};


