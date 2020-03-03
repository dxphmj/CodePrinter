// CodePrinter.cpp : 定义应用程序的类行为。
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


// CCodePrinterApp 构造
CCodePrinterApp::CCodePrinterApp()
	: CWinApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CCodePrinterApp 对象
CCodePrinterApp theApp;

// CCodePrinterApp 初始化

BOOL CCodePrinterApp::InitInstance()
{
	mainPicPixel=7;
	mainPicMatrx=9;
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
								25,                 //字体高度(旋转后的字体宽度)=56   
								0,                 //字体宽度(旋转后的字体高度)=20 
								0,                 //字体显示角度  
								0,                  //nOrientation=0 
								700,                 //字体磅数=10  
								FALSE,              //非斜体
								FALSE,              //无下划线
								FALSE,              //无删除线
								DEFAULT_CHARSET,    //使用缺省字符集
								OUT_DEFAULT_PRECIS, //缺省输出精度
								CLIP_DEFAULT_PRECIS,//缺省裁减精度
								DEFAULT_QUALITY,    //nQuality=缺省值
								DEFAULT_PITCH,      //nPitchAndFamily=缺省值
								L"@system");         //字体名=@system 
	m_StaticFont = new CFont;
	m_StaticFont->CreateFont(
							15,                 //字体高度(旋转后的字体宽度)=56   
							0,                 //字体宽度(旋转后的字体高度)=20 
							0,                 //字体显示角度  
							0,                  //nOrientation=0 
							700,                 //字体磅数=10  
							FALSE,              //非斜体
							FALSE,              //无下划线
							FALSE,              //无删除线
							DEFAULT_CHARSET,    //使用缺省字符集
							OUT_DEFAULT_PRECIS, //缺省输出精度
							CLIP_DEFAULT_PRECIS,//缺省裁减精度
							DEFAULT_QUALITY,    //nQuality=缺省值
							DEFAULT_PITCH,      //nPitchAndFamily=缺省值
							L"@system");         //字体名=@system  

	m_ListBoxFont = new CFont;
	m_ListBoxFont->CreateFont(
							18,                 //字体高度(旋转后的字体宽度)=56   
							0,                 //字体宽度(旋转后的字体高度)=20 
							0,                 //字体显示角度  
							0,                  //nOrientation=0 
							700,                 //字体磅数=10  
							FALSE,              //非斜体
							FALSE,              //无下划线
							FALSE,              //无删除线
							DEFAULT_CHARSET,    //使用缺省字符集
							OUT_DEFAULT_PRECIS, //缺省输出精度
							CLIP_DEFAULT_PRECIS,//缺省裁减精度
							DEFAULT_QUALITY,    //nQuality=缺省值
							DEFAULT_PITCH,      //nPitchAndFamily=缺省值
							L"@system");         //字体名=@system  




	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	CCodePrinterDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}

void CCodePrinterApp::InitCommMsg()
{
	MyDcb tempDcb;
	tempDcb.nComPort=4;
	tempDcb.BaudRate=115200;
	tempDcb.ByteSize=(BYTE)8;
	tempDcb.Parity=(BYTE)0;
	tempDcb.StopBits=(BYTE)0;
	tempDcb.bIsSave=true;
	myCIOVsd.SetComIndx(tempDcb.nComPort);
	if (!myCIOVsd.OpenComm(tempDcb))
	{
		CString csMsg ;//= _T("串口4打开失败!");
		csMsg.Format(_T("串口%d打开失败!"),tempDcb.nComPort);
		AfxMessageBox(csMsg);
	}
}

//时间序列号刷新时间
void CCodePrinterApp::refalsetimedata()
{
	/*if (m_MessageEdit.bytTimeConCoun>0)
	{
		boETimetextLock.Lock();
		for (int j=0;j<m_MessageEdit.bytTimeConCoun;j++)
		{
			m_MessageEdit.strETimetext[j] = 
				myModuleMain.TimeFormatToText(myModuleMain.string2CString(m_MessageEdit.strTimeFormat[0][j]),m_MessageEdit.strETimeOffSet[j],m_MessageEdit.intTimeOffSetdis[j],m_MessageEdit.strTimeOffSetUint[j]);
		}
		boETimetextLock.Unlock();
	}*/
}

void CCodePrinterApp::SetProgressBar(int nPos)
{
	 CDealXml dealmxl;
	 CString strPos;
	 strPos.Format(L"%d",nPos);
	 dealmxl.WriteXml(_T("LoadConfig.xml"),_T("Value"),strPos,_T("Storage Card\\System"));
}