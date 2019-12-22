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

	//��ǰ���ϴδ򿪵������ļ���
	pcf_currentname = dealXml.ReadXml(_T("PrintConfig.xml"),_T("CurrentName"), _T("Default.pcf"), _T("Storage Card\\System"));
	
	//��ǰ���ϴδ򿪵������ļ���·��
	pcf_currentpath = dealXml.ReadXml(_T("PrintConfig.xml"),_T("CurrentName"), _T("\Storage Card\System"), _T("Storage Card\\System"));
	

	bool isFileExit = true;
	if (isFileExit)//����ϴδ򿪵������ļ�������򿪸��ļ����������Ĭ�������ļ�
	{
		CString tempstr;

		strLABlabForMName = pcf_currentname;
		
		//����ֹͣ��ӡ(�����ӡ)
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ErrorStopPrinting"), _T("OFF"), pcf_currentpath);
		int nCur = m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_virtualPrint.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_virtualPrint.SetCurSel(nCur);
		
		//��ѹ���ָߣ�
		tempstr = dealXml.ReadXml(pcf_currentname,_T("PrintHeight"), _T("70"), pcf_currentpath);
		m_pCodePrinterDlg->m_Confi->m_height = _wtoi(tempstr);

		//��ӡ����,,,,������λ����������ʱ�ȷ�ǰ�к�β�У�������β�к�ͷ�У���Ϣѡ��ͨ������ʱ��
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Reverse"), _T("OFF"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_reverse.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_reverse.SetCurSel(nCur);
		
		
		//��������,,,,������λ���������Ƿ�ߵ͵�Ե�����Ϣѡ��ͨ������ʱ��
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Inverse"), _T("OFF"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_inverse.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_inverse.SetCurSel(nCur);
		
		//�����˶���ʽ���̶����ɱ�,,,,Ĭ�Ϲ̶�
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Way"), _T("Fixed"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_speedWay.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_speedWay.SetCurSel(nCur);
		
		//�������ź�����
		tempstr = dealXml.ReadXml(pcf_currentname,_T("EncoderSignal"), _T("2 Phase"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_encodeSign.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_encodeSign.SetCurSel(nCur);
		
		//��������Ƶ
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

		//�м��,,,,Ĭ��Ϊ�ڲ���������ԼΪ800���ٶ�Ϊ20��/���ӣ�6���ֿ�Ϊ2.54mm
		tempstr = dealXml.ReadXml(pcf_currentname,_T("DotPitch"), _T("0.423"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_dotPitch = _wtoi(tempstr);

		//����Ӵ֣��ݲ�����
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("Density"), _T("1"), pcf_currentpath);

		
		//�����˶��ٶ�
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Speed"), _T("20"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_speed = _wtoi(tempstr);

		//�ӳپ���
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Delay"), _T("100"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_delay = _wtoi(tempstr);

		//��ӡģʽ
		tempstr = dealXml.ReadXml(pcf_currentname,_T("PrintMode"), _T("OFF"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_printMode.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_printMode.SetCurSel(nCur);
		
		//�����������
		tempstr = dealXml.ReadXml(pcf_currentname,_T("RepeatDistance"), _T("100"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_repeatDis = _wtoi(tempstr);
		
		//�ظ�����ֵ
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("RepeatCount"), _T("0"), pcf_currentpath);
		//m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_repeatCount =  _wtoi(tempstr);

		//�����б��˰汾�����ã�
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("JoblistEnable"), _T("OFF"), pcf_currentpath);
		//nCur = m_pCodePrinterDlg->m_Confi->m_ConfigPM->	m_workList.SelectString(0,tempstr);
		//m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_workList.SetCurSel(nCur);
		
		//�Ƿ����õ���
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ProductSensor"), _T("ON"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_productDete.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_productDete.SetCurSel(nCur);

		//������Ч��ƽ
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ActiveLevel"), _T("Low"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_activeLev.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_activeLev.SetCurSel(nCur);
		
		//������ǰ������
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ForwardDirection"), _T("Forward"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_printDire.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_printDire.SetCurSel(nCur);

		//������1ת������
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ImpulsesRoration"), _T("2500"), pcf_currentpath);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_impulse.SetWindowText(tempstr);
		
		//ͬ�����ܳ�
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Cirumference"), _T("200"), pcf_currentpath);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.SetWindowText(tempstr);
		
		//�������ֹ��������
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
		//����ֹͣ��ӡ(�����ӡ)
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ErrorStopPrinting"), _T("OFF"), pcf_currentpath);
		int nCur = m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_virtualPrint.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_virtualPrint.SetCurSel(nCur);

		//��ѹ���ָߣ�
		tempstr = dealXml.ReadXml(pcf_currentname,_T("PrintHeight"), _T("70"), pcf_currentpath);
		m_pCodePrinterDlg->m_Confi->m_height = _wtoi(tempstr);

		//��ӡ����,,,,������λ����������ʱ�ȷ�ǰ�к�β�У�������β�к�ͷ�У���Ϣѡ��ͨ������ʱ��
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Reverse"), _T("OFF"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_reverse.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_reverse.SetCurSel(nCur);


		//��������,,,,������λ���������Ƿ�ߵ͵�Ե�����Ϣѡ��ͨ������ʱ��
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Inverse"), _T("OFF"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_inverse.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_inverse.SetCurSel(nCur);

		//�����˶���ʽ���̶����ɱ�,,,,Ĭ�Ϲ̶�
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Way"), _T("Fixed"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_speedWay.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_speedWay.SetCurSel(nCur);

		//�������ź�����
		tempstr = dealXml.ReadXml(pcf_currentname,_T("EncoderSignal"), _T("2 Phase"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_encodeSign.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_encodeSign.SetCurSel(nCur);

		//��������Ƶ
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

		//�м��,,,,Ĭ��Ϊ�ڲ���������ԼΪ800���ٶ�Ϊ20��/���ӣ�6���ֿ�Ϊ2.54mm
		tempstr = dealXml.ReadXml(pcf_currentname,_T("DotPitch"), _T("0.423"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_dotPitch = _wtoi(tempstr);

		//����Ӵ֣��ݲ�����
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("Density"), _T("1"), pcf_currentpath);


		//�����˶��ٶ�
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Speed"), _T("20"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_speed = _wtoi(tempstr);

		//�ӳپ���
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Delay"), _T("100"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_delay = _wtoi(tempstr);

		//��ӡģʽ
		tempstr = dealXml.ReadXml(pcf_currentname,_T("PrintMode"), _T("OFF"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_printMode.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_printMode.SetCurSel(nCur);

		//�����������
		tempstr = dealXml.ReadXml(pcf_currentname,_T("RepeatDistance"), _T("100"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_repeatDis = _wtoi(tempstr);

		//�ظ�����ֵ
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("RepeatCount"), _T("0"), pcf_currentpath);
		//m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_repeatCount =  _wtoi(tempstr);

		//�����б��˰汾�����ã�
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("JoblistEnable"), _T("OFF"), pcf_currentpath);
		//nCur = m_pCodePrinterDlg->m_Confi->m_ConfigPM->	m_workList.SelectString(0,tempstr);
		//m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_workList.SetCurSel(nCur);

		//�Ƿ����õ���
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ProductSensor"), _T("ON"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_productDete.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_productDete.SetCurSel(nCur);

		//������Ч��ƽ
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ActiveLevel"), _T("Low"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_activeLev.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_activeLev.SetCurSel(nCur);

		//������ǰ������
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ForwardDirection"), _T("Forward"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_printDire.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_printDire.SetCurSel(nCur);

		//������1ת������
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ImpulsesRoration"), _T("2500"), pcf_currentpath);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_impulse.SetWindowText(tempstr);

		//ͬ�����ܳ�
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Cirumference"), _T("200"), pcf_currentpath);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.SetWindowText(tempstr);

		//�������ֹ��������
		tempstr = dealXml.ReadXml(pcf_currentname,_T("TriggerLength"), _T("300"), pcf_currentpath);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_triggerLen.SetWindowText(tempstr);
	}
}

//void CPcfConfig::download_pcf()//����һ����getfromxml�����·����Ķ����ȱ������·���
//{
//	CDealXml dealXml;
//
//	BYTE pcf0X00bit1_bit0  = 2; //�д�����ʽ��0Ϊ������1�࣬1Ϊ������2�࣬2Ϊ�ڲ�һ�е�����������64K/�����ʣ�
//	BYTE pcf0X00bit2  = 0; //ͬ�������࣬0��A->B��1:B->A
//	BYTE pcf0X00bit4  = 0; //�������У����ڴ�ӡ��������ʱ�Ĵ���0��ӡֹͣ��1 ��ӡ��������ī��û�������
//	BYTE pcf0X00bit5  = 0; //��Ʒ���������ã�0 �����ã�1 ���õ��趨ֵ
//	BYTE pcf0X00bit6  = 0 ;//��ӡ���������ã�0 �����ã�1 ���õ��趨ֵ
//
//	//pcf����0X01
//	BYTE pcf0X01bit0  = 1; //�Ƿ����õ��ۣ�0Ϊ�رգ�1Ϊ����
//	BYTE pcf0X01bit2  = 0; //������Ч��ƽ��0Ϊ�͵�ƽ��1Ϊ�ߵ�ƽ
//	BYTE pcf0X01bit3  = 0; //��ӡģʽΪ���λ���������0Ϊ���Σ�1Ϊ����
//
//	if ( m_pCodePrinterDlg->m_Confi->m_speedWay.GetCurSel() == 0 )//�����˶���ʽ���̶������ڲ�
//	{
//		pcf0X00bit1_bit0 = 2;
//		//������ʱ	
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
//		//�����п�
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
//		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_encodeSign.GetCurSel() == 0 )//���٣��ⲿ������1��
//	{
//		
//	} 
//	else if ( m_pCodePrinterDlg->m_Confi->m_speedWay.GetCurSel() == 1 && 
//		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_encodeSign.GetCurSel() == 1 )//���٣��ⲿ������2��
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
