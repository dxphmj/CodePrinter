/*
*	Copyright 2009,
*	All rights reserved.
*	
*	�ļ����ƣ�stpSerail.cpp
*	�ļ���ʶ: 
*	ժҪ��
*		�������Ҫ������:
*		 1.���Է��ͺͽ���������һ֡���ģ�0203��ת�����Э�飩���Զ�����ת�崦���CRC���ĵĴ�����Щ�����Ǵ���ͨ�Ų�
*		   ��CRC���ģ�����Ӧ�ò�ı��ġ������Կ���CRC�ĸ��ֽ���ǰ�����ǵ��ֽ���ǰ��
*		 2.�������ɵĿ��Ʋ����ʡ�����λ��ֹͣλ��У��λ�Ȳ���
*		 3.ʹ�÷������ƽ̨�������еĵײ㺯��������Ϸ������ƽ̨������ʹ�ã��Ƿ������ƽ̨�������е�һ���֡�
*		 4.���������Զ���¼������Ϣ�Ĺ��ܡ�
*		 5.���������ǰ������䣨�ӻ������͵�ַ��ʼ���䣩���ǰ��շ����䡣
*	��ǰ�汾��1.0
*	�� �ߣ���ΰ
*	������ڣ�2009-5-24
*
*	ȡ���汾��CSerailEx V0.5
*	�� �ߣ���ΰ
*	������ڣ�2008-12-31
*/


#ifndef _FILE_STP_SERIAL_H__
#define _FILE_STP_SERIAL_H__


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "process.h"
#include "stpDefine.h"

//���ڽ��ջ���������
#define STP_SERAIL_MAX_SIZE_RCV_BUFF					16384		/*16K BYTES*/

//��֡��������
#define STP_SERAIL_FRAME_HEAD						(BYTE)0x02		/*֡ͷ*/   
#define STP_SERAIL_FRAME_TAIL						(BYTE)0x03		/*֡β*/    
#define STP_SERAIL_FRAME_KEY_WORD					(BYTE)0x10		/*ת���ַ�1*/  
#define STP_SERAIL_FRAME_KEY_OFFSET					(BYTE)0x80		/*ת���ַ�2*/  

//������

//��Чֵ
#define INVALID_COM									-1				/*��Ч���ڶ˿�*/			

/*
����ԭ��:UINT __stdcall stpTP_SerialRcv(LPVOID IN pParam)
����˵��:
	LPVOID IN pParam						Ҫ�����̵߳Ĵ������ָ�룬����ǰ���ָ�룬�˺������ⲻ�ɼ���
											ʹ��ʱ��Ҫ����ǿ��ת��
ʹ�õ���ȫ�ֱ�����
��������:
	���մ���Ĺ��ܣ�����������öԽ��յ��Ĵ������ݽ��н��������Խ��еĽ�����CRC16��CRC32��֡ͷ֡β
	����ѡ��������һ֡����������Լ��ַ�ת�崦��ȡ������ʽΪ����ָ��
����ֵ:
	�߳�������������0���쳣�˳����ش�����
*/
UINT __stdcall stpTP_SerialRcv(LPVOID IN pParam);

class AFX_EXT_CLASS CStpSerial
{

public:

	/*
	����ԭ��:CSerialEx(int IN nCycleLen = 200)
	����˵��:
		int IN nCycleLen			���ڽ����̵߳���ѯ����
	ʹ�õ���ȫ�ֱ�����
	��������:
		���캯�����ɳ�ʼ����ѯ����
	����ֵ:
		��
	*/
	CStpSerial(int IN nCycleLen = 200);//Ĭ�����ڳ���200ms


	/*
	����ԭ��:~CSerialEx(void)
	����˵��:
	ʹ�õ���ȫ�ֱ�����
	��������:
		����������Ŀǰ����
	����ֵ:
		��
	*/
	~CStpSerial(void);

	/*
	����ԭ��:Open(IN HWND hwnd, IN DWORD (*pFuncRcvCallback)(BYTE*, int, LPVOID), LPVOID IN pParam,
					   IN int nPort, IN int nBaud, IN int nData, IN int nParity, IN int nStop)
	����˵��:
		hwnd				��ǰ����ľ�������ڱ�Ҫ����Ϣ���ݡ�
		pFuncRcvCallback	���մ������ĺ���ָ�룬���˺���ΪNULLʱ������������ʱ�ӡ�
							pFuncRcvCallback�Ĳ�������������һ��BYTE*�ǽ��յ�������һ֡�Ļ�������ַ���ڶ���int�ǽ��յ�������һ֡��
							���ĳ��ȣ�������LPVOID�����洫�ݽ���pParam
		pParam				Ҫ���ݵ����ڽ����߳���Ĳ�����������ΪpFuncRcvCallback�е��������
		nPort				�˿ں�
		nBaud			    ��������
		nData				����λ		  1-5 = 4-9
		nParity				��żУ��λ	  0-4=None,Odd,Even,Mark,Space
		nStop				ֹͣλ		  0,1,2 = 1, 1.5, 2
	ʹ�õ���ȫ�ֱ�����
	��������:
		��ָ���Ĵ����豸�������б�Ҫ�ĳ�ʼ��������
		���pFuncRcvCallbackΪNULL�Ļ�����ô���������߳̽��պ������û����Ҫ���մ�������ʱ���迪��ʱ�ӻ��߳������Ե��ý��պ���ReadData��
		���pFuncRcvCallback��ΪNULL�Ļ�����ô������Զ�����һ���߳̽��պ�������ʱ�û�����������pFuncRcvCallback��ɣ�ÿ�յ�һ֡
		���������ݣ��˺������ᱻ����һ�Ρ�����һ֡���жϱ�׼��ʼ��02����03���м���ת���ַ�10����ʱ�û��������ReadData����ReadData��Ч����
	����ֵ:�ɹ�����1��ʧ�ܷ���0
	*/
	BOOL Open(IN HWND hwnd, IN DWORD (*pFuncRcvCallback)(BYTE*, int, LPVOID), LPVOID IN pParam = NULL,
			   IN int nPort = 1, IN int nBaud = 9600, IN int nData = 4, IN int nParity = 0, IN int nStop = 0);

