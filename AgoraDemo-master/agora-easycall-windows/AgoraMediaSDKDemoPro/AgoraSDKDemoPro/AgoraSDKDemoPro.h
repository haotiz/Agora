
// AgoraSDKDemoPro.h : AgoraSDKDemoPro Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CAgoraSDKDemoProApp:
// �йش����ʵ�֣������ AgoraSDKDemoPro.cpp
//

class CAgoraSDKDemoProApp : public CWinAppEx
{
public:
	CAgoraSDKDemoProApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

public:
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAgoraSDKDemoProApp theApp;
