// PathDialog.cpp : implementation file
//

#include "stdafx.h"
#include "PathDlgDll.h"
#include "PathDialog.h"
#include "BnvImage.h"
#include "IsDeletDlg.h"
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
	booAllSet=false;
	//{{AFX_DATA_INIT(CPathDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CPathDialog::CPathDialog(int theType,bool isDisplay,CWnd* pParent /*=NULL*/)
: CDialog(CPathDialog::IDD, pParent)
{
	myType = theType;
	booDisplay=isDisplay;
	booAllSet=false;
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
	DDX_Control(pDX, IDC_BUTTON_NEWFILE, m_NewButton);
	DDX_Control(pDX, IDOK, m_OKBUT);
	DDX_Control(pDX, IDCANCEL, m_CLOBUT);
	DDX_Control(pDX, IDC_BUTTON_DELET, m_DETBUT);
	DDX_Control(pDX, IDC_BUTTON_RENAME, m_reName);
	DDX_Control(pDX, IDC_BUTTON_ALLSET, m_allSELECT);
}


BEGIN_MESSAGE_MAP(CPathDialog, CDialog)
	//{{AFX_MSG_MAP(CPathDialog)
	ON_NOTIFY(TVN_ITEMEXPANDING, IDC_TREE_DIRVIEW, OnItemexpandingTreeDirview)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_DIRVIEW, OnSelchangedTreeDirview)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CPathDialog::OnBnClickedOk)
//	ON_EN_CHANGE(IDC_EDIT_FULLPATH, &CPathDialog::OnEnChangeEditFullpath)
ON_EN_CHANGE(IDC_EDIT_FULLPATH, &CPathDialog::OnEnChangeEditFullpath)
ON_WM_CTLCOLOR()
//ON_NOTIFY(NM_CUSTOMDRAW, IDC_TREE_DIRVIEW, &CPathDialog::OnNMCustomdrawTreeDirview)
ON_BN_CLICKED(IDC_BUTTON_DELET, &CPathDialog::OnBnClickedButtonDelet)
ON_BN_CLICKED(IDC_BUTTON_ALLSET, &CPathDialog::OnBnClickedButtonAllset)
END_MESSAGE_MAP()
/////////////////////////////////////////////////////////////////////////////
// CPathDialog message handlers