	/*
	����ԭ��:Close( void )
	����˵��:
		��
	ʹ�õ���ȫ�ֱ�����
	��������:�رմ����豸
	����ֵ:�ɹ�����1
	*/
	BOOL Close(void);

	/*
	����ԭ��:int ReadDataWaiting(void)
	����˵��:
		��
	ʹ�õ���ȫ�ֱ�����
	��������:
		��ȡ���ݽ��ջ������еĽ������ݵĳ��ȡ�������������
	����ֵ:
		���ؽ��յ����ݵĳ��ȡ�-1��ʾ����ʱ���ִ���
	*/
	int ReadDataWaiting(void);

	/*
	����ԭ��:DWORD ReadData(BYTE OUT *pbBuffer, DWORD IN dwLimit)
	����˵��:
		OUT void *pbBuffer				�������ݻ�����
		IN DWORD dwLimit			    �������ݵĳ��ȣ�һ�����������ݻ������ĳ���
	ʹ�õ���ȫ�ֱ�����
	��������:��ȡ���ڽ��յ�����Ϣ
	����ֵ:dwBytesRead ���ش��ڶ�������������ʧ�ܷ���0
	*/
	DWORD ReadData(BYTE OUT *pbBuffer, DWORD IN dwLimit);

	/*
	����ԭ��:DWORD SendData(const BYTE IN *pbBuffer, int IN nSize)
	����˵��:
		IN const char *pbBuffer					�������ݻ�����
		IN int nSize			                �������ݵĳ���
	ʹ�õ���ȫ�ֱ�����
	��������:���ڷ�������
	����ֵ:���ش��ڷ��͵���������ʧ�ܷ���0
	*/
	DWORD SendData(const BYTE IN *pbBuffer, int IN nSize);

 	/*
	����ԭ��:BOOL IsOpened(void)
	����˵��:
	ʹ�õ���ȫ�ֱ�����
	��������:
		�����жϴ����Ƿ��Ѿ��򿪡�
	����ֵ:���ش��ڷ��͵���������ʧ�ܷ���0
	*/
    BOOL IsOpened(void);

 	/*
	����ԭ��:BOOL GetPortIndex(void)
	����˵��:
	ʹ�õ���ȫ�ֱ�����
	��������:
		���ڻ�ȡ��ǰ���ڵĶ˿ں�
	����ֵ:
		��ǰ���ڵĶ˿ںš���Ч��δ��ʱ����-1.
	*/
    int GetPortIndex(void);

 	/*
	����ԭ��:void SetCycleLen(int IN nCycleLen)
	����˵��:
		int IN nCycleLen	Ҫ�趨�����ڳ���
	ʹ�õ���ȫ�ֱ�����
	��������:
		�����趨���ڲɼ����ݵ���ѯ����
	����ֵ:
	*/
    void SetCycleLen(int IN nCycleLen);

 	/*
	����ԭ��:void SetCrcType(stpCrcType IN stType = CrcType_16)
	����˵��:
		stpCrcType IN stType				Ҫ�趨��Crc����
	ʹ�õ���ȫ�ֱ�����
	��������:
		��������Crc�����ͣ�ʹ��16λCRC����32λCRC
	����ֵ:
	*/
    void SetCrcType(stpCrcType IN stType = CrcType_16);

 	/*
	����ԭ��:void SetCrcMode(BOOL IN boCrcValid, BOOL IN boBigEnddian = TRUE)
	����˵��:
		BOOL IN boCrcValid					��Ч��־�����TRUE��ʾCRC��Ч�������ʾCRC��Ч��CRC��Чʱ������֡�ͽ�֡ʱ�Զ�
											ʹ��ѡ����CRC���͡�
		BOOL IN boBigEnddian				�ֽ�˳�����TRUE��ʾ���ֽ���ǰ��FALSE��ʾ���ֽ���ǰ
	ʹ�õ���ȫ�ֱ�����
	��������:
		��������Crc��ģʽ�������Ƿ�����CRC�Լ�CRC�ڴ���ʱ���ֽ�˳��
	����ֵ:
	*/
    void SetCrcMode(BOOL IN boCrcValid, BOOL IN boBigEnddian = TRUE);

