#pragma once


// CEditFigureDlg �Ի���

class CEditFigureDlg : public CDialog
{
	DECLARE_DYNAMIC(CEditFigureDlg)

public:
	CEditFigureDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CEditFigureDlg();

// �Ի�������
	enum { IDD = IDD_EDITFIGURE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
