/*
*	Copyright 2009,
*	All rights reserved.
*	
*	�ļ����ƣ�stpDefine.h
*	�ļ���ʶ: ����CBTC�������ƽ̨�з�װ�Ĺ��ú������з�װ�������ͺͺ궨���ͷ�ļ���
*	ժҪ��
*		���ļ�ʵ�ֵ���Ҫ������:
*		 1.�������������
*		 2.���������ĺ�
*		 3.���峣������
*	��ǰ�汾��0.0.0.20090407
*	�� �ߣ���ΰ
*	������ڣ�2009��4��7��
*
*	ȡ���汾��
*	�� �ߣ�
*	������ڣ�
*/

#ifndef FILE_STP_DEFINE_H /* stpDefine.h */
#define FILE_STP_DEFINE_H

/*������ֵ����*/
#ifndef FALSE
#define FALSE									0				/*ʧ��*/
#endif
#ifndef TRUE
#define TRUE									1				/*�ɹ�*/
#endif

#ifndef YES
#define YES										(BYTE)0x55		/*��*/			
#endif
#ifndef NO
#define NO										(BYTE)0xaa		/*��*/			
#endif
#ifndef INVALID
#define INVALID									(BYTE)0xff		/*��Ч*/			
#endif
#ifndef INITIAL
#define INITIAL									(BYTE)0x00		/*��ʼ��*/			
#endif

/*�����붨��*/
#ifndef ERR_SUCCESS
#define ERR_SUCCESS									0UL			/*�������еĳɹ�ֵ*/		
#endif

/*LDRA_NOANALYSIS*/
/*NULL�Ķ���*/
#ifndef NULL
#define NULL										0UL			/*NULLֵ����*/
#endif
/*LDRA_ANALYSIS*/

/*����������Ͷ���*/
#ifndef IN
#define IN
#endif
#ifndef OUT
#define OUT
#endif


/*�����������Ͷ���*/
#if !defined(BYTE)
typedef unsigned char	BYTE;/*���ֽ�����*/
#endif
#if !defined(WORD)
typedef unsigned short	WORD;/*˫�ֽ�����*/
#endif
#if !defined(DWORD)
typedef unsigned long	DWORD;/*���ֽ�����*/
#endif
#if !defined(CHAR)
typedef char			CHAR;/*���ֽ�����*/
#endif
#if !defined(SWORD)
typedef signed short	SWORD;/*˫�ֽ�����*/
#endif
#if !defined(DSWORD)
typedef signed long		DSWORD;/*���ֽ�����*/
#endif
#if !defined(BOOL)
typedef int				BOOL;/*��������*/
#endif

//���Ͷ���
typedef enum STP_CRC_TYPE
{
	CrcType_16, CrcType_32
} stpCrcType;//Crc�����ͣ�32λCrc����16λCrc



#endif
