// SetupPage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AgoraSDKDemoPro.h"
#include "SetupPage.h"


// CSetupPage �Ի���

IMPLEMENT_DYNAMIC(CSetupPage, CPropertyPage)

CSetupPage::CSetupPage()
	: CPropertyPage(CSetupPage::IDD)
	, m_nResolution(0)
{

}

CSetupPage::~CSetupPage()
{
}

void CSetupPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_CBIndex(pDX, IDC_CMBRSL_SETUP, m_nResolution);
}


BEGIN_MESSAGE_MAP(CSetupPage, CPropertyPage)
END_MESSAGE_MAP()


// CSetupPage ��Ϣ�������

BOOL CSetupPage::OnApply()
{
	// TODO: �ڴ����ר�ô����/����û���
	CAgoraObject *lpAgoraObject = CAgoraObject::GetAgoraObject();
	IRtcEngine *lpAgoraRTCEngine = CAgoraObject::GetEngine();

	RtcEngineParameters rep(lpAgoraRTCEngine);

	UpdateData(TRUE);

	switch (m_nResolution)
	{
	case 0:
		rep.setVideoResolution(1920, 1080);
		break;
	case 1:
		rep.setVideoResolution(1080, 720);
		break;
	default:
		rep.setVideoResolution(1080, 720);
		break;
	}
	

	
	return CPropertyPage::OnApply();
}

void CSetupPage::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���
	CAgoraObject *lpAgoraObject = CAgoraObject::GetAgoraObject();
	IRtcEngine *lpAgoraRTCEngine = CAgoraObject::GetEngine();

	RtcEngineParameters rep(lpAgoraRTCEngine);

	UpdateData(TRUE);

	switch (m_nResolution)
	{
	case 0:
		rep.setVideoResolution(1920, 1080);
		break;
	case 1:
		rep.setVideoResolution(1080, 720);
		break;
	default:
		rep.setVideoResolution(1080, 720);
		break;
	}

	CPropertyPage::OnOK();
}
