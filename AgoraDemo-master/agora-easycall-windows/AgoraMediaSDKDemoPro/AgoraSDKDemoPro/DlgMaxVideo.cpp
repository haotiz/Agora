// DlgMaxVideo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AgoraSDKDemoPro.h"
#include "DlgMaxVideo.h"


// CDlgMaxVideo �Ի���

IMPLEMENT_DYNAMIC(CDlgMaxVideo, CDialog)

CDlgMaxVideo::CDlgMaxVideo(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMaxVideo::IDD, pParent)
	, m_nUID(0)
{

}

CDlgMaxVideo::~CDlgMaxVideo()
{
}

void CDlgMaxVideo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgMaxVideo, CDialog)
END_MESSAGE_MAP()


// CDlgMaxVideo ��Ϣ�������

BOOL CDlgMaxVideo::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CDlgMaxVideo::SetUID(UINT nUID)
{
	CString str;

	m_nUID = nUID;
	str.Format(_T("UID: %d"), nUID);

	SetWindowText(str);
}
void CDlgMaxVideo::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���
	#define WM_MAXVIDEOCLOSED	(WM_USER+200)

	/*
	CWnd *lpParentWnd = GetParent();

	HWND hParent = lpParentWnd->GetSafeHwnd();
	GetParent()->SendMessage(WM_MAXVIDEOCLOSED, 0, 0);
*/
	AfxGetMainWnd()->GetDlgItem(AFX_IDW_PANE_FIRST)->SendMessage(WM_MAXVIDEOCLOSED, 0, 0);
	CDialog::OnCancel();
}
