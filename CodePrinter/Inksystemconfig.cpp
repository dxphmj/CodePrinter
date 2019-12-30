#include "StdAfx.h"
#include "Inksystemconfig.h"
#include "resource.h"
#include "CodePrinterDlg.h"
#include "DealXml.h"
#include <vector>

using namespace std;
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
	CString str = NULL;

	//����Ĭ������������
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("Peltier"), _T("OFF"), _T("Storage Card\\System"));
	int nCur = m_pCodePrinterDlg->m_Ink->m_setup->m_sleepList.SelectString(0,str);
	m_pCodePrinterDlg->m_Ink->m_setup->m_peltierList.SetCurSel(nCur);	
 
	//����Ĭ��˯�߿���
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("Sleep"), _T("OFF"), _T("Storage Card\\System"));
	nCur = m_pCodePrinterDlg->m_Ink->m_setup->m_sleepList.SelectString(0,str);
	m_pCodePrinterDlg->m_Ink->m_setup->m_sleepList.SetCurSel(nCur);
	
	//����Ĭ�Ͼ���Ƶ��
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("ModulationFrequency"), _T("64000"), _T("Storage Card\\System"));
	nCur = m_pCodePrinterDlg->m_Ink->m_setup->m_modulFreList.SelectString(0,str);
	m_pCodePrinterDlg->m_Ink->m_setup->m_modulFreList.SetCurSel(nCur);
	
	//����Ĭ������ߴ�
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("NozzleSize"), _T("60"), _T("Storage Card\\System"));
	nCur = m_pCodePrinterDlg->m_Ink->m_setup->m_sizeList.SelectString(0,str);
	m_pCodePrinterDlg->m_Ink->m_setup->m_sizeList.SetCurSel(nCur);
	
	//����Ĭ��īˮ�ͺ�
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("InkType"), _T("236"), _T("Storage Card\\System"));
	nCur = m_pCodePrinterDlg->m_Ink->m_setup->m_inkTypeList.SelectString(0,str);
	m_pCodePrinterDlg->m_Ink->m_setup->m_inkTypeList.SetCurSel(nCur);
	
	//����Ĭ�����õ�ѹ��
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("Pressure"), _T("3000"), _T("Storage Card\\System"));
	m_pCodePrinterDlg->m_Ink->m_par->m_parPressure = _wtoi(str);
	
	//����Ĭ�����õı���
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("BumpSpeed"), _T("1500"), _T("Storage Card\\System"));
	m_pCodePrinterDlg->m_Ink->m_par->m_parPumpSpeed = _wtoi(str);

	//����Ĭ�����õ���ͷ�¶�
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("PrintHeadTemp"), _T("24"), _T("Storage Card\\System"));
	m_pCodePrinterDlg->m_Ink->m_par->m_printheadTemp = _wtoi(str);


	//����Ĭ�����õķ��ѵ�ѹģʽΪ�̶���ѹ
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("ModulationMode"), _T("0"), _T("Storage Card\\System"));
	int errtest = str.Compare(_T("0"));
	if (str.Compare(_T("0")) == 0)
	{
		theApp.myStatusClass.ctr0X03bit6 = 0;
		//picbtn_inksystem_pha_mv_auto.Image = My.Resources.ResourceBng.bm043
	} 
	else if(str.Compare(_T("1")) == 0)
	{
		theApp.myStatusClass.ctr0X03bit6 = 1;
		//picbtn_inksystem_pha_mv_auto.Image = My.Resources.ResourceBng.bm044
	}

	//����Ĭ�����õķ��ѵ�ѹ����Ϊ10V
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("ModulationStep"), _T("10"), _T("Storage Card\\System"));
	if (str.Compare(_T("10")) == 0)
	{
		theApp.myStatusClass.bytModuStep = 10;
		//picbtn_inksystem_pha_mv_10.Image = My.Resources.ResourceBng.bm044
		//picbtn_inksystem_pha_mv_1.Image = My.Resources.ResourceBng.bm043
		//picbtn_inksystem_pha_mv_10.Enabled = False
		//picbtn_inksystem_pha_mv_1.Enabled = True
	} 
	else if(str.Compare(_T("1")) == 0)
	{
		theApp.myStatusClass.bytModuStep = 1;
 		//picbtn_inksystem_pha_mv_10.Image = My.Resources.ResourceBng.bm043
		//picbtn_inksystem_pha_mv_1.Image = My.Resources.ResourceBng.bm044
		//picbtn_inksystem_pha_mv_10.Enabled = True
		//picbtn_inksystem_pha_mv_1.Enabled = False
	}

	//����Ĭ�����õķ��ѵ�ѹ
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("ModulationVoltage"), _T("100"), _T("Storage Card\\System"));
	m_pCodePrinterDlg->m_Ink->m_phas->m_fixed = _wtoi(str);
	theApp.myStatusClass.bytModuVol = _wtoi(str);
	
	//����Ĭ�����õ�īˮ�߱���Һλ
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("InkFlowLevel"), _T("150"), _T("Storage Card\\System"));
	m_pCodePrinterDlg->m_Ink->m_par->m_inkFlowLev = _wtoi(str);

	//����Ĭ�����õ�īˮ��ӱ���Һλ
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("InkAddLevel"), _T("30"), _T("Storage Card\\System"));
	m_pCodePrinterDlg->m_Ink->m_par->m_inkAddLev = _wtoi(str);

	//����Ĭ�����õ�īˮ�ձ���Һλ
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("InkEmptyLevel"), _T("10"), _T("Storage Card\\System"));
	m_pCodePrinterDlg->m_Ink->m_par->m_inkEmptyLev = _wtoi(str);

	//����Ĭ�����õ��ܼ��߱���Һλ
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("SolventFlowLevel"), _T("150"), _T("Storage Card\\System"));
	m_pCodePrinterDlg->m_Ink->m_par->m_solventFlowLev = _wtoi(str);

	//����Ĭ�����õ��ܼ���ӱ���Һλ
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("SolventAddLevel"), _T("30"), _T("Storage Card\\System"));
	m_pCodePrinterDlg->m_Ink->m_par->m_solAddLev = _wtoi(str);

	//����Ĭ�����õ��ܼ��ձ���Һλ
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("SolventEmptyLevel"), _T("10"), _T("Storage Card\\System"));
	m_pCodePrinterDlg->m_Ink->m_par->m_solEmptyLev = _wtoi(str);

	//����Ĭ�����õ�īˮճ���������ٷֱ�
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("ViscoDeviation"), _T("15"), _T("Storage Card\\System"));
	m_pCodePrinterDlg->m_Ink->m_par->m_viscoDevia = _wtoi(str);

	m_pCodePrinterDlg->m_Ink->m_par->UpdateData(FALSE);
	m_pCodePrinterDlg->m_Ink->m_phas->UpdateData(FALSE);
	m_pCodePrinterDlg->m_Ink->m_setup->UpdateData(FALSE);
}

