#pragma once
 
#include "afxwin.h"

class CColorButton : public CButton
{
	//DECLARE_DYNAMIC(CColorButton)

public:

	CColorButton();
	virtual ~CColorButton();

	//����Button Down�ı�����ɫ
	void SetDownColor(COLORREF color);

	//����Button Up�ı�����ɫ
	void SetUpColor(COLORREF color);

	bool m_bDown;

	BOOL Attach(const UINT nID, CWnd* pParent);

protected:

	//�������صĺ���
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

public:

	//������ɫ�ֱ�Ϊ���֣�Button Down�ı�����ɫ��Button Up�ı�����ɫ
	COLORREF m_TextColor, m_DownColor, m_UpColor;

}; 