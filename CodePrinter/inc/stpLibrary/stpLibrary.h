/*
*	Copyright 2009,
*	All rights reserved.
*	
*	�ļ����ƣ�stpLibrary.h
*	�ļ���ʶ: ����CBTC�������ƽ̨�з�װ�Ĺ��ú�������ͷ�ļ��Ĺ����ļ���
*	ժҪ��
*		���ļ�ʵ�ֵ���Ҫ������:
*		 1.����Ŀǰ�������е�����ͷ�ļ�
*		 2.�����������Ӳ�ͬ�Ŀ��ļ�(ͨ����������)
*	��ǰ�汾��0.0.0.20090518
*	�� �ߣ���ΰ
*	������ڣ�2009��5��18��
*
*	ȡ���汾��
*	�� �ߣ�
*	������ڣ�
*/

#ifndef _FILE_STP_LIBRARY_H /*stpLibrary.h*/
#define _FILE_STP_LIBRARY_H

#include "stpDefine.h"
#include "stpCRC.h"//CRC16��CRC32�ĺ���
#include "stpQueue.h"//���еĺ���
#include "stpTypeChange.h"//����ת���ĺ���
#include "stpTrace.h"//�ļ���¼�ĺ���

#ifdef _STP_FUNC_LIBRARY

#pragma comment(lib, "stpFuncLibrary.lib")//���ӹ��ú����Ķ�̬��

#define CRC16			stpCrc16			//16λCrc�������Ƶ��ض���
#define CRC32			stpCrc32			//32λCrc�������Ƶ��ض���

#define fTRACE			stpTrace			//����ϢTRACE���ļ���ĺ������ض���

#endif	//#ifdef _STP_FUNC_LIBRARY



#ifdef _STP_SERIAL_LIBRARY			//���ڶ�̬���ӿ�

#include "stpSerial.h"						//�������ӿ��ͷ�ļ�
#if !defined(_STP_FUNC_LIBRARY) 			//֮ǰ���û�����ӹ��ú�����̬�⣬��ôֱ���Զ����Ӹÿ�
#pragma comment(lib, "stpFuncLibrary.lib")//���ӹ��ú����Ķ�̬��
#endif
#pragma comment(lib, "stpSerialLibrary.lib")//���Ӵ��ڶ�̬���ӿ�

#endif//#ifdef _STP_SERIAL_LIBRARY


#ifdef _STP_UDP_SOCKET_LIBRARY			//UDPSocket��̬���ӿ�

#include "stpUDPSocket.h"						//UDPSocket���ӿ��ͷ�ļ�
#if !defined(_STP_FUNC_LIBRARY) && !defined(_STP_SERIAL_LIBRARY)			//֮ǰ���û�����ӹ��ú�����̬�⣬��ôֱ���Զ����Ӹÿ�
#pragma comment(lib, "stpFuncLibrary.lib")//���ӹ��ú����Ķ�̬��
#endif
//#pragma comment(lib, "ws2_32.lib")//�Զ�����Socket��
#pragma comment(lib, "Ws2.lib")//�Զ�����Socket��
#pragma comment(lib, "stpUDPSocketLibrary.lib")//����UDPSocket��̬���ӿ�

#endif//#ifdef _STP_UDP_SOCKET_LIBRARY

#ifdef _STP_EXCEL_LIBRARY			//Excel��̬���ӿ�

#include "stpExcel.h"						//Excel���ӿ��ͷ�ļ�
//֮ǰ���û�����ӹ��ú�����̬�⣬��ôֱ���Զ����Ӹÿ�
#if !defined(_STP_FUNC_LIBRARY) && !defined(_STP_SERIAL_LIBRARY) && !defined(_STP_UDP_SOCKET_LIBRARY)
#pragma comment(lib, "stpFuncLibrary.lib")//���ӹ��ú����Ķ�̬��
#endif
#pragma comment(lib, "stpExcelLibrary.lib")//����Excel��̬���ӿ�

#endif//#ifdef _STP_EXCEL_LIBRARY


#ifdef _STP_DRAW_TRAIN_LIBRARY					//��С���ද̬���ͷ�ļ�	

#include "stpDrawTrain.h"
#pragma comment(lib, "stpDrawTrainLibrary.lib")//���ӻ�С����Ķ�̬��

#endif	//#ifdef _STP_DRAW_TRAIN_LIBRARY



#endif