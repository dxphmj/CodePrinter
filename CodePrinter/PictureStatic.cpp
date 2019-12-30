// PictureStatic.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CodePrinter.h"
#include "PictureStatic.h"


// CPictureStatic

IMPLEMENT_DYNAMIC(CPictureStatic, CStatic)

CPictureStatic::CPictureStatic()
{
	m_bShowLogo = false;
}

CPictureStatic::~CPictureStatic()
{
}


BEGIN_MESSAGE_MAP(CPictureStatic, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CPictureStatic ��Ϣ�������



void CPictureStatic::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CStatic::OnPaint()

	CWnd::Default();   // �ÿؼ������Լ��Ķ���

					   // TODO: Add your message handler code here
					   // ���������ֵ����˻��� ����

	CClientDC  dc(this);
	CFont* pof;
 
    //���ƻ�����������������Ϣ
	if(!m_bShowLogo)
	{
		pof = dc.SelectObject(theApp.m_HeadOperationStaFont);

		// ������ɫ
		dc.SetTextColor(RGB(255, 255, 255));
		// ͸��
		dc.SetBkMode(TRANSPARENT);
		CRect rect(10,0,200,95);
		// ������
		dc.DrawText(m_strOperation,&rect,DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		dc.SelectObject(pof);
	}

	 //���ƻ���״̬������Ϣ
	 		
	pof = dc.SelectObject(theApp.m_HeadMachineStaFont);
	// ������ɫ
	dc.SetTextColor(RGB(255, 255, 255));
	// ͸��
	dc.SetBkMode(TRANSPARENT);
	CRect rect2(360,0,440,95);
	// ������
	dc.DrawText(m_strMachineStatus,&rect2,DT_SINGLELINE | DT_CENTER | DT_VCENTER);
	dc.SelectObject(pof); 

	if(m_bShowLogo)
	{ 
		CBitmap bm;
		bm.LoadBitmap(IDB_BITMAP1);
		CRect rect3(0,0,200,95);
 		BITMAP bm1;
		CDC menbm;
		menbm.CreateCompatibleDC(&dc);
		menbm.SelectObject(&bm);
		dc.BitBlt(0,0,rect3.Width(),rect3.Height(),&menbm,1,1,SRCCOPY);
	} 
}
