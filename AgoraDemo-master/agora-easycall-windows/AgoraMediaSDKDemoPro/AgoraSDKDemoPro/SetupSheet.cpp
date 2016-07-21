// SetupSheet.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "AgoraSDKDemoPro.h"
#include "SetupSheet.h"


// CSetupSheet

IMPLEMENT_DYNAMIC(CSetupSheet, CMFCPropertySheet)

CSetupSheet::CSetupSheet(CWnd* lpParentWnd)
	: CMFCPropertySheet(_T("��������"), lpParentWnd)
{
	SetLook(CMFCPropertySheet::PropSheetLook_OutlookBar);
	SetIconsList(IDB_SETUP_SHEET, 32);

	AddPage(&m_pageNetworkTest);
	AddPage(&m_pageEchoTest);
	AddPage(&m_pageDeviceTest);
	AddPage(&m_pageSetup);
}

CSetupSheet::~CSetupSheet()
{
}


BEGIN_MESSAGE_MAP(CSetupSheet, CMFCPropertySheet)
END_MESSAGE_MAP()



// CSetupSheet ��Ϣ�������



BOOL CSetupSheet::OnInitDialog()
{
	BOOL bResult = CMFCPropertySheet::OnInitDialog();

	// TODO:  �ڴ��������ר�ô���
	

	return bResult;
}
