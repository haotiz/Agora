
// AgoraSDKDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CAgoraSDKDemoApp:
// �йش����ʵ�֣������ AgoraSDKDemo.cpp
//

class CAgoraSDKDemoApp : public CWinAppEx
{
public:
	CAgoraSDKDemoApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CAgoraSDKDemoApp theApp;