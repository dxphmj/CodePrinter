#pragma once

#include "stdafx.h "
#include "xml\tinyxml.h"
#include "xml\tinystr.h"
#include <string>

using namespace std;

class CDealXml
{
public:
	CDealXml(void);
	~CDealXml(void);
public:
	CString ReadXml(CString FileName,CString Name,CString FaultStr,CString Path);//��XMLĳ��
	bool WriteXml(CString FileName,CString Name,CString Value,CString Path);//����XMLĳ��

	//��;����ʮ������ת��Ϊʮ����byte��
	//���룺Hex(ʮ��������)
	//�����������ͣ�String
	//�����HEX_to_DECbyte(ʮ������)
	//����������ͣ�Long
	//����������ΪFF,����������Ϊ255
	BYTE HEX_to_DECbyte(CString strHex);//

};
