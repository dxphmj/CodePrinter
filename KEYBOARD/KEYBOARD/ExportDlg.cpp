#include "StdAfx.h"
#include "ExportDlg.h"
#include "KeyBoardDlg.h"
CExportDlg::CExportDlg(void)
{
}

CExportDlg::~CExportDlg(void)
{
}


CString CExportDlg::GetInputText(CString strIn)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString str;

	CKeyBoardDlg dlg;
	if(dlg.DoModal() == IDOK)
	{
		return str;
	}
	return str;
}
