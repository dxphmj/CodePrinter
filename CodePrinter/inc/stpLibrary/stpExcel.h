/*
*	Copyright 2009,
*	All rights reserved.
*	
*	�ļ����ƣ�stpUDPSocket.h
*	�ļ���ʶ: �������ƽ̨��������ʵ��Excel�ļ���д�����ͷ�ļ�
*	ժҪ��
*		�������Ҫ������:
*		 1.��װ��Excel9�Ĳ��ֲ���������ʹ��Excel����ȡExcel���ر�Excel������Excel�ļ��������
*		 2.��װ�˹رճ���򿪵�Excel���̵Ĺ��ܣ����Ǵ˹��ܴ���С©�������޷�ʶ���ĸ�EXCEL�������ɳ���򿪵ġ�����Ĵ���ʽ��
*		   ��EXCEL����ǰ���������Ѿ����ڵ�EXCEL��֮������ڹر�EXCELʱ��ر�����EXCEL���̡������ȱ��������ڳ����EXCEL��
*		   �ر�EXCEL���û������д�����һ��EXCEL���̡���ô�ᵼ�³���ر�EXCEL����ʱ����Ĺر��û��򿪵�EXCEL���̡�
*		 3.��װ��ͨ��һ������EXCEL�ļ�Ϊģ�洴��һ��EXCEL�ļ��Ĺ��ܡ�
*		 4.���Բ���ָ����Sheet�е����ݣ�����CSV��ʽ���ļ������ܴ���ġ�
*		 5.�Ե�Ԫ��Ķ�д������װ�˶��ֽӿڣ������û�������
*	��ǰ�汾��1.0
*	�� �ߣ���ΰ
*	������ڣ�2009-6-20
*
*	ȡ���汾��
*	�� �ߣ�
*	������ڣ�
*/
//////////////////////////////////////////////////////////////////////

#ifndef _FILE_STP_EXCEL_H__
#define _FILE_STP_EXCEL_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//----------------------����ͷ�ļ�-----------------------------------------
#include "stpDefine.h"
#include "excel9.h"


//----------------------�궨��-----------------------------------------
//�����붨��
#define STP_EXCEL_ERR_SUCCESS						0				//�ɹ�
#define STP_EXCEL_ERR_EXCEL_UNKNOWN					0xFFFF0100		//δ֪����
#define STP_EXCEL_ERR_INVALID_FILE_NAME				0xFFFF0101		//��Ч�ļ���
#define STP_EXCEL_ERR_INVALID_SHEET_NAME			0xFFFF0102		//��Ч����
#define STP_EXCEL_ERR_FILE_CLOSED					0xFFFF0103		//�ļ�δ��
#define STP_EXCEL_ERR_SHEET_CLOSED					0xFFFF0104		//��δ��
#define STP_EXCEL_ERR_EXCEL_MISSED					0xFFFF0105		//δ��װEXCEL����
#define STP_EXCEL_ERR_CANNOT_OPEN_TWO_EXCEL_APP		0xFFFF0106		//�޷�ͬʱ������Excel����
#define STP_EXCEL_ERR_CELL_ABNORMAL					0xFFFF0107		//��Ԫ���쳣

//Excel��д�������˵��
class AFX_EXT_CLASS CstpExcel  
{
public:
	/*
	CstpExcel(CHAR IN szAppCaption[] = NULL)
	����˵��:
		CHAR IN szAppCaption					Ӧ�ó������ƣ����ڶ��ⵯ����Ϣʱ�Ĵ�������˵��
	ʹ�õ���ȫ�ֱ�����
	��������:���캯��,��ʼ����̬�⡣
	����ֵ:��
	*/
	CstpExcel(CHAR IN szAppCaption[] = NULL);

	/*
	����ԭ��:virtual ~CstpExcel(void)
	����˵��:
	ʹ�õ���ȫ�ֱ�����
	��������:��������,���б�Ҫ�Ŀռ��ͷŹ���
	����ֵ:��
	*/
	virtual ~CstpExcel(void);

