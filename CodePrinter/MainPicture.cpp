// MainPicture.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "MainPicture.h"


// MainPicture

IMPLEMENT_DYNAMIC(MainPicture, CStatic)

MainPicture::MainPicture()
{

}

MainPicture::~MainPicture()
{
}

BEGIN_MESSAGE_MAP(MainPicture, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// MainPicture ��Ϣ�������
void MainPicture::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CStatic::OnPaint()
	CWnd::Default();   // �ÿؼ������Լ��Ķ���
	CClientDC  dc(this);
	//////////////////////////////////////////////////////////////////////////
	CDC* pDC = &dc;
	CRect rectClient;
	CDC dcMem,dcBkgnd;
	CBitmap bitmapTemp; 
	bitmapTemp.CreateCompatibleBitmap(pDC, 640, 129);//�����ڴ�λͼ
	dcMem.CreateCompatibleDC(pDC); //��������DC�������ݵ�DC
	dcMem.SelectObject(&bitmapTemp);
	//�����ɫ
	int pixSize = 4;
	GetClientRect(&rectClient);
	CRect drawRect=rectClient;
	drawRect.top=rectClient.top+(32-theApp.mainPicPixel)*pixSize;
	CRect bkRect=rectClient;
	bkRect.bottom=(32-theApp.mainPicPixel)*pixSize;
	dcMem.FillSolidRect(bkRect,theApp.m_BKcolor);
	dcMem.FillSolidRect(drawRect,RGB(255,255,255));   //�����ɫ

	CBrush cbrush;
 	CBrush *pBrush; //�ɱ�ˢ
	cbrush.CreateSolidBrush(RGB(0,0,0)); 
 	//int pixel = theApp.myclassMessage.Pixel+1;

		//������
		CPen cPen; 
		cPen.CreatePen(PS_SOLID,1,RGB(220,220,220)); 
		CPen* pOldPen; 
		pOldPen = dcMem.SelectObject(&cPen); //�����ˢ
		for (int i=0;i<=rectClient.Width();)//��
		{
			dcMem.MoveTo(i,rectClient.Height()-pixSize*theApp.mainPicPixel-1);
			dcMem.LineTo(i,rectClient.Height());
			i+=pixSize;
		}
		for (int j=rectClient.Height()-pixSize*theApp.mainPicPixel-1;j<=rectClient.Height();)
		{
			dcMem.MoveTo(0,j);
			dcMem.LineTo(rectClient.Width(),j);
			j+=pixSize;
		}
		dcMem.SelectObject(pOldPen);
		cPen.DeleteObject();		 
		//isFrame=false;
	if (theApp.mainPicMatrx==14)
	{
		CRect bkRect=rectClient;
		bkRect.bottom=(32-7)*pixSize;
		bkRect.top=(32-8)*pixSize;
		dcMem.FillSolidRect(bkRect,theApp.m_BKcolor);
	}

	pBrush = dcMem.SelectObject(&cbrush);
	theApp.myclassMessage.DrawMainPageDot(&dcMem);
	
	pDC->BitBlt(0, 0, rectClient.Width(), rectClient.Height(), &dcMem, 0, 0, SRCCOPY);//����ͼƬ����dc

	dcMem.SelectObject(pBrush);
	cbrush.DeleteObject();

 	dcMem.DeleteDC();               // ɾ���ڴ�DC
	bitmapTemp.DeleteObject();      // ɾ���ڴ�λͼ
 	theApp.boDrawMainPic = true;
	ReleaseDC(pDC); 	
}


UINT methoddis(LPVOID pParam)
{
	structMP *pstructMP = (structMP *)pParam;
	CClientDC  dc(pstructMP->myMainPicture);
	//////////////////////////////////////////////////////////////////////////
	int pixSize = 4;

	////
	CDC* pDC = &dc;
	////Ŀǰ����˫�ػ���
	//CRect rectClient;
	//CDC dcMem,dcBkgnd;
	//CBitmap bitmapTemp;//, *pOldBitmap;
	////GetClientRect(&rectClient);//��ȡ������Ϣ
	//bitmapTemp.CreateCompatibleBitmap(pDC, 640, 129);//�����ڴ�λͼ
	//dcMem.CreateCompatibleDC(pDC); //��������DC�������ݵ�DC
	////pOldBitmap = dcMem.SelectObject(&bitmapTemp);//���ڴ�λͼѡ���ڴ�dc
	//dcMem.SelectObject(&bitmapTemp);
	
	while(theApp.mythreadDynamicBoo)
	{
		while(theApp.boDrawMainPic)
		{
			for(int i = 0; i < theApp.myclassMessage.OBJ_Vec.size(); i++)
			{		 
				if (theApp.myclassMessage.OBJ_Vec[i]->strType2 == "serial")
				{	
					int intDynamicRowEnd = theApp.myclassMessage.OBJ_Vec[i]->intRowStart+theApp.myclassMessage.OBJ_Vec[i]->intRowSize-1;
					int nRowStartdis = theApp.myclassMessage.OBJ_Vec[i]->intRowStart;
					int nStartValue = theApp.myclassMessage.OBJ_Vec[i]->intSerialStartValue;
					theApp.myclassMessage.DrawSerialTimeDynamic(nRowStartdis,intDynamicRowEnd,nStartValue,pDC);		
				}
				else if (theApp.myclassMessage.OBJ_Vec[i]->strType2 == "time")
				{	
					int intDynamicRowEnd = theApp.myclassMessage.OBJ_Vec[i]->intRowStart+theApp.myclassMessage.OBJ_Vec[i]->intRowSize-1;
					int nRowStartdis = theApp.myclassMessage.OBJ_Vec[i]->intRowStart;
					 
					theApp.myclassMessage.DrawSerialTimeDynamic(nRowStartdis,intDynamicRowEnd,nRowStartdis,pDC);		
				}
			}
		}
		Sleep(10);
	}

	return 0;
}