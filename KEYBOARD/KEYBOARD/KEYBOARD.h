// KEYBOARD.h : KEYBOARD DLL ����ͷ�ļ�
//
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"
#include "MainDlg.h"
// CKEYBOARDApp
// �йش���ʵ�ֵ���Ϣ������� KEYBOARD.cpp
//



class CKEYBOARDApp : public CWinApp
{
public:
	CKEYBOARDApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
public:
	//void dlgShow();
};

class  showdlg
{
public:
	void dlgShow();
protected:
private:
};