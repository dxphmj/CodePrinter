#pragma once
#include "EditTextDlg.h"
#include "EditFigureDlg.h"
#include "DateDlg.h"
#include "PictureDlg.h"
#include "BarCodeDlg.h"
#include "ModuleMain.h"
// CInputDlg �Ի���

class CInputDlg : public CDialog
{
	DECLARE_DYNAMIC(CInputDlg)

public:
	CInputDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInputDlg();

// �Ի�������
	enum { IDD = IDD_INPUT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedEdittextButton();
	afx_msg void OnBnClickedEditfigureButton();
	afx_msg void OnBnClickedEditdateButton();
	afx_msg void OnBnClickedEditpictureButton();
	afx_msg void OnBnClickedBarcodeButton();
	afx_msg void OnBnClickedInputCloseBtn();
	void showInputDlg(int ID);

public:
	CEditTextDlg *pEditText;
	CEditFigureDlg *pEditFigure;
	CDateDlg *pDate;
	CPictureDlg *pPic;
	CBarCodeDlg *pBarCode;
    ModuleMain inPutModule;
};
