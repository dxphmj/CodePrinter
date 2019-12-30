// PathDlgDll.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "PathDlgDll.h"
#include "PathDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CPathDlgDllApp

BEGIN_MESSAGE_MAP(CPathDlgDllApp, CWinApp)
	//{{AFX_MSG_MAP(CPathDlgDllApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPathDlgDllApp construction

CPathDlgDllApp::CPathDlgDllApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CPathDlgDllApp object

CPathDlgDllApp theApp;

extern "C" __declspec(dllexport) BOOL ShowPathDlg(LPTSTR szPath, int size,int theType,bool isDisplay)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CPathDialog		pathDlg(theType,isDisplay);

	if(IDOK == pathDlg.DoModal())
	{
		lstrcpy(szPath, pathDlg.m_path);
		return TRUE;
	}
	
	return FALSE;
}

//extern "C" __declspec(dllexport) BOOL ShowReadPathDlg(LPTSTR szPath, int size)
//{
//	AFX_MANAGE_STATE(AfxGetStaticModuleState());
//	CPathDialog		pathDlg;
//
//	if(IDOK == pathDlg.DoModal())
//	{
//		lstrcpy(szPath, pathDlg.m_path);
//		//lstrcpy(szPath, pathDlg.m_path);
//		return TRUE;
//	}
//
//	return FALSE;
//}
