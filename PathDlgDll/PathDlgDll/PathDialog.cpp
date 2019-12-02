// PathDialog.cpp : implementation file
//

#include "stdafx.h"
#include "PathDlgDll.h"
#include "PathDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPathDialog dialog

CPathDialog::CPathDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CPathDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPathDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPathDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPathDialog)
	DDX_Control(pDX, IDC_TREE_DIRVIEW, m_tree);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPathDialog, CDialog)
	//{{AFX_MSG_MAP(CPathDialog)
	ON_NOTIFY(TVN_ITEMEXPANDING, IDC_TREE_DIRVIEW, OnItemexpandingTreeDirview)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_DIRVIEW, OnSelchangedTreeDirview)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CPathDialog::OnBnClickedOk)
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// CPathDialog message handlers

BOOL CPathDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_ImageList.Create(IDB_FILE, 16, 16, RGB(0, 255, 0));
	m_tree.SetImageList(&m_ImageList, LVSIL_NORMAL);

	HTREEITEM hRoot = m_tree.InsertItem(_T("我的设备"), 0, 0, TVI_ROOT, TVI_LAST);
	CreateDriveList();
	m_tree.Expand(hRoot, TVE_EXPAND);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

//添加驱动器列表
BOOL CPathDialog::CreateDriveList()
{
	HTREEITEM hRoot = m_tree.GetRootItem();

	if(hRoot == NULL)
		return FALSE;
#ifdef ON_EMUL
	HTREEITEM hItem = m_tree.InsertItem(_T("\\Storage Card\\"), 3, 3, hRoot, TVI_LAST);
	if(HasSubDirectory(GetFullPath(hItem)))
		ShowTreeButton(hItem, STB_SHOW);
	else
		ShowTreeButton(hItem, STB_HIDE);
#else
	FILE* fp = NULL;
	TCHAR szName[MAX_PATH] = _T("~~~testpartition.drive");
	TCHAR szPath[MAX_PATH];
	TCHAR szPart[20];

	for(int i = 1; i <= 10; i++)
	{
		if(i > 1)
		{
			wsprintf(szPart, _T("\\硬盘%d\\"), i);
			wsprintf(szPath, _T("\\硬盘%d\\%s"), i, szName);
		}
		else
		{
			lstrcpy(szPart, _T("\\硬盘\\"));
			wsprintf(szPath, _T("\\硬盘\\%s"), szName);
		}
		fp = _tfopen(szPath, _T("wb"));
		if(fp != NULL)
		{
			fclose(fp);
			fp = NULL;
			::DeleteFile(szPath);

			HTREEITEM hItem = m_tree.InsertItem(szPart, 
				3, 3, hRoot, TVI_LAST);
			if(HasSubDirectory(GetFullPath(hItem)))
				ShowTreeButton(hItem, STB_SHOW);
			else
				ShowTreeButton(hItem, STB_HIDE);
		}
	}
#endif
	return TRUE;
}

BOOL CPathDialog::HasSubDirectory(LPCTSTR szCurDir)
{
	HANDLE hFind = INVALID_HANDLE_VALUE;
	WIN32_FIND_DATA wfd;
	BOOL bRet;
	TCHAR szPath[MAX_PATH];

	lstrcpy(szPath, szCurDir);
	if(szPath[lstrlen(szCurDir)-1] != _T('\\'))
		lstrcat(szPath, _T("\\"));
	lstrcat(szPath, _T("*.*"));

	hFind = FindFirstFile(szPath, &wfd);
	bRet = ((hFind == INVALID_HANDLE_VALUE) ? FALSE : TRUE);
	while(bRet)
	{
		if(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			if(wfd.cFileName[0] != _T('.'))
			{
				FindClose(hFind);
				return TRUE;
			}
		}
		bRet = FindNextFile(hFind, &wfd);
	}

	FindClose(hFind);
	return FALSE;
}

CString CPathDialog::GetFullPath(HTREEITEM hCurrent)
{
	CString strTemp;
	CString strFullPath;
	HTREEITEM hRoot = m_tree.GetRootItem();

	strTemp.Empty();
	strFullPath.Empty();

	while(hCurrent != hRoot)
	{
		strTemp = m_tree.GetItemText(hCurrent);
		if(strTemp.Right(1) != _T("\\"))
			strTemp += _T("\\");

		strFullPath = strTemp + strFullPath;
		hCurrent = m_tree.GetParentItem(hCurrent);
	}

	return strFullPath;
}

BOOL CPathDialog::CreateSubDirectory(HTREEITEM hParent)
{
	HANDLE hFind = INVALID_HANDLE_VALUE;
	WIN32_FIND_DATA wfd;
	BOOL bRet = FALSE;
	BOOL bHasChild = FALSE;
	HTREEITEM hti;
	CString strFullPath = GetFullPath(hParent);
	CString str;

	if(hParent == m_tree.GetRootItem())
	{
		CreateDriveList();

		return TRUE;
	}

	if(strFullPath.Right(1) != _T("\\"))
		strFullPath += _T("\\");
	strFullPath += _T("*.*");

	hFind = FindFirstFile(strFullPath, &wfd);
	bRet = ((hFind == INVALID_HANDLE_VALUE) ? FALSE : TRUE);
	while(bRet)
	{
		if(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			if(wfd.cFileName[0] != _T('.'))
			{
				bHasChild = TRUE;
				hti = m_tree.InsertItem(wfd.cFileName, 6, 6, hParent, TVI_LAST);
				str = GetFullPath(hti);
				if(HasSubDirectory(str))
					ShowTreeButton(hti, STB_SHOW);
				else
					ShowTreeButton(hti, STB_HIDE);
			}
		}

		bRet = FindNextFile(hFind, &wfd);
	}

	return bHasChild;
}

BOOL CPathDialog::ShowTreeButton(HTREEITEM hti, int nShow)
{
	TVITEM tvi;

	tvi.mask = TVIF_CHILDREN;
	tvi.hItem = hti;
	tvi.cChildren = ((nShow == STB_SHOW) ? 1 : 0);

	return m_tree.SetItem(&tvi);
}

void CPathDialog::OnItemexpandingTreeDirview(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	HTREEITEM hti = pNMTreeView->itemNew.hItem;
//	if(hti != m_tree.GetRootItem())
	{
		HTREEITEM hChild = m_tree.GetChildItem(hti);
		while(hChild != NULL)
		{
			m_tree.DeleteItem(hChild);
			hChild = m_tree.GetChildItem(hti);
		}

		if(!CreateSubDirectory(hti))
			ShowTreeButton(hti, STB_HIDE);
		else
			ShowTreeButton(hti, STB_SHOW);
	}

	*pResult = 0;
}

void CPathDialog::OnSelchangedTreeDirview(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	HTREEITEM hti = pNMTreeView->itemNew.hItem;
	if(hti != m_tree.GetRootItem())
	{
		lstrcpy(m_path, GetFullPath(hti));
		SetDlgItemText(IDC_EDIT_FULLPATH, m_path);
	}
	else
	{
		lstrcpy(m_path, _T(""));
		SetDlgItemText(IDC_EDIT_FULLPATH, m_path);
	}
	
	*pResult = 0;
}

void CPathDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	OnOK();
}
