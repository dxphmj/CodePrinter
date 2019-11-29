
#include "stdafx.h"
#include "MyLogCpp.h"

CMyLogCpp::CMyLogCpp()
{
	g_bLogFlag = FALSE;
	s_hFileLog = NULL;		/* 日志文件句柄 */
	startTime = 0;
	m_csDir  = _T("");//存储文件目录
	m_csName = _T("");//文件名称
}

CMyLogCpp::~CMyLogCpp()
{
	if (s_hFileLog)
	{
		CloseHandle(s_hFileLog);
		s_hFileLog = NULL;
	}

}
/* 获取时间字符串 */
int CMyLogCpp::GetTimeString(char *szBuffer)
{
	SYSTEMTIME time;

	/* 获取时间 */
	GetLocalTime(&time);

	sprintf(szBuffer, "[%02d:%02d:%02d.%03d]",
		time.wHour,time.wMinute, time.wSecond,time.wMilliseconds); 
	return 0;
}
/* 设置日志输出目录和文件名称*/
void CMyLogCpp::SetDirAndFileName(CString csDir,CString csName)
{
	m_csDir  = csDir;
	m_csName = csName;
}

/* 日志初始化 */
BOOL CMyLogCpp::InitLog(CString csDir, CString csName)
{
	BOOL bRet = FALSE;
	/* //后期处理
	int i;
	time_t ltime;
	char szFileName[256];

	SYSTEMTIME timeTmp;

	m_csDir  = csDir;
	m_csName = csName;
	if (!csDir.IsEmpty())
	{
		if (!PathFileExists(csDir))
		{
			CreateDirectory(csDir,NULL);
		}
	}

	GetLocalTime(&timeTmp);
	sprintf(szFileName, "%s//%s_%04d%02d%02d%02d%02d%02d.txt",
		csDir,csName,timeTmp.wYear,timeTmp.wMonth,timeTmp.wDay,timeTmp.wHour,timeTmp.wMinute, timeTmp.wSecond); 

	//获取UNIX系统时间 
	//startTime = time( &ltime );  //后期完善

	//sprintf(szFileName, "%d.txt", ltime);

	USES_CONVERSION;  

	// 创建日志文件 
	s_hFileLog = CreateFile(A2W(szFileName),           // open MYFILE.TXT 
		GENERIC_READ|GENERIC_WRITE,              // open for reading 
		FILE_SHARE_READ,           // share for reading 
		NULL,                      // no security 
		OPEN_ALWAYS,             // existing file only 
		FILE_ATTRIBUTE_NORMAL,     // normal file 
		NULL);                     // no attr. template 

	i  = GetLastError();

	if (s_hFileLog != INVALID_HANDLE_VALUE) 
	{ 
		//SetIsPrint(TRUE);
		bRet = TRUE;
	} 
	*/
	return bRet;
}

/* 写日志数据 */
void CMyLogCpp::WriteLog(PBYTE pBuf, int nLen)
{
	DWORD dwBytesWritten = 0;
	time_t logTime;
	//time(&logTime); //后期完善

	if(!g_bLogFlag)
	{
		return;
	}
	m_Writelock.Lock();
	/* 获取文件大小，如果大于10M，重写文件 */
	if(logTime - startTime >= LOG_TIME_A_FILE)
	{
		CloseHandle(s_hFileLog);
		s_hFileLog = NULL;
		InitLog(m_csDir,m_csName);
	}

	if (NULL != s_hFileLog)
	{
		WriteFile(s_hFileLog, pBuf, nLen, &dwBytesWritten, NULL); 
	}
	m_Writelock.Unlock();
}

