#include "StdAfx.h"
#include "PcfConfig.h"
#include "resource.h"
#include "CodePrinterDlg.h"
#include "DealXml.h"
#include <cmath>

CPcfConfig::CPcfConfig(CCodePrinterDlg* pCodeDlg)
{
	m_pCodePrinterDlg = pCodeDlg;

	//pcf0X00bit1_bit0  = 2; //�д�����ʽ��0Ϊ������1�࣬1Ϊ������2�࣬2Ϊ�ڲ�һ�е�����������64K/�����ʣ�
	//pcf0X00bit2  = 0; //ͬ�������࣬0��A->B��1:B->A
	//pcf0X00bit4  = 0; //�������У����ڴ�ӡ��������ʱ�Ĵ���0��ӡֹͣ��1 ��ӡ��������ī��û�������
	//pcf0X00bit5  = 0; //��Ʒ���������ã�0 �����ã�1 ���õ��趨ֵ
	//pcf0X00bit6  = 0 ;//��ӡ���������ã�0 �����ã�1 ���õ��趨ֵ

	////pcf����0X01
	//pcf0X01bit0  = 1; //�Ƿ����õ��ۣ�0Ϊ�رգ�1Ϊ����
	//pcf0X01bit2  = 0; //������Ч��ƽ��0Ϊ�͵�ƽ��1Ϊ�ߵ�ƽ
	//pcf0X01bit3  = 0; //��ӡģʽΪ���λ���������0Ϊ���Σ�1Ϊ����
}