	/*
	����ԭ��:void SetNoMessage(BOOL IN boYes = TRUE)
	����˵��:
		BOOL IN boYes						���ò������κ���Ϣ
	ʹ�õ���ȫ�ֱ�����
	��������:
		���ý��õ�����Ϣ���ܡ����ΪTRUE������õ�����Ϣ��������������Ϣ
	����ֵ:
		��
	*/
	void SetNoMessage(BOOL IN boYes = TRUE);

	/*
	����ԭ��:DWORD OpenFile(const CHAR IN szFileName[], const CHAR IN szSheetName[] = NULL)
	����˵��:
		const CHAR IN szFileName[]				Excel�ļ����ļ���������·��
		const CHAR IN szSheetName[]				Excel�ļ���Ҫ�򿪵ı����������NULL��Ĭ��Ϊ��
	ʹ�õ���ȫ�ֱ�����
	��������:ͨ���������·�����ļ�������ָ���ļ���Ȼ���ָ����δָ���Ļ���Ĭ�ϴ��ļ������ı����Ա�����Ķ�д��Ԫ��
	����ֵ:
		�ɹ�����0(SHEET�Ѿ���)��ʧ�ܷ��ش����롣
	*/
	DWORD OpenFile(const CHAR IN szFileName[], const CHAR IN szSheetName[] = NULL);

	/*
	����ԭ��:DWORD OpenFileEx(const CHAR IN szFileCaption[], const CHAR IN szSheetName[] = NULL)
	����˵��:
		const CHAR IN szFileCaption[]			Excel�ļ����ļ�����������·��
		const CHAR IN szSheetName[]				Excel�ļ���Ҫ�򿪵ı����������NULL��Ĭ��Ϊ��
	ʹ�õ���ȫ�ֱ�����
	��������:
		ͨ�����벻����·�����ļ������ھ�����ѯ�������·����õ�ǰ·����ƴ�ӳ�����·������ָ���ļ���
		Ȼ���ָ����δָ���Ļ���Ĭ�ϴ��ļ������ı����Ա�����Ķ�д��Ԫ��
	����ֵ:
		�ɹ�����0(SHEET�Ѿ���)��ʧ�ܷ��ش����롣
	*/
	DWORD OpenFileEx(const CHAR IN szFileCaption[], const CHAR IN szSheetName[] = NULL);

	/*
	����ԭ��:DWORD CreateFileIndirect(const CHAR IN szNewFileName[], const CHAR IN szSrcFileName[])
	����˵��:
		const CHAR IN szNewFileName[]			���ļ���
		const CHAR IN szSheetName[]				Դ�ļ���
	ʹ�õ���ȫ�ֱ�����
	��������:
		ͨ��ָ����szSrcFileName��������ʽΪԴ�ļ���ʽ��szNewFileName���ļ����˺�����������ļ���
		�����ڴ���ʱ��Ҫ����Excel�಻�ܴ��κ������ļ���
		�˺����ڵ���Excel�ļ�ʱ�ǳ����á�
	����ֵ:
		�����ɹ�����0��ʧ�ܷ��ش����롣
	*/
	DWORD CreateFileIndirect(const CHAR IN szNewFileName[], const CHAR IN szSrcFileName[]);

	/*
	����ԭ��:DWORD ChangeSheet(const CHAR IN szNewSheetName[])
	����˵��:
		const CHAR IN szNewSheetName[]				Ҫ�򿪵��µ�Sheet��	
	ʹ�õ���ȫ�ֱ�����
	��������:
		ͨ�������µı������ر�ԭ�б���ͬʱ���µı��������ʧ�ܣ�Ҳ�������¿���ԭ�б���
	����ֵ:
		�ɹ�����0��ʧ�ܷ��ش����롣
	*/
	DWORD ChangeSheet(const CHAR IN szNewSheetName[]);

	/*
	����ԭ��:BOOL IsFileOpen(void)
	����˵��:
	ʹ�õ���ȫ�ֱ�����
	��������:
		����Excel�ļ��Ƿ��Ѵ򿪡�����ֻ����ͬʱ��һ���ļ���������ͬʱ�򿪶���ļ���
	����ֵ:
		�Ѵ򿪷���TRUE�����򷵻�FALSE��
	*/
	BOOL IsFileOpen(void);

