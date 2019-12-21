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
	//m_pCodePrinterDlg->
	CString pcf_currentname,pcf_currentpath;
	//当前或上次打开的配置文件名
	pcf_currentname = dealXml.ReadXml(_T("inksystem.xml"),_T("CurrentName"), _T("Default.pcf"), _T("Storage Card\\System"));
	//当前或上次打开的配置文件的路径
	pcf_currentpath = dealXml.ReadXml(_T("inksystem.xml"),_T("CurrentName"), _T("\Storage Card\System"), _T("Storage Card\\System"));
	bool isFileExit = true;

	if (isFileExit)//如果上次打开的配置文件存在则打开该文件，否则调出默认配置文件
	{
		CString tempstr;
		//m_pCodePrinterDlg->m_Confi->m_ConfigPrintModeDlg->
		strLABlabForMName = pcf_currentname;
		//故障停止喷印(虚拟打印)
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ErrorStopPrinting"), _T("OFF"), pcf_currentpath);
		//高压（字高）
		tempstr = dealXml.ReadXml(pcf_currentname,_T("PrintHeight"), _T("70"), pcf_currentpath);
		//喷印方向,,,,决定上位机发送数据时先发前列后尾列，还是先尾列后头列（信息选用通用配置时）
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Reverse"), _T("OFF"), pcf_currentpath);
		//文字正反,,,,决定上位机列数据是否高低点对调（信息选用通用配置时）
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Inverse"), _T("OFF"), pcf_currentpath);
		//产线运动方式：固定，可变,,,,默认固定
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Way"), _T("Fixed"), pcf_currentpath);
		//编码器信号相数
		tempstr = dealXml.ReadXml(pcf_currentname,_T("EncoderSignal"), _T("2 Phase"), pcf_currentpath);
		//编码器倍频
		//cmbval_pcf_external_fremul.Items.Clear();
		//if ()
		//{
		//	
		//}
		tempstr = dealXml.ReadXml(pcf_currentname,_T("FrequencyMultiplier"), _T("OFF"), pcf_currentpath);
		//列间距,,,,默认为内部划速率且约为800，速度为20米/分钟，6列字宽为2.54mm
		tempstr = dealXml.ReadXml(pcf_currentname,_T("DotPitch"), _T("0.423"), pcf_currentpath);
		//整体加粗（暂不做）
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("Density"), _T("1"), pcf_currentpath);
		//产线运动速度
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Speed"), _T("20"), pcf_currentpath);
		//延迟距离
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Delay"), _T("100"), pcf_currentpath);
		//喷印模式
		tempstr = dealXml.ReadXml(pcf_currentname,_T("PrintMode"), _T("OFF"), pcf_currentpath);
		//连续间隔距离
		tempstr = dealXml.ReadXml(pcf_currentname,_T("RepeatDistance"), _T("100"), pcf_currentpath);
		//重复计数值
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("RepeatCount"), _T("0"), pcf_currentpath);
		//工作列表（此版本不可用）
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("JoblistEnable"), _T("OFF"), pcf_currentpath);
		//是否启用电眼
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ProductSensor"), _T("ON"), pcf_currentpath);
		//电眼有效电平
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ActiveLevel"), _T("Low"), pcf_currentpath);
		//编码器前进方向
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ForwardDirection"), _T("Forward"), pcf_currentpath);
		//编码器1转脉冲数
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ImpulsesRoration"), _T("2500"), pcf_currentpath);
		//同步轮周长
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Cirumference"), _T("200"), pcf_currentpath);
		//触发后禁止触发长度
		tempstr = dealXml.ReadXml(pcf_currentname,_T("TriggerLength"), _T("300"), pcf_currentpath);
		//labval_gui_pcf.Text = pcf_currentname;	
	}
	else
	{
		CString tempstr;
		
		//labval_gui_pcf.Text = _T("Default");
		strLABlabForMName = pcf_currentname;
		//故障停止喷印(虚拟打印)
		//m_pCodePrinterDlg->m_Confi->m_ConfigPrintModeDlg-> = dealXml.ReadXml(pcf_currentname,_T("ErrorStopPrinting"), _T("OFF"), pcf_currentpath);
		//高压（字高）
		tempstr = dealXml.ReadXml(pcf_currentname,_T("PrintHeight"), _T("70"), pcf_currentpath);
		//喷印方向,,,,决定上位机发送数据时先发前列后尾列，还是先尾列后头列（信息选用通用配置时）
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Reverse"), _T("OFF"), pcf_currentpath);
		//文字正反,,,,决定上位机列数据是否高低点对调（信息选用通用配置时）
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Inverse"), _T("OFF"), pcf_currentpath);
		//产线运动方式：固定，可变,,,,默认固定
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Way"), _T("Fixed"), pcf_currentpath);
		//编码器信号相数
		tempstr = dealXml.ReadXml(pcf_currentname,_T("EncoderSignal"), _T("2 Phase"), pcf_currentpath);
		//编码器倍频
		//cmbval_pcf_external_fremul.Items.Clear();
		//if ()
		//{

		//}
		tempstr = dealXml.ReadXml(pcf_currentname,_T("FrequencyMultiplier"), _T("OFF"), pcf_currentpath);
		//列间距,,,,默认为内部划速率且约为800，速度为20米/分钟，6列字宽为2.54mm
		tempstr = dealXml.ReadXml(pcf_currentname,_T("DotPitch"), _T("0.423"), pcf_currentpath);
		//整体加粗（暂不做）
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("Density"), _T("1"), pcf_currentpath);
		//产线运动速度
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Speed"), _T("20"), pcf_currentpath);
		//延迟距离
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Delay"), _T("100"), pcf_currentpath);
		//喷印模式
		tempstr = dealXml.ReadXml(pcf_currentname,_T("PrintMode"), _T("OFF"), pcf_currentpath);
		//连续间隔距离
		tempstr = dealXml.ReadXml(pcf_currentname,_T("RepeatDistance"), _T("100"), pcf_currentpath);
		//重复计数值
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("RepeatCount"), _T("0"), pcf_currentpath);
		//工作列表（此版本不可用）
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("JoblistEnable"), _T("OFF"), pcf_currentpath);
		//是否启用电眼
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ProductSensor"), _T("ON"), pcf_currentpath);
		//电眼有效电平
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ActiveLevel"), _T("Low"), pcf_currentpath);
		//编码器前进方向
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ForwardDirection"), _T("Forward"), pcf_currentpath);
		//编码器1转脉冲数
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ImpulsesRoration"), _T("2500"), pcf_currentpath);
		//同步轮周长
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Cirumference"), _T("200"), pcf_currentpath);
		//触发后禁止触发长度
		tempstr = dealXml.ReadXml(pcf_currentname,_T("TriggerLength"), _T("300"), pcf_currentpath);		
	}
}

void CPcfConfig::download_pcf()
{
	
}
