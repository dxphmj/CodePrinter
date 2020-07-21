#ifndef __GETREGVALUE_H__
#define __GETREGVALUE_H__

#include <string>

//---------------------------------------------------------------
//function: 
//     GetRegValue ��ȡע�����ָ������ֵ
//Access:
//      public 
//Parameter:
//     [in] int nKeyType - ע���������ͣ�����Ĳ���ֻ������������ֵ��
//               0:HKEY_CLASSES_ROOT
//               1:HKEY_CURRENT_USER
//               2:HKEY_LOCAL_MACHINE
//               3:HKEY_USERS
//               4:HKEY_PERFORMANCE_DATA
//               5:HKEY_CURRENT_CONFIG
//               6:HKEY_DYN_DATA
//               7:HKEY_CURRENT_USER_LOCAL_SETTINGS
//               8:HKEY_PERFORMANCE_TEXT
//               9:HKEY_PERFORMANCE_NLSTEXT
//     [in] const std::string & strUrl - Ҫ���� �ļ���·��
//     [in] const std::string & strKey - ָ���ļ�
//Returns:
//     std::string - ָ������ֵ
//Remarks:
//     ...
//author:  luoweifu
//---------------------------------------------------------------
std::string GetRegValue(int nKeyType, const std::string& strUrl, const std::string& strKey);

////����ֲ�汾 wstring => string
std::string ws2s(const std::wstring& wstr);
//
////����ֲ�汾 string => wstring
//std::wstring s2ws(const std::string& s);
//std::string WcharToChar(const wchar_t* wp, size_t m_encode = CP_ACP);
std::wstring stringToWstring(const std::string& str);

#endif //__GETREGVALUE_H__


