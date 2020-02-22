/*
*	Copyright 2009,
*	All rights reserved.
*	
*	�ļ����ƣ�stpCRC.h
*	�ļ���ʶ: ����CBTC�������ƽ̨�з�װ�Ĺ��ú������з�װCRC���ܵĴ����ļ���
*	ժҪ��
*		���ļ�ʵ�ֵ���Ҫ������:
*		 1.CRC16�Ĺ���
*		 2.CRC32�Ĺ���
*	��ǰ�汾��0.0.0.20090407
*	�� �ߣ���ΰ
*	������ڣ�2009��4��7��
*
*	ȡ���汾��
*	�� �ߣ�
*	������ڣ�
*/

#ifndef FILE_STP_CRC_H /* stpCRC.h */
#define FILE_STP_CRC_H

#include "stpDefine.h"

/*
����ԭ��:DWORD stpCrc32(const BYTE IN pbData[], WORD IN wLength)
����˵��:
	BYTE IN pbData[]  				����ָ��
	WORD IN wLength					���ݻ��������ȣ�Ҫ����CRC�Ļ��������ȣ�
��������:
	CRC32�ĺ�����ע�⣺����CRC�Ǵ��������ݵ�һ���ֽڵ����BIT��ʼ��
����ֵ:
	����ֵΪ32λCRCֵ��������볤��Ϊ0���߻���������Ϊ0����ô����0xcccccccc
*/
DWORD stpCrc32(const BYTE IN pbData[], WORD IN wLength);

/*
����ԭ��:WORD stpCrc16(const BYTE IN pbData[], WORD IN wLength)
����˵��:
	BYTE IN pbData[]  				����ָ��
	WORD IN wLength					���ݻ��������ȣ�Ҫ����CRC�Ļ��������ȣ�
��������:
	CRC16�ĺ�����ע�⣺����CRC�Ǵ��������ݵ�һ���ֽڵ����BIT��ʼ��
����ֵ:
	����ֵΪ16λCRCֵ
*/
WORD stpCrc16(const BYTE IN pbData[], WORD IN wLength);


#endif