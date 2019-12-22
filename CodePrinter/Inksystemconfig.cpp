#include "StdAfx.h"
#include "Inksystemconfig.h"
#include "resource.h"
#include "CodePrinterDlg.h"
#include "DealXml.h"

CInksystemconfig::CInksystemconfig(CCodePrinterDlg* pCodeDlg)
{
	m_pCodePrinterDlg = pCodeDlg;
}

CInksystemconfig::~CInksystemconfig(void)
{
}

void CInksystemconfig::get_inksystem_from_xml()
{
	CDealXml dealXml;
	//m_pCodePrinterDlg->m_Ink->m_setup->
	//����Ĭ������������
	CString str = dealXml.ReadXml(_T("inksystem.xml"),_T("Peltier"), _T("OFF"), _T("Storage Card\\System"));
	//����Ĭ��˯�߿���
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("Sleep"), _T("OFF"), _T("Storage Card\\System"));
	//����Ĭ�Ͼ���Ƶ��
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("ModulationFrequency"), _T("64000"), _T("Storage Card\\System"));
	//����Ĭ������ߴ�
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("NozzleSize"), _T("60"), _T("Storage Card\\System"));
	//����Ĭ��īˮ�ͺ�
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("InkType"), _T("236"), _T("Storage Card\\System"));
	//����Ĭ�����õ�ѹ��
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("Pressure"), _T("3000"), _T("Storage Card\\System"));
	//����Ĭ�����õı���
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("BumpSpeed"), _T("1500"), _T("Storage Card\\System"));
	//����Ĭ�����õ���ͷ�¶�
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("PrintHeadTemp"), _T("24"), _T("Storage Card\\System"));
	//����Ĭ�����õķ��ѵ�ѹģʽΪ�̶���ѹ
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("ModulationMode"), _T("0"), _T("Storage Card\\System"));
	if (str == _T("0"))
	{
		theApp.myStatusClass.ctr0X03bit6 = 0;
		//picbtn_inksystem_pha_mv_auto.Image = My.Resources.ResourceBng.bm043
	} 
	else if(str == _T("1"))
	{
		theApp.myStatusClass.ctr0X03bit6 = 1;
		//picbtn_inksystem_pha_mv_auto.Image = My.Resources.ResourceBng.bm044
	}
	//����Ĭ�����õķ��ѵ�ѹ����Ϊ10V
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("ModulationStep"), _T("10"), _T("Storage Card\\System"));
	if (str == _T("10"))
	{
		theApp.myStatusClass.bytModuStep = 10;
		//picbtn_inksystem_pha_mv_10.Image = My.Resources.ResourceBng.bm044
			//picbtn_inksystem_pha_mv_1.Image = My.Resources.ResourceBng.bm043
			//picbtn_inksystem_pha_mv_10.Enabled = False
			//picbtn_inksystem_pha_mv_1.Enabled = True
	} 
	else if(str == _T("1"))
	{
		theApp.myStatusClass.bytModuStep = 1;
		//picbtn_inksystem_pha_mv_10.Image = My.Resources.ResourceBng.bm043
			//picbtn_inksystem_pha_mv_1.Image = My.Resources.ResourceBng.bm044
			//picbtn_inksystem_pha_mv_10.Enabled = True
			//picbtn_inksystem_pha_mv_1.Enabled = False
	}
	//����Ĭ�����õķ��ѵ�ѹ
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("ModulationVoltage"), _T("100"), _T("Storage Card\\System"));
	//theApp.myStatusClass.bytModuVol = CByte(texval_inksystem_pha_mv.Text);
	//����Ĭ�����õ�īˮ�߱���Һλ
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("InkFlowLevel"), _T("150"), _T("Storage Card\\System"));
	//����Ĭ�����õ�īˮ���ӱ���Һλ
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("InkAddLevel"), _T("30"), _T("Storage Card\\System"));
	//����Ĭ�����õ�īˮ�ձ���Һλ
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("InkEmptyLevel"), _T("10"), _T("Storage Card\\System"));
	//����Ĭ�����õ��ܼ��߱���Һλ
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("SolventFlowLevel"), _T("150"), _T("Storage Card\\System"));
	//����Ĭ�����õ��ܼ����ӱ���Һλ
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("SolventAddLevel"), _T("30"), _T("Storage Card\\System"));
	//����Ĭ�����õ��ܼ��ձ���Һλ
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("SolventEmptyLevel"), _T("10"), _T("Storage Card\\System"));
	//����Ĭ�����õ�īˮճ���������ٷֱ�
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("ViscoDeviation"), _T("15"), _T("Storage Card\\System"));
}

