// NetworkTestPage.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AgoraSDKDemoPro.h"
#include "NetworkTestPage.h"


// CNetworkTestPage �Ի���

IMPLEMENT_DYNAMIC(CNetworkTestPage, CPropertyPage)

CNetworkTestPage::CNetworkTestPage()
	: CPropertyPage(CNetworkTestPage::IDD)
	, m_bEnableNETTest(FALSE)
{

}

CNetworkTestPage::~CNetworkTestPage()
{
}

void CNetworkTestPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CKTEST_NETWORKTEST, m_bEnableNETTest);
}


BEGIN_MESSAGE_MAP(CNetworkTestPage, CPropertyPage)

END_MESSAGE_MAP()


// CNetworkTestPage ��Ϣ�������

BOOL CNetworkTestPage::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}