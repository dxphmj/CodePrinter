/*
*	Copyright 2009,
*	All rights reserved.
*	
*	�ļ����ƣ�stpTypeChange.h
*	�ļ���ʶ: ����CBTC�������ƽ̨�з�װ�Ĺ��ú������з�װ����ת���Ĵ����ļ���
*	ժҪ��
*		���ļ�ʵ�ֵ���Ҫ������:
*		 1.��һ��DWORD�Ͱ����ֽ���ǰת�����ֽ���
*		 2.��һ��WORD�Ͱ����ֽ���ǰת�����ֽ���
*		 3.������BYTE�Ͱ����ֽ���ǰת����WORD��
*		 4.���ĸ�BYTE�Ͱ����ֽ���ǰת����DWORD��
*		 5.��һ��DWORD�Ͱ����ֽ���ǰת�����ֽ���
*		 6.��һ��WORD�Ͱ����ֽ���ǰת�����ֽ���
*		 7.������BYTE�Ͱ����ֽ���ǰת����WORD��
*		 8.���ĸ�BYTE�Ͱ����ֽ���ǰת����DWORD��
*		 9.��һ������ת����ʮ�������ַ�������
*		 10.��һ��ʮ�������ַ�������ת��������
*	��ǰ�汾��0.0.0.20090407
*	�� �ߣ���ΰ
*	������ڣ�2009��4��7��
*
*	ȡ���汾��
*	�� �ߣ�
*	������ڣ�
*/

#ifndef FILE_STP_TYPE_CHANGE_H /* stpQueue.h */
#define FILE_STP_TYPE_CHANGE_H

#include "stpDefine.h"

/*
����ԭ��:void stpDWord2Byte(DWORD IN dwIn, BYTE OUT pbOut[])
����˵��:
	DWORD IN dwIn						Ҫת�����ֽ��͵�DWORD����ֵ
	BYTE OUT pbOut[]  					�洢�ֽ��͵ĵ�ַ
��������:
	��4���ֽڵ�DWord��Ϊ�ߵ��ֽڣ���λ���ֽڣ���λ���ֽڣ���ʾ wIn Ϊ���� pbOutΪ���
����ֵ:
	��
*/
void stpDWord2Byte(DWORD IN dwIn, BYTE OUT pbOut[]);

/*
����ԭ��:void stpWord2Byte(WORD IN wIn, BYTE OUT pbOut[])
����˵��:
	WORD IN wIn						Ҫת�����ֽ��͵�WORD����ֵ
	BYTE OUT pbOut[]  					�洢�ֽ��͵ĵ�ַ
��������:
	��2���ֽڵ�Word��Ϊ�ߵ��ֽڱ�ʾ wIn Ϊ����  pbOutΪ��� ��8λ����ߵ�ַ ��8λ����͵�ַ
����ֵ:
	��
*/
void stpWord2Byte(WORD IN wIn, BYTE OUT pbOut[]);

/*
����ԭ��:WORD stpByte2Word(const BYTE IN pbIn[])
����˵��:
	const BYTE IN pbIn[]  		Ҫת��ΪWORD�͵�BYTE�͵�ַ
��������:
	�������ֽڵ�Bytes��ΪWord  ���ֽ���ǰ  ���ֽ��ں�
����ֵ:
	����WORD�͵�ֵ������pbIn��NULL�Ļ�ֱ�ӷ���0xcccc
*/
WORD stpByte2Word(const BYTE IN pbIn[]);

/*
����ԭ��:DWORD stpByte2DWord(const BYTE IN pbIn[])
����˵��:
	const BYTE IN pbIn[]  		Ҫת��ΪDWORD�͵�BYTE�͵�ַ
��������:
	���ĸ��ֽڵ�Bytes��ΪDWord  ���ֽ���ǰ ���ֽ��ں�
����ֵ:
	����DWORD�͵�ֵ������pbIn��NULL�Ļ�ֱ�ӷ���0xcccc
*/
DWORD stpByte2DWord(const BYTE IN pbIn[]);

/*
����ԭ��:void stpDWord2ByteEx(DWORD IN dwIn, BYTE OUT pbOut[])
����˵��:
	DWORD IN dwIn						Ҫת�����ֽ��͵�DWORD����ֵ
	BYTE OUT pbOut[]  					�洢�ֽ��͵ĵ�ַ
��������:
	��4���ֽڵ�DWord��Ϊ�ߵ��ֽڣ���λ���ֽڣ���λ���ֽڣ���ʾ wIn Ϊ���� pbOutΪ���
����ֵ:
	��
*/
void stpDWord2ByteEx(DWORD IN dwIn, BYTE OUT pbOut[]);

/*
����ԭ��:void stpWord2ByteEx(WORD IN wIn, BYTE OUT pbOut[])
����˵��:
	WORD IN wIn						Ҫת�����ֽ��͵�WORD����ֵ
	BYTE OUT pbOut[]  					�洢�ֽ��͵ĵ�ַ
��������:
	��2���ֽڵ�Word��Ϊ�ߵ��ֽڱ�ʾ wIn Ϊ����  pbOutΪ��� ��8λ����͵�ַ ��8λ����ߵ�ַ
����ֵ:
	��
*/
void stpWord2ByteEx(WORD IN wIn, BYTE OUT pbOut[]);

/*
����ԭ��:WORD stpByte2WordEx(const BYTE IN pbIn[])
����˵��:
	const BYTE IN pbIn[]  		Ҫת��ΪWORD�͵�BYTE�͵�ַ
��������:
	�������ֽڵ�Bytes��ΪWord  ���ֽ���ǰ  ���ֽ��ں�
����ֵ:
	����WORD�͵�ֵ������pbIn��NULL�Ļ�ֱ�ӷ���0xcccc
*/
WORD stpByte2WordEx(const BYTE IN pbIn[]);

/*
����ԭ��:DWORD stpByte2DWordEx(const BYTE IN pbIn[])
����˵��:
	const BYTE IN pbIn[]  		Ҫת��ΪDWORD�͵�BYTE�͵�ַ
��������:
	���ĸ��ֽڵ�Bytes��ΪDWord  ���ֽ���ǰ ���ֽ��ں�
����ֵ:
	����DWORD�͵�ֵ������pbIn��NULL�Ļ�ֱ�ӷ���0xcccc
*/
DWORD stpByte2DWordEx(const BYTE IN pbIn[]);

/*
����ԭ��:void stpStrToHex(BYTE IN *pbDest, const BYTE IN *pbSrc, int IN nLen)
����˵��:
	BYTE OUT *pbDest  		���������
	BYTE IN *pbSrc			�ַ���
	int IN nLen				16���������ֽ���(�ַ����ĳ���/3)
��������:
	���ַ���ת��Ϊ16������
����ֵ:
*/
void stpStrToHex(BYTE OUT *pbDest, const BYTE IN *pbSrc, int IN nLen);

/*
����ԭ��:void stpHexToStr(BYTE OUT *pbDest, const BYTE IN *pbSrc, int IN nLen)
����˵��:
	BYTE IN *pbDest  		���Ŀ���ַ���
	BYTE IN *pbSrc			����16����������ʼ��ַ
	int IN nLen				16���������ֽ���
��������:
	��16������ת��Ϊ�ַ���
����ֵ:
*/
void stpHexToStr(BYTE OUT *pbDest, const BYTE IN *pbSrc, int IN nLen);

#endif