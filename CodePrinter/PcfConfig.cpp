#include "StdAfx.h"
#include "PcfConfig.h"
#include "resource.h"
#include "CodePrinterDlg.h"
#include "DealXml.h"
#include <cmath>

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
	pcf_currentname = dealXml.ReadXml(_T("PrintConfig.xml"),_T("CurrentName"), _T("Default.pcf"), _T("Storage Card\\System"));
	
	//当前或上次打开的配置文件的路径
	pcf_currentpath = dealXml.ReadXml(_T("PrintConfig.xml"),_T("CurrentName"), _T("\Storage Card\System"), _T("Storage Card\\System"));
	

	bool isFileExit = true;
	if (isFileExit)//如果上次打开的配置文件存在则打开该文件，否则调出默认配置文件
	{
		CString tempstr;

		strLABlabForMName = pcf_currentname;
		
		//故障停止喷印(虚拟打印)
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ErrorStopPrinting"), _T("OFF"), pcf_currentpath);
		int nCur = m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_virtualPrint.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_virtualPrint.SetCurSel(nCur);
		
		//高压（字高）
		tempstr = dealXml.ReadXml(pcf_currentname,_T("PrintHeight"), _T("70"), pcf_currentpath);
		m_pCodePrinterDlg->m_Confi->m_height = _wtoi(tempstr);

		//喷印方向,,,,决定上位机发送数据时先发前列后尾列，还是先尾列后头列（信息选用通用配置时）
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Reverse"), _T("OFF"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_reverse.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_reverse.SetCurSel(nCur);
		
		
		//文字正反,,,,决定上位机列数据是否高低点对调（信息选用通用配置时）
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Inverse"), _T("OFF"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_inverse.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_inverse.SetCurSel(nCur);
		
		//产线运动方式：固定，可变,,,,默认固定
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Way"), _T("Fixed"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_speedWay.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_speedWay.SetCurSel(nCur);
		
		//编码器信号相数
		tempstr = dealXml.ReadXml(pcf_currentname,_T("EncoderSignal"), _T("2 Phase"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_encodeSign.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_encodeSign.SetCurSel(nCur);
		
		//编码器倍频
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.Clear();
		if (m_pCodePrinterDlg->m_Confi->m_speedWay.GetCurSel() == 0)//Fixed
		{
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("OFF"));
		}
		else if (m_pCodePrinterDlg->m_Confi->m_speedWay.GetCurSel() == 1)//Variable
		{
			if (m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_encodeSign.GetCurSel() == 0 )
			{
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("OFF"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("2"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("3"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("4"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("5"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("6"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("7"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("8"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("9"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("10"));
			} 
			else
			{
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("OFF"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("2"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("3"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("4"));
			}
		}
		tempstr = dealXml.ReadXml(pcf_currentname,_T("FrequencyMultiplier"), _T("OFF"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.SetCurSel(nCur);

		//列间距,,,,默认为内部划速率且约为800，速度为20米/分钟，6列字宽为2.54mm
		tempstr = dealXml.ReadXml(pcf_currentname,_T("DotPitch"), _T("0.423"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_dotPitch = _wtoi(tempstr);

		//整体加粗（暂不做）
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("Density"), _T("1"), pcf_currentpath);

		
		//产线运动速度
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Speed"), _T("20"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_speed = _wtoi(tempstr);

		//延迟距离
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Delay"), _T("100"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_delay = _wtoi(tempstr);

		//喷印模式
		tempstr = dealXml.ReadXml(pcf_currentname,_T("PrintMode"), _T("OFF"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_printMode.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_printMode.SetCurSel(nCur);
		
		//连续间隔距离
		tempstr = dealXml.ReadXml(pcf_currentname,_T("RepeatDistance"), _T("100"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_repeatDis = _wtoi(tempstr);
		
		//重复计数值
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("RepeatCount"), _T("0"), pcf_currentpath);
		//m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_repeatCount =  _wtoi(tempstr);

		//工作列表（此版本不可用）
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("JoblistEnable"), _T("OFF"), pcf_currentpath);
		//nCur = m_pCodePrinterDlg->m_Confi->m_ConfigPM->	m_workList.SelectString(0,tempstr);
		//m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_workList.SetCurSel(nCur);
		
		//是否启用电眼
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ProductSensor"), _T("ON"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_productDete.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_productDete.SetCurSel(nCur);

		//电眼有效电平
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ActiveLevel"), _T("Low"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_activeLev.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_activeLev.SetCurSel(nCur);
		
		//编码器前进方向
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ForwardDirection"), _T("Forward"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_printDire.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_printDire.SetCurSel(nCur);

		//编码器1转脉冲数
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ImpulsesRoration"), _T("2500"), pcf_currentpath);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_impulse.SetWindowText(tempstr);
		
		//同步轮周长
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Cirumference"), _T("200"), pcf_currentpath);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.SetWindowText(tempstr);
		
		//触发后禁止触发长度
		tempstr = dealXml.ReadXml(pcf_currentname,_T("TriggerLength"), _T("300"), pcf_currentpath);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_triggerLen.SetWindowText(tempstr);
		//labval_gui_pcf.Text = pcf_currentname;	
	}
	else
	{
		CString tempstr;
		//labval_gui_pcf.Text = _T("Default");

		pcf_currentname = _T("PrintConfig.xml");
		pcf_currentpath = _T("Storage Card\\System");
		//故障停止喷印(虚拟打印)
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ErrorStopPrinting"), _T("OFF"), pcf_currentpath);
		int nCur = m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_virtualPrint.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_virtualPrint.SetCurSel(nCur);

		//高压（字高）
		tempstr = dealXml.ReadXml(pcf_currentname,_T("PrintHeight"), _T("70"), pcf_currentpath);
		m_pCodePrinterDlg->m_Confi->m_height = _wtoi(tempstr);

		//喷印方向,,,,决定上位机发送数据时先发前列后尾列，还是先尾列后头列（信息选用通用配置时）
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Reverse"), _T("OFF"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_reverse.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_reverse.SetCurSel(nCur);


		//文字正反,,,,决定上位机列数据是否高低点对调（信息选用通用配置时）
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Inverse"), _T("OFF"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_inverse.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_inverse.SetCurSel(nCur);

		//产线运动方式：固定，可变,,,,默认固定
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Way"), _T("Fixed"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_speedWay.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_speedWay.SetCurSel(nCur);

		//编码器信号相数
		tempstr = dealXml.ReadXml(pcf_currentname,_T("EncoderSignal"), _T("2 Phase"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_encodeSign.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_encodeSign.SetCurSel(nCur);

		//编码器倍频
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.Clear();
		if (m_pCodePrinterDlg->m_Confi->m_speedWay.GetCurSel() == 0)//Fixed
		{
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("OFF"));
		}
		else if (m_pCodePrinterDlg->m_Confi->m_speedWay.GetCurSel() == 1)//Variable
		{
			if (m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_encodeSign.GetCurSel() == 0 )
			{
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("OFF"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("2"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("3"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("4"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("5"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("6"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("7"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("8"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("9"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("10"));
			} 
			else
			{
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("OFF"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("2"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("3"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.AddString(_T("4"));
			}
		}
		tempstr = dealXml.ReadXml(pcf_currentname,_T("FrequencyMultiplier"), _T("OFF"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->FreqMulti.SetCurSel(nCur);

		//列间距,,,,默认为内部划速率且约为800，速度为20米/分钟，6列字宽为2.54mm
		tempstr = dealXml.ReadXml(pcf_currentname,_T("DotPitch"), _T("0.423"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_dotPitch = _wtoi(tempstr);

		//整体加粗（暂不做）
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("Density"), _T("1"), pcf_currentpath);


		//产线运动速度
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Speed"), _T("20"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_speed = _wtoi(tempstr);

		//延迟距离
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Delay"), _T("100"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_delay = _wtoi(tempstr);

		//喷印模式
		tempstr = dealXml.ReadXml(pcf_currentname,_T("PrintMode"), _T("OFF"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_printMode.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_printMode.SetCurSel(nCur);

		//连续间隔距离
		tempstr = dealXml.ReadXml(pcf_currentname,_T("RepeatDistance"), _T("100"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_repeatDis = _wtoi(tempstr);

		//重复计数值
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("RepeatCount"), _T("0"), pcf_currentpath);
		//m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_repeatCount =  _wtoi(tempstr);

		//工作列表（此版本不可用）
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("JoblistEnable"), _T("OFF"), pcf_currentpath);
		//nCur = m_pCodePrinterDlg->m_Confi->m_ConfigPM->	m_workList.SelectString(0,tempstr);
		//m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_workList.SetCurSel(nCur);

		//是否启用电眼
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ProductSensor"), _T("ON"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_productDete.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_productDete.SetCurSel(nCur);

		//电眼有效电平
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ActiveLevel"), _T("Low"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_activeLev.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_activeLev.SetCurSel(nCur);

		//编码器前进方向
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ForwardDirection"), _T("Forward"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_printDire.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_printDire.SetCurSel(nCur);

		//编码器1转脉冲数
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ImpulsesRoration"), _T("2500"), pcf_currentpath);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_impulse.SetWindowText(tempstr);

		//同步轮周长
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Cirumference"), _T("200"), pcf_currentpath);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.SetWindowText(tempstr);

		//触发后禁止触发长度
		tempstr = dealXml.ReadXml(pcf_currentname,_T("TriggerLength"), _T("300"), pcf_currentpath);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_triggerLen.SetWindowText(tempstr);
	}
}

//void CPcfConfig::download_pcf()//开机一定先getfromxml，再下发。改动后先保存再下发。
//{
//	CDealXml dealXml;
//
//	BYTE pcf0X00bit1_bit0  = 2; //列触发方式：0为编码器1相，1为编码器2相，2为内部一列点数（即等于64K/划速率）
//	BYTE pcf0X00bit2  = 0; //同步器反相，0：A->B，1:B->A
//	BYTE pcf0X00bit4  = 0; //故障运行，正在打印遇到故障时的处理，0打印停止，1 打印继续，但墨点没有喷出来
//	BYTE pcf0X00bit5  = 0; //产品计数器重置，0 不重置，1 重置到设定值
//	BYTE pcf0X00bit6  = 0 ;//打印计数器重置，0 不重置，1 重置到设定值
//
//	//pcf控制0X01
//	BYTE pcf0X01bit0  = 1; //是否启用电眼，0为关闭，1为启用
//	BYTE pcf0X01bit2  = 0; //电眼有效电平，0为低电平，1为高电平
//	BYTE pcf0X01bit3  = 0; //喷印模式为单次还是连续，0为单次，1为连续
//
//	if ( m_pCodePrinterDlg->m_Confi->m_speedWay.GetCurSel() == 0 )//产线运动方式：固定，即内部
//	{
//		pcf0X00bit1_bit0 = 2;
//		//计算延时	
//		try
//		{
//			pcf0X02_05 = Hex(round(_wtof(m_pCodePrinterDlg->m_Confi->m_delay) * 3840 / _wtof(m_pCodePrinterDlg->m_Confi->m_speed), 0));
//		}
//		catch (CException* e)
//		{
//			m_pCodePrinterDlg->m_Confi->m_speed = 20;	
//			pcf0X02_05 = Hex(round(_wtof(m_pCodePrinterDlg->m_Confi->m_delay) * 3840 / _wtof(m_pCodePrinterDlg->m_Confi->m_speed), 0));
//		}
//
//		pcf0X02_05 = pcf0X02_05.Mid("00000000" & pcf0X02_05, pcf0X02_05.GetLength() + 1, 8);
//		pcf0X02 = dealXml.HEX_to_DECbyte(pcf0X02_05.Mid(6, 2));
//		pcf0X03 = dealXml.HEX_to_DECbyte(pcf0X02_05.Mid(4, 2));
//		pcf0X04 = dealXml.HEX_to_DECbyte(pcf0X02_05.Mid(2, 2));
//		pcf0X05 = dealXml.HEX_to_DECbyte(pcf0X02_05.Mid(0, 2));
//		//计算列宽
//		try
//		{
//			pcf0X02_05 = Hex(round(_wtof(m_pCodePrinterDlg->m_Confi->m_dotPitch) * 3840 / _wtof(m_pCodePrinterDlg->m_Confi->m_speed), 0));
//		}
//		catch (CException* e)
//		{
//			m_pCodePrinterDlg->m_Confi->m_speed = 20;	
//			pcf0X02_05 = Hex(round(_wtof(m_pCodePrinterDlg->m_Confi->m_dotPitch) * 3840 / _wtof(m_pCodePrinterDlg->m_Confi->m_speed), 0));
//		}
//		
//	} 
//	else if ( m_pCodePrinterDlg->m_Confi->m_speedWay.GetCurSel() == 1 && 
//		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_encodeSign.GetCurSel() == 0 )//变速，外部编码器1相
//	{
//		
//	} 
//	else if ( m_pCodePrinterDlg->m_Confi->m_speedWay.GetCurSel() == 1 && 
//		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_encodeSign.GetCurSel() == 1 )//变速，外部编码器2相
//	{
//		
//	}
//	else
//	{
//		
//	}
//
//}

int CPcfConfig::round(double r)
{
	int a = (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
	return a;
}
