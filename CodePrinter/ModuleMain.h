#pragma once
#include <stdio.h>
#include "xml\tinyxml.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

UINT TTLcomLoop(LPVOID pParam);
BYTE* VEC2ARRAY(vector<BYTE> tempVec,int n);
CString GETnBIT_from_bytReadData(int I , int m , int n );
CString GETnBIT_from_bytStatus(int I , int m , int n );
class StatusClass
{
public:
	StatusClass(void){			
		 ctr0X00bit0  = 0 ;//'0�ػ���1����
		 ctr0X00bit1  = 0 ;//'0������1����
		 ctr0X00bit2  = 0 ;//'0����ģʽ��1ѹ��ģʽ
		 ctr0X00bit3  = 0 ;//'0�رã�1����
		 ctr0X00bit5  = 0 ;//'�����λ�����ϱ�־λ��0ƽʱ��1�����λ������

		//'����0X01
		 ctr0X01bit0  = 0 ;//'0�����죬1������
		 ctr0X01bit1  = 0; //'0�ع�ī����1����ī��
		 ctr0X01bit2  = 0; //'0����������1��������
		 ctr0X01bit3  = 0 ;//'0����ϴ����1����ϴ��
		 ctr0X01bit4  = 0; //'0���ܼ�����1���ܼ���
		 ctr0X01bit5  = 0; //'0��ճ�ȷ���1��ճ�ȷ�
		 ctr0X01bit6  = 0; //'0�س�ϴ����1����ϴ��

		//'����0X02
		 ctr0X02bit0  = 0; //'�ػ��ռ�⹦�ܣ�1Ϊ�رռ�⣬0Ϊ�������
		 ctr0X02bit1  = 0; //'��ī�߹��ܣ�1Ϊ�ر�ī�ߣ�0Ϊ����ī��
		 ctr0X02bit2  = 0; //'�����ܼ���0�أ�1��
		 ctr0X02bit3  = 0; //'����ճ�ȣ�0�أ�1��
		 ctr0X02bit4  = 0; //'��ϴ���죬0�أ�1��
		 ctr0X02bit5  = 0; //'�������죬0�أ�1��
		 ctr0X02bit6  = 0; //'ī·У����0�أ�1��
		 ctr0X02bit7  = 0; //'ī·ѭ����0�أ�1��

		//'����0X03
		 ctr0X03bit0  = 0; //'����ӡ���ܣ�1����
		 ctr0X03bit1  = 0; //'�����ش�ӡ����Ҫ����ȷ�ϸù��ܣ�
		 ctr0X03bit3  = 0; //'��ѹ���أ�1Ϊ����
		 ctr0X03bit6  = 0; //'����ģʽ��0Ϊ�ֶ���1Ϊ�Զ� (��λ��Ĭ��Ϊ1)

		//'����
		 bytModuStep  = 10; //'�̶����ѵ�ѹ����
	}
	~StatusClass(){}
	void getstatu();
	void byStatusFromSlaveState();

	void download_inksystem_control00();
	void download_inksystem_control01();
	void download_inksystem_control02();
	void download_inksystem_control03();
public:
	bool staSysRea, staSysBus, staBumMod, staBum, staHarFin, staCleFauFin;
		bool staNozVal, staFeeVal, staBleVal, staFluVal, staSolVal, staVisVal, staWasVal ;
		bool staInkFloSenOff, staCloInkLin, staAddSol, staDetVis, staWasNoz, staSucNoz, staAdjInkLin, staInkCir ;
		bool staInkTemSenFau, staPriHeaTemFau, staBumSpeOveFau, staPreOveFau, staVisAbnFau, staVisSenFau, staInkFloFau, staPriHeaCle ;
		bool staFanFau, staChaFau, staPhaFau;
		bool staHigVolFau ;
		string staSolLevFau, staInkLevFau, staRFID ;
		bool staPrnting, staHigVolSwi, staActProSen, staProSenFas, staAutModFau, staValFau ;
		bool staPrinted, staRemPrinSwi, staBufFul, staBufRea, staEncDir, staLinFas, staPriHeaHot, staPriHeaHotFau, staSetTimeEna ;
		int staPressure, staBumSpe, staHigVol, staEncFre ;
		BYTE staPriHeaTem, staActVis, staTarVis, staInkLev, staSolLev, staPhase ;
		int staInkTem ;
		int staProCou, staPriCou, staInkLifeTime ;
		BYTE staPixDotNee, staAutModVol ;