void CInksystemconfig::download_inksystem_setup()
{
	CString tempStr;
	CDealXml dealXml;
	BYTE inksystem_setup_0x00, inksystem_setup_0x01, inksystem_setup_0x02, inksystem_setup_0x03, inksystem_setup_0x04;
	BYTE inksystem_setup_0x05, inksystem_setup_0x06, inksystem_setup_0x07, inksystem_setup_0x08, inksystem_setup_0x09;
	BYTE inksystem_setup_0x0a, inksystem_setup_0x0b, inksystem_setup_0x0c, inksystem_setup_0x0d, inksystem_setup_0x0e;

	int peltierIndex = m_pCodePrinterDlg->m_Ink->m_setup->m_peltierList.GetCurSel();
	int sleepIndex = m_pCodePrinterDlg->m_Ink->m_setup->m_sleepList.GetCurSel();
	inksystem_setup_0x00 = peltierIndex*128 + sleepIndex*64;

	inksystem_setup_0x01 = 0;

	//����Ĭ��īˮ��ճ�ȱ�
	CString inksystem_setup_it;
	int ninkTypeIndex = m_pCodePrinterDlg->m_Ink->m_setup->m_inkTypeList.GetCurSel();
	m_pCodePrinterDlg->m_Ink->m_setup->m_inkTypeList.GetText(ninkTypeIndex,inksystem_setup_it);
 
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
	tempStr = dealXml.ReadXml(_T("inksystem.xml"),_T("Type") + inksystem_setup_it + _T("degC10"), _T("70"), _T("Storage Card\\System"));
	inksystem_setup_0x0b = _wtoi(tempStr.GetBuffer(0));
	tempStr = dealXml.ReadXml(_T("inksystem.xml"),_T("Type") + inksystem_setup_it + _T("degC11"), _T("66"), _T("Storage Card\\System"));
	inksystem_setup_0x0c = _wtoi(tempStr.GetBuffer(0));
	tempStr = dealXml.ReadXml(_T("inksystem.xml"),_T("Type") + inksystem_setup_it + _T("degC12"), _T("62"), _T("Storage Card\\System"));
	inksystem_setup_0x0d = _wtoi(tempStr.GetBuffer(0));
	tempStr = dealXml.ReadXml(_T("inksystem.xml"),_T("Type") + inksystem_setup_it + _T("degC13"), _T("59"), _T("Storage Card\\System"));
	inksystem_setup_0x0e = _wtoi(tempStr.GetBuffer(0));

	vector<BYTE> tempCtrVec;

#define  xml_def 1

#ifdef xml_def
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

#else
	tempCtrVec.push_back(0x1);
	tempCtrVec.push_back(0x80);
	tempCtrVec.push_back(0x10);
	tempCtrVec.push_back(0x4);
	tempCtrVec.push_back(0x0);
	tempCtrVec.push_back(0x0);
	tempCtrVec.push_back(0x7e);
	tempCtrVec.push_back(0x75);
	tempCtrVec.push_back(0x6d);
	tempCtrVec.push_back(0x66);
	tempCtrVec.push_back(0x5f);
	tempCtrVec.push_back(0x59);
	tempCtrVec.push_back(0x54);
	tempCtrVec.push_back(0x4f);
	tempCtrVec.push_back(0x4a);
	tempCtrVec.push_back(0x46);
	tempCtrVec.push_back(0x42);
	tempCtrVec.push_back(0x3e);
	tempCtrVec.push_back(0x3b);
	tempCtrVec.push_back(0xFF);
	tempCtrVec.push_back(0xFF);
#endif

	theApp.boQueCtrLock.Lock();
	theApp.queCtr.push(tempCtrVec);
	theApp.boQueCtrLock.Unlock();

}

