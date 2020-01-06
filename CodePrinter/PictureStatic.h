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
	bool    m_bShowGreenAlarm,m_bShowBlueAlarm,m_bShowYellowAlarm,m_bShowRedAlarm;
	bool    m_bRedAlarm,m_bGreenAlarm,m_bBlueAlarm,m_bYellowAlarm;

public:
	void SetOperationString(CString OperationString);
	void SetMachineStatus(CString MachineStatusString){m_strMachineStatus = MachineStatusString;m_bShowLogo = false; Invalidate();}
	void ShowLogo(bool bShow){m_bShowLogo = bShow;Invalidate();}
	void ResetAlarm(){m_bShowGreenAlarm = m_bShowBlueAlarm = m_bShowYellowAlarm = m_bShowRedAlarm = false;Invalidate();}
	void SetRedAlarm(bool bAlarm);
	void SetGreenAlarm(bool bAlarm);
	void SetBlueAlarm(bool bAlarm);
	void SetYellowAlarm(bool bAlarm);

protected:
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnPaint();
};