BOOL CPathDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	switch(myType)
	{
	case 0://�ļ�����
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
	m_BKcolor = RGB(210, 231, 251);
	m_DlgBrush.CreateSolidBrush(m_BKcolor); 

	CRect rect;
	//GetWindowRect(&rect);
	GetClientRect(&rect);
	//���ð�ť��λ�ü���С
	CFont *m_Font;
	m_Font=new CFont;
	m_Font->CreateFont(
		15,                 //����߶�(��ת���������)=56   
		0,                 //������(��ת�������߶�)=20 
		0,                 //������ʾ�Ƕ�  
		0,                  //nOrientation=0 
		700,                 //�������=10  
		FALSE,              //��б��
		FALSE,              //���»���
		FALSE,              //��ɾ����
		DEFAULT_CHARSET,    //ʹ��ȱʡ�ַ���
		OUT_DEFAULT_PRECIS, //ȱʡ�������
		CLIP_DEFAULT_PRECIS,//ȱʡ�ü�����
		DEFAULT_QUALITY,    //nQuality=ȱʡֵ
		DEFAULT_PITCH,      //nPitchAndFamily=ȱʡֵ
		L"@system");         //������=@system  
		//CreatePointFont(120, _T("Arial"), NULL);
	GetDlgItem(IDC_STATIC_SELECT)->SetWindowPos(NULL,rect.left+50,rect.top+10,700,20,SWP_SHOWWINDOW);
	//GetDlgItem(IDC_STATIC_SELECT)->SetFont(&m_Font,true);
	m_Select.SetFont(m_Font,true);
	// TODO: Add extra initialization here
	m_ImageList.Create(IDB_FILE, 16, 16, RGB(0, 255, 0));
	m_tree.SetImageList(&m_ImageList, LVSIL_NORMAL);
	m_tree.SetFont(m_Font);
	HTREEITEM hRoot = m_tree.InsertItem(_T("�ҵ��豸"), 0, 0, TVI_ROOT, TVI_LAST);
	CreateDriveList();
	m_tree.Expand(hRoot, TVE_EXPAND);
	GetDlgItem(IDC_EDIT_FULLPATH)->SetWindowPos(NULL,rect.left+50,rect.top+50,700,30,SWP_SHOWWINDOW);
	GetDlgItem(IDC_EDIT_FULLPATH)->SetFont(m_Font,true);
	GetDlgItem(IDC_TREE_DIRVIEW)->SetWindowPos(NULL,rect.left+50,rect.top+100,700,330,SWP_SHOWWINDOW);
	GetDlgItem(IDOK)->SetWindowPos(NULL,rect.left+680,rect.top+450,100,40,SWP_SHOWWINDOW);
	GetDlgItem(IDOK)->EnableWindow(booDisplay);
	GetDlgItem(IDCANCEL)->SetWindowPos(NULL,rect.left+50,rect.top+450,100,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_ALLSET)->SetWindowPos(NULL,rect.left+185,rect.top+450,100,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_ALLSET)->EnableWindow(booDisplay);
	GetDlgItem(IDC_BUTTON_NEWFILE)->SetWindowPos(NULL,rect.left+305,rect.top+450,100,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_NEWFILE)->EnableWindow(booDisplay);
	GetDlgItem(IDC_BUTTON_RENAME)->SetWindowPos(NULL,rect.left+425,rect.top+450,100,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_RENAME)->EnableWindow(booDisplay);
	GetDlgItem(IDC_BUTTON_DELET)->SetWindowPos(NULL,rect.left+545,rect.top+450,100,40,SWP_SHOWWINDOW);
	GetDlgItem(IDC_BUTTON_DELET)->EnableWindow(booDisplay);
	m_allSELECT.LoadBitmaps(IDB_BITMAP_ALLUP,IDB_BITMAP_ALLDOWN,0,0,IDB_BITMAP_ALLUP);
	m_allSELECT.SizeToContent(); 
	m_NewButton.LoadBitmaps(IDB_BITMAP_NEWUP,IDB_BITMAP_NEWDOWN,0,0,IDB_BITMAP_NEWUP);
	m_NewButton.SizeToContent(); 
	m_OKBUT.LoadBitmaps(IDB_BITMAP_OKUP,IDB_BITMAP_OKDOWN,0,0,IDB_BITMAP_OKUP);
	m_OKBUT.SizeToContent(); 
	m_CLOBUT.LoadBitmaps(IDB_BITMAP_CLOUP,IDB_BITMAP_CLODOWN,0,0,IDB_BITMAP_CLOUP);
	m_CLOBUT.SizeToContent(); 
	m_DETBUT.LoadBitmaps(IDB_BITMAP_DETUP,IDB_BITMAP_DETDOWN,0,0,IDB_BITMAP_DETUP);
	m_DETBUT.SizeToContent(); 
	m_reName.LoadBitmaps(IDB_BITMAP_NAMEUPM,IDB_BITMAP_NAMEDOWNM,0,0,IDB_BITMAP_NAMEUPM);
	m_reName.SizeToContent(); 
	if (myType!=0)
	{
		GetDlgItem(IDC_BUTTON_ALLSET)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_NEWFILE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_RENAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_DELET)->ShowWindow(SW_HIDE);
	}
	//CTreeCtrl* testTree=(CTreeCtrl*)GetDlgItem(IDC_TREE_DIRVIEW);
	//testTree->SetBkColor(m_BKcolor);///���ǳ�Ա
	//delete m_Font;

	SetWindowPos(NULL,0,80,800,520,SWP_SHOWWINDOW );	

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

