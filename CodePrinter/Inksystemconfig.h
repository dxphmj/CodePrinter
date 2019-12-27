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
	void get_inksystem_from_xml();//�������ļ�InkSystem.xml��ȡ�������ڽ�������ʾ����
	void download_inksystem_setup();//���豸����
	void download_inksystem_parameter();//����������
	void save_inksystem_to_xml();
};
