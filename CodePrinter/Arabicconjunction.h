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
	CString disposeinputtext( CString inputtext );//����������
	CString ArabicLan(CString inputstring);
	void W2C(wchar_t w_cn , char c_cn[]);
	CString ConvertWCHARToHex(CString Data, long nDataLength);//CStringת16����
	CString HexStrToCString(CString HexStr);//16����תCString
	vector<CString> split(CString str);//�ַ����ָ�
};
