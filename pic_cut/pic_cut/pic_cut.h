
// pic_cut.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cpic_cutApp:
// �йش����ʵ�֣������ pic_cut.cpp
//

class Cpic_cutApp : public CWinApp
{
public:
	Cpic_cutApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cpic_cutApp theApp;