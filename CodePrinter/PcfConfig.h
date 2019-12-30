#pragma once
#include "DealXml.h"
class CCodePrinterDlg;


class CPcfConfig
{
public:
	CPcfConfig(CCodePrinterDlg* pCodeDlg);
	~CPcfConfig(void);
public:
	CCodePrinterDlg* m_pCodePrinterDlg;
public:

	void get_pcf_from_xml();//�������ļ�PrintConfig.xml��ȡ��һ�δ򿪵������ļ������в������ڽ�������ʾ����
	void download_pcf();//
	int round(double r);

public:
	CString strLABlabForMName;

	CString mypcf0X02_05, mypcf0X06_09, mypcf0X13_16, mypcf0X19_1C;

	//BYTE pcf0X00, pcf0X01, pcf0X02, pcf0X03, pcf0X04, pcf0X05, pcf0X06, pcf0X07, pcf0X08, pcf0X09, 
	//	pcf0X0A, pcf0X13, pcf0X14, pcf0X15, pcf0X16, pcf0X18, pcf0X19, pcf0X1A, pcf0X1B, pcf0X1C;
	////pcf����0X00
	//BYTE pcf0X00bit1_bit0; //�д�����ʽ��0Ϊ������1�࣬1Ϊ������2�࣬2Ϊ�ڲ�һ�е�����������64K/�����ʣ�
	//BYTE pcf0X00bit2; //ͬ�������࣬0��A->B��1:B->A
	//BYTE pcf0X00bit4; //�������У����ڴ�ӡ��������ʱ�Ĵ���0��ӡֹͣ��1 ��ӡ��������ī��û�������
	//BYTE pcf0X00bit5; //��Ʒ���������ã�0 �����ã�1 ���õ��趨ֵ
	//BYTE pcf0X00bit6;//��ӡ���������ã�0 �����ã�1 ���õ��趨ֵ

	////pcf����0X01
	//BYTE pcf0X01bit0; //�Ƿ����õ��ۣ�0Ϊ�رգ�1Ϊ����
	//BYTE pcf0X01bit2; //������Ч��ƽ��0Ϊ�͵�ƽ��1Ϊ�ߵ�ƽ
	//BYTE pcf0X01bit3; //��ӡģʽΪ���λ���������0Ϊ���Σ�1Ϊ����
};