CPcfConfig::~CPcfConfig(void)
{
}
void CPcfConfig::getPcfFromXml(string pcfNamePath)
{
	CDealXml dealXml;
	CString pcf_currentname,pcf_currentpath;
	
	string strPathName=pcfNamePath;
	int lastN=strPathName.find_last_of('\\');
	pcf_currentname = theApp.myModuleMain.string2CString(strPathName.substr(lastN + 1));
	pcf_currentpath= theApp.myModuleMain.string2CString(strPathName.substr(0,lastN));
	m_pcfName=pcf_currentname;
	//��ǰ���ϴδ򿪵������ļ���
	//pcf_currentname = dealXml.ReadXml(_T("PrintConfig.xml"),_T("CurrentName"), _T("Default.pcf"), _T("Storage Card\\System"));

	//��ǰ���ϴδ򿪵������ļ���·��
	//pcf_currentpath = dealXml.ReadXml(_T("PrintConfig.xml"),_T("CurrentPath"), _T("\Storage Card\System"), _T("Storage Card\\System"));


	bool isFileExit = true;
	CString tempstr;

	strLABlabForMName = pcf_currentname;

	//����ֹͣ��ӡ(�����ӡ)
	tempstr = dealXml.ReadXml(pcf_currentname,_T("ErrorStopPrinting"), _T("OFF"), pcf_currentpath);
	int nCur = m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_virtualPrint.SelectString(0,tempstr);
	m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_virtualPrint.SetCurSel(nCur);

	//��ѹ���ָߣ�
	tempstr = dealXml.ReadXml(pcf_currentname,_T("PrintHeight"), _T("70"), pcf_currentpath);
	m_pCodePrinterDlg->m_Confi->m_height = _wtoi(tempstr);

	//��ӡ����,������λ����������ʱ�ȷ�ǰ�к�β�У�������β�к�ͷ�У���Ϣѡ��ͨ������ʱ��
	tempstr = dealXml.ReadXml(pcf_currentname,_T("Reverse"), _T("OFF"), pcf_currentpath);
	nCur = m_pCodePrinterDlg->m_Confi->m_reverse.SelectString(0,tempstr);
	m_pCodePrinterDlg->m_Confi->m_reverse.SetCurSel(nCur);


	//��������,������λ���������Ƿ�ߵ͵�Ե�����Ϣѡ��ͨ������ʱ��
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
	m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.ResetContent();
	if (m_pCodePrinterDlg->m_Confi->m_speedWay.GetCurSel() == 0)//Fixed
	{
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("OFF"));
	}
	else if (m_pCodePrinterDlg->m_Confi->m_speedWay.GetCurSel() == 1)//Variable
	{
		if (m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_encodeSign.GetCurSel() == 0 )
		{
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("OFF"));
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("2"));
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("3"));
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("4"));
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("5"));
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("6"));
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("7"));
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("8"));
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("9"));
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("10"));
		} 
		else
		{
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("OFF"));
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("2"));
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("3"));
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("4"));
		}
	}
	tempstr = dealXml.ReadXml(pcf_currentname,_T("FrequencyMultiplier"), _T("OFF"), pcf_currentpath);
	nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.SelectString(0,tempstr);
	m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.SetCurSel(nCur);

	//�м��,Ĭ��Ϊ�ڲ���������ԼΪ800���ٶ�Ϊ20��/���ӣ�6���ֿ�Ϊ2.54mm
	USES_CONVERSION;
	tempstr = dealXml.ReadXml(pcf_currentname,_T("DotPitch"), _T("0.423"), pcf_currentpath);
	m_pCodePrinterDlg->m_Confi->m_dotPitch = atof(W2A(tempstr.GetBuffer(0)));

	//����Ӵ֣��ݲ�����
	//tempstr = dealXml.ReadXml(pcf_currentname,_T("Density"), _T("1"), pcf_currentpath);

	//�����˶��ٶ�
	tempstr = dealXml.ReadXml(pcf_currentname,_T("Speed"), _T("20"), pcf_currentpath);
	m_pCodePrinterDlg->m_Confi->m_speed = _wtoi(tempstr);

	//�ӳپ���
	tempstr = dealXml.ReadXml(pcf_currentname,_T("Delay"), _T("100"), pcf_currentpath);
	m_pCodePrinterDlg->m_Confi->m_delay = _wtoi(tempstr);

	//��ӡģʽ
	tempstr = dealXml.ReadXml(pcf_currentname,_T("PrintMode"), _T("OFF"), pcf_currentpath);
	nCur = m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_printMode.SelectString(0,tempstr);
	m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_printMode.SetCurSel(nCur);

	//�����������
	tempstr = dealXml.ReadXml(pcf_currentname,_T("RepeatDistance"), _T("100"), pcf_currentpath);
	m_pCodePrinterDlg->m_Confi->m_repeatDis = _wtoi(tempstr);

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
void CPcfConfig::get_pcf_from_xml()
{
	CDealXml dealXml;
	CString pcf_currentname,pcf_currentpath;

	//��ǰ���ϴδ򿪵������ļ���
	pcf_currentname = dealXml.ReadXml(_T("PrintConfig.xml"),_T("CurrentName"), _T("Default.pcf"), _T("Storage Card\\System"));
	m_pcfName=pcf_currentname;
	//��ǰ���ϴδ򿪵������ļ���·��
	pcf_currentpath = dealXml.ReadXml(_T("PrintConfig.xml"),_T("CurrentPath"), _T("\Storage Card\System"), _T("Storage Card\\System"));
	

	bool isFileExit = true;
	CString tempstr;
	if (isFileExit)//����ϴδ򿪵������ļ�������򿪸��ļ����������Ĭ�������ļ�
	{

		strLABlabForMName = pcf_currentname;
		
		//����ֹͣ��ӡ(�����ӡ)
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ErrorStopPrinting"), _T("OFF"), pcf_currentpath);
		int nCur = m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_virtualPrint.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_virtualPrint.SetCurSel(nCur);
		
		//��ѹ���ָߣ�
		tempstr = dealXml.ReadXml(pcf_currentname,_T("PrintHeight"), _T("70"), pcf_currentpath);
		m_pCodePrinterDlg->m_Confi->m_height = _wtoi(tempstr);

		//��ӡ����,������λ����������ʱ�ȷ�ǰ�к�β�У�������β�к�ͷ�У���Ϣѡ��ͨ������ʱ��
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Reverse"), _T("OFF"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_reverse.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_reverse.SetCurSel(nCur);
		
		
		//��������,������λ���������Ƿ�ߵ͵�Ե�����Ϣѡ��ͨ������ʱ��
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
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.ResetContent();
		if (m_pCodePrinterDlg->m_Confi->m_speedWay.GetCurSel() == 0)//Fixed
		{
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("OFF"));
		}
		else if (m_pCodePrinterDlg->m_Confi->m_speedWay.GetCurSel() == 1)//Variable
		{
			if (m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_encodeSign.GetCurSel() == 0 )
			{
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("OFF"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("2"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("3"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("4"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("5"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("6"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("7"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("8"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("9"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("10"));
			} 
			else
			{
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("OFF"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("2"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("3"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("4"));
			}
		}
		tempstr = dealXml.ReadXml(pcf_currentname,_T("FrequencyMultiplier"), _T("OFF"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.SetCurSel(nCur);

		//�м��,Ĭ��Ϊ�ڲ���������ԼΪ800���ٶ�Ϊ20��/���ӣ�6���ֿ�Ϊ2.54mm
		USES_CONVERSION;
		tempstr = dealXml.ReadXml(pcf_currentname,_T("DotPitch"), _T("0.423"), pcf_currentpath);
		m_pCodePrinterDlg->m_Confi->m_dotPitch = atof(W2A(tempstr.GetBuffer(0)));

		//����Ӵ֣��ݲ�����
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("Density"), _T("1"), pcf_currentpath);
		
		//�����˶��ٶ�
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Speed"), _T("20"), pcf_currentpath);
		 m_pCodePrinterDlg->m_Confi->m_speed = _wtoi(tempstr);

		//�ӳپ���
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Delay"), _T("100"), pcf_currentpath);
		m_pCodePrinterDlg->m_Confi->m_delay = _wtoi(tempstr);

		//��ӡģʽ
		tempstr = dealXml.ReadXml(pcf_currentname,_T("PrintMode"), _T("OFF"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_printMode.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_printMode.SetCurSel(nCur);
		
		//�����������
		tempstr = dealXml.ReadXml(pcf_currentname,_T("RepeatDistance"), _T("100"), pcf_currentpath);
		m_pCodePrinterDlg->m_Confi->m_repeatDis = _wtoi(tempstr);
		
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

		//��ӡ����,������λ����������ʱ�ȷ�ǰ�к�β�У�������β�к�ͷ�У���Ϣѡ��ͨ������ʱ��
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Reverse"), _T("OFF"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_reverse.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_reverse.SetCurSel(nCur);


		//��������,������λ���������Ƿ�ߵ͵�Ե�����Ϣѡ��ͨ������ʱ��
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
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.ResetContent();
		if (m_pCodePrinterDlg->m_Confi->m_speedWay.GetCurSel() == 0)//Fixed
		{
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("OFF"));
		}
		else if (m_pCodePrinterDlg->m_Confi->m_speedWay.GetCurSel() == 1)//Variable
		{
			if (m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_encodeSign.GetCurSel() == 0 )
			{
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("OFF"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("2"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("3"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("4"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("5"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("6"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("7"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("8"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("9"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("10"));
			} 
			else
			{
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("OFF"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("2"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("3"));
				m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.AddString(_T("4"));
			}
		}
		tempstr = dealXml.ReadXml(pcf_currentname,_T("FrequencyMultiplier"), _T("OFF"), pcf_currentpath);
		nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.SelectString(0,tempstr);
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.SetCurSel(nCur);

		//�м��,,,,Ĭ��Ϊ�ڲ���������ԼΪ800���ٶ�Ϊ20��/���ӣ�6���ֿ�Ϊ2.54mm
		USES_CONVERSION;
		tempstr = dealXml.ReadXml(pcf_currentname,_T("DotPitch"), _T("0.423"), pcf_currentpath);
		m_pCodePrinterDlg->m_Confi->m_dotPitch = atof(W2A(tempstr.GetBuffer(0)));

		//����Ӵ֣��ݲ�����
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("Density"), _T("1"), pcf_currentpath);

		//�����˶��ٶ�
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Speed"), _T("20"), pcf_currentpath);
		m_pCodePrinterDlg->m_Confi->m_speed = _wtoi(tempstr);

		//�ӳپ���
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Delay"), _T("100"), pcf_currentpath);
		m_pCodePrinterDlg->m_Confi->m_delay = _wtoi(tempstr);

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
	m_pCodePrinterDlg->m_Confi->pcf_diagram_select();
}


void CPcfConfig::download_pcf()//����һ����getfromxml�����·����Ķ����ȱ������·���
{
	CDealXml dealXml;
	string tempstr;
	CString strtmp;
	int nTmp;

	m_pCodePrinterDlg->m_Confi->UpdateData();
	m_pCodePrinterDlg->m_Confi->m_ConfigOS->UpdateData();
	m_pCodePrinterDlg->m_Confi->m_ConfigPM->UpdateData();

	if(m_pCodePrinterDlg->m_Confi->m_speedWay.GetCurSel() == 0)//�����˶���ʽ���̶������ڲ�
	{
		theApp.myPcfClass.pcf0X00bit1_bit0 = 2;
		
		//������ʱ	
		try
		{
			//tempstr = theApp.myModuleMain.jinzhi10to16(round(m_pCodePrinterDlg->m_Confi->m_delay * 3840.0 / m_pCodePrinterDlg->m_Confi->m_speed));
			//mypcf0X02_05 = theApp.myModuleMain.stringToLPCWSTR(tempstr);
            
			nTmp = m_pCodePrinterDlg->m_Confi->m_delay * 3840.0 / m_pCodePrinterDlg->m_Confi->m_speed;	

		}
		catch (CException* e)
		{
			m_pCodePrinterDlg->m_Confi->m_speed = 20;
			//tempstr = theApp.myModuleMain.jinzhi10to16(round(m_pCodePrinterDlg->m_Confi->m_delay * 3840.0 / m_pCodePrinterDlg->m_Confi->m_speed));
			//mypcf0X02_05 = theApp.myModuleMain.stringToLPCWSTR(tempstr);
			nTmp = m_pCodePrinterDlg->m_Confi->m_delay * 3840.0 / m_pCodePrinterDlg->m_Confi->m_speed;	
		}
		//strtmp.Format(_T("%s%s"),_T("00000000"),mypcf0X02_05);
		//mypcf0X02_05 = strtmp.Right(8);
		//theApp.myPcfClass.pcf0X02 = dealXml.HEX_to_DECbyte(mypcf0X02_05.Mid(6, 2));
		//theApp.myPcfClass.pcf0X03 = dealXml.HEX_to_DECbyte(mypcf0X02_05.Mid(4, 2));
		//theApp.myPcfClass.pcf0X04 = dealXml.HEX_to_DECbyte(mypcf0X02_05.Mid(2, 2));
		//theApp.myPcfClass.pcf0X05 = dealXml.HEX_to_DECbyte(mypcf0X02_05.Mid(0, 2));
        theApp.myPcfClass.pcf0X02 = nTmp & 0xFF;
        theApp.myPcfClass.pcf0X03 = (nTmp >> 8) & 0xFF;
        theApp.myPcfClass.pcf0X04 = (nTmp >> 16) & 0xFF;
        theApp.myPcfClass.pcf0X05 = (nTmp >> 24) & 0xFF;
		
		//�����п�
		try
		{
			//tempstr = theApp.myModuleMain.jinzhi10to16(round(m_pCodePrinterDlg->m_Confi->m_dotPitch * 3840.0 / m_pCodePrinterDlg->m_Confi->m_speed));
			//mypcf0X06_09 = theApp.myModuleMain.stringToLPCWSTR(tempstr);
			nTmp = m_pCodePrinterDlg->m_Confi->m_dotPitch * 3840.0 / m_pCodePrinterDlg->m_Confi->m_speed;	

		}
		catch (CException* e)
		{
			m_pCodePrinterDlg->m_Confi->m_speed = 20;
			//tempstr =  theApp.myModuleMain.jinzhi10to16(round(m_pCodePrinterDlg->m_Confi->m_dotPitch * 3840.0 / m_pCodePrinterDlg->m_Confi->m_speed));
			//mypcf0X06_09 = theApp.myModuleMain.stringToLPCWSTR(tempstr);
			nTmp = m_pCodePrinterDlg->m_Confi->m_dotPitch * 3840.0 / m_pCodePrinterDlg->m_Confi->m_speed;	
		}
		//strtmp.Format(_T("%s%s"),_T("00000000"),mypcf0X06_09);
		//mypcf0X06_09 = strtmp.Right(8);
		//theApp.myPcfClass.pcf0X06 = dealXml.HEX_to_DECbyte(mypcf0X06_09.Mid(6, 2));
		//theApp.myPcfClass.pcf0X07 = dealXml.HEX_to_DECbyte(mypcf0X06_09.Mid(4, 2));
		//theApp.myPcfClass.pcf0X08 = dealXml.HEX_to_DECbyte(mypcf0X06_09.Mid(2, 2));
		//theApp.myPcfClass.pcf0X09 = dealXml.HEX_to_DECbyte(mypcf0X06_09.Mid(0, 2));

		theApp.myPcfClass.pcf0X06 = nTmp & 0xFF;
        theApp.myPcfClass.pcf0X07 = (nTmp >> 8) & 0xFF;
        theApp.myPcfClass.pcf0X08 = (nTmp >> 16) & 0xFF;
        theApp.myPcfClass.pcf0X09 = (nTmp >> 24) & 0xFF;


		//�����ظ���ӡ���
		try
		{
			//tempstr = theApp.myModuleMain.jinzhi10to16(round(m_pCodePrinterDlg->m_Confi->m_repeatDis * 3840.0 / m_pCodePrinterDlg->m_Confi->m_speed));
			//mypcf0X13_16 = theApp.myModuleMain.stringToLPCWSTR(tempstr);
			nTmp = m_pCodePrinterDlg->m_Confi->m_repeatDis * 3840.0 / m_pCodePrinterDlg->m_Confi->m_speed;	
		}
		catch (CException* e)
		{
			m_pCodePrinterDlg->m_Confi->m_speed = 20;
			//tempstr =  theApp.myModuleMain.jinzhi10to16(round(m_pCodePrinterDlg->m_Confi->m_repeatDis * 3840.0 / m_pCodePrinterDlg->m_Confi->m_speed));
			//mypcf0X13_16 = theApp.myModuleMain.stringToLPCWSTR(tempstr);
			nTmp = m_pCodePrinterDlg->m_Confi->m_repeatDis * 3840.0 / m_pCodePrinterDlg->m_Confi->m_speed;	

		}
	/*	strtmp.Format(_T("%s%s"),_T("00000000"),mypcf0X13_16);
		mypcf0X13_16 = strtmp.Mid(mypcf0X13_16.GetLength(), 8);
		theApp.myPcfClass.pcf0X13 = dealXml.HEX_to_DECbyte(mypcf0X13_16.Mid(6, 2));
		theApp.myPcfClass.pcf0X14 = dealXml.HEX_to_DECbyte(mypcf0X13_16.Mid(4, 2));
		theApp.myPcfClass.pcf0X15 = dealXml.HEX_to_DECbyte(mypcf0X13_16.Mid(2, 2));
		theApp.myPcfClass.pcf0X16 = dealXml.HEX_to_DECbyte(mypcf0X13_16.Mid(0, 2));*/

		theApp.myPcfClass.pcf0X13 = nTmp & 0xFF;
        theApp.myPcfClass.pcf0X14 = (nTmp >> 8) & 0xFF;
        theApp.myPcfClass.pcf0X15 = (nTmp >> 16) & 0xFF;
        theApp.myPcfClass.pcf0X16 = (nTmp >> 24) & 0xFF;


		//�������ֹ��������
		try
		{
			CString strtriggerLen;
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_triggerLen.GetWindowText(strtriggerLen);
			int triggerLen = _wtoi(strtriggerLen);
			//tempstr = theApp.myModuleMain.jinzhi10to16(round(triggerLen * 3840.0 / m_pCodePrinterDlg->m_Confi->m_speed));
			//mypcf0X19_1C = theApp.myModuleMain.stringToLPCWSTR(tempstr);
			nTmp = triggerLen * 3840.0 / m_pCodePrinterDlg->m_Confi->m_speed;	
		}
		catch (CException* e)
		{
			CString strtriggerLen;
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_triggerLen.GetWindowText(strtriggerLen);
			int triggerLen = _wtoi(strtriggerLen);

			m_pCodePrinterDlg->m_Confi->m_speed = 20;
			//tempstr =  theApp.myModuleMain.jinzhi10to16(round(triggerLen * 3840.0 / m_pCodePrinterDlg->m_Confi->m_speed));
			//mypcf0X19_1C = theApp.myModuleMain.stringToLPCWSTR(tempstr);
			nTmp = triggerLen * 3840.0 / m_pCodePrinterDlg->m_Confi->m_speed;	
		}
	/*	strtmp.Format(_T("%s%s"),_T("00000000"),mypcf0X19_1C);
		mypcf0X19_1C = strtmp.Mid(mypcf0X19_1C.GetLength(), 8);
		theApp.myPcfClass.pcf0X19 = dealXml.HEX_to_DECbyte(mypcf0X19_1C.Mid(6, 2));
		theApp.myPcfClass.pcf0X1A = dealXml.HEX_to_DECbyte(mypcf0X19_1C.Mid(4, 2));
		theApp.myPcfClass.pcf0X1B = dealXml.HEX_to_DECbyte(mypcf0X19_1C.Mid(2, 2));
		theApp.myPcfClass.pcf0X1C = dealXml.HEX_to_DECbyte(mypcf0X19_1C.Mid(0, 2));*/

		theApp.myPcfClass.pcf0X19 = nTmp & 0xFF;
        theApp.myPcfClass.pcf0X1A = (nTmp >> 8) & 0xFF;
        theApp.myPcfClass.pcf0X1B = (nTmp >> 16) & 0xFF;
        theApp.myPcfClass.pcf0X1C = (nTmp >> 24) & 0xFF;

	} 
	else if(m_pCodePrinterDlg->m_Confi->m_speedWay.GetCurSel() == 1 && 
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_encodeSign.GetCurSel() == 0)//���٣��ⲿ������1��
	{
		theApp.myPcfClass.pcf0X00bit1_bit0 = 0;
		//������ʱ
		try
		{
			CString strimpulse,strlength;
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_impulse.GetWindowText(strimpulse);
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.GetWindowText(strlength);
			int impulse = _wtoi(strimpulse);
			int length = _wtoi(strlength);
			tempstr = theApp.myModuleMain.jinzhi10to16(round((m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.GetCurSel() + 1 )* impulse * m_pCodePrinterDlg->m_Confi->m_delay / length ));
			mypcf0X02_05 = theApp.myModuleMain.stringToLPCWSTR(tempstr);
		}
		catch (CException* e)
		{
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.SetWindowText(_T("200"));

			CString strimpulse,strlength;
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_impulse.GetWindowText(strimpulse);
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.GetWindowText(strlength);
			int impulse = _wtoi(strimpulse);
			int length = _wtoi(strlength);
			tempstr = theApp.myModuleMain.jinzhi10to16(round((m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.GetCurSel() + 1 )* impulse * m_pCodePrinterDlg->m_Confi->m_delay /length ));
			mypcf0X02_05 = theApp.myModuleMain.stringToLPCWSTR(tempstr);
		}
		strtmp.Format(_T("%s%s"),_T("00000000"),mypcf0X02_05);
		mypcf0X02_05 = strtmp.Mid(mypcf0X02_05.GetLength(), 8);
		theApp.myPcfClass.pcf0X02 = dealXml.HEX_to_DECbyte(mypcf0X02_05.Mid(6, 2));
		theApp.myPcfClass.pcf0X03 = dealXml.HEX_to_DECbyte(mypcf0X02_05.Mid(4, 2));
		theApp.myPcfClass.pcf0X04 = dealXml.HEX_to_DECbyte(mypcf0X02_05.Mid(2, 2));
		theApp.myPcfClass.pcf0X05 = dealXml.HEX_to_DECbyte(mypcf0X02_05.Mid(0, 2));

		//�����п�
		try
		{
			CString strimpulse,strlength;
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_impulse.GetWindowText(strimpulse);
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.GetWindowText(strlength);
			int impulse = _wtoi(strimpulse);
			int length = _wtoi(strlength);

			tempstr = theApp.myModuleMain.jinzhi10to16(round((m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.GetCurSel() + 1 )* impulse * m_pCodePrinterDlg->m_Confi->m_dotPitch / length ));
			mypcf0X06_09 = theApp.myModuleMain.stringToLPCWSTR(tempstr);
		}
		catch (CException* e)
		{
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.SetWindowText(_T("200"));

			CString strimpulse,strlength;
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_impulse.GetWindowText(strimpulse);
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.GetWindowText(strlength);
			int impulse = _wtoi(strimpulse);
			int length = _wtoi(strlength);

			tempstr =  theApp.myModuleMain.jinzhi10to16(round((m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.GetCurSel() + 1 )* impulse * m_pCodePrinterDlg->m_Confi->m_dotPitch / length ));
			mypcf0X06_09 = theApp.myModuleMain.stringToLPCWSTR(tempstr);
		}
		strtmp.Format(_T("%s%s"),_T("00000000"),mypcf0X06_09);
		mypcf0X06_09 = strtmp.Mid(mypcf0X06_09.GetLength(), 8);
		theApp.myPcfClass.pcf0X06 = dealXml.HEX_to_DECbyte(mypcf0X06_09.Mid(6, 2));
		theApp.myPcfClass.pcf0X07 = dealXml.HEX_to_DECbyte(mypcf0X06_09.Mid(4, 2));
		theApp.myPcfClass.pcf0X08 = dealXml.HEX_to_DECbyte(mypcf0X06_09.Mid(2, 2));
		theApp.myPcfClass.pcf0X09 = dealXml.HEX_to_DECbyte(mypcf0X06_09.Mid(0, 2));

		//�����ظ���ӡ���
		try
		{
			CString strimpulse,strlength;
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_impulse.GetWindowText(strimpulse);
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.GetWindowText(strlength);
			int impulse = _wtoi(strimpulse);
			int length = _wtoi(strlength);

			tempstr = theApp.myModuleMain.jinzhi10to16(round((m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.GetCurSel() + 1 )* impulse * m_pCodePrinterDlg->m_Confi->m_repeatDis / length ));
			mypcf0X13_16 = theApp.myModuleMain.stringToLPCWSTR(tempstr);
		}
		catch (CException* e)
		{
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.SetWindowText(_T("200"));

			CString strimpulse,strlength;
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_impulse.GetWindowText(strimpulse);
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.GetWindowText(strlength);
			int impulse = _wtoi(strimpulse);
			int length = _wtoi(strlength);

			tempstr =  theApp.myModuleMain.jinzhi10to16(round((m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.GetCurSel() + 1 )* impulse * m_pCodePrinterDlg->m_Confi->m_repeatDis / length ));
			mypcf0X13_16 = theApp.myModuleMain.stringToLPCWSTR(tempstr);
		}
		strtmp.Format(_T("%s%s"),_T("00000000"),mypcf0X13_16);
		mypcf0X13_16 = strtmp.Mid(mypcf0X13_16.GetLength(), 8);
		theApp.myPcfClass.pcf0X13 = dealXml.HEX_to_DECbyte(mypcf0X13_16.Mid(6, 2));
		theApp.myPcfClass.pcf0X14 = dealXml.HEX_to_DECbyte(mypcf0X13_16.Mid(4, 2));
		theApp.myPcfClass.pcf0X15 = dealXml.HEX_to_DECbyte(mypcf0X13_16.Mid(2, 2));
		theApp.myPcfClass.pcf0X16 = dealXml.HEX_to_DECbyte(mypcf0X13_16.Mid(0, 2));

		//�������ֹ��������
		try
		{
			CString strimpulse,strlength,strtriggerLen;
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_impulse.GetWindowText(strimpulse);
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.GetWindowText(strlength);
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_triggerLen.GetWindowText(strtriggerLen);
			int impulse = _wtoi(strimpulse);
			int length = _wtoi(strlength);
			int triggerLen = _wtoi(strtriggerLen);

			tempstr = theApp.myModuleMain.jinzhi10to16(round((m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.GetCurSel() + 1 )* impulse * triggerLen / length ));
			mypcf0X19_1C = theApp.myModuleMain.stringToLPCWSTR(tempstr);
		}
		catch (CException* e)
		{
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.SetWindowText(_T("200"));

			CString strimpulse,strlength,strtriggerLen;
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_impulse.GetWindowText(strimpulse);
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.GetWindowText(strlength);
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_triggerLen.GetWindowText(strtriggerLen);
			int impulse = _wtoi(strimpulse);
			int length = _wtoi(strlength);
			int triggerLen = _wtoi(strtriggerLen);

			tempstr =  theApp.myModuleMain.jinzhi10to16(round((m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.GetCurSel() + 1 )* impulse * triggerLen / length ));
			mypcf0X19_1C = theApp.myModuleMain.stringToLPCWSTR(tempstr);
		}
		strtmp.Format(_T("%s%s"),_T("00000000"),mypcf0X19_1C);
		mypcf0X19_1C = strtmp.Mid(mypcf0X19_1C.GetLength(), 8);
		theApp.myPcfClass.pcf0X19 = dealXml.HEX_to_DECbyte(mypcf0X19_1C.Mid(6, 2));
		theApp.myPcfClass.pcf0X1A = dealXml.HEX_to_DECbyte(mypcf0X19_1C.Mid(4, 2));
		theApp.myPcfClass.pcf0X1B = dealXml.HEX_to_DECbyte(mypcf0X19_1C.Mid(2, 2));
		theApp.myPcfClass.pcf0X1C = dealXml.HEX_to_DECbyte(mypcf0X19_1C.Mid(0, 2));
	} 
	else if ( m_pCodePrinterDlg->m_Confi->m_speedWay.GetCurSel() == 1 && 
		m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_encodeSign.GetCurSel() == 1 )//���٣��ⲿ������2��
	{
		theApp.myPcfClass.pcf0X00bit1_bit0 = 1;
		
		//������ʱ
		try
		{
			CString strimpulse,strlength;
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_impulse.GetWindowText(strimpulse);
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.GetWindowText(strlength);
			int impulse = _wtoi(strimpulse);
			int length = _wtoi(strlength);
			tempstr = theApp.myModuleMain.jinzhi10to16(round((m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.GetCurSel() + 1 )* impulse * m_pCodePrinterDlg->m_Confi->m_delay / length ));
			mypcf0X02_05 = theApp.myModuleMain.stringToLPCWSTR(tempstr);
		}
		catch (CException* e)
		{
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.SetWindowText(_T("200"));

			CString strimpulse,strlength;
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_impulse.GetWindowText(strimpulse);
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.GetWindowText(strlength);
			int impulse = _wtoi(strimpulse);
			int length = _wtoi(strlength);
			tempstr = theApp.myModuleMain.jinzhi10to16(round((m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.GetCurSel() + 1 )* impulse * m_pCodePrinterDlg->m_Confi->m_delay /length ));
			mypcf0X02_05 = theApp.myModuleMain.stringToLPCWSTR(tempstr);
		}
		strtmp.Format(_T("%s%s"),_T("00000000"),mypcf0X02_05);
		mypcf0X02_05 = strtmp.Mid(mypcf0X02_05.GetLength(), 8);
		theApp.myPcfClass.pcf0X02 = dealXml.HEX_to_DECbyte(mypcf0X02_05.Mid(6, 2));
		theApp.myPcfClass.pcf0X03 = dealXml.HEX_to_DECbyte(mypcf0X02_05.Mid(4, 2));
		theApp.myPcfClass.pcf0X04 = dealXml.HEX_to_DECbyte(mypcf0X02_05.Mid(2, 2));
		theApp.myPcfClass.pcf0X05 = dealXml.HEX_to_DECbyte(mypcf0X02_05.Mid(0, 2));

		//�����п�
		try
		{
			CString strimpulse,strlength;
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_impulse.GetWindowText(strimpulse);
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.GetWindowText(strlength);
			int impulse = _wtoi(strimpulse);
			int length = _wtoi(strlength);

			tempstr = theApp.myModuleMain.jinzhi10to16(round((m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.GetCurSel() + 1 )* impulse * m_pCodePrinterDlg->m_Confi->m_dotPitch / length ));
			mypcf0X06_09 = theApp.myModuleMain.stringToLPCWSTR(tempstr);
		}
		catch (CException* e)
		{
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.SetWindowText(_T("200"));

			CString strimpulse,strlength;
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_impulse.GetWindowText(strimpulse);
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.GetWindowText(strlength);
			int impulse = _wtoi(strimpulse);
			int length = _wtoi(strlength);

			tempstr =  theApp.myModuleMain.jinzhi10to16(round((m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.GetCurSel() + 1 )* impulse * m_pCodePrinterDlg->m_Confi->m_dotPitch / length ));
			mypcf0X06_09 = theApp.myModuleMain.stringToLPCWSTR(tempstr);
		}
		strtmp.Format(_T("%s%s"),_T("00000000"),mypcf0X06_09);
		mypcf0X06_09 = strtmp.Mid(mypcf0X06_09.GetLength(), 8);
		theApp.myPcfClass.pcf0X06 = dealXml.HEX_to_DECbyte(mypcf0X06_09.Mid(6, 2));
		theApp.myPcfClass.pcf0X07 = dealXml.HEX_to_DECbyte(mypcf0X06_09.Mid(4, 2));
		theApp.myPcfClass.pcf0X08 = dealXml.HEX_to_DECbyte(mypcf0X06_09.Mid(2, 2));
		theApp.myPcfClass.pcf0X09 = dealXml.HEX_to_DECbyte(mypcf0X06_09.Mid(0, 2));

		//�����ظ���ӡ���
		try
		{
			CString strimpulse,strlength;
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_impulse.GetWindowText(strimpulse);
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.GetWindowText(strlength);
			int impulse = _wtoi(strimpulse);
			int length = _wtoi(strlength);

			tempstr = theApp.myModuleMain.jinzhi10to16(round((m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.GetCurSel() + 1 )* impulse * m_pCodePrinterDlg->m_Confi->m_repeatDis / length ));
			mypcf0X13_16 = theApp.myModuleMain.stringToLPCWSTR(tempstr);
		}
		catch (CException* e)
		{
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.SetWindowText(_T("200"));

			CString strimpulse,strlength;
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_impulse.GetWindowText(strimpulse);
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.GetWindowText(strlength);
			int impulse = _wtoi(strimpulse);
			int length = _wtoi(strlength);

			tempstr =  theApp.myModuleMain.jinzhi10to16(round((m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.GetCurSel() + 1 )* impulse * m_pCodePrinterDlg->m_Confi->m_repeatDis / length ));
			mypcf0X13_16 = theApp.myModuleMain.stringToLPCWSTR(tempstr);
		}
		strtmp.Format(_T("%s%s"),_T("00000000"),mypcf0X13_16);
		mypcf0X13_16 = strtmp.Mid(mypcf0X13_16.GetLength(), 8);
		theApp.myPcfClass.pcf0X13 = dealXml.HEX_to_DECbyte(mypcf0X13_16.Mid(6, 2));
		theApp.myPcfClass.pcf0X14 = dealXml.HEX_to_DECbyte(mypcf0X13_16.Mid(4, 2));
		theApp.myPcfClass.pcf0X15 = dealXml.HEX_to_DECbyte(mypcf0X13_16.Mid(2, 2));
		theApp.myPcfClass.pcf0X16 = dealXml.HEX_to_DECbyte(mypcf0X13_16.Mid(0, 2));

		//�������ֹ��������
		try
		{
			CString strimpulse,strlength,strtriggerLen;
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_impulse.GetWindowText(strimpulse);
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.GetWindowText(strlength);
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_triggerLen.GetWindowText(strtriggerLen);
			int impulse = _wtoi(strimpulse);
			int length = _wtoi(strlength);
			int triggerLen = _wtoi(strtriggerLen);

			tempstr = theApp.myModuleMain.jinzhi10to16(round((m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.GetCurSel() + 1 )* impulse * triggerLen / length ));
			mypcf0X19_1C = theApp.myModuleMain.stringToLPCWSTR(tempstr);
		}
		catch (CException* e)
		{
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.SetWindowText(_T("200"));

			CString strimpulse,strlength,strtriggerLen;
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_impulse.GetWindowText(strimpulse);
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.GetWindowText(strlength);
			m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_triggerLen.GetWindowText(strtriggerLen);
			int impulse = _wtoi(strimpulse);
			int length = _wtoi(strlength);
			int triggerLen = _wtoi(strtriggerLen);

			tempstr =  theApp.myModuleMain.jinzhi10to16(round((m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.GetCurSel() + 1 )* impulse * triggerLen / length ));
			mypcf0X19_1C = theApp.myModuleMain.stringToLPCWSTR(tempstr);
		}
		strtmp.Format(_T("%s%s"),_T("00000000"),mypcf0X19_1C);
		mypcf0X19_1C = strtmp.Mid(mypcf0X19_1C.GetLength(), 8);
		theApp.myPcfClass.pcf0X19 = dealXml.HEX_to_DECbyte(mypcf0X19_1C.Mid(6, 2));
		theApp.myPcfClass.pcf0X1A = dealXml.HEX_to_DECbyte(mypcf0X19_1C.Mid(4, 2));
		theApp.myPcfClass.pcf0X1B = dealXml.HEX_to_DECbyte(mypcf0X19_1C.Mid(2, 2));
		theApp.myPcfClass.pcf0X1C = dealXml.HEX_to_DECbyte(mypcf0X19_1C.Mid(0, 2));

	}
	 
	//ͬ�������࣬0��A->B��1:B->A
	theApp.myPcfClass.pcf0X00bit2 = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_printDire.GetCurSel();
	//�������м�����ʱ��Ϣ�����Ƿ񻹰�������ӡ����ӡ��������0Ϊ�رգ�1Ϊ����
	theApp.myPcfClass.pcf0X00bit4 = m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_virtualPrint.GetCurSel();
	//pcf0X00����
	theApp.myPcfClass.pcf0X00 = theApp.myPcfClass.pcf0X00bit6 * 64 + theApp.myPcfClass.pcf0X00bit5 * 32 
		+ theApp.myPcfClass.pcf0X00bit4 * 16 + theApp.myPcfClass.pcf0X00bit2 * 4 + theApp.myPcfClass.pcf0X00bit1_bit0;
	//pcf0X00 = IIf(pcf0X00.Length.Equals(2), pcf0X00, "0" & pcf0X00)
	//�Ƿ����õ��ۣ�0Ϊ�رգ�1Ϊ����
	theApp.myPcfClass.pcf0X01bit0 = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_productDete.GetCurSel();
	//������Ч��ƽ��0Ϊ�͵�ƽ��1Ϊ�ߵ�ƽ
	theApp.myPcfClass.pcf0X01bit2 = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_activeLev.GetCurSel();
	//��ӡģʽΪ���λ���������0Ϊ���Σ�1Ϊ����
	theApp.myPcfClass.pcf0X01bit3 = m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_printMode.GetCurSel();
	//pcf0X01����
	theApp.myPcfClass.pcf0X01 = theApp.myPcfClass.pcf0X01bit3 * 8 + theApp.myPcfClass.pcf0X01bit2 * 4 + theApp.myPcfClass.pcf0X01bit0;
	// pcf0X01 = IIf(pcf0X01.Length.Equals(2), pcf0X01, "0" & pcf0X01)
	//�ָ�
	theApp.myPcfClass.pcf0X0A = m_pCodePrinterDlg->m_Confi->m_height;
	// pcf0X0A = IIf(pcf0X0A.Length.Equals(2), pcf0X0A, "0" & pcf0X0A)
	//pcf0X0B_0E = "00000000"
	// pcf0X0F_12 = "00000000"
	// ���뱶Ƶ
	theApp.myPcfClass.pcf0X18 = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.GetCurSel();
 
	//���´����к���;��
	/*
	theApp.myPcfClass.pcf0X02_05 = CT2A(mypcf0X02_05.GetString());
	theApp.myPcfClass.pcf0X06_09 = CT2A(mypcf0X02_05.GetString());
	theApp.myPcfClass.pcf0X13_16 = CT2A(mypcf0X02_05.GetString());
	theApp.myPcfClass.pcf0X19_1C = CT2A(mypcf0X02_05.GetString());
    */ 
/////////////////////////////////////////////////////////////////////////////
#define  xml_def 1

#ifdef xml_def
#else
	theApp.myPcfClass.pcf0X00=0x2;
	theApp.myPcfClass.pcf0X01=0x1;
	theApp.myPcfClass.pcf0X02=0x0;
	theApp.myPcfClass.pcf0X03=0x4b;
	theApp.myPcfClass.pcf0X04=0x0;
	theApp.myPcfClass.pcf0X05=0x0;
	theApp.myPcfClass.pcf0X06=0x51;
	theApp.myPcfClass.pcf0X07=0x0;
	theApp.myPcfClass.pcf0X08=0x0;
	theApp.myPcfClass.pcf0X09=0x0;
	theApp.myPcfClass.pcf0X0A=0x46;
	theApp.myPcfClass.pcf0X13=0x0;
	theApp.myPcfClass.pcf0X14=0xe1;
	theApp.myPcfClass.pcf0X15=0x0;
	theApp.myPcfClass.pcf0X16=0x0;
	theApp.myPcfClass.pcf0X18=0x0;
	theApp.myPcfClass.pcf0X19=0x0;
	theApp.myPcfClass.pcf0X1A=0xe1;
	theApp.myPcfClass.pcf0X1B=0x0;
	theApp.myPcfClass.pcf0X1C=0x0;
#endif

	vector<BYTE> tempCtrVec;
	tempCtrVec.push_back(0x01);
	tempCtrVec.push_back(0x80);

	tempCtrVec.push_back(0x21); //���ݳ��� = 33
	tempCtrVec.push_back(0x01); // ��ʾ�� �ļ�֡

	tempCtrVec.push_back(0x12); //�ļ����ƺ�����(������0X12)
	tempCtrVec.push_back(0x00); //�ļ���
	tempCtrVec.push_back(0x00); //�Ĵ�����ַ����ʾ�Ӵ˵�ַ��ʼд29�����ݣ���0x00-0x1C)

	tempCtrVec.push_back(theApp.myPcfClass.pcf0X00);
	tempCtrVec.push_back(theApp.myPcfClass.pcf0X01);
	tempCtrVec.push_back(theApp.myPcfClass.pcf0X02);
	tempCtrVec.push_back(theApp.myPcfClass.pcf0X03);
	tempCtrVec.push_back(theApp.myPcfClass.pcf0X04);
	tempCtrVec.push_back(theApp.myPcfClass.pcf0X05);
	tempCtrVec.push_back(theApp.myPcfClass.pcf0X06);
	tempCtrVec.push_back(theApp.myPcfClass.pcf0X07);
	tempCtrVec.push_back(theApp.myPcfClass.pcf0X08);
	tempCtrVec.push_back(theApp.myPcfClass.pcf0X09);
	tempCtrVec.push_back(theApp.myPcfClass.pcf0X0A);  //�ָ�

	tempCtrVec.push_back(0);
	tempCtrVec.push_back(0);
	tempCtrVec.push_back(0);
	tempCtrVec.push_back(0);
	tempCtrVec.push_back(0);
	tempCtrVec.push_back(0);
	tempCtrVec.push_back(0);
	tempCtrVec.push_back(0);

	tempCtrVec.push_back(theApp.myPcfClass.pcf0X13);
	tempCtrVec.push_back(theApp.myPcfClass.pcf0X14);
	tempCtrVec.push_back(theApp.myPcfClass.pcf0X15);
	tempCtrVec.push_back(theApp.myPcfClass.pcf0X16);
	tempCtrVec.push_back(0);
	tempCtrVec.push_back(theApp.myPcfClass.pcf0X18);
	tempCtrVec.push_back(theApp.myPcfClass.pcf0X19);
	tempCtrVec.push_back(theApp.myPcfClass.pcf0X1A);
	tempCtrVec.push_back(theApp.myPcfClass.pcf0X1B);
	tempCtrVec.push_back(theApp.myPcfClass.pcf0X1C);

	tempCtrVec.push_back(0xFF);
	tempCtrVec.push_back(0xFF);

	theApp.boQueCtrLock.Lock();
	theApp.queCtr.push(tempCtrVec);
	theApp.boQueCtrLock.Unlock();	
}

int CPcfConfig::round(double r)
{
	int a = (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
	return a;
}

void CPcfConfig::save_pcf_to_xml()
{
	CDealXml dealXml;
	CString pcf_currentname,pcf_currentpath;
	CString strTmp;
	int nCur;

 	m_pCodePrinterDlg->m_Confi->UpdateData();
	m_pCodePrinterDlg->m_Confi->m_ConfigPM->UpdateData();
	m_pCodePrinterDlg->m_Confi->m_ConfigOS->UpdateData();

	//��ǰ���ϴδ򿪵������ļ���
	pcf_currentname = dealXml.ReadXml(_T("PrintConfig.xml"),_T("CurrentName"), _T("Default.pcf"), _T("Storage Card\\System"));
	
	//��ǰ���ϴδ򿪵������ļ���·��
	pcf_currentpath = dealXml.ReadXml(_T("PrintConfig.xml"),_T("CurrentPath"), _T("\Storage Card\System"), _T("Storage Card\\System"));
	
     //����ֹͣ��ӡ(�����ӡ)
 	nCur = m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_virtualPrint.GetCurSel();
    m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_virtualPrint.GetText(nCur,strTmp);
    dealXml.WriteXml(pcf_currentname, L"ErrorStopPrinting", strTmp,pcf_currentpath);

	//��ѹ���ָߣ�
	strTmp.Format(L"%d",m_pCodePrinterDlg->m_Confi->m_height);	
    dealXml.WriteXml(pcf_currentname, L"PrintHeight", strTmp,pcf_currentpath);

	//��ӡ����,������λ����������ʱ�ȷ�ǰ�к�β�У�������β�к�ͷ�У���Ϣѡ��ͨ������ʱ��
	nCur = m_pCodePrinterDlg->m_Confi->m_reverse.GetCurSel();
	m_pCodePrinterDlg->m_Confi->m_reverse.GetLBText(nCur,strTmp);
	dealXml.WriteXml(pcf_currentname, L"Reverse", strTmp,pcf_currentpath);

    //��������,������λ���������Ƿ�ߵ͵�Ե�����Ϣѡ��ͨ������ʱ��
	nCur = m_pCodePrinterDlg->m_Confi->m_inverse.GetCurSel();
	m_pCodePrinterDlg->m_Confi->m_inverse.GetLBText(nCur,strTmp);
	dealXml.WriteXml(pcf_currentname, L"Inverse", strTmp,pcf_currentpath);

	//�����˶���ʽ���̶����ɱ�,,,,Ĭ�Ϲ̶�
	nCur = m_pCodePrinterDlg->m_Confi->m_speedWay.GetCurSel();
	m_pCodePrinterDlg->m_Confi->m_speedWay.GetLBText(nCur,strTmp);
	dealXml.WriteXml(pcf_currentname, L"Way", strTmp,pcf_currentpath);

    //�������ź�����
	nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_encodeSign.GetCurSel();
	m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_encodeSign.GetText(nCur,strTmp);
	dealXml.WriteXml(pcf_currentname, L"EncoderSignal", strTmp,pcf_currentpath);

    //��������Ƶ
	nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.GetCurSel();
	m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.GetLBText(nCur,strTmp);
	dealXml.WriteXml(pcf_currentname, L"FrequencyMultiplier", strTmp,pcf_currentpath);

	//�м��,Ĭ��Ϊ�ڲ���������ԼΪ800���ٶ�Ϊ20��/���ӣ�6���ֿ�Ϊ2.54mm
	strTmp.Format(L"%.3f",m_pCodePrinterDlg->m_Confi->m_dotPitch);	
    dealXml.WriteXml(pcf_currentname, L"DotPitch", strTmp,pcf_currentpath);

	//�����˶��ٶ�
	strTmp.Format(L"%d",m_pCodePrinterDlg->m_Confi->m_speed);	
    dealXml.WriteXml(pcf_currentname, L"Speed", strTmp,pcf_currentpath);

    //�ӳپ���
	strTmp.Format(L"%d",m_pCodePrinterDlg->m_Confi->m_delay);	
    dealXml.WriteXml(pcf_currentname, L"Delay", strTmp,pcf_currentpath);

	//��ӡģʽ
	nCur = m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_printMode.GetCurSel();
	m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_printMode.GetText(nCur,strTmp);
	dealXml.WriteXml(pcf_currentname, L"PrintMode", strTmp,pcf_currentpath);

    //�����������
	strTmp.Format(L"%d",m_pCodePrinterDlg->m_Confi->m_repeatDis);	
    dealXml.WriteXml(pcf_currentname, L"RepeatDistance", strTmp,pcf_currentpath);

    //�Ƿ����õ���
	nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_productDete.GetCurSel();
	m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_productDete.GetText(nCur,strTmp);
	dealXml.WriteXml(pcf_currentname, L"ProductSensor", strTmp,pcf_currentpath);

    //������Ч��ƽ
	nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_activeLev.GetCurSel();
	m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_activeLev.GetText(nCur,strTmp);
	dealXml.WriteXml(pcf_currentname, L"ActiveLevel", strTmp,pcf_currentpath);


	//������ǰ������
	nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_printDire.GetCurSel();
	m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_printDire.GetText(nCur,strTmp);
	dealXml.WriteXml(pcf_currentname, L"ForwardDirection", strTmp,pcf_currentpath);

	//������1ת������
	m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_impulse.GetWindowText(strTmp);
    dealXml.WriteXml(pcf_currentname, L"ImpulsesRoration", strTmp,pcf_currentpath);

	//ͬ�����ܳ�
 	m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.GetWindowText(strTmp);
    dealXml.WriteXml(pcf_currentname, L"Cirumference", strTmp,pcf_currentpath);

	//�������ֹ��������
 	m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_triggerLen.GetWindowText(strTmp);
    dealXml.WriteXml(pcf_currentname, L"TriggerLength", strTmp,pcf_currentpath);

}

void CPcfConfig::savePcfToXml(string pcfNamePath)
{
	CDealXml dealXml;
	CString pcf_currentname,pcf_currentpath;
	CString strTmp;
	int nCur;

	m_pCodePrinterDlg->m_Confi->UpdateData();
	m_pCodePrinterDlg->m_Confi->m_ConfigPM->UpdateData();
	m_pCodePrinterDlg->m_Confi->m_ConfigOS->UpdateData();

	string strPathName=pcfNamePath;
	int lastN=strPathName.find_last_of('\\');
	pcf_currentname = theApp.myModuleMain.string2CString(strPathName.substr(lastN + 1));
	pcf_currentpath= theApp.myModuleMain.string2CString(strPathName.substr(0,lastN));
	if (pcf_currentname.Mid(pcf_currentname.GetLength()-4,1)!=".")
	{
		pcf_currentpath=_T("Storage Card\\User\\PrintConfig");
		pcf_currentname=_T("Default.pcf");
	}
	m_pcfName=pcf_currentname;
	//��ǰ���ϴδ򿪵������ļ���
	//pcf_currentname = dealXml.ReadXml(_T("PrintConfig.xml"),_T("CurrentName"), _T("Default.pcf"), _T("Storage Card\\System"));

	//��ǰ���ϴδ򿪵������ļ���·��
	//pcf_currentpath = dealXml.ReadXml(_T("PrintConfig.xml"),_T("CurrentPath"), _T("\Storage Card\System"), _T("Storage Card\\System"));

	//����ֹͣ��ӡ(�����ӡ)
	nCur = m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_virtualPrint.GetCurSel();
	m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_virtualPrint.GetText(nCur,strTmp);
	dealXml.WriteXml(pcf_currentname, L"ErrorStopPrinting", strTmp,pcf_currentpath);

	//��ѹ���ָߣ�
	strTmp.Format(L"%d",m_pCodePrinterDlg->m_Confi->m_height);	
	dealXml.WriteXml(pcf_currentname, L"PrintHeight", strTmp,pcf_currentpath);

	//��ӡ����,������λ����������ʱ�ȷ�ǰ�к�β�У�������β�к�ͷ�У���Ϣѡ��ͨ������ʱ��
	nCur = m_pCodePrinterDlg->m_Confi->m_reverse.GetCurSel();
	m_pCodePrinterDlg->m_Confi->m_reverse.GetLBText(nCur,strTmp);
	dealXml.WriteXml(pcf_currentname, L"Reverse", strTmp,pcf_currentpath);

	//��������,������λ���������Ƿ�ߵ͵�Ե�����Ϣѡ��ͨ������ʱ��
	nCur = m_pCodePrinterDlg->m_Confi->m_inverse.GetCurSel();
	m_pCodePrinterDlg->m_Confi->m_inverse.GetLBText(nCur,strTmp);
	dealXml.WriteXml(pcf_currentname, L"Inverse", strTmp,pcf_currentpath);

	//�����˶���ʽ���̶����ɱ�,,,,Ĭ�Ϲ̶�
	nCur = m_pCodePrinterDlg->m_Confi->m_speedWay.GetCurSel();
	m_pCodePrinterDlg->m_Confi->m_speedWay.GetLBText(nCur,strTmp);
	dealXml.WriteXml(pcf_currentname, L"Way", strTmp,pcf_currentpath);

	//�������ź�����
	nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_encodeSign.GetCurSel();
	m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_encodeSign.GetText(nCur,strTmp);
	dealXml.WriteXml(pcf_currentname, L"EncoderSignal", strTmp,pcf_currentpath);

	//��������Ƶ
	nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.GetCurSel();
	m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_FreqMulti.GetLBText(nCur,strTmp);
	dealXml.WriteXml(pcf_currentname, L"FrequencyMultiplier", strTmp,pcf_currentpath);

	//�м��,Ĭ��Ϊ�ڲ���������ԼΪ800���ٶ�Ϊ20��/���ӣ�6���ֿ�Ϊ2.54mm
	strTmp.Format(L"%.3f",m_pCodePrinterDlg->m_Confi->m_dotPitch);	
	dealXml.WriteXml(pcf_currentname, L"DotPitch", strTmp,pcf_currentpath);

	//�����˶��ٶ�
	strTmp.Format(L"%d",m_pCodePrinterDlg->m_Confi->m_speed);	
	dealXml.WriteXml(pcf_currentname, L"Speed", strTmp,pcf_currentpath);

	//�ӳپ���
	strTmp.Format(L"%d",m_pCodePrinterDlg->m_Confi->m_delay);	
	dealXml.WriteXml(pcf_currentname, L"Delay", strTmp,pcf_currentpath);

	//��ӡģʽ
	nCur = m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_printMode.GetCurSel();
	m_pCodePrinterDlg->m_Confi->m_ConfigPM->m_printMode.GetText(nCur,strTmp);
	dealXml.WriteXml(pcf_currentname, L"PrintMode", strTmp,pcf_currentpath);

	//�����������
	strTmp.Format(L"%d",m_pCodePrinterDlg->m_Confi->m_repeatDis);	
	dealXml.WriteXml(pcf_currentname, L"RepeatDistance", strTmp,pcf_currentpath);

	//�Ƿ����õ���
	nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_productDete.GetCurSel();
	m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_productDete.GetText(nCur,strTmp);
	dealXml.WriteXml(pcf_currentname, L"ProductSensor", strTmp,pcf_currentpath);

	//������Ч��ƽ
	nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_activeLev.GetCurSel();
	m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_activeLev.GetText(nCur,strTmp);
	dealXml.WriteXml(pcf_currentname, L"ActiveLevel", strTmp,pcf_currentpath);


	//������ǰ������
	nCur = m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_printDire.GetCurSel();
	m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_printDire.GetText(nCur,strTmp);
	dealXml.WriteXml(pcf_currentname, L"ForwardDirection", strTmp,pcf_currentpath);

	//������1ת������
	m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_impulse.GetWindowText(strTmp);
	dealXml.WriteXml(pcf_currentname, L"ImpulsesRoration", strTmp,pcf_currentpath);

	//ͬ�����ܳ�
	m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_length.GetWindowText(strTmp);
	dealXml.WriteXml(pcf_currentname, L"Cirumference", strTmp,pcf_currentpath);

	//�������ֹ��������
	m_pCodePrinterDlg->m_Confi->m_ConfigOS->m_triggerLen.GetWindowText(strTmp);
	dealXml.WriteXml(pcf_currentname, L"TriggerLength", strTmp,pcf_currentpath);
}