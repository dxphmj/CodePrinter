#include "stdafx.h"
#include <Windows.h>
#include "GetRegValue.h"
#include "CodePrinter.h"
//可移植版本 wstring => string

std::string ws2s(const std::wstring &wstr)
{
	std::string str;
	int nLen = (int)wstr.length();
	str.resize(nLen, ' ');
	int nResult = WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)wstr.c_str(), nLen, (LPSTR)str.c_str(), nLen, NULL, NULL);
	if (nResult == 0)
	{
		return "";
	}
	return str;
}
//
////可移植版本 string => wstring
//std::wstring s2ws(const std::string& s)
//{
//	std::string curLocale = setlocale(LC_ALL, ""); 
//	const char* _Source = s.c_str();
//	size_t _Dsize = mbstowcs(NULL, _Source, 0) + 1;
//	wchar_t *_Dest = new wchar_t[_Dsize];
//	wmemset(_Dest, 0, _Dsize);
//	mbstowcs(_Dest,_Source,_Dsize);
//	std::wstring result = _Dest;
//	delete []_Dest;
//	setlocale(LC_ALL, curLocale.c_str());
//	return result;
//}
//string WcharToChar(const wchar_t* wp, size_t m_encode)
//{
//	std::string str;
//	int len = WideCharToMultiByte(m_encode, 0, wp, wcslen(wp), NULL, 0, NULL, NULL);
//	char	*m_char = new char[len + 1];
//	WideCharToMultiByte(m_encode, 0, wp, wcslen(wp), m_char, len, NULL, NULL);
//	m_char[len] = '\0';
//	str = m_char;
//	delete m_char;
//	return str;
//}
std::wstring stringToWstring(const std::string& str)
{	 
	// 预算-缓冲区中宽字节的长度    
	int unicodeLen = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);  
	// 给指向缓冲区的指针变量分配内存    
	wchar_t *pUnicode = (wchar_t*)malloc(sizeof(wchar_t)*unicodeLen);  
	// 开始向缓冲区转换字节    
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, pUnicode, unicodeLen);  
	wstring ret_str = pUnicode;  
	free(pUnicode);  
	return ret_str; 
}
std::string GetRegValue(int nKeyType, const std::string& strUrl, const std::string& strKey)
{
	std::string strValue("");
	HKEY hKey = NULL;
	HKEY hKeyResult = NULL;
	DWORD dwSize   = 0;
	DWORD dwDataType = 0;
	std::wstring wstrUrl = stringToWstring(strUrl);
	std::wstring wstrKey = stringToWstring(strKey);

	switch(nKeyType)
	{
	case 0:
		{
			hKey = HKEY_CLASSES_ROOT;
			break;
		}
	case 1:
		{
			hKey = HKEY_CURRENT_USER;
			break;
		}
	case 2:
		{
			hKey = HKEY_LOCAL_MACHINE;
			break;
		}
	case 3:
		{
			hKey = HKEY_USERS;
			break;
		}
	//case 4:
	//	{
	//		hKey = HKEY_PERFORMANCE_DATA;
	//		break;
	//	}
	//case 5:
	//	{
	//		hKey = HKEY_CURRENT_CONFIG;
	//		break;
	//	}
	//case 6:
	//	{
	//		hKey = HKEY_DYN_DATA;
	//		break;
	//	}
	//case 7:
	//	{
	//		//hKey = HKEY_CURRENT_USER_LOCAL_SETTINGS;
	//		break;
	//	}
	//case 8:
	//	{
	//		hKey = HKEY_PERFORMANCE_TEXT;
	//		break;
	//	}
	//case 9:
	//	{
	//		hKey = HKEY_PERFORMANCE_NLSTEXT;
	//		break;
	//	}
	default:
		{
			return strValue;
		}
	}

	//打开注册表
	if(ERROR_SUCCESS == ::RegOpenKeyEx(hKey, wstrUrl.c_str(), 0, KEY_QUERY_VALUE, &hKeyResult))
	{
		// 获取缓存的长度dwSize及类型dwDataType
		::RegQueryValueEx(hKeyResult, wstrKey.c_str(), 0, &dwDataType, NULL, &dwSize); 
		switch (dwDataType)
		{
		case REG_MULTI_SZ:
			{
				//分配内存大小
				BYTE* lpValue = new BYTE[dwSize];
				//获取注册表中指定的键所对应的值
				LONG lRet = ::RegQueryValueEx(hKeyResult, wstrKey.c_str(), 0, &dwDataType, lpValue, &dwSize);
				delete[] lpValue;
				break;
			}
		case REG_SZ:
			{
				//分配内存大小
				wchar_t* lpValue = new wchar_t[dwSize];
				memset(lpValue, 0, dwSize * sizeof(wchar_t));
				//获取注册表中指定的键所对应的值
				if (ERROR_SUCCESS == ::RegQueryValueEx(hKeyResult, wstrKey.c_str(), 0, &dwDataType, (LPBYTE)lpValue, &dwSize))
				{
					std::wstring wstrValue(lpValue);
					strValue = ws2s(wstrValue);
				}
				delete[] lpValue;
				break;
			}
		default:
			break;
		}
	}

	//关闭注册表
	::RegCloseKey(hKeyResult);


	return strValue;
}

