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

	void get_pcf_from_xml();//从配置文件PrintConfig.xml读取上一次打开的配置文件并从中参数并在界面上显示出来
	void download_pcf();//
	int round(double r);

public:
	CString strLABlabForMName;

	CString mypcf0X02_05, mypcf0X06_09, mypcf0X13_16, mypcf0X19_1C;

	//BYTE pcf0X00, pcf0X01, pcf0X02, pcf0X03, pcf0X04, pcf0X05, pcf0X06, pcf0X07, pcf0X08, pcf0X09, 
	//	pcf0X0A, pcf0X13, pcf0X14, pcf0X15, pcf0X16, pcf0X18, pcf0X19, pcf0X1A, pcf0X1B, pcf0X1C;
	////pcf控制0X00
	//BYTE pcf0X00bit1_bit0; //列触发方式：0为编码器1相，1为编码器2相，2为内部一列点数（即等于64K/划速率）
	//BYTE pcf0X00bit2; //同步器反相，0：A->B，1:B->A
	//BYTE pcf0X00bit4; //故障运行，正在打印遇到故障时的处理，0打印停止，1 打印继续，但墨点没有喷出来
	//BYTE pcf0X00bit5; //产品计数器重置，0 不重置，1 重置到设定值
	//BYTE pcf0X00bit6;//打印计数器重置，0 不重置，1 重置到设定值

	////pcf控制0X01
	//BYTE pcf0X01bit0; //是否启用电眼，0为关闭，1为启用
	//BYTE pcf0X01bit2; //电眼有效电平，0为低电平，1为高电平
	//BYTE pcf0X01bit3; //喷印模式为单次还是连续，0为单次，1为连续
};
