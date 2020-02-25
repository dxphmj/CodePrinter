/*
*	Copyright 2009,
*	All rights reserved.
*	
*	�ļ����ƣ�stpQueue.h
*	�ļ���ʶ: ����CBTC�������ƽ̨�з�װ�Ĺ��ú������з�װ��̬���еĴ����ļ������ж��е�һ���ڵ�Ϊһ���ֽ�
*	ժҪ��
*		���ļ�ʵ�ֵ���Ҫ������:
*		 1.�ڶ����в������ɸ�Ԫ��
*		 2.�ڶ����ж������ɸ�Ԫ��
*		 3.���г�ʼ��
*		 4.��ȡ���е����ݣ������ı���еĽṹ
*		 5.��ȡ���еĳ���
*		 6.����Ԫ�ص�����
*	��ǰ�汾��0.0.0.20090407
*	�� �ߣ���ΰ
*	������ڣ�2009��4��7��
*
*	ȡ���汾��
*	�� �ߣ�
*	������ڣ�
*/

#ifndef FILE_STP_QUEUE_H /* stpQueue.h */
#define FILE_STP_QUEUE_H

#include "stpDefine.h"

/*----------------�궨��----------------------------------*/
#define ERR_CODE_QUEUE_UNKOWN						0xffff0100	/*δ֪����*/
#define ERR_CODE_QUEUE_NOT_ENOUGH_ElEM				0xffff0101	/*���п���Ԫ��������Ҫ��ȡ�ĳ�����*/
#define ERR_CODE_QUEUE_NOT_ENOUGH_BUFF				0xffff0102	/*���п���Ԫ��������Ҫд��ĳ�����*/
#define ERR_CODE_QUEUE_ILLEGAL_INPUT				0xffff0111	/*���к������������ݲ��Ϸ�*/


/*----------------���Ͷ���---------------------------------*/
/*���²���Ϊ������صĶ���*/
typedef   BYTE  QueueElement;/*����Ԫ������*/
typedef struct S_stpQueueStruct
{
	DWORD dwIn; /* Queue input/write pointer */
	DWORD dwOut; /* Queue output/read pointer */
	DWORD dwQueueSize;/*���г���*/
	QueueElement *pValue; /* Queue array */
} stpQueueStruct;

/*----------------��������---------------------------------*/

/*
����ԭ��:DWORD stpQueueInitial(stpQueueStruct IN *pQueue, DWORD IN dwSize)
����˵��:
	stpQueueStruct IN *pQueue  		Ҫ��ʼ���Ķ���
	DWORD IN dwSize					���д�С
��������:
	���г�ʼ�����������ڳ�ʼ��һ�����У�Ϊ���нṹ���е�pValue����ռ䣬�������е�size��ʼ��
����ֵ:
	�ɹ�����0��ʧ�ܷ��ش�����
*/
DWORD stpQueueInitial(stpQueueStruct IN *pQueue, DWORD IN dwSize);

/*
����ԭ��:DWORD stpQueueInitialEx(stpQueueStruct IN *pQueue, DWORD IN dwSize, QueueElement pQueueElementSpace[])
����˵��:
	stpQueueStruct IN *pQueue  				Ҫ��ʼ���Ķ���
	DWORD IN dwSize							���д�С
	QueueElement IN pQueueElementSpace[]	������Ҫ���ڴ�ռ�
��������:
	���г�ʼ�����������ڳ�ʼ��һ�����У�Ϊ���нṹ���е�pValue����ռ䣬�������е�size��ʼ��.
	ע�⣺ʹ��stpQueueInitialEx����Ҫʹ��stpQueueRelease������
����ֵ:
	�ɹ�����0��ʧ�ܷ��ش�����
*/
DWORD stpQueueInitialEx(stpQueueStruct IN *pQueue, DWORD IN dwSize, QueueElement IN pQueueElementSpace[]);

/*
����ԭ��:void stpQueueRelease(stpQueueStruct IN *pQueue)
����˵��:
	stpQueueStruct IN *pQueue  		Ҫ�ͷſռ�Ķ���
��������:
	���д洢�ռ��ͷź������ڲ���Ҫĳ�����е�ʱ�򣬰Ѷ��е�Ԫ������ռ��ͷŵ�
����ֵ:
	�ɹ�����0��ʧ�ܷ��ش�����
*/
void stpQueueRelease(stpQueueStruct IN *pQueue);

