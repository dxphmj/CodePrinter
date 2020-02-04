// PathDialog.cpp : implementation file
//

#include "stdafx.h"
#include "PathDlgDll.h"
#include "PathDialog.h"
#include "BnvImage.h"
#include "IsDeletDlg.h"
#include "RenameDlg.h"
#include "NewDlg.h"
#include "..\..\KEYBOARD\KEYBOARD\ExportDlg.h"
//#include <fstream>
//#include <string>
//#include <stdio.h>
////#include <Shlwapi.h>
////#pragma comment (lib,"Shlwapi.lib")
//#include "shellapi.h"
//#pragma comment (lib,"Ceshell.lib")
//using namespace std;
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
ON_BN_CLICKED(IDC_BUTTON_RENAME, &CPathDialog::OnBnClickedButtonRename)
ON_BN_CLICKED(IDC_BUTTON_NEWFILE, &CPathDialog::OnBnClickedButtonNewfile)
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
	m_BKcolor = RGB(210, 231, 251);
	m_DlgBrush.CreateSolidBrush(m_BKcolor); 
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CRect rect;
	//GetWindowRect(&rect);
	GetClientRect(&rect);
	//设置按钮的位置及大小
	CFont *m_Font;
	m_Font=new CFont;
	m_Font->CreateFont(
		15,                 //字体高度(旋转后的字体宽度)=56   
		0,                 //字体宽度(旋转后的字体高度)=20 
		0,                 //字体显示角度  
		0,                  //nOrientation=0 
		700,                 //字体磅数=10  
		FALSE,              //非斜体
		FALSE,              //无下划线
		FALSE,              //无删除线
		DEFAULT_CHARSET,    //使用缺省字符集
		OUT_DEFAULT_PRECIS, //缺省输出精度
		CLIP_DEFAULT_PRECIS,//缺省裁减精度
		DEFAULT_QUALITY,    //nQuality=缺省值
		DEFAULT_PITCH,      //nPitchAndFamily=缺省值
		L"@system");         //字体名=@system  
		//CreatePointFont(120, _T("Arial"), NULL);
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
	//testTree->SetBkColor(m_BKcolor);///不是成员
	//delete m_Font;

	SetWindowPos(NULL,0,80,800,520,SWP_SHOWWINDOW );	

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

HBRUSH CPathDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何属性
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
		
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	
}

//void CPathDialog::OnNMCustomdrawTreeDirview(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	//LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
//	//// TODO: 在此添加控件通知处理程序代码
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

