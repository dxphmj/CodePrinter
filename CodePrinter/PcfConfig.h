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

	void get_pcf_from_xml();//从配置文件PrintConfig.xml读取上一次打开的配置文件并从中参数并在界面上显示出来
	void download_pcf();//

public:
	CString strLABlabForMName;
};
