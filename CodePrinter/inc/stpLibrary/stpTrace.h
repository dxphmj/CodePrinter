/*
*	Copyright 2009,
*	All rights reserved.
*	
*	�ļ����ƣ�stpTrace.h
*	�ļ���ʶ: ����CBTC�������ƽ̨�з�װ�Ĺ��ú������з�װ�ļ���¼���ܵĴ����ļ���
*	ժҪ��
*		���ļ�ʵ�ֵ���Ҫ������:
*		 1.ͨ��1����ʼ��������д�ļ�����ر�������ʼ����ֵ��
*		 2.stpTrace����TRACE������������ض����ļ��С�
*		 3.ͨ����ͬ�����������������趨��ͬ������ļ����������ļ���ID��
*		 4.stpTraceEx����TRACE���ļ��������IDΪ��ŵ��ļ����С�
*	��ǰ�汾��0.0.0.20090519
*	�� �ߣ���ΰ
*	������ڣ�2009��5��19��
*
*	ȡ���汾��
*	�� �ߣ�
*	������ڣ�
*/

#ifndef FILE_STP_TRACE_H /* stpTrace.h */
#define FILE_STP_TRACE_H

#include "stpDefine.h"


/*----------------�궨��----------------------------------*/
#define ERR_CODE_FLAG								0xff000000	/*������ı�־�������ڴ�ֵʱ��ʾ��Ȼ�����˴���*/
#define ERR_CODE_TRACE_UNKOWN						0xffff0200	/*δ֪����*/
#define ERR_CODE_TRACE_BUFF_OVERFLOW				0xffff0201	/*��¼�ļ��л��������*/
#define ERR_CODE_TRACE_ILLEGAL_INPUT				0xffff0202	/*�Ƿ�����*/
#define ERR_CODE_TRACE_FILE_CLOSED					0xffff0203	/*��¼�ļ�δ��*/
#define ERR_CODE_TRACE_FILL_COUNT_OVERFLOW			0xffff0204	/*��¼�ļ�������*/
#define ERR_CODE_TRACE_CREATE_FILE_FAILURE			0xffff0205	/*�����ļ�ʧ��*/
#define ERR_CODE_TRACE_INVALID_FORMAT				0xffff0206	/*��ʽ������Ч*/
#define ERR_CODE_TRACE_DISABLE						0xffff02ff	/*��¼���ܱ��ر�*/


#define MAX_COUNT_FILE_INDEX						100			/*��¼��������ͬʱ��¼�ļ�������*/


/*----------------���Ͷ���---------------------------------*/


/*----------------��������---------------------------------*/
/*
����ԭ��:void stpStartTrace(void)
����˵��:
��������:
	���ڿ����ļ���¼���ܡ�
����ֵ:
*/
void stpStartTrace(void);

/*
����ԭ��:void stpEndTrace(void)
����˵��:
��������:
	���ڹر��ļ���¼���ܡ�
����ֵ:
*/
void stpEndTrace(void);

/*
����ԭ��:void stpInitTrace(BOOL IN boValid)
����˵��:
	BOOL IN boValid					�ļ���¼�����Ƿ���Ч��
��������:
	��ʼ���ļ���¼��
����ֵ:
*/
void stpInitTrace(BOOL IN boValid);

/*
����ԭ��:DWORD __stdcall stpLockTrace(void)
����˵��:
��������:
	����д�ļ�������д�ļ�ʱ�п��ܴ��ڶ��̲߳�������ʱҪ�������������������ҡ�
	����������ʹ����ϱ�����н�����������������������
����ֵ:
	�ɹ�����0��ʧ�ܷ��ش�����
*/
DWORD __stdcall stpLockTrace(void);

/*
����ԭ��:BOOL __stdcall stpUnlockTrace(void)
����˵��:
��������:
	����д�ļ�������д�ļ�ʱ�п��ܴ��ڶ��̲߳�������ʱҪ�������������������ҡ�
	����������ʹ����ϱ�����н�����������������������
����ֵ:
	�ɹ����سɹ������򷵻�ʧ��
*/
BOOL __stdcall stpUnlockTrace(void);

