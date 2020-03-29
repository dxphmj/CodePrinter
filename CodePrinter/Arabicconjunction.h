#pragma once
#include "stdafx.h "
#include <Map>
#include <vector>

using namespace std;

class CArabicconjunction
{
public:
	CArabicconjunction(CWnd* pParent = NULL);
	~CArabicconjunction(void);
public:
	CWnd* m_pCodePrinterDlg;
public:
	CString disposeinputtext( CString inputtext );//阿拉伯连体
	CString ArabicLan(CString inputstring);
	void W2C(wchar_t w_cn , char c_cn[]);
	CString ConvertWCHARToHex(CString Data, long nDataLength);//CString转16进制
	CString HexStrToCString(CString HexStr);//16进制转CString
	vector<CString> split(CString str);//字符串分割
};
