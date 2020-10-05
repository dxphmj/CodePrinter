#pragma once
#include <vector>
using namespace std;
// CDesignStatic

class CDesignStatic : public CStatic
{
	DECLARE_DYNAMIC(CDesignStatic)
	
public:
	CDesignStatic();
	virtual ~CDesignStatic();
	vector<vector<bool>> bmpvec;
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
