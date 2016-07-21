// EchoTestPage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AgoraSDKDemoPro.h"
#include "EchoTestPage.h"


// CEchoTestPage �Ի���

IMPLEMENT_DYNAMIC(CEchoTestPage, CPropertyPage)

CEchoTestPage::CEchoTestPage()
	: CPropertyPage(CEchoTestPage::IDD)
{

}

CEchoTestPage::~CEchoTestPage()
{
}

void CEchoTestPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEchoTestPage, CPropertyPage)
	ON_BN_CLICKED(IDC_BTNCTR_ECHOTEST, &CEchoTestPage::OnBnClickedBtnctrEchotest)
END_MESSAGE_MAP()


// CEchoTestPage ��Ϣ�������

void CEchoTestPage::OnBnClickedBtnctrEchotest()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CAgoraObject *lpAgoraObject = CAgoraObject::GetAgoraObject();
	IRtcEngine *lpAgoraRTCEngine = CAgoraObject::GetEngine();
	
	// runing->stop
	if(lpAgoraObject->GetEchoTestFlag()) {
		SetDlgItemText(IDC_BTNCTR_ECHOTEST, _T("��������"));
		lpAgoraRTCEngine->stopEchoTest();
		lpAgoraObject->SetEchoTestFlag(FALSE);
	}
	else{
		SetDlgItemText(IDC_BTNCTR_ECHOTEST, _T("ֹͣ����"));
		lpAgoraRTCEngine->startEchoTest();
		lpAgoraObject->SetEchoTestFlag(TRUE);

		RtcEngineParameters rep(lpAgoraRTCEngine);
		rep.enableAudioVolumeIndication(1000, 10);
	}
}