	/*
	����ԭ��:BOOL IsSheetOpen(void)
	����˵��:
	ʹ�õ���ȫ�ֱ�����
	��������:
		���ر��Ƿ��Ѵ򿪡�����ֻ����ͬʱ��һ������������ͬʱ�򿪶���������⣬��д��Ԫ���������ض��ı���
		����δ��ʱ���޷���д��Ԫ��
	����ֵ:
		�Ѵ򿪷���TRUE�����򷵻�FALSE��
	*/
	BOOL IsSheetOpen(void);

	/*
	����ԭ��:void CloseFile(void)
	����˵��:
	ʹ�õ���ȫ�ֱ�����
	��������:
		�ر��ļ����ͷű�Ҫ����Դ���Լ��ر��Ѿ�������Excel�ļ���
	����ֵ:
		��
	*/
	void CloseFile(void);

	/*
	����ԭ��:void SaveFile(void)
	����˵��:
	ʹ�õ���ȫ�ֱ�����
	��������:
		�����ļ������Ѿ�д������ݱ��浽�ļ��С�
	����ֵ:
		��
	*/
	void SaveFile(void);

	/*
	����ԭ��:DWORD Write(int IN nRow, int IN nCol, int IN nValue)
	����˵��:
		int IN nRow							��Ԫ���к�
		int IN nCol							��Ԫ���к�
		int IN nValue						��Ԫ���ֵ(int��)
	ʹ�õ���ȫ�ֱ�����
	��������:
		���nRow�е�nCol�еĵ�Ԫ��д��ֵΪnValue��int������
	����ֵ:
		�ɹ�����0��ʧ�ܷ��ش����롣
	*/
	DWORD Write(int IN nRow, int IN nCol, int IN nValue);

	/*
	����ԭ��:DWORD Write(int IN nRow, int IN nCol, DWORD IN dwValue)
	����˵��:
		int IN nRow							��Ԫ���к�
		int IN nCol							��Ԫ���к�
		DWORD IN dwValue					��Ԫ���ֵ(int��)
	ʹ�õ���ȫ�ֱ�����
	��������:
		���nRow�е�nCol�еĵ�Ԫ��д��ֵΪdwValue��DWORD������
	����ֵ:
		�ɹ�����0��ʧ�ܷ��ش����롣
	*/
	DWORD Write(int IN nRow, int IN nCol, DWORD IN dwValue);

	/*
	����ԭ��:DWORD Write(int IN nRow, int IN nCol, double IN dfValue)
	����˵��:
		int IN nRow							��Ԫ���к�
		int IN nCol							��Ԫ���к�
		double IN dfValue					��Ԫ���ֵ(double��)
	ʹ�õ���ȫ�ֱ�����
	��������:
		���nRow�е�nCol�еĵ�Ԫ��д��ֵΪdfValue��double�͸�����
	����ֵ:
		�ɹ�����0��ʧ�ܷ��ش����롣
	*/
	DWORD Write(int IN nRow, int IN nCol, double IN dfValue);

	/*
	����ԭ��:DWORD Write(int IN nRow, int IN nCol, CString IN strValue)
	����˵��:
		int IN nRow							��Ԫ���к�
		int IN nCol							��Ԫ���к�
		CString IN strValue					��Ԫ���ֵ(CString���ַ���)
	ʹ�õ���ȫ�ֱ�����
	��������:
		���nRow�е�nCol�еĵ�Ԫ��д��ֵΪstrValue��CString���ַ���
	����ֵ:
		�ɹ�����0��ʧ�ܷ��ش����롣
	*/
	DWORD Write(int IN nRow, int IN nCol, CString IN strValue);

	/*
	����ԭ��:DWORD Write(int IN nRow, int IN nCol, const CHAR IN szValue[])
	����˵��:
		int IN nRow							��Ԫ���к�
		int IN nCol							��Ԫ���к�
		const CHAR IN szValue[]				��Ԫ���ֵ(const CHAR���ַ���)
	ʹ�õ���ȫ�ֱ�����
	��������:
		���nRow�е�nCol�еĵ�Ԫ��д��ֵΪszValue��const CHAR���ַ���
	����ֵ:
		�ɹ�����0��ʧ�ܷ��ش����롣
	*/
	DWORD Write(int IN nRow, int IN nCol, const CHAR IN szValue[]);

