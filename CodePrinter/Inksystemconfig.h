#pragma once



class CCodePrinterDlg;

class CInksystemconfig
{
public:
	CInksystemconfig(CCodePrinterDlg* pCodeDlg);
	~CInksystemconfig(void);

public:
	CCodePrinterDlg* m_pCodePrinterDlg;

public:
	void get_inksystem_from_xml();//从配置文件InkSystem.xml读取参数并在界面上显示出来
	void download_inksystem_setup();//发设备配置
	void download_inksystem_parameter();//发参数设置
	void save_inksystem_to_xml();
};
