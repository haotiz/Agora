// RemoteVideoView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AgoraSDKDemoPro.h"
#include "RemoteVideoView.h"


// CRemoteVideoView

IMPLEMENT_DYNAMIC(CRemoteVideoView, CDockablePane)

CRemoteVideoView::CRemoteVideoView()
{

}

CRemoteVideoView::~CRemoteVideoView()
{
}


BEGIN_MESSAGE_MAP(CRemoteVideoView, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_NOTIFY(NM_CLICK, ID_WND_REMOTEVIDEO+0, &CRemoteVideoView::OnNMClickVideoWnd)
	ON_NOTIFY(NM_CLICK, ID_WND_REMOTEVIDEO+1, &CRemoteVideoView::OnNMClickVideoWnd)
	ON_NOTIFY(NM_CLICK, ID_WND_REMOTEVIDEO+2, &CRemoteVideoView::OnNMClickVideoWnd)
	ON_NOTIFY(NM_CLICK, ID_WND_REMOTEVIDEO+3, &CRemoteVideoView::OnNMClickVideoWnd)
END_MESSAGE_MAP()



// CRemoteVideoView ��Ϣ�������

int CRemoteVideoView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������

	// ������ͼ:
	const DWORD dwViewStyle = WS_TABSTOP | WS_CHILD | WS_BORDER;

	CRect rcClientRect;

	rcClientRect.SetRect(1, 1, 1, 1);

	for(int nIndex = 0; nIndex < 4; nIndex++) {
		m_wndRemoteVideo[nIndex].Create(NULL, _T("Remote"), WS_BORDER | WS_VISIBLE, rcClientRect, this, ID_WND_REMOTEVIDEO+nIndex);
		m_wndRemoteVideo[nIndex].SetVolbarPos(CAgoraVideoWnd::VOLBAR_LEFT);
	}

	m_lpRTCEngine = CAgoraObject::GetEngine();

	return 0;
}

void CRemoteVideoView::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	if (GetSafeHwnd() == NULL)
		return;

	int nVideoHeight = cy/4;

	for(int nIndex = 0; nIndex < 3; nIndex++){
		m_wndRemoteVideo[nIndex].SetWindowPos(NULL, 0, nIndex*nVideoHeight, 40, nVideoHeight, SWP_NOACTIVATE | SWP_NOZORDER);
	}

	m_wndRemoteVideo[3].SetWindowPos(NULL, 0, 3*nVideoHeight, 40, cy-3*nVideoHeight, SWP_NOACTIVATE | SWP_NOZORDER);
}

CAgoraVideoWnd *CRemoteVideoView::GetAgoraVideoWnd(int nIndex)
{
	if(nIndex < 0 || nIndex>3)
		return NULL;

	return &m_wndRemoteVideo[nIndex];
}

void CRemoteVideoView::OnNMClickVideoWnd(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMAGVIDEOWND pNMVideoWnd = reinterpret_cast<LPNMAGVIDEOWND>(pNMHDR);
	RtcEngineParameters rep(m_lpRTCEngine);
	CAgoraVideoWnd *lpAgoraVideoWnd = (CAgoraVideoWnd *)GetDlgItem(pNMVideoWnd->hdr.idFrom);

	DWORD dwUserFlag = lpAgoraVideoWnd->GetUserFlag();
	BOOL bValue = FALSE;

	switch (pNMVideoWnd->nMousePos)
	{
	case CAgoraVideoWnd::MOUSE_POS_BIGSCREEN:

		break;
	case CAgoraVideoWnd::MOUSE_POS_MUTEVIDEO:
		bValue = lpAgoraVideoWnd->IsVideoMuted();
		

		break;
	case CAgoraVideoWnd::MOUSE_POS_MUTEAUDIO:
		bValue = lpAgoraVideoWnd->IsAudioMuted();
		if(rep.muteRemoteAudioStream(lpAgoraVideoWnd->GetUID(), !bValue) == 0)
			lpAgoraVideoWnd->SetMuteAudioFlag(!bValue);

		break;
	default:
		break;
	}

	Invalidate();
	UpdateWindow();
}