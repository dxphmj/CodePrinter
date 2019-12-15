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
	CKeyBoardDlg dlg(strIn);
	int nRet = dlg.DoModal();
	if(nRet == 2||nRet == 0)
	{
		return dlg.m_strRet;
	}
	return strIn;

}
