
// TestDll_VS2010.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTestDll_VS2010App:
// �йش����ʵ�֣������ TestDll_VS2010.cpp
//

class CTestDll_VS2010App : public CWinApp
{
public:
	CTestDll_VS2010App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTestDll_VS2010App theApp;