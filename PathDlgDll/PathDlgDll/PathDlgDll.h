// PathDlgDll.h : main header file for the PATHDLGDLL DLL
//

#if !defined(AFX_PATHDLGDLL_H__50DD697F_B041_44D1_9652_DFEDDDB9678A__INCLUDED_)
#define AFX_PATHDLGDLL_H__50DD697F_B041_44D1_9652_DFEDDDB9678A__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPathDlgDllApp
// See PathDlgDll.cpp for the implementation of this class
//

/*
	ShowPathDlg - ��ʾѡ��Ŀ¼�Ի���
	������
		szPath���û�ѡ��Ŀ¼��ȫ·����szPath�������㹻�Ŀռ�����
		size��szPath���ܴ�С
	����ֵ��
		TRUE���û�����ˡ�ȷ������ť
		FALSE���û�����ˡ�ȡ������ť
*/
extern "C" __declspec(dllexport) BOOL ShowPathDlg(LPTSTR szPath, int size);
//extern "C" __declspec(dllexport) BOOL ShowReadPathDlg(LPTSTR szPath, int size);
class CPathDlgDllApp : public CWinApp
{
public:
	CPathDlgDllApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPathDlgDllApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CPathDlgDllApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PATHDLGDLL_H__50DD697F_B041_44D1_9652_DFEDDDB9678A__INCLUDED_)
