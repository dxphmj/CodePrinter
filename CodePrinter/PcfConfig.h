#pragma once
#include "DealXml.h"
class CCodePrinterDlg;


class CPcfConfig
{
public:
	CPcfConfig(CCodePrinterDlg* pCodeDlg);
	~CPcfConfig(void);
public:
	CCodePrinterDlg* m_pCodePrinterDlg;
public:

	void get_pcf_from_xml();//�������ļ�PrintConfig.xml��ȡ��һ�δ򿪵������ļ������в������ڽ�������ʾ����
	void download_pcf();//

public:
	CString strLABlabForMName;
};