//  以十六进制文本格式系日志文件
int CMyLogCpp::BytesToHex(PBYTE szInfo, int iLen, PBYTE szDest)
{
	int i = 0;
	/* 十六进制字符 */
	char chHex;
	/* 偏移量 */
	int  iOffset = 0;

	for (i=0; i<iLen; i++)
	{
		/* 转化高字节 */
		chHex = (szInfo[i]>>4) & 0x0F;
		if (chHex<10)
		{
			chHex += 0x30;
		}
		else
		{
			chHex += 'A'-10;
		}

		/* 存储高字节 */
		szDest[iOffset] = chHex;
		iOffset++;

		/* 转化低字节 */
		chHex = szInfo[i] & 0x0F;
		if (chHex<10)
		{
			chHex += 0x30;
		}
		else
		{
			chHex += 'A'-10;
		}

		/* 存储低字节 */
		szDest[iOffset] = chHex;
		iOffset++;

		/* 存储空格 */
		szDest[iOffset] = ' ';
		iOffset++;
	}

	return iOffset;
}

/* 带格式的日志输出 */
void CMyLogCpp::logFormat(const char *format, ...)//在哪调用
{
	va_list arg_ptr;
	char	szBuffer[4096];

	va_start(arg_ptr, format);

	vsprintf(szBuffer, format, arg_ptr);

	va_end(arg_ptr);

	logString(szBuffer);
}

/* 在日志中记录字符串 */
void CMyLogCpp::logString(char *szBuf)
{
	char szBuffer[32];

	if(!g_bLogFlag)
	{
		return;
	}

	/* 在日志中写时间 */
	GetTimeString(szBuffer);
	WriteLog((PBYTE)szBuffer, strlen(szBuffer));

	/* 写日志数据 */
	WriteLog((PBYTE)szBuf, strlen(szBuf));

	/* 写回车换行符 */
	WriteLog(PBYTE(_T("\r\n")), 2);
}
/* 在日志中记录十六进制数据,并有提示符 */ 
void CMyLogCpp::logHex(const char *format,PBYTE pBuf, int nLen)
{
	char szTime[32];
	char szBuffer[4096];
	int  nStringLen = 0;

	/* 在日志中写时间 */
	GetTimeString(szTime);
	WriteLog((PBYTE)szTime, strlen(szTime));

	WriteLog((PBYTE)format, strlen(format));

	nStringLen = BytesToHex(pBuf, nLen, (PBYTE)szBuffer);

	WriteLog((PBYTE)szBuffer, nStringLen);

	/* 写回车换行符 */
	WriteLog((PBYTE)"\r\n", 2);
}
/* 在日志中记录十六进制数据 */
void CMyLogCpp::logHex(unsigned char *pBuf, int nLen)
{
	char szTime[32];
	char szBuffer[40960];
	int  nStringLen = 0;

	if(!g_bLogFlag)
	{
		return;
	}

	/* 在日志中写时间 */
	GetTimeString(szTime);
	WriteLog((PBYTE)szTime, strlen(szTime));

	nStringLen = BytesToHex(pBuf, nLen, (PBYTE)szBuffer);
	WriteLog((PBYTE)szBuffer, nStringLen);

	/* 写回车换行符 */
	WriteLog((PBYTE)"\r\n", 2);
}

/* 把src 拼接到 dest后，返回最后一个 */
char* CMyLogCpp::addLogInfo(char* dst, char* src )
{
	char * pt= dst;
	if((dst==NULL)||(src==NULL)) 
	{
		return NULL;
	}

	while(*dst!='\0') dst++;  
	while(*src!='\0') *dst++ = *src++;  
	*dst = '\0';  
	return pt;
}
/* 设置是否打印 */
void CMyLogCpp::SetIsPrint(BOOL bRet)
{
	g_bLogFlag = bRet;
}

// 停止记录
void CMyLogCpp::StopLog()
{
	if (NULL != s_hFileLog)
	{
		CloseHandle(s_hFileLog);
		s_hFileLog = NULL;
	}
	SetIsPrint(FALSE);
}

//////////////////////////////////////////////////////////////////////
//功能：
//    重新建日志文件
//返回值：
//    TRUE:重新建日志文件成功
//    FALSE:重新建分日志文件失败
//////////////////////////////////////////////////////////////////////
BOOL CMyLogCpp::RecreateLogFile()
{
	BOOL bRet = FALSE;
	SetIsPrint(FALSE);
	if (NULL != s_hFileLog)
	{
		CloseHandle(s_hFileLog);
		s_hFileLog = NULL;
	}
	bRet = InitLog(m_csDir,m_csName);
	return bRet;
}