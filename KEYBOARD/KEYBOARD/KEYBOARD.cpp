// KEYBOARD.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "KEYBOARD.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//


// CKEYBOARDApp

BEGIN_MESSAGE_MAP(CKEYBOARDApp, CWinApp)
END_MESSAGE_MAP()


// CKEYBOARDApp ����

CKEYBOARDApp::CKEYBOARDApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CKEYBOARDApp ����

CKEYBOARDApp theApp;


// CKEYBOARDApp ��ʼ��

BOOL CKEYBOARDApp::InitInstance()
{
	CWinApp::InitInstance();
	


	return TRUE;
}

void showdlg::dlgShow()
{
	CMainDlg dlg;
	INT_PTR nResponse = dlg.DoModal();
}