	/*
	����ԭ��:DWORD Write(int IN nRow, int IN nCol, const BYTE IN pbValue[], int IN nLen)
	����˵��:
		int IN nRow							��Ԫ���к�
		int IN nCol							��Ԫ���к�
		const BYTE IN pbValue[]				Ҫ�洢�ڵ�Ԫ���е�ԭʼֵ(const BYTE������)��д��ʱд��ʮ�����Ƶ��ַ���
		int IN nLen							������Ч���ݴ�С						
	ʹ�õ���ȫ�ֱ�����
	��������:
		���nRow�е�nCol�еĵ�Ԫ��д�볤��ΪnLen��pbValue�����ʮ��������ʽ���Կո�Ϊ�ָ���
	����ֵ:
		�ɹ�����0��ʧ�ܷ��ش����롣
	*/
	DWORD WriteHex(int IN nRow, int IN nCol, const BYTE IN pbValue[], int IN nLen);

	/*
	����ԭ��:DWORD Read(int IN nRow, int IN nCol, int OUT *pnValue)
	����˵��:
		int IN nRow							��Ԫ���к�
		int IN nCol							��Ԫ���к�
		int IN *pnValue						��Ԫ���ֵ(int��ָ��)
	ʹ�õ���ȫ�ֱ�����
	��������:
		��ȡ��nRow�е�nCol�еĵ�Ԫ��洢��int��������ֵ���洢��pnValue�С�
	����ֵ:
		�ɹ�����0��ʧ�ܷ��ش����롣
	*/
	DWORD Read(int IN nRow, int IN nCol, int OUT *pnValue);

	/*
	����ԭ��:DWORD Read(int IN nRow, int IN nCol, DWORD OUT *pdwValue)
	����˵��:
		int IN nRow							��Ԫ���к�
		int IN nCol							��Ԫ���к�
		DWORD OUT *pdwValue					��Ԫ���ֵ(DWORD��ָ��)
	ʹ�õ���ȫ�ֱ�����
	��������:
		��ȡ��nRow�е�nCol�еĵ�Ԫ��洢��DWORD��������ֵ���洢��pdwValue�С�
	����ֵ:
		�ɹ�����0��ʧ�ܷ��ش����롣
	*/
	DWORD Read(int IN nRow, int IN nCol, DWORD OUT *pdwValue);

	/*
	����ԭ��:DWORD Read(int IN nRow, int IN nCol, double OUT *pdfValue)
	����˵��:
		int IN nRow							��Ԫ���к�
		int IN nCol							��Ԫ���к�
		double OUT *pdfValue				��Ԫ���ֵ(double��ָ��)
	ʹ�õ���ȫ�ֱ�����
	��������:
		��ȡ��nRow�е�nCol�еĵ�Ԫ��洢��double�͸�������ֵ���洢��pdfValue�С�
	����ֵ:
		�ɹ�����0��ʧ�ܷ��ش����롣
	*/
	DWORD Read(int IN nRow, int IN nCol, double OUT *pdfValue);

	/*
	����ԭ��:DWORD Read(int IN nRow, int IN nCol, CString OUT *pstrValue)
	����˵��:
		int IN nRow							��Ԫ���к�
		int IN nCol							��Ԫ���к�
		CString OUT *pstrValue				��Ԫ���ֵ(double��ָ��)
	ʹ�õ���ȫ�ֱ�����
	��������:
		��ȡ��nRow�е�nCol�еĵ�Ԫ��洢��CString���ַ�����ֵ���洢��pstrValue�С�
	����ֵ:
		�ɹ�����0��ʧ�ܷ��ش����롣
	*/
	DWORD Read(int IN nRow, int IN nCol, CString OUT *pstrValue);

