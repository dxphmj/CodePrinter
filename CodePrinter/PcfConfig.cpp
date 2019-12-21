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
	//��ǰ���ϴδ򿪵������ļ���
	pcf_currentname = dealXml.ReadXml(_T("inksystem.xml"),_T("CurrentName"), _T("Default.pcf"), _T("Storage Card\\System"));
	//��ǰ���ϴδ򿪵������ļ���·��
	pcf_currentpath = dealXml.ReadXml(_T("inksystem.xml"),_T("CurrentName"), _T("\Storage Card\System"), _T("Storage Card\\System"));
	bool isFileExit = true;

	if (isFileExit)//����ϴδ򿪵������ļ�������򿪸��ļ����������Ĭ�������ļ�
	{
		CString tempstr;
		
		//strLABlabForMName = pcf_currentname;
		////����ֹͣ��ӡ
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("ErrorStopPrinting"), _T("OFF"), pcf_currentpath);
		////��ѹ���ָߣ�
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("PrintHeight"), _T("70"), pcf_currentpath);
		////��ӡ����,,,,������λ����������ʱ�ȷ�ǰ�к�β�У�������β�к�ͷ�У���Ϣѡ��ͨ������ʱ��
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("Reverse"), _T("OFF"), pcf_currentpath);
		////��������,,,,������λ���������Ƿ�ߵ͵�Ե�����Ϣѡ��ͨ������ʱ��
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("Inverse"), _T("OFF"), pcf_currentpath);
		////�����˶���ʽ���̶����ɱ�,,,,Ĭ�Ϲ̶�
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("Way"), _T("Fixed"), pcf_currentpath);
		////�������ź�����
		//tempstr = dealXml.ReadXml(pcf_currentname,_T("EncoderSignal"), _T("2 Phase"), pcf_currentpath);
		////��������Ƶ
		//cmbval_pcf_external_fremul.Items.Clear();
		//if ()
		//{
		//}
	}
}

void CPcfConfig::download_pcf()
{

}
