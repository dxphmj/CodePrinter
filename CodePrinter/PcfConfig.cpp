#include "StdAfx.h"
#include "PcfConfig.h"
#include "resource.h"
#include "CodePrinterDlg.h"
#include "DealXml.h"

CPcfConfig::CPcfConfig(CCodePrinterDlg* pCodeDlg)
{
	m_pCodePrinterDlg = pCodeDlg;
}

CPcfConfig::~CPcfConfig(void)
{
}

void CPcfConfig::get_pcf_from_xml()
{
	CDealXml dealXml;
	CString pcf_currentname,pcf_currentpath;
	//当前或上次打开的配置文件名
	pcf_currentname = dealXml.ReadXml(_T("inksystem.xml"),_T("CurrentName"), _T("Default.pcf"), _T("Storage Card\\System"));
	//当前或上次打开的配置文件的路径
	pcf_currentpath = dealXml.ReadXml(_T("inksystem.xml"),_T("CurrentName"), _T("\Storage Card\System"), _T("Storage Card\\System"));
	bool isFileExit = true;

	if (isFileExit)//如果上次打开的配置文件存在则打开该文件，否则调出默认配置文件
	{
		CString tempstr;
		
		//strLABlabForMName = pcf_currentname;
		////故障停止喷印
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("ErrorStopPrinting"), _T("OFF"), pcf_currentpath);
		////高压（字高）
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("PrintHeight"), _T("70"), pcf_currentpath);
		////喷印方向,,,,决定上位机发送数据时先发前列后尾列，还是先尾列后头列（信息选用通用配置时）
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("Reverse"), _T("OFF"), pcf_currentpath);
		////文字正反,,,,决定上位机列数据是否高低点对调（信息选用通用配置时）
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("Inverse"), _T("OFF"), pcf_currentpath);
		////产线运动方式：固定，可变,,,,默认固定
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("Way"), _T("Fixed"), pcf_currentpath);
		////编码器信号相数
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("EncoderSignal"), _T("2 Phase"), pcf_currentpath);
		////编码器倍频
		//cmbval_pcf_external_fremul.Items.Clear();
		//if ()
		//{
		//}
	}
}

void CPcfConfig::download_pcf()
{

}