/*
����ԭ��:DWORD stpOpenTraceFile(const CHAR* IN szPath, const CHAR* IN szFileName, BOOL IN boIsBinary = FALSE)
����˵��:
	const CHAR* IN szPath			·�������������NULL����Ĭ��ѡ��ǰ�ļ���
	const CHAR* IN szFileName		�ļ������������NULL����Ĭ���Ե�ǰʱ��Ϊ�ļ�����
									ʱ��ĸ�ʽ��"YYYY��mm��DD��HH-MM-SS"
	BOOL IN boIsBinary				�Ƿ��Զ����Ʒ�ʽ¼�롣
��������:
	���벻ͬ��·�����ļ�����ò�ͬ���ļ�ID�������ID���ں�����stpTraceEx��
����ֵ:
	�ɹ�����0�����ʧ�ܣ����ش����롣�����������0xff000000��
	���޷������ļ�ʱ����������������Ϸ���ERR_CODE_TRACE_ILLEGAL_INPUT����
	��û�п��е��ļ��ռ�ʱ�����ؼ�¼�ļ������ã�ERR_CODE_TRACE_FILL_COUNT_OVERFLOW����
*/
DWORD stpOpenTraceFile(const CHAR* IN szPath, const CHAR* IN szFileName, BOOL IN boIsBinary = FALSE);

/*
����ԭ��:DWORD stpEndTraceFile(DWORD IN dwTraceIndex)
����˵��:
	DWORD IN dwIndex				TRACE�ļ�����ţ������ͨ��stpStartTrace���
��������:
	�ر�ĳ����¼�ļ���
����ֵ:
*/
void stpCloseTraceFile(DWORD IN dwTraceIndex);

/*
����ԭ��:DWORD stpEndAllTraceFile(void)
����˵��:
��������:
	�ر����м�¼�ļ���
����ֵ:
*/
void stpCloseAllTraceFile(void);

/*
����ԭ��:DWORD stpTrace(const CHAR* IN szFormat, ...)
����˵��:
	const CHAR* IN szFormat			��ʽ����������
	...								��ʽ�����еĲ���
��������:
	��TRACE�Ľ�������Ĭ�ϵ��ļ��С�Ĭ�ϵ��ļ���ָ"E:\DebugData"�ļ������Ե�һ��д�ļ���ʱ��Ϊ�ļ���
	�´������ļ���
����ֵ:
	����ֵΪд�뵽�ļ��е��ֽ�����������󣬷��ش����롣�����������0xff000000��
	�����������ݳ���ʱ�����ػ����������ERR_CODE_TRACE_BUFF_OVERFLOW����
*/
DWORD stpTrace(const CHAR* IN szFormat, ...);

/*
����ԭ��:DWORD stpTraceEx(DWORD IN dwTraceIndex,const CHAR IN *szFormat, ...)
����˵��:
	DWORD IN dwIndex				TRACE�ļ�����ţ������ͨ��stpStartTrace���
	const CHAR IN *szFormat		��ʽ����������
	...								��ʽ�����еĲ���
��������:
	ͨ����ͬ��TRACE��ţ��Ը�ʽ������ʽ����������������ض��ļ���
����ֵ:
	����ֵΪд�뵽�ļ��е��ֽ�����������󣬷��ش����롣�����������0xff000000��
	���ļ�TRACE��źϷ�ʱ����������������Ϸ���ERR_CODE_TRACE_ILLEGAL_INPUT����
	���ļ�δ��ʱ�������ļ�δ�򿪣�ERR_CODE_TRACE_FILE_CLOSED����
	�����������ݳ���ʱ�����ػ����������ERR_CODE_TRACE_BUFF_OVERFLOW����
*/
DWORD stpTraceEx(DWORD IN dwTraceIndex, const CHAR IN *szFormat, ...);

/*
����ԭ��:void GetCurrentTimeString(CHAR OUT *szTimeString)
����˵��:
	CHAR OUT *szTimeString					�γɵĵ�ǰʱ����ַ�������ʽΪ��%Y��%B%d_%H_%M_%S��
��������:
	��õ�ǰʱ����ַ�������ʽΪ��%Y��%B%d_%H_%M_%S��
����ֵ:
*/
void GetCurrentTimeString(CHAR OUT *szTimeString);

#endif