  	/*
	����ԭ��:void SetTransferMode(BOOL IN boReverseTransfer = FALSE)
	����˵��:
		BOOL IN boReverseTransfer		�Ƿ����䡣���TRUE����ӻ�����������ֽڿ�ʼ���䣬����ӻ�����������ֽڿ�ʼ����
	ʹ�õ���ȫ�ֱ�����
	��������:
		��������Crc��ģʽ�������Ƿ�����CRC�Լ�CRC�ڴ���ʱ���ֽ�˳��
	����ֵ:
	*/
    void SetTransferMode(BOOL IN boReverseTransfer = FALSE);

	/*
	����ԭ��:void SetAutoRecord(BOOL IN boValid = TRUE)
	����˵��:
		BOOL IN boValid					�Ƿ��Զ���¼�շ���Ϣ��TRUEΪ�Զ���¼��FALSEΪ����¼
	ʹ�õ���ȫ�ֱ�����
	��������:
		���������Ƿ��Զ���¼�շ���Ϣ��ȫ�������C:/StpSerialDebug�£��Դ���ʱ��Ϊ�ļ�����
	����ֵ:
	*/
    void SetAutoRecord(BOOL IN boValid = TRUE);

	/*
	����ԭ��:BOOL IsFrameCrcOK(const BYTE IN *pbFrameBuff, WORD IN wFrameLen)
	����˵��:
		const BYTE IN *pbFrameBuff				Ҫ���CRC��һ֡���ĵ�����
		WORD IN wFrameLen						֡����
	ʹ�õ���ȫ�ֱ�����
	��������:
		�ж����ڱ��ĵ�CRC�Ƿ���ȷ������CRC�����ͺ�����ģʽ�����жϡ����ĵ�CRC����������������ĸ��ֽڡ�
	����ֵ:
		�������CRC��ȷ����ô����TRUE�����򷵻�FALSE
	*/
    BOOL IsFrameCrcOK(const BYTE IN *pbFrameBuff, WORD IN wFrameLen);

	//�̺߳�����ʹ�õı���
	DWORD (*m_pFuncRcvProcess)(BYTE*, int, LPVOID);//����������ݵĺ���ָ��
	BOOL m_boCrcValid;//Ĭ��CRC��Ч
	BOOL m_boReverseTransfer;//����ʱ�Ƿ�ת˳��
	int m_nCycleLen;//��ѯ���ڳ���
	BOOL m_boCrcBigEnddian;//���ֽ���ǰ�Ŀ��Ʊ���	TRUEΪ���ֽ���ǰ��FALSEΪ���ֽ���ǰ
	stpCrcType m_stCrcType;//Crc���ͣ�16λCrc����32λCRC
	BOOL m_boAutoRecord;//�Զ���¼������Ϣ�������ڵ��շ���Ϣ��ȫ�������C:/StpSerialDebug�£��Դ���ʱ��Ϊ�ļ���
	int m_nRecordFileIndex;//�Զ���¼�ļ������
	LPVOID m_pParam;//������������ʱҪ���ݳ����Ĳ���
	DWORD m_dwMaxLenOfFrame;//֡��󳤶�
	BOOL m_boTPSerialRcvEnded;//���ڽ����߳��˳����Ʊ��������ڰ�ȫ�Ĺض��߳�

private:
	/*
	����ԭ��:WriteCommByte(BYTE bWriteByte)
	����˵��:
		IN  BYTE bWriteByte        Ҫд�봮�ڵ�����
	ʹ�õ���ȫ�ֱ�����
	��������:���ֽ�д�봮��
	����ֵ:�ɹ�����1
	*/
	BOOL WriteCommByte(BYTE bWriteByte);


	/*
	����ԭ��:
	����˵��:
		IN const BYTE* pbInBuffer        ��Ҫ��֡��ԭʼ����
		IN int nBufferSize			    ԭʼ���ݵĳ���
		OUT BYTE* pbSendBuff             ����֡������
		OUT WORD &wSendSize             ����֡�ĳ���
	ʹ�õ���ȫ�ֱ�����
	��������:��ԭʼ���ݽ�����֡��ת�崦��
	����ֵ:��
	*/
	void BuildFrame(const BYTE* pbInBuffer, int nBufferSize, BYTE* pbSendBuff, WORD &wSendSize);

	//�̲߳���
	HANDLE m_hThreadRcv;//�����߳�
	UINT m_nThreadRcv;//�����߳�

	//���ò���
	HANDLE m_hIDComDev;
	OVERLAPPED m_OverlappedRead, m_OverlappedWrite;
	BOOL m_boOpened;//���ڴ����ı�־
	BYTE m_pbRcvDATA[STP_SERAIL_MAX_SIZE_RCV_BUFF];//���ڽ��ջ�����
    DWORD m_dwReceiveNum;//���ڽ��ջ�����
	int m_nPort;//���ڶ˿ں�
	HWND m_hwnd;//�������Ĵ�����
};

#endif
