#pragma once


// CDesignStatic

class CDesignStatic : public CStatic
{
	DECLARE_DYNAMIC(CDesignStatic)

public:
	CDesignStatic();
	virtual ~CDesignStatic();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


