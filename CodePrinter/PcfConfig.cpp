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
	//��ǰ���ϴδ򿪵������ļ���
	pcf_currentname = dealXml.ReadXml(_T("inksystem.xml"),_T("CurrentName"), _T("Default.pcf"), _T("Storage Card\\System"));
	//��ǰ���ϴδ򿪵������ļ���·��
	pcf_currentpath = dealXml.ReadXml(_T("inksystem.xml"),_T("CurrentName"), _T("\Storage Card\System"), _T("Storage Card\\System"));
	bool isFileExit = true;

	if (isFileExit)//����ϴδ򿪵������ļ�������򿪸��ļ����������Ĭ�������ļ�
	{
		CString tempstr;
		//m_pCodePrinterDlg->m_Confi->m_ConfigPrintModeDlg->
		strLABlabForMName = pcf_currentname;
		//����ֹͣ��ӡ(�����ӡ)
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ErrorStopPrinting"), _T("OFF"), pcf_currentpath);
		//��ѹ���ָߣ�
		tempstr = dealXml.ReadXml(pcf_currentname,_T("PrintHeight"), _T("70"), pcf_currentpath);
		//��ӡ����,,,,������λ����������ʱ�ȷ�ǰ�к�β�У�������β�к�ͷ�У���Ϣѡ��ͨ������ʱ��
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Reverse"), _T("OFF"), pcf_currentpath);
		//��������,,,,������λ���������Ƿ�ߵ͵�Ե�����Ϣѡ��ͨ������ʱ��
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Inverse"), _T("OFF"), pcf_currentpath);
		//�����˶���ʽ���̶����ɱ�,,,,Ĭ�Ϲ̶�
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Way"), _T("Fixed"), pcf_currentpath);
		//�������ź�����
		tempstr = dealXml.ReadXml(pcf_currentname,_T("EncoderSignal"), _T("2 Phase"), pcf_currentpath);
		//��������Ƶ
		//cmbval_pcf_external_fremul.Items.Clear();
		//if ()
		//{
		//	
		//}
		tempstr = dealXml.ReadXml(pcf_currentname,_T("FrequencyMultiplier"), _T("OFF"), pcf_currentpath);
		//�м��,,,,Ĭ��Ϊ�ڲ���������ԼΪ800���ٶ�Ϊ20��/���ӣ�6���ֿ�Ϊ2.54mm
		tempstr = dealXml.ReadXml(pcf_currentname,_T("DotPitch"), _T("0.423"), pcf_currentpath);
		//����Ӵ֣��ݲ�����
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("Density"), _T("1"), pcf_currentpath);
		//�����˶��ٶ�
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Speed"), _T("20"), pcf_currentpath);
		//�ӳپ���
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Delay"), _T("100"), pcf_currentpath);
		//��ӡģʽ
		tempstr = dealXml.ReadXml(pcf_currentname,_T("PrintMode"), _T("OFF"), pcf_currentpath);
		//�����������
		tempstr = dealXml.ReadXml(pcf_currentname,_T("RepeatDistance"), _T("100"), pcf_currentpath);
		//�ظ�����ֵ
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("RepeatCount"), _T("0"), pcf_currentpath);
		//�����б��˰汾�����ã�
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("JoblistEnable"), _T("OFF"), pcf_currentpath);
		//�Ƿ����õ���
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ProductSensor"), _T("ON"), pcf_currentpath);
		//������Ч��ƽ
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ActiveLevel"), _T("Low"), pcf_currentpath);
		//������ǰ������
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ForwardDirection"), _T("Forward"), pcf_currentpath);
		//������1ת������
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ImpulsesRoration"), _T("2500"), pcf_currentpath);
		//ͬ�����ܳ�
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Cirumference"), _T("200"), pcf_currentpath);
		//�������ֹ��������
		tempstr = dealXml.ReadXml(pcf_currentname,_T("TriggerLength"), _T("300"), pcf_currentpath);
		//labval_gui_pcf.Text = pcf_currentname;	
	}
	else
	{
		CString tempstr;
		
		//labval_gui_pcf.Text = _T("Default");
		strLABlabForMName = pcf_currentname;
		//����ֹͣ��ӡ(�����ӡ)
		//m_pCodePrinterDlg->m_Confi->m_ConfigPrintModeDlg-> = dealXml.ReadXml(pcf_currentname,_T("ErrorStopPrinting"), _T("OFF"), pcf_currentpath);
		//��ѹ���ָߣ�
		tempstr = dealXml.ReadXml(pcf_currentname,_T("PrintHeight"), _T("70"), pcf_currentpath);
		//��ӡ����,,,,������λ����������ʱ�ȷ�ǰ�к�β�У�������β�к�ͷ�У���Ϣѡ��ͨ������ʱ��
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Reverse"), _T("OFF"), pcf_currentpath);
		//��������,,,,������λ���������Ƿ�ߵ͵�Ե�����Ϣѡ��ͨ������ʱ��
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Inverse"), _T("OFF"), pcf_currentpath);
		//�����˶���ʽ���̶����ɱ�,,,,Ĭ�Ϲ̶�
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Way"), _T("Fixed"), pcf_currentpath);
		//�������ź�����
		tempstr = dealXml.ReadXml(pcf_currentname,_T("EncoderSignal"), _T("2 Phase"), pcf_currentpath);
		//��������Ƶ
		//cmbval_pcf_external_fremul.Items.Clear();
		//if ()
		//{

		//}
		tempstr = dealXml.ReadXml(pcf_currentname,_T("FrequencyMultiplier"), _T("OFF"), pcf_currentpath);
		//�м��,,,,Ĭ��Ϊ�ڲ���������ԼΪ800���ٶ�Ϊ20��/���ӣ�6���ֿ�Ϊ2.54mm
		tempstr = dealXml.ReadXml(pcf_currentname,_T("DotPitch"), _T("0.423"), pcf_currentpath);
		//����Ӵ֣��ݲ�����
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("Density"), _T("1"), pcf_currentpath);
		//�����˶��ٶ�
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Speed"), _T("20"), pcf_currentpath);
		//�ӳپ���
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Delay"), _T("100"), pcf_currentpath);
		//��ӡģʽ
		tempstr = dealXml.ReadXml(pcf_currentname,_T("PrintMode"), _T("OFF"), pcf_currentpath);
		//�����������
		tempstr = dealXml.ReadXml(pcf_currentname,_T("RepeatDistance"), _T("100"), pcf_currentpath);
		//�ظ�����ֵ
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("RepeatCount"), _T("0"), pcf_currentpath);
		//�����б��˰汾�����ã�
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("JoblistEnable"), _T("OFF"), pcf_currentpath);
		//�Ƿ����õ���
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ProductSensor"), _T("ON"), pcf_currentpath);
		//������Ч��ƽ
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ActiveLevel"), _T("Low"), pcf_currentpath);
		//������ǰ������
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ForwardDirection"), _T("Forward"), pcf_currentpath);
		//������1ת������
		tempstr = dealXml.ReadXml(pcf_currentname,_T("ImpulsesRoration"), _T("2500"), pcf_currentpath);
		//ͬ�����ܳ�
		tempstr = dealXml.ReadXml(pcf_currentname,_T("Cirumference"), _T("200"), pcf_currentpath);
		//�������ֹ��������
		tempstr = dealXml.ReadXml(pcf_currentname,_T("TriggerLength"), _T("300"), pcf_currentpath);		
	}
}

void CPcfConfig::download_pcf()
{
	
}
