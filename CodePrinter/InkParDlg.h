#pragma once


// CInkParDlg �Ի���

class CInkParDlg : public CDialog
{
	DECLARE_DYNAMIC(CInkParDlg)

public:
	CInkParDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInkParDlg();

// �Ի�������
	enum { IDD = IDD_INK_PAR_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_parPressure;
	int m_parPumpSpeed;
	int m_inkFlowLev;
	int m_inkAddLev;
	int m_inkEmptyLev;
	int m_printheadTemp;
	int m_viscoDevia;
	int m_solventFlowLev;
	int m_solAddLev;
	int m_solEmptyLev;
};
