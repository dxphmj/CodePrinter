#pragma once


// CPictureStatic

class CPictureStatic : public CStatic
{
	DECLARE_DYNAMIC(CPictureStatic)

public:
	CPictureStatic();
	virtual ~CPictureStatic();

public:
	CString m_strOperation;
	CString m_strMachineStatus;
	bool    m_bShowLogo;

public:
	void SetOperationString(CString OperationString){m_strOperation = OperationString; m_bShowLogo = false;Invalidate();}
	void SetMachineStatus(CString MachineStatusString){m_strMachineStatus = MachineStatusString;m_bShowLogo = false; Invalidate();}
	void ShowLogo(bool bShow){m_bShowLogo = bShow;Invalidate();}

protected:
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnPaint();
};


