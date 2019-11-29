
#include "stdafx.h"
#include "MyLogCpp.h"

CMyLogCpp::CMyLogCpp()
{
	g_bLogFlag = FALSE;
	s_hFileLog = NULL;		/* ��־�ļ���� */
	startTime = 0;
	m_csDir  = _T("");//�洢�ļ�Ŀ¼
	m_csName = _T("");//�ļ�����
}

CMyLogCpp::~CMyLogCpp()
{
	if (s_hFileLog)
	{
		CloseHandle(s_hFileLog);
		s_hFileLog = NULL;
	}

}
/* ��ȡʱ���ַ��� */
int CMyLogCpp::GetTimeString(char *szBuffer)
{
	SYSTEMTIME time;

	/* ��ȡʱ�� */
	GetLocalTime(&time);

	sprintf(szBuffer, "[%02d:%02d:%02d.%03d]",
		time.wHour,time.wMinute, time.wSecond,time.wMilliseconds); 
	return 0;
}
/* ������־���Ŀ¼���ļ�����*/
void CMyLogCpp::SetDirAndFileName(CString csDir,CString csName)
{
	m_csDir  = csDir;
	m_csName = csName;
}

/* ��־��ʼ�� */
BOOL CMyLogCpp::InitLog(CString csDir, CString csName)
{
	BOOL bRet = FALSE;
	/* //���ڴ���
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

	//��ȡUNIXϵͳʱ�� 
	//startTime = time( &ltime );  //��������

	//sprintf(szFileName, "%d.txt", ltime);

	USES_CONVERSION;  

	// ������־�ļ� 
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

/* д��־���� */
void CMyLogCpp::WriteLog(PBYTE pBuf, int nLen)
{
	DWORD dwBytesWritten = 0;
	time_t logTime;
	//time(&logTime); //��������

	if(!g_bLogFlag)
	{
		return;
	}
	m_Writelock.Lock();
	/* ��ȡ�ļ���С���������10M����д�ļ� */
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

//  ��ʮ�������ı���ʽϵ��־�ļ�
int CMyLogCpp::BytesToHex(PBYTE szInfo, int iLen, PBYTE szDest)
{
	int i = 0;
	/* ʮ�������ַ� */
	char chHex;
	/* ƫ���� */
	int  iOffset = 0;

	for (i=0; i<iLen; i++)
	{
		/* ת�����ֽ� */
		chHex = (szInfo[i]>>4) & 0x0F;
		if (chHex<10)
		{
			chHex += 0x30;
		}
		else
		{
			chHex += 'A'-10;
		}

		/* �洢���ֽ� */
		szDest[iOffset] = chHex;
		iOffset++;

		/* ת�����ֽ� */
		chHex = szInfo[i] & 0x0F;
		if (chHex<10)
		{
			chHex += 0x30;
		}
		else
		{
			chHex += 'A'-10;
		}

		/* �洢���ֽ� */
		szDest[iOffset] = chHex;
		iOffset++;

		/* �洢�ո� */
		szDest[iOffset] = ' ';
		iOffset++;
	}

	return iOffset;
}

/* ����ʽ����־��� */
void CMyLogCpp::logFormat(const char *format, ...)//���ĵ���
{
	va_list arg_ptr;
	char	szBuffer[4096];

	va_start(arg_ptr, format);

	vsprintf(szBuffer, format, arg_ptr);

	va_end(arg_ptr);

	logString(szBuffer);
}

/* ����־�м�¼�ַ��� */
void CMyLogCpp::logString(char *szBuf)
{
	char szBuffer[32];

	if(!g_bLogFlag)
	{
		return;
	}

	/* ����־��дʱ�� */
	GetTimeString(szBuffer);
	WriteLog((PBYTE)szBuffer, strlen(szBuffer));

	/* д��־���� */
	WriteLog((PBYTE)szBuf, strlen(szBuf));

	/* д�س����з� */
	WriteLog(PBYTE(_T("\r\n")), 2);
}
/* ����־�м�¼ʮ����������,������ʾ�� */ 
void CMyLogCpp::logHex(const char *format,PBYTE pBuf, int nLen)
{
	char szTime[32];
	char szBuffer[4096];
	int  nStringLen = 0;

	/* ����־��дʱ�� */
	GetTimeString(szTime);
	WriteLog((PBYTE)szTime, strlen(szTime));

	WriteLog((PBYTE)format, strlen(format));

	nStringLen = BytesToHex(pBuf, nLen, (PBYTE)szBuffer);

	WriteLog((PBYTE)szBuffer, nStringLen);

	/* д�س����з� */
	WriteLog((PBYTE)"\r\n", 2);
}
/* ����־�м�¼ʮ���������� */
void CMyLogCpp::logHex(unsigned char *pBuf, int nLen)
{
	char szTime[32];
	char szBuffer[40960];
	int  nStringLen = 0;

	if(!g_bLogFlag)
	{
		return;
	}

	/* ����־��дʱ�� */
	GetTimeString(szTime);
	WriteLog((PBYTE)szTime, strlen(szTime));

	nStringLen = BytesToHex(pBuf, nLen, (PBYTE)szBuffer);
	WriteLog((PBYTE)szBuffer, nStringLen);

	/* д�س����з� */
	WriteLog((PBYTE)"\r\n", 2);
}

/* ��src ƴ�ӵ� dest�󣬷������һ�� */
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
/* �����Ƿ��ӡ */
void CMyLogCpp::SetIsPrint(BOOL bRet)
{
	g_bLogFlag = bRet;
}

// ֹͣ��¼
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
//���ܣ�
//    ���½���־�ļ�
//����ֵ��
//    TRUE:���½���־�ļ��ɹ�
//    FALSE:���½�����־�ļ�ʧ��
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