	/*
	����ԭ��:DWORD Read(int IN nRow, int IN nCol, CHAR OUT szValue[])
	����˵��:
		int IN nRow							��Ԫ���к�
		int IN nCol							��Ԫ���к�
		CHAR OUT szValue[]					��Ԫ���ֵ(CHAR��ָ��)
	ʹ�õ���ȫ�ֱ�����
	��������:
		��ȡ��nRow�е�nCol�еĵ�Ԫ��洢��CHAR���ַ�����ֵ���洢��szValue�С�
	����ֵ:
		�ɹ�����0��ʧ�ܷ��ش����롣
	*/
	DWORD Read(int IN nRow, int IN nCol, CHAR OUT szValue[]);

	/*
	����ԭ��:DWORD Read(int IN nRow, int IN nCol, BYTE OUT pbValue[], int IN *pnLen)
	����˵��:
		int IN nRow							��Ԫ���к�
		int IN nCol							��Ԫ���к�
		BYTE OUT pbValue[]					��Ԫ���ֵ(��ʮ�������ı���ʽ�洢�ģ�ת�����ֽ���ʽ���ֵ)
		int OUT *pnLen						�ֽ���ʽ��ֵ�ĳ���
	ʹ�õ���ȫ�ֱ�����
	��������:
		��ȡ��nRow�е�nCol�еĵ�Ԫ��洢��CHAR���ַ�����ֵ��Ȼ��ת���ɸ�ʮ�������ı���ʽ��Ӧ���ֽ���ʽ�����洢������
		pbValue��������pnLen��
	����ֵ:
		�ɹ�����0��ʧ�ܷ��ش����롣
	*/
	DWORD ReadHex(int IN nRow, int IN nCol, BYTE OUT pbValue[], int OUT *pnLen);

	/*
	����ԭ��:int GetValidRowCount(void)
	����˵��:
	ʹ�õ���ȫ�ֱ�����
	��������:
		��ȡ�Ѿ��򿪵ĵ�ǰSheet�е���Ч������
	����ֵ:
		�ɹ�������Ч��������ʧ�ܷ���-1��
	*/
	int GetValidRowCount(void);

	/*
	����ԭ��:int GetValidColumnCount(void)
	����˵��:
	ʹ�õ���ȫ�ֱ�����
	��������:
		��ȡ�Ѿ��򿪵ĵ�ǰSheet�е���Ч������
	����ֵ:
		�ɹ�������Ч��������ʧ�ܷ���-1��
	*/
	int GetValidColumnCount(void);

	BOOL m_boNoMessage;//���õ�����Ϣ
private:
	/*
	����ԭ��:BOOL IsExcelAppExist(void)
	����˵��:
	ʹ�õ���ȫ�ֱ�����
	��������:
		�ж��Ƿ���Excel���������С�������ڣ���ô����TRUE�����򷵻�ʧ�ܡ�
	����ֵ:
		������ڣ���ô����TRUE�����򷵻�FALSE��
	*/
	BOOL CstpExcel::IsExcelAppExist(void);

	/*
	����ԭ��:void CloseAllExistExcelApp(void)
	����˵��:
	ʹ�õ���ȫ�ֱ�����
	��������:
		�ر������Ѿ����ڵ�ExcelApp.
	����ֵ:
		��
	*/
	void CloseAllExistExcelApp(void);

	CHAR m_szAppCaption[MAX_PATH];//Ӧ�ó��������

	CHAR m_szFileName[MAX_PATH];//�ļ�������·����
	CHAR m_szSheetName[MAX_PATH];//����
	BOOL m_boIsFileOpened;//�ļ��Ƿ񱻴�
	BOOL m_boIsSheetOpened;//���Ƿ񱻴�

	//Excel��д�ò���
	_Application  m_ExcelApp;//����ʵ��
	Workbooks m_wbsMyBooks;//��������ʵ��
	_Workbook m_wbMyBook;//������ʵ��
	Worksheets m_wssMysheets;//����ʵ��
	_Worksheet m_wsMysheet;//��ʵ��
	Range m_rgMyRge;//��Ԫ��ʵ��
};

#endif // !defined(AFX_STPEXCEL_H__F4914924_7E51_4764_AC20_0F6C35EA10F0__INCLUDED_)
