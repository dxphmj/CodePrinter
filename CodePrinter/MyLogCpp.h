#pragma once

#include <stdio.h>
#include <afxmt.h>
//#include <sys/timeb.h>
#include <time.h>
#include <stdarg.h>
#include <SHLWAPI.H>

//#pragma comment(lib,"Shlwapi.lib")

#define LOG_TIME_A_FILE  (60*5)   /* һ���ļ���¼������ */
class CMyLogCpp
{
public:
	CMyLogCpp();
	virtual ~CMyLogCpp();
public:
	/* ������־���Ŀ¼���ļ�����*/
	void SetDirAndFileName(CString csDir,CString csName);
	/* ��־��ʼ�� */
	BOOL InitLog(CString csDir = _T(""),CString csName = _T(""));
	/* ����־�м�¼�ַ��� */
	void logString(char *szBuf);
	/* ����־�м�¼ʮ���������� */
	void logHex(unsigned char *pBuf, int nLen);
	void logHex(const char *format,PBYTE pBuf, int nLen);
	/* ����ʽ����־��� */
	void logFormat(const char *format, ...);
	// ֹͣ��¼
	void StopLog();
	//////////////////////////////////////////////////////////////////////
	//���ܣ�
	//    ���½���־�ļ�
	//����ֵ��
	//    TRUE:���½���־�ļ��ɹ�
	//    FALSE:���½�����־�ļ�ʧ��
	//////////////////////////////////////////////////////////////////////
	BOOL RecreateLogFile();
	/* �����Ƿ��ӡ */
	void SetIsPrint(BOOL bRet);
private:
	/* ��ȡʱ���ַ��� */
	int GetTimeString(char *szBuffer);
	/* д��־���� */
	void WriteLog(PBYTE pBuf, int nLen);
	//  ��ʮ�������ı���ʽϵ��־�ļ�
	int BytesToHex(PBYTE szInfo, int iLen, PBYTE szDest);
	char* addLogInfo(char* dest, char* src );
private:
	BOOL g_bLogFlag;//�Ƿ��¼��ʶ
	HANDLE s_hFileLog;		/* ��־�ļ���� */
	time_t startTime;
	CCriticalSection m_Writelock;
	CString m_csDir;//�洢�ļ�Ŀ¼
	CString m_csName;//�ļ�����
};