			BYTE ctr0X00, ctr0X01, ctr0X02, ctr0X03, ctr0X04 ;
			//'����0X00
			BYTE ctr0X00bit0 ;//'0�ػ���1����
			BYTE ctr0X00bit1   ;//'0������1����
			BYTE ctr0X00bit2   ;//'0����ģʽ��1ѹ��ģʽ
			BYTE ctr0X00bit3   ;//'0�رã�1����
			BYTE ctr0X00bit5   ;//'�����λ�����ϱ�־λ��0ƽʱ��1�����λ������

			//'����0X01
			BYTE ctr0X01bit0   ;//'0�����죬1������
			BYTE ctr0X01bit1 ; //'0�ع�ī����1����ī��
			BYTE ctr0X01bit2  ; //'0����������1��������
			BYTE ctr0X01bit3   ;//'0����ϴ����1����ϴ��
			BYTE ctr0X01bit4 ; //'0���ܼ�����1���ܼ���
			BYTE ctr0X01bit5  ; //'0��ճ�ȷ���1��ճ�ȷ�
			BYTE ctr0X01bit6  ; //'0�س�ϴ����1����ϴ��

			//'����0X02
			BYTE ctr0X02bit0 ; //'�ػ��ռ�⹦�ܣ�1Ϊ�رռ�⣬0Ϊ�������
			BYTE ctr0X02bit1 ; //'��ī�߹��ܣ�1Ϊ�ر�ī�ߣ�0Ϊ����ī��
			BYTE ctr0X02bit2  ; //'�����ܼ���0�أ�1��
			BYTE ctr0X02bit3  ; //'����ճ�ȣ�0�أ�1��
			BYTE ctr0X02bit4  ; //'��ϴ���죬0�أ�1��
			BYTE ctr0X02bit5  ; //'�������죬0�أ�1��
			BYTE ctr0X02bit6 ; //'ī·У����0�أ�1��
			BYTE ctr0X02bit7  ; //'ī·ѭ����0�أ�1��

			//'����0X03
			BYTE ctr0X03bit0  ; //'����ӡ���ܣ�1����
			BYTE ctr0X03bit1  ; //'�����ش�ӡ����Ҫ����ȷ�ϸù��ܣ�
			BYTE ctr0X03bit3  ; //'��ѹ���أ�1Ϊ����
			BYTE ctr0X03bit6  ; //'����ģʽ��0Ϊ�ֶ���1Ϊ�Զ� (��λ��Ĭ��Ϊ1)

			//'����
			BYTE bytModuStep  ; //'�̶����ѵ�ѹ����
			int	bytModuVol, SolLevSum, InkLevSum, LevCoun ;
};
class ModuleMain//ͨ���㷨��
{
public:
	ModuleMain(void);
	~ModuleMain(void);
	LPCWSTR stringToLPCWSTR(std::string orig);
    string WcharToChar(const wchar_t* wp, size_t m_encode = CP_ACP);
	string ReadXml(string xmlFileName,string nameStr,string faultValue,string path);//��
    //bool writeXml(string xmlFileName,string valueStr,string textStr,string path);//��
	bool changeXml(string xmlFileName,string valueStr,string textStr,string path);//��
	void string2tchar(std::string &src, TCHAR* buf);
	string TCHAR2STRING(TCHAR *STR);
   const char* CString2ConstChar(CString str);
   string CString2string(CString csStrData);
public:
	void InitCommMsg();
};
