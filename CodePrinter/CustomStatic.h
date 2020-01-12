#pragma once


// CCustomStatic

class CCustomStatic : public CStatic
{
	DECLARE_DYNAMIC(CCustomStatic)

public:
	CCustomStatic();
	virtual ~CCustomStatic();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


