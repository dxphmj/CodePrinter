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
	int pixSize=4;

	////
	CDC* pDC = &dc;
	CRect rectClient;
	CDC dcMem,dcBkgnd;
	CBitmap bitmapTemp;//, *pOldBitmap;
	//GetClientRect(&rectClient);//��ȡ������Ϣ
	bitmapTemp.CreateCompatibleBitmap(pDC, 640, 129);//�����ڴ�λͼ
	dcMem.CreateCompatibleDC(pDC); //��������DC�������ݵ�DC
	//pOldBitmap = dcMem.SelectObject(&bitmapTemp);//���ڴ�λͼѡ���ڴ�dc
	dcMem.SelectObject(&bitmapTemp);
	//�����ɫ
	GetClientRect(&rectClient);
	CRect drawRect=rectClient;
	drawRect.top=rectClient.top+(32-theApp.myclassMessage.Pixel-1)*pixSize;
	CRect bkRect=rectClient;
	bkRect.bottom=(32-theApp.myclassMessage.Pixel-1)*pixSize;
	dcMem.FillSolidRect(bkRect,theApp.m_BKcolor);
	dcMem.FillSolidRect(drawRect,RGB(255,255,255));   //�����ɫ

	CBrush cbrush;
	CBrush cwrush;
	CBrush *pBrush; //�ɱ�ˢ
	cbrush.CreateSolidBrush(RGB(0,0,0)); 
	cwrush.CreateSolidBrush(RGB(255,255,255));
	int pixel = theApp.myclassMessage.Pixel+1;
	if(1)
	{
		//������
		CPen cPen; 
		cPen.CreatePen(PS_SOLID,1,RGB(220,220,220)); 
		CPen* pOldPen; 
		pOldPen = dcMem.SelectObject(&cPen); //�����ˢ
		for (int i=0;i<=rectClient.Width();)//��
		{
			dcMem.MoveTo(i,rectClient.Height()-pixSize*pixel-1);
			dcMem.LineTo(i,rectClient.Height());
			i+=pixSize;
		}
		for (int j=rectClient.Height()-pixSize*pixel-1;j<=rectClient.Height();)
		{
			dcMem.MoveTo(0,j);
			dcMem.LineTo(rectClient.Width(),j);
			j+=pixSize;
		}
		dcMem.SelectObject(pOldPen);
		cPen.DeleteObject();
		pOldPen->DeleteObject();
		//isFrame=false;
	}
	///theApp.myclassMessage.DrawDot(&dcMem);

	//int recSize=4;
	for (int i=0;i<(theApp.myclassMessage.Pixel+1);i++)
	{
		for (int j=0;j<theApp.myclassMessage.intRowMax;j++)
		{
			if (theApp.myclassMessage.boDotMes[i][j])
			{
				int tx=j*pixSize+1;
				int ty=129-(i+1)*pixSize;
				int bx=(j+1)*pixSize;
				int by=129-i*pixSize-1;
				pBrush=dcMem.SelectObject(&cbrush);
				//LPCRECT xyRect;
				//xyRect->left=tx;
				//xyRect->top=ty;
				//xyRect->bottom=by;
				//xyRect->right=bx;
				//dcMem.FillSolidRect(tx,ty,bx,by,RGB(0,0,0));
				dcMem.Rectangle(tx,ty,bx,by);
			}
			//else
			//{
			//	
			//	int tx=j*pixSize+1;
			//	int ty=129-(i+1)*pixSize;
			//	int bx=(j+1)*pixSize;
			//	int by=129-i*pixSize-1;
			//	pBrush=dcMem.SelectObject(&cwrush);
			//	//LPCRECT xyRect;
			//	//xyRect->left=tx;
			//	//xyRect->top=ty;
			//	//xyRect->bottom=by;
			//	//xyRect->right=bx;
			//	//dcMem.FillSolidRect(tx,ty,bx,by,RGB(0,0,0));
			//	dcMem.Rectangle(tx,ty,bx,by);
			//	
			//}
		}
	}
	pDC->BitBlt(0, 0, rectClient.Width(), rectClient.Height(), &dcMem, 0, 0, SRCCOPY);//����ͼƬ����dc
	//dcMem.SelectObject(pOldBitmap);//����
	dcMem.DeleteDC();      // ɾ���ڴ�DC
	bitmapTemp.DeleteObject();      // ɾ���ڴ�λͼ
	//theApp.myclassMessage.DrawDot(pDC);

	ReleaseDC(pDC); 
}
