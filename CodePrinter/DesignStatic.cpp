// DesignStatic.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "DesignStatic.h"


// CDesignStatic

IMPLEMENT_DYNAMIC(CDesignStatic, CStatic)

CDesignStatic::CDesignStatic()
{

}

CDesignStatic::~CDesignStatic()
{
}


BEGIN_MESSAGE_MAP(CDesignStatic, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CDesignStatic ��Ϣ�������



void CDesignStatic::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CStatic::OnPaint()
	CWnd::Default();   // �ÿؼ������Լ��Ķ���
	CClientDC  dc(this);

    CDC* pDC = &dc;
	CRect rectClient;
	CDC dcMem,dcBkgnd;
	CBitmap bitmapTemp;//, *pOldBitmap;
	//GetClientRect(&rectClient);//��ȡ������Ϣ
	int tempNeed;
	if (theApp.myclassMessage.scrMaxRow<256)
	{
		tempNeed=1276;
	}
	else
	{
		tempNeed=theApp.myclassMessage.scrMaxRow*5 + 1;
	}
	bitmapTemp.CreateCompatibleBitmap(pDC, tempNeed, 161);//�����ڴ�λͼ
	dcMem.CreateCompatibleDC(pDC); //��������DC�������ݵ�DC
	//pOldBitmap = dcMem.SelectObject(&bitmapTemp);//���ڴ�λͼѡ���ڴ�dc
	dcMem.SelectObject(&bitmapTemp);
	//�����ɫ
	GetClientRect(&rectClient);
	CRect bitRect=rectClient;
	bitRect.right=tempNeed;
	dcMem.FillSolidRect(bitRect,RGB(255,255,255));   //�����ɫ
	
	CBrush cbrush;
	CBrush* pBrush; //�ɱ�ˢ
	int pixel = theApp.myclassMessage.Pixel+1;
	if(1)
	{
		//������
		CPen cPen; 
		cPen.CreatePen(PS_SOLID,1,RGB(220,220,220)); 
		CPen* pOldPen; 
		pOldPen = dcMem.SelectObject(&cPen); //�����ˢ
		for (int i=0;i<=bitRect.Width();)//��
		{
			dcMem.MoveTo(i,bitRect.Height()-5*pixel-1);
			dcMem.LineTo(i,bitRect.Height());
			i+=5;
		}
		for (int j=bitRect.Height()-5*pixel-1;j<=bitRect.Height();)
		{
			dcMem.MoveTo(0,j);
			dcMem.LineTo(bitRect.Width(),j);
			j+=5;
		}
		dcMem.SelectObject(pOldPen);
		cPen.DeleteObject();

		//������
		CPen cRPen; 
		cRPen.CreatePen(PS_SOLID,1,RGB(255,0,0)); 
		pOldPen = dcMem.SelectObject(&cRPen); //�����ˢ
		dcMem.MoveTo(bitRect.left,bitRect.Height()-1);
		dcMem.LineTo(bitRect.right,bitRect.Height()-1);
		dcMem.MoveTo(bitRect.left,bitRect.Height()-5*pixel-1);
		dcMem.LineTo(bitRect.right,bitRect.Height()-5*pixel-1);
		
		dcMem.SelectObject(pOldPen);
		cRPen.DeleteObject();		 
		//isFrame=false;
	}
	theApp.myclassMessage.DrawDot(&dcMem);


	pDC->BitBlt(0, 0, rectClient.Width(), rectClient.Height(), &dcMem, theApp.scrPox*5, 0, SRCCOPY);//����ͼƬ����dc
	//dcMem.SelectObject(pOldBitmap);//����

	dcMem.DeleteDC();      // ɾ���ڴ�DC
	bitmapTemp.DeleteObject();      // ɾ���ڴ�λͼ

	ReleaseDC(pDC); 
}