void CInksystemconfig::download_inksystem_parameter()
{
	CDealXml dealXml;
	BYTE inksystem_parameter_0x00, inksystem_parameter_0x01, inksystem_parameter_0x02, inksystem_parameter_0x03, inksystem_parameter_0x04;
	BYTE inksystem_parameter_0x05, inksystem_parameter_0x06, inksystem_parameter_0x07, inksystem_parameter_0x08, inksystem_parameter_0x09;
	BYTE inksystem_parameter_0x0a, inksystem_parameter_0x0b, inksystem_parameter_0x0c, inksystem_parameter_0x0d;	
	
	m_pCodePrinterDlg->m_Ink->m_par->UpdateData();

	//��ȡѹ��
	int nParam = m_pCodePrinterDlg->m_Ink->m_par->m_parPressure;
	inksystem_parameter_0x00 = nParam & 0xFF;
	inksystem_parameter_0x01 = nParam >> 8;
	
	//��ȡ����
	nParam = m_pCodePrinterDlg->m_Ink->m_par->m_parPumpSpeed;
	inksystem_parameter_0x02 = nParam & 0xFF;
	inksystem_parameter_0x03 = nParam >> 8;

	//��ȡ�¶�
	inksystem_parameter_0x04 = m_pCodePrinterDlg->m_Ink->m_par->m_printheadTemp;
	
	//��ȡ���ѵ�ѹ
	nParam = m_pCodePrinterDlg->m_Ink->m_phas->m_fixed;
	inksystem_parameter_0x05 = (nParam * 10) & 0xFF; //�����ѹΪ0��200;ȱʡ��60�Ϻ���
	inksystem_parameter_0x06 = (nParam * 10) >> 8;

	//��ȡ�߱���Һλ
	inksystem_parameter_0x07 = m_pCodePrinterDlg->m_Ink->m_par->m_inkFlowLev;//īˮ�߱���ҺλΪ100��150

	//��ȡ��ӱ���Һλ
	inksystem_parameter_0x08 = m_pCodePrinterDlg->m_Ink->m_par->m_inkAddLev; //īˮ��ӱ���ҺλΪ20��100

	//��ȡ�ձ���Һλ
	inksystem_parameter_0x09 = m_pCodePrinterDlg->m_Ink->m_par->m_inkEmptyLev; //īˮ�ձ���ҺλΪ10�������-7��

	//��ȡ�ܼ��߱���Һλ
	inksystem_parameter_0x0a = m_pCodePrinterDlg->m_Ink->m_par->m_solventFlowLev; //�ܼ��߱���ҺλΪ100��150

	//��ȡ�ܼ���ӱ���Һλ
	inksystem_parameter_0x0b = m_pCodePrinterDlg->m_Ink->m_par->m_solAddLev; //�ܼ���ӱ���ҺλΪ20��100

	//��ȡ�ܼ��ձ���Һλ
	inksystem_parameter_0x0c = m_pCodePrinterDlg->m_Ink->m_par->m_solEmptyLev; //�ܼ��ձ���ҺλΪ10�������-7��

	//��ȡճ�Ȱٷֱ�
	inksystem_parameter_0x0d = m_pCodePrinterDlg->m_Ink->m_par->m_viscoDevia; //ճ����Χ1��100

	vector<BYTE> tempCtrVec;

#ifdef xml_def
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
#else
	tempCtrVec.push_back(0x01);
	tempCtrVec.push_back(0x80);
	tempCtrVec.push_back(0x10);
	tempCtrVec.push_back(0x05);

	tempCtrVec.push_back(0x00);
	tempCtrVec.push_back(0xb8);//0x00
	tempCtrVec.push_back(0xb);
	tempCtrVec.push_back(0xd0);
	tempCtrVec.push_back(0x7);
	tempCtrVec.push_back(0x18);//0x04
	tempCtrVec.push_back(0x58);
	tempCtrVec.push_back(0x2);
	tempCtrVec.push_back(0x96);
	tempCtrVec.push_back(0x1e);
	tempCtrVec.push_back(0xa);//0x09
	tempCtrVec.push_back(0x96);
	tempCtrVec.push_back(0x1e);
	tempCtrVec.push_back(0xa);
	tempCtrVec.push_back(0x14);

	tempCtrVec.push_back(0xFF);
	tempCtrVec.push_back(0xFF);
#endif

	theApp.boQueCtrLock.Lock();
	theApp.queCtr.push(tempCtrVec);
	theApp.boQueCtrLock.Unlock();
}