//单个删除
void CPathDialog::DeleteDirectory(LPCTSTR path)//迭代删除用
{
	vector<WIN32_FIND_DATA> detErrVec;
	LPCTSTR szCurDir=path;
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
				//FindClose(hFind);
				lstrcpy(szPath, szCurDir);
				lstrcat(szPath,wfd.cFileName);
				DeleteDirectory(szPath);
			}
		}
		else //if(wfd.dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE)
		{
			if(wfd.cFileName[0] != _T('.'))
			{
				//FindClose(hFind);
				//lstrcpy(szPath, szCurDir);
				//lstrcat(szPath,wfd.cFileName);
				//ifstream fin(szPath);/////应该删除空文件
				//if(!fin)
				//{
				//	continue;;
				//}
				//string c;
				//fin >> c;
				//if(c.empty())
				//{
				//	fin.close();
					detErrVec.push_back(wfd);
				//	bRet = FindNextFile(hFind, &wfd);
				//	continue;
				//}
				//fin.close();
				//allErrVec.push_back(wfd);
			}
		}
		bRet = FindNextFile(hFind, &wfd);
	}
	FindClose(hFind);

	//sort(allErrVec.begin(),allErrVec.end(),comp);
	for (int i=0;i<detErrVec.size();i++)
	{
		WIN32_FIND_DATA tempDet=detErrVec.at(i);
		//lstrcpy(szPath, szCurDir);
		//lstrcat(szPath,tempDet.cFileName);
		lstrcpy(szPath, szCurDir);
		if(szPath[lstrlen(szCurDir)-1] != _T('\\'))
			lstrcat(szPath, _T("\\"));
		lstrcat(szPath,tempDet.cFileName);
		int tsttt=DeleteFile(szPath);
		tsttt=GetLastError();
	}
	RemoveDirectory(path);
}
//删除和粘贴
void CPathDialog::OnBnClickedButtonDelet()
{
	// TODO: 在此添加控件通知处理程序代码
	if (booAllSet)
	{
		booAllSet=false;
		CWnd * pwnd=GetDlgItem(IDC_TREE_DIRVIEW);
		pwnd->ModifyStyle(TVS_CHECKBOXES,0);
		HTREEITEM hItem = m_tree.GetSelectedItem();
		//CString Text = m_tree.GetItemText(hItem);
		CString movePath=GetFullPath(hItem);
		if (movePath.ReverseFind('\\')==(movePath.GetLength()-1))
		{
			movePath.Delete(movePath.GetLength()-1,1);
		}
		if (booIsCut)
		{
			//CString parentPath=_T("");
			for (int i=0;i<pasteVec.size();i++)
			{
				MoveFileM(movePath,pasteVec.at(i));
				//DeleteFileM(pasteVec.at(i));
				if (pasteVec.at(i).ReverseFind('.')==-1)
				{
					int tempN=pasteVec.at(i).ReverseFind('\\');
					CString tempName=pasteVec.at(i).Mid(tempN,pasteVec.at(i).GetLength()-1-tempN);
					m_tree.InsertItem(tempName,6,6,hItem,TVI_LAST);
				} 
				else
				{
					int tempN=pasteVec.at(i).ReverseFind('\\');
					CString tempName=pasteVec.at(i).Mid(tempN,pasteVec.at(i).GetLength()-1-tempN);
					m_tree.InsertItem(tempName,7,7,hItem,TVI_LAST);
				}
				//CString nowParentPath=pasteVec.at(i).Mid(0,pasteVec.at(i).ReverseFind('\\'));
				//if (!nowParentPath.CompareNoCase(parentPath))
				//{
				//	//相等
				//	continue;
				//}
				//else
				//{
				//	//不相等
				//	if(HasSubDirectory(parentPath))
				//		ShowTreeButton(HTreeParentItem, STB_SHOW);
				//	else
				//		ShowTreeButton(HTreeParentItem, STB_HIDE);
				//	parentPath=nowParentPath;
				//}
			}
		} 
		else
		{
			for (int i=0;i<pasteVec.size();i++)
			{
				CopyFileM(movePath,pasteVec.at(i));
				if (pasteVec.at(i).ReverseFind('.')==-1)
				{
					int tempN=pasteVec.at(i).ReverseFind('\\');
					CString tempName=pasteVec.at(i).Mid(tempN,pasteVec.at(i).GetLength()-1-tempN);
					m_tree.InsertItem(tempName,6,6,hItem,TVI_LAST);
				} 
				else
				{
					int tempN=pasteVec.at(i).ReverseFind('\\');
					CString tempName=pasteVec.at(i).Mid(tempN,pasteVec.at(i).GetLength()-1-tempN);
					m_tree.InsertItem(tempName,7,7,hItem,TVI_LAST);
				}
			}
		}
		CString str;
		str = GetFullPath(hItem);
		if(HasSubDirectory(str))
			ShowTreeButton(hItem, STB_SHOW);
		else
			ShowTreeButton(hItem, STB_HIDE);

		m_allSELECT.LoadBitmaps(IDB_BITMAP_ALLUP,IDB_BITMAP_ALLDOWN,0,0,IDB_BITMAP_ALLUP);
		m_allSELECT.SizeToContent(); 
		m_NewButton.LoadBitmaps(IDB_BITMAP_NEWUP,IDB_BITMAP_NEWDOWN,0,0,IDB_BITMAP_NEWUP);
		m_NewButton.SizeToContent(); 
		m_DETBUT.LoadBitmaps(IDB_BITMAP_DETUP,IDB_BITMAP_DETDOWN,0,0,IDB_BITMAP_DETUP);
		m_DETBUT.SizeToContent(); 
		m_reName.LoadBitmaps(IDB_BITMAP_NAMEUPM,IDB_BITMAP_NAMEDOWNM,0,0,IDB_BITMAP_NAMEUPM);
		m_reName.SizeToContent(); 
		GetDlgItem(IDC_BUTTON_ALLSET)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_NEWFILE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_RENAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_DELET)->ShowWindow(SW_SHOW);
	} 
	else
	{
		HTREEITEM hItem = m_tree.GetSelectedItem();
		CString Text = m_tree.GetItemText(hItem);
		CString detCstr;
		detCstr.Format(_T("确定删除<%s>"),Text);
		CIsDeletDlg		isDeletDlg(detCstr);
		//isDeletDlg.GetDlgItem(IDC_STATIC_ISDET)->SetWindowText(detCstr);
		if(IDOK == isDeletDlg.DoModal())
		{
			//lstrcpy(szPath, pathDlg.m_path);
			//return TRUE;
			CString tempPN=m_path;
			if (tempPN.ReverseFind('\\')==(tempPN.GetLength()-1))
			{
				tempPN.Delete(tempPN.GetLength()-1,1);
			}
			tempPN=tempPN+'\0';
			//if (tempPN[tempPN.GetLength()-4]=)
			//{
			//}
			DeleteFileM(m_path);
			//if (!DeleteFile(m_path))
			//{
			//	DeleteDirectory(m_path);
			//}
			HTREEITEM HTreeParentItem = m_tree.GetParentItem(hItem);
			m_tree.DeleteItem(hItem);
			CString str;
			str = GetFullPath(HTreeParentItem);
			if(HasSubDirectory(str))
				ShowTreeButton(HTreeParentItem, STB_SHOW);
			else
				ShowTreeButton(HTreeParentItem, STB_HIDE);
		}
	}

}

