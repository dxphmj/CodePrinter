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
	myType = 0;
	//{{AFX_DATA_INIT(CPathDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CPathDialog::CPathDialog(int theType,bool isDisplay,CWnd* pParent /*=NULL*/)
: CDialog(CPathDialog::IDD, pParent)
{
	myType = theType;
	booDisplay=isDisplay;
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
	//DDX_Control(pDX, IDC_EDIT_FULLPATH, m_editPath);
	DDX_Control(pDX, IDC_STATIC_SELECT, m_Select);
}


BEGIN_MESSAGE_MAP(CPathDialog, CDialog)
	//{{AFX_MSG_MAP(CPathDialog)
	ON_NOTIFY(TVN_ITEMEXPANDING, IDC_TREE_DIRVIEW, OnItemexpandingTreeDirview)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_DIRVIEW, OnSelchangedTreeDirview)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CPathDialog::OnBnClickedOk)
//	ON_EN_CHANGE(IDC_EDIT_FULLPATH, &CPathDialog::OnEnChangeEditFullpath)
ON_EN_CHANGE(IDC_EDIT_FULLPATH, &CPathDialog::OnEnChangeEditFullpath)
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// CPathDialog message handlers

BOOL CPathDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	switch(myType)
	{
	case 0://文件管理
		myPath="Storage Card\\User";
		break;
	case 1://Label
		//SetWindowPos(NULL,300,200,306,338,SWP_SHOWWINDOW );
		myPath="Storage Card\\User\\Label";
		break;
	case 2://logo
		myPath="Storage Card\\User\\Logo";
		break;
	case 3://PrintConfig
		myPath="Storage Card\\User\\PrintConfig";
		break;
	}
	SetWindowPos(NULL,0,100,800,500,SWP_SHOWWINDOW );	
	CRect rect;
	//GetWindowRect(&rect);
	GetClientRect(&rect);
	//设置按钮的位置及大小
	CFont *m_Font;
	m_Font=new CFont;
	m_Font->CreatePointFont(120, _T("Arial"), NULL);
	GetDlgItem(IDC_STATIC_SELECT)->SetWindowPos(NULL,rect.left+50,rect.top+10,700,20,SWP_SHOWWINDOW);
	//GetDlgItem(IDC_STATIC_SELECT)->SetFont(&m_Font,true);
	m_Select.SetFont(m_Font,true);
	// TODO: Add extra initialization here
	m_ImageList.Create(IDB_FILE, 16, 16, RGB(0, 255, 0));
	m_tree.SetImageList(&m_ImageList, LVSIL_NORMAL);
	m_tree.SetFont(m_Font);
	HTREEITEM hRoot = m_tree.InsertItem(_T("我的设备"), 0, 0, TVI_ROOT, TVI_LAST);
	CreateDriveList();
	m_tree.Expand(hRoot, TVE_EXPAND);
	GetDlgItem(IDC_EDIT_FULLPATH)->SetWindowPos(NULL,rect.left+50,rect.top+50,700,30,SWP_SHOWWINDOW);
	GetDlgItem(IDC_EDIT_FULLPATH)->SetFont(m_Font,true);
	GetDlgItem(IDC_TREE_DIRVIEW)->SetWindowPos(NULL,rect.left+50,rect.top+100,700,290,SWP_SHOWWINDOW);
	GetDlgItem(IDOK)->SetWindowPos(NULL,rect.left+500,rect.top+410,100,40,SWP_SHOWWINDOW);
	GetDlgItem(IDOK)->EnableWindow(booDisplay);
	GetDlgItem(IDCANCEL)->SetWindowPos(NULL,rect.left+650,rect.top+410,100,40,SWP_SHOWWINDOW);
	//delete m_Font;
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
	//HTREEITEM hItem = m_tree.InsertItem(_T("Storage Card"), 3, 3, hRoot, TVI_LAST);
	HTREEITEM hItem = m_tree.InsertItem(myPath, 3, 3, hRoot, TVI_LAST);
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
		else if(wfd.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE)
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
			if (strTemp[strTemp.GetLength()-4] == _T('.'))
			{
				fileName=strTemp;
			} 
			else
			{
				strTemp += _T("\\");
			}
			

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
		else if(wfd.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE)
		{
			if(wfd.cFileName[0] != _T('.'))
			{
				bHasChild = TRUE;
				hti = m_tree.InsertItem(wfd.cFileName, 7, 7, hParent, TVI_LAST);
				str = GetFullPath(hti);
				if(HasSubDirectory(str))
					ShowTreeButton(hti, STB_SHOW);
				else
					ShowTreeButton(hti, STB_HIDE);
			}
		}
		else if (wfd.cFileName[4] != _T('')&&wfd.dwFileAttributes==0)
		{
			if(wfd.cFileName[0] != _T('.'))
			{
				bHasChild = TRUE;
				hti = m_tree.InsertItem(wfd.cFileName, 7, 7, hParent, TVI_LAST);
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

//void CPathDialog::OnEnChangeEditFullpath()
//{
//	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
//	// 发送该通知，除非重写 CDialog::OnInitDialog()
//	// 函数并调用 CRichEditCtrl().SetEventMask()，
//	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
//
//	// TODO:  在此添加控件通知处理程序代码
//	CString textPath;
//	GetDlgItemText(IDC_EDIT_FULLPATH,textPath);
//    
//	//更改m_path
//
//
//	_tcscpy(m_path, textPath);
//	SetDlgItemText(IDC_EDIT_FULLPATH, m_path);
//}

void CPathDialog::OnEnChangeEditFullpath()
{
	// TODO:  如果该控件是 RICHEDIT 控件，则它将不会
	// 发送该通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

		CString textPath;		GetDlgItemText(IDC_EDIT_FULLPATH,textPath);
	    
		//更改m_path
	
	
		_tcscpy(m_path, textPath);
		//SetDlgItemText(IDC_EDIT_FULLPATH, m_path);
}
