
// GLauncher.h : GLauncher ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CGLauncherApp:
// �� Ŭ������ ������ ���ؼ��� GLauncher.cpp�� �����Ͻʽÿ�.
//

class CGLauncherApp : public CWinApp
{
public:
	CGLauncherApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CGLauncherApp theApp;
