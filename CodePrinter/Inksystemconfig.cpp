#include "StdAfx.h"
#include "Inksystemconfig.h"
#include "resource.h"
#include "CodePrinterDlg.h"
#include "DealXml.h"
#include <vector>
#define  xml_def 1
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

	//开机默认帕尔贴开关
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("Peltier"), _T("OFF"), _T("Storage Card\\System"));
	int nCur = m_pCodePrinterDlg->m_Ink->m_setup->m_sleepList.SelectString(0,str);
	m_pCodePrinterDlg->m_Ink->m_setup->m_peltierList.SetCurSel(nCur);
	
//	CString hexstr = _T("af");
//	BYTE tempbt = dealXml.HEX_to_DECbyte(hexstr);

	//开机默认睡眠开关
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("Sleep"), _T("OFF"), _T("Storage Card\\System"));
	nCur = m_pCodePrinterDlg->m_Ink->m_setup->m_sleepList.SelectString(0,str);
	m_pCodePrinterDlg->m_Ink->m_setup->m_sleepList.SetCurSel(nCur);
	
	//开机默认晶振频率
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("ModulationFrequency"), _T("64000"), _T("Storage Card\\System"));
	nCur = m_pCodePrinterDlg->m_Ink->m_setup->m_modulFreList.SelectString(0,str);
	m_pCodePrinterDlg->m_Ink->m_setup->m_modulFreList.SetCurSel(nCur);
	
	//开机默认喷嘴尺寸
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("NozzleSize"), _T("60"), _T("Storage Card\\System"));
	nCur = m_pCodePrinterDlg->m_Ink->m_setup->m_sizeList.SelectString(0,str);
	m_pCodePrinterDlg->m_Ink->m_setup->m_sizeList.SetCurSel(nCur);
	
	//开机默认墨水型号
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("InkType"), _T("236"), _T("Storage Card\\System"));
	nCur = m_pCodePrinterDlg->m_Ink->m_setup->m_inkTypeList.SelectString(0,str);
	m_pCodePrinterDlg->m_Ink->m_setup->m_inkTypeList.SetCurSel(nCur);
	
	//开机默认设置的压力
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("Pressure"), _T("3000"), _T("Storage Card\\System"));
	m_pCodePrinterDlg->m_Ink->m_par->m_parPressure = _wtoi(str);
	
	//开机默认设置的泵速
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("BumpSpeed"), _T("1500"), _T("Storage Card\\System"));
	m_pCodePrinterDlg->m_Ink->m_par->m_parPumpSpeed = _wtoi(str);

	//开机默认设置的喷头温度
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("PrintHeadTemp"), _T("24"), _T("Storage Card\\System"));
	m_pCodePrinterDlg->m_Ink->m_par->m_printheadTemp = _wtoi(str);


	//开机默认设置的分裂电压模式为固定电压
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

	//开机默认设置的分裂电压步级为10V
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

	//开机默认设置的分裂电压
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("ModulationVoltage"), _T("100"), _T("Storage Card\\System"));
	m_pCodePrinterDlg->m_Ink->m_phas->m_fixed = _wtoi(str);
	theApp.myStatusClass.bytModuVol = _wtoi(str);
	
	//开机默认设置的墨水高报警液位
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("InkFlowLevel"), _T("150"), _T("Storage Card\\System"));
	m_pCodePrinterDlg->m_Ink->m_par->m_inkFlowLev = _wtoi(str);

	//开机默认设置的墨水添加报警液位
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("InkAddLevel"), _T("30"), _T("Storage Card\\System"));
	m_pCodePrinterDlg->m_Ink->m_par->m_inkAddLev = _wtoi(str);

	//开机默认设置的墨水空报警液位
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("InkEmptyLevel"), _T("10"), _T("Storage Card\\System"));
	m_pCodePrinterDlg->m_Ink->m_par->m_inkEmptyLev = _wtoi(str);

	//开机默认设置的溶剂高报警液位
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("SolventFlowLevel"), _T("150"), _T("Storage Card\\System"));
	m_pCodePrinterDlg->m_Ink->m_par->m_solventFlowLev = _wtoi(str);

	//开机默认设置的溶剂添加报警液位
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("SolventAddLevel"), _T("30"), _T("Storage Card\\System"));
	m_pCodePrinterDlg->m_Ink->m_par->m_solAddLev = _wtoi(str);

	//开机默认设置的溶剂空报警液位
	str = dealXml.ReadXml(_T("inksystem.xml"),_T("SolventEmptyLevel"), _T("10"), _T("Storage Card\\System"));
	m_pCodePrinterDlg->m_Ink->m_par->m_solEmptyLev = _wtoi(str);

	//开机默认设置的墨水粘度允许误差百分比
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

	vector<BYTE> tempCtrVec;
	inksystem_setup_0x01 = 0;

	//开机默认墨水的粘度表
	CString inksystem_setup_it;// = _T("236");
	inksystem_setup_it.Format(_T("%d"),270);

	//CString inksystem_setup_it  = lisval_inksystem_setup_it.SelectedItem;
