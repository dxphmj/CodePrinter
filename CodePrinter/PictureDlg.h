#pragma once


// CPictureDlg �Ի���

class CPictureDlg : public CDialog
{
	DECLARE_DYNAMIC(CPictureDlg)

public:
	CPictureDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPictureDlg();

// �Ի�������
	enum { IDD = IDD_PICTURE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedPictureCloseButton();
};
