#include "afxwin.h"
#include "ImageButton.h"
#include <vector>
#include <fstream>
#include <string>
#include <stdio.h>
//#include <Shlwapi.h>
//#pragma comment (lib,"Shlwapi.lib")
#include "shellapi.h"
#pragma comment (lib,"Ceshell.lib")
using namespace std;
#if !defined(AFX_PATHDIALOG_H__B16DE00C_2A9D_4E5B_B18B_C683218622DE__INCLUDED_)
#define AFX_PATHDIALOG_H__B16DE00C_2A9D_4E5B_B18B_C683218622DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PathDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPathDialog dialog
class CPathDialog : public CDialog
{
private:
	int myType;//0为文件管理，1为lab保存，2为lab读取//0为默认。
	bool booDisplay;
	CString myPath;
	COLORREF m_BKcolor;
	CBrush m_DlgBrush;
	bool booAllSet;
	bool booIsCut;
	vector<CString> pasteVec;
public:
	enum{
		STB_HIDE = 0,
		STB_SHOW = 1
	};
// Construction
public:
	CPathDialog(CWnd* pParent = NULL);   // standard constructor
    CPathDialog(int theType,bool isDisplay,CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(CPathDialog)
	enum { IDD = IDD_DIALOG_PATH };
	CTreeCtrl	m_tree;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPathDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPathDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnItemexpandingTreeDirview(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangedTreeDirview(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP();
public:
	void CheckAndAddNode(HTREEITEM hRoot);
	BOOL ShowTreeButton(HTREEITEM hti, int nShow = STB_SHOW);
	BOOL CreateSubDirectory(HTREEITEM hParent);
	CString GetFullPath(HTREEITEM hCurrent);
	BOOL HasSubDirectory(LPCTSTR szCurDir);
	BOOL CreateDriveList();
	CImageList m_ImageList;
	TCHAR m_path[MAX_PATH];
	afx_msg void OnBnClickedOk();
	CString fileName;
	/*afx_msg void OnEnChangeEditFullpath();*/
	//CEdit m_editPath;
	afx_msg void OnEnChangeEditFullpath();
	CStatic m_Select;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//afx_msg void OnNMCustomdrawTreeDirview(NMHDR *pNMHDR, LRESULT *pResult);
	CImageButton m_NewButton;
	CImageButton m_OKBUT;
	CImageButton m_CLOBUT;
	CImageButton m_DETBUT;
	afx_msg void OnBnClickedButtonDelet();
	CImageButton m_reName;
	CImageButton m_allSELECT;
	afx_msg void OnBnClickedButtonAllset();
	void DeleteDirectory(LPCTSTR path);
	afx_msg void OnBnClickedButtonRename();

	bool DeleteFileM(LPCTSTR lpszPath);
	bool ReNameFile(LPCTSTR pTo,LPCTSTR pFrom);
	bool CopyFileM(LPCTSTR pTo,LPCTSTR pFrom);
	bool MoveFileM(LPCTSTR pTo,LPCTSTR pFrom);
	afx_msg void OnBnClickedButtonNewfile();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PATHDIALOG_H__B16DE00C_2A9D_4E5B_B18B_C683218622DE__INCLUDED_)
