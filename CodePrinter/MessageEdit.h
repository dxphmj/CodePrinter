// MessageEdit.h : MessageEdit DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"

// CMessageEditApp
// �йش���ʵ�ֵ���Ϣ������� MessageEdit.cpp
//

class CMessageEditApp : public CWinApp
{
public:
	CMessageEditApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};

