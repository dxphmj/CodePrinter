// CodePrinter.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "CodePrinterDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCodePrinterApp

BEGIN_MESSAGE_MAP(CCodePrinterApp, CWinApp)
END_MESSAGE_MAP()


// CCodePrinterApp ����
CCodePrinterApp::CCodePrinterApp()
	: CWinApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CCodePrinterApp ����
CCodePrinterApp theApp;

// CCodePrinterApp ��ʼ��

BOOL CCodePrinterApp::InitInstance()
{

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	m_BKcolor = RGB(210, 231, 251);
	m_DlgBrush.CreateSolidBrush(m_BKcolor); 

	m_StaticBrush.CreateSolidBrush(RGB(197, 221, 244)); 
	m_ListBoxBrush.CreateSolidBrush(RGB(197, 221, 244));
	
	m_HeadMachineStaFont = new CFont;
	m_HeadMachineStaFont->CreatePointFont(120, _T("Arial"), NULL);

	m_HeadOperationStaFont = new CFont;
	m_HeadOperationStaFont->CreatePointFont(160, _T("Arial"), NULL);

	m_EditFont = new CFont;
	m_EditFont->CreateFont(
								25,                 //����߶�(��ת���������)=56   
								0,                 //������(��ת�������߶�)=20 
								0,                 //������ʾ�Ƕ�  
								0,                  //nOrientation=0 
								700,                 //�������=10  
								FALSE,              //��б��
								FALSE,              //���»���
								FALSE,              //��ɾ����
								DEFAULT_CHARSET,    //ʹ��ȱʡ�ַ���
								OUT_DEFAULT_PRECIS, //ȱʡ�������
								CLIP_DEFAULT_PRECIS,//ȱʡ�ü�����
								DEFAULT_QUALITY,    //nQuality=ȱʡֵ
								DEFAULT_PITCH,      //nPitchAndFamily=ȱʡֵ
								L"@system");         //������=@system 
	m_StaticFont = new CFont;
	m_StaticFont->CreateFont(
							15,                 //����߶�(��ת���������)=56   
							0,                 //������(��ת�������߶�)=20 
							0,                 //������ʾ�Ƕ�  
							0,                  //nOrientation=0 
							700,                 //�������=10  
							FALSE,              //��б��
							FALSE,              //���»���
							FALSE,              //��ɾ����
							DEFAULT_CHARSET,    //ʹ��ȱʡ�ַ���
							OUT_DEFAULT_PRECIS, //ȱʡ�������
							CLIP_DEFAULT_PRECIS,//ȱʡ�ü�����
							DEFAULT_QUALITY,    //nQuality=ȱʡֵ
							DEFAULT_PITCH,      //nPitchAndFamily=ȱʡֵ
							L"@system");         //������=@system  

	m_ListBoxFont = new CFont;
	m_ListBoxFont->CreateFont(
							18,                 //����߶�(��ת���������)=56   
							0,                 //������(��ת�������߶�)=20 
							0,                 //������ʾ�Ƕ�  
							0,                  //nOrientation=0 
							700,                 //�������=10  
							FALSE,              //��б��
							FALSE,              //���»���
							FALSE,              //��ɾ����
							DEFAULT_CHARSET,    //ʹ��ȱʡ�ַ���
							OUT_DEFAULT_PRECIS, //ȱʡ�������
							CLIP_DEFAULT_PRECIS,//ȱʡ�ü�����
							DEFAULT_QUALITY,    //nQuality=ȱʡֵ
							DEFAULT_PITCH,      //nPitchAndFamily=ȱʡֵ
							L"@system");         //������=@system  




	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CCodePrinterDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

