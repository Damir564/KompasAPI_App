
// WSCAD.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CWSCADApp:
// � ���������� ������� ������ ��. WSCAD.cpp
//

class CWSCADApp : public CWinApp
{
public:
	CWSCADApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CWSCADApp theApp;