//复选切换
void CPathDialog::OnBnClickedButtonAllset()
{
	// TODO: 在此添加控件通知处理程序代码
	CWnd * pwnd=GetDlgItem(IDC_TREE_DIRVIEW);
	if (!booAllSet)
	{
		pwnd->ModifyStyle(0,TVS_CHECKBOXES);
		booAllSet=true;

		m_allSELECT.LoadBitmaps(IDB_BITMAP_NOTALLUP,IDB_BITMAP_NOTALLDOWN,0,0,IDB_BITMAP_NOTALLUP);
		m_allSELECT.SizeToContent(); 
		m_NewButton.LoadBitmaps(IDB_BITMAP_COPYUP,IDB_BITMAP_COPYDOWN,0,0,IDB_BITMAP_COPYUP);
		m_NewButton.SizeToContent(); 
		m_reName.LoadBitmaps(IDB_BITMAP_CUTUP,IDB_BITMAP_CUTDOWN,0,0,IDB_BITMAP_CUTUP);
		m_reName.SizeToContent(); 
		GetDlgItem(IDC_BUTTON_DELET)->ShowWindow(SW_HIDE);
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
		//pwnd->Invalidate(false);
		//m_tree.invalidate();
		booAllSet=false;

		m_allSELECT.LoadBitmaps(IDB_BITMAP_ALLUP,IDB_BITMAP_ALLDOWN,0,0,IDB_BITMAP_ALLUP);
		m_allSELECT.SizeToContent(); 
		m_NewButton.LoadBitmaps(IDB_BITMAP_NEWUP,IDB_BITMAP_NEWDOWN,0,0,IDB_BITMAP_NEWUP);
		m_NewButton.SizeToContent(); 
		m_DETBUT.LoadBitmaps(IDB_BITMAP_DETUP,IDB_BITMAP_DETDOWN,0,0,IDB_BITMAP_DETUP);
		m_DETBUT.SizeToContent(); 
		m_reName.LoadBitmaps(IDB_BITMAP_NAMEUPM,IDB_BITMAP_NAMEDOWNM,0,0,IDB_BITMAP_NAMEUPM);
		m_reName.SizeToContent(); 
		GetDlgItem(IDC_BUTTON_DELET)->ShowWindow(SW_SHOW);
	}
}