/*
����ԭ��:DWORD stpQueueScan(DWORD IN dwLength, QueueElement OUT pData[], stpQueueStruct IN *pQueue)
����˵��:
	DWORD IN dwLength				Ҫ���������ݳ���
	QueueElement OUT pData[]			����������Ҫ��ŵ�����
	stpQueueStruct IN *pQueue  		Ҫ�������ݵĶ���
��������:
	����ɨ�躯�������Զ��������е����ݣ����ǶԶ��еĶ�дָ�붼������Ӱ�죬�����������ݻ��ڶ�����
����ֵ:
	�ɹ�����0��ʧ�ܷ��ش�����
		1-	��������е����ݲ������ͷ���0,�ɹ�����1
*/
DWORD stpQueueScan(DWORD IN dwLength, QueueElement OUT pData[], stpQueueStruct IN *pQueue);

/*
����ԭ��:DWORD stpQueueRead(DWORD IN dwLength, QueueElement OUT pData[], stpQueueStruct IN *pQueue)
����˵��:
	DWORD IN dwLength				Ҫ���������ݳ���
	QueueElement OUT pData[]			����������Ҫ��ŵ�����
	stpQueueStruct IN *pQueue  		Ҫ�������ݵĶ���
��������:
	�����к��������Զ��������е�����,�������һ�������У����ݶ������ָ�뷢���仯���������������Ѳ����ڶ�����
����ֵ:
	�ɹ�����0��ʧ�ܷ��ش�����
*/
DWORD stpQueueRead(DWORD IN dwLength, QueueElement OUT pData[], stpQueueStruct IN *pQueue);

/*
����ԭ��:DWORD stpQueueWrite(DWORD IN dwLength, QueueElement OUT pData[], stpQueueStruct IN *pQueue)
����˵��:
	DWORD IN dwLength				Ҫд������ݳ���
	QueueElement IN pData[]			Ҫд������ݴ�ŵ�����
	stpQueueStruct IN *pQueue  		Ҫд�����ݵĶ���
��������:
	д���к�������һ�������е�����д��һ�������С���һ�����еĲ�����������������ͬʱд��
	�����ǲ�����д���ģ����д���º������ش���
����ֵ:
	�ɹ�����0��ʧ�ܷ��ش�����
*/
DWORD stpQueueWrite(DWORD IN dwLength, QueueElement IN pData[], stpQueueStruct IN *pQueue);

/*
����ԭ��:DWORD stpQueueStatus (stpQueueStruct IN *pQueue)
����˵��:
	stpQueueStruct IN *pQueue  		Ҫ��ȡ���ݵĶ���
��������:
	���������п������ݳ���
����ֵ:
	���ض����п��õ����ݳ��ȣ��������Ϊ�գ�����0
*/
DWORD stpQueueStatus(stpQueueStruct IN *pQueue);

/*
����ԭ��:void stpQueueClear(stpQueueStruct IN *pQueue)
����˵��:
	stpQueueStruct IN *pQueue  		Ҫ������ݵĶ���
��������:
	��ն����п������ݳ���
����ֵ:
	��
*/
void stpQueueClear(stpQueueStruct IN *pQueue);

/*
����ԭ��:DWORD stpQueuePointChange(WORD IN wLen, stpQueueStruct IN *pQueue)
����˵��:
	WORD IN wLen					ָ���λ�ƴ�С
	stpQueueStruct IN *pQueue  		Ҫ�ı��ָ��Ķ���
��������:
	ֱ�Ӹı��ָ�롣��QueueScan���ʹ�ã����߽�ϼ�ʹQueueRead�Ĺ��ܡ��˷������QueueReadЧ�ʸߣ�����������ڶ������ͬʱ
	����һ�����У����ô˺�������Ϊ�˺���δ�����������
����ֵ:
	�ɹ�����0��ʧ�ܷ��ش�����
*/
DWORD stpQueuePointChange(WORD IN wLen, stpQueueStruct IN *pQueue);

#endif