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

	CKeyBoardDlg dlg(strIn);
	int nRet = dlg.DoModal();
	if(nRet == 2)
	{
		return dlg.m_strRet;
	}
	//CWnd* pWnd = GetDlgItem(IDC_EDIT1);
	//pWnd->SetWindowText(strIn);

	return str;

}
