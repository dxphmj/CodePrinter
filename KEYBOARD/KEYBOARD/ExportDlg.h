#pragma once

#ifdef KEYBOARD_EXPORTS
#define MESSAGEEDIT_API  _declspec(dllexport)
#else
#define MESSAGEEDIT_API  _declspec(dllimport)
#endif

class MESSAGEEDIT_API CExportDlg
{
public:
	CExportDlg(void);
	~CExportDlg(void);

    CString GetInputText(CString strIn);
};