void CInksystemconfig::save_inksystem_to_xml()
{
	CDealXml dealXml;
	CString pcf_currentname,pcf_currentpath;
	CString strTmp;
	int nCur;

	m_pCodePrinterDlg->m_Ink->m_setup->UpdateData();
	m_pCodePrinterDlg->m_Ink->m_par->UpdateData();
	m_pCodePrinterDlg->m_Ink->m_phas->UpdateData();

	//��ǰ���ϴδ򿪵������ļ���
	pcf_currentname = _T("InkSystem.xml");
	
	//��ǰ���ϴδ򿪵������ļ���·��
	pcf_currentpath = _T("Storage Card\\System");
	
    //д����������
	nCur = m_pCodePrinterDlg->m_Ink->m_setup->m_peltierList.GetCurSel();
    m_pCodePrinterDlg->m_Ink->m_setup->m_peltierList.GetText(nCur,strTmp);
    dealXml.WriteXml(pcf_currentname, L"Peltier", strTmp,pcf_currentpath);

    //д˯�߿���
	nCur = m_pCodePrinterDlg->m_Ink->m_setup->m_sleepList.GetCurSel();
    m_pCodePrinterDlg->m_Ink->m_setup->m_sleepList.GetText(nCur,strTmp);
    dealXml.WriteXml(pcf_currentname, L"Sleep", strTmp,pcf_currentpath);

    //д����Ƶ��
 	nCur = m_pCodePrinterDlg->m_Ink->m_setup->m_modulFreList.GetCurSel();
    m_pCodePrinterDlg->m_Ink->m_setup->m_modulFreList.GetText(nCur,strTmp);
   dealXml.WriteXml(pcf_currentname, L"ModulationFrequency", strTmp,pcf_currentpath);

    //д����ߴ�
  	nCur = m_pCodePrinterDlg->m_Ink->m_setup->m_sizeList.GetCurSel();
    m_pCodePrinterDlg->m_Ink->m_setup->m_sizeList.GetText(nCur,strTmp);
   dealXml.WriteXml(pcf_currentname, L"NozzleSize", strTmp,pcf_currentpath);

    //дīˮ�ͺ�
 	nCur = m_pCodePrinterDlg->m_Ink->m_setup->m_inkTypeList.GetCurSel();
    m_pCodePrinterDlg->m_Ink->m_setup->m_inkTypeList.GetText(nCur,strTmp);
    dealXml.WriteXml(pcf_currentname, L"InkType", strTmp,pcf_currentpath);

    //д���õ�ѹ��
	strTmp.Format(L"%d",m_pCodePrinterDlg->m_Ink->m_par->m_parPressure);    
    dealXml.WriteXml(pcf_currentname, L"Pressure", strTmp,pcf_currentpath);

    //д���õı���
	strTmp.Format(L"%d",m_pCodePrinterDlg->m_Ink->m_par->m_parPumpSpeed);    
    dealXml.WriteXml(pcf_currentname, L"BumpSpeed", strTmp,pcf_currentpath);

    //д���õ���ͷ�¶�
	strTmp.Format(L"%d",m_pCodePrinterDlg->m_Ink->m_par->m_printheadTemp);    
    dealXml.WriteXml(pcf_currentname, L"PrintHeadTemp", strTmp,pcf_currentpath);

    //д���õķ��ѵ�ѹģʽΪ�̶������Զ�
    strTmp.Format(L"%d",theApp.myStatusClass.ctr0X03bit6);    
    dealXml.WriteXml(pcf_currentname, L"ModulationMode", strTmp,pcf_currentpath);

    //д���õķ��ѵ�ѹ���� 
    strTmp.Format(L"%d",theApp.myStatusClass.bytModuStep);    
	dealXml.WriteXml(pcf_currentname, L"ModulationStep", strTmp,pcf_currentpath);

    //д���õķ��ѵ�ѹ
    strTmp.Format(L"%d",m_pCodePrinterDlg->m_Ink->m_phas->m_fixed);    
    dealXml.WriteXml(pcf_currentname, L"ModulationVoltage", strTmp,pcf_currentpath);

    //д���õ�īˮ�߱���Һλ
    strTmp.Format(L"%d",m_pCodePrinterDlg->m_Ink->m_par->m_inkFlowLev);    
    dealXml.WriteXml(pcf_currentname, L"InkFlowLevel", strTmp,pcf_currentpath);

    //д���õ�īˮ��ӱ���Һλ
   	strTmp.Format(L"%d",m_pCodePrinterDlg->m_Ink->m_par->m_inkAddLev);    
    dealXml.WriteXml(pcf_currentname, L"InkAddLevel", strTmp,pcf_currentpath);

    //д���õ�īˮ�ձ���Һλ
   	strTmp.Format(L"%d",m_pCodePrinterDlg->m_Ink->m_par->m_inkEmptyLev);    
    dealXml.WriteXml(pcf_currentname, L"InkEmptyLevel", strTmp,pcf_currentpath);

    //д���õ��ܼ��߱���Һλ
   	strTmp.Format(L"%d",m_pCodePrinterDlg->m_Ink->m_par->m_solventFlowLev);    
    dealXml.WriteXml(pcf_currentname, L"SolventFlowLevel", strTmp,pcf_currentpath);

    //д���õ��ܼ���ӱ���Һλ
  	strTmp.Format(L"%d",m_pCodePrinterDlg->m_Ink->m_par->m_solAddLev);    
   dealXml.WriteXml(pcf_currentname, L"SolventAddLevel", strTmp,pcf_currentpath);

    //д���õ��ܼ��ձ���Һλ
 	strTmp.Format(L"%d",m_pCodePrinterDlg->m_Ink->m_par->m_solEmptyLev);    
    dealXml.WriteXml(pcf_currentname, L"SolventEmptyLevel", strTmp,pcf_currentpath);

    //д���õ�īˮճ���������ٷֱ�
 	strTmp.Format(L"%d",m_pCodePrinterDlg->m_Ink->m_par->m_viscoDevia);    
    dealXml.WriteXml(pcf_currentname, L"ViscoDeviation", strTmp,pcf_currentpath);
}