//����������б�
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
			wsprintf(szPart, _T("\\Ӳ��%d\\"), i);
			wsprintf(szPath, _T("\\Ӳ��%d\\%s"), i, szName);
		}
		else
		{
			lstrcpy(szPart, _T("\\Ӳ��\\"));
			wsprintf(szPath, _T("\\Ӳ��\\%s"), szName);
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	OnOK();
}

//void CPathDialog::OnEnChangeEditFullpath()
//{
//	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
//	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
//	// ���������� CRichEditCtrl().SetEventMask()��
//	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
//
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//	CString textPath;
//	GetDlgItemText(IDC_EDIT_FULLPATH,textPath);
//    
//	//����m_path
//
//
//	_tcscpy(m_path, textPath);
//	SetDlgItemText(IDC_EDIT_FULLPATH, m_path);
//}

void CPathDialog::OnEnChangeEditFullpath()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������

		CString textPath;		GetDlgItemText(IDC_EDIT_FULLPATH,textPath);
	    
		//����m_path
	
	
		_tcscpy(m_path, textPath);
		//SetDlgItemText(IDC_EDIT_FULLPATH, m_path);
}

HBRUSH CPathDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
    //if(pWnd->GetDlgCtrlID() != )
	if (pWnd->GetDlgCtrlID() !=IDC_TREE_DIRVIEW)
	{
		pDC->SetBkColor(m_BKcolor);
		return m_DlgBrush;
	}
	else
	{
		return hbr;
	}
		
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	
}

//void CPathDialog::OnNMCustomdrawTreeDirview(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	//LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
//	//// TODO: �ڴ���ӿؼ�֪ͨ����������
//	//*pResult = 0;
//
//
//	*pResult = CDRF_DODEFAULT;
//	NMTVCUSTOMDRAW* plvoid = reinterpret_cast<NMTVCUSTOMDRAW*>(pNMHDR);
//
//	if(CDDS_PREPAINT == plvoid->nmcd.dwDrawStage)
//	{
//		*pResult = CDRF_NOTIFYITEMDRAW;
//	}
//	else if(CDDS_ITEMPREPAINT == plvoid->nmcd.dwDrawStage)
//	{
//		COLORREF crText, crBkgnd;
//		plvoid->clrTextBk=m_BKcolor;
//		*pResult = CDRF_DODEFAULT;  
//	}
//}

void CPathDialog::OnBnClickedButtonDelet()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	HTREEITEM hItem = m_tree.GetSelectedItem();
	CString Text = m_tree.GetItemText(hItem);
	CString detCstr;
	detCstr.Format(_T("ȷ��ɾ��<%s>"),Text);
	CIsDeletDlg		isDeletDlg(detCstr);
	//isDeletDlg.GetDlgItem(IDC_STATIC_ISDET)->SetWindowText(detCstr);
	if(IDOK == isDeletDlg.DoModal())
	{
		//lstrcpy(szPath, pathDlg.m_path);
		//return TRUE;
		if (!DeleteFile(m_path))
		{
			RemoveDirectory(m_path);
		}
		
		m_tree.DeleteItem(hItem);
	}
}

void CPathDialog::OnBnClickedButtonAllset()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CWnd * pwnd=GetDlgItem(IDC_TREE_DIRVIEW);
	if (!booAllSet)
	{
		pwnd->ModifyStyle(0,TVS_CHECKBOXES);
		booAllSet=true;
	} 
	else
	{
		pwnd->ModifyStyle(TVS_CHECKBOXES,0);
	 //   m_tree.SetRedraw(FALSE);  
		////m_tree.DeleteAllItems(); 
		////insert or delete here  
		//m_tree.SetRedraw(TRUE);  
		//m_tree.RedrawWindow(); 
		//UpdateData(FALSE);
		 pwnd->Invalidate();
		booAllSet=false;
	}
	

}