//重命名和剪切
void CPathDialog::OnBnClickedButtonRename()
{
	// TODO: 在此添加控件通知处理程序代码
//rename(source,newname)；
	if (booAllSet)
	{
		booIsCut=true;
		HTREEITEM hRoot = m_tree.GetRootItem();
		CheckAndAddNode(hRoot);

		m_DETBUT.LoadBitmaps(IDB_BITMAP_PASTEUP,IDB_BITMAP_PASTEDOWN,0,0,IDB_BITMAP_PASTEUP);
		m_DETBUT.SizeToContent(); 
		GetDlgItem(IDC_BUTTON_ALLSET)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_NEWFILE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_RENAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_DELET)->ShowWindow(SW_SHOW);
	} 
	else
	{
		HTREEITEM hItem = m_tree.GetSelectedItem();
		CString Text = m_tree.GetItemText(hItem);
		CRenameDlg		renameDlg(Text);

		if(IDOK == renameDlg.DoModal())
		{
			CString tempStr;
			tempStr=m_path;
			tempStr.Replace(Text,renameDlg.m_RenameSTR);
			int tempNum=tempStr.ReverseFind('\\');
			//tempStr=tempStr.Mid(0,tempNum);
			//lstrcat(tempStr,Text);
			if (tempNum==(tempStr.GetLength()-1))
			{
				tempStr.Delete(tempNum,1);
			}
			tempStr=tempStr+'\0';
			CString tempFm=m_path;
			tempFm=tempFm+'\0';
			ReNameFile(tempStr,m_path);
			m_tree.SetItemText(hItem,renameDlg.m_RenameSTR);
		}
	}

}
////删除文件或者文件夹
bool CPathDialog::DeleteFileM(LPCTSTR lpszPath)
{
	SHFILEOPSTRUCT FileOp={0};
	FileOp.fFlags = FOF_ALLOWUNDO | //允许放回回收站
		FOF_NOCONFIRMATION; //不出现确认对话框
	FileOp.pFrom = lpszPath;
	FileOp.pTo = NULL; //一定要是NULL
	FileOp.wFunc = FO_DELETE; //删除操作
	return SHFileOperation(&FileOp) == 0;
}
//从命名文件或文件夹
bool CPathDialog::ReNameFile(LPCTSTR pTo,LPCTSTR pFrom)
{
	SHFILEOPSTRUCT FileOp={0};
	FileOp.fFlags = FOF_NOCONFIRMATION; //不出现确认对话框
	FileOp.pFrom = pFrom;
	FileOp.pTo = pTo;
	FileOp.wFunc = FO_RENAME;
	return SHFileOperation(&FileOp) == 0;
}

//复制文件或文件夹
bool CPathDialog::CopyFileM(LPCTSTR pTo,LPCTSTR pFrom)
{
	SHFILEOPSTRUCT FileOp={0};
	FileOp.fFlags = FOF_NOCONFIRMATION| //不出现确认对话框
		FOF_NOCONFIRMMKDIR|FOF_NOERRORUI ; //需要时直接创建一个文件夹,不需用户确定
	FileOp.pFrom = pFrom;
	FileOp.pTo = pTo;
	FileOp.wFunc = FO_COPY;
	return SHFileOperation(&FileOp) == 0;
}

