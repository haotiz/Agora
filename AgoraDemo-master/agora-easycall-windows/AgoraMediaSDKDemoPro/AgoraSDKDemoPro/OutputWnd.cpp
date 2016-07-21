
#include "stdafx.h"

#include "OutputWnd.h"
#include "Resource.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COutputBar

COutputWnd::COutputWnd()
{
}

COutputWnd::~COutputWnd()
{
}

BEGIN_MESSAGE_MAP(COutputWnd, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

int COutputWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_Font.CreateStockObject(DEFAULT_GUI_FONT);

	CRect rectDummy;
	rectDummy.SetRectEmpty();

	// ������ͼ:
	const DWORD dwViewStyle = WS_TABSTOP | WS_CHILD | WS_BORDER | WS_VISIBLE | LVS_ALIGNLEFT | LVS_REPORT;

	m_ctrLogList.Create(dwViewStyle, rectDummy, this, ID_LIST_LOGLIST);
	m_ctrLogList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_SUBITEMIMAGES | LVS_EX_INFOTIP);
	m_ctrLogList.InsertColumn(0, _T("��־����"), 0, 100, 0);

	m_wndToolBar.Create(this, AFX_DEFAULT_TOOLBAR_STYLE, ID_TOOLBAR_LOGLIST);
	m_wndToolBar.LoadToolBar(IDR_USERLIST, 0, 0, TRUE /* ������*/);


	return 0;
}

void COutputWnd::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// ѡ��ؼ�Ӧ��������������:
	if (GetSafeHwnd() == NULL)
		return;

	CRect rectClient;
	GetClientRect(rectClient);

	int cyTlb = m_wndToolBar.CalcFixedLayout(FALSE, TRUE).cy;

	m_wndToolBar.SetWindowPos(NULL, rectClient.left, rectClient.top, rectClient.Width(), cyTlb, SWP_NOACTIVATE | SWP_NOZORDER);
	m_ctrLogList.SetWindowPos(NULL, rectClient.left, rectClient.top+cyTlb, rectClient.Width(), rectClient.Height()-cyTlb, SWP_NOACTIVATE | SWP_NOZORDER);
}