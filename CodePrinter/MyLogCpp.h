#pragma once

#include <stdio.h>
#include <afxmt.h>
//#include <sys/timeb.h>
#include <time.h>
#include <stdarg.h>
#include <SHLWAPI.H>

//#pragma comment(lib,"Shlwapi.lib")

#define LOG_TIME_A_FILE  (60*5)   /* 一个文件记录的秒数 */
class CMyLogCpp
{
public:
	CMyLogCpp();
	virtual ~CMyLogCpp();
public:
	/* 设置日志输出目录和文件名称*/
	void SetDirAndFileName(CString csDir,CString csName);
	/* 日志初始化 */
	BOOL InitLog(CString csDir = _T(""),CString csName = _T(""));
	/* 在日志中记录字符串 */
	void logString(char *szBuf);
	/* 在日志中记录十六进制数据 */
	void logHex(unsigned char *pBuf, int nLen);
	void logHex(const char *format,PBYTE pBuf, int nLen);
	/* 带格式的日志输出 */
	void logFormat(const char *format, ...);
	// 停止记录
	void StopLog();
	//////////////////////////////////////////////////////////////////////
	//功能：
	//    重新建日志文件
	//返回值：
	//    TRUE:重新建日志文件成功
	//    FALSE:重新建分日志文件失败
	//////////////////////////////////////////////////////////////////////
	BOOL RecreateLogFile();
	/* 设置是否打印 */
	void SetIsPrint(BOOL bRet);
private:
	/* 获取时间字符串 */
	int GetTimeString(char *szBuffer);
	/* 写日志数据 */
	void WriteLog(PBYTE pBuf, int nLen);
	//  以十六进制文本格式系日志文件
	int BytesToHex(PBYTE szInfo, int iLen, PBYTE szDest);
	char* addLogInfo(char* dest, char* src );
private:
	BOOL g_bLogFlag;//是否记录标识
	HANDLE s_hFileLog;		/* 日志文件句柄 */
	time_t startTime;
	CCriticalSection m_Writelock;
	CString m_csDir;//存储文件目录
	CString m_csName;//文件名称
};