//移动文件或文件夹
bool CPathDialog::MoveFileM(LPCTSTR pTo,LPCTSTR pFrom)
{
	SHFILEOPSTRUCT FileOp={0};
	FileOp.fFlags = FOF_NOCONFIRMATION| //不出现确认对话框
		FOF_NOCONFIRMMKDIR|FOF_NOERRORUI ; //需要时直接创建一个文件夹,不需用户确定
	FileOp.pFrom = pFrom;
	FileOp.pTo = pTo;
	FileOp.wFunc = FO_MOVE;
	return SHFileOperation(&FileOp) == 0;
}
//新建和复制
void CPathDialog::OnBnClickedButtonNewfile()
{
	// TODO: 在此添加控件通知处理程序代码
	
	if (booAllSet)
	{
		booIsCut=false;
		HTREEITEM hRoot = m_tree.GetRootItem();
		CheckAndAddNode(hRoot);
		m_DETBUT.LoadBitmaps(IDB_BITMAP_PASTEUP,IDB_BITMAP_PASTEDOWN,0,0,IDB_BITMAP_PASTEUP);
		m_DETBUT.SizeToContent(); 
		GetDlgItem(IDC_BUTTON_ALLSET)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_NEWFILE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_RENAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_DELET)->ShowWindow(SW_SHOW);
	} 
	else
	{
		HTREEITEM hItem = m_tree.GetSelectedItem();
		CString Text = m_tree.GetItemText(hItem);
		CNewDlg	newDlg;
		//isDeletDlg.GetDlgItem(IDC_STATIC_ISDET)->SetWindowText(detCstr);
		if(IDOK == newDlg.DoModal())
		{
			CString tempName=newDlg.m_nameSTR;
			CString tempPath=m_path;
			int tempNum=tempPath.ReverseFind('\\');
			//tempStr=tempStr.Mid(0,tempNum);
			//lstrcat(tempStr,Text);
			if (tempNum==(tempPath.GetLength()-1))
			{
				tempPath=tempPath+tempName;

				CreateDirectory(tempPath,NULL);
				m_tree.InsertItem(tempName, 6, 6, hItem, TVI_LAST);
				if(HasSubDirectory(m_path))
					ShowTreeButton(hItem, STB_SHOW);
				else
					ShowTreeButton(hItem, STB_HIDE);
			}

		}
	}

}

// 递归遍历树形控件
 void CPathDialog::CheckAndAddNode(HTREEITEM hRoot)
 {
	     // 如果不是叶子节点
    if(TRUE == m_tree.ItemHasChildren(hRoot))
     {
        if(TRUE == m_tree.GetCheck(hRoot))
        {
             // 插入所有页节点
	         //InsertAllLeaves(hRoot);
			CString tempPP=GetFullPath(hRoot);
			if (tempPP.ReverseFind('\\')==(tempPP.GetLength()-1))
			{
				tempPP.Delete(tempPP.GetLength()-1,1);
			}
			tempPP=tempPP+'\0';
			pasteVec.push_back(tempPP);
        }
        else
	    {
			 // 查询所有节点，递归
             HTREEITEM hChild = m_tree.GetChildItem(hRoot);
			while(NULL != hChild)
             {
	               CheckAndAddNode(hChild);
	               hChild = m_tree.GetNextSiblingItem(hChild);
             }
		}
	}
    else // 是叶子节点
	{
		   // 被选中
         if(TRUE == m_tree.GetCheck(hRoot))
         {
	        // m_tree.InsertString(m_listClients.GetCount(), m_treeTest.GetItemText(hRoot));
			 CString tempPP=GetFullPath(hRoot);
			 if (tempPP.ReverseFind('\\')==(tempPP.GetLength()-1))
			 {
				 tempPP.Delete(tempPP.GetLength()-1,1);
			 }
			 tempPP=tempPP+'\0';
			 pasteVec.push_back(tempPP);
	     }
	}
 }
 BOOL CPathDialog::PreTranslateMessage(MSG* pMsg)
 {
	 // TODO: 在此添加专用代码和/或调用基类
	 CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_FULLPATH);
	 ASSERT(pEdit && pEdit->GetSafeHwnd());
	 if(WM_LBUTTONDOWN == pMsg->message && pEdit->GetSafeHwnd() == pMsg->hwnd)
	 {
		 //pEdit->SetFocus();
		 //pEdit->SetSel(-1);
		 CString str;
		 pEdit-> GetWindowText(str);

		 CExportDlg myCExportDlg;
		 //CString ts;
		 //ts.Format(L"%s",_T("sdfsa"));
		 str=myCExportDlg.GetInputText(str);
		 pEdit-> SetWindowText(str);
		 return TRUE;
	 }
	 return CDialog::PreTranslateMessage(pMsg);
 }