//	int nParam = _wtoi(inksystem_setup_it.GetBuffer(0));
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
	tempStr = dealXml.ReadXml(_T("inksystem.xml"),_T("Type") + inksystem_setup_it + _T("degC10"), _T("70"), _T("Storage Card\\System"));
	inksystem_setup_0x0b = _wtoi(tempStr.GetBuffer(0));
	tempStr = dealXml.ReadXml(_T("inksystem.xml"),_T("Type") + inksystem_setup_it + _T("degC11"), _T("66"), _T("Storage Card\\System"));
	inksystem_setup_0x0c = _wtoi(tempStr.GetBuffer(0));
	tempStr = dealXml.ReadXml(_T("inksystem.xml"),_T("Type") + inksystem_setup_it + _T("degC12"), _T("62"), _T("Storage Card\\System"));
	inksystem_setup_0x0d = _wtoi(tempStr.GetBuffer(0));
	tempStr = dealXml.ReadXml(_T("inksystem.xml"),_T("Type") + inksystem_setup_it + _T("degC13"), _T("59"), _T("Storage Card\\System"));
	inksystem_setup_0x0e = _wtoi(tempStr.GetBuffer(0));

#ifndef xml_def

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
#endif

#ifdef xml_def
	//vector<BYTE> tempCtrVec;
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
	CString tempStr;
	vector<BYTE> tempCtrVec;
	BYTE inksystem_parameter_0x00, inksystem_parameter_0x01, inksystem_parameter_0x02, inksystem_parameter_0x03, inksystem_parameter_0x04;
	BYTE inksystem_parameter_0x05, inksystem_parameter_0x06, inksystem_parameter_0x07, inksystem_parameter_0x08, inksystem_parameter_0x09;
	BYTE inksystem_parameter_0x0a, inksystem_parameter_0x0b, inksystem_parameter_0x0c, inksystem_parameter_0x0d;	
	
	m_pCodePrinterDlg->m_Ink->m_par->UpdateData();

	//获取压力
	int nParam = m_pCodePrinterDlg->m_Ink->m_par->m_parPressure;
	inksystem_parameter_0x00 = nParam & 0xFF;
	inksystem_parameter_0x01 = nParam >> 8;
	
	//获取泵速
	nParam = m_pCodePrinterDlg->m_Ink->m_par->m_parPumpSpeed;
	inksystem_parameter_0x02 = nParam & 0xFF;
	inksystem_parameter_0x03 = nParam >> 8;

	//获取温度
	inksystem_parameter_0x04 = m_pCodePrinterDlg->m_Ink->m_par->m_printheadTemp;
	
	//获取分裂电压
	nParam = m_pCodePrinterDlg->m_Ink->m_phas->m_fixed;
	inksystem_parameter_0x05 = (nParam * 10) & 0xFF; //晶振电压为0到200
	inksystem_parameter_0x06 = (nParam * 10) >> 8;

	//获取高报警液位
	inksystem_parameter_0x07 = m_pCodePrinterDlg->m_Ink->m_par->m_inkFlowLev;//墨水高报警液位为100到150

	//获取添加报警液位
	inksystem_parameter_0x08 = m_pCodePrinterDlg->m_Ink->m_par->m_inkAddLev; //墨水添加报警液位为20到100

	//获取空报警液位
	inksystem_parameter_0x09 = m_pCodePrinterDlg->m_Ink->m_par->m_inkEmptyLev; //墨水空报警液位为10到（添加-7）

	//获取溶剂高报警液位
	inksystem_parameter_0x0a = m_pCodePrinterDlg->m_Ink->m_par->m_solventFlowLev; //溶剂高报警液位为100到150

	//获取溶剂添加报警液位
	inksystem_parameter_0x0b = m_pCodePrinterDlg->m_Ink->m_par->m_solAddLev; //溶剂添加报警液位为20到100

	//获取溶剂空报警液位
	inksystem_parameter_0x0c = m_pCodePrinterDlg->m_Ink->m_par->m_solEmptyLev; //溶剂空报警液位为10到（添加-7）

	//获取粘度百分比
	inksystem_parameter_0x0d = m_pCodePrinterDlg->m_Ink->m_par->m_viscoDevia; //粘度误差范围1到100
#ifndef xml_def

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
#endif
#ifdef xml_def

	CString str;
	str.Format(_T("%x\n"),inksystem_parameter_0x0d);
	TRACE(str);

	tempCtrVec.push_back(0x01);
	tempCtrVec.push_back(0x80);
	tempCtrVec.push_back(0x10);
	tempCtrVec.push_back(0x05);
	tempCtrVec.push_back(0x00);

	tempCtrVec.push_back(0xb8);
	tempCtrVec.push_back(0xb);
	tempCtrVec.push_back(0xd0);
	tempCtrVec.push_back(0x7);
	tempCtrVec.push_back(0x18);
	tempCtrVec.push_back(0x58);
	tempCtrVec.push_back(0x2);
	tempCtrVec.push_back(0x96);
	tempCtrVec.push_back(0x1e);
	tempCtrVec.push_back(0xa);
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