void CInksystemconfig::download_inksystem_setup()
{
	CString tempStr;
	CDealXml dealXml;
	BYTE inksystem_setup_0x00, inksystem_setup_0x01, inksystem_setup_0x02, inksystem_setup_0x03, inksystem_setup_0x04, inksystem_setup_0x05, inksystem_setup_0x06, inksystem_setup_0x07, inksystem_setup_0x08, inksystem_setup_0x09, inksystem_setup_0x0a, inksystem_setup_0x0b, inksystem_setup_0x0c, inksystem_setup_0x0d, inksystem_setup_0x0e;
	//inksystem_setup_0x00 = CByte(lisval_inksystem_setup_pe.SelectedIndex * 128 + lisval_inksystem_setup_sl.SelectedIndex * 64);
	vector<BYTE> tempCtrVec;
	inksystem_setup_0x01 = 0;
	//����Ĭ��īˮ��ճ�ȱ�
	CString inksystem_setup_it = _T("236");
	//CString inksystem_setup_it  = lisval_inksystem_setup_it.SelectedItem;
	int nParam = _wtoi(inksystem_setup_it.GetBuffer(0));
 //   inksystem_setup_0x02 = nParam;

	//inksystem_setup_0x02 = nParam & 0xFF;
 //   inksystem_setup_0x03 = nParam >> 8;
	tempStr = dealXml.ReadXml(_T("inksystem.xml"),_T("Type") + inksystem_setup_it + _T("degC01"), _T("126"), _T("Storage Card\\System"));
	inksystem_setup_0x02 = _wtoi(tempStr.GetBuffer(0));
	tempStr = dealXml.ReadXml(_T("inksystem.xml"),_T("Type") + inksystem_setup_it + _T("degC02"), _T("117"), _T("Storage Card\\System"));
	inksystem_setup_0x03 = _wtoi(tempStr.GetBuffer(0));
	tempStr = dealXml.ReadXml(_T("inksystem.xml"),_T("Type") + inksystem_setup_it + _T("degC03"), _T("109"), _T("Storage Card\\System"));
	inksystem_setup_0x04 = _wtoi(tempStr.GetBuffer(0));
	tempStr = dealXml.ReadXml(_T("inksystem.xml"),_T("Type") + inksystem_setup_it + _T("degC04"), _T("102"), _T("Storage Card\\System"));
	inksystem_setup_0x05 = _wtoi(tempStr.GetBuffer(0));
	tempStr = dealXml.ReadXml(_T("inksystem.xml"),_T("Type") + inksystem_setup_it + _T("degC05"), _T("95"), _T("Storage Card\\System"));
	inksystem_setup_0x06 = _wtoi(tempStr.GetBuffer(0));
	tempStr = dealXml.ReadXml(_T("inksystem.xml"),_T("Type") + inksystem_setup_it + _T("degC06"), _T("89"), _T("Storage Card\\System"));
	inksystem_setup_0x07 = _wtoi(tempStr.GetBuffer(0));
	tempStr = dealXml.ReadXml(_T("inksystem.xml"),_T("Type") + inksystem_setup_it + _T("degC07"), _T("84"), _T("Storage Card\\System"));
	inksystem_setup_0x08 = _wtoi(tempStr.GetBuffer(0));
	tempStr = dealXml.ReadXml(_T("inksystem.xml"),_T("Type") + inksystem_setup_it + _T("degC08"), _T("79"), _T("Storage Card\\System"));
	inksystem_setup_0x09 = _wtoi(tempStr.GetBuffer(0));
	tempStr = dealXml.ReadXml(_T("inksystem.xml"),_T("Type") + inksystem_setup_it + _T("degC09"), _T("74"), _T("Storage Card\\System"));
	inksystem_setup_0x0a = _wtoi(tempStr.GetBuffer(0));
	tempStr = dealXml.ReadXml(_T("inksystem.xml"),_T("Type") + inksystem_setup_it + _T("degC010"), _T("70"), _T("Storage Card\\System"));
	inksystem_setup_0x0b = _wtoi(tempStr.GetBuffer(0));
	tempStr = dealXml.ReadXml(_T("inksystem.xml"),_T("Type") + inksystem_setup_it + _T("degC011"), _T("66"), _T("Storage Card\\System"));
	inksystem_setup_0x0c = _wtoi(tempStr.GetBuffer(0));
	tempStr = dealXml.ReadXml(_T("inksystem.xml"),_T("Type") + inksystem_setup_it + _T("degC012"), _T("62"), _T("Storage Card\\System"));
	inksystem_setup_0x0d = _wtoi(tempStr.GetBuffer(0));
	tempStr = dealXml.ReadXml(_T("inksystem.xml"),_T("Type") + inksystem_setup_it + _T("degC013"), _T("59"), _T("Storage Card\\System"));
	inksystem_setup_0x0e = _wtoi(tempStr.GetBuffer(0));

	tempCtrVec.push_back(0x01);
	tempCtrVec.push_back(0x80);
	tempCtrVec.push_back(0x10);
	tempCtrVec.push_back(0x04);
	tempCtrVec.push_back(inksystem_setup_0x00);
	tempCtrVec.push_back(inksystem_setup_0x01);
	tempCtrVec.push_back(inksystem_setup_0x02);
	tempCtrVec.push_back(inksystem_setup_0x03);
	tempCtrVec.push_back(inksystem_setup_0x04);
	tempCtrVec.push_back(inksystem_setup_0x05);
	tempCtrVec.push_back(inksystem_setup_0x06);
	tempCtrVec.push_back(inksystem_setup_0x07);
	tempCtrVec.push_back(inksystem_setup_0x08);
	tempCtrVec.push_back(inksystem_setup_0x09);
	tempCtrVec.push_back(inksystem_setup_0x0a);
	tempCtrVec.push_back(inksystem_setup_0x0b);
	tempCtrVec.push_back(inksystem_setup_0x0c);
	tempCtrVec.push_back(inksystem_setup_0x0d);
	tempCtrVec.push_back(inksystem_setup_0x0e);
	tempCtrVec.push_back(0xFF);
	tempCtrVec.push_back(0xFF);

	theApp.boQueCtrLock.Lock();
	theApp.queCtr.push(tempCtrVec);
	theApp.boQueCtrLock.Unlock();
}


