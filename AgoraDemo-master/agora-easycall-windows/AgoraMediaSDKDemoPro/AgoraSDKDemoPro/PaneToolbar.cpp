// PaneToolbar.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AgoraSDKDemoPro.h"
#include "PaneToolbar.h"


// CPaneToolbar

IMPLEMENT_DYNAMIC(CPaneToolbar, CMFCToolBar)

CPaneToolbar::CPaneToolbar()
{

}

CPaneToolbar::~CPaneToolbar()
{
}


BEGIN_MESSAGE_MAP(CPaneToolbar, CMFCToolBar)
END_MESSAGE_MAP()



// CPaneToolbar ��Ϣ�������
void CPaneToolbar::OnUpdateCmdUI(CFrameWnd* lpTarget, BOOL bDisableIfNoHndler)
{
	CMFCToolBar::OnUpdateCmdUI((CFrameWnd*) GetOwner(), bDisableIfNoHndler);
}

