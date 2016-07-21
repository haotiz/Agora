
// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once
#include "ChildView.h"
#include "UserListView.h"
#include "LocalVideoView.h"
#include "RemoteVideoView.h"

#include "OutputWnd.h"

class CMainFrame : public CFrameWndEx
{
	
public:
	CMainFrame();
protected: 
	DECLARE_DYNAMIC(CMainFrame)

// ����
public:

// ����
public:

// ��д
public:

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CMFCMenuBar			m_wndMenuBar;
	CMFCToolBar			m_wndToolBar;
//	CMFCStatusBar		m_wndStatusBar;
	
	CMFCRibbonStatusBar		m_wndStatusBar;
	CMFCRibbonBaseElement	*m_lpElementTextInfo;		// message text
	CMFCRibbonBaseElement	*m_lpElementRoomInfo;		// room info
	CMFCRibbonBaseElement	*m_lpElementNetQuality;		// NetworkQuality
	CMFCRibbonBaseElement	*m_lpElementSDKVer;			// SDKVersion

//	CUserListView		m_wndUserView;

//	CLocalVideoView		m_wndLocalView;
//	CRemoteVideoView	m_wndRemoteView;

	CChildView			m_wndView;

	IRtcEngine			*m_lpRTCEngine;
	CAgoraObject		*m_lpAgoraObject;

	CAgoraVideoWnd		*m_lpWndLocalVideo;
	CAgoraVideoWnd		*m_lpWndRemoteVideo[4];

	CMFCListCtrl		*m_lpUserListCtrl;

// ���ɵ���Ϣӳ�亯��
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	afx_msg void OnViewCustomize();
	
	afx_msg LRESULT OnToolbarCreateNew(WPARAM wp, LPARAM lp);


	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
};