void CInksystemconfig::download_inksystem_parameter()
{
	CDealXml dealXml;
	CString tempStr;
	vector<BYTE> tempCtrVec;
	BYTE inksystem_parameter_0x00, inksystem_parameter_0x01, inksystem_parameter_0x02, inksystem_parameter_0x03, inksystem_parameter_0x04, inksystem_parameter_0x05, inksystem_parameter_0x06, inksystem_parameter_0x07, inksystem_parameter_0x08, inksystem_parameter_0x09, inksystem_parameter_0x0a, inksystem_parameter_0x0b, inksystem_parameter_0x0c, inksystem_parameter_0x0d;	

	//tempStr = texval_inksystem_para_pre.Text;
	int nParam = _wtoi(tempStr.GetBuffer(0));
	inksystem_parameter_0x00 = nParam & 0xFF;
	inksystem_parameter_0x01 = nParam >> 8;
	
	//tempStr = texval_inksystem_para_bs.Text;
	nParam = _wtoi(tempStr.GetBuffer(0));
	inksystem_parameter_0x02 = nParam & 0xFF;
	inksystem_parameter_0x03 = nParam >> 8;

	//tempStr = texval_inksystem_para_pt.Text;
	inksystem_parameter_0x04 = _wtoi(tempStr.GetBuffer(0));
	
	//tempStr = texval_inksystem_pha_mv.Text;
	nParam = _wtoi(tempStr.GetBuffer(0));
	inksystem_parameter_0x05 = (nParam * 10) & 0xFF; //�����ѹΪ0��200
	inksystem_parameter_0x06 = (nParam * 10) >> 8;

	//tempStr = texval_inksystem_para_ifl.Text;
	inksystem_parameter_0x07 = _wtoi(tempStr.GetBuffer(0));//īˮ�߱���ҺλΪ100��150

	//tempStr = texval_inksystem_para_ial.Text;
	inksystem_parameter_0x08 = _wtoi(tempStr.GetBuffer(0)); //īˮ���ӱ���ҺλΪ20��100

	//tempStr = texval_inksystem_para_iel.Text;
	inksystem_parameter_0x09 = _wtoi(tempStr.GetBuffer(0)); //īˮ�ձ���ҺλΪ10��������-7��

	//tempStr = texval_inksystem_para_sfl.Text;
	inksystem_parameter_0x0a = _wtoi(tempStr.GetBuffer(0)); //�ܼ��߱���ҺλΪ100��150

	//tempStr = texval_inksystem_para_sal.Text;
	inksystem_parameter_0x0b = _wtoi(tempStr.GetBuffer(0)); //�ܼ����ӱ���ҺλΪ20��100

	//tempStr = texval_inksystem_para_sel.Text;
	inksystem_parameter_0x0c = _wtoi(tempStr.GetBuffer(0)); //�ܼ��ձ���ҺλΪ10��������-7��

	//tempStr = texval_inksystem_para_vd.Text;
	inksystem_parameter_0x0d = _wtoi(tempStr.GetBuffer(0)); //ճ����Χ1��100



	tempCtrVec.push_back(0x01);
	tempCtrVec.push_back(0x80);
	tempCtrVec.push_back(0x10);
	tempCtrVec.push_back(0x05);
	tempCtrVec.push_back(0x00);
	tempCtrVec.push_back(inksystem_parameter_0x00);
	tempCtrVec.push_back(inksystem_parameter_0x01);
	tempCtrVec.push_back(inksystem_parameter_0x02);
	tempCtrVec.push_back(inksystem_parameter_0x03);
	tempCtrVec.push_back(inksystem_parameter_0x04);
	tempCtrVec.push_back(inksystem_parameter_0x05);
	tempCtrVec.push_back(inksystem_parameter_0x06);
	tempCtrVec.push_back(inksystem_parameter_0x07);
	tempCtrVec.push_back(inksystem_parameter_0x08);
	tempCtrVec.push_back(inksystem_parameter_0x09);
	tempCtrVec.push_back(inksystem_parameter_0x0a);
	tempCtrVec.push_back(inksystem_parameter_0x0b);
	tempCtrVec.push_back(inksystem_parameter_0x0c);
	tempCtrVec.push_back(inksystem_parameter_0x0d);
	tempCtrVec.push_back(0xFF);
	tempCtrVec.push_back(0xFF);

	theApp.boQueCtrLock.Lock();
	theApp.queCtr.push(tempCtrVec);
	theApp.boQueCtrLock.Unlock();
}