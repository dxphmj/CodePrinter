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
public:
	enum{
		STB_HIDE = 0,
		STB_SHOW = 1
	};
// Construction
public:
	CPathDialog(CWnd* pParent = NULL);   // standard constructor

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
	DECLARE_MESSAGE_MAP()
public:
	BOOL ShowTreeButton(HTREEITEM hti, int nShow = STB_SHOW);
	BOOL CreateSubDirectory(HTREEITEM hParent);
	CString GetFullPath(HTREEITEM hCurrent);
	BOOL HasSubDirectory(LPCTSTR szCurDir);
	BOOL CreateDriveList();
	CImageList m_ImageList;
	TCHAR m_path[MAX_PATH];
	afx_msg void OnBnClickedOk();
};
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PATHDIALOG_H__B16DE00C_2A9D_4E5B_B18B_C683218622DE__INCLUDED_)
